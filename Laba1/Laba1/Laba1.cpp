#include"Laba1.h"

int main() {
	int num;
	bool quit = true;
	while (quit) {
		system("cls");
		cout << "1. Single list\n";
		cout << "2. Double list\n";
		cout << "3. Exit\n";
		cout << "Choose the type of list: ";
		cin >> num;
		system("cls");
		if (num == 1) {
			single_menu();
		}
		else {
			if (num == 2) {
				double_menu();
			}
			else quit = false;
		}
	}
	return 0;
}