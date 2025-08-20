#include<stdio.h>
#include<stdlib.h>

void bubble_sorting()
{
    int a[5];

    printf("Enter 5 numbers to sort using bubble sort:\n");
    for(int i = 0; i < 5; i++) {   
        printf("Enter number %d: ", i + 1);
        scanf("%d", &a[i]);
    }

    // Bubble sort algorithm

    for(int i =0; i < 5 - 1; i++)
    {
        for(int j = 0 ; j< 5 ; j++)
        {
            if(a[j] > a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    printf("Sorted array using bubble sort:\n");
    for(int i = 0; i < 5; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main()
{
    bubble_sorting(); // Call the bubble sort function
    return 0;
} 

