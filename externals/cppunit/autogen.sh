#!/bin/sh

set -e

ACLOCAL_FLAGS="-I config"

aclocal $ACLOCAL_FLAGS  || \
    aclocal $ACLOCAL_FLAGS -I /usr/local/share/aclocal

for l in libtoolize glibtoolize;
do
 ($l --version) < /dev/null > /dev/null 2>&1 && {
 LIBTOOLIZE=$l
 break
 }
done

$LIBTOOLIZE --force
autoheader
automake --add-missing
autoconf
