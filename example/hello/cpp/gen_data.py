N = 2000000
def main():
    with open("data.cpp", "w") as f:
        f.write("#include <utility>\n")
        f.write("#include <string>\n")
        f.write("#include <unordered_map>\n")
        f.write("std::pair<std::string, long> values[] = {\n")
        for n in range(N):
            f.write(f"{{\"key_{n}\", {n}}},\n")
        f.write(f"{{\"key_{N}\", {N}}},\n")
        f.write("};\n")
        f.write("std::unordered_map<std::string, long> messages(std::begin(values), std::end(values));")

if __name__ == "__main__":
    main()
