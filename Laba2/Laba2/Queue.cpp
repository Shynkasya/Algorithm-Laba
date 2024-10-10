#include"Laba2.h"
void create_queue(queue* list, int n) {
	if (n <= 0) return;
	queue_node* ptr;
	ptr = new queue_node;
	cout << "Enter element: ";
	cin >> ptr->data;
	ptr->prev = NULL;
	list->begin = ptr;
	list->end = ptr;
	n--;
	for (int i = 0; i < n; i++) {
		ptr = new queue_node;
		cout << "Enter element: ";
		cin >> ptr->data;
		list->begin->prev = ptr;
		list->begin = ptr;
	}
}
void create_queue_from_file(queue* list, char* filename) {
	ifstream fin;
	short data;
	fin.open(filename, ifstream::in);
	queue_node* ptr;
	ptr = new queue_node;
	fin >> ptr->data;
	ptr->prev = NULL;
	list->begin = ptr;
	list->end = ptr;
	while (!fin.eof()) {
		ptr = new queue_node;
		fin >> ptr->data;
		if (fin.eof()) break;
		list->begin->prev = ptr;
		list->begin = ptr;
	}
	fin.close();
}
void print_queue_rec(queue list) {
	if (list.end == list.begin) {
		cout << "end -> " << list.end->data << " -> ";
		return;
	}
	print_queue_rec({ list.begin, list.end->prev });
	cout << list.end->data << " -> ";
}
void print_queue(queue list) {
	if (list.end == NULL || list.begin == NULL) {
		cout << "Queue doesn't exist\n";
		return;
	}
	print_queue_rec(list);
	cout << "begin\n";
}
void print_queue_to_file(queue list, char* filename) {
	if (list.end == NULL || list.begin == NULL) {
		cout << "Queue is doesn't exist\n";
		return;
	}
	ofstream fout;
	fout.open(filename, ofstream::out | ofstream::trunc);
	while (list.end != list.begin) {
		fout << list.end->data << " ";
		list.end = list.end->prev;
	}
	fout << list.end->data << " ";
	fout.close();
}
void delete_queue(queue* list) {
	if (list->end == NULL || list->begin == NULL) return;
	queue_node* ptr;
	while (list->end != list->begin) {
		ptr = list->end;
		list->end = list->end->prev;
		delete ptr;
	}
	delete list->end;
	list->end = NULL;
	list->begin = NULL;
}
int count_queue_elements(queue list) {
	if (list.end == NULL || list.begin == NULL) return 0;
	int counter = 0;
	while (list.end != list.begin) {
		counter++;
		list.end = list.end->prev;
	}
	counter++;
	return counter;
}
double avegange_queue_elements(queue list) {
	if (list.end == NULL || list.begin == NULL) return 0;
	double counter = count_queue_elements(list);
	double sum = 0;
	while (list.end != list.begin) {
		sum += list.end->data;
		list.end = list.end->prev;
	}
	sum += list.end->data;
	return sum / counter;
}
void min_max_queue(queue list) {
	if (list.end == NULL || list.begin == NULL) {
		//cout << "Queue is doesn't exist\n";
		return;
	}
	short min = list.end->data;
	short max = list.end->data;
	while (list.end != list.begin) {
		if (list.end->data < min) min = list.end->data;
		if (list.end->data > max) max = list.end->data;
		list.end = list.end->prev;
	}
	if (list.end->data < min) min = list.end->data;
	if (list.end->data > max) max = list.end->data;
	cout << "Minimum of queue is " << min << endl;
	cout << "Maximum of queue is " << max << endl;
}
void element_before_min_queue(queue list) {
	if (list.end == NULL || list.begin == NULL) {
		//cout << "Queue is doesn't exist\n";
		return;
	}
	queue_node* end;
	end = list.end;
	short min = list.end->data;
	while (list.end != list.begin) {
		if (list.end->data < min) min = list.end->data;
		list.end = list.end->prev;
	}
	if (list.end->data < min) min = list.end->data;
	while (end->data != min) {
		end = end->prev;
	}
	if (end->prev == NULL) {
		cout << "Element before minimum doesn't exist\n";
		return;
	}
	end = end->prev;
	cout << "Element before minimum: " << end->data << "\n";
}






void queue_menu() {
	char filename[] = "File.txt";
	queue list;
	list.begin = NULL;
	list.end = NULL;
	bool quit = true;
	int num_menu;
	while (quit) {
		system("cls");
		cout << "1. Create queue\n";
		cout << "2. Create queue from file\n";
		cout << "3. Print queue\n";
		cout << "4. Write queue to file\n";
		cout << "5. Quantity of queue elements\n";
		cout << "6. Arithmetic average of queue\n";
		cout << "7. Minimum and maximum of queue\n";
		cout << "8. Element before minimum\n";
		cout << "9. Exit\n";
		cout << "Choose oparetion: ";
		cin >> num_menu;
		switch (num_menu)
		{
		case 1:
			delete_queue(&list);
			cout << "Enter the quantity of element: ";
			cin >> num_menu;
			create_queue(&list, num_menu);
			print_queue(list);
			//cout << endl;
			break;
		case 2:
			delete_queue(&list);
			create_queue_from_file(&list, filename);
			print_queue(list);
			//cout << endl;
			break;
		case 3:
			print_queue(list);
			//cout << endl;
			break;
		case 4:
			print_queue_to_file(list, filename);
			cout << "Queue is sucsessfully loaded to the file\n";
			break;
		case 5:
			print_queue(list);
			cout << "Queue have " << count_queue_elements(list) << " elements" << endl;
			break;
		case 6:
			print_queue(list);
			cout << "Arithmetic average of queue is " << avegange_queue_elements(list) << endl;
			break;
		case 7:
			print_queue(list);
			//cout << endl;
			min_max_queue(list);
			break;
		case 8:
			print_queue(list);
			//cout << endl;
			element_before_min_queue(list);
			//cout << endl;
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
