# Explore directory recursively and replace cvs root for access by the specified developper.
# Put together by a newbie to python, use at your own risk!

import os
import sys

def updateCVSRoot( developper, dirName, fileNames ):
    print "Exploring: ", os.path.abspath( dirName )
    if ( fileNames.count( 'Root' ) > 0 ) and os.path.basename(dirName) == 'CVS':
        cvsroot_path = os.path.join( dirName, 'Root' )
        new_root = ':ext:%s@cppunit.cvs.sourceforge.net:/cvsroot/cppunit' % developper
        file( cvsroot_path, 'wt' ).write( new_root )
        print 'Updated:', cvsroot_path

if __name__ == '__main__':
    developper = sys.argv[1]
    os.path.walk( ".", updateCVSRoot, developper )
