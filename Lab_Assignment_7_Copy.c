/*
* Name: Joshua Paz
* Date: 03/07/2024
* Lab Section: 27
*/

#include <stdio.h>

//Macros
#define ARRAY_SIZE 9

//Prototypes
int bubbleSort(int array[], int n, int swapped[9][2]);
int selectionSort(int array[], int n, int swapped[9][2]);

int main ()
{
    //Variables
    int array1[ARRAY_SIZE] ={97, 16, 45, 63, 13, 22, 7, 58, 72};
    int array2[ARRAY_SIZE] = {90, 80, 70, 60, 50, 40, 30, 20, 10};

    int swap1[ARRAY_SIZE][2] = {{97,0}, {16,0}, {45,0}, {22,0}, {7,0}, {58,0}, {72,0}, {20,0}, {72,0}};
    int swap2[ARRAY_SIZE][2] = {{90,0}, {80,0}, {70,0}, {60,0}, {50,0}, {40,0}, {30,0}, {20,0}, {10,0}};

    int totalBubbleSwaps = 0;
    int totalSelectionSwaps = 0;
    
    //Bubble Sort
    //Array1
    printf("array1:\n");
    totalBubbleSwaps = bubbleSort(array1, ARRAY_SIZE, swap1);
    for(int i = 0; i < ARRAY_SIZE; i++){
        
        printf("%d: # of times %d is swapped\n", swap1[i][0], swap1[i][1]);
    }
    printf("Total number of swaps: %d\n", totalBubbleSwaps);

    //Array2
    printf("\narray2:\n");
    totalBubbleSwaps = bubbleSort(array2, ARRAY_SIZE, swap2);

    for(int i = 0; i < ARRAY_SIZE; i++){
        printf("%d: # of times %d is swapped\n", swap2[i][0], swap2[i][1]);
    }
    printf("Total number of swaps: %d\n", totalSelectionSwaps);


    //Selection Sort
    printf("\narray1:\n");
    totalSelectionSwaps = selectionSort(array1, ARRAY_SIZE, swap1);

    for(int i = 0; i < ARRAY_SIZE; i++){
        printf("%d: # of times %d is swapped\n", swap1[i][0], swap1[i][1]);
    }
    printf("Total number of swaps: %d\n", totalSelectionSwaps);

    printf("\narray2:\n");
    totalSelectionSwaps = selectionSort(array2, ARRAY_SIZE, swap2);

    for(int i = 0; i < ARRAY_SIZE; i++){
        printf("%d: # of times %d is swapped\n", swap2[i][0], swap2[i][1]);
    }
    printf("Total number of swaps: %d\n", totalSelectionSwaps);

    return 0;
}

int bubbleSort(int array[], int n, int swapped[9][2]){
    int totalSwaps = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n - 1; j++){  
            //Swap
            if(array[j] >  array[j + 1]){

                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                //swapped[i][1]++;
                swapped[j][1]++;
                swapped[j+1][1]++;
                totalSwaps++;
            }
        }
    }
    return totalSwaps;
}

int selectionSort(int array[], int n, int swapped[9][2]){
    int totalSwaps = 0;
    
    for (int i = 0; i < n - 1; i++) 
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (array[j] < array[minIndex])
            {
                minIndex = j;
            }
        }
        // Swap
        int temp = array[i];
        array[i] = array[minIndex];
        array[minIndex] = temp;
        swapped[i][1]++;
        totalSwaps++;
    }
    
    return totalSwaps;
}

