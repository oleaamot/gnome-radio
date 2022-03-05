#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([gnome-radio], [14.0.0], [ole@gnome.org])
AM_INIT_AUTOMAKE([-Wno-portability 1.11 no-dist-gzip dist-xz tar-ustar subdir-objects])
AC_CONFIG_SRCDIR([src/gnome-radio-main.c])
AC_CONFIG_HEADERS([config.h])

# Initialize automake.
AM_INIT_AUTOMAKE

# Checks for programs.
AC_PROG_CC

# Checks for libraries.
PKG_CHECK_MODULES(GNOME_RADIO,
                  gtk+-3.0 >= 3.22.30 \
                  gstreamer-1.0 >= 1.0 \
                  gstreamer-player-1.0 >= 1.0 \
                  gstreamer-tag-1.0 >= 1.0 \
                  gstreamer-video-1.0 \
                  gstreamer-plugins-bad-1.0 \
                  gstreamer-plugins-base-1.0 \
                  champlain-gtk-0.12 >= 0.12.10)
GNOME_RADIO_PKG_DEPS="gtk+-3.0 gstreamer-1.0 gstreamer-player-1.0 gstreamer-plugins-bad-1.0 gstreamer-plugins-base-1.0 gstreamer-plugins-good-1.0 gstreamer-video-1.0 champlain-gtk-0.12"

# Checks for header files.

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.

GLIB_GSETTINGS

AM_GLIB_GNU_GETTEXT
IT_PROG_INTLTOOL([0.50.1])

GETTEXT_PACKAGE=AC_PACKAGE_NAME
AC_SUBST(GETTEXT_PACKAGE)
AC_DEFINE_UNQUOTED(GETTEXT_PACKAGE, "$GETTEXT_PACKAGE", [Gettext package.])

AC_OUTPUT([
Makefile
data/Makefile
data/gnome-radio.appdata.xml
data/gnome-radio.desktop.in
data/icons/Makefile
gnome-radio.spec
po/Makefile.in
src/Makefile
])
