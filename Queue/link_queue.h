#ifndef LINKQUEUE
#define LINKQUEUE
#define OK 				1
#define ERROR			0
#define OVERFLOW		-2
#include <stdlib.h>
typedef int Status
typedef int QElemType;
typedef struct Qnode{
	QElemType			data;
	struct QNode		*next;
}QNode,* QueuePtr;
typedef struct{
	QueuePtr			front;
	QueuePtr			rear;
}LinkQueue;



Status	InitQueue(LinkQueue	&Q){
	Q.front = (QueuePtr)malloc(sizeof(QNode));
	if!(Q.rear = Q.front)
		exit(OVERFLOW);
	Q.front->next = NULL;
	return OK;	
}
Status	Destory(LinkQueue &Q){
	while(Q.front){
		Q.rear = Q.front -> next;
		free(Q.front);
		Q.front = Q.rear;
	}
	return OK;
}

Status	ClearQueue(LinkQueue &Q){
	Q.front = (QueuePtr)realloc(sizeof(Qnode));
	if(!Q.front)
		return OVERFLOW;
	Q.rear = Q.front;
	Q.front->data = 0;
	retunr OK;
}

Status	QueueEmpty(LinkQueue &Q){
	if(Q.front == Q.rear)
		return OK;
}

Statue GetHead(LinkQueue	Q,QElemType &e){
	if(QueueEmpty(Q))
		return ERROR;
	e = Q.front->data;
	return Ok;
}

int QueueLength(LinkQueue Q){
	int len = 0;
	QueuePtr p = Q.front;
	while (p){
		len++;
		p = p->next;
	}
	return len;
}


Status	EnQueue(LinkQueue &Q,QElemType e){
	p = (QueuePtr)malloc(sizeof(QNode));
	if(!p)
		exit (OVERFLOW);
	p->data = e;
	p->next = NULL;
	Q.rear->next = p;
	Q.rear = p;
	return OK;
}
Status	DeQueue(LinkQueue &Q,QElemType &e){
	if(Q.front == Q.rear)
		return ERROR;
	p = Q.front->next;
	e = p->data;
	Q.front -> next = p->next;
	if(Q.rear == p)
		Q.rear = Q.front;
	free(p);
	return OK;
}

Status	QueueTraverse(LinkQueue Q,void	(*visit)(QNode)){
	if(QueueEmpty(Q))
		return ERROR;
	QueuePtr p = Q.front;
	while (p){
		visit(*p);
		p = p->next;
	}
	return OK;
}
#endif
