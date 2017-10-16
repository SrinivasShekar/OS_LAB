#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<semaphore.h>

sem_t lock;

sem_t buffer_full;

sem_t buffer_empty;
int buffer[5];
int fill=0;
int use=0;
void pro()
{
	int i;
	for(i=0;i<5;i++)
	{
		
		sem_wait(&buffer_empty);
		sem_wait(&lock);
		put(i);
		printf("pro=%d\n",i);
		//sleep(5);
		sem_post(&lock);
		sem_post(&buffer_full);
	}
	
}
void con()
{
	int i;
	for(i=0;i<5;i++)
	{
		sem_wait(&buffer_full);
		sem_wait(&lock);
		int temp=get();
		printf("con=%d\n",temp);
		//sleep(3);
		sem_post(&lock);
		sem_post(&buffer_empty);
		
	}
}
int main()
{
	pthread_t p,c;
	sem_init(&buffer_empty,0,5);
	sem_init(&buffer_full,0,0);
	sem_init(&lock,0,1);
	pthread_create(&p,NULL,pro,NULL);
	pthread_create(&c,NULL,con,NULL);
	pthread_join(p,NULL);
	pthread_join(c,NULL);
	return 0;
}
void put(int value)
{
	buffer[fill]=value;
	fill=(fill+1)%5;
}


int get()
{
	int temp=buffer[use];
	use=(use+1)%5;
	return temp;
}
