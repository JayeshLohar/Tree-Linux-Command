#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<dirent.h>
#include "tree.h"
#include "color.h"

int file_count = 0 ;
int dir_count = 0 ;

//  -a = 0           All files are listed.
//  -f = 1           Print the full path prefix for each file.
//  -Q = 2           Quote filenames with double quotes.
void dir_a( char *dir_name, int no, int *arr, int mode ){
    DIR *dir;
    dir = opendir( dir_name ) ;
    if( dir == NULL )
        return ;

    if( no == 0 ){
        yellow();
        printf("%s \n", dir_name );
        reset();
    }

    struct dirent *de;
    int i, count = -2, j = 0 ;
    while( ( de = readdir(dir)) )
        count++ ;

    closedir(dir);
    dir = opendir( dir_name ) ;

    char fname[64], dname[64] ;
    strcpy( dname, dir_name );

    if( dir!=NULL ){
        while( ( de = readdir(dir)) ){
            if( de->d_type == DT_DIR ){
                if( strcmp( de->d_name, ".") == 0 || strcmp( de->d_name, "..") == 0 );
                else {
                    j++ ;
                    dir_count++ ;
                    for( i = 0 ; i < no ; i++ ){
                        if( *(arr+i) == 0 )
                            printf("│   ");
                        else
                            printf("    ");
                    }
                    if( j == count )
                        printf("└── ");
                    else
                        printf("├── ");
                    strcpy( dname, dir_name ) ;
                    strcat( dname, "/");
                    strcat( dname, de->d_name);

                    yellow();
                    if( mode == 0 )
                        printf("%s \n", de->d_name );
                    else if( mode == 1 )
                        printf("%s \n", dname );
                    else if( mode == 2 )
                        printf("\"%s\" \n", de->d_name );
                    reset();

                    if( j == count )
                        arr[no] = 1 ;
                    dir_a( dname, no +1, arr, mode );
                }
            }
            else{
                j++ ;
                file_count++ ;
                strcpy( fname, dir_name );
                strcat( fname, "/");
                strcat( fname, de->d_name );
                for( i = 0 ; i < no ; i++ ){
                    if( arr[i] == 0 )
                        printf("│   ");
                    else
                        printf("    ");
                }
                if( j == count )
                        printf("└── ");
                    else
                        printf("├── ");
                cyan();
                if( mode == 0 )
                    printf("%s \n", de->d_name );
                else if( mode == 1 )
                    printf("%s \n", fname );
                else if( mode == 2 )
                    printf("\"%s\" \n", de->d_name );

                reset();
            }
        }
        closedir(dir);
    }
    arr[no] = 0;
    if( no == 0 )
        printf("\n%d directories, %d files \n", dir_count, file_count );
    return ;
}

//  -d            List directories only.
void dir_d( char *dir_name, int no, int *arr ){
    DIR *dir;
    dir = opendir( dir_name ) ;
    if( dir == NULL )
        return ;

    if( no == 0 ){
        yellow();
        printf("%s \n", dir_name );
        reset();
    }

    struct dirent *de;
    int i, count = -2, j = 0 ;
    while( ( de = readdir(dir)) )
        if( de->d_type == DT_DIR )
            count++ ;

    closedir(dir);
    dir = opendir( dir_name ) ;

    char fname[64], dname[64] ;
    strcpy( dname, dir_name );

    if( dir!=NULL ){
        while( ( de = readdir(dir)) ){
            if( de->d_type == DT_DIR ){
                if( strcmp( de->d_name, ".") == 0 || strcmp( de->d_name, "..") == 0 );
                else {
                    j++ ;
                    dir_count++ ;
                    for( i = 0 ; i < no ; i++ ){
                        if( *(arr+i) == 0 )
                            printf("│   ");
                        else
                            printf("    ");
                    }
                    if( j == count )
                        printf("└── ");
                    else
                        printf("├── ");
                    strcpy( dname, dir_name ) ;
                    strcat( dname, "/");
                    strcat( dname, de->d_name);

                    yellow();
                    printf("%s \n", de->d_name );
                    reset();

                    if( j == count )
                        arr[no] = 1 ;
                    dir_d( dname, no +1, arr );
                }
            }
        }
        closedir(dir);
    }
    arr[no] = 0;
    if( no == 0 )
        printf("\n%d directories \n", dir_count );
    return ;
}

void dir_L( char *dir_name, int no, int *arr, int level ){
    if( level < 1 )
        return ;
    DIR *dir;
    dir = opendir( dir_name ) ;
    if( dir == NULL )
        return ;

    if( no == 0 ){
        yellow();
        printf("%s \n", dir_name );
        reset();
    }

    struct dirent *de;
    int i, count = -2, j = 0 ;
    while( ( de = readdir(dir)) )
        count++;
    closedir(dir);
    dir = opendir( dir_name ) ;

    char fname[64], dname[64] ;
    strcpy( dname, dir_name );

    if( dir!=NULL ){
        while( ( de = readdir(dir)) ){
            if( de->d_type == DT_DIR ){
                if( strcmp( de->d_name, ".") == 0 || strcmp( de->d_name, "..") == 0 );
                else {
                    j++ ;
                    dir_count++ ;
                    for( i = 0 ; i < no ; i++ ){
                        if( *(arr+i) == 0 )
                            printf("│   ");
                        else
                            printf("    ");
                    }
                    if( j == count )
                        printf("└── ");
                    else
                        printf("├── ");
                    strcpy( dname, dir_name ) ;
                    strcat( dname, "/");
                    strcat( dname, de->d_name);

                    yellow();    
                    printf("%s \n", de->d_name );
                    reset();

                    if( j == count )
                        arr[no] = 1 ;
                    dir_L( dname, no +1, arr, level -1 );
                }
            }
            else{
                j++ ;
                file_count++ ;
                for( i = 0 ; i < no ; i++ ){
                    if( arr[i] == 0 )
                        printf("│   ");
                    else
                        printf("    ");
                }
                if( j == count )
                        printf("└── ");
                    else
                        printf("├── ");
                cyan();
                printf("%s \n", de->d_name );
                reset();
            }
        }
        closedir(dir);
    }
    arr[no] = 0;
    if( no == 0 )
        printf("\n%d directories, %d files \n", dir_count, file_count );
    return ;
}

//  -p = 0           Print the protections for each file.
//  -s = 1           Print the size in bytes of each file.
//  -D = 2           Print the date of last modification or (-c) status change.
void dir_p( char *dir_name, int no, int *arr, int mode ){
    DIR *dir;
    dir = opendir( dir_name ) ;
    if( dir == NULL )
        return ;

    if( no == 0 ){
        yellow();
        printf("%s \n", dir_name );
        reset();
    }

    struct dirent *de;
    int i, count = -2, j = 0 ;
    while( ( de = readdir(dir)) )
        count++ ;

    closedir(dir);
    dir = opendir( dir_name ) ;

    char fname[64], dname[64] ;
    strcpy( dname, dir_name );

    if( dir!=NULL ){
        while( ( de = readdir(dir)) ){
            if( de->d_type == DT_DIR ){
                if( strcmp( de->d_name, ".") == 0 || strcmp( de->d_name, "..") == 0 );
                else {
                    j++ ;
                    dir_count++ ;
                    for( i = 0 ; i < no ; i++ ){
                        if( *(arr+i) == 0 )
                            printf("│   ");
                        else
                            printf("    ");
                    }
                    if( j == count )
                        printf("└── ");
                    else
                        printf("├── ");
                    strcpy( dname, dir_name ) ;
                    strcat( dname, "/");
                    strcat( dname, de->d_name);

                    yellow();
                    printf("%s \n", de->d_name );
                    reset();

                    if( j == count )
                        arr[no] = 1 ;
                    dir_p( dname, no +1, arr, mode );
                }
            }
            else{
                j++ ;
                file_count++ ;
                strcpy( fname, dir_name );
                strcat( fname, "/");
                strcat( fname, de->d_name );
                for( i = 0 ; i < no ; i++ ){
                    if( arr[i] == 0 )
                        printf("│   ");
                    else
                        printf("    ");
                }
                if( j == count )
                        printf("└── ");
                    else
                        printf("├── ");
                cyan();
                printf("%s ", de->d_name );
                reset();
                if( mode == 0 )
                    file_permission( fname );
                else if( mode == 1 )
                    file_size( fname );
                else if( mode == 2 )
                    file_time( fname );
                printf("\n");
            }
        }
        closedir(dir);
    }
    arr[no] = 0;
    if( no == 0 )
        printf("\n%d directories, %d files \n", dir_count, file_count );
    return ;
}

//  -u            Displays file owner or UID number.
//  -g            Displays file group owner or GID number.
void dir_u( char *dir_name, int no, int *arr, int mode ){
    DIR *dir;
    dir = opendir( dir_name ) ;
    if( dir == NULL )
        return ;

    if( no == 0 ){
        yellow();
        printf("%s \n", dir_name );
        reset();
    }

    struct dirent *de;
    int i, count = -2, j = 0 ;
    while( ( de = readdir(dir)) )
        count++ ;

    closedir(dir);
    dir = opendir( dir_name ) ;

    char fname[64], dname[64] ;
    strcpy( dname, dir_name );

    if( dir!=NULL ){
        while( ( de = readdir(dir)) ){
            if( de->d_type == DT_DIR ){
                if( strcmp( de->d_name, ".") == 0 || strcmp( de->d_name, "..") == 0 );
                else {
                    j++ ;
                    dir_count++ ;
                    for( i = 0 ; i < no ; i++ ){
                        if( *(arr+i) == 0 )
                            printf("│   ");
                        else
                            printf("    ");
                    }
                    if( j == count )
                        printf("└── ");
                    else
                        printf("├── ");
                    strcpy( dname, dir_name ) ;
                    strcat( dname, "/");
                    strcat( dname, de->d_name);

                    yellow();
                    printf("%s \n", de->d_name );
                    reset();

                    if( j == count )
                        arr[no] = 1 ;
                    dir_u( dname, no +1, arr, mode );
                }
            }
            else{
                j++ ;
                file_count++ ;
                for( i = 0 ; i < no ; i++ ){
                    if( arr[i] == 0 )
                        printf("│   ");
                    else
                        printf("    ");
                }
                if( j == count )
                        printf("└── ");
                    else
                        printf("├── ");
                cyan();
                printf("%s ", de->d_name );
                reset();
                if( mode == 0 )
                    uid_num();
                else if( mode == 1 )
                    gid_num();
                printf("\n");
            }
        }
        closedir(dir);
    }
    arr[no] = 0;
    if( no == 0 )
        printf("\n%d directories, %d files \n", dir_count, file_count );
    return ;
}

//Graphics option i
void dir_i( char *dir_name, int no ){
    DIR *dir;
    dir = opendir( dir_name ) ;
    if( dir == NULL )
        return ;

    if( no == 0 ){
        yellow();
        printf("%s \n", dir_name );
        reset();
    }

    struct dirent *de;
    char fname[64], dname[64] ;
    strcpy( dname, dir_name );

    if( dir!=NULL ){
        while( ( de = readdir(dir)) ){
            if( de->d_type == DT_DIR ){
                if( strcmp( de->d_name, ".") == 0 || strcmp( de->d_name, "..") == 0 );
                else {
                    dir_count++ ;
                    strcpy( dname, dir_name ) ;
                    strcat( dname, "/");
                    strcat( dname, de->d_name);

                    yellow();
                    printf("%s \n", de->d_name );
                    reset();
                    dir_i( dname, no +1 );
                }
            }
            else{
                file_count++ ;
                cyan();
                printf("%s \n", de->d_name );
                reset();
            }
        }
        closedir(dir);
    }
    if( no == 0 )
        printf("\n%d directories, %d files \n", dir_count, file_count );
    return ;
}

//Graphics
void dir_S( char *dir_name, int no ){
    DIR *dir;
    dir = opendir( dir_name ) ;
    if( dir == NULL )
        return ;

    if( no == 0 ){
        yellow();
        printf("%s \n", dir_name );
        reset();
    }

    struct dirent *de;
    char fname[64], dname[64] ;
    strcpy( dname, dir_name );
    int i ;

    if( dir!=NULL ){
        while( ( de = readdir(dir)) ){
            if( de->d_type == DT_DIR ){
                if( strcmp( de->d_name, ".") == 0 || strcmp( de->d_name, "..") == 0 );
                else {
                    dir_count++ ;
                    for( i = 0 ; i < no ; i++ )
                        printf("    ");

                    strcpy( dname, dir_name ) ;
                    strcat( dname, "/");
                    strcat( dname, de->d_name);

                    yellow();
                    printf("%s \n", de->d_name );
                    reset();
                    dir_S( dname, no +1 );
                }
            }
            else{
                file_count++ ;
                for( i = 0 ; i < no ; i++ )
                    printf("    ");
                cyan();    
                printf("%s \n", de->d_name );
                reset();
            }
        }
        closedir(dir);
    }
    if( no == 0 )
        printf("\n%d directories, %d files \n", dir_count, file_count );
    return ;
}

void dir_n( char *dir_name, int no, int *arr ){
    DIR *dir;
    dir = opendir( dir_name ) ;
    if( dir == NULL )
        return ;
    if( no == 0 ){
        printf("%s \n", dir_name );
    }

    struct dirent *de;
    int i, count = -2, j = 0 ;
    while( ( de = readdir(dir)) )
        count++ ;

    closedir(dir);
    dir = opendir( dir_name ) ;

    char fname[64], dname[64] ;
    strcpy( dname, dir_name );

    if( dir!=NULL ){
        while( ( de = readdir(dir)) ){
            if( de->d_type == DT_DIR ){
                if( strcmp( de->d_name, ".") == 0 || strcmp( de->d_name, "..") == 0 );
                else {
                    j++ ;
                    dir_count++ ;
                    for( i = 0 ; i < no ; i++ ){
                        if( arr[i] == 0 )
                            printf("│   ");
                        else
                            printf("    ");
                    }
                    if( j == count )
                        printf("└── ");
                    else
                        printf("├── ");
                    strcpy( dname, dir_name ) ;
                    strcat( dname, "/");
                    strcat( dname, de->d_name);
    
                    printf("%s \n", de->d_name );
                    if( j == count )
                        arr[no] = 1 ;
                    dir_n( dname, no +1, arr );
                }
            }
            else{
                j++ ;
                file_count++ ;
                for( i = 0 ; i < no ; i++ ){
                    if( arr[i] == 0 )
                        printf("│   ");
                    else
                        printf("    ");
                }
                if( j == count )
                        printf("└── ");
                    else
                        printf("├── ");
                
                printf("%s \n", de->d_name );
                reset();
            }
        }
        closedir(dir);
    }
    arr[no] = 0;
    if( no == 0 )
        printf("\n%d directories, %d files \n", dir_count, file_count );
    return ;
}

void dir_X( char *dir_name, int no ){
    DIR *dir;
    dir = opendir( dir_name ) ;
    if( dir == NULL )
        return ;

    if( no == 0 ){
        printf("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n");
        printf("<tree>\n");
        printf("    <directory name= \"%s\" > \n", dir_name);
    }

    struct dirent *de;
    char fname[64], dname[64] ;
    strcpy( dname, dir_name );
    int i ;

    if( dir!=NULL ){
        while( ( de = readdir(dir)) ){
            if( de->d_type == DT_DIR ){
                if( strcmp( de->d_name, ".") == 0 || strcmp( de->d_name, "..") == 0 );
                else {
                    dir_count++ ;
                    for( i = -1 ; i <= no ; i++ )
                        printf("    ");

                    strcpy( dname, dir_name ) ;
                    strcat( dname, "/");
                    strcat( dname, de->d_name);

                    printf("<directory name= \"%s\" > \n", de->d_name );
                    dir_X( dname, no +1 );
                    for( i = -1 ; i <= no ; i++ )
                        printf("    ");
                    printf("</directory> \n");
                }
            }
            else{
                file_count++ ;
                for( i = -1 ; i <= no ; i++ )
                    printf("    ");
                printf("<file name= \"%s\" ></file> \n", de->d_name );
            }
        }
        closedir(dir);
    }
    if( no == 0 ){
        printf("    </directory> \n");
        printf("    <report> \n");
        printf("        <directories> %d </directories> \n", dir_count );
        printf("        <files> %d </files> \n", file_count );
        printf("    </report> \n");
        printf("</tree> \n");
    }
    return ;
}

void dir_J( char *dir_name, int no ){
    DIR *dir;
    dir = opendir( dir_name ) ;
    if( dir == NULL )
        return ;

    if( no == 0 ){
        if( strcmp( dir_name, ".") == 0 )
            printf("[{\"type\":\"directory\",\"name\": \".\",\"contents\":[ \n");
        else
            printf("[ \n    {\"type\":\"directory\",\"name\": \"%s\",\"contents\":[ \n", dir_name );
    }

    struct dirent *de ;
    int i, count = -2, j = 0 ;
    while( ( de = readdir(dir)) )
        count++ ;

    closedir(dir);
    dir = opendir( dir_name ) ;
        
    char fname[64], dname[64] ;
    strcpy( dname, dir_name );

    if( dir!=NULL ){
        while( ( de = readdir(dir)) ){
            if( de->d_type == DT_DIR ){
                if( strcmp( de->d_name, ".") == 0 || strcmp( de->d_name, "..") == 0 );
                else {
                    j++ ;
                    dir_count++ ;
                    for( i = -1 ; i <= no ; i++ )
                        printf("    ");

                    printf("{\"type\":\"directory\",\"name\": \"%s\",\"contents\":[ \n", de->d_name );
                    strcpy( dname, dir_name ) ;
                    strcat( dname, "/");
                    strcat( dname, de->d_name);

                    dir_J( dname, no +1 );
                    for( i = -1 ; i <= no ; i++ )
                        printf("    ");
                    if( j == count )
                        printf("]} \n");
                    else
                        printf("]}, \n");
                }
            }
            else{
                j++ ;
                file_count++ ;
                for( i = -1 ; i <= no ; i++ )
                    printf("    ");
                printf("{\"type\":\"file\",\"name\":\"%s\"}", de->d_name );
                if( j == count )
                    printf(" \n");
                else
                    printf(", \n");
            }
        }
        closedir(dir);
    }
    if( no == 0 ){
        printf("    ]}, \n");
        printf("    {\"type\":\"report\",\"directories\": %d,\"files\": %d} \n", dir_count, file_count );
        printf("] \n");
    }
    return ;
}

// P = 0
// I = 1
void dir_P( char *dir_name, int no, int *arr, int mode, char *patt ){
    DIR *dir;
    dir = opendir( dir_name ) ;
    if( dir == NULL )
        return ;

    if( no == 0 ){
        yellow();
        printf("%s \n", dir_name );
        reset();
    }

    struct dirent *de;
    int i, count = -2, j = 0 ;
    while( ( de = readdir(dir)) )
        count++ ;

    closedir(dir);
    dir = opendir( dir_name ) ;

    char fname[64], dname[64] ;
    strcpy( dname, dir_name );

    if( dir!=NULL ){
        while( ( de = readdir(dir)) ){
            if( de->d_type == DT_DIR ){
                if( strcmp( de->d_name, ".") == 0 || strcmp( de->d_name, "..") == 0 );
                else {
                    j++ ;
                    dir_count++ ;
                    for( i = 0 ; i < no ; i++ ){
                        if( *(arr+i) == 0 )
                            printf("│   ");
                        else
                            printf("    ");
                    }
                    if( j == count )
                        printf("└── ");
                    else
                        printf("├── ");
                    strcpy( dname, dir_name ) ;
                    strcat( dname, "/");
                    strcat( dname, de->d_name);

                    yellow();
                    printf("%s \n", de->d_name );
                    reset();

                    if( j == count )
                        arr[no] = 1 ;
                    dir_P( dname, no +1, arr, mode, patt );
                }
            }
            else{
                j++ ;
                if( ( mode == 0 && str_str( de->d_name, patt ) != -1 ) || ( mode == 1 && str_str( de->d_name, patt ) == -1 ) ){
                    file_count++ ;
                    for( i = 0 ; i < no ; i++ ){
                        if( arr[i] == 0 )
                            printf("│   ");
                        else
                            printf("    ");
                    }
                    if( j == count )
                        printf("└── ");
                    else
                        printf("├── ");
                    cyan();
                    printf("%s \n", de->d_name );
                    reset();
                }
            }
        }
        closedir(dir);
    }
    arr[no] = 0;
    if( no == 0 )
        printf("\n%d directories, %d files \n", dir_count, file_count );
    return ;
}
