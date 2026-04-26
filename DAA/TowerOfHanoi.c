#include <stdio.h> 

/**
 * Function to solve Tower of Hanoi problem
 * @param diskNumber: Number of disks to move
 * @param source: Starting rod
 * @param destination: Target rod
 * @param auxiliary: Intermediate rod
 */
void towerOfHanoi(int diskNumber, char source, char destination, char auxiliary) 
{
    /* Base Condition: If only one disk remains, move it directly */
    if (diskNumber == 1) { 
        printf("Move disk 1 from %c to %c\n", source, destination); 
        return; 
    } 

    /* Step 1: Move (n-1) disks from source rod to auxiliary rod */
    towerOfHanoi(diskNumber - 1, source, auxiliary, destination); 

    /* Step 2: Move the largest disk (nth disk) from source rod to destination rod */
    printf("Move disk %d from %c to %c\n", diskNumber, source, destination); 

    /* Step 3: Move (n-1) disks from auxiliary rod to destination rod */
    towerOfHanoi(diskNumber - 1, auxiliary, destination, source); 
} 

int main() { 
    int n; 

    /* Prompt user to enter number of disks */
    printf("Enter number of disks: "); 

    /* Input validation: must be a positive integer */
    if (scanf("%d", &n) != 1 || n <= 0) { 
        printf("Please enter a valid positive integer.\n"); 
        return 1; 
    } 

    /* Display the sequence of moves required */
    printf("\nRequired moves:\n"); 
    towerOfHanoi(n, 'S', 'D', 'A');  // S = Source, D = Destination, A = Auxiliary

    /* End of program */
    return 0; 
}
