#include <stdio.h>

int main(){
	int i, a=0;
	
	int arr1[3] = {1, 2, 3};			//	First array - size = 3
	int arr2[5] = {5, 6, 7, 8, 9};			//	Second array - size = 5
	int arr3[8];					//	Third array - size = arr1_size + arr2_size = 8
	
	printf("1st Array : ");				//	Printing 1st array
	
	for(i=0; i<3; i++){				//	i is taken from 0 to 3 because the array consists of 3 elements
		printf("%d ", arr1[i]);			//	array is printed here
	}
	
	printf("\n2nd Array : ");			//	Printing 2nd array
	
	for(i=0; i<5; i++){				//	i is taken from 0 to 5 because the array consists of 5 elements
		printf("%d ", arr2[i]);			//	array is printed here
	}
	
	for(i=0; i<8; i++){				//	i is taken from 0 to 8 because the third array consists of 8 elements, sum of other two arrays
		if(i<3){				//	i<3 means the first three elements, those elements are the elements of 1st array.
			arr3[i] = arr1[i];		//	Here we assign the elements of 1st array to the 3rd one.
		}
		else{					//	if i<3 is false (ie: i>=3) then the elements to be inserted are in the 2nd array.
			arr3[i] = arr2[a];		//	So we assign the values of the 2nd array to the 3rd one. Here we are using a variable 'a' insted of 'i'
			a++;				//	for the array index of 2nd array. If we use i for that the elements will start to enter 3rd array starting 
		}					//	from 'i' (i>=3), so you will loose the first three elements. 
	}						//	'a' is also incremented as 'i'
	
	printf("\n3rd Array : ");			//	Printing 3rd array
	
	for(i=0; i<8; i++){				//	i is taken from 0 to 8 because the array consists of 3 elements
		printf("%d ", arr3[i]);			//	array is printed here
	}
	
	return 0;
}
