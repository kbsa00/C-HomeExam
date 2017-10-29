//
// Created by khalid on 26.10.17.
//

#ifndef EKSAMENSOPPGAVE_HEADER_H
#define EKSAMENSOPPGAVE_HEADER_H

#define MAX_NODE  10

typedef unsigned long ULONG;


typedef struct _NODE{
    char * pszName;
    ULONG ulIntval;
    char * pszString;
    struct _NODE * pnNodes[MAX_NODE];

}Node;


void readFile(char * filename);

void setINT(int number);
void setString(char * string);
int getINT();
char getString();
void Delete();
void Enumerate();
//getValue og setValue.. Finn ut hvilken datatype, som
//skal sendes og returneres..


#endif //EKSAMENSOPPGAVE_HEADER_H
