
typedef struct NumberList
{
	struct NumberList* pntNextNode;
	int numberData;
} NumberList;

NumberList* initializeBlankedNumberList();

NumberList* intializedDetailedNumberList(int number);

void insertNumberIntoListOrdered(NumberList** numberList, int number);

void insertNumberIntoListUnordered(NumberList** numberList, int number);

void bubbleSortNumberList(NumberList** numberList);

