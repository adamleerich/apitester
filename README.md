# API Tester Package

Goal: write a package that uses every part of the R API to understand how it works.
Documentation via usage perhaps?

## Reference Material

Core R Manuals: 
* https://rstudio.github.io/r-manuals/r-lang/
* https://rstudio.github.io/r-manuals/r-exts/
* https://rstudio.github.io/r-manuals/r-ints/

Advanced R Book:
* http://adv-r.had.co.nz/
* http://adv-r.had.co.nz/C-interface.html

R Packages Book:
* https://r-pkgs.org/



## All environment variables that R cares about

1. R_MAKEVARS_SITE
1. R_MAKEVARS_USER
1. R_PACKAGE_NAME 
1. R_PACKAGE_SOURCE 
1. R_PACKAGE_DIR 
1. R_ARCH 
1. SHLIB_EXT 
1. WINDOWS 
1. R_HOME
1. R_PLATFORM
1. R_PAPERSIZE_USER
1. R_PAPERSIZE
1. R_PRINTCMD
1. R_RD4PDF
1. R_TEXI2DVICMD
1. R_GZIPCMD
1. R_UNZIPCMD
1. R_ZIPCMD
1. R_BZIPCMD
1. R_BROWSER
1. EDITOR
1. PAGER
1. R_PDFVIEWER
1. LN_S
1. MAKE
1. SED
1. TAR
1. R_STRIP_SHARED_LIB
1. R_STRIP_STATIC_LIB
1. R_LIBS_USER
1. R_LIBS_SITE
1. LD_LIBRARY_PATH 
1. TMPDIR 




## Other things to learn about

* IGNORE_RDIFF
* zapsmall
* loading package namespaces but not attaching them by using requireNamespace(pkg, quietly = TRUE) and using pkg:: to refer to objects in the namespace
* Learn more about Autoconf: https://rstudio.github.io/r-manuals/r-exts/Creating-R-packages.html#FOOT30
* Static libraries, dynamic libraries, shared libraries, etc.
* unsatisfied entry points in compiled code





## Packages to learn from 

WriteXLS/inst/Perl
NMF/inst/m-files
RnavGraph/inst/tcl
RProtoBuf/inst/python
emdbook/inst/BUGS
gridSVG/inst/js
tiff for pkg-config
RSiena for src/ organization and including other code






## How R CMD Install builds packages

Flags set when building:
* CC 
* CFLAGS
* CXX
* CXXFLAGS
* CPPFLAGS
* LDFLAGS
* FC
* FCFLAGS
* PKG_CPPFLAGS
* PKG_CFLAGS
* PKG_CXXFLAGS
* PKG_FFLAGS
* PKG_FCFLAGS
* PKG_LIBS
* BLAS_LIBS
* NDEBUG



## Header Files

https://rstudio.github.io/r-manuals/r-exts/The-R-API.html#organization-of-header-files

| Header               | Description                                                                                   | 
|----------------------|-----------------------------------------------------------------------------------------------| 
| R.h                  | includes many other files                                                                     | 
| Rinternals.h         | definitions for using R’s internal structures                                                 | 
| Rdefines.h           | macros for an S-like interface to the above (no longer maintained)                            | 
| Rmath.h              | standalone math library                                                                       | 
| Rversion.h           | R version information                                                                         | 
| Rinterface.h         | for add-on front-ends (Unix-alikes only)                                                      | 
| Rembedded.h          | for add-on front-ends                                                                         | 
| R_ext/Applic.h       | optimization, integration and some LAPACK ones)                                               | 
| R_ext/BLAS.h         | C definitions for BLAS routines                                                               | 
| R_ext/Callbacks.h    | C (and R function) top-level task handlers                                                    | 
| R_ext/GetX11Image.h  | X11Image interface used by package trkplot                                                    | 
| R_ext/Lapack.h       | C definitions for some LAPACK routines                                                        | 
| R_ext/Linpack.h      | C definitions for some LINPACK routines, not all of which are included in R                   | 
| R_ext/Parse.h        | a small part of R’s parse interface: not part of the stable API.                              | 
| R_ext/RStartup.h     | for add-on front-ends                                                                         | 
| R_ext/Rdynload.h     | needed to register compiled code in packages                                                  | 
| R_ext/Riconv.h       | interface to iconv                                                                            | 
| R_ext/Visibility.h   | definitions controlling visibility                                                            | 
| R_ext/eventloop.h    | for add-on front-ends and for packages that need to share in the R event loops (not Windows)  | 

| R.h Includes       | Description                                                            | 
|--------------------|------------------------------------------------------------------------| 
| Rconfig.h          | configuration info that is made available                              | 
| R_ext/Arith.h      | handling for NAs, NaNs, Inf/-Inf                                       | 
| R_ext/Boolean.h    | TRUE/FALSE type                                                        | 
| R_ext/Complex.h    | C typedefs for R’s complex                                             | 
| R_ext/Constants.h  | constants                                                              | 
| R_ext/Error.h      | error signaling                                                        | 
| R_ext/Memory.h     | memory allocation                                                      | 
| R_ext/Print.h      | Rprintf and variations.                                                | 
| R_ext/RS.h         | definitions common to R.h and the former S.h, including F77_CALL etc.  | 
| R_ext/Random.h     | random number generation                                               | 
| R_ext/Utils.h      | sorting and other utilities                                            | 
| R_ext/libextern.h  | definitions for exports from R.dll on Windows.                         | 

R_ext/GraphicsEngine.h
R_ext/GraphicsDevice.h
R_ext/QuartzDevice.h
R_ext/Connections.h


## Tons of compile options, where are they documented?

USE_RINTERNALS
COMPILING_R
TESTING_WRITE_BARRIER
STRICT_TYPECHECK
CATCH_ZERO_LENGTH_ACCESS
