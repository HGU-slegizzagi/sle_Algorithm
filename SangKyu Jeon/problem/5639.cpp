#include <iostream>
using namespace std;



class Node{

    public:     
        int value;
        Node * leftNode;
        Node * rightNode;

        Node(int value){
            this -> value = value;
            this -> leftNode = NULL;
            this -> rightNode = NULL;
        }

        void Insert(Node * node){


            if(this->value > node->value){

                if(this->leftNode == NULL){
                    this -> leftNode = node;
                    return;
                }

                this->leftNode->Insert(node);
            }
            else{

                if(this->rightNode == NULL){
                    this -> rightNode = node;
                    return;
                }

                this->rightNode->Insert(node);
            }
        }
        
};

void PostOrder(Node * curNode){

    if(curNode->leftNode != NULL){
        PostOrder(curNode->leftNode);
    }
    
    if(curNode->rightNode != NULL){
        PostOrder(curNode->rightNode);
    }
    
    
    cout << curNode->value << endl;
    return;
}




int main(){

    Node * root = new Node(0);
    int temp;

    while(scanf("%d", &temp) != EOF) {
        Node * tempNode = new Node(temp);
        root->Insert(tempNode);
    }

    PostOrder(root->rightNode);
}