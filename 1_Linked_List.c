#include "1_Linked_list.h"
#include <stdio.h>
#include <stdlib.h>

void print_message(struct Information *self){
    printf("%s\n", self->message);
}

void set_message(struct Information *self, char* message){
    self->message = message;
}

void add_node(struct Information *self){
    Information node;
    node.initialize = initialize;
    node.initialize(&node);

    // shallow copy
    Information* self_copy;
    self_copy = self;

    // go to the end of the list
    while(self_copy->next != NULL){
        self_copy = self_copy->next;
    }

    // deep copy
    self_copy->next = (Information*)malloc(sizeof(Information)); // malloc returns void -> you cast to that one
    *self_copy->next = node;

    // only for second one
    // method 1 - shallow copy
    // self->next = (Information*)malloc(sizeof(Information)); // malloc returns void -> you cast to that one
    // *self->next = node;
    // method 2 - deep copy
    // self->next = &node;
}

void initialize(struct Information *self){
    self->next = NULL;
    self->message = "";

    self->print_message = print_message;
    self->set_message = set_message;
    self->add_node = add_node;
}

int main(){
    Information my_info;
    my_info.initialize = initialize;
    my_info.initialize(&my_info);

    // my_info.message = "Hellow";
    set_message(&my_info, "Hellow");

    // if it wouldn't be initialized, then it would have to do for each function
    // my_info.print_message = print_message;
    my_info.print_message(&my_info);

    my_info.add_node(&my_info);
    my_info.next->message = "Pointers are real";
    my_info.next->print_message(my_info.next);

    my_info.next->set_message(my_info.next, "Pointers are funny");
    my_info.next->print_message(my_info.next);
    my_info.print_message(&my_info);

}