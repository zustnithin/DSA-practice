#include <iostream>
using namespace std;
class Node{
public:
    int data;
    Node* next;
    Node(int data1,Node* next1){
        data=data1;
        next=next1;
    }
    Node(int data1){
        data=data1;
        next=nullptr;
    }
};
Node* convertArr2LL(int arr[],int n){
    if(n==0){ return nullptr;}
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i=1;i<n;i++){
        Node* temp= new Node(arr[i]);
        mover->next=temp;
        mover=temp;
    }
    return head;
}
Node* insertAtHead(Node* head,int x){
    Node* temp = new Node(x);
    temp->next=head;
    return temp;
}
int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    int x;
    cin >> x;
    Node* head=convertArr2LL(arr,n);
    head=insertAtHead(head,x);
    Node* temp=head;
    while(temp){
        cout << temp->data << " ";
        temp=temp->next;
    }
}