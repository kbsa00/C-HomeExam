//
// Created by khalid on 26.10.17.
//

#ifndef EKSAMENSOPPGAVE_HEADER_H
#define EKSAMENSOPPGAVE_HEADER_H

#define MAX_NODE  10
#define intvalue "Integer Value"
#define stringValue "String Value"
#define feilkode "Finner ikke katalogen"
typedef unsigned long ULONG;


typedef struct _NODE{
    char * pszName; //Navn på noden
    ULONG ulIntval; // Verdi ULONG
    char * pszString; // Verdi String
    struct _NODE * pnNodes[MAX_NODE];

}Node;

Node * root;

void readFile(char * filename);
void sortAlphabetical(char * textFile[], int size);
void checkNode(char * textline);
Node * createSubNode(Node * parentNode, char * string);
void printAll(Node * current, char * folder);
void GetType(char * string);

//getValue og setValue.. Finn ut hvilken datatype, som
//skal sendes og returneres..


#endif //EKSAMENSOPPGAVE_HEADER_H
