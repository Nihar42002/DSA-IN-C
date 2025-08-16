#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int queue[100];
int top = -1;
int isEmpty() 
{
    return top == -1;
}

void enqueue(int value) 
{
    queue[++top] = value;
    printf("Enqueued %d to queue\n", value);
}

void dequeue() 
{
    if (isEmpty()) {
        printf("Queue underflow\n");
        return;
    }
    int dequeuedValue = queue[0];
    for (int i = 0; i < top; i++) {
        queue[i] = queue[i + 1]; // Shift elements to the left
    }
    top--; // Decrease the top index
    printf("Dequeued %d from queue\n", dequeuedValue);
}
int peek() 
{
    if (isEmpty()) {
        printf("Queue is empty\n");
        return -1; // Return an invalid value to indicate the queue is empty
    }
    return queue[0];
}
void display() 
{
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements are:\n");
    for (int i = 0; i <= top; i++) {
        printf("%d\n", queue[i]);
    }
}

int main() 
{
   enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
    
    printf("Front element is: %d\n", peek());
    
    dequeue();
    display();
    
    printf("Front element after dequeue is: %d\n", peek());
    
    dequeue();
    dequeue();
    dequeue(); // Attempt to dequeue from an empty queue
    
    return 0;
    
}   