//Hjemme-eksamen i Programmering i C.
Info før du kjører programmet:  

Programmet tar imot void parameteren.
- Kjør programmet ./run 

Kjører du programmet i CLion og andre lignende programmer: 
- Ta høyde for at file.txt ligger i cmake-build-debug mappen..

Da vil den lage nodene basert på fil.txt: 
Den vil da printe ut hele prossessen av å lage hvert Node.
Alt i fra å lage ny node og si ifra at Noden allerede finnes
og ikke trenges å lages på nytt.

Du vil bli møtt av en brukervennlig interface hvor du kan 
kjøre hver metode som du har lyst å kjøre. 
Her er et eksempel av interfacet. 

Press 1 for the function GetType()
Press 2 for the function GetString()
Press 3 for the function GetInt/GetUlong()
Press 4 for the function GetText
Press 5 for the function Delete()
Press 6 for the function Enumurate()
Press 7 for Exiting the program

Insert your input: 


Programmet avslutter når du velger å avslutte. 

Noen av disse funksjonene tar i mot en nøkkel-verdi. Om du 
skriver feil nøkkelverdi vil programmet gi deg en feilmelding
og avslutter programmet. 


Beskrivelse av funksjonene alle funksjon:
_________________________________________

functions.c: 

void readFile(char * filename);(Leser filen og lagrer 
hvert linje i en Array.) 


void sortAlphabetical(char * textFile[], int size);(Sorterer
teksfilen i en alfabetisk rekkefølge før nodene blir laget, 
dermed blir B-Treet laget i en alfabetisk rekkefølge)

Node * GetCurrentNode(char * string); (Tar i mot en nøkkel-verdi og 
returnerer noden basert på Nøkkel-verdien)


main.c: 

void checkNode(char * textline); (Sjekker om noden finnes
og om den har blitt laget og lagt til i B-Treet)

Node * createSubNode(Node * parentNode, char * string); (Lager noden 
og setter den inn i B-Treet og returnerer parentNode)

char * GetType(char * string); (Returnerer en beskrivelse om noden er en mappe eller
en node med hvilke type verdi)

ULONG GetULONG(char * keyvalue); (Returnerer Nodens ULONG)

char * GetString(char * keyvalue); (Returnerer nodens String)

char * GetText(char * undernode, char * hovednode);

char * GetTextRekursiv(Node * current, char * hovednode, char * undernod); (Sjekker rekursiv gjennom hele node-treet og finner 
undernoden som du er på utkikk etter.) 

void Delete(char * string); (Sletter noden basert på nøkkel-verdien
om det er en mappe eller en underliggende Node)

void Enumurate(char * keyname, void (*callback)(Node * current));
void  callback(Node * current); (Enumurate og Callback, enumurerer nodene og 
printer disse ut på en respektabelt måte.) 




