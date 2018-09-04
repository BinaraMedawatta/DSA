#include <stdio.h>

int main(){
	int i, n, m, k, b=0;
	
	printf("Enter the size of 1st array : ");
	scanf("%d", &n);
	
	int arr1[n];
	
	printf("Enter the 1st array : ");
	
	for(i=0; i<n; i++){
		scanf("%d", &arr1[i]);
	}
	
	printf("Enter the size of 2nd array : ");
	scanf("%d", &m);
	
	int arr2[m];
	
	printf("Enter the 2nd array : ");
	
	for(i=0; i<m; i++){
		scanf("%d", &arr2[i]);
	}	
	
	k = n + m;
	
	int arr3[k];
	
	for(i=0; i<k; i++){
		if(i<n){
			arr3[i] = arr1[i];
		}
		else{
			arr3[i] = arr2[b];
			b++;
		}
	}
	
	printf("New Array : ");
	
	for(i=0; i<k; i++){
		printf("%d ", arr3[i]);
	}
}
