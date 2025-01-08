#ifndef R_NO_REMAP
# define R_NO_REMAP
#endif

#include <R.h>
#include <Rinternals.h>

#ifndef OBJSXP
#define OBJSXP 25
#endif

#ifndef intCHARSXP
#define intCHARSXP 73
#endif

static char* sexptype2str(int x) {
  switch (x) {
    case NILSXP:       return "NILSXP";     /* 0   nil = NULL */
    case SYMSXP:       return "SYMSXP";     /* 1   symbols */
    case LISTSXP:      return "LISTSXP";    /* 2   lists of dotted pairs */
    case CLOSXP:       return "CLOSXP";     /* 3   closures */
    case ENVSXP:       return "ENVSXP";     /* 4   environments */
    case PROMSXP:      return "PROMSXP";    /* 5   promises: [un]evaluated closure arguments */
    case LANGSXP:      return "LANGSXP";    /* 6   language constructs (special lists) */
    case SPECIALSXP:   return "SPECIALSXP"; /* 7   special forms */
    case BUILTINSXP:   return "BUILTINSXP"; /* 8   builtin non-special forms */
    case CHARSXP:      return "CHARSXP";    /* 9   "scalar" string type (internal only)*/
    case LGLSXP:       return "LGLSXP";     /* 10  logical vectors */
    case INTSXP:       return "INTSXP";     /* 13  integer vectors */
    case REALSXP:      return "REALSXP";    /* 14  real variables */
    case CPLXSXP:      return "CPLXSXP";    /* 15  complex variables */
    case STRSXP:       return "STRSXP";     /* 16  string vectors */
    case DOTSXP:       return "DOTSXP";     /* 17  dot-dot-dot object */
    case ANYSXP:       return "ANYSXP";     /* 18  make "any" args work. */
    case VECSXP:       return "VECSXP";     /* 19  generic vectors */
    case EXPRSXP:      return "EXPRSXP";    /* 20  expressions vectors */
    case BCODESXP:     return "BCODESXP";   /* 21  byte code */
    case EXTPTRSXP:    return "EXTPTRSXP";  /* 22  external pointer */
    case WEAKREFSXP:   return "WEAKREFSXP"; /* 23  weak reference */
    case RAWSXP:       return "RAWSXP";     /* 24  raw bytes */
    case NEWSXP:       return "NEWSXP";     /* 30  fresh node created in new page */
    case FREESXP:      return "FREESXP";    /* 31  node released by GC */
    case FUNSXP:       return "FUNSXP";     /* 99  Closure or Builtin or Special */
    case OBJSXP:       return "OBJSXP";     /* 25  object, non-vector  */
    case intCHARSXP:   return "intCHARSXP"; /* 73  internal CHARSXP in memory.c */
    default:		       return "<unknown>";
  }
}

// SEXP internal__new_SEXP(SEXP x);
SEXP internal__TYPEOF_list(SEXP x);
SEXP internal__type2str(SEXP x);
SEXP internal__TYPEOF(SEXP x);
SEXP internal__isReal(SEXP x);
