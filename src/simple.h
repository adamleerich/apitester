#ifndef R_NO_REMAP
# define R_NO_REMAP
#endif

#include <R.h>
#include <Rinternals.h>

// SEXP internal__new_SEXP(SEXP x);
SEXP internal__TYPEOF_list(SEXP x);
SEXP internal__type2str(SEXP x);
SEXP internal__TYPEOF(SEXP x);
SEXP internal__isReal(SEXP x);
