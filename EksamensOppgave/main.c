#include <stdio.h>
#include <malloc.h>
#include <memory.h>
#include <ctype.h>
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



    for(int i = 0; i < 1; i++){
       checkNode(*(dataValue+i));
    }
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
            }

            while (index < MAX_NODE){

                if(conducter->pnNodes[index] != NULL){

                    if(strcmp(conducter->pnNodes[index]->pszName, ph) == 0){
                    printf("Node is already created: %s\n", conducter->pnNodes[index]->pszName);
                    conducter = conducter->pnNodes[index];

                    }

                }
                else if(conducter->pnNodes[index] == NULL){
                    conducter = createSubNode(conducter, ph);
                    break;
                }
                index++;
            }

                index = 0;
                while(index < MAX_NODE){

                if(strcmp(conducter->pnNodes[index]->pszName, ph) == 0){
                    conducter = conducter->pnNodes[index];
                    printf("%s-node was succesfully created\n",conducter->pszName);
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
            subnode->pszName = malloc(sizeof(strlen(string))+1);
            strcpy(subnode->pszName, string);
            subnode->pszName[sizeof(string)] = '\0';
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

/*    if(conducter != NULL){

        int index = 0;
        int counter = 0;
        char * ph = strtok(splitString,". =");

        while(ph != NULL) {

            for (int i = 0; i < MAX_NODE; i++) {

                if (conducter->pnNodes[i] == NULL) {
                    counter++;
                }
                else if (conducter->pnNodes[i] != NULL) {
                    conducter = conducter->pnNodes[i];

                    if (strcmp(conducter->pszName, splitString) == 0) {

                        printf("\nAlready created node: %s", conducter->pszName);

                        int co = 0;

                        counter = 0;
                        while (co < MAX_NODE) {

                            if (conducter->pnNodes[co] != NULL) {
                                conducter = conducter->pnNodes[co];

                                if (strcmp(conducter->pszName, ph) == 0) {
                                    conducter = subnode;
                                }
                                else {
                                    printf("\nCreating new node: %s", ph);
                                    int co = 0;
                                    subnode->pszName = ph;
                                    conducter->pnNodes[co] = subnode;
                                    conducter = subnode;
                                }
                            }
                            else if(conducter->pnNodes[co] == NULL){
                                counter++;
                            }

                            co++;
                        }
                    }
                    else {
                        //TODO: HUSK Å SETT HEADER SIN VERDI SOM OPPDATERING HER INNE.....
                        printf("\n\n%s", ph);
                    }

                }
                else if (isdigit(ph)) {
                    conducter->ulIntval = (ULONG) ph;
                    conducter = root;
                }

            }

            if (counter == MAX_NODE) {
                printf("Creating new node for the first time: %s", ph);
                subnode->pszName = ph;
                conducter->pnNodes[index] = subnode;

            }

            ph = strtok(NULL, ". =");
        }
    }

    else{
        printf("Conducter == NULL, Something went wrong with root");
    }*/
    return 0;
}