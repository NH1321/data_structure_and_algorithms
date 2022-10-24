#include<iostream>
#include<queue>

//using namespace std;

int main(){
    std::queue<int> a; //khai báo hàng đợi chứa int
    std::cout<<a.empty()<<"\n"; //lúc này hàng đợi đang rỗng nên sẽ in ra 1

    a.push(1); //thêm 1 vào cuối hàng đợi, hàng đợi lúc này là: [1]
    a.push(2); //thêm 2 vào cuối hàng đợi, hàng đợi lúc này là: [1, 2]
    a.push(3); //thêm 3 vào cuối hàng đợi, hàng đợi lúc này là: [1, 2, 3]

    std::cout<<a.size()<<"\n"; //in ra kích thước hiện tại, lúc này là 3
    std::cout<<a.empty()<<"\n"; //lúc này hàng đợi không rỗng nên sẽ in ra 0
    std::cout<<a.front()<<"\n"; //in ra phần tử đầu hàng đợi, lúc này là: 1
    std::cout<<a.back()<<"\n"; //in ra phần tử cuối hàng đợi, lúc này là: 3

    a.pop(); //loại bỏ phần tử ở cuối hàng đợi, lúc này là 1, hàng đợi sau bước này là: [2, 3]
    std::cout<<a.size()<<"\n"; //in ra kích thước của hàng đợi hiện tại, lúc này là 2
    std::cout<<a.front()<<"\n"; //in ra phần tử đầu của hảng đợi, lúc này là 2

    // std::queue<std::pair<int, int> > b; // Khai báo queue chứa pair<int, int>
    // b.emplace(std::make_pair(0, 1)); // Thêm 1 pair {0, 1} vào cuối hàng đợi, pair được khởi tạo ngay khi thêm vào
    // std::cout << b.size() << '\n'; // In ra kích thước hàng đợi hiện tại, lúc này là 1
    // std::cout << b.front().first << ' ' << b.front().second << '\n'; // In ra phần tử ở đầu hàng đợi, lúc này là {0, 1}
    
    // std::queue<std::pair<int, int> > c; // Khai báo queue chứa pair<int, int>
    // b.swap(c); // Hoán đổi dữ liệu của 2 hàng đợi cùng loại
    // std::cout << b.empty() << '\n'; // Lúc này hàng đợi đang rỗng do vừa tráo đổi dữ liệu với một hàng đợi rỗng, nên sẽ in ra 1
}