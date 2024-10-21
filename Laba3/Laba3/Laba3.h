#pragma once
#include<string>
#include<iostream>
#include<algorithm>
#include <time.h>
#include <Windows.h>


extern HANDLE handle;
//extern const string Surnames[26];

using namespace std;

struct tree_node {
	//public:	
	string surname;
	int private_number;
	int experience = 0;
	int height = 0;
	tree_node* right;
	tree_node* left;


	//function
};
void enter_tree(tree_node* node);
void insert(tree_node** tree, tree_node* node);
void make_binary_tree(tree_node** root, int n);



void print_node(tree_node* node);
void update_height(tree_node** tree, int height = -1);
void print_structure(tree_node* node);
void print_tree(tree_node* node);
void print_preorder_tree(tree_node* node);
void print_postorder_tree(tree_node* node);


int count_element(tree_node* node);
int sum_element(tree_node* node);
double  averange_ex(tree_node* node);

void delete_tree(tree_node** node);

void delete_right_tree(tree_node** tree);
void delete_left_tree(tree_node** tree);
tree_node* get_parent_min_node(tree_node* tree);
void delete_node(tree_node** node);



void insert_by_exp(tree_node** tree, tree_node* node);
void make_experience_tree(tree_node** tree, tree_node** root);
tree_node* resort_tree_by_experience(tree_node** tree);



void tree_menu();

enum color { RED, BLACK };
struct rb_tree {
	string surname;
	int private_number;
	int experience = 0;
	int height = 0;
	color color = BLACK;
	rb_tree* right;
	rb_tree* left;
	rb_tree* parent;
};

void enter_rb_tree(rb_tree* node);