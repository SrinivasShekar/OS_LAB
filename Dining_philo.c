#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<semaphore.h>

#define n 5
sem_t chop[5];
#define EATING 1
#define THINKING 2
#define HUNGRY 3
int states[n];
int count=0;
sem_t hold;
void eat(i)
{
		if(states[i]==HUNGRY && states[(i-1) % n]!=EATING && states[(i+1) %n]!=EATING)
		{
			if(count==0)
			{
			
			sem_wait(&hold);	
			states[i]=EATING;
			printf("Philosophers %d is eating\n",i);
			count++;
			sem_post(&hold);
			printf("Philosophers %d finished eating\n",i);
			}
			else
			{
			sem_wait(&hold);
			sem_wait(&chop[i]);
			sem_wait(&chop[(i+1) % 5]);
		
			states[i]=EATING;
			printf("Philosophers %d is eating\n",i);
			sem_post(&chop[i]);
			sem_post(&chop[(i+1)%5]);
			states[i]=THINKING;
			sem_post(&hold);
			printf("Philosophers %d finished eating\n",i);
			}
		}
		else
		{
			sleep(2);		
		}
}
void *pro(int i)
{
	
	
		//printf("hi");
		printf("Philosophers %d is thinking\n",i);
		states[i]=THINKING;
		sleep(2);
		states[i]=HUNGRY;
		eat(i);
		sleep(2);
		//printf("hi");
		
		
				
	
}
int main()
{
	int i,j;
	pthread_t p[5];
	sem_init(&hold,0,1);
	//sem_init(&buffer_empty,0,5);
	for(i=0;i<n;i++)
	{
		sem_init(&chop[i],0,1);
		
	}
	for(i=0;i<n;i++)
	{
		pthread_create(&p[i],NULL,&pro,i);
		usleep(1);	
	}
	for(j=0;j<n;j++)
	{
		pthread_join(&p[i],NULL);
		//printf("hi");
	}
	
	return 0;
}

