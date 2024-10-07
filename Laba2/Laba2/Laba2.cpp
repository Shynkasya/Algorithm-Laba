#include"Laba2.h"


int main() {
	queue list;
	list.begin = NULL;
	list.end = NULL;
	element_before_min_queue(list);
	create_queue(&list, 5);
	print_queue(list);
	delete_queue(&list);
	print_queue(list);
	return 0;
}