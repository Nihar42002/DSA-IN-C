#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char infix[100] , postfix[100];
char stack[100];
int top = -1;


int  character( char c)
{
    if (c == '+' || c == '-') 
    {
        return 1;
    } 
    else if (c == '*' || c == '/') 
    {
        return 2;
    } 
    else if (c == '^') 
    {
        return 3;
    }
    return 0; // Not an operator
}

int isEmpty() 
{
    return top == -1;
}

void push(char value) 
{
    stack[++top] = value;
}

char pop() 
{
    if (!isEmpty()) 
    {
        stack[top--];
    }
    return -1; // Return an invalid value to indicate the stack is empty
}

char peek() 
{
    if (!isEmpty()) 
    {
        return stack[top];
    }
    return -1; // Return an invalid value to indicate the stack is empty
}

void convert(char infix [], char postfix[])
{
    int j = 0 , i = 0;
    char c;
    

    while(infix[i]!= '\0')
    
    {
         c = infix[i];

         
    if (c == ' ') {   // Skip whitespace
        i++;
        continue;
    }
       
       if ( c >= 'a' && c <= 'z') 
        {
            postfix[j++] = c; // Add operand to postfix
        } 
        else if (c == '(') 
        {
            push(c); // Push '(' onto stack
        } 
        else if (c == ')') 
        {
            while (!isEmpty() && peek() != '(') 
            {
                postfix[j++]  =  peek();
                pop(); // Pop until '('
            }
            
            pop(); // Pop the '('
        } 
        else 
        {
            while (!isEmpty() && character(peek()) >= character(c)) // Check precedence
            {
                postfix[j++] = peek(); // Pop operators with higher or equal precedence
                pop();
            }
            push(c); // Push current operator onto stack
        }
        i++;
    }


    while (!isEmpty()) 
    {
        postfix[j++] = peek(); // Pop remaining operators
        pop();
    }
    postfix[j] = '\0'; // Null-terminate the postfix expression
}


int main() 
{

    printf("Enter the infix expression :\n");
    fgets((char *)infix, sizeof(infix), stdin); // Read input
    infix[strcspn((char *)infix, "\n")] = 0; // Remove newline character

    convert(infix, postfix); // Convert infix to postfix

    printf("Postfix expression: ");
    for (int i = 0; postfix[i] != '\0'; i++) 
    {
        printf("%c", postfix[i]); // Print the postfix expression
    }
    printf("\n");

    return 0;
}