#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    int* data;
    int size;
    int capacity;
} Vector;


Vector* vector_create(int capacity) {
    (void) capacity;
    return NULL;
}


void vector_destroy(Vector* v) {
    (void) v;
}


void vector_reserve(Vector* v, int newCapacity) {
    (void) v;
    (void) newCapacity;
}


void vector_push_back(Vector* v, int value) {
    (void) v;
    (void) value;
}


bool vector_pop_back(Vector* v) {
    (void) v;
    return false;
}


bool vector_insert(Vector* v, int index, int value) {
    (void) v;
    (void) index;
    (void) value;
    return false;
}


bool vector_erase(Vector* v, int index) {
    (void) v;
    (void) index;
    return false;
}


int vector_index_of(Vector* v, int value) {
    (void) v;
    (void) value;
    return 0;
}


bool vector_contains(Vector* v, int value) {
    (void) v;
    (void) value;
    return false;
}


int vector_get_size(Vector* v) {
    (void) v;
    return 0;
}


int vector_get_capacity(Vector* v) {
    (void) v;
    return 0;
}


void vector_status(Vector* v) {
    (void) v;
}


void vector_str(Vector* v) {
    (void) v;
}


bool vector_at(Vector* v, int index, int* out_value) {
    (void) v;
    (void) index;
    (void) out_value;
    return false;
}


bool vector_set(Vector* v, int index, int value) {
    (void) v;
    (void) value;
    return false;
}


void vector_clear(Vector* v) {
    (void) v;
}

int main() {
    char line[100];
    Vector* v = vector_create(0);

    while (true) {
        printf("$");
        if (!fgets(line, sizeof(line), stdin)) break;
        line[strcspn(line, "\n")] = 0;
        printf("%s\n", line);

        char* cmd = strtok(line, " ");
        if (!cmd) continue;

        if (strcmp(cmd, "end") == 0) {
            break;
        } else if (strcmp(cmd, "init") == 0) {
            int cap = atoi(strtok(NULL, " "));
            vector_destroy(v);
            v = vector_create(cap);
        } else if (strcmp(cmd, "push") == 0) {
            char* arg;
            while ((arg = strtok(NULL, " ")))
                vector_push_back(v, atoi(arg));
        } else if (strcmp(cmd, "show") == 0) {
            vector_str(v);
        } else if (strcmp(cmd, "status") == 0) {
            vector_status(v);
        } else if (strcmp(cmd, "pop") == 0) {
            if (!vector_pop_back(v))
                printf("vector is empty\n");
        } else if (strcmp(cmd, "insert") == 0) {
            int index = atoi(strtok(NULL, " "));
            int value = atoi(strtok(NULL, " "));
            if (!vector_insert(v, index, value))
                printf("index out of range\n");
        } else if (strcmp(cmd, "erase") == 0) {
            int index = atoi(strtok(NULL, " "));
            if (!vector_erase(v, index))
                printf("index out of range\n");
        } else if (strcmp(cmd, "indexOf") == 0) {
            int value = atoi(strtok(NULL, " "));
            printf("%d\n", vector_index_of(v, value));
        } else if (strcmp(cmd, "contains") == 0) {
            int value = atoi(strtok(NULL, " "));
            printf(vector_contains(v, value) ? "true\n" : "false\n");
        } else if (strcmp(cmd, "clear") == 0) {
            vector_clear(v);
        } else if (strcmp(cmd, "capacity") == 0) {
            printf("%d\n", vector_get_capacity(v));
        } else if (strcmp(cmd, "get") == 0) {
            int index = atoi(strtok(NULL, " "));
            int value;
            if (vector_at(v, index, &value))
                printf("%d\n", value);
            else
                printf("index out of range\n");
        } else if (strcmp(cmd, "set") == 0) {
            int index = atoi(strtok(NULL, " "));
            int value = atoi(strtok(NULL, " "));
            if (!vector_set(v, index, value))
                printf("index out of range\n");
        } else if (strcmp(cmd, "reserve") == 0) {
            int newCap = atoi(strtok(NULL, " "));
            vector_reserve(v, newCap);
        } else {
            printf("comando invalido\n");
        }
    }

    vector_destroy(v);
    return 0;
}
