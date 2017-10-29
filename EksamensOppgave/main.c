#include <stdio.h>
#include <malloc.h>
#include <memory.h>
#include <ctype.h>
#include "header.h"

void splitUp(char *string);
void createNode(char * splitString);


Node * root;

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



    for(int i = 0; i < 1; i++){
       createNode(*(dataValue+i));
    }
}

/*

void splitUp(char * string) {

    char *ph = strtok(string, ". =");

        while (ph != NULL) {

            createNode(ph);

            ph = strtok(NULL, ". =");
        }
}*/


void createNode(char * splitString){

    Node * conducter = root;
    Node * subnode = malloc(sizeof(Node));

    if(conducter != NULL){
        int index = 0;
        int counter = 0;
        char * ph = strtok(splitString,". =");

        while(ph != NULL){

            for(int i = 0; i < MAX_NODE; i++){

                if(conducter->pnNodes[i] == NULL){
                    counter++;
                }

                 else if(conducter->pnNodes[i] != NULL){
                    conducter = conducter->pnNodes[i];

                    if(strcmp(conducter->pszName, splitString) == 0){
                        printf("\nAlready created String");
                        printf("\nCreating node: %s", ph);
                        int co = 0;
                        subnode->pszName = ph;
                        conducter->pnNodes[co] = subnode;
                        conducter = subnode;

                    } else{
                        //TODO: HUSK Å SETT HEADER SIN VERDI SOM OPPDATERING HER INNE.....
                        conducter = root; 
                    }
                }
                else if(isdigit(ph)){
                    conducter->ulIntval = (ULONG) ph;
                    conducter = root;
                }
            }

            if(counter == MAX_NODE){
                printf("Creating node for the first time: %s", ph);
                subnode->pszName = ph;
                conducter->pnNodes[index] = subnode;

            }

            ph = strtok(NULL,". =");

        }
    }
    else{
        printf("Conducter == NULL, Something went wrong with root");
    }

}

int main(void) {
    root = malloc(sizeof(Node));
    root->pszName = "root";

    char * filename = "file.txt";
    readFile(filename);

    /* for(int i = 0; i < MAX_NODE; i++){

            if(conducter->pnNodes[index] == NULL){
                if(strcmp(ph, splitString) == 0) {
                    subnode->pszName = ph;
                    conducter->pnNodes[index] = subnode;
                    printf("Created node: %s", subnode->pszName);
                    conducter = subnode;
                }

                else if(strcmp(conducter->pszName, splitString) == 0){
                    printf("\n%s is already created: ", splitString);
                    //TODO  if- statment with strings that starts with *
                    printf("\nWill now create node for: %s", ph );
                    Node * subnode2 = malloc(sizeof(Node));
                    subnode2->pszName = ph;
                    subnode->pnNodes[index] = subnode2;
                    conducter = subnode2;

                }
            }


           }*/
    return 0;
}