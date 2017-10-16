#include<stdio.h>
#include<stdlib.h>
struct fcfs
{
	int *pid;
	int *burst_time;
	int *arrival_time;
	int *priority;
	int *wait_time;
	int *response_time;
	
};
int main()
{
	struct fcfs f1;
	int i,n;
	printf("Enter the no of processes");
	scanf("%d",&n);
	f1.burst_time=(int *) malloc(sizeof(struct fcfs)*n);
	f1.arrival_time=(int *) malloc(sizeof(struct fcfs)*n);
	f1.priority=(int *) malloc(sizeof(struct fcfs)*n);
	f1.pid=(int *) malloc(sizeof(struct fcfs)*n);
	f1.response_time=(int *) malloc(sizeof(struct fcfs)*n);
	f1.wait_time=(int *) malloc(sizeof(struct fcfs)*n);
	printf("\nEnter pid of the processes\n");		
	for(i=0;i<n;i++)
	{
		scanf("%d",&f1.pid[i]);
	}
	printf("\nEnter burst time of the processes\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&f1.burst_time[i]);
	}
	printf("\nEnter arrival time of the processes\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&f1.arrival_time[i]);
	}		
	printf("\nEnter priority time of the processes\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&f1.priority[i]);
	}
	int j,temp;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(f1.arrival_time[i]<f1.arrival_time[j])
			{
				temp=f1.arrival_time[i];
				f1.arrival_time[i]=f1.arrival_time[j];
				f1.arrival_time[j]=temp;
				temp=f1.pid[i];
				f1.pid[i]=f1.pid[j];
				f1.pid[j]=temp;
				temp=f1.burst_time[i];
				f1.burst_time[i]=f1.burst_time[j];
				f1.burst_time[j]=temp;
				temp=f1.priority[i];
				f1.priority[i]=f1.priority[j];
				f1.priority[j]=temp;
			}
		}
	}
	int waittime=0;
	for(i=0;i<n;i++)
	{
		f1.wait_time[i]=waittime;
		f1.response_time[i]=f1.wait_time[i];
		waittime=waittime+f1.burst_time[i];
	}
	
	for(i=0;i<n;i++)
	{
		printf("\nPID=%d",f1.pid[i]);
		printf("\nBurst time=%d(ms)",f1.burst_time[i]);
		printf("\nArrival_time=%d(ms)",f1.arrival_time[i]);
		printf("\nPriority_time=%d(ms)",f1.priority[i]);
		printf("\nResponse_time=%d(ms)",f1.response_time[i]);
		printf("\nWait_time=%d(ms)",f1.wait_time[i]);
	}
	
}
