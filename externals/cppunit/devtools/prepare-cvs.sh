#! /bin/sh
set -e

perl -pi -e 's/\n/\r\n/g' `find $1 -name '*.ds?'` \
		$1/contrib/msvc/*			  \
		$1/INSTALL-WIN32.txt

(cd $1 && rm -rf `find . -name CVS`)

tar cf $1.tar $1
gzip -9 $1.tar
