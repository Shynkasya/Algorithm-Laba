#include "Laba2.h"

void make_stack(stack** Top_Stack, int n) {
	if (n > 0) {
		short tmp;
		cout << "Enter element: ";
		cin >> tmp;
		push_stack(tmp, *(&Top_Stack));
		make_stack(Top_Stack, n - 1);
	}
}
void read_stack_from_file(stack** list, char* filename) {
	ifstream fin;
	short data;
	fin.open(filename, ifstream::in);
	while (!fin.eof()) {
		fin >> data;
		push_stack(data, *(&list));
	}
	fin.close();
}
void push_stack(short data, stack** Top_Stack) {
	stack* ptr = new stack;
	ptr->data = data;
	ptr->link = *Top_Stack;
	*Top_Stack = ptr;
}
void delete_stack(stack** top_stack) {
	while ((*top_stack) != NULL) {
		pop_element(*(&top_stack));
	}
}
void print_stack(stack* list) {
	if (list == NULL) {
		cout << "Stack is empty\n";
		return;
	}
	cout << "Stack:\n";
	while (list->link != NULL) {
		cout << list->data << " ";
		list = list->link;
	}
	cout << list->data;
}
void print_stack_to_file(stack* list, char* filename) {
	if (list == NULL) {
		return;
	}
	ofstream fout;
	fout.open(filename, ofstream::out | ofstream::trunc);
	while (list != NULL) {
		fout << list->data << " ";
		list = list->link;
	}
	fout.close();
}
void pop_element(stack** top_stack) {
	stack* ptr;
	ptr = *top_stack;
	*top_stack = (*top_stack)->link;
	delete ptr;
}




void swap_elements(stack** Top_Stack) {
	if ((*Top_Stack) == NULL) return;
	short tmp = (*Top_Stack)->data;
	short tmp1;
	reverse_stack(*(&Top_Stack));
	tmp1 = (*Top_Stack)->data;
	(*Top_Stack)->data = tmp;
	reverse_stack(*(&Top_Stack));
	(*Top_Stack)->data = tmp1;
}
void reverse_stack(stack** top_stack) {
	if ((*top_stack) == NULL) return;
	stack* second_stack = NULL;
	while ((*top_stack) != NULL) {
		push_stack((*top_stack)->data, &second_stack);
		pop_element(*(&top_stack));
	}
	*top_stack = second_stack;
}
void delete_elements(stack** top_stack) {
	if ((*top_stack) == NULL) return;
	stack* second_stack = NULL;
	while ((*top_stack) != NULL) {
		push_stack((*top_stack)->data, &second_stack);
		pop_element(*(&top_stack));
		if ((*top_stack) != NULL) pop_element(*(&top_stack));
	}
	reverse_stack(&second_stack);
	*top_stack = second_stack;
}
void max_element(stack** top_stack) {
	if ((*top_stack) == NULL) return;
	stack* second_stack = NULL;
	short max = (*top_stack)->data;
	while ((*top_stack) != NULL) {
		push_stack((*top_stack)->data, &second_stack);
		if ((*top_stack)->data > max) max = (*top_stack)->data;
		pop_element(*(&top_stack));
	}
	while (second_stack != NULL) {
		push_stack(second_stack->data, *(&top_stack));
		if (second_stack->data == max) push_stack(0, *(&top_stack));
		pop_element(&second_stack);
	}
}
void min_element(stack** top_stack) {
	if ((*top_stack) == NULL) return;
	stack* second_stack = NULL;
	short min = (*top_stack)->data;
	while ((*top_stack) != NULL) {
		push_stack((*top_stack)->data, &second_stack);
		if ((*top_stack)->data < min) min = (*top_stack)->data;
		pop_element(*(&top_stack));
	}
	while (second_stack != NULL) {
		if (second_stack->data != min) push_stack(second_stack->data, *(&top_stack));
		pop_element(&second_stack);
	}
}
void delete_except_first(stack** top_stack) {
	if ((*top_stack) == NULL) return;
	while ((*top_stack)->link != NULL) {
		pop_element(*(&top_stack));
	}
}
void delete_except_last(stack** top_stack) {
	if ((*top_stack) == NULL) return;
	short tmp = (*top_stack)->data;
	while ((*top_stack) != NULL) {
		pop_element(*(&top_stack));
	}
	push_stack(tmp, *(&top_stack));
}


void stack_menu() {
	char filename[] = "File.txt";
	stack* list = NULL;
	bool quit = true;
	short data;
	int num_menu;
	while (quit) {
		system("cls");
		cout << "1. Create stack\n";
		cout << "2. Create stack from file\n";
		cout << "3. Print stack\n";
		cout << "4. Write stack to file\n";
		cout << "5. Swap first and last element\n";
		cout << "6. Reverse stack\n";
		cout << "7. Delete every second element of the stack\n";
		cout << "8. Place zero behind maximum element\n";
		cout << "9. Replace manimum element\n";
		cout << "10. Delete stack except the first element\n";
		cout << "11. Delete stack except the last element\n";
		cout << "12. Exit\n";
		cout << "Choose oparetion: ";
		cin >> num_menu;
		switch (num_menu)
		{
		case 1:
			delete_stack(&list);
			cout << "Enter the quantity of element: ";
			cin >> num_menu;
			make_stack(&list, num_menu);
			print_stack(list);
			cout << endl;
			break;
		case 2:
			delete_stack(&list);
			read_stack_from_file(&list, filename);
			print_stack(list);
			cout << endl;
			break;
		case 3:
			print_stack(list);
			cout << endl;
			break;
		case 4:
			print_stack_to_file(list, filename);
			cout << "Stack is sucsessfully loaded to the file\n";
			break;
		case 5:
			print_stack(list);
			swap_elements(&list);
			cout << "\nAfter swap\n";
			print_stack(list);
			cout << endl;
			break;
		case 6:
			print_stack(list);
			reverse_stack(&list);
			cout << "\nAfter reverse\n";
			print_stack(list);
			cout << endl;
			break;
		case 7:
			print_stack(list);
			delete_elements(&list);
			cout << "\nAfter deleting\n";
			print_stack(list);
			cout << endl;
			break;
		case 8:
			print_stack(list);
			max_element(&list);
			cout << "\nAfter function works\n";
			print_stack(list);
			cout << endl;
			break;
		case 9:
			print_stack(list);
			min_element(&list);
			cout << "\nAfter function works\n";
			print_stack(list);
			cout << endl;
			break;
		case 10:
			print_stack(list);
			delete_except_first(&list);
			cout << "\nAfter deleting\n";
			print_stack(list);
			cout << endl;
			break;
		case 11:
			print_stack(list);
			delete_except_last(&list);
			cout << "\nAfter deleting\n";
			print_stack(list);
			cout << endl;
			break;
		case 12:
			quit = false;
			break;
		default:
			cout << "Ty daun probui eshche raz\n";
			break;
		}
		system("pause");
	}
}


