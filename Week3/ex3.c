#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node *next;
};

void print_list(struct Node *node) {
	while(node != NULL) {
		printf("%d ", node->value);
		node = node->next;
	}
	printf("\n");
}

void insert_node(struct Node *node, int value) {
	struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->value = value;
	newNode->next = node->next;
	node->next = newNode;
}

void delete_node(struct Node *head, struct Node *node) {
	while(head != NULL) {
		if (head->next == node) {
			head->next = node->next;
			break;
		}
		head = head->next;
	}
}

int main(void) {
	struct Node *head = NULL;
	head = (struct Node*)malloc(sizeof(struct Node));
	struct Node *second = NULL;
	second = (struct Node*)malloc(sizeof(struct Node));
	struct Node *third = NULL;
	third = (struct Node*)malloc(sizeof(struct Node));
	head->value = 1;
	head->next = second;
	second->value = 2;
	second->next = third;
	third->value = 3;
	printf("INITIAL LIST:\n");
	print_list(head);
	printf("INSERT 4 AFTER 2:\n");
	insert_node(second, 4);
	print_list(head);
	printf("INSERT 5 AFTER 3:\n");
	insert_node(third, 5);
	print_list(head);
	printf("DELETE 3:\n");
	delete_node(head, third);
	print_list(head);
} 
