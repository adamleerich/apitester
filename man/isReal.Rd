% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/all.R
\name{isReal}
\alias{isReal}
\title{Wrapper of Rf_isReal}
\usage{
isReal(x)
}
\arguments{
\item{x}{any SEXP object}
}
\value{
A logical vector of length one
TRUE if x is real, FALSE otherwise
}
\description{
Interact with Rf_isReal from R
}
\examples{
isReal(1L)
isReal(-12.3)
isReal("A String")

}
