AC_DEFUN([CHECK_MED2],[
AC_REQUIRE([AC_PROG_CC])dnl
AC_REQUIRE([AC_PROG_CPP])dnl
AC_REQUIRE([CHECK_HDF5])dnl

AC_CHECKING(for MED2)

AC_ARG_WITH(med2,
    [  --with-med2=DIR                 root directory path to med2 installation ],
    [MED2HOME="$withval"
      AC_MSG_RESULT("select $withval as path to med2")
    ])

AC_SUBST(MED2_INCLUDES)
AC_SUBST(MED2_LIBS)
AC_SUBST(MED2_MT_LIBS)

MED2_INCLUDES=""
MED2_LIBS=""
MED2_MT_LIBS=""

med2_ok=no

LOCAL_INCLUDES="$HDF5_INCLUDES"
LOCAL_LIBS="-lmed $HDF5_LIBS"

if test -z $MED2HOME
then
   AC_MSG_WARN(undefined MED2HOME variable which specify med2 installation directory)
else
   LOCAL_INCLUDES="$LOCAL_INCLUDES -I$MED2HOME/include"
   LOCAL_LIBS="-L$MED2HOME/lib $LOCAL_LIBS"
fi

dnl check med2 header

CPPFLAGS_old="$CPPFLAGS"
dnl we must test system : linux = -DPCLINUX
CPPFLAGS="$CPPFLAGS -DPCLINUX $LOCAL_INCLUDES"
AC_CHECK_HEADER(med.h,med2_ok=yes ,med2_ok=no)
CPPFLAGS="$CPPFLAGS_old"

if  test "x$med2_ok" = "xyes"
then

dnl check med2 library

  LIBS_old="$LIBS"
  LIBS="$LIBS $LOCAL_LIBS"
  AC_CHECK_LIB(med,MEDouvrir,med2_ok=yes,med2_ok=no)
  LIBS="$LIBS_old"

fi

if  test "x$med2_ok" = "xyes"
then
  MED2_INCLUDES="-DPCLINUX $LOCAL_INCLUDES"
  MED2_LIBS="$LOCAL_LIBS"
  MED2_MT_LIBS="$LOCAL_LIBS"
fi

AC_MSG_RESULT(for med2: $med2_ok)

])dnl