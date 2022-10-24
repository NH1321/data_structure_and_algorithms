//Thuật toán sắp xếp chèn
#include<iostream>
using namespace std;

void InsertionSort(int arr[], int n){
    int i, j, key;
    for(int i=1; i<n; i++){
        key=arr[i];
        j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=key;
    }
}

void Print(int arr[], int n){
    for(int i=0; i<n; i++){
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
    cout<<"Mang da sap xep la: "<<endl;
    InsertionSort(arr, n);
    Print(arr, n);
    return 0;
}
