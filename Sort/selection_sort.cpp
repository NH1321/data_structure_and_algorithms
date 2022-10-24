//Thuật toán sắp xếp chọn 
#include<iostream>
using namespace std;

//hàm đổi chỗ 2 số nguyên
void swap(int &x, int &y){
    int temp=x;
    x=y;
    y=temp;
}

//hàm selection sort
void SelectionSort(int arr[], int n){
    int i, j, min;
    for(int i=0; i<n-1; i++){
        min = i;
        for(j=i+1; j<n; j++){
            if(arr[j]<arr[min]) min = j;
        }
        swap(arr[min], arr[i]);
    }
}

//hàm xuất mảng
void Print(int arr[], int size){
    for(int i=0; i<size; i++){
        cout<<arr[i]<<"\t";
    }
    cout<<endl;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    SelectionSort(arr, n);
    cout<<"Mang da sap xep"<<"\n";
    Print(arr, n);
    return 0;
}
