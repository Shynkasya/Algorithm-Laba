#include"Laba1.h"
void double_push_back(double_list** list, long long data) {
	if (*list == NULL) {
		(*list) = new double_list;
		(*list)->node = data;
		(*list)->next = NULL;
		(*list)->prev = NULL;
		return;
	}
	double_list* node = (*list);
	while (node->next != NULL) {
		node = node->next;
	}
	node->next = new double_list;
	node->next->prev = node;
	node = node->next;
	node->node = data;
	node->next = NULL;
}
void create_double_list(double_list** list, int n) {
	cout << "Enter the data: ";
	long long data;
	for (int i = 0; i < n; i++) {
		cin >> data;
		double_push_back(&(*list), data);
	}
}
void create_double_list_from_file(double_list** list, char* filename) {
	/*if (!std::filesystem::is_empty(filename)) {
		cout << "File is empty\n";
	}*/
	ifstream fin;
	long long data;
	fin.open(filename, ifstream::in);
	while (!fin.eof()) {
		fin >> data;
		double_push_back(&(*list), data);
	}
	//fin >> (*list)->node;
	fin.close();
}
void print_double_list(double_list* list) {
	if (list == NULL) {
		cout << "List is empty\n";
		return;
	}
	cout << "List: ";
	while (list->next != NULL) {
		cout << list->node << "<->";
		list = list->next;
	}
	cout << list->node;
}
void print_double_list_to_file(double_list* list, char* filename) {
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
void delete_double_list(double_list** list) {
	if ((*list) != NULL) {
		delete_double_list(&(*list)->next);
		delete* list;
	}
	(*list) = NULL;
}
void swap_double_element(double_list** list, int n1, int n2) {
	if (n1 <= 0 || n2 < 0) {
		cout << "Invalid number\n";
		return;
	}
	if (n1 > double_list_size(*list) || n2 > double_list_size(*list)) {
		cout << "List is too small\n";
		return;
	}
	n1--;
	n2--;
	long long temp;
	double_list* ptr1 = (*list);
	for (int i = 0; i < n1; i++) {
		ptr1 = ptr1->next;
	}
	double_list* ptr2 = (*list);
	for (int i = 0; i < n2; i++) {
		ptr2 = ptr2->next;
	}
	temp = ptr1->node;
	ptr1->node = ptr2->node;
	ptr2->node = temp;
}
int double_list_size(double_list* list) {
	//if (list == NULL) return 0;
	double_list* node = list;
	int counter = 0;
	while (node != NULL) {
		node = node->next;
		counter++;
	}
	return counter;
}
void pop_double_element(double_list** list, int n) {
	if (n <= 0) {
		cout << "Invalid number\n";
		return;
	}
	if (n > double_list_size(*list)) {
		cout << "List is too small\n";
		return;
	}
	if (list == NULL) return;
	if (n == 1) {
		double_list* ptr = (*list);
		(*list) = (*list)->next;
		(*list)->prev = NULL;
		delete ptr;
		return;
	}
	n -= 2;
	double_list* ptr = (*list)->next;
	for (int i = 0; i < n; i++) {
		ptr = ptr->next;
	}
	ptr->prev->next = ptr->next;
	delete ptr;
}
void push_double_element(double_list** list, long long data, int n) {
	n--;
	double_list* new_node = new(double_list);
	new_node->node = data;
	new_node->next = NULL;
	new_node->prev = NULL;
	if ((*list) == NULL) {
		(*list) = new_node;
		return;
	}
	if (n == 0) {
		new_node->next = (*list);
		(*list)->prev = new_node;
		(*list) = new_node;
		return;
	}
	double_list* ptr = (*list);
	for (int i = 1; i < n && ptr->next != NULL; i++) ptr = ptr->next;
	if (ptr->next != NULL)ptr->next->prev = new_node;
	new_node->next = ptr->next;
	ptr->next = new_node;
	new_node->prev = ptr;
}



void double_menu() {
	char filename[] = "File.txt";
	double_list* list = NULL;
	bool quit = true;
	long long data;
	int num_menu;
	while (quit) {
		system("cls");
		cout << "1. Create linked list\n";
		cout << "2. Create linked list from file\n";
		cout << "3. Print linked list\n";
		cout << "4. Write linked list to file\n";
		cout << "5. Push element to list\n";
		cout << "6. Pop element from list\n";
		cout << "7. Swap element\n";
		cout << "8. Delete list\n";
		cout << "9. Exit\n";
		cout << "Choose oparetion: ";
		cin >> num_menu;
		switch (num_menu)
		{
		case 1:
			delete_double_list(&list);
			cout << "Enter the quantity of element: ";
			cin >> num_menu;
			create_double_list(&list, num_menu);
			print_double_list(list);
			cout << endl;
			break;
		case 2:
			delete_double_list(&list);
			create_double_list_from_file(&list, filename);
			print_double_list(list);
			cout << endl;
			break;
		case 3:
			print_double_list(list);
			cout << endl;
			break;
		case 4:
			print_double_list_to_file(list, filename);
			cout << "List is sucsessfully loaded to the file\n";
			break;
		case 5:
			print_double_list(list);
			cout << endl;
			cout << "Enter position where you want to push: ";
			cin >> num_menu;
			cout << "Enter the data you want to enter: ";
			cin >> data;
			push_double_element(&list, data, num_menu);
			print_double_list(list);
			cout << endl;
			break;
		case 6:
			print_double_list(list);
			cout << endl;
			cout << "Enter the number of element that you want to delete: ";
			cin >> num_menu;
			pop_double_element(&list, num_menu);
			print_double_list(list);
			cout << endl;
			break;
		case 7:
			print_double_list(list);
			cout << endl;
			cout << "Enter the numbers of element that you want to swap: ";
			cin >> num_menu >> data;
			swap_double_element(&list, num_menu, (int)data);
			print_double_list(list);
			cout << endl;
			break;
		case 8:
			delete_double_list(&list);
			print_double_list(list);
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