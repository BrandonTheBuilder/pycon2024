import time
import sys
import os

MEM_DATA = {"VmPeak", "VmSize", "VmLck", "VmHWM", "VmRSS", "VmData", "VmStk", "VmExe", "VmLib", "VmPTE"}

def main():
    N = int(sys.argv[1])
    FILE = sys.argv[2]
    start = time.time()
    for i in range(N):
        __import__(f"examples.too_many_extensions.extension_{i}")
    end = time.time()
    data = [str(N), str(end - start)]
    pid = os.getpid()
    with open(f"/proc/{pid}/status", "r") as status:
        for line in status.readlines():
            name, value = line.split(":")
            if name in MEM_DATA:
                value.replace
                data.append(value.strip().replace(" kB", ""))

    with open(FILE, "a") as fout:
        print(",".join(data), file = fout)
