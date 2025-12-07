#include "Queue.h"

#include <cstdlib>
#include <cstring>
#include <cfloat>
#include <cstdio>




void initRow(Row* r)
{

	if (r != NULL)
	{
		r->data = 0.00f;
		r->average = 0.00f;
		r->maxValue = -FLT_MAX;
		r->minValue = FLT_MAX;
		r->sum = 0.00f;

	}

}




void operations(Row* r, Queue* q, float value)
{
	if (q->count == MAX_SIZE)
	{
		r->sum -= getValueFromQueue(q);
	}
	pushToQueue(q, value);
	r->data = value;
	r->sum += value;
	r->average = (float)(r->sum / q->count);
	r->maxValue = getMax(q);
	r->minValue = getMin(q);

}


float getMax(Queue* q) 
{
	float maxVal = -FLT_MAX;
	for (size_t i = 0; i < q->count; i++)
	{
		int idx = (q->front + i) % MAX_SIZE;
		if (q->values[idx] > maxVal)
			maxVal = q->values[idx];
	}
	return maxVal;
}

float getMin(Queue* q) 
{
	float minVal = FLT_MAX;
	for (size_t i = 0; i < q->count; i++)
	{
		int idx = (q->front + i) % MAX_SIZE;
		if (q->values[idx] < minVal)
			minVal = q->values[idx];
	}
	return minVal;
}


void initQueue(Queue* q)
{
	q->rear = 0;
	q->front = 0;
	q->count = 0;
}

bool isEmpty(Queue* q)
{
	return (q->count == 0);
}

bool isFull(Queue* q)
{
	return (q->count == MAX_SIZE);
}

void pushToQueue(Queue* q, float value)
{
	if (q != NULL)
	{
		if (!isFull(q))
		{

			q->values[q->rear] = value;
			q->rear = (q->rear + 1) % MAX_SIZE;
			q->count++;

		}
		else
		{
			q->values[q->rear] = value;
			q->rear = (q->rear + 1) % MAX_SIZE;
			q->front = (q->front + 1) % MAX_SIZE;
		}
	}

	else
	{
		printf("Error.\n");
		return;
	}
}

void resetQueue(Queue* q)
{
	q->rear = 0;
	q->front = 0;
	q->count = 0;
}

float getValueFromQueue(Queue* q)
{
	if (!isEmpty(q))
	{
		float val = q->values[q->front];
		q->front = (q->front + 1) % MAX_SIZE;
		q->count--;
		return val;
	}
	return 0.0f;
}