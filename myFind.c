//
// Created by Tilliw on 6/8/20.
//
#include "ftw.h"
#include "stdio.h"
#include "stdlib.h"


void processEntry(char *filePath,...);

int main(int argc, char *argv[])
{
    char *filename = NULL;
    char *searchLocation = NULL;
    // check parameters match.
    // if there is only one parameters, set searchLocation to local location
    if (argc == 1)
    {
        filename = argv[0];
        searchLocation = "./";
    }
        // if there is two parameters, set searchLocation to customized location
    else if (argc == 2)
    {
        filename = argv[0];
        searchLocation = argv[1];;
    }
        // if parameters not match, warning message.
    else
    {
        perror("myFind <file-name> [location]");
    }

    if (nftw(searchLocation, processEntry, 25, 0))
    { ;
    }
    // exit
    exit(0);
}

void processEntry(char *filePath,...)
{
    ;
}