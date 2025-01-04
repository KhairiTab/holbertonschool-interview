def canUnlockAll(boxes):
    """
    
    Args:
        boxes (list of list): List of boxes, each containing a list of keys.
    
    Returns:
        bool: True if all boxes can be unlocked, False otherwise.
    """
    unlocked = set([0])
    keys = set(boxes[0])

    # unlocking while there are keys available
    while keys:
        current_key = keys.pop()
        
        # Only process valid keys that lead to locked boxes
        if current_key < len(boxes) and current_key not in unlocked:
            # Unlock the box and add its keys
            unlocked.add(current_key)
            keys.update(boxes[current_key])

    # Return True if the number of unlocked boxes equals the total number of boxes
    return len(unlocked) == len(boxes)

