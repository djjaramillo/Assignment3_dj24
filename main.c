#include <stdio.h>
#include <stdlib.h>
#include "array.h"

//Function declarations 
void output_array(Array *a);
void shift_array(Array *a);
Array *average_adjacent(Array *a);

//Main function
int main(int argc, char *argv[])
{
    //main code
if (argc != 2)
    {
       //Prompt the user to enter an array size
       printf("Please enter the array size.\n");
        return 1;
    }
    //To convert the command line argument into an integer
    int size = atoi(argv[1]);

    Array *array = malloc(sizeof(Array));
    array->size = size;
    array->data = malloc(size * sizeof(double));

    //Fill the array with values based on the input
    for (int i = 0; i < size; i++)
    {
        array->data[i] = i + 1;
    }
    //Print the original array
    printf("Original array:\n");
    output_array(array);

    //Shift the values to the left
    shift_array(array);

    //print out the shifted array
    //using \n to keep everything organized
    printf("Shifted array:\n");
    output_array(array);

    //Create a new array that includes the averages
    Array *average = average_adjacent(array);

    //Print out the average array
    printf("Average array:\n");
    output_array(average);

    //Per lab requirments. need to free up memory
    free(array->data);
    free(array);

    free(average->data);
    free(average);

    return 0;
}

//Prints out the values in the array
void output_array(Array *a)
{
 // code
 for (int i = 0; i < a->size; i++)
    {
        printf("%.1f ", a->data[i]);
    }

    printf("\n");
}

//prints out the array
void shift_array(Array *a)
{
    // code

double first = a->data[0];

    for (int i = 0; i < a->size - 1; i++)
    {
        a->data[i] = a->data[i + 1];

}
    //move the value of the original to the end
    a->data[a->size - 1] = first;
}
//This creates a new array while using the averages from the neighboring values
Array *average_adjacent(Array *a)
{
    //creates memory for the new array
    Array *average = malloc(sizeof(Array));

    average->size = a->size / 2;
    average->data = malloc(average->size * sizeof(double));

    //Average each pair of the values
    for (int i = 0; i < average->size; i++)
    {
        average->data[i] =
            (a->data[2 * i] + a->data[2 * i + 1]) / 2.0;
    }
//return the new averaged array
    return average;
}

