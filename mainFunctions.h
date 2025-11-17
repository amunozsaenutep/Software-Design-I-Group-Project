void add_point_to_shape(sSHAPE *theShape)
{
	sPOINT *newPoint = malloc(sizeof(sPOINT));

	// Poll the user for the coordinates of the new point
	printf("Enter the new point's coordinates\n");
	printf("x: "); scanf("%lg", &(newPoint->x));
	printf("y: "); scanf("%lg", &(newPoint->y));
	newPoint->next = NULL; newPoint->prev = NULL;	// default pointer values are NULL

	// Queue the point at the end of the existing shape's point list
	if(theShape->tail == NULL)
	{
		// point list was empty
		theShape->count = 1;
		theShape->head = newPoint;
		theShape->tail = newPoint;
	}
	else
	{
		// Add new point to the end of the point list
		theShape->count++;
		theShape->tail->next = newPoint;
		newPoint->prev = theShape->tail;
		theShape->tail = newPoint;
	}

}

void print_shape(sSHAPE *theShape)
{
	sPOINT *travPtr;

	// If the shape has no points, print a message
	if(theShape->head == NULL)
	{
		printf("Shape undefined\n");
		return;
	}

	// Traverse the shape's list of points and print their coordinates
	travPtr = theShape->head;
	while(travPtr != NULL)
	{
		printf("x = %lg, y = %lg\n", travPtr->x, travPtr->y);
		travPtr = travPtr->next;
	}

	return;
}
