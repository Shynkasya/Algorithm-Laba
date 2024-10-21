#include"Laba3.h"
HANDLE handle;
//string Surnames[26] = { "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z" };






//enum color { RED, BLACK };

rb_tree* rotate_right(rb_tree* y, rb_tree* root) {
	rb_tree* x = y->left;
	y->left = x->right;

	if (x->right != nullptr) {
		x->right->parent = y;
	}

	x->parent = y->parent;
	if (y->parent == nullptr) {
		root = x;
	}
	else if (y == y->parent->left) {
		y->parent->left = x;
	}
	else {
		y->parent->right = x;
	}
	x->right = y;
	y->parent = x;
	return root;
}
rb_tree* rotate_left(rb_tree* x, rb_tree* root) {
	rb_tree* y = x->right;
	x->right = y->left;
	if (y->left != nullptr) {
		y->left->parent = x;
	}
	y->parent = x->parent;
	if (x->parent == nullptr) {
		root = y;
	}
	else if (x == x->parent->left) {
		x->parent->left = y;
	}
	else {
		x->parent->right = y;
	}
	y->left = x;
	x->parent = y;
	return root;
}
color return_color(rb_tree* node) {
	if (node == NULL) return BLACK;
	return node->color;
}
void balance_tree(rb_tree* node, rb_tree** root) {
	rb_tree* uncle;
	bool is_left_balance = false;
	//while (return_color(node->parent) == RED) {
	if (return_color(node->parent) == RED) {
		uncle = node->parent->parent->left;
		is_left_balance = false;
		if (uncle == node->parent) {
			uncle = node->parent->parent->right;
			is_left_balance = true;
		}
		if (return_color(uncle) == RED) {
			uncle->color = BLACK;
			node->parent->color = BLACK;
			uncle->parent->color = RED;
			node = node->parent->parent;
		}
		else {
			if (is_left_balance) {
				if (node == node->parent->right) {
					node = node->parent;
					(*root) = rotate_left(node, *root);
				}
				node->parent->color = BLACK;
				node->parent->parent->color = RED;
				(*root) = rotate_right(node->parent->parent, *root);
			}
			else {
				if (node == node->parent->left) {
					node = node->parent;
					(*root) = rotate_right(node, *root);
				}
				node->parent->color = BLACK;
				node->parent->parent->color = RED;
				(*root) = rotate_left(node->parent->parent, *root);
			}
		}
	}
	(*root)->color = BLACK;
}
//void update_rb_height(rb_tree** tree) {
//	if ((*tree) == NULL) return;
//	if((*tree)->parent != NULL)	(*tree)->height = (*tree)->parent->height + 1;
//	update_rb_height(&(*tree)->right);
//	update_rb_height(&(*tree)->left);
//}
void update_rb_height(rb_tree** tree, int height = -1) {
	if ((*tree) == NULL) return;
	(*tree)->height = height + 1;
	update_rb_height(&(*tree)->right, (*tree)->height);
	update_rb_height(&(*tree)->left, (*tree)->height);
}
void insert_rb_node(rb_tree** tree, rb_tree* node) {
	rb_tree* current_node = *tree;
	rb_tree* parent_node = NULL;
	while (current_node != NULL) {
		parent_node = current_node;
		if (current_node->surname <= node->surname) current_node = current_node->right;
		else current_node = current_node->left;
	}
	node->parent = parent_node;
	if (parent_node == NULL) (*tree) = node;
	else if (parent_node->surname <= node->surname) parent_node->right = node;
	else parent_node->left = node;
	balance_tree(node, *&tree);
}

void colorize_tree(rb_tree** root, int n) {
	rb_tree* tmp;
	while (n > 0) {
		tmp = new rb_tree;
		enter_rb_tree(tmp);
		//if ((*root) == NULL) { 
		//	(*root) = tmp; 
		//	(*root)->color = BLACK;
		//	//(*root)->surname = "a";
		//}
		//else
		insert_rb_node(*&root, tmp);
		update_rb_height(*&root);
		print_rb_tree(*root);
		//cout << "Element is insert\n";
		cout << endl << "**************************" << endl;
		n--;
	}
	update_rb_height(*&root);
}
void print_rb_node(rb_tree* node) {
	if (node->color == RED) {
		SetConsoleTextAttribute(handle, 12);
	}
	for (int i = 0; i < node->height; i++) cout << "    ";
	cout << node->surname << endl;
	for (int i = 0; i < node->height; i++) cout << "    ";
	cout << node->private_number << endl;
	for (int i = 0; i < node->height; i++)   cout << "    ";
	cout << node->experience << endl;
	SetConsoleTextAttribute(handle, 7);
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
	handle = GetStdHandle(STD_OUTPUT_HANDLE);

	//tree_menu();

	rb_tree* tree = NULL;
	colorize_tree(&tree, 8);
	print_rb_tree(tree);
	/*rotate_left(&tree, );
	cout << "*********************";
	print_rb_tree(tree);*/


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