#include "header.h"
#include <stdio.h>
#include <malloc.h>
#include <memory.h>
#include <stdlib.h>
#include <stdbool.h>


/**
 *
 * Denne funksjonen vil lese filen som brukeren har bestemt og vil deretter legge
 * hvert linje av tekstfilen i minnet (array), som senere skal tas i bruk for å lage
 * B-treet vårt.
 */
void readFile(char * filename){

    FILE * fp;
    fp = fopen(filename, "r");
    int line;
    int counterLines = 0;

    //Teller opp hvor mange tekstlinjer det er i filen.
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

    //Legger hvert linje av tekstfilen i en array
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

    //Lager B-Treet etter at tekstfilen er lagret i minnet og er ferdig sortert.
    for(int i = 0; i < counterLines; i++){
        checkNode(*(dataValue+i));
    }
}

/**
 * Denne funksjonen er laget for å sortere tekstfilen som ble laget i ReadFile funksjonen
 * Funksjonen vil dermed sortere hvert tekstlinje basert alfabetisk rekkefølge
 * Slik at når B-Treet blir laget så vil den bli laget basert på alfabetisk rekkefølge.
 */
void sortAlphabetical(char * textFile[], int size){

    //Bruker en optimalisert Bubble-sort algoritme for å sortere hver linje i tekstfilen i en alfabetisk rekkefølge.

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

/**
 * Denne funksjonen skal ta i mot et nøkkelverdi fra brukeren og vil dermed spore opp
 * noden i B-treet og dermed returnere noden. Funksjonen tar også høyde for at brukeren
 * har kanskje skrevet feil nøkkelverdi, og vil terminere programmet med en feilmelding.
 */

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

