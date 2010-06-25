#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.65])
AC_INIT(mc, 0.1, zhicheng@in-blue.org)
AM_INIT_AUTOMAKE(mc, 0.1, zhicheng@in-blue.org)
AC_CONFIG_SRCDIR([src/main.c])
AC_CONFIG_HEADERS([config/config.h])
AC_CONFIG_FILES([Makefile
                 src/Makefile])

# Checks for programs.
AC_PROG_CC

# Checks for libraries.
AC_CHECK_LIB(curl, curl_easy_init,, AC_MSG_ERROR([*** Unable to find libcurl]), `curl-config --libs`)
AC_CHECK_LIB(json, json_object_new_object,, AC_MSG_ERROR([*** Unable to find json]), `pkg-config --libs json`)

# Checks for header files.
AC_CHECK_HEADERS([stdlib.h string.h unistd.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_TYPE_SIZE_T

# Checks for library functions.
AC_FUNC_MALLOC
AC_CHECK_FUNCS([strndup strstr])

AC_OUTPUT
