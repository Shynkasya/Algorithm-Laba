#include"Laba2.h"

void create_deque(deque* list, int n) {
	if (n <= 0) return;
	deque_node* ptr;
	ptr = new deque_node;
	cout << "Enter element: ";
	cin >> ptr->data;
	ptr->next = NULL;
	list->begin = ptr;
	list->end = ptr;
	n--;
	for (int i = 0; i < n; i++) {
		ptr = new deque_node;
		cout << "Enter element: ";
		cin >> ptr->data;
		list->begin->prev = ptr;
		ptr->next = list->begin;
		list->begin = ptr;
		list->begin->prev = NULL;
	}
}
void create_deque_from_file(deque* list, char* filename) {
	ifstream fin;
	short data;
	fin.open(filename, ifstream::in);
	deque_node* ptr;
	ptr = new deque_node;
	fin >> ptr->data;
	ptr->next = NULL;
	list->begin = ptr;
	list->end = ptr;
	while (!fin.eof()) {
		ptr = new deque_node;
		fin >> ptr->data;
		if (fin.eof()) {
			fin.close();
			return;
		}
		list->begin->prev = ptr;
		ptr->next = list->begin;
		list->begin = ptr;
		list->begin->prev = NULL;
	}
	fin.close();
}
void print_deque(deque list) {
	if (list.end == NULL || list.begin == NULL) {
		cout << "Deque is doesn't exist\n";
		return;
	}
	while (list.begin->next != NULL) {
		cout << list.begin->data << " <-> ";
		list.begin = list.begin->next;
	}
	cout << list.begin->data;
}
void print_deque_to_file(deque list, char* filename) {
	if (list.end == NULL || list.begin == NULL) {
		cout << "Deque is doesn't exist\n";
		return;
	}
	ofstream fout;
	fout.open(filename, ofstream::out | ofstream::trunc);
	while (list.begin->next != NULL) {
		fout << list.begin->data << " ";
		list.begin = list.begin->next;
	}
	fout << list.begin->data;
	cout << "Data is seccesfully loaded to file\n";
	fout.close();
}
void delete_deque(deque* list) {
	if (list->end == NULL || list->begin == NULL) return;
	deque_node* ptr;
	while (list->end != list->begin) {
		ptr = list->end;
		list->end = list->end->prev;
		delete ptr;
	}
	delete list->end;
	list->end = NULL;
	list->begin = NULL;
}
void pop_element_to_deque_begin(deque* list, short data) {
	deque_node* ptr;
	ptr = new deque_node;
	ptr->data = data;
	if (list->begin == NULL) {
		ptr->next = NULL;
		ptr->prev = NULL;
		list->begin = ptr;
		list->end = ptr;
		return;
	}
	list->begin->prev = ptr;
	ptr->next = list->begin;
	list->begin = ptr;
	list->begin->prev = NULL;
}
void pop_element_to_deque_end(deque* list, short data) {
	deque_node* ptr;
	ptr = new deque_node;
	ptr->data = data;
	if (list->begin == NULL) {
		ptr->next = NULL;
		ptr->prev = NULL;
		list->begin = ptr;
		list->end = ptr;
		return;
	}
	list->end->next = ptr;
	ptr->prev = list->end;
	list->end = ptr;
	list->end->next = NULL;
}
short read_deque_last_element(deque list) {
	return list.end->data;
}
bool is_empty_deque(deque list) {
	if (list.begin != NULL) return false;
	return true;
}




void deque_menu() {
	char filename[] = "File.txt";
	deque list;
	list.begin = NULL;
	list.end = NULL;
	short data;
	bool quit = true;
	int num_menu;
	while (quit) {
		system("cls");
		cout << "1. Create deque\n";
		cout << "2. Create deque from file\n";
		cout << "3. Print deque\n";
		cout << "4. Write deque to file\n";
		cout << "5. Checking emptiness of deque\n";
		cout << "6. Add element to begin of deque\n";
		cout << "7. Add element to end of deque\n";
		cout << "8. Read the last element of deque\n";
		cout << "9. Exit\n";
		cout << "Choose oparetion: ";
		cin >> num_menu;
		switch (num_menu)
		{
		case 1:
			delete_deque(&list);
			cout << "Enter the quantity of element: ";
			cin >> num_menu;
			create_deque(&list, num_menu);
			if(is_empty_deque(list)) cout << "Deque: ";
			print_deque(list);
			cout << endl;
			break;
		case 2:
			delete_deque(&list);
			create_deque_from_file(&list, filename);
			if (is_empty_deque(list)) cout << "Deque: ";
			print_deque(list);
			cout << endl;
			break;
		case 3:
			if (is_empty_deque(list)) cout << "Deque: ";
			print_deque(list);
			cout << endl;
			break;
		case 4:
			print_deque_to_file(list, filename);
			cout << "Deque is sucsessfully loaded to the file\n";
			break;
		case 5:
			if (is_empty_deque(list)) {
				cout << "List is empty\n";
			}
			else {
				cout << "List isn't empty\n";
			}
			break;
		case 6:
			cout << "Enter data: ";
			cin >> data;
			if (is_empty_deque(list)) cout << "Deque before: ";
			print_deque(list);
			cout << endl;
			pop_element_to_deque_begin(&list, data);
			cout << "Deque after:  ";
			print_deque(list);
			cout << endl;
			break;
		case 7:
			cout << "Enter data: ";
			cin >> data;
			if (is_empty_deque(list)) cout << "Deque before: ";
			print_deque(list);
			cout << endl;
			pop_element_to_deque_end(&list, data);
			cout << "Deque after:  ";
			print_deque(list);
			cout << endl;
			break;
		case 8:
			if (is_empty_deque(list)) {
				cout << "List is empty\n";
			}
			else {
				cout << "The last element of deque is " << read_deque_last_element(list) << endl;
			}
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