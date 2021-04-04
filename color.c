#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
#include "color.h"

void black(){
    printf("\033[0;30m");
    return ;
}

void red(){
    printf("\033[1;31m");
    return ;
}

void green(){
    printf("\033[1;32m");
    return ;
}

void yellow(){
    printf("\033[1;33m");
    return ;
}

void blue(){
    printf("\033[1;34m");
    return ;
}

void purple(){
    printf("\033[1;35m");
    return ;
}

void cyan(){
    printf("\033[1;36m");
    return ;
}

void white(){
    printf("\033[1;37m");
    return ;
}

void reset(){
    printf("\033[0m");
    return ;
}

void file_size( char *fname ){
    struct stat fileStat;
    if(stat( fname, &fileStat) < 0)    
        return ;
    printf("[ ");
    purple();
    printf("%ld bytes", fileStat.st_size );
    reset();
    printf(" ]");
    return ;
}

void file_permission( char *fname ){
    struct stat fileStat;
    if(stat( fname, &fileStat) < 0)    
        return ;
    printf("[ ") ;
    purple();
    printf( (S_ISDIR(fileStat.st_mode)) ? "d" : "-");
    printf( (fileStat.st_mode & S_IRUSR) ? "r" : "-");
    printf( (fileStat.st_mode & S_IWUSR) ? "w" : "-");
    printf( (fileStat.st_mode & S_IXUSR) ? "x" : "-");
    printf( (fileStat.st_mode & S_IRGRP) ? "r" : "-");
    printf( (fileStat.st_mode & S_IWGRP) ? "w" : "-");
    printf( (fileStat.st_mode & S_IXGRP) ? "x" : "-");
    printf( (fileStat.st_mode & S_IROTH) ? "r" : "-");
    printf( (fileStat.st_mode & S_IWOTH) ? "w" : "-");
    printf( (fileStat.st_mode & S_IXOTH) ? "x" : "-");
    reset();
    printf(" ]");
    return ;
}

void file_time( char *fname ){
    struct stat fileStat;
    if(stat( fname, &fileStat) < 0)    
        return ;
    char time[50];
    strftime(time, 50,"%Y-%m-%d %H:%M:%S", localtime(&fileStat.st_mtime));
    printf("[ ");
    purple();
    printf ("%s", time);
    reset();
    printf(" ]");
    return ;
}

void uid_num(){
    printf("[ ");
    purple();
    printf("%d", getuid());
    reset();
    printf(" ]");
}

void gid_num(){
    printf("[ ");
    purple();
    printf("%d", getgid());
    reset();
    printf(" ]");
}

int str_str(char *str, char *ch){
    int i = 0 ;
	char *p = str, *q = ch;
	while( *p != '\0' && *q != '\0' ){
		if( *p == *q )
			q++ ;
		else
			q = ch ;
		p++ ;
		i++ ;
	}
	if( *q == '\0' )
		return i -strlen( ch ) ;
	else
		return -1 ;
}

void version(){
    yellow();
    printf("tree v1.8.0 \n");
    printf("By Jayesh Gadilohar \n");
    reset();
    return ;
}

void help(){
    cyan();
    printf("usage : ./tree [option] folder name \n");
    printf("  ------- Listing options -------   \n");
    yellow();
    printf("  -a            All files are listed. \n");
    printf("  -d            List directories only. \n");
    printf("  -f            Print the full path prefix for each file. \n");
    printf("  -L level      Descend only level directories deep. \n");
    printf("  -P pattern    List only those files that match the pattern given. \n");
    printf("  -I pattern    Do not list files that match the given pattern. \n");
    cyan();
    printf("  ------- File options ------- \n");
    yellow();
    printf("  -Q            Quote filenames with double quotes. \n");
    printf("  -p            Print the protections for each file. \n");
    printf("  -s            Print the size in bytes of each file. \n");
    printf("  -D            Print the date of last modification or (-c) status change. \n");
    printf("  -u            Displays file owner or UID number. \n");
    printf("  -g            Displays file group owner or GID number. \n");
    cyan();
    printf("  ------- Graphics options ------- \n");
    yellow();
    printf("  -i            Don't print indentation lines. \n");
    printf("  -S            Print with CP437 (console) graphics indentation lines. \n");
    printf("  -n            Turn colorization off always (-C overrides). \n");
    cyan();
    printf("  ------- XML/JSON options ------- \n");
    yellow();
    printf("  -X            Prints out an XML representation of the tree. \n");
    printf("  -J            Prints out an JSON representation of the tree. \n");
    cyan();
    printf("  ------- Miscellaneous options ------- \n");
    yellow();
    printf("  --version     Print version and exit. \n");
    printf("  --help        Print usage and this help message and exit. \n");
    reset();
    return ;
}