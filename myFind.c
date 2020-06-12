//
// Created by Maxi on 6/8/20.
//
#define _XOPEN_SOURCE 700
#include <libgen.h>
#include "ftw.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"


int processEntry(char *filePath, ...);

char *filename = NULL;

int main(int argc, char *argv[])
{
    filename = NULL;
    char *searchLocation = NULL;
    // check parameters match.
    // if there is only one parameters, set searchLocation to local location
    if (argc == 2)
    {
        // set target file name
        filename = argv[1];
        // set searchLocation
        searchLocation = "./";
    }
        // if there is two parameters, set searchLocation to customized location
    else if (argc == 3)
    {
        // set target file name
        filename = argv[1];
        // set searchLocation
        searchLocation = argv[2];
    }
        // if parameters not match, warning message.
    else
    {
        perror("myFind <file-name> [location]");
        // exit
        exit(0);
    }

    // Using nftw() (new file tree walker) to work through a given directory
    // https://linux.die.net/man/3/nftw
    if (nftw(searchLocation, processEntry, 25, 0) == -1)
    {
        // If there is an error happen, show error message.
        perror("Call to nftw failed.");
        // exit with failure(1).
        exit(EXIT_FAILURE);
    }
    // exit
    exit(0);
}

// this function will be called by nftw() in main
// it manage what we gonna do with thr file we found in a directory.
int processEntry(char *filePath, ...)
{
    // basename() get the deepest file name in a path.
    // compare the deepest file name in a path with our target file name to check if it's the file we are looking for.
    if (strcmp(basename(filePath), filename) == 0)
    {
        // if find the file, print the path of it.
        printf("%s %s\n", "found: ", filePath);
    }
    // return 0 to let nftw continue the search or travel.
    return 0;
}