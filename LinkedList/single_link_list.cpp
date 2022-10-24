#include<iostream>
using namespace std;

typedef struct LinkedList{
    int data;
    struct LinkedList *next;
}node;
//t?o m?t node m?i
node *CreateNode(int value){
    node *temp = new node; //khai báo 1 nút và c?p phát vùng nh? cho nó
    temp->next=NULL; //cho next tr? t?i null
    temp->data=value; //gán giá tr? cho node
    return temp; //tr? v? node m?i dã có gía tr?
} 
//thêm vào d?u
node *AddHead(node *head, int value){
    node *temp=CreateNode(value); //kh?i t?o node temp m?i có data=value
    if(head==NULL) head=temp; //n?u linked dang tr?ng thì node temp là head luôn
    else{
        temp->next=head; //tr? next c?a temp = head hi?n t?i
        head=temp; //d?i head hi?n t?i b?ng temp(vì temp là head m?i)
    }
    return head;
}
//thêm vào cu?i
node *AddTail(node *head, int value){
    node *temp, *p; //khai báo 2 node t?m temp và p
    temp = CreateNode(value); //g?i hàm createnode d? kh?i t?o node temp có next tr? t?i null và giá tr? là value
    if(head==NULL) head = temp; //n?u linked list dang tr?ng thì node temp là head luôn
    else {
        p=head; //kh?i t?o p tr? t?i head
        while(p->next!=NULL){
            p=p->next; //duy?t linked list d?n cu?i. node cu?i là node có next = null
        }
        p->next=temp; //gán next c?a node cu?i b?ng  temp. khi dó temp s? là node cu?i(teamp->next=null)
    }
    return head;
}
//thêm vào v? trí b?t kì
node *AddAt(node *head, int value, int x){
    if(x==0 || head == NULL) head = AddHead(head, value); //n?u v? trí chèn là 0 ho?c linked list r?ng thì thêm vào d?u
    else {
        int k=1;
        node *p=head;
        while(p!=NULL && k!=x){
            p=p->next;
            ++k;
        }
        if(k!=x) head=AddTail(head, value);
        else {
            node *temp=CreateNode(value);
            temp->next=p->next;
            p->next=temp;
        }
    }
    return head;
}
//xóa node d?u c?a linked list
node *DeleteHead(node *head){
    if(head==NULL) cout<<"Cha co gi de xoa";
    else {
        head=head->next;
    }
    return head;
}
//xóa node cu?i c?a linked list
node *DeleteTail(node *head){
    node *p=head;
    if(head==NULL) cout<<"Cha co gi de xoa";
    else if(head->next==NULL) return DeleteHead(head);
    else {
        while(p->next->next!=NULL){
            p=p->next;
        }
        p->next=NULL;
    }
    return head;
}
//xóa m?t node b?t kì trong linked list
node *DeleteAt(node *head, int x){
    if(head==NULL) cout<<"Cha co gi de xoa";
    else if(head->next==NULL) return DeleteHead(head);
    else {
        int k=1;
        node *p=head;
        while(p->next->next!=NULL && k!=x){
            p=p->next;
            ++k;
        }
        if(k!=x) return DeleteTail(head);
        else {
            p->next=p->next->next;
        }
    }
    return head;
}
//l?y giá tr? ? v? trí b?t kì
int Get(node *head, int index){
    int k=0;
    node *p=head;
    while(p->next!=NULL && k!=index){
        ++k;
        p=p->next;
    }
    return p->data;
}
//tìm ki?m trong linked list
int Search(node *head, int value){
    int x=0;
    for(node *p=head; p!=NULL; p=p->next){
        if(p->data=value) return x;
        ++x;
    }
    return -1;
}
//xóa t?t c? các node 
node *DeleteByVal(node *head, int value){
    int x=Search(head, value);
    while(x!=-1){
        DeleteAt(head, x);
        x=Search(head, value);
    }
    return head;
}
//duy?t danh sách liên k?t
void Traverser(node *head){
    cout<<endl;
    for(node *p=head; p!=NULL; p=p->next){
        cout<<p->data<<"\t";
    }
}
//l?y s? phân ph?n t? c?a danh sách liên k?t
int Length(node *head){
    int length=0;
    for(node *p=head; p!=NULL; p=p->next){
        +length;
    }
    return length;
}
//hàm kh?i t?o node head
node *InitHead(){
    node *head;
    head=NULL;
    return head;
}
//hàm nh?p linked list
node *Input(){
    node *head=InitHead();
    int n, value;
    do{
        cout<<endl<<"Nhap so luong phan tu n = ";
        cin>>n;
    }
    while(n<=0);
    for(int i=0; i<n; i++){
        cout<<endl<<"Nhap gia tri can them: ";
        cin>>value;
        head=AddTail(head,value);
    }
    return head;
}

int main(){
    cout<<endl<<".....Tao 1 linked list.....";
    node *head=Input();
    Traverser(head);

    cout<<endl<<"Them 1 phan tu vao linked list";
    head=AddAt(head, 100, 2);
    Traverser(head);

    cout<<endl<<"Xoa 1 phan tu khoi linked list";
    head=DeleteAt(head, 1);
    Traverser(head);

    cout<<endl<<"Tim kiem 1 phan tu trong linked list";
    int index=Search(head, 5);
    Traverser(head);

    cout<<endl<<"The la duoc roi nhe!";
    return 0;
}