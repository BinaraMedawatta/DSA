#include <stdio.h>
#define MAX 10										//	Max is the total number of chairs in the barber shop (Including the barber room) 

char queue[MAX];									//	Here we are using a circular queue 
int front = 0, rear = 0, count = 0;
void enqueue();
void dequeue();
int leave();

int main(){
	int cho;
	
	do{
		printf("\n\n***** Main Menu *****");		
		printf("\n1. Cliant arrives");
		printf("\n2. Cliant leaves");
		printf("\n3. Exit");
		printf("\n******** END ********");
		printf("\nEnter your choice : ");
		scanf("%d", &cho);
		
		switch(cho){
			case 1 : 
				enqueue();							//	When a client enters the barber shop then the enqueue function is called.
				break;
				
			case 2 :
				dequeue();							//	When client leaves the barber shop after having a hair cut then the dequeue function is called. 
				break;
		}
	}while (cho!=3);
	
}

void enqueue(){
	char client[20];
	
	if(count==0){
		printf("\nThe barber is asleep");			//	When the first client is arriving the barber is asleep (ie. count = 0)
	}
	else{
		printf("\nThe barber is busy");				//	If it isn't the first one then that means the barber is busy (ie. count != 0)
	}
	
	printf("\nEnter client name : ");				//	Input the client name here.
	scanf("%s", &client);
	
	if(count==MAX){
		printf("\nNo chairs");						//	If the number of clients in the shop is equal to the maximunm number of chairs then
		printf("\n%s left", client);				//	The client leaves.
		return;
	}
	else if(count==0){
		front = 0;									//	count = 0, ie. no client is in the barber shop so the first client enters into the
		rear = (rear + 1) % MAX;					//	barber rooom and gets the hair cut.
		queue[front] = client[20];					//	The count becomes 1 because one of the total number of chairs is occupied (Barber room)
		count++;
		
		printf("\n%s wakes the barber", client);
		printf("\n%s is in the barber room", client);
		
		return;
	}
	else{
		rear = (rear + 1) % MAX;					//	If the barber is busy ie. MAX > count > 1, then the client waits in the waiting room. 
		queue[rear] = client[20];					//	Until his chance.
		count++;
		
		printf("\n%s is in the waiting room", client);
		return;
	}
}

void dequeue(){										//	When a client leaves after having a hair cut then the dequeue function is called.
	char val[20];
	if(count==0){
		printf("The barber goes to sleep");			//	When both the waiting room and the barber room are free (All clients have left the shop), then
		return;										//	The barber goes to sleep.
	}
	else{
		val[20] == queue[front];
		front = (front + 1) % MAX;
		count = count - 1;							//	Clients leave the salon after the hair cut, so the count is reduced by one.
		printf("\n%s left the salon", val);			
	}
	
	if(count==0){
		printf("\nThe barber goes to sleep");		//	When count = 0 (No one is left in the shop) then the barber goes to sleep.
		return;
	}
	else{
		return;
	}
}
