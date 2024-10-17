#include<string>
#include<iostream>
#include<algorithm>
#include <time.h>

using namespace std;
string Surnames[5] = { "f", "a", "z", "g", "p" };
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
void update_height(tree_node* node) {
	node->height = max(node->left->height, node->right->height) + 1;
}
void enter_tree(tree_node* node) {
	/*cout << "Enter name: ";
	cin >> node->surname;
	cout << "Enter private number: ";
	cin >> node->private_number;
	cout << "Enter experience: ";
	cin >> node->experience;*/
	node->surname = Surnames[rand() % 5];
	node->private_number = rand() % 100 + 1;
	node->experience = rand() % 15 + 1;
	node->left = NULL;
	node->right = NULL;
}
void insert(tree_node** tree, tree_node* node) {
	if ((*tree)->surname < node->surname) {
		if ((*tree)->left == NULL) (*tree)->left = node;
		else insert(&(*tree)->left, node);
	}
	if ((*tree)->surname >= node->surname) {
		if ((*tree)->right == NULL) (*tree)->right = node;
		else insert(&(*tree)->right, node);
	}
}
void make_binary_tree(tree_node** root, int n) {
	tree_node* tmp;
	while (n > 0) {
		tmp = new tree_node;
		enter_tree(tmp);
		if ((*root) == NULL) (*root) = tmp;
		else insert(*&root, tmp);
		cout << "Element is insert\n";
		n--;
	}
}

void print_node(tree_node* node) {
	cout << node->surname << endl;
	cout << node->private_number << endl;
	cout << node->experience << endl;
	cout << endl;
}

void print_tree(tree_node* node) {
	if (node == NULL) return;
	print_tree(node->right);
	print_node(node);
	print_tree(node->left);
}

void print_preorder_tree(tree_node* node) {
	if (node == NULL) return;
	print_node(node);
	print_tree(node->left);
	print_tree(node->right);
}
void print_postorder_tree(tree_node* node) {
	if (node == NULL) return;
	print_tree(node->left);
	print_tree(node->right);
	print_node(node);
}
int count_element(tree_node* node) {
	int counter = 1;
	if (node == NULL) return 0;
	counter += count_element(node->left);
	counter += count_element(node->right);
	return counter;
}
int sum_element(tree_node* node) {
	if (node == NULL) return 0;
	int sum = node->experience;
	sum += sum_element(node->left);
	sum += sum_element(node->right);
	return sum;
}
double  averange_ex(tree_node* node) {
	return (double)((double)sum_element(node) / (double)count_element(node));
}
void delete_tree(tree_node** node) {
	if ((*node) == NULL) return;
	delete_tree(&(*node)->left);
	delete_tree(&(*node)->right);
	delete((*node));
	(*node) = NULL;
}
void delete_right_tree(tree_node** tree) {
	if ((*tree) == NULL) return;
	delete_tree(&(*tree)->right);
}
void delete_left_tree(tree_node** tree) {
	if ((*tree) == NULL) return;
	delete_tree(&(*tree)->left);
}
tree_node* get_parent_min_node(tree_node* tree) {
	//if (tree == NULL) return NULL;
	//if (tree->right == NULL) return tree;
	if (tree->right->right == NULL) return tree;
	get_parent_min_node(tree->right);
}
void delete_node(tree_node** node) {
	if ((*node) == NULL) return;
	tree_node* tmp = (*node);
	if ((*node)->left == NULL) {
		(*node) = (*node)->right;
		delete tmp;
		tmp = NULL;
		return;
	}
	if ((*node)->right == NULL) {
		(*node) = (*node)->left;
		delete tmp;
		tmp = NULL;
		return;
	}
	if ((*node)->left->right == NULL) {
		tmp = (*node)->left;
		(*node)->surname = tmp->surname;
		(*node)->private_number = tmp->private_number;
		(*node)->experience = tmp->experience;
		(*node)->left = NULL;
		return;
	}
	tmp = get_parent_min_node((*node)->left);
	cout << "*******\n";
	print_tree(tmp);
	cout << "*******\n";

	(*node)->surname = tmp->right->surname;
	(*node)->private_number = tmp->right->private_number;
	(*node)->experience = tmp->right->experience;
	delete(tmp->right);
	tmp->right = NULL;
}

void insert_by_exp(tree_node** tree, tree_node* node) {
	if ((*tree)->experience < node->experience) {
		if ((*tree)->left == NULL) (*tree)->left = node;
		else insert_by_exp(&(*tree)->left, node);
	}
	if ((*tree)->experience >= node->experience) {
		if ((*tree)->right == NULL) (*tree)->right = node;
		else insert_by_exp(&(*tree)->right, node);
	}
}
void make_experience_tree(tree_node** tree, tree_node** root) {
	tree_node* tmp = NULL;
	if ((*tree) == NULL) return;
	make_experience_tree(&(*tree)->right, &(*root));
	make_experience_tree(&(*tree)->left, &(*root));
	tmp = new tree_node;
	tmp->surname = (*tree)->surname;
	tmp->private_number = (*tree)->private_number;
	tmp->experience = (*tree)->experience;
	tmp->left = NULL;
	tmp->right = NULL;
	if ((*root) == NULL) (*root) = tmp;
	else insert_by_exp(*&root, tmp);
}

tree_node* resort_tree_by_experience(tree_node** tree) {
	tree_node* changed_tree = NULL;
	make_experience_tree(&(*tree), &changed_tree);
	delete_tree(&(*tree));
	return changed_tree;
}
int main() {
	srand(time(NULL));
	tree_node *tree = NULL;
	make_binary_tree(&tree, 4);
	print_tree(tree);
	system("pause");
	cout << "******************\n";
	tree = resort_tree_by_experience(&tree);
	print_tree(tree);
	/*if (tree == NULL) cout << "Tree is Null";
	delete_tree(&tree);
	if (tree == NULL) cout << "Tree is Null";
	print_tree(tree);*/
	//cout << averange_ex(*&tree);
}