#include <stdio.h>
#include <malloc.h>
#include <memory.h>
#include <stdlib.h>
#include "header.h"
#include <stdbool.h>
#include <setjmp.h>

/**
 * checkNode tar høyde for å sjekke om Noden allerede finnes i B-Treet.
 * Funksjonen setter også verdi for nodene. Om ikke en node finnes sender funksjonen
 * til en createSubnode som lager nodene og returnerer dette.
 * CheckNode vil så dobbelt sjekke om nodene blir faktisk laget.
 * Funksjonen printer også ut hele prossessen av å lage B-treet.
 *
 */

int lol;

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
/**
 * Denne funksjonen er dedikert for å opprette Nodene og plasserer disse i et B-tree struktur.
 * Funksjonen blir kalt på fra checkNode for hver gang en Node må lages. Og deretter
 * returnerer den noden som den har laget.
 */

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

/**
 * Funksjonen GetType tar i mot en key-value fra bruker og vil
 * presentere for brukeren om hvilken type node dette er.
 */

void GetType(char * namenode){
    Node * conducter;
    char * name = calloc(1, sizeof(strlen(namenode)));
    strcpy(name, namenode);

    //For å slippe å sjekke om noden finnes i denne funksjonen
    //Kaller jeg på en GetcurrentNode funksjon som tar i mot en Key-Value
    //Og søker etter denne noden, slik at vi slipper å søke etter den her og vil returnere noden til oss
    //GetCurrentNode vil ta høyde for at brukeren kanskje har skrevet feil.

    conducter = GetCurrentNode(name);

    if(conducter != NULL){

        if(conducter->pszString == NULL && conducter->ulIntval == 0){
            printf("Nøkkelnavnet du sendte inn er en %s\n",Mappe);
        }
        else if(conducter->pszString != NULL){
            printf("Nøkkelnavnet du sendte inn inneholder en %s\n",stringValue);
        }
        else if(conducter->ulIntval != 0){
            printf("Nøkkelnavnet du sendte inn inneholder en %s\n", intvalue);
        }

    }else{
        printf("Noe gikk galt med conducter");
        exit(0);
    }

}

/**
 * GetString funksjonen tar i mot en Keyvalue fra brukeren og returner Nodens String verdi.
 * I tillegg til at den tar høyde for at Noden ikke har en String verdi.
 */
 char * GetString(char * keyvalue){

    Node * conducter;
    char * namenode = calloc(1, sizeof(strlen(keyvalue)+1));
    strcpy(namenode,keyvalue);

    //Vi sender keyvalue til GetCurrentNode som returnerer noden om den finnes i treet.
    //Hvis ikke så vil den returnere en feilmelding og avslutter programmet.

    conducter = GetCurrentNode(namenode);

    if(conducter != NULL) {

        if (conducter->pszString != NULL) {

            return conducter->pszString;
        }
        else {
            printf("ERROR: %s\n", fDatatype);
        }
    }
    else{
        printf("Noe gikk galt med Conducter");
        exit(0);
    }
    return 0;
}

/**
 * GetString funksjonen tar i mot en Keyvalue fra brukeren og returner Nodens ULONG verdi.
 * I tillegg til at den tar høyde for at Noden ikke har en ULONG verdi.
 */

ULONG GetULONG(char * keyvalue){

    Node * conducter;
    char * namenode = calloc(1, sizeof(strlen(keyvalue)+1));
    strcpy(namenode,keyvalue);

    //Vi sender keyvalue til GetCurrentNode som returnerer noden om den finnes i treet.
    //Hvis ikke så vil den returnere en feilmelding og avslutter programmet.

    conducter = GetCurrentNode(namenode);

    if(conducter != NULL) {

        if (conducter->pszName == NULL) {
            printf("ERROR: %s\n", fDatatype);
        } else {

            return conducter->ulIntval;
        }
    } else{
        printf("Noe gikk galt med conducter");
        exit(0);
    }
    return 1;
}

void Delete(char * string){

    Node * conducter = root;
    Node * subnode;

    if(conducter != NULL){

        char * keyvalue = calloc(1, sizeof(strlen(string))+1);
        char * substring = malloc(sizeof(char) * sizeof(strlen(string+1)));
        strcpy(keyvalue,string);
        strcpy(substring, string);
        subnode = GetCurrentNode(keyvalue);


        if(subnode->pszString == NULL && subnode->ulIntval == 0){
            printf("Sletter mappe: %s \nSletter også alle undernoder i mappen..\n", subnode->pszName);

            for(int i = 0; i < MAX_NODE; i++){
                free(subnode->pnNodes[i]);
                subnode->pnNodes[i] = NULL;
            }

            char * del = ".";
            char * token = strtok(substring, del);
            bool boolean = false;
            while(token != NULL && boolean != true){

                int index = 0;

                while(index < MAX_NODE) {


                    if (strcmp(conducter->pnNodes[index]->pszName, substring) == 0) {
                        conducter = conducter->pnNodes[index];

                        for(int i = 0; i < MAX_NODE; i++){

                            if( strcmp(conducter->pnNodes[i]->pszName, subnode->pszName) == 0){
                                free(conducter->pnNodes[i]);
                                conducter->pnNodes[i] = NULL;
                                boolean = true;
                                printf("Mappen er nå SLETTET!\n");
                                break;
                            }

                        }
                        break;
                    }

                    index++;
                }



                token = strtok(NULL, del);

            }
        }
        else if(subnode->pszString != NULL || subnode->ulIntval != 0){
            char * del = ".";
            char * token = strtok(substring, del);

            printf("Du vil slette %s-node med en verdi\n", subnode->pszName);

            bool boolean = false;
            while(token != NULL && boolean != true){

                int index = 0;

                while(index < MAX_NODE){

                    if(strcmp(conducter->pnNodes[index]->pszName, token) == 0){
                        conducter = conducter->pnNodes[index];
                        break;
                    }

                    index++;
                }


                for(int i = 0; i < MAX_NODE; i++){

                    if(conducter->pnNodes[i] != NULL) {
                        int ret;

                        ret = strncmp(conducter->pnNodes[i]->pszName, subnode->pszName, sizeof(strlen(subnode->pszName)));

                        if (ret == 0){
                            printf("Sletter nå %s\n", subnode->pszName);
                            free(conducter->pnNodes[i]);
                            conducter->pnNodes[i] = NULL;
                            printf("SLETTET fra B-Treet!\n");
                            boolean = true;
                            break;

                        }
                    }

                }

                token = strtok(NULL, del);
            }

        }

    }
    else{
        printf("Noe gikk galt med Root\n");
        exit(0);
    }

}

void GetText(char * undernode, char * hovednode){

    Node * conducter;
    conducter = root;

    if(conducter != NULL){


        conducter = rekursiv(conducter,hovednode,undernode);

        puts(conducter->pszName);


    }
    else{
        printf("Noe gikk galt med Conducter");

    }



}

Node * rekursiv(Node * current, char * mainnode, char * undernode) {


        Node *subnode;
        int counter = 0;


        for (int i = 0; i < MAX_NODE; i++) {

            if(lol == 0) {

                if (current->pnNodes[i] != NULL) {

                    if (strcmp(current->pszName, mainnode) == 0) {

                        if (current->pnNodes != NULL) {

                            break;
                        }
                    }

                   subnode = rekursiv(current->pnNodes[i], mainnode, undernode);
                    if(subnode != NULL){
                        return subnode;
                    }
                    else{
                        return NULL;
                    }
                }
            }
            counter++;
        }

        if (counter == MAX_NODE) {

            if (strcmp(current->pszName, undernode) == 0) {

                subnode = current;

                return subnode;

            }

        }


        for (int i = 0; i < MAX_NODE; i++) {

            if (current->pnNodes[i] != NULL) {
                if (strcmp(current->pnNodes[i]->pszName, undernode) == 0) {
                    subnode = current->pnNodes[i];

                    return subnode;

                }

            }


        }

    }


void printAll(Node * current, char * folder) {

   /*  char *  pfolder = malloc(sizeof(char) + strlen(folder + 2));

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


int main(void) {
    root = malloc(sizeof(Node));
    root->pszName = "root";

    char * filename = "file.txt";
    readFile(filename);
    Node * r = root;
    puts("hallo");
    //GetText("hggu", "guug");

   // printAll(root, root->pszName);


    return 0;
}