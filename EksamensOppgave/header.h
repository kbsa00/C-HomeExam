//
// Created by khalid on 26.10.17.
//

#ifndef EKSAMENSOPPGAVE_HEADER_H
#define EKSAMENSOPPGAVE_HEADER_H

#define MAX_NODE  10

typedef unsigned long ULONG;


typedef struct _NODE{
    char * pszName; //Navn på noden
    ULONG ulIntval; // Verdi ULONG
    char * pszString; // Verdi String
    struct _NODE * pnNodes[MAX_NODE];

}Node;

Node * root;

void readFile(char * filename);
void setString(char * string);
int getINT();
char getString();
void Delete();
void Enumerate();
void sortAlphabetical(char * textFile[], int size);
void checkNode(char * textline);
Node * createSubNode(Node * parentNode, char * string);

//getValue og setValue.. Finn ut hvilken datatype, som
//skal sendes og returneres..


#endif //EKSAMENSOPPGAVE_HEADER_H
