
void shellSwapPointers(int** arrPointers, int indexOne, int indexTwo)
{
	int* temp = arrPointers[indexOne];
	arrPointers[indexOne] = arrPointers[indexTwo];
	arrPointers[indexTwo] = temp;
}

void shellSwapNumbers(int* arrNumbers, int indexOne, int indexTwo)
{
	int temp = arrNumbers[indexOne];
	arrNumbers[indexOne] = arrNumbers[indexTwo];
	arrNumbers[indexTwo] = temp;
}

void shellSortNumberArray(int* arrNumbers, int lengthArr)
{
	for (int j = lengthArr / 2; j > 0; j = j / 2)
	{
		for (int i = 0; i < lengthArr; i++)
		{
			int temp = i;
			while (temp + j < lengthArr)
			{
				if (arrNumbers[temp] > arrNumbers[temp + j])
				{
					shellSwapNumbers(arrNumbers, temp, temp + j);
				}
				temp += j;
			}
		}
	}
}




































void shellSortPointerArray(int** arrPointers, int lengthArr)
{
	for (int gap = lengthArr / 2; gap > 0; gap /= 2)
	{
		for (int currentIndex = 0; currentIndex < lengthArr; currentIndex++)
		{
			int tempIndex = currentIndex;
			
			while (tempIndex + gap < lengthArr)
			{
				if (*arrPointers[tempIndex] > *arrPointers[tempIndex + gap])
				{
					shellSwapPointers(arrPointers, tempIndex, tempIndex + gap);
				}
				
				tempIndex += gap;
			}
		}
	}
}
