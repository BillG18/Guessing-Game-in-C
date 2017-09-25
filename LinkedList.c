/*
 * LinkedList.c
 *
 *  Created on: Mar 14, 2016
 *      Author: Billy
 */


#include <stdio.h>

typedef struct Node_struct{

	struct Node *next;

	int data;


}Node;

Node* Node1 = NULL;
	Node* Node2 = NULL;
	Node1 = (Node*)malloc(sizeof(Node));
	Node1->data= 5;

	Node2 = (Node*)malloc(sizeof(Node));
	Node2->data = 7;
	Node1->next = Node2;

int addNode(data){
	Node* NewNode = NULL;
	NewNode = (Node*)malloc(sizeof(Node));
	NewNode->data = data;
	NewNode->next = Node1;
	return 0;
}

int removeNode(){
	free(*Node);

}

int main(){
	Node* Node1 = NULL;
	Node* Node2 = NULL;
	Node1 = (Node*)malloc(sizeof(Node));
	Node1->data= 5;

	Node2 = (Node*)malloc(sizeof(Node));
	Node2->data = 7;
	Node1->next = Node2;
	printf("%d and %d", Node1->data, Node2->data);

	return 0;
}
