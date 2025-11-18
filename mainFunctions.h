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

void add_client_info(accLIST *clientsLIST)
{
	accINFO *newClient = malloc(sizeof(accINFO));

	// Poll the user for the coordinates of the new point
	printf("Enter the new point's coordinates\n");
	//printf("x: "); scanf("%lg", &(newClient->x));
	//printf("y: "); scanf("%lg", &(newClient->y));
	newClient->next = NULL; newClient->prev = NULL;	// default pointer values are NULL

	// Queue the point at the end of the existing shape's point list
	if(clientsLIST->tail == NULL)
	{
		// point list was empty
		clientsLIST->count = 1;
		clientsLIST->head = newClient;
		clientsLIST->tail = newClient;
	}
	else
	{
		// Add new point to the end of the point list
		clientsLIST->count++;
		clientsLIST->tail->next = newClient;
		newClient->prev = clientsLIST->tail;
		clientsLIST->tail = newClient;
	}

}

void print_clients_list(accLIST *clientsLIST)
{
	accINFO *travPtr;

	// If the shape has no points, print a message
	if(clientsLIST->head == NULL)
	{
		printf("Shape undefined\n");
		return;
	}

	// Traverse the shape's list of points and print their coordinates
	travPtr = clientsLIST->head;
	while(travPtr != NULL)
	{
		//printf("x = %lg, y = %lg\n", travPtr->x, travPtr->y);
		travPtr = travPtr->next;
	}

	return;
}
/*  void store_list(clientsLIST *theList)  PENDING FUNCTIONS
	void load_list(clientsLIST *theList)
	void delete_client(clientsLIST *theList)
	void sort_list(clientsLIST *theList)
	void account_desposit(clientsLIST *theList)
	void account_withdrawal(clientsLIST *theList)*/
