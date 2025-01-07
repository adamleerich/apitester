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

// TODO R_typeToChar
// todo R_NilValue



SEXP new_SEXP(int type) {

  SEXP result = R_NilValue;

  switch(type) {
    case REALSXP:
    case INTSXP:
    case LGLSXP:
    case NILSXP:
    case RAWSXP:
    case CPLXSXP:
    case STRSXP:
    case EXPRSXP:
    case VECSXP:
    case LANGSXP:
    case LISTSXP:
    case intCHARSXP:
      result = PROTECT(Rf_allocVector(type, 1));
      break;

    case CHARSXP:
      result = Rf_mkChar("");
      break;

    // case PROMSXP:
    // case SYMSXP:
    // case CLOSXP:
    // case ENVSXP:
    // case SPECIALSXP:
    // case BUILTINSXP:
    // case DOTSXP:
    // case ANYSXP:
    // case BCODESXP:
    // case EXTPTRSXP:
    // case WEAKREFSXP:
    // case NEWSXP:
    // case FREESXP:
    // case FUNSXP:
    // case OBJSXP:
    // default:
    //   result = R_NilValue;
  }

  UNPROTECT(1);
  return result;

}






SEXP Rapi__TYPEOF_list(SEXP x) {

  SEXP result = PROTECT(Rf_allocVector(VECSXP, 3));
  SEXP type_int = PROTECT(Rf_allocVector(INTSXP, 1));
  SEXP type_str = PROTECT(Rf_allocVector(STRSXP, 1));
  SEXP type_str2 = PROTECT(Rf_allocVector(STRSXP, 1));

  int type = TYPEOF(x);
  char* type_char = sexptype2str(type);

  INTEGER(type_int)[0] = type;
  SET_STRING_ELT(type_str, 0, Rf_type2str(type));
  SET_STRING_ELT(type_str2, 0, Rf_mkChar(type_char));
  SET_VECTOR_ELT(result, 0, type_int);
  SET_VECTOR_ELT(result, 1, type_str);
  SET_VECTOR_ELT(result, 2, type_str2);

  UNPROTECT(4);
  return result;
}


SEXP Rapi__type2str(SEXP x) {
  SEXP result = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_STRING_ELT(result, 0, Rf_type2str(TYPEOF(x)));
  UNPROTECT(1);
  return result;
}



SEXP Rapi__TYPEOF(SEXP x)
{
  // #define TYPEOF(x) ((x)->sxpinfo.type)
  SEXP result = PROTECT(Rf_allocVector(INTSXP, 1));
  INTEGER(result)[0] = TYPEOF(x);
  UNPROTECT(1);
  return result;
}




SEXP Rapi__isReal(SEXP x)
{
    SEXP result = PROTECT(Rf_allocVector(LGLSXP, 1));
    LOGICAL(result)[0] = Rf_isReal(x);
    UNPROTECT(1);
    return result;
}
