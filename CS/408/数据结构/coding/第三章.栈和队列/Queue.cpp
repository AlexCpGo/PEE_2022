/* Queue */
// Only move rear backward a unit of the queue when data into queue, and only move front backward a unit when data out of queue
// Sequential Queue
#define MaxSize 100
typedef struct
{
	int data[MaxSize];
	int front;  // points to the empty before the data in queue 
	int rear;  // points to the last data in queue
} SqQueue;

// Linked Queue 1.QNode
typedef struct QNode
{
	int data;
	struct QNode *next;
} QNode;
// Linked Queue 2.LiQueue
typedef struct
{
	QNode *front;
	QNode *rear; 
} LiQueue;



// Circular queue
qu.rear = qu.front; // empty circular queue
(qu.rear + 1) % MaxSize = qu.front // full circular queue

// Queue in
qu.rear = (qu.rear + 1) % MaxSize;
qu.data[qu.rear] = x;
// Queue out
qu.front = (qu.front + 1) % MaxSize;
x = qu.data[qu.front]

void intiSqQueue(SqQueue &qu)
{
	qu.front = qu.rear = 0;
}

int isSqQueueEmpty(SqQueue qu)
{
	if(qu.front == qu.rear)
		return 1;
	else
		return 0;
}

int enSqQueue(SqQueue &qu, int x)
{
	if ((qu.rear+1)%MaxSize == qu.front)
		return 0;
	else
		qu.rear = (qu.rear + 1) % MaxSize;
		qu.data[qu.rear] = x;
		return 1;
}

int deSqQueue(SqQueue &qu, int &x)
{
	if (qu.rear == qu.front)
		return 0;
	else
		qu.front = (qu.front + 1) % MaxSize;
		x = qu.data[qu.front];
		return 1;
}



// Linked Queue
// Empty lqu
lqu->rear = NULL || lqu->front = NULL;
// Full lqu: Do not exist

// enLQueue
lqu->rear->next = p;
lqu->rear = p;

// deLQueue 
p = lqu->front;
x = p->data;
lqu->front = p->next;
free(p);

void initLiQueue(LiQueue *&lqu)
{
	lqu = (LiQueue*)malloc(sizeof(LiQueue));
	lqu->front = lqu->rear = NULL;
}

void isLiQueueEmpty(LiQueue *&lqu)
{
	if (lqu->rear = NULL || lqu->front = NULL){
		return 1;
	}
	else
		return 0;
}

void enLiQueue(LiQueue *lqu, int x)
{
	QNode *p;
	p = (QNode*)malloc(sizeof(QNode));
	P->data = x;
	p->next = NULL;
	if (lqu->rear == NULL) // Empty LQueue: move lqu->front too!!!
		lqu->front = lqu->rear = p; 

	// Not empty LQueue: Do not move lqu->front !!!
	else { 
		lqu->rear->next = p;
		lqu->rear = p;
	}
}

int deLiQueue(LiQueue &lqu, int &x)
{
	QNode *p;
	if (lqu->rear == NULL)
		return 0;
	else
		p = lqu->front;

	if  (lqu->front == lqu->rear) //If only one Node in the Queue: Make the special operation on the rear
		lqu->front = lqu->rear = NULL;
	else
		lqu->front = lqu->front->next;

	x=p->data;
	free(p)
	return 1;
}

