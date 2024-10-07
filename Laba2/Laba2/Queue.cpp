#include"Laba2.h"
void create_queue(queue* list, int n) {
	if (n <= 0) return;
	queue_node* ptr;
	ptr = new queue_node;
	cout << "Enter element: ";
	cin >> ptr->data;
	//ptr->prev = NULL;
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
void print_queue_rec(queue list) {
	if (list.end == list.begin) {
		cout << "end <- " << list.end->data << " <- ";
		return;
	}
	print_queue_rec({ list.begin, list.end->prev });
	cout << list.end->data << " <- ";
}
void print_queue(queue list) {
	if (list.end == NULL || list.begin == NULL) {
		cout << "Queue is doesn't exist\n";
		return;
	}
	print_queue_rec(list);
	cout << "begin";
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
		cout << "Queue is doesn't exist\n";
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
		cout << "Queue is doesn't exist\n";
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
	end = end->prev;
	cout << "Element before minimum: " << end->data;
}