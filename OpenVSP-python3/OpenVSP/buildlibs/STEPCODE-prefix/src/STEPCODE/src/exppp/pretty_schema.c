/** \file pretty_schema.c
 * split out of exppp.c 9/21/13
 */

#include <stdlib.h>
#include <errno.h>

#include <sc_version_string.h>
#include <express/express.h>

#include <exppp/exppp.h>
#include "pp.h"
#include "pretty_ref.h"
#include "pretty_scope.h"
#include "pretty_schema.h"

#if defined( _WIN32 ) || defined ( __WIN32__ )
#  define unlink _unlink
#else
#  include <unistd.h> /* for unlink */
#endif

char * exppp_output_filename = ( char * )0; /* if this is set, override default output filename */
char exppp_filename_buffer[1000];           /* output file name */

/* Only the first line is compared to an existing file, so putting a
 * version number in here won't cause problems. The actual version must
 * be inserted later - this can't be initialized with non-constant.
 */
char * expheader[] = {
    "(* This file was generated by the EXPRESS Pretty Printer exppp,"   ,
    "part of STEPcode (formerly NIST's SCL). exppp version:"            ,
    ""     /* if there are two consecutive blank lines, */              ,
    ""  /* the version string will be printed on the first */           ,
    "WARNING: If you modify this file and want to save the changes,"    ,
    "delete this comment block or else the file will be rewritten"      ,
    "the next time exppp processes this schema. *)"                     ,
    0
};


/** returns name of file written to in static storage */
char * SCHEMAout( Schema s ) {
    #define PP_SMALL_BUF_SZ 80
    char buf[PP_SMALL_BUF_SZ];
    char * p;
    int level = 0;
    char ** hp;
    bool described = false;
    if( exppp_print_to_stdout ) {
        exppp_fp = stdout;
    } else {
        FILE * f;
        if( exppp_output_filename_reset ) {
            exppp_output_filename = 0;
        }

        if( exppp_output_filename ) {
            if( !strcmp( input_filename, exppp_output_filename ) ) {
                fprintf( stderr, "Error: input filename and output filename are the same (%s)", exppp_output_filename );
                exit( EXIT_FAILURE );
            }
            strcpy( exppp_filename_buffer, exppp_output_filename );
        } else {
            /* when there is only a single file, allow user to find */
            /* out what it is */
            exppp_output_filename = exppp_filename_buffer;
            exppp_output_filename_reset = true;

            /* since we have to generate a filename, make sure we don't */
            /* overwrite a valuable file */

            sprintf( exppp_filename_buffer, "%s.exp", s->symbol.name );

            if( 0 != ( f = fopen( exppp_filename_buffer, "r" ) ) ) {
                char * result = fgets( buf, PP_SMALL_BUF_SZ, f );
                if( 0 != ( p = strchr( buf, '\n' ) ) ) {
                    *p = '\0';
                }
                if( ( !result ) || ( streq( buf, expheader[0] ) ) ) {
                    unlink( exppp_filename_buffer );
                } else {
                    fprintf( stderr, "%s: %s already exists and appears to be hand-written\n",
                             EXPRESSprogram_name, exppp_filename_buffer );
                    /*          strcat(bp,".pp");*/
                    strcat( exppp_filename_buffer, ".pp" );
                    fprintf( stderr, "%s: writing schema file %s instead\n",
                             EXPRESSprogram_name, exppp_filename_buffer );
                    described = true;
                }
            }
            if( f ) {
                fclose( f );
            }
        }
        error_sym.filename = exppp_filename_buffer;

        if( !described && !exppp_terse ) {
            fprintf( stdout, "%s: writing schema file %s\n", EXPRESSprogram_name, exppp_filename_buffer );
        }
        if( !( exppp_fp = f = fopen( exppp_filename_buffer, "w" ) ) ) {
            ERRORreport( ERROR_file_unwriteable, exppp_filename_buffer, strerror( errno ) );
            return 0;
        }
    }
    error_sym.line = 1;
    /* print our header - generated by exppp, don't edit, etc */
    for( hp = expheader; *hp; hp++ ) {
        if( ( **hp == '\0' ) && ( **( hp + 1 ) == '\0' ) ) {
            /* if this and the next lines are blank, put version string on this line */
            raw( "%s\n", sc_version );
        } else {
            raw( "%s\n", *hp );
        }
    }

    /*  first_newline();*/
    /*  raw("SCHEMA %s;\n",s->symbol.name);*/

    first_line = false;
    raw( "\nSCHEMA %s;\n", s->symbol.name );

    if( s->u.schema->usedict || s->u.schema->use_schemas
            || s->u.schema->refdict || s->u.schema->ref_schemas ) {
        raw( "\n" );
    }

    REFout( s->u.schema->usedict, s->u.schema->use_schemas, "USE", level + exppp_nesting_indent );
    REFout( s->u.schema->refdict, s->u.schema->ref_schemas, "REFERENCE", level + exppp_nesting_indent );

    /* output order for DIS & IS schemas:
     * CONSTANT
     * TYPE
     * ENTITY
     * RULE
     * FUNCTION
     * PROCEDURE
     *
     * Within each of those groups, declarations must be sorted alphabetically.
     */

    SCOPEconsts_out( s, level + exppp_nesting_indent );
    SCOPEtypes_out( s, level + exppp_nesting_indent );
    SCOPEentities_out( s, level + exppp_nesting_indent );
    SCOPEalgs_out( s, level + exppp_nesting_indent );

    raw( "\nEND_SCHEMA;");
    tail_comment( s->symbol.name );

    fclose( exppp_fp );

    return exppp_filename_buffer;
    #undef PP_SMALL_BUF_SZ
}



char * SCHEMAref_to_string( Schema s ) {
    if( prep_string() ) {
        return placeholder;
    }
    REFout( s->u.schema->usedict, s->u.schema->use_schemas, "USE", 0 );
    REFout( s->u.schema->refdict, s->u.schema->ref_schemas, "REFERENCE", 0 );
    return ( finish_string() );
}

/** return length of buffer used */
int SCHEMAref_to_buffer( Schema s, char * buffer, int length ) {
    if( prep_buffer( buffer, length ) ) {
        return -1;
    }
    REFout( s->u.schema->usedict, s->u.schema->use_schemas, "USE", 0 );
    REFout( s->u.schema->refdict, s->u.schema->ref_schemas, "REFERENCE", 0 );
    return( finish_buffer() );
}

void SCHEMAref_out( Schema s ) {
    prep_file();
    REFout( s->u.schema->usedict, s->u.schema->use_schemas, "USE", 0 );
    REFout( s->u.schema->refdict, s->u.schema->ref_schemas, "REFERENCE", 0 );
    finish_file();
}
