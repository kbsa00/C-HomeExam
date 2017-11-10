

#ifndef EKSAMENSOPPGAVE_HEADER_H
#define EKSAMENSOPPGAVE_HEADER_H

#define MAX_NODE  10
#define intvalue "Keyvalue you sent inn contains: Integer Value"
#define stringValue "Keyvalue you sent in contains: String Value"
#define Mappe "Keyvalue you sent in is a folder"
#define feilkode "Can't find the directory.."
#define fDatatype "Wrong Datatype"


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
char * GetType(char * string);
Node * GetCurrentNode(char * string);
ULONG GetULONG(char * keyvalue);
char * GetString(char * keyvalue);
char * GetText(char * undernode, char * hovednode);
char * GetTextRekursiv(Node * current, char * hovednode, char * undernod);
void Delete(char * string);
void Enumurate(char * keyname, void (*callback)(Node * current));
void  callback(Node * current);




#endif //EKSAMENSOPPGAVE_HEADER_H
