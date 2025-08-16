#include<stdio.h>
#include<stdlib.h>


int queue[4];
int rear = -1 , front = -1;
int size = 4;

int isEmpty() 
{
     return(front == -1 && rear == -1) ;
        
}

int isFull() {
    return (front == (rear + 1) % size); // Check if queue is full
}

void enqueue(int value) 
{
    if(isFull()) {
        printf("Queue overflow\n");
        return;
    }
    if (isEmpty()) {
        front = rear = 0; // Initialize front if queue was empty
    }
    else {
        rear = (rear + 1) % size; // Circular increment
    }
    queue[rear] = value; // Add value to the rear of the queue
    printf("Enqueued %d to queue\n", value);
   
}

void dequeue()
{
    if (isEmpty())
    {
        printf("Queue underflow\n");
        return;
    }
    
    int dequeuedValue = queue[front];
   if (front == rear) {
        front = rear = -1; // Reset queue if it becomes empty
    } else {
        front = (front + 1) % size; // Circular increment
    }
    printf("Dequeued %d from queue\n", dequeuedValue);
}

int peek() 
{
    if (isEmpty()) {
        printf("Queue is empty\n");
        return -1; // Return an invalid value to indicate the queue is empty
    }
    return queue[front];
}


void display() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements are: ");
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear) break;
        i = (i + 1) % size;
    }
    printf("\n");
}
int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50); 
    

    display();

    printf("Front element: %d\n", peek());

    dequeue();
    dequeue();

    display();

    enqueue(60);
    enqueue(70);   

    display();

    return 0;
}
