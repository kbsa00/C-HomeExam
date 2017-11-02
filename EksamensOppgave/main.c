#include <stdio.h>
#include <malloc.h>
#include <memory.h>
#include <stdlib.h>
#include "header.h"



void checkNode(char * textline){

    Node * conducter = root;

    if(conducter != NULL){

        char * ph = strtok(textline,"\". ");

        while(ph != NULL) {

            int index = 0;

            if(strcmp(ph, "=") == 0){
                ph = strtok(NULL,"=");
            }

            if(ph[0] == '\"'){
                ph = strtok(ph, "\"");
                conducter->pszString = calloc(1,sizeof(ph));
                strcpy(conducter->pszString, ph);
                printf("Value: %s has now been placed in %s-Node", conducter->pszString, conducter->pszName);
                break;
            } else{

                ULONG a;
                a = (ULONG) atoi(ph);

                if(a > 0){
                    conducter->ulIntval = a;
                    printf("Value: %lu has now been placed in %s-Node", conducter->ulIntval, conducter->pszName);
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
        exit(0);
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
            parentNode->pnNodes[index] = subnode;
            return parentNode;
        }

        index++;
    }

    return 0;
}

void printAll(Node * current, char * folder) {

   /* char *  pfolder = malloc(sizeof(char) + strlen(folder + 2));

    for (int i = 0; i < MAX_NODE ; i++){

        if(current->pnNodes[i] != NULL){
            strcpy(pfolder, folder);
            pfolder = realloc(pfolder,sizeof(char) * strlen(folder) + strlen(current->pnNodes[i]->pszName + 2));
            strcat(pfolder, ".");
            strcat(pfolder, current->pnNodes[i]->pszName);
            printAll(current->pnNodes[i], pfolder);
        }
    }

    if(current->pnNodes[0] == NULL){

        if(current->pszString != NULL){
            printf("%s = %s.", folder, (current->pszString));
            printf("\n");
        }
        else{
            printf("%s = %lu", folder, current->ulIntval);
            printf("\n");
        }
    }*/
}



void GetType(char * string){

    Node * conducter = root;

    if(conducter != NULL) {

    char *del = ".";
        char * token = strtok(string, del);

        while (token != NULL) {

            int index = 0;

            do{

                if(strcmp(conducter->pnNodes[index]->pszName, token) == 0){
                    conducter = conducter->pnNodes[index];
                    break;
                }

                index++;
            }while(index < MAX_NODE);


            if(conducter->pszString !=  NULL){
                printf("Mappen inneholder en %s mer spesifikt: %s", stringValue, conducter->pszString);
            }
            else if(conducter->ulIntval != 0){
                printf("Mappen inneholder en %s, mer spesifikt: %lu", intvalue, conducter->ulIntval);
            }

            token = strtok(NULL, del);
            }
    }else{
        printf("Noe gikk galt med Root");
        exit(0);
    }


}



int main(void) {
    root = malloc(sizeof(Node));
    root->pszName = "root";

    char * filename = "file.txt";
    readFile(filename);
    char string[40] = "config.update.interval";

    GetType(string);



    /*char *pfolder;
    pfolder = malloc(sizeof(char) * sizeof(strlen(folder) + 1));

    int counter = 0;

    for (int i = 0; i < MAX_NODE; i++) {

        if (current->pnNodes[i] != NULL) {
            strcpy(pfolder, folder);
            pfolder = realloc(pfolder, sizeof(char) * sizeof(strlen(pfolder) + sizeof(current->pnNodes[i]->pszName + 1)));
            strcat(pfolder, ".");
            strcat(pfolder, current->pnNodes[i]->pszName);
            printAll(current->pnNodes[i], pfolder);
        } else{

            counter++;
        }
    }

    if (counter == MAX_NODE) {

        if (current->pszString != NULL) {

            printf("%s = %s", folder, current->pszString);
            printf("\n");


        } else if (current->ulIntval > 0) {
            printf("%s = %lu", folder, current->ulIntval);
            printf("\n");
        }
    }*/


   /* while (token != NULL) {
        int counter = 0;
        int index = 0;

        while(index < MAX_NODE){

            if(strcmp(conducter->pnNodes[index]->pszName, token) == 0){
                conducter = conducter->pnNodes[index];
                break;
            }

            index++;
        }

        if(conducter->pszString != NULL){
            printf("\nNøkkel verdien du sendte inn inneholder %s mer spesifikt %s", stringValue, conducter->pszString);
        }
        else if(conducter->ulIntval != 0){
            printf("\nNøkkel verdien du sendte inn inneholder %s mer spesifikt tallet %lu", intvalue, conducter->ulIntval);
        }


        token = strtok(NULL, del);
    }*/
    return 0;
}