#include <stdio.h>
#include <string.h>


int front = -1, rear = -1, count=0,num,j,h,g,k;
char qm[10][13],qw[10][13],inputList[20][13];
int i,result,u;								//for spot_finder function
int w,t;      								//for departure and related functions
int frontW = -1, rearW = -1, countW= 0;		//for add_to_waiting_list function
char nump[13];						//char variables used for testing purposes
int y;								//int variables used for testing purposes


void arrival(char carnump[]);
int spot_finder(char queue[][13],char carnump[]);
void departure(char carnump[]);
void move_forward(char queue[][13],int spot_index,int whichRear);
void move_to_tempstack(int spot_index);
void back_to_queue(int spot_index);
void add_to_waiting_queue(char carnump[]);
void waitingToMain();
int movementCounter(char queue[][13],int variable,int increment);
void mainToTempQ(int spot_index);
void tempQtoMainQ(int spot_index);
void test1();
void test2();
void test3();
void test4();
void test5();
void test6();
				


int main(){
	
		printf("-----------------------WELCOME TO LAUGHS CAR PARK------------------------------\n");
		printf("Please enter the number of inputs that you are going to enter - \n");
		scanf("%d",&num); 
		printf("Enter your inputs - \n");
		for(h=0;h<num;h++){
			scanf("%s",inputList[h]); //The entered vehicle numbers will be inserted to inputList queue.
		}
		
		
		test1();
		//test2();
		//test3();
		//test4();
		//test5();
		//test6();
		

		
		printf("\ninputList - "); 								//inputList testing
		for(h=0;h<num;h++){
			printf("%s\n",inputList[h]);
		}
		
			
		for(h=0;h<num;h++){					//This is the main loop. 
				char fLetter,vnum[11],singleInput[13]; //fLetter means the first element(Letter) of a particular user input(either d or s). The vehicle number in singleInput is assigned to vnum.
				strcpy(singleInput,inputList[h]); //This function will assign a user input string from inputList queue to singleInput array and use it for further operations.
				fLetter=singleInput[0]; //The first element(letter) of singleInput array is assigned to fLetter here to use it for further operations
				
				k=1; 										//creating the vnum string
				for(j=0;j<strlen(singleInput);j++){ 
					
					vnum[j]=singleInput[k];
					k++;		
				}
				//printf("\nvnum %d - %s",h,vnum);			//vnum testing
				
				if(fLetter=='a'){			//Here the programme is checking whether a particular user input is an arrival or departure, and function according to that
					if(count<10){
						
						printf("\n\nFree parking slots are available in the car park.\nThe vehicle bearing the number plate %s entered to the car park.",vnum);
						//printf("\n%s",vnum);           //for testing purpose
						arrival(vnum);    //Calling 'arrival' function
						
						//printf("\nThe vehicle is parked at slot number %d - %s",rear+1,vnum);    		//for testing purposes
					}
						
					else{
						printf("\n\nNo free parking slots are available in the car park.");
						printf("\nThe vehicle bearing the number plate %s is waiting in the queue.",vnum);
						add_to_waiting_queue(vnum);   //if the main car park is full, the vehicle will have to wait in the waiting queue
					}
						
				}
				else if(fLetter=='d'){
					departure(vnum);  		//this function will work when a car tries to leave from the car park
					//printf("\n\nThe vehicle bearing the number plate %s left the car park",vnum);
				}
				else
					printf("\n\nInvalid Input"); 
				
			
		}
		printf("\n\n\nFinal main queue - ");
		for(y=0;y<=rear;y++){						//Testing the final main queue
			printf("\n%d. %s Movements - %c%c",y,qm[y],qm[y][11],qm[y][12]);
		}
		
		printf("\n\n\nFinal waiting queue - ");
		for(y=frontW;y<=rearW;y++){						//Testing the final waiting queue
			printf("\n%d. %s ",y,qw[y]);
		}
		
		
	return 0;
}

void arrival(char carnump[]){ //This function will add the vehicle number string to the main queue(qm) if the car park is not full.
	
	if(front == -1 && rear == -1){
		front = rear = 0;
		strcpy(qm[rear],carnump);
		qm[rear][11]='0';
		qm[rear][12]='0';
		count++;
	}
	else{
		rear++;
		strcpy(qm[rear],carnump);
		qm[rear][11]='0';
		qm[rear][12]='0';
		count++;
	}
		
}

void add_to_waiting_queue(char carnump[]){ //This function is used to add the vehicles to the waiting queue(qw) when the car park is full
	
	if(frontW == -1 && rearW == -1){
		frontW = rearW = 0;
		strcpy(qw[rearW],carnump);
		countW++;
	}
	else{
		rearW++;
		strcpy(qw[rearW],carnump);
		countW++;
	}
		
}

void waitingToMain(){ //This funcion is used to move a vehicle from waiting queue(qw) to car park(qm) when a parking slot becomes available in the car park
	
	rear++;
	strcpy(qm[rear],qw[frontW]);
	frontW++;
	countW--;
	qm[9][11]='0';
	qm[9][12]='0';
	printf("\nThe vehicle bearing the number plate %s moved from the waiting queue to the car park.",qm[rear]);
			
}

//finding the slot_no of the parked vehicle
int spot_finder(char queue[][13],char carnump[]){  //This function will find the car in a queue(either qm or qw) and return the INDEX of it. 
	int f;
	u=0;	
	for(i=0;i<10;i++){		
		char tempArr[11];
		for(f=0;f<11;f++){
			tempArr[f]=queue[i][f];			
		}		
    	result=strcmp(carnump,tempArr); //Checks whether carnump(vnum) is matches with tempArr. if carnump = tempArr, then the 'result' will be 0
    	if(result == 0){        	
        	u=1;
			return i;        	
        	break;
		}		
	}
	if(u==0){ //if there's no vehicle which matches with that entered vehicle number, it will return -1278. that's just a random number ;)
		//printf("\nCannot find the parked slot of the vehicle bearing the number plate %s.\n",carnump);
		return -1278; //just a random number
	}
		
}

void departure(char carnump[]){ //This function will work when the car tries to leave the car park(when fletter=d)
	
	int spot_index=spot_finder(qm,carnump);
	if(spot_index != -1278){
		if(count==0){
			printf("\nCar park is empty!\n");			
		}
		else{
			if(spot_index>0)				
				mainToTempQ(spot_index);		
			printf("\n\nThe vehicle bearing the number plate %s departed from the car park.",carnump);			
			int b;
			b = movementCounter(qm,spot_index,1);	//check again
			move_forward(qm,spot_index,rear);
			count--;
			rear--;			
			printf("\nThe number of times this vehicle has moved inside the car park - %d ",b);
			while(count<10 && countW>0){
				printf("\nFree parking slots are now available in the car park.");
				waitingToMain();
				count++;
			}
			
		}
	}else{											//this part of the function will work when a vehicle trys to leave from the waiting line
		spot_index=spot_finder(qw,carnump);
		if(spot_index != -1278){
			if(count==0){
				printf("Car park is empty!\n");			
			}
			else{				
				printf("\nThe vehicle bearing the number plate %s left the car park",carnump); //check
				move_forward(qw,spot_index,rearW); //moving forward in waiting list
				countW--;
				rearW--;				
				printf("\nThis vehicle has moved for 0 times in the car park");				
			}
		}
		else
			printf("\n\nThe vehicle bearing the number plate %s is not parked in the car park.\n",carnump); //This message will be displayed when a particular car cannot be found either in the car park(qm) or in the waiting queue(qw)
	}	
}

void move_forward(char queue[][13],int spot_index,int whichRear){ //This function will count the movements of the vehicles which are moved forward when a vehicle leaves the car park. This will also move the vehicle number strings forward in the particular 2d queue(either main queue or waiting queue) when a car leaves from it.
	for(t=spot_index; t<whichRear; t++){
		strcpy(queue[t],queue[t+1]); //This will move the vehicle number strings forward in the particular 2d queue(either main queue or waiting queue) when a car leaves the car park.
		queue[t][11]=queue[t+1][11]; //227 and 228 lines will move the digits of the movement count to forward
		queue[t][12]=queue[t+1][12];
		movementCounter(queue,t,1);	//This will count the forward movements	
	}
}


void mainToTempQ(int spot_index){ //This function will count the movements of the vehicles which are moved out temporarily to let another car to leave the car park.
	
	int x;
	for(x=0; x<spot_index; x++){		
		movementCounter(qm,x,2);
	}		
}

int movementCounter(char queue[][13],int variable,int increment){ //This function will count the movements and store the count in the particular vehicle number string in main queue(qm).
	
	char r=queue[variable][11]; //Assigning the first digit of that movement count to the 12th element(index = 11) of it's vehicle number string.  
	char m=queue[variable][12];	//Assigning the second digit of that movement count to the 13th element(index = 12) of it's vehicle number string.
	
	if(r=='\0'&&m=='\0'){  //Checking whether the 12th and 13th elements of the particular array is NULL(empty). If they are NULL, the number zero will be assigned to them as a char value.
		r='0';
		m='0';
	}
	
	int s = r -'0'; //Converting the 12th element(index = 11) of the array to an int
	int v = m-'0';	//Converting the 13th element(index = 12) of the array to an int
	int z=(s*10)+v;	//Using above s and v, a complete movement count number will be created here and assigned to z
	z+=increment;	//Incrementing the movement count by either 1 or 2. For the vehicles which are moved out temporarily to let another car to depart from the park, the increment will be 2. For the vehicles which gets moved forward when a car leaves the car park, the increment will be 1.
	
	queue[variable][11]=(z/10)+'0'; //the first digit of the new movement count is assigned to the 12th element of that particular vehicle number string in main queue(qm)
	queue[variable][12]=(z%10)+'0';	//the second digit of the new movement count is assigned to the 13th element of that particular vehicle number string in main queue(qm)

	return z;
	
}

void test1(){
	//num=20;
	if(num==9){
		strcpy(inputList[0],"aCAC-3456");
		strcpy(inputList[1],"aTP-2371");
		strcpy(inputList[2],"aCAD-2390");
		strcpy(inputList[3],"dGD-1097");
		strcpy(inputList[4],"aJK-4589");
		strcpy(inputList[5],"GH-5236");
		strcpy(inputList[6],"aKL-5689");
		strcpy(inputList[7],"dCAD-2390");
		strcpy(inputList[8],"aNB-1287");
		
	}
	if(num>10){
		num=20;
		strcpy(inputList[0],"aCAC-3456");
		strcpy(inputList[1],"aTP-2371");
		strcpy(inputList[2],"aCAD-2390");
		strcpy(inputList[3],"aGH-1678");
		strcpy(inputList[4],"aJK-4589");
		strcpy(inputList[5],"dGD-1097");
		strcpy(inputList[6],"aKL-5689");
		strcpy(inputList[7],"aCBA-7890");
		strcpy(inputList[8],"GH-5236");
		strcpy(inputList[9],"aNB-1287");
		strcpy(inputList[10],"aABB-8478");
		strcpy(inputList[11],"aTI-1289");
		strcpy(inputList[12],"aKY-1490");
		strcpy(inputList[13],"dJK-4589");
		strcpy(inputList[14],"dNB-1287");
		strcpy(inputList[15],"aQE-2749");
		strcpy(inputList[16],"a301-6764");
		strcpy(inputList[17],"dCAD-2390");
		strcpy(inputList[18],"dKY-1490");
		strcpy(inputList[19],"aTJ-1289");
	}
}

void test2(){							//Movement Counter exceeds 10 
	num=20;
	strcpy(inputList[0],"aTP-2371");
	strcpy(inputList[1],"aCAC-3456");
	strcpy(inputList[2],"aCAD-2390");
	strcpy(inputList[3],"aGH-1678");
	strcpy(inputList[4],"aJK-4589");
	strcpy(inputList[5],"dGH-1678");
	strcpy(inputList[6],"aKL-5689");
	strcpy(inputList[7],"aCBA-7890");
	strcpy(inputList[8],"aGH-5236");
	strcpy(inputList[9],"aNB-1287");
	strcpy(inputList[10],"aABB-8478");
	strcpy(inputList[11],"aTI-1289");
	strcpy(inputList[12],"aKY-1490");
	strcpy(inputList[13],"dJK-4589");
	strcpy(inputList[14],"dNB-1287");
	strcpy(inputList[15],"aQE-2749");
	strcpy(inputList[16],"a301-6764");
	strcpy(inputList[17],"dCAD-2390");
	strcpy(inputList[18],"dKY-1490");
	strcpy(inputList[19],"dTI-1289");
}

void test3(){							//testing - A vehicle which was in the waiting line departed
	num=20;
	strcpy(inputList[0],"aTP-2371");
	strcpy(inputList[1],"aCAC-3456");
	strcpy(inputList[2],"aCAD-2390");
	strcpy(inputList[3],"aGH-1678");
	strcpy(inputList[4],"a300sri2233");
	strcpy(inputList[5],"aPO-2378");
	strcpy(inputList[6],"aKL-5689");
	strcpy(inputList[7],"aCBA-7890");
	strcpy(inputList[8],"aGH-5236");
	strcpy(inputList[9],"aNB-1287");
	strcpy(inputList[10],"aABB-8478");
	strcpy(inputList[11],"aTI-1289");
	strcpy(inputList[12],"aKY-1490");
	strcpy(inputList[13],"aGF-2389");
	strcpy(inputList[14],"dNB-1287");
	strcpy(inputList[15],"aQE-2749");
	strcpy(inputList[16],"a301-6764");
	strcpy(inputList[17],"dGF-2389");
	strcpy(inputList[18],"a12sri9921");
	strcpy(inputList[19],"dTI-1289");
}

void test4(){							//117 and 118 lines are added to 'arrival' function because of the logical error which showed by this test
	num=20;
	strcpy(inputList[0],"aTP-2371");
	strcpy(inputList[1],"aCAC-3456");
	strcpy(inputList[2],"aCAD-2390");
	strcpy(inputList[3],"aGH-1678");
	strcpy(inputList[4],"a300sri2233");
	strcpy(inputList[5],"aPO-2378");
	strcpy(inputList[6],"aKL-5689");
	strcpy(inputList[7],"aCBA-7890");
	strcpy(inputList[8],"aGH-5236");
	strcpy(inputList[9],"aNB-1287");
	strcpy(inputList[10],"dNB-1287");
	strcpy(inputList[11],"dPO-2378");
	strcpy(inputList[12],"aKY-1490");
	strcpy(inputList[13],"aGF-2389");
	strcpy(inputList[14],"d300sri2233");
	strcpy(inputList[15],"aQE-2749");
	strcpy(inputList[16],"a301-6764");
	strcpy(inputList[17],"dGF-2389");
	strcpy(inputList[18],"a12sri9921");
	strcpy(inputList[19],"dTI-1289");
}

void test5(){							//testing - checking for any possible capacity issues in tempstack
	num=20;
	strcpy(inputList[0],"aTP-2371");
	strcpy(inputList[1],"aCAC-3456");
	strcpy(inputList[2],"aCAD-2390");
	strcpy(inputList[3],"aGH-1678");
	strcpy(inputList[4],"a300sri2233");
	strcpy(inputList[5],"aPO-2378");
	strcpy(inputList[6],"aKL-5689");
	strcpy(inputList[7],"aCBA-7890");
	strcpy(inputList[8],"aGH-5236");
	strcpy(inputList[9],"aNB-1287");
	strcpy(inputList[10],"aABB-8478");
	strcpy(inputList[11],"aTI-1289");
	strcpy(inputList[12],"aKY-1490");
	strcpy(inputList[13],"dKL-5689");
	strcpy(inputList[14],"dNB-1287");
	strcpy(inputList[15],"aQE-2749");
	strcpy(inputList[16],"a301-6764");
	strcpy(inputList[17],"dGF-2389");
	strcpy(inputList[18],"a12sri9921");
	strcpy(inputList[19],"dTI-1289");
}

void test6(){							//testing - first input is a departure
	num=20;
	strcpy(inputList[0],"dTP-2371");
	strcpy(inputList[1],"aCAC-3456");
	strcpy(inputList[2],"aCAD-2390");
	strcpy(inputList[3],"aGH-1678");
	strcpy(inputList[4],"a300sri2233");
	strcpy(inputList[5],"aPO-2378");
	strcpy(inputList[6],"aKL-5689");
	strcpy(inputList[7],"aCBA-7890");
	strcpy(inputList[8],"aGH-5236");
	strcpy(inputList[9],"aNB-1287");
	strcpy(inputList[10],"aABB-8478");
	strcpy(inputList[11],"aTI-1289");
	strcpy(inputList[12],"aKY-1490");
	strcpy(inputList[13],"dKL-5689");
	strcpy(inputList[14],"dNB-1287");
	strcpy(inputList[15],"aQE-2749");
	strcpy(inputList[16],"a301-6764");
	strcpy(inputList[17],"dGF-2389");
	strcpy(inputList[18],"a12sri9921");
	strcpy(inputList[19],"dTI-1289");
}


