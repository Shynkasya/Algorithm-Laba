#include"Laba1.h"
void push_back(single_list** list, long long data) {
	if (*list == NULL) {
		(*list) = new single_list;
		(*list)->node = data;
		(*list)->next = NULL;
		return;
	}
	single_list* node = (*list);
	while (node->next != NULL) {
		node = node->next;
	}
	node->next = new single_list;
	node = node->next;
	node->node = data;
	node->next = NULL;
}
void create_single_list(single_list** list, int n) {
	cout << "Enter the data: ";
	long long data;
	for (int i = 0; i < n; i++) {
		cin >> data;
		push_back(&(*list), data);
	}
}
void create_single_list_from_file(single_list** list, char* filename) {
	/*if (!std::filesystem::is_empty(filename)) {
		cout << "File is empty\n";
	}*/
	ifstream fin;
	long long data;
	fin.open(filename, ifstream::in);
	while (!fin.eof()) {
		fin >> data;
		push_back(&(*list), data);
	}
	fin >> (*list)->node;
	fin.close();
}
void print_list(single_list* list) {
	if (list == NULL) {
		cout << "List is empty\n";
		return;
	}
	cout << "List: ";
	while (list->next != NULL) {
		cout << list->node << "->";
		list = list->next;
	}
	cout << list->node;
}
void print_list_to_file(single_list* list, char* filename) {
	if (list == NULL) {
		return;
	}
	ofstream fout;
	fout.open(filename, ofstream::out | ofstream::trunc);
	while (list->next != NULL) {
		fout << list->node << " ";
		list = list->next;
	}
	fout << list->node;
	fout.close();
}
void delete_list(single_list** list) {
	if ((*list) != NULL) {
		delete_list(&(*list)->next);
		delete* list;
	}
	(*list) = NULL;
}
void swap_element(single_list** list, int n) {
	if (n <= 0) {
		cout << "Invalid number\n";
		return;
	}
	if (n > list_size(*list) - 1) {
		cout << "List is too small\n";
		return;
	}
	n--;
	long long temp;
	single_list* ptr = (*list);
	for (int i = 0; i < n; i++){
		ptr = ptr->next;
	}
	temp = ptr->node;
	ptr->node = ptr->next->node;
	ptr->next->node = temp;
}
int list_size(single_list* list) {
	//if (list == NULL) return 0;
	single_list* node = list;
	int counter = 0;
	while (node != NULL) {
		node = node->next;
		counter++;
	}
	return counter;
}
void pop_element(single_list** list, int n) {
	if (n <= 0) {
		cout << "Invalid number\n";
		return;
	}
	if (n > list_size(*list) - 1) {
		cout << "List is too small\n";
		return;
	}
	if (list == NULL) return;
	if (n == 1) {
		single_list* ptr = (*list);
		(*list) = (*list)->next;
		delete ptr;
		return;
	}
	n -= 2;
	single_list* prev_ptr = (*list);
	single_list* ptr = prev_ptr->next;
	for (int i = 0; i < n; i++) {
		prev_ptr = ptr;
		ptr = ptr->next;
	}
	prev_ptr->next = ptr->next;
	delete ptr;
}



void single_menu() {
	char filename[] = "File.txt";
	single_list* list = NULL;
	bool quit = true;
	long long data;
	int num_menu;
	while (quit) {
		system("cls");
		cout << "1. Create linked list\n";
		cout << "2. Create linked list from file\n";
		cout << "3. Print linked list\n";
		cout << "4. Write linked list to file\n";
		cout << "5. Push element to back of the list\n";
		cout << "6. Pop element from list\n";
		cout << "7. Quant element in linked list\n";
		cout << "8. Swap element\n";
		cout << "9. Delete list\n";
		cout << "10. Exit\n";
		cout << "Choose oparetion: ";
		cin >> num_menu;
		switch (num_menu)
		{
		case 1:
			delete_list(&list);
			cout << "Enter the quantity of element: ";
			cin >> num_menu;
			create_single_list(&list, num_menu);
			print_list(list);
			cout << endl;
			break;
		case 2:
			delete_list(&list);
			create_single_list_from_file(&list, filename);
			print_list(list);
			cout << endl;
			break;
		case 3:
			print_list(list);
			cout << endl;
			break;
		case 4:
			print_list_to_file(list, filename);
			cout << "List is sucsessfully loaded to the file\n";
			break;
		case 5:
			print_list(list);
			cout << endl;
			cout << "Enter the data you want to enter: ";
			cin >> data;
			push_back(&list, data);
			print_list(list);
			cout << endl;
			break;
		case 6:
			print_list(list);
			cout << endl;
			cout << "Enter the number of element that you want to delete: ";
			cin >> num_menu;
			pop_element(&list, num_menu);
			print_list(list);
			cout << endl;
			break;
		case 7:
			print_list(list);
			cout << "\nList size is has " << list_size(list) << " elements" << endl;
			break;
		case 8:
			print_list(list);
			cout << endl;
			cout << "Program swap the element that you enter and next one\n";
			cout << "Enter the number that you want to swap: ";
			cin >> num_menu;
			swap_element(&list, num_menu);
			print_list(list);
			cout << endl;
			break;
		case 9:
			delete_list(&list);
			print_list(list);
			break;
		case 10:
			quit = false;
			break;
		default:
			cout << "Ty daun probui eshche raz\n";
			break;
		}
		system("pause");
	}
}