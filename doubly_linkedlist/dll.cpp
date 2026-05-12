#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node* back;
    Node(int d1,Node* n1,Node* b1){
        data=d1;
        next=n1;
        back=b1;
    }
    Node(int d1){
        data=d1;
        next=nullptr;
        back=nullptr;
    }
};
Node* convertArr2DLL(vector<int> &arr){
    if(arr.size()==0){ return nullptr;}
    Node* head=new Node(arr[0]);
    Node* prev=head;
    for(int i=1;i<arr.size();i++){
        Node* temp=new Node(arr[i],nullptr,prev);
        prev->next=temp;
        prev=temp;
    }
    return head;
}
Node* reverseDLL(Node* head){
    Node* current=head;
    Node* last;
    while(current!=nullptr){
        last=current->back;
        current->back=current->next;
        current->next=last;
        current=current->back;
    }
    return last->back;
}
int main(){
    vector<int> arr={5,6,7};
     Node* head = convertArr2DLL(arr);
    head=reverseDLL(head);
    while(head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
}