#ifndef DATA_STRUCTURES_IN_C_1_LINKED_LIST_H
#define DATA_STRUCTURES_IN_C_1_LINKED_LIST_H

typedef struct Information{
    char* message;
    struct Information* next;

    // initializer
    void (*initialize)(struct Information *self);
    // void print_message() -> field 'print_message' declared as a function -> use pointers in C
    void (*print_message)(struct Information *self);
    void (*set_message)(struct Information *self, char* message);
    void (*add_node)(struct Information *self);

} Information;

void print_message(struct Information *self);
void set_message(struct Information *self, char* message);
void add_node(struct Information *self);
void initialize(struct Information *self);

#endif //DATA_STRUCTURES_IN_C_1_LINKED_LIST_H
