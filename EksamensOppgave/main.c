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

Node * root = NULL;

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

    long size;
    fseek(fp, 0, SEEK_END);
    size = ftell(fp);
    rewind(fp);
    fclose(fp);

    FILE * fpointer;
    fpointer = fopen(filename, "r");

    char readline[size];
    char * dataValue[counterLines];

    int index = 0 ;

    if(fpointer != NULL) {

        while(fgets(readline, sizeof(readline),fpointer) != NULL){
            dataValue[index] = malloc(sizeof(readline));
            strcpy(dataValue[index], readline);
            index++;
        }
    }
    else{
        printf("ERROR");
    }

    fclose(fpointer);
}


void createNodes(char * string){


}

int main(void) {
    char * filename = "file.txt";
    Node * root = malloc(sizeof(Node));
    readFile(filename);

    return 0;
}