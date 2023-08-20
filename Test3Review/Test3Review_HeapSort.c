
void heapSwapPointers(int** arrPointers, int indexOne, int indexTwo)
{
	int* temp = arrPointers[indexOne];
	arrPointers[indexOne] = arrPointers[indexTwo];
	arrPointers[indexTwo] = temp;
}

void heapSwapNumbers(int* arrNumbers, int indexOne, int indexTwo)
{
	int temp = arrNumbers[indexOne];
	arrNumbers[indexOne] = arrNumbers[indexTwo];
	arrNumbers[indexTwo] = temp;
}

void maxHeapifyNumberArray(int* arrNumbers, int lengthArr, int parentIndex)
{
	int childIndex = 2 * parentIndex + 1;
	
	while (childIndex < lengthArr - 1)
	{
		if (arrNumbers[childIndex] < arrNumbers[childIndex + 1])
		{
			childIndex++;
		}
		
		if (arrNumbers[parentIndex] > arrNumbers[childIndex])
		{
			break;
		}
		
		heapSwapNumbers(arrNumbers, parentIndex, childIndex);
		parentIndex = childIndex; 
		childIndex = 2 * parentIndex + 1;
	}
}

void maxHeapifyPointerArray(int** arrPointers, int lengthArr, int parentIndex)
{
	int childIndex = parentIndex * 2 + 1;
	
	if (childIndex >= lengthArr - 1)
	{
		return;
	}
	
	if (*arrPointers[childIndex] < *arrPointers[childIndex + 1])
	{
		childIndex++;
	}
	
	if (*arrPointers[childIndex] > *arrPointers[parentIndex])
	{
		heapSwapPointers(arrPointers, childIndex, parentIndex);
	}
	
	maxHeapifyPointerArray(arrPointers, lengthArr, childIndex);
}

void heapSortNumberArray(int* arrNumbers, int lengthArr)
{
	for (int i = lengthArr / 2; i >= 0; i--)
	{
		maxHeapifyNumberArray(arrNumbers, lengthArr, i);
	}
	
	for (int i = lengthArr - 1; i >= 0; i--)
	{
		heapSwapNumbers(arrNumbers, i, 0);
		maxHeapifyNumberArray(arrNumbers, i, 0);
	}
}

void heapSortPointerArray(int** arrPointers, int lengthArr)
{
	for (int i = lengthArr / 2; i >= 0; i--)
	{
		maxHeapifyPointerArray(arrPointers, lengthArr, i);
	}
	
	for (int i = lengthArr - 1; i >= 0; i--)
	{
		heapSwapPointers(arrPointers, i, 0);
		maxHeapifyPointerArray(arrPointers, i, 0);
	}
}
