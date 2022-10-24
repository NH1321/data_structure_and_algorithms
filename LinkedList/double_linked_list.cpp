#include<iostream>
using namespace std;

typedef struct linkedlist{
    int data;
    struct linkedlist *next;
    struct linkedlist *prev;
}node;
//khởi tạo node head global của danh sách liên kết đôi
 node *head, *tail;

//tạo 1 node mới
node *NewNode(int x){
    node *newnode= new node;
    newnode->data=x;
    newnode->next=NULL;
    newnode->prev=NULL;
    return newnode;
}

//thêm 1 node vào đầu
node *AddHead(int x){
    node *newnode=NewNode(x);
    if(head==NULL){
        head=newnode;
        tail=newnode;
        return 0;
    }
    head->prev=newnode;
    newnode->next=head;
    head=newnode;
}

//thêm 1 node vào cuối
node *Addtail(int x){
    node *newnode=NewNode(x);
    node *p;
    if(head==NULL){
        head=newnode;
        tail=newnode;
        return 0;
    }
    tail->next=newnode;
    newnode->prev=tail;
    tail=newnode;
}

//thêm 1 node vào vị trí bất kì
// node *AddAt(int x, int vitri){
//     node *newnode=NewNode(x);
//     if(head==NULL){
//         head=newnode;
//         tail=newnode;
//         return 0;
//     }
//     else if(head->next==NULL) newnode=AddHead(x);
//     else {
//         int k=1;
//         node *p=head;
//         while(p!=NULL && k!=vitri){
//             p=p->next;
//             ++k;
//         }
//         if(k!=vitri) newnode=Addtail(x);
//         else {
//             newnode->next=p->next;
//             newnode->prev=p;
//             newnode=p->next;
//         }
//     }
// }

//xóa node đầu của double linked list
node *DeleteHead(){
    if(head==NULL) return 0;
    head=head->next;
    head->prev=NULL;
}

//xóa 1 node ở cuối double linked list
node *Deletetail(){
    if(head==NULL) return 0;
    tail=tail->prev;
    tail->next=NULL;
}

//duyệt danh sách liên kết từ đầu tới cuối
void Print(){
    node *temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"\t";
        temp=temp->next;
    }
    cout<<endl;
}

//duyệt danh sách liên kết từ cuối tới đầu
void ReversePrint(){
    node *temp=tail;
    if(temp==NULL) return;
    while(temp!=NULL){
        cout<<temp->data<<"\t";
        temp=temp->prev;
    }
    cout<<endl;
}

int main(){
    head = NULL;

    Addtail(2);
    Print();
    ReversePrint();
    cout<<endl;

    Addtail(4);
    Print();
    ReversePrint();
    cout<<endl;

    AddHead(6);
    Print();
    ReversePrint();
    cout<<endl;

    Addtail(8);
    Print();
    ReversePrint();
    cout<<endl;

    // AddAt(10,2);
    // Print();
    // ReversePrint();
    // cout<<endl;

    DeleteHead();
    Print();
    ReversePrint();
    cout<<endl;

    Deletetail();
    Print();
    ReversePrint();
    return 0;
}