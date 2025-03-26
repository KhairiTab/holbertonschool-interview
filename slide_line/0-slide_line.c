#include "slide_line.h"

// Function prototypes
void shift_left(int *line, size_t size);
void shift_right(int *line, size_t size);
void merge_left(int *line, size_t size);
void merge_right(int *line, size_t size);

/**
 * slide_line - Slides and merges an array of integers to the left or right.
 * @line: Pointer to the array of integers.
 * @size: Number of elements in the array.
 * @direction: Direction to slide (SLIDE_LEFT or SLIDE_RIGHT).
 *
 * Return: 1 upon success, 0 upon failure.
 */
int slide_line(int *line, size_t size, int direction)
{
    if (direction != SLIDE_LEFT && direction != SLIDE_RIGHT)
        return (0); /* Invalid direction */

    /* Step 1: Shift non-zero numbers */
    if (direction == SLIDE_LEFT)
        shift_left(line, size);
    else
        shift_right(line, size);

    /* Step 2: Merge adjacent identical numbers */
    if (direction == SLIDE_LEFT)
        merge_left(line, size);
    else
        merge_right(line, size);

    /* Step 3: Compact the array after merging */
    if (direction == SLIDE_LEFT)
        shift_left(line, size);
    else
        shift_right(line, size);

    return (1); /* Success */
}

/**
 * shift_left - Shifts non-zero numbers to the left.
 * @line: Pointer to the array of integers.
 * @size: Number of elements in the array.
 */
void shift_left(int *line, size_t size)
{
    size_t write_idx = 0, read_idx;

    for (read_idx = 0; read_idx < size; read_idx++)
    {
        if (line[read_idx] != 0)
        {
            line[write_idx] = line[read_idx];
            if (write_idx != read_idx)
                line[read_idx] = 0;
            write_idx++;
        }
    }
}

/**
 * shift_right - Shifts non-zero numbers to the right.
 * @line: Pointer to the array of integers.
 * @size: Number of elements in the array.
 */
void shift_right(int *line, size_t size)
{
    size_t write_idx = size - 1, read_idx;

    for (read_idx = size - 1; read_idx < size; read_idx--)
    {
        if (line[read_idx] != 0)
        {
            line[write_idx] = line[read_idx];
            if (write_idx != read_idx)
                line[read_idx] = 0;
            write_idx--;
        }
    }
}

/**
 * merge_left - Merges adjacent identical numbers to the left.
 * @line: Pointer to the array of integers.
 * @size: Number of elements in the array.
 */
void merge_left(int *line, size_t size)
{
    size_t i;

    for (i = 0; i < size - 1; i++)
    {
        if (line[i] != 0 && line[i] == line[i + 1])
        {
            line[i] *= 2;
            line[i + 1] = 0;
            i++; /* Skip the next number to prevent double merging */
        }
    }
}

/**
 * merge_right - Merges adjacent identical numbers to the right.
 * @line: Pointer to the array of integers.
 * @size: Number of elements in the array.
 */
void merge_right(int *line, size_t size)
{
    size_t i;

    for (i = size - 1; i > 0; i--)
    {
        if (line[i] != 0 && line[i] == line[i - 1])
        {
            line[i] *= 2;
            line[i - 1] = 0;
            i--; /* Skip the previous number to prevent double merging */
        }
    }
}