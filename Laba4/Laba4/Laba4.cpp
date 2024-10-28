#include "Laba4.h"



int main() {
	bool quit = true;
	int num_menu;
	while (quit) {
		system("cls");
		cout << "1. Task 1\n";
		cout << "2. Task 2\n";
		cout << "3. Task 3\n";
		cout << "4. Exit\n";
		cout << "Choose oparetion: ";
		cin >> num_menu;
		switch (num_menu)
		{
		case 1:
			task1_menu();
			break;
		case 2:
			task2_menu();
			break;
		case 3:
			task3_help_menu();
			break;
		case 4:
			quit = false;
			break;
		default:
			cout << "Ty daun probui eshche raz\n";
			break;
		}
		//system("pause");
	}
	return 0;
}