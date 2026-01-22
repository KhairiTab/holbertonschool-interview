#!/usr/bin/python3
"""
Task - Script that reads stdin line by line and computes metrics
"""
import sys


def parse_line(line, status_codes):
    """Read, parse and grab data"""
    try:
        parsed_line = line.split()
        status_code = parsed_line[-2]

        if status_code in status_codes:
            status_codes[status_code] += 1

        return int(parsed_line[-1])
    except (IndexError, ValueError):
        return 0


def print_stats(file_size, status_codes):
    """Print stats in ascending order"""
    print("File size: {}".format(file_size))
    for key in sorted(status_codes.keys()):
        if status_codes[key] > 0:
            print("{}: {}".format(key, status_codes[key]))


if __name__ == "__main__":
    status_codes = {
        "200": 0,
        "301": 0,
        "400": 0,
        "401": 0,
        "403": 0,
        "404": 0,
        "405": 0,
        "500": 0
    }

    count = 0
    file_size = 0

    try:
        for line in sys.stdin:
            file_size += parse_line(line, status_codes)
            count += 1

            if count % 10 == 0:
                print_stats(file_size, status_codes)

    except KeyboardInterrupt:
        print_stats(file_size, status_codes)
        raise

    print_stats(file_size, status_codes)
