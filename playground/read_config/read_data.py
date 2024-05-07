import sys
from read_config.read_data_extension import find_value_c, load_file_c

data = []

def find_value(value):
    global data
    try:
        return data.index(value)
    except ValueError:
        return -1

def load_file(name):
    global data
    with open(name, "r") as f:
        data = [int(x) for x in f.readlines()]

def main():
    filename = sys.argv[1]
    load_file_c(filename)
    print(find_value_c(8496))
