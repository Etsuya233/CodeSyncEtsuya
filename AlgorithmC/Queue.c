#include <stdio.h>
#include <stdlib.h>

#define QueueDataType int
#define MaxQueueSize 20

typedef struct Queue{
    QueueDataType data[MaxQueueSize];
    int front, rear, cnt;
} *queue, queueNode;

queue CreateQueue(){
    queue ret = (queue)malloc(sizeof(queueNode));
    ret->cnt = 0;
    ret->front = 0;
    ret->rear = 0;
}

void QueueAppend(queue queue, QueueDataType data){
    if(queue->front == queue->rear && queue->cnt){
        printf("E: The queue is full!\n");
    }
    queue->data[queue->rear] = data;
    queue->rear = (queue->rear + 1) % MaxQueueSize;
    queue->cnt++;
}

QueueDataType QueuePop(queue queue){
    if(queue->cnt == 0){
        printf("E: The queue is empty!");
        return;
    }
    QueueDataType ret = queue->data[queue->front];
    queue->front = (queue->front + 1) % MaxQueueSize;
    queue->cnt--;
    return ret;
}

int QueueIsEmpty(queue queue){
    if(queue->cnt == 0) return 1;
    return 0;
}

QueueDataType QueueGetFront(queue queue){
    if(queue->cnt == 0){
        printf("E: The queue is empty!");
        return 0;
    }
    return queue->data[queue->front];
}

QueueDataType QueueGetTail(queue queue){
    if(queue->cnt == 0){
        printf("E: The queue is empty!");
        return 0;
    }
    return queue->data[queue->rear];
}