#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<sys/shm.h>
static int consumed,produced;
struct shmem_structure {
int field1;
int field2;
};
void *Producer(),*Consumer();
int main()
{
pthread_t t1,t2;
pthread_create(t1,NULL,Producer,NULL);
pthread_create(t2,NULL,Consumer,NULL);
pthread_join(t1,NULL);
pthread_join(t2,NULL);
}
void *Producer(){
struct shmem_structure *shptr = get_shared_memory_structure();
int produced = produceNext();
printf("\nproducer produced : %d",produced);
shptr->field1=produced;
shptr->field2 = 1; //indicating ready
while(shptr->field2 == 1);
}
void *Consumer(){
struct shmem_structure *shptr = get_shared_memory_structure();
while(shptr->field2 == 0); //do nothing
consumed=shptr->field1;
consumeNext(consumed);
shptr->field2 = 0; //indicating done
}
int producedNext(){
if(produced!=consumed){
printf("\nError! Consumer did'nt consumed the value \n");
consumeNext(consumed);
}
int i;
while(i!=10){
int x;
x++;
i++;
return x;
}
}
void consumeNext(int y){
int z;
int i;
while(i!=10){
z=y;
printf("\nConsumer consumed : %d",z);
}
}

