#include <stdio.h>
#include <stdbool.h>

int main(){
	//The total amount of numbers to order, aka the length of the list
	int totalCount;
	printf("Please enter the amount of numbers to order: \n");
	scanf("%d", &totalCount);
	
	//The list containing all the numbers
	int list[totalCount];
	
	printf("Now please enter the integers to sort one at the time: \n");
	for(int i = 0; i < totalCount; i++){
		printf("[%d]: ", i);
		scanf("%d", &list[i]);
	}

	//Loop while it is not sorted
	bool isSorted = false;
	//Optimization, since it will swap all the elements till the last one, the last element will be the biggest and it can be skipped
	//in order to save time
	int lastUnsorted = totalCount - 1;
	//totalCount - 1; is due to having to access [i] and [i+1], if lastUnsorted = totalCount then at the end of the loop it will throw an exception

	while(!isSorted){
		//Assume it is sorted
		isSorted = true;
		for(int i = 0; i < lastUnsorted; i++){
			//Depending on the < > it will be from biggest to smallest or the other way around
			if(list[i] > list[i+1]){
				//Swap the values, use this temp var since you're replacing it's value with [i+1]
				int temp = list[i];
				list[i] = list[i+1];
				list[i+1] = temp;
				//When looping through the list if this statement is entered it means it is not sorted
				isSorted = false;
			}
		}
		//Since it is the length of the array just substract one
		lastUnsorted--;
	}
	
	printf("Sorted list:\n");
	for(int i = 0; i < totalCount; i++)
		printf("[%d]: %d\n", i, list[i]);

	return 0;
}
