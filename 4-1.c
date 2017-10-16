#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
int count=10;
void inc()
{	int reg=count;
	reg+=1;
	count=reg;
	printf("\nCount in thread 1=%d\n",count);


	
	printf("%d",	
	
	
}
void dec()
{
	int reg=count;
	reg-=1;
	count=reg;
	printf("\nCount in thread 2=%d\n",count);
}

int main()
{
	pthread_t t1,t2;
	printf("\nCount before thread creation=%d\n",count);
	pthread_create(&t1,NULL,inc,NULL);
	
	pthread_create(&t2,NULL,dec,NULL);//sleep(2);
	printf("\nFinal count =%d\n",count);
	return 0;	
}
