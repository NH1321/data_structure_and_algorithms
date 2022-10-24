#include<iostream>
using namespace std;

int max(int a, int b, int c){
    int d;
    int max = a > (d = b > c ? b : c) ? a : d;
    return max; 
}

int main(){
    int a, b, c;
    cin>>a>>b>>c;
    cout<<max(a, b, c);
}