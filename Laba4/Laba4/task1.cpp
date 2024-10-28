#include "Laba4.h"
int hash_function(int k, int m) {
	double y, n;
	y = modf(A * k, &n);
	return (int)(m * y);
}
struct hash_node {
	int key;
	bool is_empty = true;
};
void add(hash_node* hash_table, int key, int size) {
	int h = hash_function(key, size);
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
void print_hash_table(hash_node* hash_table, int size) {
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
void delete_node(hash_node* hash_table, int key, int size) {
	int h = hash_function(key, size);
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
void create_hash_table_from_file(hash_node* hash_table, int size, char* filename) {
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
void print_hash_table_to_file(hash_node* hash_table, int size, char* filename) {
	ofstream fout;
	fout.open(filename, ofstream::out | ofstream::trunc);
	for (int i = 0; i < size; i++) {
		if (!hash_table[i].is_empty) {
			fout << hash_table[i].key << " ";
		}
	}
	fout.close();
}
void task1_menu() {
	char filename[] = "File.txt";
	int arr[] = { 21, 22, 23, 24, 25 };
	hash_node* hash_table = new hash_node[20];
	int m = 20;
	bool quit = true;
	int num_menu;
	while (quit) {
		system("cls");
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
			print_hash_table(hash_table, m);
			break;
		case 2:
			create_hash_table_from_file(*&hash_table, m, filename);
			print_hash_table(hash_table, m);
			break;
		case 3:
			print_hash_table(hash_table, m);
			break;
		case 4:
			print_hash_table_to_file(*&hash_table, m, filename);
			cout << "Hash table is succesfully print to file\n";
			break;
		case 5:
			print_hash_table(hash_table, m);
			cout << "Enter node: ";
			cin >> num_menu;
			add(*&hash_table, num_menu, m);
			break;
		case 6:
			print_hash_table(hash_table, m);
			cout << "Enter node: ";
			cin >> num_menu;
			delete_node(*&hash_table, num_menu, m);
			break;
		case 7:
			quit = false;
			break;
		default:
			cout << "Ty daun probui eshche raz\n";
			break;
		}
		system("pause");
	}
}