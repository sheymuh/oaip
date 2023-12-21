#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node* next;
};

struct Node* first = NULL;

void printList() {
	struct Node* ptr = first;
	while (ptr != NULL) {
		printf("(%d)->", ptr->data);
		ptr = ptr->next;
	}
	printf("NULL\n");
}

void addToHead(int value) {
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

	newNode->next = first;
	newNode->data = value;

	first = newNode;
}




int deleteFromHead() {
	int value = first->data;
	
	struct Node* delNode = first;
	first = first->next;
	free(delNode);

	return value;
}

int contains(int value) {
	struct Node* ptr = first;
	while (ptr != NULL) {
		if (ptr->data == value) return 1;
		ptr = ptr->next;
	}
	return 0;
}

void clearList() {
	while (first != NULL) {
		struct Node* delNode = first;
		first = first->next;
		free(delNode);
	}
}

int sum() {
	struct Node* sumNode = first;
	int s = 0;
	while (sumNode != NULL) {
		s += sumNode->data;
		sumNode = sumNode->next;
	}
	return s;
}

int evensCount() {
	struct Node* ptr = first;
	int counter = 0;
	while (ptr != NULL) {
		if (ptr->data % 2 == 0) counter++;
		ptr = ptr->next;
	}
	return counter;
}

void oddsX10() {
	struct Node* ptr = first;
	while (ptr != NULL) {
		if (ptr->data % 2 != 0) ptr->data *= 10;
		ptr = ptr->next;
	}

}

void elementIx100(int i) {
	struct Node* ptr = first;
	for (int index = 0; index < i; index++)
		ptr = ptr->next;
	ptr->data *= 100;
}

void elementsLeftIx10(int i) {
	struct Node* ptr = first;
	for (int index = 0; index < i; index++) {
		ptr->data *= 10;
		ptr = ptr->next;
	}
}

void elementsRightIx10(int i) {
	struct Node* ptr = first;
	int index = 0;
	while (ptr != NULL) {
		if (index > i)
			ptr->data *= 10;
		ptr = ptr->next;
		index++;
	}
}

void printReverse(struct Node* ptr = first) {
	if (ptr != NULL) {
		printReverse(ptr->next);
	}
	if (ptr == NULL)
		printf("NULL");
	else
		printf("<-(%d)", ptr->data);
}

void main() {
	printList();
	// ÇÀÄÀ×À 1
	//addToHead(400);
	//addToHead(300);
	//addToHead(200);
	//addToHead(100);
	//printList();

	//printf("contains(100) = %d\n", contains(100));
	//printf("contains(150) = %d\n", contains(150));
	//printf("contains(200) = %d\n", contains(200));

	//clearList();
	//printList();

	//printf("contains(100) = %d\n", contains(100));
	//printf("contains(150) = %d\n", contains(150));
	//printf("contains(200) = %d\n", contains(200));

	addToHead(1);
	addToHead(3);
	addToHead(6);
	addToHead(8);
	printList();

	// ÇÀÄÀ×À 2
	//printf("sum = %d\n", sum());

	//clearList();
	//printList();
	//printf("sum = %d\n", sum());

	// ÇÀÄÀ×À 3
	//printf("even numbers = %d\n", evensCount());

	//clearList();
	//printList();
	//printf("even numbers = %d\n", evensCount());

	// ÇÀÄÀ×À 4
	//oddsX10();
	//printList();

	//clearList();
	//printList();

	// ÇÀÄÀ×À 5
	//elementIx100(0);
	//printList();

	//elementIx100(2);
	//printList();

	//elementIx100(0);
	//printList();

	// ÇÀÄÀ×À 6
	//elementsLeftIx10(1);
	//printList();

	//elementsLeftIx10(2);
	//printList();

	//elementsLeftIx10(4);
	//printList();

	// ÇÀÄÀ×À 7*
	//elementsRightIx10(1);
	//printList();

	//elementsRightIx10(2);
	//printList();

	//elementsRightIx10(4);
	//printList();

	// ÇÀÄÀ×À 9**
	printReverse();
	printf("\n");
	printList();
}
