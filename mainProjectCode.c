#include <stdlib.h>
#include <stdio.h>
#include <string.h>
// Here we have to add any extra library that will be designed

//Here we can add the function prototypes that we will utilize
void add_client_info(accLIST *theList);
void print_clients_list(accLIST *theList);


//Main structures definition
typedef struct account //Individual accounts structure
{
  char firstName[30];
  char lastName[30];
  int accountID;
  double accountBalance;
  struct account *next;
  struct account *prev;
} accINFO;

typedef struct //List of accounts structure
{
  unsigned int count;
  struct account *head;
  struct account *tail;
} accLIST;

//Create a list
accLIST clientsLIST;

int main()
{
  char menuControl[100];
	char *controlVal;
	int i;

	clientsLIST.count = 0; clientsLIST.head = NULL; clientsLIST.tail = NULL;	// Initialize accounts list

	printf("Available commands: \n"); //Menu commands
	printf("add - Add new client information\n");
	printf("print - Display clients information \n");
	printf("store - Store clients information to a file in binary format \n");
	printf("load - Load clients information from a file in binary format\n");
	printf("help - Display this help message\n");
	printf("exit - Exit the system\n");

	while(1)	// Render and operate the menu
	{
		printf("--> ");
		scanf("%s", menuControl); //Menu selection

		controlVal = strtok(menuControl, " \t");
		if(strcmp(controlVal, "add") == 0)
		{
			// Enter data command
			add_client_info(&clientsLIST);
		}
		else if(strcmp(controlVal, "print") == 0)
		{
			// Print data command
			print_clients_list(&clientsLIST);
		}
		else if(strcmp(controlVal, "store") == 0)
		{
			// Save data command
			printf("To be implemented\n");
			//store_list(&clientsLIST);
		}
		else if(strcmp(controlVal, "load") == 0)
		{
			// Load data command
			printf("To be implemented\n");
			//load_list(&clientsLIST);
		}
		else if(strcmp(controlVal, "delete") == 0)
		{
			// Load data command
			printf("To be implemented\n");
			//load_list(&clientsLIST);
		}
		else if(strcmp(controlVal, "sort") == 0)
		{
			// Load data command
			printf("To be implemented\n");
			//load_list(&clientsLIST);
		}
		else if(strcmp(controlVal, "deposit") == 0)
		{
			// Load data command
			printf("To be implemented\n");
			//load_list(&clientsLIST);
				}
		else if(strcmp(controlVal, "withdrawal") == 0)
				{
			// Load data command
			printf("To be implemented\n");
			//load_list(&clientsLIST);
				}
		else if(strcmp(controlVal, "help") == 0)
		{
			// Help command
			printf("Available commands: \n");
			printf("add - Add new client information\n");
			printf("print - Display clients information \n");
			printf("store - Store clients information to a file in binary format \n");
			printf("load - Load clients information from a file in binary format\n");
			printf("delete - Delete customer account \n");
			printf("sort - Sort list of clients in alphabetical order \n");
			printf("deposit - Deposit into account balance \n");
			printf("withdrawal - Withdraw money from account balance \n");
			printf("help - Display this help message\n");
			printf("exit - Exit the system\n");
		}
		else if(strcmp(controlVal, "exit") == 0)
		{
			// Exit command
			printf("Goodbye!\n");
			return 0;
		}
		else
		{
			printf("Invalid command!\n");
		}
	}

	return 0; //End of main
}



