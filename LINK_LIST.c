#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node {
    int data;
    struct Node* next;
};

int main()
{
    struct Node *head = NULL;
    struct Node *second = NULL; 
    struct Node *third = NULL;
    // Allocate nodes in the heap
    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));

    if (head == NULL || second == NULL || third == NULL) {
        printf("Memory allocation failed!\n");
        return 1; // Exit if memory allocation fails
    }

    head->data = 1; // Assign data in first node
    head->next = second; // Link first node with the second node

    second->data = 2; // Assign data to second node
    second->next = third; // Link second node with the third node

    third->data = 3; // Assign data to third node
    third->next = NULL; // Terminate the list at the third node
    printf("Linked List created successfully:\n");


    struct Node* current = head;
    while (current != NULL) {
        printf("Data: %d\n", current->data);
        current = current->next; // Move to the next node
    }
   
}