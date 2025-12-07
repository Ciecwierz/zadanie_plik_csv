#ifndef  QUEUE_H
#define QUEUE_H
#define MAX_SIZE 500
#endif 





typedef struct
{
	float data;
	float average;
	float maxValue;
	float minValue;
	double sum;

}Row;

typedef struct
{
	float values[MAX_SIZE];
	int front;
	int rear;
	size_t count;
}Queue;


void initRow(Row* r);


void operations(Row* r, Queue* q, float value);


float getMax(Queue* q);

float getMin(Queue* q);


void initQueue(Queue* q);


bool isEmpty(Queue* q);


bool isFull(Queue* q);


void pushToQueue(Queue* q, float value);


void resetQueue(Queue* q);


float getValueFromQueue(Queue* q);
