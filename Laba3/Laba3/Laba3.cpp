#include"Laba3.h"
HANDLE handle;
//string Surnames[26] = { "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z" };






//enum color { RED, BLACK };


int main() {
	srand(time(NULL));
	handle = GetStdHandle(STD_OUTPUT_HANDLE);

	tree_menu();

	/*rb_tree* tree = NULL;
	colorize_tree(&tree, 15);
	print_rb_tree(tree);
	cout << endl << "*************************\n";
	tree = delete_rb_node(tree, tree);
	update_rb_height(&tree);
	print_rb_tree(tree);*/



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