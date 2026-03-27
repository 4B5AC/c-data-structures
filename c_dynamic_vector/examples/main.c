#include "../include/int_vector.h"

int main(void){
    vector_int* vector = create_int_vector(10);

    int_vector_push(vector,314);
    int_vector_push(vector,628);
    int_vector_push(vector,981);
    int_vector_push(vector,218);
    int_vector_push(vector,314);
    int_vector_push(vector,000);
    int_vector_pop(vector);
    print_int_vector(vector);

    destroy_int_vector(vector);
    return 0;
}