#include <stdio.h>
#include <malloc.h>
#include <memory.h>
#include "header.h"


typedef struct _NODE{
    char * pszName;
    ULONG ulIntval;
    char * pszString;
    struct _NODE * pnNodes[MAX_NODE];

}Node;

void readFile(char * filename){

    FILE * fp;
    fp = fopen(filename, "r");
    int line;
    int counterLines = 0;

    if(fp != NULL){
        while(!feof(fp)){
            line = fgetc(fp);

            if(line == '\n'){
                counterLines++;
            }
        }
    }
    else{
        printf("ERROR: Can't read file");
    }

    rewind(fp);

    int  countLengthStrings[counterLines];
    int index = 0;
    int counter = 0;

    do{
        line = fgetc(fp);

        if(line != '\n' && line != '\0'){
            counter++;
        }
        else{
            countLengthStrings[index] =  counter;
            counter = 0;

            index++;
        }
    }
    while(!feof(fp));

    for(int i = 0; i < counterLines; i++) printf("%d", countLengthStrings[i]);

    rewind(fp);

    fclose(fp);

    FILE * fpointer;
    fpointer = fopen(filename, "r");

    index = 0;
    char * readline;
    char * dataValue[counterLines];

    //TODO FIND THE EXCACT BYTE SIZE SO THAT YOU CAN INPUT THE TEXTFILE IN DATAVALUE..


    if(fpointer != NULL) {

        while(!feof(fp)) {
            int current = countLengthStrings[index];

            printf("%zu\n", sizeof(readline));

            index++;
        }
    }
    else{
        printf("ERROR");
    }


    fclose(fpointer);

}

int main(void) {
    char * filename = "file.txt";
    readFile(filename);

    return 0;
}