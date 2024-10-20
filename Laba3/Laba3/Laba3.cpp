#include<string>
#include<iostream>
#include<algorithm>
#include <time.h>

using namespace std;
string Surnames[26] = { "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z" };
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
void enter_tree(tree_node* node) {
	/*cout << "Enter name: ";
	cin >> node->surname;
	cout << "Enter private number: ";
	cin >> node->private_number;
	cout << "Enter experience: ";
	cin >> node->experience;*/
	node->surname = Surnames[rand() % 26];
	node->private_number = rand() % 100 + 1;
	node->experience = rand() % 15 + 1;
	node->left = NULL;
	node->right = NULL;
}
void insert(tree_node** tree, tree_node* node) {
	node->height++;
	if ((*tree)->surname > node->surname) {
		if ((*tree)->left == NULL) (*tree)->left = node;
		else insert(&(*tree)->left, node);
	}
	if ((*tree)->surname <= node->surname) {
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
	cout << "Surname: " << node->surname << endl;
	cout << "Privat number: " << node->private_number << endl;
	cout << "Experience: " << node->experience << endl;
	cout << endl;
}
void print_structure(tree_node* node) {
	if (node == NULL) return;
	print_structure(node->right);
	for (int i = 0; i < node->height; i++) cout << "    ";
	cout << "Surname: " << node->surname << endl;
	for (int i = 0; i < node->height; i++) cout << "    ";
	cout << "Privat number: " << node->private_number << endl;
	for (int i = 0; i < node->height; i++) cout << "    ";
	cout << "Experience: " << node->experience << endl;
	print_structure(node->left);
}
void print_tree(tree_node* node) {
	if (node == NULL) return;
	print_tree(node->right);
	print_node(node);
	print_tree(node->left);
}
void update_height(tree_node** tree, int height = -1) {
	if ((*tree) == NULL) return;
	update_height(&(*tree)->right, (*tree)->height);
	(*tree)->height = height + 1;
	update_height(&(*tree)->right, (*tree)->height);
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
	if (tree->left->left == NULL) return tree;
	get_parent_min_node(tree->left);
}
void delete_node(tree_node** node) {
	if ((*node) == NULL) return;
	tree_node* tmp = (*node);
	if ((*node)->left == NULL) {
		(*node) = (*node)->right;
		delete tmp;
		tmp = NULL;
		update_height(&(*node));
		return;
	}
	if ((*node)->right == NULL) {
		(*node) = (*node)->left;
		delete tmp;
		tmp = NULL;
		update_height(&(*node));
		return;
	}
	if ((*node)->right->left == NULL) {
		(*node)->right->left = (*node)->left;
		tmp = (*node)->right;
		delete (*node);
		(*node) = tmp;
		update_height(&(*node));
		return;
	}
	tmp = get_parent_min_node((*node)->right);

	(*node)->surname = tmp->left->surname;
	(*node)->private_number = tmp->left->private_number;
	(*node)->experience = tmp->left->experience;
	tree_node* tmp_1 = tmp->left->right;
	delete(tmp->left);
	tmp->left = tmp_1;
	update_height(&(*node));
}

void insert_by_exp(tree_node** tree, tree_node* node) {
	node->height++;
	if ((*tree)->experience > node->experience) {
		if ((*tree)->left == NULL) (*tree)->left = node;
		else insert_by_exp(&(*tree)->left, node);
	}
	if ((*tree)->experience <= node->experience) {
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
	update_height(&(*tree));
}

tree_node* resort_tree_by_experience(tree_node** tree) {
	tree_node* changed_tree = NULL;
	make_experience_tree(&(*tree), &changed_tree);
	delete_tree(&(*tree));
	return changed_tree;
}






enum color { RED, BLACK };
struct rb_tree{
	string surname;
	int private_number;
	int experience = 0;
	int height = 0;
	color color = BLACK;
	rb_tree* right;
	rb_tree* left;
	rb_tree* parent;
};
void rotate_right(rb_tree** node) {
	if ((*node)->parent == NULL) {
		rb_tree* tmp = (*node)->left;
		(*node)->left = tmp->right;
		tmp->right = (*node);
		tmp->parent = NULL;
		(*node)->parent = tmp;
		(*node)->left->parent = (*node);
		//(*node) = tmp;
		return;
	}
	rb_tree* tmp = (*node)->parent;
	tmp->right = (*node)->left;
	(*node)->left = tmp->right->right;
	tmp->right->right = (*node);
	tmp->right->parent = tmp;
	(*node)->parent = tmp->right;
	(*node)->left->parent = (*node);
	//(*node) = tmp->right;
}
void rotate_left(rb_tree** node) {
	if ((*node)->parent == NULL) {
		rb_tree* tmp = (*node)->right;
		(*node)->right = tmp->left;
		tmp->left = (*node);
		tmp->parent = NULL;
		(*node)->parent = tmp;
		(*node)->right->parent = (*node);
		//(*node) = tmp;
		return;
	}
	rb_tree* tmp = (*node)->parent;
	tmp->left = (*node)->right;
	(*node)->right = tmp->left->left;
	tmp->left->left = (*node);
	tmp->left->parent = tmp;
	(*node)->parent = tmp->left;
	(*node)->right->parent = (*node);
	//(*node) = tmp->left;
}
color return_color(rb_tree* node) {
	if (node == NULL) return BLACK;
	return node->color;
}
void balance_tree(rb_tree** node) {
	rb_tree* uncle;
	bool is_left_balance = false;
	while (return_color((*node)->parent) == RED) {
		uncle = (*node)->parent->parent->left;
		is_left_balance = false;
		if (uncle->surname ==  (*node)->parent->surname) {
			uncle = (*node)->parent->parent->right;
			is_left_balance = true;
		}
		if (return_color(uncle) == RED) {
			uncle->color = BLACK;
			(*node)->parent->color = BLACK;
			if (uncle->parent->parent != NULL) uncle->parent->color == RED;
			(*node) = (*node)->parent->parent;
		}
		else {
			if (is_left_balance) {
				if ((*node)->surname == (*node)->parent->right->surname) {
					(*node) = (*node)->parent;
					rotate_left(*&node);
				}
				(*node)->parent->color = BLACK;
				(*node)->parent->parent->color = RED;
				rotate_right(&(*node)->parent->parent);
			}
			else {
				if ((*node)->surname == (*node)->parent->left->surname) {
					(*node) = (*node)->parent;
					rotate_right(*&node);
				}
				(*node)->parent->color = BLACK;
				(*node)->parent->parent->color = RED;
				rotate_left(&(*node)->parent->parent);
			}
		}
	}
}
void update_rb_height(rb_tree** tree, int height = -1) {
	if ((*tree) == NULL) return;
	update_rb_height(&(*tree)->right, (*tree)->height);
	(*tree)->height = height + 1;
	update_rb_height(&(*tree)->right, (*tree)->height);
}
void insert_rb_node(rb_tree** tree, rb_tree* node) {
	if ((*tree)->surname < node->surname) {
		if ((*tree)->left == NULL) {
			(*tree)->left = node;
			node->parent = (*tree);
		}
		else insert_rb_node(&(*tree)->left, node);
	}
	if ((*tree)->surname >= node->surname) {
		if ((*tree)->right == NULL) {
			(*tree)->right = node;
			node->parent = (*tree);
		}
		else insert_rb_node(&(*tree)->right, node);
	}
	balance_tree(&(*tree));
	update_rb_height(&(*tree));
}
void enter_rb_tree(rb_tree* node) {
	/*cout << "Enter name: ";
	cin >> node->surname;
	cout << "Enter private n  umber: ";
	cin >> node->private_number;
	cout << "Enter experience: ";
	cin >> node->experience;*/
	node->surname = Surnames[rand() % 26];
	node->private_number = rand() % 100 + 1;
	node->experience = rand() % 15 + 1;
	node->color = RED;
	node->left = NULL;
	node->right = NULL;
	node->parent = NULL;
}
void colorize_tree(rb_tree** root, int n) {
	rb_tree* tmp;
	while (n > 0) {
		tmp = new rb_tree;
		enter_rb_tree(tmp);
		if ((*root) == NULL) { 
			(*root) = tmp; 
			(*root)->color = BLACK;
			(*root)->surname = "z";
		}
		else insert_rb_node(*&root, tmp);
		cout << "Element is insert\n";
		n--;
	}
}
void print_rb_node(rb_tree* node) {
	for (int i = 0; i < node->height; i++) cout << "    ";
	cout << node->surname << endl;
	for (int i = 0; i < node->height; i++) cout << "    ";
	cout << node->private_number << endl;
	for (int i = 0; i < node->height; i++) cout << "    ";
	cout << node->experience << endl;
	cout << endl;
}
void print_rb_tree(rb_tree* tree){
	/*if (tree == NULL) return;
	print_rb_tree(tree->right);
	print_rb_node(tree);
	print_rb_tree(tree->left);*/
	if (tree == NULL) return;
	print_rb_tree(tree->right);
	print_rb_node(tree);
	print_rb_tree(tree->left);
}

int main() {
	srand(time(NULL));
	
	rb_tree* tree = NULL;
	colorize_tree(&tree, 8);
	print_rb_tree(tree);
	rotate_left(&tree);
	cout << "*********************";
	print_rb_tree(tree);


	//tree_node *tree = NULL;
	//make_binary_tree(&tree, 11);
	//print_structure(tree);
	//system("pause");
	//cout << "******************\n";
	////tree = resort_tree_by_experience(&tree);
	//delete_node(&tree);
	//print_structure(tree);
	
	
	
	
	/*if (tree == NULL) cout << "Tree is Null";
	delete_tree(&tree);
	if (tree == NULL) cout << "Tree is Null";
	print_tree(tree);*/
	//cout << averange_ex(*&tree);
}