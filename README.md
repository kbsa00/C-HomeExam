# C Home Exam 2017

## Assignment: 
The assignment was to create a B-Tree using Linked List. The program has to create
this file structure by first reading a file and then start building the nodes and the entire structure. 
The assignment also specified that there had to be a couple of functions where you were interacting and doing
changes to the Linked List. Like for example: Deleting a node *"File or a Folder"*, Finding what type the 
node is *"File or a Folder"* and getting the name of the node.

## Run the program
To run the program for the first time you need to to these following steps. 
Go into the folder of the project and write the following \n

```
make
Creating an executable file.. 
./run

```

## Functions

###### main.c

```c
void checkNode(char * textline);
Node * createSubNode(Node * parentNode, char * string);
char * GetType(char * string); 
ULONG GetULONG(char * keyvalue);
char * GetString(char * keyvalue);
char * GetText(char * undernode, char * hovednode);
char * GetTextRekursiv(Node * current, char * hovednode, char * undernod); 
void Delete(char * string);
void Enumurate(char * keyname, void (*callback)(Node * current));
void  callback(Node * current); 
```


###### function.c 
```c
void readFile(char * filename);
void sortAlphabetical(char * textFile[], int size);
Node * GetCurrentNode(char * string);
```

    
