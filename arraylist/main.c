#include <stdio.h>

#define MAX_LIST_SIZE 10

typedef int element;

typedef struct {
	element array[MAX_LIST_SIZE];
	int size;
} ArrayListType;

void error(char* message) {
	fprintf(stderr, "%s\n", message);
	return;
}

void init(ArrayListType* L) {
	L->size = 0;
}

int is_empty(ArrayListType* L) {
	return L->size == 0;
}

int is_full(ArrayListType* L) {
	return L->size == MAX_LIST_SIZE;
}

element get_entry(ArrayListType* L, int pos) {
	if (pos < 0 || pos >= L->size)
		error("Position Error!");
	return L->array[pos];
}

void print_list(ArrayListType* L) {
	int i, count = 0;
	for (i = 0; i < L->size; i++)
		printf("%d->", L->array[i]);
	printf("\n");
}

void insert_last(ArrayListType* L, element item) {
	if (L->size >= MAX_LIST_SIZE) {
		error("List Overflow!");
	}
	L->array[L->size++] = item;
}

void insert(ArrayListType* L, int pos, element item) {
	int count = 0;
	if (!is_full(L) && (pos >= 0) && (pos <= L->size)) {
		for (int i = (L->size - 1); i >= pos; i--) {
			L->array[i + 1] = L->array[i];
			count++;
		}
		printf("\nMove: %d\n", count);
		L->array[pos] = item;
		L->size++;
	}
}

element delete(ArrayListType* L, int pos) {
	element item;
	int count = 0;
	if (pos < 0 || pos >= L->size)
		error("Position Error!");
	item = L->array[pos];
	for (int i = pos; i < (L->size - 1); i++) {
		L->array[i] = L->array[i + 1];
		count++;
	}
	printf("\nMove: %d\n", count);
	L->size--;
	printf("Deleted: %d\n", item);
	return item;
}

void print_menu(void) {
	printf("\nMenu\n");
	printf("(1) Insert\n");
	printf("(2) Delete\n");
	printf("(3) Print\n");
	printf("(0) Exit\n");
	printf("Enter the menu: ");
}

int main() {
	ArrayListType list;
	int pos;
	element num;
	int menu;

	init(&list);

	while (1) {
		print_menu();
		scanf_s("%d", &menu);

		switch (menu) {
		case 1:
			while (1) {
				printf("Enter the number and position: ");
				scanf_s("%d %d", &num, &pos);
				if (pos > list.size)
					printf("List size is %d, please enter again.\n\n", list.size);

				else
					break;
			}
			insert(&list, pos, num);
			break;

		case 2:
			if (is_empty(&list)) {
				error("List is empty");
				break;
			}
			printf("Enter the position: ");
			scanf_s("%d", &pos);
			delete(&list, pos);
			break;

		case 3:
			print_list(&list);
			break;

		case 0:
			printf("Exit the program.\n");
			return 0;

		default:
			printf("Invalid Menu. Please seclet again.\n");
			break;
		}
	}

	return 0;
}
