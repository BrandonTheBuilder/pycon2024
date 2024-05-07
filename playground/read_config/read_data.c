extern int load_file(char* name);
extern int find_value(int value);

int main(int argc, char* argv[]) {
    char* filename = argv[1];
    int res = load_file(filename);
    if (res != 0) {
        return res;
    }
    int val = find_value(7);
    printf("%i\n", val);
    return 0;
}
