#include <stdlib.h>
#include <stdio.h>
#include <string.h>
// Here we have to add any extra library that will be designed

//Here we can add the function prototypes that we will utilize

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

int main()
{
  char menuControl[100];
	char *controlVal;
	int i;
	
	accLIST.count = 0; accLIST.head = NULL; accLIST.tail = NULL;	// Initialize accounts list
	
	while(1)	// Render and operate the menu
	{
		printf("--> ");
		scanf("%s", menuControl);
		//printf("%s", commandStr);

		controlVal = strtok(menuControl, " \t");
		if(strcmp(controlVal, "add") == 0)
		{
			// Enter data command
			add_point_to_shape(&myShape);
		}
		else if(strcmp(controlVal, "print") == 0)
		{
			// Print data command
			print_shape(&myShape);
		}
		else if(strcmp(controlVal, "store") == 0)
		{
			// Save data command
			printf("To be implemented\n");
			//store_shape(&myShape);
		}
		else if(strcmp(controlVal, "load") == 0)
		{
			// Load data command
			printf("To be implemented\n");
			//load_shape(&myShape);
		}
		else if(strcmp(controlVal, "help") == 0)
		{
			// Help command
			printf("Available commands: \n");
			printf("add - add \n");
			printf("print - print \n");
			printf("store - store  data \n");
			printf("load - load data \n");
			printf("help - displays this help message\n");
			printf("exit - exits the system\n");
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

	return 0;
}

