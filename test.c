#include <stdio.h>
#include <stdlib.h> // For malloc

// Define a structure
struct Person {
    char name[50];
    int age;
};

int main() {
    // Declare a pointer to a Person structure
    struct Person *ptr_person;

    // Dynamically allocate memory for a Person structure
    ptr_person = (struct Person *) malloc(sizeof(struct Person));

    // Check if memory allocation was successful
    if (ptr_person == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Access members using the arrow operator
    // This is equivalent to (*ptr_person).name = "Alice";
    sprintf(ptr_person->name, "Alice");
    ptr_person->age = 30; // This is equivalent to (*ptr_person).age = 30;

    // Print the accessed members
    printf("Name: %s\n", ptr_person->name);
    printf("Age: %d\n", ptr_person->age);

    // Free the dynamically allocated memory
    free(ptr_person);
    ptr_person = NULL; // Good practice to set pointer to NULL after freeing

    return 0;
}