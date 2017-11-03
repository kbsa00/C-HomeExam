#include "header.h"
#include <stdio.h>
#include <malloc.h>
#include <memory.h>
#include <stdlib.h>
#include <stdbool.h>



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

    sortAlphabetical(dataValue, counterLines);


    for(int i = 0; i < counterLines; i++){
        checkNode(*(dataValue+i));
    }
}

void sortAlphabetical(char * textFile[], int size){

    //Sorting the textfile before making nodes of them, So that I dont need to sort the B-Tree
    bool swapped;

    char * temp;

    for(int i = 0; i < size; i++){

        swapped = false;

        for(int j = 1; j < size; j++){

            if(strcmp(*(textFile+j-1), *(textFile+j)) > 0){
                temp = *(textFile+j);
                *(textFile+j) = *(textFile+j-1);
                *(textFile+j-1) = temp;
                swapped = true;
            }
        }

        if(swapped == false){
            break;
        }

    }
}


Node * GetCurrentNode(char * string){

    Node * conducter = root;

    if(conducter != NULL){
        char * token = strtok(string, ".");

        while(token != NULL){

            int index = 0;
            int counter = 0;

            do {

                if(conducter->pnNodes[index] != NULL){
                    counter++;
                    if (strcmp(conducter->pnNodes[index]->pszName, token) == 0) {
                        conducter = conducter->pnNodes[index];
                        break;
                    }
                }
                else{
                    counter++;
                }


                index++;

            } while (index < MAX_NODE);

            if(counter == MAX_NODE){
                printf("ERROR: %s\n", feilkode);
                printf("Avslutter programmet...");
                exit(0);
            }

            token = strtok(NULL, ".");
        }

        return conducter;

    } else{
        printf("Noe gikk galt med Root..");
        exit(0);
    }
}

