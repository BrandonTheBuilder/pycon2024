import time

N = 1000


def main():
    start = time.time()
    for i in range(N):
        __import__(f"examples.too_many_extensions.extension_{i}")
    end = time.time()
    print(f"imported {N} modules in {end - start}s")
