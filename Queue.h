#ifndef Queue_h
#define Queue_h

#include "Node.h"

typedef struct {
	 NodePtr headPtr,tailPtr;
	int size;
}Queue;


void enqueue_struct(Queue* q, int x){
  Node *new_node=(Node*) malloc(sizeof(Node));
if(new_node){
  new_node->data=x;
  new_node->nextPtr=NULL; 
  /*Finish enqueue */
  if(q->tailPtr==NULL) {
    q->headPtr=new_node;
    q->tailPtr=new_node;
  }
  else {
    q->tailPtr->nextPtr=new_node;
    q->tailPtr =new_node;
  }
  q->size++;
}
}


int dequeue_struct(Queue *q){
   NodePtr t=q->headPtr;
   if(t){
   int value= t->data;
   q->headPtr =t->nextPtr;
       /*Finish dequeue */
  // if(q->size==1) q->tailPtr=q->headPtr;
    if(q->headPtr==NULL) q->tailPtr=NULL;
  q->size--;
  free(t);
    return value;
   }
  //  printf("Empty queue");
   return -1;
}

#endif

