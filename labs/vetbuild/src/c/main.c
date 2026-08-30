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
    // @UNC
    // (void) capacity;
    // return NULL;
    // @DROP
    Vector* v = (Vector*) malloc(sizeof(Vector));
    v->data = (int*) malloc(sizeof(int) * capacity);
    v->size = 0;
    v->capacity = capacity;
    return v;
}


void vector_destroy(Vector* v) {
    // @UNC
    // (void) v;
    // @DROP
    free(v->data);
    free(v);
}


void vector_reserve(Vector* v, int newCapacity) {
    // @UNC
    // (void) v;
    // (void) newCapacity;
    // @DROP
    if (newCapacity > v->capacity) {
        int* newData = (int*) malloc(sizeof(int) * newCapacity);
        for (int i = 0; i < v->size; i++)
            newData[i] = v->data[i];
        free(v->data);
        v->data = newData;
        v->capacity = newCapacity;
    }
}


void vector_push_back(Vector* v, int value) {
    // @UNC
    // (void) v;
    // (void) value;
    // @DROP
    if (v->size == v->capacity)
        vector_reserve(v, v->capacity == 0 ? 1 : v->capacity * 2);
    v->data[v->size++] = value;
}


bool vector_pop_back(Vector* v) {
    // @UNC
    // (void) v;
    // return false;
    // @DROP
    if (v->size == 0)
        return false;
    v->data[v->size - 1] = 0;
    v->size--;
    return true;
}


bool vector_insert(Vector* v, int index, int value) {
    // @UNC
    // (void) v;
    // (void) index;
    // (void) value;
    // return false;
    // @DROP
    if (index < 0 || index > v->size)
        return false;
    if (v->size == v->capacity)
        vector_reserve(v, v->capacity == 0 ? 1 : v->capacity * 2);
    for (int i = v->size; i > index; i--)
        v->data[i] = v->data[i - 1];
    v->data[index] = value;
    v->size++;
    return true;
}


bool vector_erase(Vector* v, int index) {
    // @UNC
    // (void) v;
    // (void) index;
    // return false;
    // @DROP
    if (index < 0 || index >= v->size)
        return false;
    for (int i = index; i < v->size - 1; i++)
        v->data[i] = v->data[i + 1];
    v->size--;
    return true;
}


int vector_index_of(Vector* v, int value) {
    // @UNC
    // (void) v;
    // (void) value;
    // return 0;
    // @DROP
    for (int i = 0; i < v->size; i++)
        if (v->data[i] == value)
            return i;
    return -1;
}


bool vector_contains(Vector* v, int value) {
    // @UNC
    // (void) v;
    // (void) value;
    // return false;
    // @DROP
    return vector_index_of(v, value) != -1;
}


int vector_get_size(Vector* v) {
    // @UNC
    // (void) v;
    // return 0;
    // @DROP
    return v->size;
}


int vector_get_capacity(Vector* v) {
    // @UNC
    // (void) v;
    // return 0;
    // @DROP
    return v->capacity;
}


void vector_status(Vector* v) {
    // @UNC
    // (void) v;
    // @DROP
    printf("size:%d capacity:%d\n", v->size, v->capacity);
}


void vector_str(Vector* v) {
    // @UNC
    // (void) v;
    // @DROP
    printf("[");
    for (int i = 0; i < v->size; i++) {
        printf("%d", v->data[i]);
        if (i < v->size - 1) printf(", ");
    }
    printf("]\n");
}


bool vector_at(Vector* v, int index, int* out_value) {
    // @UNC
    // (void) v;
    // (void) index;
    // (void) out_value;
    // return false;
    // @DROP
    if (index < 0 || index >= v->size)
        return false;
    *out_value = v->data[index];
    return true;
}


bool vector_set(Vector* v, int index, int value) {
    // @UNC
    // (void) v;
    // (void) value;
    // return false;
    // @DROP
    if (index < 0 || index >= v->size)
        return false;
    v->data[index] = value;
    return true;
}


void vector_clear(Vector* v) {
    // @UNC
    // (void) v;
    // @DROP
    v->size = 0;
}

Vector vector_slice(Vector* v, int start, int end) {
    // @UNC
    // (void) v;
    // (void) start;
    // (void) end;
    // return (Vector){0};
    // @DROP
    start = start % v->size;
    end = end % v->size;
    if (start < 0) 
        start += v->size;
    if (end <  0)
        end += v->size;
    Vector slice;
    slice.data = v->data + start;
    slice.size = end - start;
    slice.capacity = slice.size;
    return slice;
}

int main() {
    char line[100];
    Vector* v = vector_create(0);

    while (true) {
        printf("$");
        if (!fgets(line, sizeof(line), stdin)) { 
            break;
        }
        line[strcspn(line, "\n")] = 0;
        printf("%s\n", line);

        char* cmd = strtok(line, " ");
        if (!cmd) {
            continue;
        }
        if (strcmp(cmd, "end") == 0) {
            break;
        } else if (strcmp(cmd, "init") == 0) {
            int cap = atoi(strtok(NULL, " "));
            vector_destroy(v);
            v = vector_create(cap);
        } else if (strcmp(cmd, "push") == 0) {
            char* arg;
            while ((arg = strtok(NULL, " "))) {
                vector_push_back(v, atoi(arg));
            }
        } else if (strcmp(cmd, "show") == 0) {
            vector_str(v);
        } else if (strcmp(cmd, "status") == 0) {
            vector_status(v);
        } else if (strcmp(cmd, "pop") == 0) {
            if (!vector_pop_back(v)) {
                printf("vector is empty\n");
            }
        } else if (strcmp(cmd, "insert") == 0) {
            int index = atoi(strtok(NULL, " "));
            int value = atoi(strtok(NULL, " "));
            if (!vector_insert(v, index, value)) {
                printf("index out of range\n");
            }
        } else if (strcmp(cmd, "erase") == 0) {
            int index = atoi(strtok(NULL, " "));
            if (!vector_erase(v, index)) {
                printf("index out of range\n");
            }
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
            if (vector_at(v, index, &value)) {
                printf("%d\n", value);
            } else {
                printf("index out of range\n");
            }
        } else if (strcmp(cmd, "set") == 0) {
            int index = atoi(strtok(NULL, " "));
            int value = atoi(strtok(NULL, " "));
            if (!vector_set(v, index, value)) {
                printf("index out of range\n");
            }
        } else if (strcmp(cmd, "reserve") == 0) {
            int newCap = atoi(strtok(NULL, " "));
            vector_reserve(v, newCap);
        } else if (strcmp(cmd, "slice") == 0) {
            int start = atoi(strtok(NULL, " "));
            int end = atoi(strtok(NULL, " "));
            Vector slice = vector_slice(v, start, end);
            vector_str(&slice);
        } else {
            printf("comando invalido\n");
        }
    }

    vector_destroy(v);

    return 0;
}
