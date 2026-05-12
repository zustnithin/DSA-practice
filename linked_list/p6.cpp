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
Node* reverseLL(Node* head){
    Node* prev=nullptr;
    Node* temp=head;
    Node* front;
    while(temp){
        front=temp->next;
        temp->next=prev;
        prev=temp;
        temp=front;

    }
    return prev;
}
Node* reverseLLusingRecursion(Node* head){
    if(head==nullptr || head->next==nullptr) return head;
    Node* newHead=reverseLLusingRecursion(head->next);
    Node* front=head->next;
    front->next=head;
    head->next=nullptr;
    return newHead;
}
bool isPalindrome(Node* head){
    if(head==nullptr || head->next==nullptr) return true;
    Node* slow=head;
    Node* fast=head;
    Node* first=head;
    Node* newHead;
    while(1){
        slow=slow->next;
        fast=fast->next->next;
        if(fast==nullptr || fast->next==nullptr){
            newHead=reverseLL(slow);
            break;
        }
    }
    while(newHead){
        if(first->data!=newHead->data){
            return false;
        }
        first=first->next;
        newHead=newHead->next;
    }
    return true;
}
Node* add1(Node* head){

    Node* adder;
    Node* dummynode=new Node(0,head);
    Node* mover=dummynode;
    while(mover->next){
        if(mover->data<9){
            adder=mover;
        }
        mover=mover->next;
    }
    if(mover->data==9){
        adder->data++;
        adder=adder->next;
        while(adder){
            adder->data=0;
            adder=adder->next;
        }
    }
    else{
        mover->data++;
        return head;
    }
    return dummynode;
}
Node* findYintersection(Node* head1,Node* head2){
    Node* t1=head1;
    Node* t2=head2;
    while(t1!=t2){
        t1=t1->next;
        t2=t2->next;
        if(t1==t1) return t1;
        if(t1==nullptr){
            t1=head2;
        }
        if(t2==nullptr){
            t2=head1;
        }
        return t1;
    }
}
int main(){
    vector<int> arr={9,8};
    Node* head1=convertArr2LL(arr);
    vector<int> arr1={9,8};
    Node* head2=convertArr2LL(arr1);
    head1=findYintersection(head1,head2);
    
    
    
    
}