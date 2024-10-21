#include "Laba3.h"
string Surnames[26] = { "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z" };


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
void update_height(tree_node** tree, int height) {
	if ((*tree) == NULL) return;
	update_height(&(*tree)->right, (*tree)->height);
	(*tree)->height = height + 1;
	update_height(&(*tree)->right, (*tree)->height);
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

void tree_menu() {
	char filename[] = "File.txt";
	tree_node* tree = NULL;
	bool quit = true;
	int num_menu;
	while (quit) {
		system("cls");
		cout << "1. Make tree\n";
		cout << "2. Make tree from file\n";
		cout << "3. Print tree\n";
		cout << "4. Write tree to file\n";
		cout << "5. Averange of experience\n";
		cout << "6. Delete all tree\n";
		cout << "7. Delete parts of the tree\n";
		cout << "8. Sort tree by experience\n";
		cout << "9. Exit\n";
		cout << "Choose oparetion: ";
		cin >> num_menu;
		switch (num_menu)
		{
		case 1:
			delete_tree(&tree);
			cout << "Enter the quantity of element: ";
			cin >> num_menu;
			make_binary_tree(&tree, num_menu);
			print_structure(tree);
			cout << endl;
			break;
		case 2:
			break;
		case 3:
			system("cls");
			cout << "1. Print in-order\n";
			cout << "2. Print pre-order\n";
			cout << "3. Print post-order\n";
			cout << "4. Print structure\n";
			cout << "Choose oparetion: ";
			cin >> num_menu;
			switch (num_menu)
			{
			case 1:
				print_tree(tree);
				break;
			case 2:
				print_preorder_tree(tree);
				break;
			case 3:
				print_postorder_tree(tree);
				break;
			case 4:
				print_structure(tree);
				break;
			default:
				break;
			}
			break;
		case 4:
			break;
		case 5:
			cout << "Averange of experience: " << averange_ex(tree) << endl;
			break;
		case 6:
			delete_tree(&tree);
			cout << "Tree is succesfully deleted\n";
			break;
		case 7:
			system("cls");
			cout << "1. Delete right tree\n";
			cout << "2. Delete left tree\n";
			cout << "3. Delete node\n";
			cout << "Choose oparetion: ";
			cin >> num_menu;
			switch (num_menu)
			{
			case 1:
				delete_right_tree(&tree);
				break;
			case 2:
				delete_left_tree(&tree);
				break;
			case 3:
				delete_node(&tree);
				break;
			default:
				break;
			}
			cout << endl;
			break;
		case 8:
			tree = resort_tree_by_experience(&tree);
			break;
		case 9:
			quit = false;
			break;
		default:
			cout << "Ty daun probui eshche raz\n";
			break;
		}
		system("pause");
	}
}