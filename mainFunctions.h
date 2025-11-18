//We will write the functions that we were asked for on this file

void add_client_info(clientsLIST *theList)
{
	accINFO *newClient = malloc(sizeof(accINFO));

	// Poll the user for the coordinates of the new point
	printf("Enter the new point's coordinates\n");
	printf("x: "); scanf("%lg", &(newClient->x));
	printf("y: "); scanf("%lg", &(newClient->y));
	newClient->next = NULL; newClient->prev = NULL;	// default pointer values are NULL

	// Queue the point at the end of the existing shape's point list
	if(theList->tail == NULL)
	{
		// point list was empty
		theList->count = 1;
		theList->head = newClient;
		theList->tail = newClient;
	}
	else
	{
		// Add new point to the end of the point list
		theList->count++;
		theList->tail->next = newClient;
		newClient->prev = theList->tail;
		theList->tail = newClient;
	}

}

void print_clients_list(clientsLIST *theList)
{
	accINFO *travPtr;

	// If the shape has no points, print a message
	if(theList->head == NULL)
	{
		printf("Shape undefined\n");
		return;
	}

	// Traverse the shape's list of points and print their coordinates
	travPtr = theList->head;
	while(travPtr != NULL)
	{
		printf("x = %lg, y = %lg\n", travPtr->x, travPtr->y);
		travPtr = travPtr->next;
	}

	return;
}
/*  void store_list(clientsLIST *theList)  PENDING FUNCTIONS
	void load_list(clientsLIST *theList)
	void delete_client(clientsLIST *theList)
	void sort_list(clientsLIST *theList)
	void account_desposit(clientsLIST *theList)
	void account_withdrawal(clientsLIST *theList)
