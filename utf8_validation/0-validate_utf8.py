#!/usr/bin/python3
""" utf8 validation """


def validUTF8(data):
    """
    Determines if a dataset represents valid UTF-8 encoding.

    Args:
    data (list): A list of integers representing bytes (0 <= integer <= 255).

    Returns:
        bool: True if valid UTF-8, False otherwise.
    """
    num_bytes = 0  # Tracks expected continuation bytes

    for byte in data:
        byte &= 0xFF  # Ensure only the least significant 8 bits are used

        if num_bytes == 0:
            # Check the number of bytes in the UTF-8 character
            if (byte >> 5) == 0b110:
                num_bytes = 1
            elif (byte >> 4) == 0b1110:
                num_bytes = 2
            elif (byte >> 3) == 0b11110:
                num_bytes = 3
            elif byte >> 7:
                return False  # Invalid single-byte character
        else:
            # Continuation bytes must start with '10'
            if (byte >> 6) != 0b10:
                return False
            num_bytes -= 1  # Decrement continuation byte count

    return num_bytes == 0  # All characters must be complete
