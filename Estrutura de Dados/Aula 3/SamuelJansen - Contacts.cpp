/*
Written by Samuel Jansen
Featrues:
	- Dynamic memory allocation
	- create, findByName, listAll, deleteByName, quit methods
	- Persistance
*/
//- Librarys
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>

//- Constants
int const NAME_SIZE = 50;
int const CODE_SIZE = 20;	
int const TELEPHONE_SIZE = 13; 		// (51)999999999
int const EMAIL_SIZE = 50; 			// email@email.com.br
int const ADDRESS_SIZE = 512; 		// Rua, Abcd de Efg, bairro Xyz, Cidade Alpha, Estado Beta
int const DIDNT_QUIT_YET_SIZE = 30;
char const DIDNT_QUIT_YET[] = "DIDNT_QUIT_YET";


//- Structures
struct Contact
{
    char code[CODE_SIZE];
    char name[NAME_SIZE];
    char telephone[TELEPHONE_SIZE];
    char email[EMAIL_SIZE];
	char address[ADDRESS_SIZE];
};

//- Global variables
Contact *contacts;
int contactPointer = 0;

///////////////////////////////////////////////////////////////////
//- Functions
///////////////////////////////////////////////////////////////////

//- Function to persist data in "repository (file)"
void persistData() {
    FILE * repository = fopen("repository.txt", "wt");
    for (int i = 0; i < contactPointer; i++) {
    	//- these lines bellow basically format the string with tab saparators
        fprintf(repository, "%s\t%s\t%s\t%s\t%s\n", 
            contacts[i].code,
            contacts[i].name,
            contacts[i].telephone,
            contacts[i].email,
            contacts[i].address);
    }
    fclose(repository);
}

//- Function to load data from "repository (file)"
void loadData() {
    FILE * repository = fopen("repository.txt", "rt");
    int n;
    if (repository != NULL) {
        while(!feof(repository)) {
        		
            Contact contact;
            // these lines bellow get everithing between '\n' and '\t' as the value of the attribute.
            // there are five attributes; that's why there are 5 "%[^\n\t]\t" string tokens
            n = fscanf(repository, "%[^\n\t]\t%[^\n\t]\t%[^\n\t]\t%[^\n\t]\t%[^\n\t]\t\n", 
               &contact.code,
               &contact.name,
               &contact.telephone,
               &contact.email,
               &contact.address);
               printf("(%d)", EOF);
               
            if (n <= 0) {
            	break;
			}
			
            contacts = (Contact*) realloc(contacts, (contactPointer + 1) * sizeof(Contact));
            contacts[contactPointer] = contact;
            contactPointer++;
        }
    }
    fclose(repository);
}

//- Print contact
void print(struct Contact contact){
    printf("\n  - Name: %s, ",contact.name);
    printf("\n  - Telephone: %s, ",contact.telephone);
    printf("\n  - Email: %s, ",contact.email);
    printf("\n  - Address: %s, ",contact.address);
    printf("\n  - Code: %s, ",contact.code);
    printf("\n");
}

//- Get keyboard input
void input(char outsideVariable[], int size) {
    fflush(stdin);
    fgets(outsideVariable, size, stdin); //- makes the outsideVariable point to keyborad onput up do "\n" character being typed //- getchar();
    outsideVariable[strcspn(outsideVariable, "\n")] = 0;
    fflush(stdin);
}

//- Create contact
void create(){
	bool contactValid = true;
	char quit[DIDNT_QUIT_YET_SIZE];
	strcpy(quit,DIDNT_QUIT_YET);

	system("clear||cls");
	printf("#######################################################\n");
	printf("#########- Create Contact -############################\n");
	printf("#######################################################\n");
	
	Contact contact;
    printf("Type contact code: ");
    input(contact.code,CODE_SIZE);
    
    for (int i = 0; i < contactPointer; i++){
		if (strcmp(contact.code,contacts[i].code) == 0) {
			contactValid = false;
			printf("\n\n  Contact already exists.");
			printf("\n\n  Press enter to return to Main Menu: ");
			fflush(stdin); gets(quit);
			break;
		}
	}
    
    if(contactValid){    	
	    printf("Type contact name: ");
   	 	input(contact.name,NAME_SIZE);
   	 	
	    printf("Type contact telephone: ");
    	input(contact.telephone,TELEPHONE_SIZE);
    	
	    printf("Type contact email: ");
    	input(contact.email,EMAIL_SIZE);
    	
	    printf("Type contact address: ");
    	input(contact.address,ADDRESS_SIZE);
	    
	    printf("\n\n  Contact persisted with success.");
		printf("\n\n  Press enter to return to Main Menu: ");
		fflush(stdin); gets(quit);
		
		//- these lines bellow increase contacts size by one unity
	    contacts = (Contact*) realloc(contacts, (contactPointer + 1) * sizeof(Contact));
	    contacts[contactPointer] = contact;
	    contactPointer++;
	}
	
	//- Persist data in "repository"
	persistData();
}

//- Find contact by name
void findByName(){
	char nameQuery[NAME_SIZE];
	bool contactFound = false;
	char quit[DIDNT_QUIT_YET_SIZE];

	system("clear||cls");
	printf("#######################################################\n");
	printf("#########- Find Contact -##############################\n");
	printf("#######################################################\n");
	printf("\n  Type contact name: ");
	fflush(stdin); gets(nameQuery);

	for (int i = 0; i < contactPointer; i++){
		if (strcmp(nameQuery,contacts[i].name)==0){
			print(contacts[i]);
			printf("\n\n  Press enter to return to Main Menu: ");
			fflush(stdin); gets(quit);
			contactFound = true;
			break;
		}
	}

	if (!contactFound) {
		printf("\n  Contact not found.\n");
		printf("\n\n  Press enter to return to Main Menu: ");
		fflush(stdin); gets(quit);
	}
}

//- List all contacts
void listAll(){
	bool atLeastOneContactListed = false;
	char quit[DIDNT_QUIT_YET_SIZE];

	system("clear||cls");
	printf("#######################################################\n");
	printf("###########- List Contacts -###########################\n");
	printf("#######################################################\n");

	for (int i = 0; i < contactPointer; i++){
		print(contacts[i]);
		atLeastOneContactListed = true;
	}

	if (!atLeastOneContactListed) {
		printf("\n  There is no persisted contact yet.\n");
	}
	printf("\n\n  Press enter to return to Main Menu: ");
	fflush(stdin); gets(quit);
}

//- Delete contact by name
void deleteByName(){
	char nameQuery[NAME_SIZE];
	bool contactDeleted = false;
	char quit[DIDNT_QUIT_YET_SIZE];

	system("clear||cls");
	printf("#######################################################\n");
	printf("##########- Delete Contact -###########################\n");
	printf("#######################################################\n");
	printf("\n  Type contact name: ");
	fflush(stdin); gets(nameQuery);

	for (int i = 0; i < contactPointer; i++){
		
		if (strcmp(nameQuery,contacts[i].name)==0){
			
			//- these lines bellow reduce contacts size by one unity
			for (int n = i; n < contactPointer - 1; n++) {
	            contacts[n] = contacts[n+1];
	        }
	        contactPointer--;
	        contacts = (Contact*) realloc(contacts, contactPointer * sizeof(Contact));
	        
			printf("\n\n  Contact deleted.");
			printf("\n\n  Press enter to return to Main Menu: ");
			fflush(stdin); gets(quit);
			contactDeleted = true;
			break;
		}
	}

	if (!contactDeleted) {
		printf("\n  Contact not found.\n");
		printf("\n\n  Press enter to return to Main Menu: ");
		fflush(stdin); gets(quit);
	}
	
	//- Persist data in "repository"
	persistData();
}

//- The main loop of the program
void program(struct Contact *contacts){
	bool running = true;
	int userChoice = 0;
	char quit[DIDNT_QUIT_YET_SIZE];

	while (running) {
		system("clear||cls");
		printf("#######################################################\n");
		printf("##############- Main Menu -############################\n");
		printf("#######################################################\n");
		printf("\n    1 Create Contact");
		printf("\n    2 Find Contact");
		printf("\n    3 List Contacts");
		printf("\n    4 Delete Contact");
		printf("\n    5 Quit");
		printf("\n\n    Type your option: ");
		fflush(stdin); scanf("%i",&userChoice);
		switch (userChoice) {
			case 1 : create(); break;
			case 2 : findByName(); break;
			case 3 : listAll(); break;
			case 4 : deleteByName(); break;
			case 5 : running = false; break;
			default : {
				printf("\n\n  Invalid option.");
				printf("\n\n  Press enter to return to Main Menu: ");
				fflush(stdin); gets(quit);
				break;
			}
		}
	}
}

//- Main Program
int main(){

	//- Load data from "repository"
	loadData();

	//- Main Loop
	program(contacts);
}
