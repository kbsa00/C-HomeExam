

#ifndef EKSAMENSOPPGAVE_HEADER_H
#define EKSAMENSOPPGAVE_HEADER_H

#define MAX_NODE  10
#define intvalue "Integer Value"
#define stringValue "String Value"
#define Mappe "Mappe"
#define feilkode "Finner ikke katalogen"
#define fDatatype "Feil Datatype"


typedef unsigned long ULONG;


typedef struct _NODE{
    char * pszName; //Navn på noden
    ULONG ulIntval; // Verdi ULONG
    char * pszString; // Verdi String
    struct _NODE * pnNodes[MAX_NODE];

}Node;

Node * root;

//Deklarasjon av alle funksjoner i programmet.

void readFile(char * filename);
void sortAlphabetical(char * textFile[], int size);
void checkNode(char * textline);
Node * createSubNode(Node * parentNode, char * string);
void printAll(Node * current, char * folder);
void GetType(char * string);
Node * GetCurrentNode(char * string);
ULONG GetULONG(char * keyvalue);
char * GetString(char * keyvalue);
void GetText(char * undernode, char * hovednode);
Node * rekursiv(Node * current, char * hovednode, char * undernod);




#endif //EKSAMENSOPPGAVE_HEADER_H
