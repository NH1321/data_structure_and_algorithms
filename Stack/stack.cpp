#include<iostream>
using namespace std;

int top=-1;
//kiểm tra stack đầy
bool IsFull(int capacity){
    if(top>=capacity-1) return true;
    else return false;
}
//kiểm tra stack rỗng
bool IsEmpty(){
    if(top==-1) return true;
    else return false;
}
//lấy số lượng phần tử stack đang có
int Size(){
    return top+1;
}
//thêm phần tửu vào đỉnh stack
void Push(int stack[], int value, int capacity){
    if(IsFull(capacity)==true) cout<<"Ngan xep da day";
    else {
        ++top;
        stack[top]=value;
    }
}
//xóa phần tử khỏi đỉnh stack
void Pop(){
    if(IsEmpty()==true) cout<<"Ngan xep rong";
    else --top;
}
//lấy phần tử trên cùng của stack
int Top(int stack[]){
    return stack[top];
}

int main(){
    int capacity = 3;
    int top=-1;
    int stack[capacity];

    Push(stack, 5, capacity); //đẩy phần tử 5 vào stack
    cout<<endl<<"kich thuoc hien tai cua ngan xep la: "<<Size();
    cout<<endl;

    Push(stack, 10, capacity); //đẩy phần tử 10 vào stack
    Push(stack, 24, capacity); //đẩy phần tử 24 vào stack
    cout<<endl<<"kich thuoc hien tai cua ngan xep la: "<<Size();
    cout<<endl;


    Push(stack, 12, capacity); //đẩy phần tử 12 vào stack
    cout<<endl<<"Phan tu tren cung hien tai cua ngan xep la: "<<Top(stack);
    //xóa tất cả các phần tử của stack
    for(int i=0; i<3; i++){
        Pop(); //xoa phần tử trên cùng của stack
    }
    cout<<endl;

    cout<<endl<<"kich thuoc hien tai cua ngan xep la: "<<Size();
    cout<<endl;
    Pop();
    return 0;
}