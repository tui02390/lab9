#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAMES_FILE "test_taker_names.txt"
#define OMR_FILE   "newomr.txt"
#define OUTPUT_FILE "full_data.csv"

int main()
{

        FILE *NAMES = fopen( NAMES_FILE, "r" );
        FILE *NEWOMR = fopen( OMR_FILE, "r" );
        FILE *OUT_CSV = fopen( OUTPUT_FILE, "w" );

        char namearray[ 300 ][ 50 ];

        int i = 0;
        while ( fgets( namearray[ i ], 50, NAMES ) != NULL ) {
                // namearray[ i ][ strlen( namearray[ i ] ) - 1 ] = '\0';
                i++;
        }
        printf( "Done counting.  The count is = %d.\n", i );
        fclose( NAMES );

        char gradearray[ 50 ];

        fgets( gradearray, 50, NEWOMR );
        i = 0;
        while( fgets( gradearray, 50, NEWOMR ) != NULL ) {
                int y;
                for( y = 0; y < 5; y++ )
                        fprintf( OUT_CSV, "%c", gradearray[ y ] );
                fputc( ',', OUT_CSV );
                namearray[ i ][ strlen( namearray[ i ] ) - 1 ] = '\0';
                fputs( namearray[i++], OUT_CSV );
                fputc( ',', OUT_CSV );
                for( y = 0; y < 11; y++ ) {
                        fputc( gradearray[ y + 5 ], OUT_CSV );
                        fputc( ',', OUT_CSV );
                }
                fputc( '\n', OUT_CSV );
        }

        return EXIT_SUCCESS;
}