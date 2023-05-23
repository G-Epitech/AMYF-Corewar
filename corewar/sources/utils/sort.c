/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** sort
*/

static void swap_number(int array[], int j)
{
    int temp = 0;

    if (array[j] > array[j + 1]) {
        temp = array[j];
        array[j] = array[j + 1];
        array[j + 1] = temp;
    }
}

void utils_array_sort(int array[], int size)
{
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++)
            swap_number(array, j);
    }
}
