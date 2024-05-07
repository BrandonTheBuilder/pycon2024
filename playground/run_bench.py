import subprocess

TARGETS_PATH = "examples/too_many_extensions/BUCK"

N = 8000
START = 0
STEP = 50

def update_targets(n):
    args = [
        "sed",
        "-i",
        f"s/gen_targets(.*)/gen_targets({n})/",
        TARGETS_PATH,
    ]
    subprocess.run(args)

def run_buck(n):
    args = [
        "buck2",
        "run",
        "examples/too_many_extensions:import_test",
        "--",
        f"{n}",
        "short_import_stats.csv",
    ]
    subprocess.run(args)
    
def main():
    for n in range(START, N + 1, STEP):
        update_targets(n)
        run_buck(n)

if __name__ == "__main__":
    main()
        
        
