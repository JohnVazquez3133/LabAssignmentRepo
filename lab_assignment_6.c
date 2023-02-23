#include <stdio.h>

int search(int numbers[], int low, int high, int value) 
{
	//search for the middle of the subarray
	int middleIndex = (low + high) / 2;
	////middle = 1
	////2,5,7,8 low 0 high 3 value 5
	//Check to see if low ends up greater than high as a result of taking 1 away from high as we search, in which case return -1
	if (low > high) {
		return(-1);
	}
	//check to see if the number held by the middle index is the number you are looking for, if so return it.
	//double equal sign, not regular
	if (numbers[middleIndex] == value) {
		return(middleIndex);
	}
	//Searching subarray on the left side of the array
	else if (numbers[middleIndex] > value) {
		//middle index -1 is the new high
		return(search(numbers, low, middleIndex - 1, value));
		////2,5,7,8 , 0, 0, 4
	}
	//searching numbers on the right side of the subarray
	else {
		return(search(numbers, middleIndex + 1, high, value));  // search right subarray
		////2,5,7,8, 1, 0, 4
	}
}

void printArray(int numbers[], int sz)
{
	int i;
	printf("Number array : ");
	for (i = 0;i<sz;++i)
	{
		printf("%d ",numbers[i]);
	}
	printf("\n");
}

int main(void)
{
	int i, numInputs;
	char* str;
	float average;
	int value;
	int index;
	int* numArray = NULL;
	int countOfNums;
	FILE* inFile = fopen("input.txt","r");

	fscanf(inFile, " %d\n", &numInputs);
	
	while (numInputs-- > 0)
	{
		fscanf(inFile, " %d\n", &countOfNums);
		numArray = (int *) malloc(countOfNums * sizeof(int));
		average = 0;
		for (i = 0; i < countOfNums; i++)
		{
			fscanf(inFile," %d", &value);
			numArray[i] = value;
			average += numArray[i];
		}

		printArray(numArray, countOfNums);
		value = average / countOfNums;
		index = search(numArray, 0, countOfNums - 1, value);
		if (index >= 0)
		{
			printf("Item %d exists in the number array at index %d!\n",value, index);
		}
		else
		{
			printf("Item %d does not exist in the number array!\n", value);
		}

		free(numArray);
	}

	fclose(inFile);
}