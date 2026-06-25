#include <iostream>
#include <queue>
#include <vector>
#include <climits>
#include <stack>
#include <map>
#include <set>
#include <utility>
using namespace std;
class Node{
    public:
    int data;
    Node* right;
    Node* left;
    Node* top;

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

int main() {
    Node* root = new Node(10);

    root->left = new Node(5);
    root->right = new Node(5);

    root->left->left = new Node(1);
    root->left->right = new Node(4);

    root->right->left = new Node(2);
    root->right->right = new Node(3);

    
}