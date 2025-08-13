#include<stdio.h>
#include<stdlib.h>

#define MAX 10 

int stack[MAX];
int top = -1;

int Empty()
{
    return top == -1;
}
int full()
    {
        return top == MAX - 1;
    }

void push(int value)
{
    if (full()) {
        printf("Stack overflow\n");
        return;
    }
    stack[++top] = value;
    printf("Pushed %d onto stack\n", value);
}

void pop()
{
    if (Empty()) {
        printf("Stack underflow\n");
        return;
    }
    else{
    int poppedValue = stack[top--];
    printf("Popped %d from stack\n", poppedValue);
    }
}

int peek()
{
    if (Empty()) {
        printf("Stack is empty\n");
        return -1; // Return an invalid value to indicate the stack is empty
    }
    return stack[top];
}

void display()
{
    if (Empty()) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements are:\n");
    for (int i = 0; i <= top; i++) {
        printf("%d\n", stack[i]);
    }
}

void peep() 
{
    if (top < 0) 
    {
        printf("Stack is empty.\n");
    } else 
    {
        printf("Top element: %d\n", stack[top]);
    }
}

// Main function to demonstrate stack operations
int main() {
    push(10);  // Push 10 onto the stack
    push(20);  // Push 20 onto the stack
    push(30);  // Push 30 onto the stack
    display(); // Display current stack: 10 20 30

    pop();     // Pop the top element (30)
    display(); // Display updated stack: 10 20

    printf("Top element: %d\n", peek()); // Peek at the top element (20)

    // Pushing more elements to fill up the stack
    push(40);
    push(50);
    push(60);
    push(70);
    push(80);
    push(90);
    push(100);

    // This push should cause overflow because the stack is full
    push(110); // Expected overflow error
    display(); // Display all current elements

    printf("Top element: %d\n", peek()); // Peek at the top element (100)

    // Another push to show overflow again
    push(89);  // Will again trigger overflow
  

    return 0;  // End of program
}