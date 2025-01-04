#!/usr/bin/python3
'''
Methode to determine if all the boxes can be opened
'''


def canUnlockAll(boxes):
    '''Function to inlock boxes'''
    unlocked = set([0])
    keys = set(boxes[0])

    # Keep checking until no new keys are added
    while keys:
        # Get a key to check
        current_key = keys.pop()

        if current_key < len(boxes) and current_key not in unlocked:
            # Unlock the box
            unlocked.add(current_key)
            # Add keys from this box to our keys set
            keys.update(boxes[current_key])

    # If we've unlocked all the boxes
    return len(unlocked) == len(boxes)
