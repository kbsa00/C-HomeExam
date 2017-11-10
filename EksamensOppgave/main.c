#include <stdio.h>
#include <malloc.h>
#include <memory.h>
#include <stdlib.h>
#include "header.h"
#include <stdbool.h>

char * streng = NULL;
char input[70];

/**
 * checkNode tar høyde for å sjekke om Noden allerede finnes i B-Treet.
 * Funksjonen setter også verdi for nodene. Om ikke en node finnes sender funksjonen
 * til en createSubnode som lager nodene og returnerer dette.
 * CheckNode vil så dobbelt sjekke om nodene blir faktisk laget.
 * Funksjonen printer også ut hele prossessen av å lage B-treet.
 *
 */


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

char * GetType(char * namenode){
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
            return Mappe;
        }
        else if(conducter->pszString != NULL){
            return stringValue;
        }
        else if(conducter->ulIntval != 0){
            return intvalue;
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

/**
 *  Delete funksjonen vil ta i mot en nøkkelverdi og slette brukerens node.
 *  Funksjonen tar høyde for at du kan slette en mappe med underliggende noder og
 *  en node med underverdi.
 *
 */

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
            printf("Deleting folder: %s \nAlso deleting nodes in the folder..\n", subnode->pszName);

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
                                printf("Folder is now DELETED!\n");
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

            printf("You want to delete %s-node with a value\n", subnode->pszName);

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
                            printf("Deleting now %s\n", subnode->pszName);
                            free(conducter->pnNodes[i]);
                            conducter->pnNodes[i] = NULL;
                            printf("Deleted from the B-Tree!\n");
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
/**
 * Funksjonen tar i mot to streng navn, en mappe node og en node med verdi.
 * Funksjonen vil sender videre informasjonen til en rekursiv funksjon som leter gjennom
 * B-Treet og returnerer dette. Dermed vil GetText funksjonen returnere nodens string verdi
 * eller returnere NULL hvis det ikke finnes.
 *
 */
char * GetText(char * undernode, char * hovednode){

    Node * conducter;
    conducter = root;

    if(conducter != NULL){

        char * string;
        string =  GetTextRekursiv(conducter,hovednode,undernode);

        if(string != NULL){

            return string;
        }
        else{
            return NULL;
        }


    }
    else{
        printf("Noe gikk galt med Conducter");

    }



}

/**
 * En rekursiv funskjon, som tar i mot en node og to string i parameteren.
 * Funkskjonen kjører rekursiv gjennom hele B-Treet for å finne undernoden
 * med verdi. Om den ikke finner i den gitte Noden du er utkikk etter. Vil den
 * sjekke en annen gren og etter den finner dette vil den returnere
 * noden.
 *
 */

char * GetTextRekursiv(Node * current, char * mainnode, char * undernode) {


    int counter = 0;


    for (int i = 0; i < MAX_NODE; i++) {

        counter++;

        if (current->pnNodes[i] != NULL) {

            if (strcmp(current->pszName, mainnode) == 0) {
                 break;
            }



            streng = GetTextRekursiv(current->pnNodes[i], mainnode, undernode);
        }

    }

    //Vil returnere hvis den finner undernoden i en annen gren enn MainNode..
    if (counter == MAX_NODE) {

        if (strcmp(current->pszName, undernode) == 0){

            char * value1 = current->pszString;

            if(streng == NULL) {

                return value1;

            }
        }

    }


    if(strcmp(current->pszName, mainnode) == 0){

        for(int i = 0; i < MAX_NODE; i++){

            if(current->pnNodes[i] != NULL) {

                if (strcmp(current->pnNodes[i]->pszName, undernode) == 0) {
                    char * value = current->pnNodes[i]->pszString;
                    return value;
                }
            }

        }

    }

    if(streng != NULL){
        return streng;
    }
    else
    {
        return NULL;
    }



}
/**
 * Enumurate funksjonen enumurerer alle underliggende noder i mappen.
 * Dermed bruker den en callbackfunksjon, som printer ut nodens navn og verdi.
 */

void Enumurate(char * keyname, void (*callback)(Node * current)){

    char * path = calloc(1, sizeof(strlen(keyname)+1));
    strncpy(path, keyname, strlen(keyname)-1);

    Node * conducter;
    conducter = root;

    if(conducter != NULL){
        conducter = GetCurrentNode(path);

        for (int i = 0; i < MAX_NODE ; i++) {

            if(conducter->pnNodes[i] != NULL){
               callback(conducter->pnNodes[i]);
            }

        }

    } else{
        printf("Noe gikk galt med conducter");
    }
    free(path);
}


/**
 * Callback funksjonen vil printe ut navnet på noden og printer ut deres verdier.
 */

void callback(Node * current){

    printf("Name: %s\t", current->pszName);

    if(current->pszString != NULL){
        printf("\tString verdi: %s", current->pszString);
    }
    else{
        printf("\tULONG verdi: %lu", current->ulIntval);
    }
    printf("\n");
}




int main(void) {
    root = malloc(sizeof(Node));
    root->pszName = "root";

    char * filename = "file.txt";
    readFile(filename);



    while(1){

        int num;

        puts("\nPress 1 for the function GetType()");
        puts("Press 2 for the function GetString()");
        puts("Press 3 for the function GetInt/GetUlong()");
        puts("Press 4 for the function GetText");
        puts("Press 5 for the function Delete()");
        puts("Press 6 for the function Enumurate()");
        puts("Press 7 for Exiting the program\n");

        printf("Insert your input: ");
        scanf("%d", &num);

        switch(num){

            case 1:
                printf("\nYou have now chosen GetType.\nPlease write input like 'config.update.interval' or 'string.no'\n");
                char * typevalue;
                printf("Input your string: ");
                scanf("%s",input);
                typevalue = GetType(input);
                printf("\n%s\n", typevalue);
                break;

            case 2:
                printf("\nYou have now chosen GetString.\nPlease write input like 'config.update.server1' or 'strings.no.header'\n");
                char * stringvalue;
                printf("Input your string: ");
                scanf("%s",input);
                stringvalue = GetString(input);
                printf("\nString value returned: %s\n", stringvalue);
                break;

            case 3:
                printf("\nYou have now chosen GetULONG.\nPlease write input like 'config.update.server1' or 'strings.no.header'\n");
                ULONG ulongvalue;
                printf("Input your string: ");
                scanf("%s", input);
                ulongvalue = GetULONG(input);
                printf("\nULONG value returned: %lu\n\n", ulongvalue);
                break;

            case 4:
                printf("\nYou have now chosen GetText.\nPlease write input like 'button_cancel' and 'no'\n");
                char * value;
                char name[70];
                printf("Input the underNode, f.e. 'button_cancel' : ");
                scanf("%s", name);
                printf("\nInput the mainNode, f.e. 'no' : ");
                scanf("%s", input);
                value = GetText(name, input);
                printf("\nValue returned: %s\n", value);
                break;

            case 5:
                printf("\nYou have now chosen Delete.\nPlease write input like 'strings.no.' or 'config.update.interval' \n");
                printf("Input your string: ");
                scanf("%s", input);
                Delete(input);
                break;


            case 6:
                printf("\nYou have now chosen Enumerate.\nPlease write input like 'config.update.*' \n");
                printf("Input your string: ");
                scanf("%s", input);
                Enumurate(input, callback);
                break;

            case 7:
                printf("\nYou choose to end the program.\nHave a great day!");
                exit(0);


            default: printf("Wrong number input\n");


        }


    }


    return 0;
}