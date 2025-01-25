#!/usr/bin/python3
'''
module reveal the power of the Min operation function
'''


def minOperations(n):
    '''
    minimum operation function
    '''
    if n <= 1:
        return 0

    n_operation = 0
    fact = 2

    while n > 1:
        while n % fact == 0:
            n_operation += fact
            n //= fact  # rounds the result down to the nearest whole number
        fact += 1

    return n_operation