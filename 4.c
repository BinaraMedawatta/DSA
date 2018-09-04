#include <stdio.h>

int main(){
	int i, a=0, b=0;
	
	char A[4] = {'A', 'A', 'A', 'A'};
	
	char B[4] = {'B', 'B', 'B', 'B'};
	
	char AB[8];
	
	for(i=0; i<8; i++){
		if(i%2==1){
			AB[i] = B[b];
			b++;
			continue;
		}
		else{
			AB[i] = A[a];
			a++;
			continue;
		}
		
	}
	
	printf("A[4]  : ");
	
	for(i=0; i<4; i++){
		printf("%c ", A[i]);
	}	
	
	printf("\nB[4]  : ");
	
	for(i=0; i<4; i++){
		printf("%c ", B[i]);
	}	
	
	printf("\nAB[8] : ");
	
	for(i=0; i<8; i++){
		printf("%c ", AB[i]);
	}
}
