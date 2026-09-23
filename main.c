#include <stdio.h>
#include <stdlib.h>
#include "array.h"

void output_array(Array *a);
void shift_array(Array *a);
Array *average_adjacent(Array *a);


int main(int argc, char *argv[])
{
    //main code 
if (argc != 2)
    {
//Prompt the user to enter an array size 
        printf("Please enter the array size.\n");
        return 1;
    }

    int size = atoi(argv[1]);

    Array *array = malloc(sizeof(Array));
    array->size = size;
    array->data = malloc(size * sizeof(double));

    for (int i = 0; i < size; i++)
    {
        array->data[i] = i + 1;
    }

    printf("Original array:\n");
    output_array(array);

    shift_array(array);

    printf("Shifted array:\n");
    output_array(array);

    Array *average = average_adjacent(array);

    printf("Average array:\n");
    output_array(average);

    free(array->data);
    free(array);

    free(average->data);
    free(average);

    return 0;
}

void output_array(Array *a)
{
    // code
 for (int i = 0; i < a->size; i++)
    {
        printf("%.1f ", a->data[i]);
    }

    printf("\n");
}

void shift_array(Array *a)
{
    // code

double first = a->data[0];

    for (int i = 0; i < a->size - 1; i++)
    {
        a->data[i] = a->data[i + 1];
    
}
    a->data[a->size - 1] = first;
}

Array *average_adjacent(Array *a)
{
    // code
Array *average = malloc(sizeof(Array));

    average->size = a->size / 2;
    average->data = malloc(average->size * sizeof(double));

    for (int i = 0; i < average->size; i++)
    {
        average->data[i] =
            (a->data[2 * i] + a->data[2 * i + 1]) / 2.0;
    }

    return average;
}

