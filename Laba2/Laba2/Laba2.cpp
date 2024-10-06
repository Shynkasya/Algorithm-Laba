#include<iostream>
using namespace std;
struct stack {
	short data;
	stack* link;
};
void push_stack(short data, stack** Top_Stack);
void reverse_stack(stack** top_stack);
void make_stack(stack** Top_Stack, int n) {
	if (n > 0) {
		short tmp;
		cout << "Enter element: ";
		cin >> tmp;
		push_stack(tmp, *(&Top_Stack));
		make_stack(Top_Stack, n - 1);
	}
}
void push_stack(short data, stack** Top_Stack) {
	stack* ptr = new stack;
	ptr->data = data;
	ptr->link = *Top_Stack;
	*Top_Stack = ptr;
}
void print_stack(stack* list) {
	if (list == NULL) {
		cout << "Stack is empty\n";
		return;
	}
	cout << "Stack:\n";
	while (list->link != NULL) {
		cout << "    " << list->data << "\n";
		list = list->link;
	}
	cout << "    " << list->data;
}
void pop_element(stack** top_stack) {
	stack* ptr;
	ptr = *top_stack;
	*top_stack = (*top_stack)->link;
	delete ptr;
}
//void swap_elements(stack** Top_Stack) {
//	short tmp = (*Top_Stack)->data;
//	stack* second_stack = NULL;
//	while ((*Top_Stack) != NULL) {
//		push_stack((*Top_Stack)->data, &second_stack);
//		pop_element(*(&Top_Stack));
//	}
//	push_stack(tmp, *(&Top_Stack));
//	tmp = second_stack->data;
//	pop_element(&second_stack);
//	while (second_stack->link != NULL) {
//		push_stack(second_stack->data, *(&Top_Stack));
//		pop_element(&second_stack);
//	}
//	pop_element(&second_stack);
//	push_stack(tmp, *(&Top_Stack));
//}
void swap_elements(stack** Top_Stack) {
	short tmp = (*Top_Stack)->data;
	short tmp1;
	reverse_stack(*(&Top_Stack));
	tmp1 = (*Top_Stack)->data;
	(*Top_Stack)->data = tmp;
	reverse_stack(*(&Top_Stack));
	(*Top_Stack)->data = tmp1;
}
void reverse_stack(stack** top_stack) {
	stack* second_stack = NULL;
	while ((*top_stack) != NULL) {
		push_stack((*top_stack)->data, &second_stack);
		pop_element(*(&top_stack));
	}
	*top_stack = second_stack;
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
			//delete_list(&list);
			cout << "Enter the quantity of element: ";
			cin >> num_menu;
			make_stack(&list, num_menu);
			print_stack(list);
			cout << endl;
			break;
		/*case 2:
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
			break;*/
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

int main() {
	stack* list = NULL;
	bool quit = true;
	short data;
	int num_menu;
	cout << "Enter the quantity of element: ";
	cin >> num_menu;
	make_stack(&list, num_menu);
	print_stack(list);
	cout << endl;
	swap_elements(&list);
	print_stack(list);
	return 0;
}