# Explore directory recursively and append the specified line
# to all .cvsignore.
# put together by a newbie to python, use at your own risk!

import os

def addEOL( line ):
    if len(line) > 0:
        line = line.rstrip( '\n\r' ) + '\n'
    return line
        
def listFiles( dummy, dirName, fileNames ):
    print "* Content of directory: ", os.path.abspath(dirName), ":"
    for file in fileNames:
        print file

def updateCVSIgnore( linesToAdd, cvsignorePath ):
    fread = file( cvsignorePath, 'r' )
    lines = fread.readlines()
    fread.close()

    lines.extend( linesToAdd )
    lines = [addEOL(line) for line in lines]

    fwrite = file( cvsignorePath, 'w+' )
    fwrite.writelines( lines )
    fwrite.close()
    print 'Updated: ', cvsignorePath

def listCVSIgnore( linesToAdd, dirName, fileNames ):
    print "Exploring: ", os.path.abspath( dirName )
    if ( fileNames.count( 'CVS' ) > 0 ):
        fileNames.remove( 'CVS' )
    if ( fileNames.count( '.cvsignore' ) > 0 ):
        cvsignorePath = os.path.join( dirName, '.cvsignore' )
        updateCVSIgnore( linesToAdd, os.path.abspath( cvsignorePath ) )

#if __name__ == '__main__':
#    os.path.walk(sys.argv[1], lister, None)          # dir name in cmdline 

lines = [ 'SunWS_cache', 'ir.out' ]

os.path.walk( ".", listCVSIgnore, lines )
