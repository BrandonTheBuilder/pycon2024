import random
import sys

N = 100000

def main():
    with open(sys.argv[1], "w") as f:
        for _ in range(N):
            f.write(f"{random.randint(0, 10000)}\n")

if __name__ == "__main__":
    main()
