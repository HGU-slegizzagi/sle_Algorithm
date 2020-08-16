#include <iostream>

typedef struct{
	int val;
	node* head, tail;
}node;

void nodeptrswap(node* &a, node* &b){
	node* temp;
	a = temp;
	a = b;
	b = temp;
}

int main(){
	node *train = new node[];

		

	delete train;
	return 0;
}