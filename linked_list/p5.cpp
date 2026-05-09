#include <bits/stdc++.h>
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
Node* convertArr2LL(vector<int> &arr){
    if(arr.size()==0){return nullptr;}
    Node* head=new Node(arr[0]);
    Node* mover =head;
    for(int i=1;i<arr.size();i++){
        Node* temp=new Node(arr[i]);
        mover->next=temp;
        mover=temp;
    }
    return head;
}
Node* divideEvenAndOdd(Node* head){
    if(head==nullptr || head->next==nullptr) return head;
    Node* odd = head;
    Node* even = head->next;
    Node* oddStart = head;
    Node* evenStart = head->next;
    while(even!=nullptr && even->next!=nullptr){
        odd->next=odd->next->next;
        even->next=even->next->next;
        
        odd=odd->next;
        even=even->next;
    }
    odd->next=evenStart;
    return head;
}
Node* sort012sLL(Node* head){
    Node* dummy0head=new Node(-1);
    Node* head0=dummy0head;
    Node* dummy1head=new Node(-1);
    Node* head1=dummy1head;
    Node* dummy2head=new Node(-1);
    Node* head2=dummy2head;
    Node* temp=head;
    while(temp!=nullptr){
        Node* mover=temp;
        temp=temp->next;
        if(mover->data==0){
            head0->next=mover;
            mover->next=nullptr;
            head0=head0->next;
        }
        else if(mover->data==1){
            head1->next=mover;
            mover->next=nullptr;
            head1=head1->next;
        }
        else{
            head2->next=mover;
            mover->next=nullptr;
            head2=head2->next;
        }
        
    }
    if(dummy1head->next==nullptr){
        head0->next=dummy2head->next;
    }
    else{
        head0->next=dummy1head->next;
        head1->next=dummy2head->next;
    }
    Node* newhead=dummy0head->next;
    dummy0head->next=nullptr;
    dummy1head->next=nullptr;
    dummy2head->next=nullptr;
    delete dummy0head;
    delete dummy1head;
    delete dummy2head; 
    return newhead;
}
int main(){
    vector<int> arr={0,0,2,2,0};
    Node* head=convertArr2LL(arr);
    head=sort012sLL(head);
    Node* temp=head;
    while(temp){
        cout << temp->data << " ";
        temp=temp->next;
    }
}