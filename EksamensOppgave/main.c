#include <stdio.h>
#include <malloc.h>
#include <memory.h>
#include "header.h"


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

void createNode(char * splitString){

    Node * conducter = root;
    int counter = 0;

    if(conducter != NULL){

        char * ph = strtok(splitString,".=");

        while(ph != NULL) {

            for(int j = 0; j < MAX_NODE; j++){

                if(conducter->pnNodes[j] == NULL) {
                    conducter->pnNodes[j] = NULL;
                }

            }



            for(int i = 0; i < MAX_NODE; i++){

                if(conducter->pnNodes[i] != NULL){

                    if(strcmp(conducter->pnNodes[i]->pszName, ph) == 0){
                    printf("Node is already created: %s\n", conducter->pnNodes[i]->pszName);
                    conducter = conducter->pnNodes[i];
                        
                        //TODO: TWO IF STATEMENTS FOR CHECKING IF ITS A VALUE..
                    }


                }
                else{
                    counter++;
                }
            }


            if(counter == MAX_NODE){
                int index = 0;

                while(index < MAX_NODE){

                    if(conducter->pnNodes[index] == NULL) {
                        printf("Node has never been created: %s\n", ph);
                        Node * subnode = malloc(sizeof(Node));
                        subnode->pszName = ph;
                        printf("Creating %s inside node: %s\n", subnode->pszName, conducter->pszName);
                        //TODO SOMETHING GOES WRONG IN THIS CODE BENETH...
                        conducter->pnNodes[index] = malloc(sizeof(Node));
                        conducter->pnNodes[index] = subnode;
                        conducter = subnode;
                        counter = 0;


                        break;
                    }

                    index++;
                }

            }


            ph = strtok(NULL, ".=");
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