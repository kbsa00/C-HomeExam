#include <stdio.h>
#include <malloc.h>
#include <memory.h>
#include <stdlib.h>
#include <ctype.h>
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

void printAll(Node * this){

    int index = 0;



    while(index < 6){

        if(this->pnNodes[index] != NULL){
            printf("%s.", this->pnNodes[index]->pszName);
            this = this->pnNodes[index];
            index = 0;

        }

        index++;
    }


   if(this->pnNodes[index] == NULL) {

       if(this->pszString == NULL){
           printf(" = %lu", this->ulIntval);
       } else{
           printf(" = %s", this->pszString);
       }


       printf("\nEverything was printed out..\n");
   } else{
       printAll(this);
   }

}



int main(void) {
    root = malloc(sizeof(Node));
    root->pszName = "root";

    char * filename = "file.txt";
    readFile(filename);

    printAll(root);

    
    return 0;
}