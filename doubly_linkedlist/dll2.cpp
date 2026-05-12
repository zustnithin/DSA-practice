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
Node* sumOf2LL(Node* head1,Node* head2){
    Node* t1=head1;
    Node* t2=head2;
    Node* dummyHead=new Node(-1);
    Node* curr=dummyHead;
    
    int carry=0;
    while(t1!=nullptr || t2!=nullptr){
        int sum=carry;
        if(t1){
            sum=sum+t1->data;
            t1=t1->next;
        }
        if(t2){
            sum=sum+t2->data;
            t2=t2->next;
        }
        Node* newNode=new Node((sum)%10);
        carry=sum/10;
        curr->next=newNode;
        curr=curr->next;
    }
    if(carry){
        curr->next=new Node(carry);
    }
    return dummyHead->next;

}
Node* deleteOccurences(Node* head,int target){
    Node* dummyhead=new Node(-1,head,nullptr);
    head->back=dummyhead;
    Node* temp=head;
    Node* mover;
    while(temp){
        if(temp->data==target){
            
            mover=temp;
            temp=temp->next;
            if(temp){temp->back=mover->back;
            temp->back->next=temp;}
            else{
                mover->back->next=nullptr;
            }

            delete mover;
        }
        else{
            temp=temp->next;
        }
    }
    return dummyhead->next;
}
int main(){
    vector<int> arr1={5,6,6,7};
     Node* head1 = convertArr2DLL(arr1);
    int x;
    cin >> x;
    head1=deleteOccurences(head1,x);
    while(head1 != nullptr) {
        cout << head1->data << " ";
        head1 = head1->next;
    }
}