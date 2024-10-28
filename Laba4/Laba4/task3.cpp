#include "Laba4.h"
int hash_function1(int k, int m) {
	return k % m;
}
int hash_function2(int k, int m) {
	return 1 + k % (m - 1);
}
struct hash_node {
	int key;
	bool is_empty = true;
};
void add_linar(hash_node* hash_table, int key, int size) {
	int h = hash_function1(key, size);
	for (int i = 0; i < size; i++)
	{
		if (hash_table[h].is_empty) {
			hash_table[h].key = key;
			hash_table[h].is_empty = false;
			return;
		}
		h++;
		h = h % size;
	}
	cout << "Table is full\n";
}
void add_square(hash_node* hash_table, int key, int size) {
	int h = hash_function1(key, size);
	int h1 = h;
	int c1 = 1;
	int c2 = 3;
	int i = 0;
	while (!hash_table[h1].is_empty)
	{
		h1 = h + c1 * i + c2 * i * i;
		h1 = h1 % size;
		i++;

	}
	if (hash_table[h1].is_empty) {
		hash_table[h1].key = key;
		hash_table[h1].is_empty = false;
		return;
	}
	cout << "Table is full\n";
}
void add_double(hash_node* hash_table, int key, int size) {
	int h = hash_function1(key, size);
	int h1 = hash_function2(key, size);
	int c1 = 1;
	int c2 = 3;
	int i = 0;
	while (!hash_table[h1].is_empty)
	{
		h1 = h + i * h1;
		h1 = h1 % size;
		i++;
	}
	if (hash_table[h1].is_empty) {
		hash_table[h1].key = key;
		hash_table[h1].is_empty = false;
		return;
	}
	cout << "Table is full\n";
}
void print_hash_table3(hash_node* hash_table, int size) {
	for (int i = 0; i < size; i++) {
		cout << i << "\t";
		if (hash_table[i].is_empty) {
			cout << "empty\n";
		}
		else {
			cout << hash_table[i].key << "\n";
		}
	}
}
void delete_node3(hash_node* hash_table, int key, int size) {
	int h = hash_function1(key, size);
	for (int i = 0; i < size; i++)
	{
		if (hash_table[h].key == key) {
			hash_table[h].is_empty = true;
			return;
		}
		h++;
		h = h % size;
	}
	cout << "Node is doesn't exist\n";
}
void create_hash_table_from_file3(hash_node* hash_table, int size, char* filename, void (*add)(hash_node* , int , int )) {
	ifstream fin;
	fin.open(filename, ifstream::in);
	int ptr;
	while (!fin.eof()) {
		fin >> ptr;
		if (fin.eof()) break;
		add(*&hash_table, ptr, size);
	}
	fin.close();
}
void print_hash_table_to_file3(hash_node* hash_table, int size, char* filename) {
	ofstream fout;
	fout.open(filename, ofstream::out | ofstream::trunc);
	for (int i = 0; i < size; i++) {
		if (!hash_table[i].is_empty) {
			fout << hash_table[i].key << " ";
		}
	}
	fout.close();
}
void task3_menu(void (*add) (hash_node*, int, int)) {
	char filename[] = "File.txt";
	int arr[] = { 1, 99, 33, 5, 3, 37, 44, 32, 12 };
	hash_node* hash_table = new hash_node[11];
	int m = 11;
	bool quit = true;
	int num_menu;
	while (quit) {
		cout << "\n\n";
		//system("cls");
		cout << "1. Create hash table\n";
		cout << "2. Create hash table from file\n";
		cout << "3. Print hash table\n";
		cout << "4. Write hash table to file\n";
		cout << "5. Add node\n";
		cout << "6. Delete node\n";
		cout << "7. Exit\n";
		cout << "Choose oparetion: ";
		cin >> num_menu;
		switch (num_menu)
		{
		case 1:
			for (int i = 0; i < 5; i++)
			{
				add(*&hash_table, arr[i], m);
			}
			print_hash_table3(hash_table, m);
			break;
		case 2:
			create_hash_table_from_file3(*&hash_table, m, filename, add);
			print_hash_table3(hash_table, m);
			break;
		case 3:
			print_hash_table3(hash_table, m);
			break;
		case 4:
			print_hash_table_to_file3(*&hash_table, m, filename);
			cout << "Hash table is succesfully print to file\n";
			break;
		case 5:
			print_hash_table3(hash_table, m);
			cout << "Enter node: ";
			cin >> num_menu;
			add(*&hash_table, num_menu, m);
			break;
		case 6:
			print_hash_table3(hash_table, m);
			cout << "Enter node: ";
			cin >> num_menu;
			delete_node3(*&hash_table, num_menu, m);
			break;
		case 7:
			quit = false;
			cout << "\n\n";
			break;
		default:
			cout << "Ty daun probui eshche raz\n";
			break;
		}
		//system("pause");
	}
}
void task3_help_menu() {
	bool quit = true;
	int num_menu;
	while (quit) {
		//system("cls");
		cout << "1. Use linear algorithm\n";
		cout << "2. Use quadratic algorithm\n";
		cout << "3. Use double hashing algorithm\n";
		cout << "4. Exit\n";
		cout << "Choose oparetion: ";
		cin >> num_menu;
		switch (num_menu)
		{
		case 1:
			task3_menu(add_linar);
			break;
		case 2:
			task3_menu(add_square);
			break;
		case 3:
			task3_menu(add_double);
			break;
		case 4:
			quit = false;
			break;
		default:
			cout << "Ty daun probui eshche raz\n";
			break;
		}
	}
}