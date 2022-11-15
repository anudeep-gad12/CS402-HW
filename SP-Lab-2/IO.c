#include <stdlib.h>
#include <stdio.h>
#include "IO.h"

FILE *file;

int open_file(char* inputfile)
{
    file = fopen(inputfile, "r");
    if (file == 0) {
        return -1; 
    }else {
        return 0;
    }
}

int write_file(char* inputfile){
    file = fopen(inputfile, "a");
    if(file == 0) {
        return -1;
    }else{
        return 0;
    }
}

void close_file(){
    fclose(file);
}



int read_int(char DB[], int option, int* var)
{
    int a,b;
    char c[64],d[64];
    if (option == 1){
        sscanf(DB, "%d %s %s %d", var, c, d, &b);
    }
    else{
        sscanf(DB, "%d %s %s %d", &a, c, d, var);
    }
    return 0;
}

int read_string(char DB[], int option, char y[])
{
    int a,b;
    char c[64],d[64];
    if (option == 1) {
        sscanf(DB, "%d %s %s %d", &a, y, d, &b);
    }
    else{
        sscanf(DB, "%d %s %s %d", &a, c, y, &b);
    }
    return 0;

}
