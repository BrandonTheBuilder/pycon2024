#define DATA_LENGTH 10000 

#include <stdio.h>

int data[DATA_LENGTH];

int find_value(int value){
    for (int i=0; i < DATA_LENGTH; i++){
        if (data[i] == value) {
            return i;
        }
    }
    return -1;
}

int load_file(const char* name){
    printf("%s\n", name);
    FILE *fptr = fopen(name, "r");
    if (fptr == NULL) {
        return 1;
    }
    int i = 0;
    for (int v; fscanf(fptr, "%i[\n]", &v) == 1;) {
        if (i < DATA_LENGTH) {
            data[i] = v;
            i++;
        } else {
            break;
        }
    }
    return 0;
}
