#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int num;
int *process;
int cord;
bool flag;
void init_elct(int d, int intiater,int Lalive){

	if(flag){
	if(d==intiater){
	
		cord =Lalive;
		return;
	}
	}
	else{
		flag=true;
	}
	for(int i=d+1;i<num;i++){
		printf("sending elect_init from %d to %d \n",d,i);
		if(process[i]==1){
		if(Lalive<i){
			Lalive = i;
		}
			printf("%d alive so %d stoping \n",i,d);
			
			init_elct(i,intiater,Lalive);
			
			return;
		}
	}
	for(int i=0;i<d+1;i++){
	if((d==intiater)&(flag==true)){
		cord =Lalive;
		return;
	}
		printf("sending elect_init from %d to %d \n",d,i);
		if(process[i]==1){
		if(Lalive<i){
			Lalive = i;
		}
			printf("%d alive so %d stoping \n",i,d);
			init_elct(i,intiater,Lalive);
			return;
		}
	}
	
	


}



int main(int argc,char *argv){
	
	printf("Enter num of process to intiate : ");
	scanf("%d",&num);
	process =(int*)malloc(sizeof(int)*num);
	for(int i=0;i<num;i++){
	
	process[i] = 1;
	}
	
	cord = num-1;
	int c,d;
	while(1){
	printf("cord is %d\n",cord);
	
	printf("enter options = ");
	scanf("%d",&c);
	if(c==0){
	//disply
	for(int i=0;i<num;i++){
	
	printf("%d is %d \n",i,process[i]);
	}
	}
	
	if(c==1){
	//kill
	printf("enter process to kill : ");
	scanf("%d",&d);
	if(d<num){
		process[d] = 0;
	}
	else{
	printf("error process number \n");
	
	
	}
	continue;
	}
	
	if(c==2){
	
	printf("enter process to init checking : ");
	scanf("%d",&d);
	
	if(process[cord]!=1){
		printf("cord dead : intiate elction\n");
		if(process[d]==1){
		flag =false;
		init_elct(d,d,d);
		}
		else{
			printf("%d process is dead\n",d);
		}
		
	}
	else{
	printf("alive only u go \n");
	}
	
	}
	

	}
}
