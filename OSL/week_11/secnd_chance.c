#include <stdio.h>
#include <limits.h>
#define size 3
int counter=0;
int faults=0;
int firstin=-1;
int find(int frame[][2],int req){
	for(int i=0;i<size;i++)
		if(frame[i][0]==req){
			return i;
		}
	return -1;	
}
int secondchance(int frame[][2],int req){
	int res=find(frame,req);
	
	if(res==-1){
		printf("\n\nFault:%d not found\n",req);
		faults++;
		int vic=firstin;
		
		for(int i=vic;;i=(i+1)%size){
			if(frame[i][1]==0)
				break;
			else
				frame[i][1]=0;
		}

		if(vic==firstin)
			firstin=(firstin+1)%size;
		
		frame[vic][0]=req;
		
		frame[vic][1]=1;	
	}

	else{
		frame[res][1]=1;
		printf("\n\n%d found\n",req);

	}

	for(int j=0;j<size;j++)
			printf("%d\t",frame[j][0]);
		printf("\n");
		for(int j=0;j<size;j++)
			printf("%d\t",frame[j][1]);
	//counter++;
}
int main(){
	int frame[size][2]; //frame[][0]=intime, [][1]=last used, [][2]=distancetillnext
	for(int i=0;i<size;i++){
		frame[i][0]=-1;
		frame[i][1]=0;
	}
	int n;
	int req[20];
	printf("Number of requests:");
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&req[i]);
	}
	printf("\n");
	for(int i=0;i<n;i++){
		secondchance(frame,req[i]);	
	}
	printf("\nFaults:%d\n",faults);
}
