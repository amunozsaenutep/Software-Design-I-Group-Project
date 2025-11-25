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
	printf("Initial Balance: "); scanf("%lg", &(newClient->accountBalance));

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
		printf("First Name: %s\n Last Name: %s\n Account ID: %d\n Account Balance: %lg\n\n", travPtr->firstName, travPtr->lastName,travPtr->accountID,travPtr->accountBalance);
		travPtr = travPtr->next;
	}

	return;
}

void store_list(accLIST *clientsLIST)
{
	clientsFILES = fopen("clients.bin","wb");

	if(clientsFILES == NULL)
	{
		perror("Error opening file\n");
	}

	size_t written_records = fwrite(clientsLIST,sizeof(clientsLIST), clientsLIST->count,clientsFILES);

	if (written_records != clientsLIST->count)
	{
		perror("Error writing to file\n");
	}
	else
	{
		printf("%zu elements successfully written\n", written_records);
	}
	fclose(clientsFILES);
}
/*  void store_list(clientsLIST *theList)  PENDING FUNCTIONS
	void load_list(clientsLIST *theList)
	void delete_client(clientsLIST *theList)
	void sort_list(clientsLIST *theList)
	void account_desposit(clientsLIST *theList)
	void account_withdrawal(clientsLIST *theList)*/
