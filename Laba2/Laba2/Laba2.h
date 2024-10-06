#pragma once
#include<iostream>
#include <fstream>
#include <filesystem>
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