#pragma once
#include<iostream>
#include <fstream>
//#include <filesystem>
#include <Windows.h>


extern HANDLE handle;

using namespace std;
struct stack {
	short data;
	stack* link;
};


void make_stack(stack** Top_Stack, int n);
void read_stack_from_file(stack** list, char* filename);
void push_stack(short data, stack** Top_Stack);
void delete_stack(stack** top_stack);
void print_stack(stack* list);
void print_stack_to_file(stack* list, char* filename);
void pop_element(stack** top_stack);
void swap_elements(stack** Top_Stack);
void reverse_stack(stack** top_stack);
void delete_elements(stack** top_stack);
void max_element(stack** top_stack);
void min_element(stack** top_stack);
void delete_except_first(stack** top_stack);
void delete_except_last(stack** top_stack);


void stack_menu();




struct queue_node {
	short data;
	queue_node* prev;
};

struct queue {
	queue_node* begin;
	queue_node* end;
};
void create_queue(queue* list, int n);
void print_queue_rec(queue list);
void print_queue(queue list);
void delete_queue(queue* list);
int count_queue_elements(queue list);
double avegange_queue_elements(queue list);
void min_max_queue(queue list);
void element_before_min_queue(queue list);


void queue_menu();





struct deque_node {
	short data;
	deque_node* prev, * next;

};
struct deque {
	deque_node* begin;
	deque_node* end;
};

void create_deque(deque* list, int n);
void create_deque_from_file(deque* list, char* filename);
void print_deque(deque list);
void print_deque_to_file(deque list, char* filename);
void delete_deque(deque* list);
void pop_element_to_deque_begin(deque* list, short data);
void pop_element_to_deque_end(deque* list, short data);
short read_deque_last_element(deque list);
bool is_empty_deque(deque list);


void deque_menu();
