//
// Created by khalid on 26.10.17.
//

#ifndef EKSAMENSOPPGAVE_HEADER_H
#define EKSAMENSOPPGAVE_HEADER_H

#define MAX_NODE  10

typedef unsigned ULONG;


typedef struct _NODE{
    char * pszName; //Navn på noden
    ULONG ulIntval; // Verdi ULONG
    char * pszString; // Verdi String
    struct _NODE * pnNodes[MAX_NODE];

}Node;


void readFile(char * filename);

void setINT(int number);
void setString(char * string);
int getINT();
char getString();
void Delete();
void Enumerate();
void sortAlphabetical(char * array[]);


//getValue og setValue.. Finn ut hvilken datatype, som
//skal sendes og returneres..


#endif //EKSAMENSOPPGAVE_HEADER_H
