#include"Laba2.h"

int main() {
	bool quit = true;
	int num_menu;
	while (quit) {
		system("cls");
		cout << "1. Stack\n";
		cout << "2. Queue\n";
		cout << "3. Deque\n";
		cout << "4. Exit\n";
		cout << "Choose oparetion: ";
		cin >> num_menu;
		system("cls");
		switch (num_menu)
		{
		case 1:
			stack_menu();
			break;
		case 2:
			queue_menu();
			break;
		case 3:
			deque_menu();
			break;
		case 4:
			quit = false;
			break;
		default:
			cout << "Ty daun probui eshche raz\n";
			break;
		}
	}
	return 0;
} 