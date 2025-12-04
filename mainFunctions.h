//We will write the functions that we were asked for on this file

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

//Create a file
FILE *clientsFILES;

void add_client_info(accLIST *clientsLIST)
{
	accINFO *newClient = malloc(sizeof(accINFO));

	// Poll the user for the information of the new client
	printf("Enter the new client's information\n");
	printf("First Name: "); scanf("%s", newClient->firstName);
	printf("Last Name: "); scanf("%s", newClient->lastName);
	printf("Account ID: "); scanf("%d", &(newClient->accountID));
	printf("Initial Balance: "); scanf("%lf", &(newClient->accountBalance));

	newClient->next = NULL; newClient->prev = NULL;	// default pointer values are NULL

	// Queue the client at the end of the existing list
	if(clientsLIST->tail == NULL)
	{
		// clients list was empty
		clientsLIST->count = 1;
		clientsLIST->head = newClient;
		clientsLIST->tail = newClient;
	}
	else
	{
		// Add new client to the end of the list
		clientsLIST->count++;
		clientsLIST->tail->next = newClient;
		newClient->prev = clientsLIST->tail;
		clientsLIST->tail = newClient;
	}

}

void print_clients_list(accLIST *clientsLIST)
{
	accINFO *travPtr;

	// If the list has no clients, print a message
	if(clientsLIST->head == NULL)
	{
		printf("List undefined\n");
		return;
	}

	// Traverse the list of clients and print their info
	travPtr = clientsLIST->head;
	while(travPtr != NULL)
	{
		printf("\nFirst Name: %s\n Last Name: %s\n Account ID: %d\n Account Balance: %.3lf\n", travPtr->firstName, travPtr->lastName,travPtr->accountID,travPtr->accountBalance);
		travPtr = travPtr->next;
	}
	free(travPtr);
	return;
}

void store_list(accLIST *clientsLIST)
{
	clientsFILES = fopen("clients.bin","wb");
	accINFO *travPtr;

		if(clientsFILES == NULL)
		{
		perror("Error opening file\n");
		}

		// If the list has no clients, print a message
		if(clientsLIST->head == NULL)
		{
			printf("List undefined\n");
			return;
		}

		// Traverse the list of clients and print their info
		travPtr = clientsLIST->head;
		size_t written_records;
		while(travPtr != NULL)
		{
			//Write first element and record control
			written_records = fwrite(travPtr->firstName,sizeof(travPtr->firstName), 1,clientsFILES);
			//Write second element
			fwrite(travPtr->lastName,sizeof(travPtr->lastName), 1,clientsFILES);
			//Write third element
			fwrite(&(travPtr->accountID),sizeof(int), 1,clientsFILES);
			//Write fourth element
			fwrite(&(travPtr->accountBalance),sizeof(double), 1,clientsFILES);
''
			travPtr = travPtr->next;
		}
				if (written_records != clientsLIST->count)
				{
					perror("Error writing to file\n");
				}
				else
				{
					printf("%zu elements successfully written\n", written_records);
				}

	fclose(clientsFILES);
	free(travPtr);

	return;
}

void load_list(accLIST *clientsLIST)
{
	clientsFILES = fopen("clients.bin","rb");
	accINFO *newClient = malloc(sizeof(accINFO));
	int i=0;

			if(clientsFILES == NULL)
			{
			perror("Error opening file\n");
			}

				// Queue the client at the end of the existing list
					if(clientsLIST->tail == NULL)
					{
						// clients list was empty
						clientsLIST->count = 1;
						clientsLIST->head = newClient;
						clientsLIST->tail = newClient;
					}
					else
					{
						// Add new client to the end of the list
						clientsLIST->count++;
						clientsLIST->tail->next = newClient;
						newClient->prev = clientsLIST->tail;
						clientsLIST->tail = newClient;
					}

					//Write first element
								size_t read_records = fread(newClient->firstName,sizeof(newClient->firstName), 1,clientsFILES);
								//Write second element
								fread(newClient->lastName,sizeof(newClient->lastName), 1,clientsFILES);
								//Write third element
								fread(&(newClient->accountID),sizeof(int), 1,clientsFILES);
								//Write fourth element
								fread(&(newClient->accountBalance),sizeof(double), 1,clientsFILES);


				printf("%zu records read\n",read_records);
					if (read_records != clientsLIST->count)
					{
						perror("Error writing to file\n");
					}
					else
					{
						printf("%zu elements successfully written\n", read_records);
					}
		fclose(clientsFILES);
		free(newClient);
}

void delete_client(accLIST *clientsLIST)
{
	accINFO *travPtr; //Auxiliary travel pointer
	char search1[30];
	char search2[30];
	int search3;

	printf("Enter the first name, last name, and account ID to be deleted.\n");
	printf("\nFirst Name: "); scanf("%s",search1);
	printf("\nLast Name: "); scanf("%s", search2);
	printf("\nAccount ID: "); scanf("%d", &search3);

	if(clientsLIST->head==NULL) //Empty list
	{
		printf("List does not exist. Deletion cannot be completed.\n");
		return;
	}

	travPtr = clientsLIST->head; //Place auxiliary pointer at the head

	while(travPtr != NULL && travPtr->firstName != search1 //Linear search for desired account
			&& travPtr->lastName != search2 && travPtr->accountID != search3)
	{
		travPtr = travPtr->next;
	}

	if(travPtr == NULL) //If account is not found
	{
		printf("Account with elements %s %s Account ID: %d not found.\n", search1,search2,search3);
	}

	if(travPtr == clientsLIST->head) //CASE 1: Head client to be deleted
	{
		clientsLIST->head = travPtr->next;
		if(clientsLIST->head != NULL)
		{
			clientsLIST->head->prev = NULL;
		}
		else
		{
			clientsLIST->tail = NULL; //List become empty
		}
	}

	else if(travPtr == clientsLIST->tail) //CASE 2: Deleting tail client
	{
		clientsLIST->tail = travPtr->prev;
		if(clientsLIST->tail != NULL)
		{
			clientsLIST->tail->next = NULL;
		}
		else
		{
			clientsLIST->head = NULL; //List ends up empty
		}
	}
	else //CASE 3: Intermediate clients
	{
		travPtr->prev->next = travPtr->next;
		travPtr->next->prev = travPtr->prev;
	}
	free(travPtr);
	printf("Element %s %s Acc. ID: %d Deleted successfully.\n", search1,search2,search3);
}

void sort_list(accLIST *clientsLIST)
{
	accINFO *tempNode;

	int compareNodes(accLIST *clientsLIST, accINFO *tempNode)
	{
	    if (clientsLIST->head->accountBalance < tempNode->accountBalance)
	        return -1;
	    if (clientsLIST->head->accountBalance > tempNode->accountBalance)
	        return 1;

	    // secondary compare by string
	    return strcmp(clientsLIST->head->lastName, tempNode->lastName);
	}

	accINFO* sortedInsert(accLIST *clientsLIST, accINFO *tempNode)
	{
	    accLIST* current;

	    // Case 1: put at head
	    if (!clientsLIST->head || compareNodes(clientsLIST,tempNode)<= 0)
	    {
	        tempNode->next = clientsLIST->head;
	        tempNode->prev = NULL;
	        if (clientsLIST->head)
	        	{
	        	clientsLIST->head->prev = tempNode;
	        	}
	        return tempNode;
	    }

	    // Otherwise find insertion point
	    current->head = clientsLIST->head;
	    while (current->head->next && compareNodes(current, tempNode) > 0)
	    {
	        current->head = current->head->next;
	    }

	    // Insert after "current"
	    tempNode->next = current->head->next;
	    tempNode->prev = current->head;

	    if (current->head->next)
	        current->head->next->prev = tempNode;

	    current->head->next = tempNode;

	    return current->head;
	}

	accINFO* insertionSort(accLIST *clientsLIST)
	{
		accLIST* sorted = NULL;
		accINFO* current = clientsLIST->head;

	    while (current)
	    {
	    	sorted->head->next = current->next;

	        current->prev = current->next = NULL; // detach node

	        sorted->head->prev = sortedInsert(sorted, current);

	        current = sorted->head->next;
	    }
	    return sorted->head;

	    current = sorted->head;
	    printf("List: ");
	    while (current)
	    {
	    	printf("%.3f,%s",current->accountBalance,current->lastName);
	    	current = current->next;
	    	printf("\n");
	    }
	}
}


void account_deposit(accLIST *clientsLIST)
{
	accINFO *travPtr; //Auxiliary travel pointer
		char search1[30];
		char search2[30];
		int search3;
		double deposit;

		printf("Enter the first name, last name, and account ID to deposit.\n");
		printf("\nFirst Name: "); scanf("%s",search1);
		printf("\nLast Name: "); scanf("%s", search2);
		printf("\nAccount ID: "); scanf("%d", &search3);
		printf("\nEnter the amount of money to deposit: "); scanf("%lf",&deposit);

		if(clientsLIST->head==NULL) //Empty list
		{
			printf("List does not exist. Deposit cannot be completed.\n");
			return;
		}

		travPtr = clientsLIST->head; //Place auxiliary pointer at the head

		while(travPtr != NULL && travPtr->firstName != search1 //Linear search for desired account
				&& travPtr->lastName != search2 && travPtr->accountID != search3)
		{
			travPtr = travPtr->next;
		}

		if(travPtr == NULL) //If account is not found
		{
			printf("Account with elements %s %s Account ID: %d not found.\n", search1,search2,search3);
		}

		if(travPtr == clientsLIST->head) //CASE 1: Deposit to head client
		{
			travPtr->accountBalance = travPtr->accountBalance + deposit;
		}

		else if(travPtr == clientsLIST->tail) //CASE 2: Deposit to head client
		{
			travPtr->accountBalance = travPtr->accountBalance + deposit;
		}
		else //CASE 3: Deposit to head client
		{
			travPtr->accountBalance = travPtr->accountBalance + deposit;
		}
		free(travPtr);
		printf("Successfully deposited %.2lf into account with elements %s %s Acc. ID: %d.\n", deposit,search1,search2,search3);
		printf("New Account Balance: %.2lf\n\n",travPtr->accountBalance);
}

void account_withdrawal(accLIST *clientsLIST)
{
	accINFO *travPtr; //Auxiliary travel pointer
			char search1[30];
			char search2[30];
			int search3;
			double withdrawal;

			printf("Enter the first name, last name, and account ID to deposit.\n");
			printf("\nFirst Name: "); scanf("%s",search1);
			printf("\nLast Name: "); scanf("%s", search2);
			printf("\nAccount ID: "); scanf("%d", &search3);
			printf("\nEnter the amount of money to deposit: "); scanf("%lf",&withdrawal);

			if(clientsLIST->head==NULL) //Empty list
			{
				printf("List does not exist. Deposit cannot be completed.\n");
				return;
			}

			travPtr = clientsLIST->head; //Place auxiliary pointer at the head

			while(travPtr != NULL && travPtr->firstName != search1 //Linear search for desired account
					&& travPtr->lastName != search2 && travPtr->accountID != search3)
			{
				travPtr = travPtr->next;
			}

			if(travPtr == NULL) //If account is not found
			{
				printf("Account with elements %s %s Account ID: %d not found.\n", search1,search2,search3);
			}

			if(travPtr == clientsLIST->head) //CASE 1: Deposit to head client
			{
				travPtr->accountBalance = travPtr->accountBalance - withdrawal;
			}

			else if(travPtr == clientsLIST->tail) //CASE 2: Deposit to head client
			{
				travPtr->accountBalance = travPtr->accountBalance - withdrawal;
			}
			else //CASE 3: Deposit to head client
			{
				travPtr->accountBalance = travPtr->accountBalance - withdrawal;
			}
			free(travPtr);
			printf("Successfully withdrew %.2lf from account with elements %s %s Acc. ID: %d.\n", withdrawal,search1,search2,search3);
			printf("New Account Balance: %.2lf\n\n",travPtr->accountBalance);
}
