"""Amalgate cppunit library sources into a single source file
   (headers are not amalgated for backward compatibility).

Requires Python 2.6

Example of invocation (must be invoked from cppunit top directory):
python amalgate.py

This will generate file ${CPPUNIT_ROOT}/dist/amalgated-src/cppunit_lib.cpp
that contains all sources (.cpp/.h) from src/cppcunit.
"""
from glob import glob
import os
import os.path
import sys

class AmalgamationFile:
    def __init__( self, top_dir ):
        self.top_dir = top_dir
        self.blocks = []

    def add_text( self, text ):
        if not text.endswith( '\n' ):
            text += '\n'
        self.blocks.append( text )

    def add_file( self, relative_input_path, wrap_in_comment=False, comment_out_local_include=False ):
        def add_marker( prefix ):
            self.add_text( '' )
            self.add_text( '// ' + '/'*70 )
            self.add_text( '// %s of content of file: %s' % (prefix, relative_input_path.replace('\\','/')) )
            self.add_text( '// ' + '/'*70 )
            self.add_text( '' )
        add_marker( 'Beginning' )
        f = open( os.path.join( self.top_dir, relative_input_path ), 'rt' )
        content = f.read()
        if wrap_in_comment:
            content = '/*\n' + content + '\n*/'
        if comment_out_local_include:
            content = content.replace( '#include "', '// header was amalgamated #include "' )
        self.add_text( content )
        f.close()
        add_marker( 'End' )
        self.add_text( '\n\n\n\n' )

    def get_value( self ):
        return ''.join( self.blocks ).replace('\r\n','\n')

    def write_to( self, output_path ):
        output_dir = os.path.dirname( output_path )
        if output_dir and not os.path.isdir( output_dir ):
            os.makedirs( output_dir )
        f = open( output_path, 'wb' )
        f.write( self.get_value() )
        f.close()

def amalgamate_source( source_top_dir=None,
                       target_source_path=None ):
    """Produces amalgated source.
       Parameters:
           source_top_dir: top-directory
           target_source_path: output .cpp path
           header_include_path: generated header path relative to target_source_path.
    """
    print 'Amalgating source...'
    source = AmalgamationFile( source_top_dir )
    source.add_text( '/// CppUnit amalgated source (http://cppunit.sourceforge.net/).' )
    source.add_file( 'COPYING', wrap_in_comment=True )
    source.add_text( '' )
    source.add_text( '' )
    lib_cppunit = 'src/cppunit'
    lib_cppunit_h = glob( os.path.join( lib_cppunit, '*.h' ) )
    lib_cppunit_h.sort()
    lib_cppunit_cpp = glob( os.path.join( lib_cppunit, '*.cpp' ) )
    lib_cppunit_cpp.sort()
    for src_relative_path in lib_cppunit_h + lib_cppunit_cpp:
        source.add_file( src_relative_path, comment_out_local_include=True )

    print 'Writing amalgated source to %r' % target_source_path
    source.write_to( target_source_path )

def main():
    usage = """%prog [options]
Generate a single amalgated source and header file from the sources.
"""
    from optparse import OptionParser
    parser = OptionParser(usage=usage)
    parser.allow_interspersed_args = False
    parser.add_option('-s', '--source', dest="target_source_path", action='store', default='dist/amalgated-src/cppunit_lib.cpp',
        help="""Output .cpp source path. [Default: %default]""")
    parser.add_option('-t', '--top-dir', dest="top_dir", action='store', default=os.getcwd(),
        help="""Source top-directory. [Default: %default]""")
    parser.enable_interspersed_args()
    options, args = parser.parse_args()

    msg = amalgamate_source( source_top_dir=options.top_dir,
                             target_source_path=options.target_source_path )
    if msg:
        sys.stderr.write( msg + '\n' )
        sys.exit( 1 )
    else:
        print 'Source succesfully amalagated'
 
if __name__ == '__main__':
    main()
