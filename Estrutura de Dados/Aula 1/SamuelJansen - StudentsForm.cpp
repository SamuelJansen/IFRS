//- Librarys
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>

//- Constants
int const MAX = 10;
int const NAME = 50;
int const CODE = 20;
int const QUIT = 30;
int const GENRE = 1;

//- Structures
struct Student
{
    char code[CODE];
    char name[NAME];
	char genre[GENRE];
	int bornDay;
    int age;
};

///////////////////////////////////////////////////////////////////
//- Functions
///////////////////////////////////////////////////////////////////

//- Initialization Function
void initialize(struct Student *students){
	for (int i=0 ; i<MAX ; i++){
		strcpy(students[i].name,"None");
	}
}

int ageCalc(struct Student student){
	time_t mytime; //- it initializes time variable in "mytime"
    mytime = time(NULL);
    struct tm tm = *localtime(&mytime);
    //- Example:
	//- printf("Data: %d/%d/%d\n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);

	student.age = tm.tm_mday - student.bornDay/1000000;
	student.age = student.age + (tm.tm_mon + 1 - student.bornDay%1000000/10000) * 30; //- An aproximation...
	student.age = student.age + (tm.tm_year + 1900 - student.bornDay%10000) * 365; //- An aproximation...
	student.age = student.age/365;
	return student.age;
}

void printStudent(struct Student student){
    printf("\n  - Nome: %s, ",student.name);
    printf("\n  - Code: %s, ",student.code);
    printf("Sexo: %s, ",student.genre);
    printf("Data de nascimento: %d/%d/%d, ",student.bornDay/1000000,student.bornDay%1000000/10000,student.bornDay%10000);
    student.age = ageCalc(student); // gambiarrinha
    printf("Idade: %i, ",student.age);
}

// Create form function
void create(struct Student *students){
	bool full = true;
	bool valid = true;
	char quit[QUIT];

	strcpy(quit,"ThisVariableWasUntouchedSoFar");

	system("clear||cls");
	printf("#######################################################\n");
	printf("#########- Cadastrar Aluno -###########################\n");
	printf("#######################################################\n");

	for (int i=0 ; i<MAX ; i++){
		if (strcmp(students[i].name,"None")==0){
			printf("\n - Nome: ");
			fflush(stdin); gets(students[i].name);
			for (int j=0 ; j<MAX ; j++){
				if (i!=j && strcmp(students[i].name,students[j].name)==0 && strcmp(students[i].name,"None")!=0) {
					strcpy(students[i].name,"None");
					valid = false;
					printf("\n\n  Aluno ja cadastrado.");
					printf("\n\n  Pressione enter para retornar ao menu: ");
					fflush(stdin); gets(quit);
				}
			}
			if (valid && strcmp(quit,"ThisVariableWasUntouchedSoFar")==0) {
			    printf(" - Code: ");
				fflush(stdin); gets(students[i].code);
				printf(" - Sexo (M/F): ");
				fflush(stdin); gets(students[i].genre);
				printf(" - Data de nascimento (ddmmaaaa): ");
				fflush(stdin); scanf("%d",&students[i].bornDay);
				printf("\n\n  Aluno cadastrado com sucesso.");
				printf("\n\n  Pressione enter para retornar ao menu: ");
				fflush(stdin); gets(quit);
				full = false;
				break; //- This line didn't worked properly
			}
		}
	}

	if (full && strcmp(quit,"ThisVariableWasUntouchedSoFar")==0) {
		printf("\n  O cadastro esta cheio.\n");
		printf("\n\n  Pressione enter para retornar ao menu: ");
		fflush(stdin); gets(quit);
	}
}

// Return the student form geting in the form for his's name
void get(struct Student *students){
	char name[NAME];
	bool found = false;
	char quit[QUIT];

	system("clear||cls");
	printf("#######################################################\n");
	printf("#########- Consultar Aluno -###########################\n");
	printf("#######################################################\n");
	printf("\n  Digite o nome do paciente: ");
	fflush(stdin); gets(name);

	for (int i=0 ; i<MAX ; i++){
		if (strcmp(students[i].name,name)==0){
			printStudent(students[i]);
			printf("\n\n  Pressione enter para retornar ao menu: ");
			fflush(stdin); gets(quit);
			found = true;
			break; //- This line didn't worked properly
		}
	}

	if (!found) {
		printf("\n  Nome nao encontrado.\n");
		printf("\n\n  Pressione enter para retornar ao menu: ");
		fflush(stdin); gets(quit);
	}
}

// List all the form
void listAll(struct Student *students){
	char name[NAME];
	bool found = false;
	char quit[QUIT];

	system("clear||cls");
	printf("#######################################################\n");
	printf("###########- Listar Cadastro -#########################\n");
	printf("#######################################################\n");

	for (int i=0 ; i<MAX ; i++){
		if (strcmp(students[i].name,"None")!=0){
			printStudent(students[i]);
			found = true;
		}
	}

	if (!found) {
		printf("\n  Nenhum paciente cadastrado.\n");
	}
	printf("\n\n  Pressione enter para retornar ao menu: ");
	fflush(stdin); gets(quit);
}

// Delete a student from the form
void deleteIt(struct Student *students){
	char name[NAME];
	bool found = false;
	char quit[QUIT];

	system("clear||cls");
	printf("#######################################################\n");
	printf("##########- Deletar Aluno -############################\n");
	printf("#######################################################\n");
	printf("\n  Digite o nome do aluno: ");
	fflush(stdin); gets(name);

	for (int i=0 ; i<MAX ; i++){
		if (strcmp(students[i].name,name)==0){
			strcpy(students[i].name,"None");
			printf("\n\n  Aluno deletado do cadastro.");
			printf("\n\n  Pressione enter para retornar ao menu: ");
			fflush(stdin); gets(quit);
			found = true;
			break; //- This line didn't worked properly
		}
	}

	if (!found) {
		printf("\n  Nome nao encontrado.\n");
		printf("\n\n  Pressione enter para retornar ao menu: ");
		fflush(stdin); gets(quit);
	}
}

// The main loop of the program
void program(struct Student *students){
	bool running = true;
	int choice = 0;
	char quit[QUIT];

	while (running) {
		system("clear||cls");
		printf("#######################################################\n");
		printf("##############- Menu -#################################\n");
		printf("#######################################################\n");
		printf("\n    1 Cadastrar");
		printf("\n    2 Consultar");
		printf("\n    3 Listar");
		printf("\n    4 Excluir");
		printf("\n    5 Sair");
		printf("\n\n    Digite sua opcao: ");
		fflush(stdin); scanf("%i",&choice);
		switch (choice) {
			case 1 : create(students); break;
			case 2 : get(students); break;
			case 3 : listAll(students); break;
			case 4 : deleteIt(students); break;
			case 5 : running = false; break;
			default : {
				printf("\n  Opcao invalida. Pressione enter para optar novamente: ");
				fflush(stdin); gets(quit);
				break;
			}
		}
	}
}

//- Main Program
int main(){
	//- Variables
	Student students[MAX];

	//- Initialization
	initialize(students);

	//- Main Loop
	program(students);
}
