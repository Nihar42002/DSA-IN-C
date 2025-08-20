#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void hanoi_tower(int n , char source , char auxiliary , char destinattion) // Function to solve Tower of Hanoi
{
  if (n==1) 
   {
    printf("move disk 1 from %c to %c\n", source, destinattion);
    return; // Base case: if there's only one disk, move it directly from source to destination
   }
    else{
    hanoi_tower(n - 1, source, destinattion, auxiliary); // Move n-1 disks from source to auxiliary
    printf("move disk %d from %c to %c run\n", n, source, destinattion); // Move nth disk from source to destination
    hanoi_tower(n - 1, auxiliary, source, destinattion); // Move n-1 disks from auxiliary to destination
    }

}
int main()
{
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n); // Read the number of disks
    hanoi_tower(n, 'A', 'B', 'C'); // Call the function with source A, auxiliary B, and destination C
    printf("Tower of Hanoi solved successfully!\n");
  
    int count = pow(2, n) - 1; // Calculate the number of moves
    printf("Total moves required: %d\n", count); // Print the total number of moves
    return 0; // Return success
}