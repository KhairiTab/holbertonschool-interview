#!/usr/bin/python3
"""
Reads stdin line by line and computes metrics.
"""
import sys
import signal

STATUS_CODES = [200, 301, 400, 401, 403, 404, 405, 500]

total_size = 0
line_count = 0
status_count = {code: 0 for code in STATUS_CODES}


def print_stats():
    """Print statistics"""
    print("File size: {}".format(total_size))
    for code in sorted(status_count.keys()):
        if status_count[code] > 0:
            print("{}: {}".format(code, status_count[code]))


def signal_handler(sig, frame):
    """Handle CTRL + C"""
    print_stats()
    sys.exit(0)


signal.signal(signal.SIGINT, signal_handler)


if __name__ == "__main__":
    for line in sys.stdin:
        try:
            parts = line.split()

            status = int(parts[-2])
            size = int(parts[-1])

            total_size += size

            if status in status_count:
                status_count[status] += 1

            line_count += 1

            if line_count % 10 == 0:
                print_stats()

        except (IndexError, ValueError):
            continue
