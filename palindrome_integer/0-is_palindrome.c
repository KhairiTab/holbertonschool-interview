#include "palindrome.h"

/**
 * is_palindrome - checks whether or not a given unsigned integer is a palindrome
 * @n: the number to check
 *
 * Return: 1 if n is a palindrome, 0 otherwise
 */
int is_palindrome(unsigned long n)
{
    unsigned long original = n;
    unsigned long reversed = 0;

    /* Reverse the number */
    while (n > 0)
    {
        reversed = reversed * 10 + (n % 10); /* Extract last digit and build reversed number */
        n /= 10; /* Remove last digit */
    }

    /* Compare the original number with the reversed number */
    return (original == reversed);
}