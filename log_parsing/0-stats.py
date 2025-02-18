#!/usr/bin/python3
"""a script that reads stdin line by line and computes metrics"""
import sys

if __name__ == "__main__":
    status_code = {
        "200": 0,
        "301": 0,
        "400": 0,
        "401": 0,
        "403": 0,
        "404": 0,
        "405": 0,
        "500": 0,
    }
    numb_lines = 0
    tot_size = 0

    def print_statistics():
        """a function that prints statistics of the log"""
        print(f"File size: {tot_size}")
        for code, count in sorted(status_code.items()):
            if count > 0:
                print(f"{code}: {count}")

    try:
        for line in sys.stdin:
            numb_lines += 1
            words = line.split(" ")
            if len(words) > 2:
                file_size = int(words[-1])
                tot_size += file_size
                code = words[-2]
                if code in status_code:
                    status_code[code] += 1
                if numb_lines % 10 == 0:
                    print_statistics()
    finally:
        print_statistics()
