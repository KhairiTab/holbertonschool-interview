#include "search.h"

/**
 * linear_skip - Searches for a value in a sorted skip list of integers
 *               using an express lane and linear search.
 * @list: Pointer to the head of the skip list to search in
 * @value: The value to search for
 *
 * Return: A pointer to the first node where value is located,
 *         or NULL if the value is not present in list or list is NULL.
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
skiplist_t *current, *express;

if (!list)
return (NULL);

current = list;
express = list->express;

while (express)
{
printf("Value checked at index [%lu] = [%d]\n", express->index, express->n);
if (express->n >= value)
break;
current = express;
express = express->express;
}

if (!express)
{
express = current;
while (express->next)
express = express->next;
}

printf("Value found between indexes [%lu] and [%lu]\n"
, current->index, express->index);

while (current && current->index <= express->index)
{
printf("Value checked at index [%lu] = [%d]\n", current->index, current->n);
if (current->n == value)
return (current);
current = current->next;
}
return (NULL);
}
