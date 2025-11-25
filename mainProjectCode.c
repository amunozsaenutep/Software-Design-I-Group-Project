#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "mainFunctions.h"

// Here we have to add any extra library that will be designed

//Here we can add the function prototypes that we will utilize
void add_client_info(accLIST *clientsLIST);
void print_clients_list(accLIST *clientsLIST);
void store_list(accLIST *clientsLIST);
void load_list(accLIST *clientsLIST);
void delete_client(accLIST *clientsLIST);
void sort_list(accLIST *clientsLIST);
void account_deposit(accLIST *clientsLIST);
void account_withdrawal(accLIST *clientsLIST);

int main()
{
  char menuControl[100];
  char *controlVal;

	clientsLIST.count = 0; clientsLIST.head = NULL; clientsLIST.tail = NULL;	// Initialize accounts list

	printf("Available commands: \n"); //Menu options
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

	while(1)	// Render and operate the menu
	{
		printf("--> ");
		scanf("%s", menuControl); //Menu selection

		controlVal = strtok(menuControl, " \t");
		if(strcmp(controlVal,"add") == 0) 			// Enter data command
		{
			add_client_info(&clientsLIST);
		}
		else if(strcmp(controlVal,"print") == 0) 	// Print data command
		{
			print_clients_list(&clientsLIST);
		}
		else if(strcmp(controlVal, "store") == 0)	// Store data command
		{
			store_list(&clientsLIST);
		}
		else if(strcmp(controlVal, "load") == 0)	// Load data command
		{
			load_list(&clientsLIST);
		}
		else if(strcmp(controlVal, "delete") == 0)	// Delete client info command
		{
			delete_client(&clientsLIST);
		}
		else if(strcmp(controlVal, "sort") == 0)	// Sort clients list command
		{
			printf("To be implemented\n");
			sort_list(&clientsLIST);
		}
		else if(strcmp(controlVal, "deposit") == 0)	// Deposit into account command
		{
			printf("To be implemented\n");
			account_deposit(&clientsLIST);
		}
		else if(strcmp(controlVal, "withdrawal") == 0)	// Withdraw from account command
		{
			printf("To be implemented\n");
			account_withdrawal(&clientsLIST);
		}
		else if(strcmp(controlVal, "help") == 0)		// Help command
		{
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
		else if(strcmp(controlVal, "exit") == 0)		// Exit command
		{
			printf("Goodbye!\n");
			return 0;
		}
		else
		{
			printf("Invalid command!\n"); //Exception to instructions
		}
	}

	return 0; //End of main
}



