#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "mpci-tests.h"
#include "mpci_config.h"

char *pathname;
unsigned long line_number; /* file name with complete path and currently read
                              line; kept globally to simplify parameter
                              passing */
int nextchar; /* character appearing next in the file, may be EOF */

FILE*
open_file (const char* file_name)
{
  FILE *fp;
  char *src_dir;
  char default_srcdir[] = ".";

  src_dir = getenv ("srcdir");
  if (src_dir == NULL)
    src_dir = default_srcdir;

  pathname = (char *) malloc ((strlen (src_dir)) + strlen (file_name) + 2);
  if (pathname == NULL) {
    printf ("Cannot allocate memory\n");
    exit (1);
  }
  sprintf (pathname, "%s/%s", src_dir, file_name);
  fp = fopen (pathname, "r");
  if (fp == NULL) {
    fprintf (stderr, "Unable to open %s\n", pathname);
    exit (1);
  }

  return fp;
}

void
close_file (FILE *f)
{
  free (pathname);
  fclose (f);
}

void
init_reading (FILE* f)
{
  line_number = 1;
  nextchar = getc (f);
  skip_whitespace_comments (f);
}

/* read primitives */

/* skips characters until reaching '\n' or EOF;
   '\n' is skipped as well  */
static void
skip_line (FILE *f)
{
  while (nextchar != EOF && nextchar != '\n')
    nextchar = getc (f);
  if (nextchar != EOF) {
    line_number++;
    nextchar = getc (f);
  }
}

/* skips over whitespace if any until reaching EOF or non-whitespace  */
static void
skip_whitespace (FILE *f)
{
  while (isspace (nextchar)) {
    if (nextchar == '\n')
      line_number++;
    nextchar = getc (f);
  }
}

/* skips over all whitespace and comments, if any */
void
skip_whitespace_comments (FILE *f)
{
  skip_whitespace (f);
  while (nextchar == '#') {
    skip_line (f);
    if (nextchar != EOF)
      skip_whitespace (f);
  }
}

static mpfr_prec_t
read_prec (FILE *f)
{
  unsigned long prec;
  int n;

  if (nextchar == EOF) {
    printf ("Error: Unexpected EOF when reading mpfr precision "
            "in file '%s' line %lu\n",
            pathname, line_number);
    exit (1);
  }
  ungetc (nextchar, f);
  n = fscanf (f, "%lu", &prec);
  if (ferror (f)) /* then also n == EOF */
    perror ("Error when reading precision");
  if (n == 0 || n == EOF || prec < MPFR_PREC_MIN || prec > MPFR_PREC_MAX) {
      printf(" %d %d\n", n, prec);
    printf ("Error: Impossible precision in file '%s' line %lu\n",
            pathname, line_number);
    exit (1);
  }
  nextchar = getc (f);
  skip_whitespace_comments (f);
  return (mpfr_prec_t) prec;
}

static void
read_mpfr_number (FILE *f, mpfr_ptr x)
{
  if (nextchar == EOF) {
    printf ("Error: Unexpected EOF when reading mpfr number"
            "in file '%s' line %lu\n",
            pathname, line_number);
    exit (1);
  }
  ungetc (nextchar, f);
  if (mpfr_inp_str (x, f, 0, MPFR_RNDN) == 0) {
    printf ("Error: Impossible to read mpfr number "
            "in file '%s' line %lu\n",
            pathname, line_number);
    exit (1);
  }

  nextchar = getc (f);
  skip_whitespace_comments (f);
}

void
read_mpfi (FILE *f, mpfi_ptr a)
{
  mpfi_set_prec (a, read_prec (f));
  read_mpfr_number (f, &(a->left));
  read_mpfr_number (f, &(a->right));
}

void
read_mpci (FILE *f, mpci_ptr a)
{
  mpci_set_prec (a, read_prec (f));
  read_mpfr_number (f, &(a->real->left));
  read_mpfr_number (f, &(a->real->right));
  read_mpfr_number (f, &(a->imag->left));
  read_mpfr_number (f, &(a->imag->right));
}

void
read_si (FILE *f, long *i)
{
  mpfr_t x;

  mpfr_init2 (x, 32);

  if (nextchar == EOF) {
    printf ("Error: Unexpected EOF when reading integer "
            "in file '%s' line %lu\n",
            pathname, line_number);
    exit (1);
  }
  ungetc (nextchar, f);
  if (mpfr_inp_str (x, f, 0, MPFR_RNDD) == 0) {
    printf ("Error: Impossible to read integer in file '%s' line %lu\n",
            pathname, line_number);
    exit (1);
  }

  if (mpfr_fits_slong_p (x, MPFR_RNDD))
    *i = mpfr_get_si (x, MPFR_RNDD);
  else {
    printf ("Error: the number ");
    mpfr_out_str (stdout, 10, 0, x, MPFR_RNDD);
    printf (" read in file '%s' line %lu does not fit in a long int\n",
            pathname, line_number);
    exit (1);
  }

  nextchar = getc (f);
  skip_whitespace_comments (f);

  mpfr_clear (x);
}
