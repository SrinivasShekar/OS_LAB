#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
pthread_mutex_t mutex,full,empty=PTHREAD_MUTEX_INITIALIZER;


int buffer_size=5;
int counter=0;
void pro()
{
	pthread_mutex_lock(&mutex);
	if(counter==buffer_size)
	{
		pthread_cond_wait(&empty,&mutex);
	}
	counter++;
	printf("Counter in pro=%d\n",counter);
	pthread_mutex_unlock(&mutex);
	pthread_cond_signal(&full);
	
}
void con()
{
	pthread_mutex_lock(&mutex);
	if(counter==0)
	{
		pthread_cond_wait(&full,&mutex);
	}
	counter--;
	printf("Counter in con=%d\n",counter);
	pthread_mutex_unlock(&mutex);
	pthread_cond_signal(&empty);
	
}
int main()
{
	
	pthread_t p,c;int i;
	for(i=0;i<5;i++)
	{
		pthread_create(&p,NULL,pro,NULL);
		pthread_create(&c,NULL,con,NULL);
	}
	
	return 0;
}
