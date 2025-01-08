#include "simple.h"


// SEXP internal__new_SEXP(SEXP x) {
//
//   SEXP result = R_NilValue;
//   int type = INTEGER(x)[0];
//
//   switch(type) {
//     case REALSXP:
//     case INTSXP:
//     case LGLSXP:
//     case NILSXP:
//     case RAWSXP:
//     case CPLXSXP:
//     case STRSXP:
//     case EXPRSXP:
//     case VECSXP:
//     case LANGSXP:
//     case LISTSXP:
//     case intCHARSXP:
//       result = PROTECT(Rf_allocVector(type, 1));
//       break;
//
//     case CHARSXP:
//       result = Rf_mkChar("");
//       break;
//
//     // case PROMSXP:
//     // case SYMSXP:
//     // case CLOSXP:
//     // case ENVSXP:
//     // case SPECIALSXP:
//     // case BUILTINSXP:
//     // case DOTSXP:
//     // case ANYSXP:
//     // case BCODESXP:
//     // case EXTPTRSXP:
//     // case WEAKREFSXP:
//     // case NEWSXP:
//     // case FREESXP:
//     // case FUNSXP:
//     // case OBJSXP:
//     // default:
//     //   result = R_NilValue;
//   }
//
//   UNPROTECT(1);
//   return result;
//
// }

SEXP internal__TYPEOF_list(SEXP x) {

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

SEXP internal__type2str(SEXP x) {
  SEXP result = PROTECT(Rf_allocVector(STRSXP, 1));
  SET_STRING_ELT(result, 0, Rf_type2str(TYPEOF(x)));
  UNPROTECT(1);
  return result;
}

SEXP internal__TYPEOF(SEXP x) {
  // #define TYPEOF(x) ((x)->sxpinfo.type)
  SEXP result = PROTECT(Rf_allocVector(INTSXP, 1));
  INTEGER(result)[0] = TYPEOF(x);
  UNPROTECT(1);
  return result;
}

SEXP internal__isReal(SEXP x) {
    SEXP result = PROTECT(Rf_allocVector(LGLSXP, 1));
    LOGICAL(result)[0] = Rf_isReal(x);
    UNPROTECT(1);
    return result;
}
