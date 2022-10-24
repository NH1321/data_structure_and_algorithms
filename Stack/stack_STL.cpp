#include<iostream>
#include<stack>

int main(){
    std::stack<int> mystack; //khai báo ngăn xếp với int

    for(int i=0; i<5; i++){
        mystack.push(i); //thêm phần tử i vào trên cùng stack
    }
    std::cout<<"Popping out elements...";
    while(!mystack.empty()){
        std::cout<<" "<<mystack.top(); //lấy phần tử trên cùng của stack
        mystack.pop(); //loại bỏ phần tử trên cùng của stack
    }
    std::cout<<"\n";
    return 0;
}