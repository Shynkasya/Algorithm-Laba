#include "Laba3.h"
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
	while (return_color(node->parent) == RED) {
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

void update_rb_height(rb_tree** tree, int height) {
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
	update_rb_height(*&tree);
}

void enter_rb_node_from_console(rb_tree* node) {
	cout << "Enter name: ";
	cin >> node->surname;
	cout << "Enter private number: ";
	cin >> node->private_number;
	cout << "Enter experience: ";
	cin >> node->experience;
	node->color = RED;
	node->left = NULL;
	node->right = NULL;
}

void enter_rb_tree(rb_tree* rb_node, tree_node* node) {
	rb_node->surname = node->surname;
	rb_node->private_number = node->private_number;
	rb_node->experience = node->experience;
	rb_node->color = RED;
	rb_node->left = NULL;
	rb_node->right = NULL;
}
void colorize_tree(rb_tree** root, tree_node* tree) {
	if (tree == NULL) return;
	colorize_tree(*&root, tree->right);
	colorize_tree(*&root, tree->left);
	rb_tree* node;
	node = new rb_tree;
	enter_rb_tree(node, tree);
	insert_rb_node(*&root, node);
}
void print_rb_node(rb_tree* node) {
	if (node->color == RED) {
		SetConsoleTextAttribute(handle, 12);
	}
	for (int i = 0; i < node->height; i++) cout << "    ";
	cout << "Surname: " << node->surname << endl;
	for (int i = 0; i < node->height; i++) cout << "    ";
	cout << "Privat number: " << node->private_number << endl;
	for (int i = 0; i < node->height; i++) cout << "    ";
	cout << "Experience: " << node->experience << endl;



	//for (int i = 0; i < node->height; i++) cout << "    ";
	//cout << node->surname << ", " << node->private_number << ", " << node->experience << endl;
	/*for (int i = 0; i < node->height; i++) cout << "    ";
	cout << node->surname << endl;
	for (int i = 0; i < node->height; i++) cout << "    ";
	cout << node->private_number << endl;
	for (int i = 0; i < node->height; i++)   cout << "    ";
	cout << node->experience << endl;

	if (node->parent != NULL) {
		for (int i = 0; i < node->height; i++) cout << "    ";
		cout << node->parent->surname << endl;
	}*/
	SetConsoleTextAttribute(handle, 7);
	//cout << endl;
}
void print_rb_tree(rb_tree* tree) {
	/*if (tree == NULL) return;
	print_rb_tree(tree->right);
	print_rb_node(tree);
	print_rb_tree(tree->left);*/
	if (tree == NULL) return;
	print_rb_tree(tree->right);
	print_rb_node(tree);
	print_rb_tree(tree->left);
}


rb_tree* rb_get_min(rb_tree* tree) {
	//if (tree == NULL) return NULL;
	//if (tree->right == NULL) return tree;
	if (tree->left == NULL) return tree;
	rb_get_min(tree->left);
}
rb_tree* delete_rb_node(rb_tree* node, rb_tree* root) {
	if (node == NULL) return root;
	color color = node->color;
	bool is_node_right_child = true;
	if (node->parent == NULL) {
		if (node->right == NULL) {
			root = node->left;
			root->parent = NULL;
			root->color = BLACK;
			delete node;
			return root;
		}
		else if (node->left == NULL) {
			root = node->right;
			root->parent = NULL;
			root->color = BLACK;
			delete node;
			return root;
		}
	}
	else {
		if (node == node->parent->left) {
			is_node_right_child = false;
		}
		if (node->left == NULL) {
			if (is_node_right_child) {
				node->parent->right = node->right;
				node->right->parent = node->parent;
			}
			else {
				node->parent->left = node->right;
				if (node->right != NULL) node->right->parent = node->parent;
			}
			if (color == BLACK) root = fix_tree(*&node, *&root);
			delete node;
			return root;
		}
		if (node->right == NULL) {
			if (is_node_right_child) {
				node->parent->right = node->left;
				node->left->parent = node->parent;
			}
			else {
				node->parent->left = node->left;
				if (node->left != NULL) node->left->parent = node->parent;
			}
			if (color == BLACK) root = fix_tree(*&node, *&root);
			delete node;
			return root;
		}
	}
	rb_tree* tmp = rb_get_min(node->right);
	node->surname = tmp->surname;
	node->private_number = tmp->private_number;
	node->experience = tmp->experience;
	return delete_rb_node(tmp, root);
}
rb_tree* fix_tree(rb_tree* node, rb_tree* root) {
	rb_tree* brother;
	rb_tree* self;
	if (node->left == NULL) self = node->right;
	else self = node->left;
	if (self == node->parent->left) {
		brother = node->parent->right;
		if (return_color(self) == RED) self->color = BLACK;
		else {
			if ((return_color(brother->right) != BLACK || return_color(brother->left) != BLACK) && brother->color == BLACK) {
				if (return_color(brother->right) == BLACK) {
					brother->color = RED;
					brother->left->color = BLACK;
					root = rotate_right(brother, root);
					brother = brother->parent;
				}
				brother->color = brother->parent->color;
				brother->parent->color = BLACK;
				brother->right->color = BLACK;
				root = rotate_left(node->parent, root);
			}
			else {
				if (brother->color = RED) {
					brother->color = BLACK;
					brother->left->color = RED;
					root = rotate_left(brother->parent, root);
				}
				else if (brother->parent->parent == NULL) brother->color = RED;
				else if (brother->parent->color == RED) {
					brother->color = RED;
					brother->parent->color = BLACK;
				}
				else {
					brother->color = RED; // Idon't know what to do here
				}
			}
		}
	}
	else {
		brother = node->parent->left;
		if (return_color(self) == RED) self->color = BLACK;
		else {
			if (return_color(brother->right) != BLACK && return_color(brother->left) != BLACK && brother->color == BLACK) {
				if (return_color(brother->left) == BLACK) {
					brother->color = RED;
					brother->right->color = BLACK;
					root = rotate_left(brother, root);
					brother = brother->parent;
				}
				brother->color = brother->parent->color;
				brother->parent->color = BLACK;
				brother->left->color = BLACK;
				root = rotate_right(node->parent, root);
			}
			else {
				if (brother->color = RED) {
					brother->color = BLACK;
					brother->right->color = RED;
					root = rotate_right(brother->parent, root);
				}
				else if (brother->parent->parent == NULL) brother->color = RED;
				else if (brother->parent->color == RED) {
					brother->color = RED;
					brother->parent->color = BLACK;
				}
				else {
					brother->color = RED; // Idon't know what to do here
				}
			}
		}
	}
	return root;
}



void delete_rb_tree(rb_tree** node) {
	if ((*node) == NULL) return;
	delete_rb_tree(&(*node)->left);
	delete_rb_tree(&(*node)->right);
	delete((*node));
	(*node) = NULL;
}



bool check_rb_tree(rb_tree* node, int& blackHeight) {
	if (node == nullptr) {
		blackHeight = 1;
		return true;
	}

	int leftBlackHeight = 0, rightBlackHeight = 0;

	if (return_color(node) == RED) {
		if (return_color(node->left) == RED || return_color(node->right) == RED) {
			return false;
		}
	}
	if (!check_rb_tree(node->left, leftBlackHeight) || !check_rb_tree(node->right, rightBlackHeight))
		return false;
    if (leftBlackHeight != rightBlackHeight) {
		return false;
	}
	blackHeight = leftBlackHeight + return_color(node);

	return true;
}

void rb_tree_menu(tree_node* tree) {
	char filename[] = "File.txt";
	rb_tree* rb_tree_root = NULL;
	int height = 0;
	colorize_tree(&rb_tree_root, tree);
	update_rb_height(&rb_tree_root);
	print_rb_tree(rb_tree_root);
	system("pause");
	rb_tree* tmp = NULL;
	cout << endl;
	bool quit = true;
	int num_menu;
	while (quit) {
		system("cls");
		cout << "1. Print red-black tree\n";
		cout << "2. Check properties\n";
		cout << "3. Delete node\n";
		cout << "4. Insert node\n";
		cout << "5. Exit\n";
		cout << "Choose oparetion: ";
		cin >> num_menu;
		switch (num_menu)
		{
		case 1:		
			print_rb_tree(rb_tree_root);
			system("pause");
			break;
		case 2:
			if (check_rb_tree(rb_tree_root, height)){
				cout << "All properties is right\n";
			}
			else {
				cout << "Not all proprietes is right\n";
			}
			system("pause");
			break;
		case 3:
			//delete_rb_node();
			system("pause");
			break;
		case 4:
			tmp = new rb_tree;
			enter_rb_node_from_console(*&tmp);
			insert_rb_node(&rb_tree_root, tmp);
			print_rb_tree(rb_tree_root);
			system("pause");
			break;
		case 5:
			quit = false;
			break;
		default:
			cout << "Ty daun probui eshche raz\n";
			break;
		}
	}
	delete_rb_tree(&rb_tree_root);
}