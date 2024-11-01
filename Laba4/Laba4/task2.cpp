#include "Laba4.h"
struct hash_node_2 {
	int key;
	bool is_empty = true;
	hash_node_2* next = NULL;
};
int hash_function_2(int k, int m) {
	return k % m;
}
void add_2(hash_node_2* hash_table, int key, int size) {
	int h = hash_function_2(key, size);
	if (hash_table[h].is_empty) {
		hash_table[h].key = key;
		hash_table[h].is_empty = false;
		return;
	}
	else {
		hash_node_2* ptr;
		ptr = &hash_table[h];
		while (ptr->next != NULL) {
			ptr = ptr->next;
		}
		ptr->next = new hash_node_2;
		ptr->next->key = key;
	}
}
void print_hash_table_2(hash_node_2* hash_table, int size) {
	for (int i = 0; i < size; i++) {
		cout << i << "\t";
		if (hash_table[i].is_empty) {
			cout << "empty\n";
		}
		else {
			hash_node_2* ptr;
			ptr = &hash_table[i];
			cout << hash_table[i].key;
			while (ptr->next != NULL) {
				ptr = ptr->next;
				cout << " -> " << ptr->key;
			}
			cout << "\n";
		}
	}
}
int search_node_2(hash_node_2* hash_table, int key, int size) {
	int h = hash_function_2(key, size);
	if (hash_table[h].key == key) {
		return h;
	}
	else {
		hash_node_2* ptr;
		ptr = &hash_table[h];
		int counter = 0;
		while (ptr != NULL && ptr->key != key) {
			ptr = ptr->next;
			counter++;
		}
		if (ptr == NULL) { 
			cout << "Table haven't got such element\n";
			return -1; 
		} else return counter;
	}
}
void delete_node_2(hash_node_2* hash_table, int key, int size) {
	int h = hash_function_2(key, size);
	hash_node_2* ptr;
	ptr = &hash_table[h];
	if (ptr->next == NULL) {
		if (ptr->key == key) {
			ptr->is_empty = true;
			return;
		}
		else {
			cout << "Node is doesn't exist\n";
			return;
		}
	}
	if (ptr->key == key) {
		ptr->key = ptr->next->key;
		ptr = ptr->next;
		hash_table[h].next = ptr->next;
		delete ptr;
		return;
	}
	hash_node_2* tmp = NULL;
	while(ptr != NULL)
	{
		if (ptr->key == key) {
			tmp->next = ptr->next;
			delete ptr;
			return;
		}
		tmp = ptr;
		ptr = ptr->next;
	}
	cout << "Node is doesn't exist\n";
}
void create_hash_table_from_file_2(hash_node_2* hash_table, int size, char* filename) {
	ifstream fin;
	fin.open(filename, ifstream::in);
	int ptr;
	while (!fin.eof()) {
		fin >> ptr;
		if (fin.eof()) break;
		add_2(*&hash_table, ptr, size);
	}
	fin.close();
}
void print_hash_table_to_file_2(hash_node_2* hash_table, int size, char* filename) {
	ofstream fout;
	fout.open(filename, ofstream::out | ofstream::trunc);
	for (int i = 0; i < size; i++) {
		if (!hash_table[i].is_empty) {
			hash_node_2* ptr;
			ptr = &hash_table[i];
			fout << hash_table[i].key << " ";
			while (ptr->next != NULL) {
				ptr = ptr->next;
				fout << ptr->key << " ";
			}
		}
	}
	fout.close();
}
void task2_menu() {
	char filename[] = "File.txt";
	int arr[] = { 1, 99, 33, 5, 3, 37, 44, 32, 12 };
	hash_node_2* hash_table = new hash_node_2[9];
	int m = 9;
	int h;
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
		cout << "7. Search node\n";
		cout << "8. Exit\n";
		cout << "Choose oparetion: ";
		cin >> num_menu;
		switch (num_menu)
		{
		case 1:
			for (int i = 0; i < 9; i++)
			{
				add_2(*&hash_table, arr[i], m);
			}
			print_hash_table_2(hash_table, m);
			break;
		case 2:
			create_hash_table_from_file_2(*&hash_table, m, filename);
			print_hash_table_2(hash_table, m);
			break;
		case 3:
			print_hash_table_2(hash_table, m);
			break;
		case 4:
			print_hash_table_to_file_2(*&hash_table, m, filename);
			cout << "Hash table is succesfully print to file\n";
			break;
		case 5:
			print_hash_table_2(hash_table, m);
			cout << "Enter node: ";
			cin >> num_menu;
			add_2(*&hash_table, num_menu, m);
			break;
		case 6:
			print_hash_table_2(hash_table, m);
			cout << "Enter node: ";
			cin >> num_menu;
			delete_node_2(*&hash_table, num_menu, m);
			break;
		case 7:
			cout << "Enter key of element: ";
			cin >> num_menu;
			h = hash_function_2(num_menu, m);
			num_menu = search_node_2(hash_table, num_menu, m);
			if (num_menu != -1) {
				cout << "Your element is on " << h << " position on table and in " << num_menu << " position on list\n";
			}
			break;
		case 8:
			quit = false;
			break;
		default:
			cout << "Ty daun probui eshche raz\n";
			break;
		}
		system("pause");
	}
}