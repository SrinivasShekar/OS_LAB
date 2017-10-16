#include<stdio.h>
#include<stdlib.h>
struct fcfs
{
	int *pid;
	int *burst_time;
	int *tat;
	int *response_time;
	int *wait_time;
	
	
};
int main()
{
	struct fcfs f1;
	int i,n;
	printf("Enter the no of processes");
	scanf("%d",&n);
	f1.burst_time=(int *) malloc(sizeof(struct fcfs)*n);
	f1.tat=(int *) malloc(sizeof(struct fcfs)*n);
	//f1.priority=(int *) malloc(sizeof(struct fcfs)*n);
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
	/*
	printf("\nEnter arrival time of the processes\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&f1.arrival_time[i]);
	}
			
	printf("\nEnter priority time of the processes\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&f1.priority[i]);
	}*/
	int j,temp;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(f1.burst_time[i]<f1.burst_time[j])
			{
				//temp=f1.burst_time[i];
				//f1.priority[i]=f1.burst_time[j];
				//f1.priority[j]=temp;
				temp=f1.pid[i];
				f1.pid[i]=f1.pid[j];
				f1.pid[j]=temp;
				temp=f1.burst_time[i];
				f1.burst_time[i]=f1.burst_time[j];
				f1.burst_time[j]=temp;
				//temp=f1.priority[i];
				//f1.priority[i]=f1.priority[j];
				//f1.priority[j]=temp;
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
		f1.tat[i]=f1.burst_time[i]+f1.wait_time[i];
	}
	float avg ;int sum=0,sum1=0;
	for(i=0;i<n;i++)
	{
		sum=sum+f1.wait_time[i];
		sum1=sum1+f1.tat[i];
	
	}
	float avg1=(float)sum/n;
	avg=(float)sum1/n;
	for(i=0;i<n;i++)
	{
		printf("\nPID=%d",f1.pid[i]);
		printf("\nBurst time=%d(ms)",f1.burst_time[i]);
		//printf("\nArrival_time=%d(ms)",f1.arrival_time[i]);
		//printf("\nPriority_time=%d(ms)",f1.priority[i]);
		//printf("\nResponse_time=%d(ms)",f1.response_time[i]);
		printf("\nWait_time=%d(ms)",f1.wait_time[i]);
		printf("\nTurnaround time=%d(ms)",f1.tat[i]);
		
		printf("\n\n\n");
	}
	printf("\nAverage Waiting time=%f(ms)\n",avg1);
	printf("\nAverage TAT time=%f(ms)\n",avg);
}
