#include <stdio.h>
#include <malloc.h>
#include <memory.h>
#include <ctype.h>
#include <stdlib.h>
#include "header.h"


void checkNode(char * splitString);
Node * createSubNode(Node * parentNode, char * string);


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



    for(int i = 0; i < counterLines; i++){
       checkNode(*(dataValue+i));
    }
}

void sortAlphabetical(char * array[]){
    
}

void checkNode(char * splitString){

    Node * conducter = root;


    if(conducter != NULL){

        char * ph = strtok(splitString,"\". ");

        while(ph != NULL) {

            int index = 0;

            if(strcmp(ph, "=") == 0){
                ph = strtok(NULL,"=");
            }

            if(ph[0] == '\"'){
                ph = strtok(ph, "\"");
                conducter->pszString = calloc(1,sizeof(ph));
                strcpy(conducter->pszString, ph);
                printf("Value: %s has now been placed in %s-Node", ph, conducter->pszName);
                break;
            } else{
                ULONG a;
                a = (ULONG) atoi(ph);

                if(a > 0){
                    conducter->ulIntval = a;
                    printf("Value: %d has now been placed in %s-Node", a, conducter->pszName);
                    break;
                }

            }



            while (index < MAX_NODE){

                if(conducter->pnNodes[index] != NULL){

                    if(strcmp(conducter->pnNodes[index]->pszName, ph) == 0){
                        printf("Node is already created: %s\n", conducter->pnNodes[index]->pszName);
                        conducter = conducter->pnNodes[index];
                        break;

                    }

                }
                else if(conducter->pnNodes[index] == NULL){
                    conducter = createSubNode(conducter, ph);

                    index = 0;
                    while(index < MAX_NODE){
                        if(strcmp(conducter->pnNodes[index]->pszName, ph) == 0){
                            conducter = conducter->pnNodes[index];
                            printf("%s-node was succesfully created\n",conducter->pszName);
                            break;
                        }
                        index++;
                    }
                    break;
                }
                index++;
            }

            ph = strtok(NULL, "\". ");
        }
    }

    else{
        printf("Conducter == NULL, Something went wrong with root");
    }

    printf("\n\n");

}


Node * createSubNode(Node * parentNode, char * string){


    int index = 0;

    while(index < MAX_NODE){

        if(parentNode->pnNodes[index] == NULL){
            printf("Will now create %s-node for the first time\n", string);
            Node * subnode = calloc(1,sizeof(Node));
            subnode->pszName = malloc(sizeof(string)+1);
            strcpy(subnode->pszName, string);
            //subnode->pszName[sizeof(string)] = '\0';
            parentNode->pnNodes[index] = subnode;
            printf("Has now created %s-node and puts in %s-node\n", subnode->pszName, parentNode->pszName);
            return parentNode;
        }

        index++;
    }


    return 0;
}


int main(void) {
    root = malloc(sizeof(Node));
    root->pszName = "root";

    char * filename = "file.txt";
    readFile(filename);


    //TODO ETTER DU ER FERDIG MED DETTE, LAG EN OPTIMALISERT BUBBLESORT FUNC SOM sorterer tekstarryaet..
    
    return 0;
}