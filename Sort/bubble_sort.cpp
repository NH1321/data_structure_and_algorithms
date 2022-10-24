#include<iostream>
using namespace std;

//Hàm đổi chỗ 2 số nguyên
void swap(int &x, int &y){
    int temp=x;
    x=y;
    y=temp;
}

//Hàm bubble sort
void BubbleSort(int arr[], int n){
    int i, j;
    bool haveswap=false;
    for(int i=0; i<n-1; i++){
        haveswap=false;
        for(int j=0; j<n-i-1; j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j], arr[j+1]);
                haveswap=true;
            }
        }
        if(haveswap==false) break;
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
    BubbleSort(arr, n);
    cout<<"Mang sau khi sap xep: "<<endl;
    Print(arr, n);
    return 0;
}