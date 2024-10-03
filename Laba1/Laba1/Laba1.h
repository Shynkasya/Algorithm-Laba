#pragma once
#include <iostream>
#include <fstream>
#include <filesystem>
using namespace std;
struct single_list {
	long long node;
	single_list* next;
};
void create_single_list(single_list** list, int n);
void create_single_list_from_file(single_list** list, char* filename);
void push_back(single_list** list, long long data);
void print_list(single_list* list);
void print_list_to_file(single_list* list, char* filename);
int list_size(single_list* list);
void delete_list(single_list** list);
void swap_element(single_list** list, int n);
void pop_element(single_list** list, int n);


void single_menu();




struct double_list {
	long long node;
	double_list* prev;
	double_list* next;
};

void double_push_back(double_list** list, long long data);
void create_double_list(double_list** list, int n);
void create_double_list_from_file(double_list** list, char* filename);
void print_double_list(double_list* list);
void print_double_list_to_file(double_list* list, char* filename);
void delete_double_list(double_list** list);
void swap_double_element(double_list** list, int n1, int n2);
int double_list_size(double_list* list);
void pop_double_element(double_list** list, int n);
void push_double_element(double_list** list, long long data, int n);

void double_menu();