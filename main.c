#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "tree.h"
#include "color.h"

int main(int argc, char *argv[]){
    int arr[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

	if( argc == 1 ){
        dir_a(".", 0, arr, 0 );
	}

    else if( ( argc == 2 || argc == 3 ) && !strcmp(argv[1],"-a") ){
        if( argc == 2 )
            dir_a(".", 0, arr, 0 );
        if( argc == 3 )
            dir_a(argv[2], 0, arr, 0 );
	}

    else if( ( argc == 2 || argc == 3 ) && !strcmp(argv[1],"-f") ){
        if( argc == 2 )
            dir_a(".", 0, arr, 1 );
        if( argc == 3 )
            dir_a(argv[2], 0, arr, 1 );
	}

    else if( ( argc == 2 || argc == 3 ) && !strcmp(argv[1],"-Q") ){
        if( argc == 2 )
            dir_a(".", 0, arr, 2 );
        if( argc == 3 )
            dir_a(argv[2], 0, arr, 2 );
	}

    else if( ( argc == 2 || argc == 3 ) && !strcmp(argv[1],"-d") ){
        if( argc == 2 )
            dir_d(".", 0, arr );
        if( argc == 3 )
            dir_d( argv[2], 0, arr );
	}

    else if( ( argc == 3 || argc == 4 ) && !strcmp(argv[1],"-L") ){
        int n = atoi( argv[2]);

        if( argc == 3 )
            dir_L(".", 0, arr, n );
        if( argc == 4 )
            dir_L( argv[3], 0, arr, n );
	}

    else if( ( argc == 2 || argc == 3 ) && !strcmp(argv[1],"-p") ){
        if( argc == 2 )
            dir_p(".", 0, arr, 0 );
        if( argc == 3 )
            dir_p( argv[2], 0, arr, 0 );
	}

    else if( ( argc == 2 || argc == 3 ) && !strcmp(argv[1],"-s") ){
        if( argc == 2 )
            dir_p(".", 0, arr, 1 );
        if( argc == 3 )
            dir_p( argv[2], 0, arr, 1 );
	}

    else if( ( argc == 2 || argc == 3 ) && !strcmp(argv[1],"-D") ){
        if( argc == 2 )
            dir_p(".", 0, arr, 2 );
        if( argc == 3 )
            dir_p( argv[2], 0, arr, 2 );
	}

    else if( ( argc == 2 || argc == 3 ) && !strcmp(argv[1],"-u") ){
        if( argc == 2 )
            dir_u(".", 0, arr, 0 );
        if( argc == 3 )
            dir_u( argv[2], 0, arr, 0 );
	}

    else if( ( argc == 2 || argc == 3 ) && !strcmp(argv[1],"-g") ){
        if( argc == 2 )
            dir_u(".", 0, arr, 1 );
        if( argc == 3 )
            dir_u( argv[2], 0, arr, 1 );
	}

    else if( ( argc == 2 || argc == 3 ) && !strcmp(argv[1],"-i") ){
        if( argc == 2 )
            dir_i(".", 0 );
        if( argc == 3 )
            dir_i(argv[2], 0 );
	}

    else if( ( argc == 2 || argc == 3 ) && !strcmp(argv[1],"-S") ){
        if( argc == 2 )
            dir_S(".", 0 );
        if( argc == 3 )
            dir_S(argv[2], 0 );
	}

    else if( ( argc == 2 || argc == 3 ) && !strcmp(argv[1],"-n") ){
        if( argc == 2 )
            dir_n(".", 0, arr );
        if( argc == 3 )
            dir_n(argv[2], 0, arr );
	}

    else if( ( argc == 2 || argc == 3 ) && !strcmp(argv[1],"-X") ){
        if( argc == 2 )
            dir_X(".", 0 );
        if( argc == 3 )
            dir_X(argv[2], 0 );
	}

    else if( ( argc == 2 || argc == 3 ) && !strcmp(argv[1],"-J") ){
        if( argc == 2 )
            dir_J(".", 0 );
        if( argc == 3 )
            dir_J(argv[2], 0 );
	}

    else if( ( argc == 3 || argc == 4 ) && !strcmp(argv[1],"-P") ){
        if( argc == 3 )
            dir_P(".", 0, arr, 0, argv[2] );
        if( argc == 4 )
            dir_P(argv[3], 0, arr, 0, argv[2] );
	}

    else if( ( argc == 3 || argc == 4 ) && !strcmp(argv[1],"-I") ){
        if( argc == 3 )
            dir_P(".", 0, arr, 1, argv[2] );
        if( argc == 4 )
            dir_P(argv[3], 0, arr, 1, argv[2] );
	}

    else if( argc == 2 && !strcmp(argv[1],"--help") )
        help();

    else if( argc == 2 && !strcmp(argv[1],"--version") )
        version();

    else
        printf("Try ./tree --help for Information \n");
    return 0 ;
}