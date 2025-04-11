#include "menger.h"
/**
 * is_blank - Determine if the cell should be blank in the Menger sponge
 * @x: The x-coordinate of the cell
 * @y: The y-coordinate of the cell
 *
 * Return: 1 if the cell should be blank, 0 otherwise
 */
int is_blank(int x, int y)
{
while (x > 0 && y > 0)
{
if (x % 3 == 1 && y % 3 == 1)
return (1);
x /= 3;
y /= 3;
}
return (0);
}

/**
 * menger - Draws a 2D Menger Sponge of a given level
 * @level: The level of the Menger Sponge to draw
 */
void menger(int level)
{
int size;
int x, y;
if (level < 0)
return;
size = pow(3, level);
for (y = 0; y < size; y++)
{
for (x = 0; x < size; x++)
{
if (is_blank(x, y))
printf(" ");
else
printf("#");
}
printf("\n");
}
}
