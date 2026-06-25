#include <iostream>
#include <vector>
using namespace std;
class Node{
    public:
    int data;
    Node* right;
    Node* left;

    Node(int data1,Node* l1,Node* r1){
        data=data1;
        left=l1;
        right=r1;
    }
    Node(int data1){
        data=data1;
        left=nullptr;
        right=nullptr;
    }
};
void preorder(Node* head){
    if(head==nullptr) return;
    cout << head->data << " ";
    preorder(head->left);
    preorder(head->right);

}
int main(){
    Node* root = new Node(5);
    root->left = new Node(6);
    root->right = new Node(7);
    root->left->left = new Node(6);
    preorder(root);
}