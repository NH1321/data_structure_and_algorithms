#include<bits/stdc++.h>

int main(){
    std::deque<int> a; //khai báo deque
    std::cout<<a.empty()<<"\n"; //lúc này hàng đợi đang rỗng, nên sẽ in ra 1

    a.push_back(2); //thêm 2 vào cuối hàng đợi, hàng đợi lúc này: [2]
    a.push_front(1); //thêm 1 vào đầu hàng đợi, hàng đợi lúc này: [1, 2]
    a.push_back(3); //thêm 3 vào cuối hàng đợi, hàng đợi lúc này: [1, 2, 3]
    a.push_front(4); //thêm 4 vào đầu hàng đợi, hàng đợi lúc này: [4, 1, 2, 3]

    std::cout<<a.size()<<"\n"; //in ra kích thước hàng đợi hiện tại, lúc này là 4
    std::cout<<a.empty()<<"\n"; //lúc này hàng đợi không rỗng, in ra 0

    std::cout<<a.front()<<"\n"; //in ra pân phần tử đầu hàng đợi, lúc này là 4
    std::cout<<a.back()<<"\n"; //in ra phần tử cuối hàng đợi, lúc này là 3
    std::sort(a.begin(), a.end()); //sắp xếp hàng đợi như một vecto bình thường, hàng đợi lúc này: [1, 2, 3, 4]

    for(int i=0; i<a.size(); i++){
        std::cout<<a[i]<<"\t"; //in ra các giá trị của hàng đợi, hàng đợi lúc này là: [1, 2, 3, 4]
    }
    std::cout<<"\n";
    
    a.resize(5); //ép kích thước của hàng đợi lên 5, hàng đợi lúc này là: [1, 2, 3, 4, 0]
    a[4]=5; //gán giá trị cho vị trí i=4 của hàng đợi, lúc này hàng đợi là:[1, 2, 3, 4, 5]

    a.pop_front(); //loại bỏ phần tử ở đầu hàng đợi, lúc này đang là 1, hàng đợi sau bước này là: [2, 3, 4, 5]
    std::cout<<a.size()<<"\n"; //in ra kích thước hàng đợi hiện tại, lúc này là 4
    std::cout<<a.front()<<"\n"; //in ra phần tử ở đầu hàng đợi, lúc này là 2
    a.pop_back(); //loại bỏ phần tử ở cuối hàng đợi, lúc này đang là 5, sau bước này hàng đợi là: [2, 3, 4]
    std::cout<<a.back()<<"\n"; //in ra phần tử ở cuối hàng đợi, lúc này là 4

    a.insert(a.begin()+1,0); //chèn 0 vào vị trí 1 của hàng đơi, hàng đợi lúc này là: [2, 0, 3, 4]
    a.erase(a.begin()+1); //xóa phần tử tại vị trí thứ 1 của hàng đợi, hàng đợi lúc này là: [2, 3, 4]
    a.clear(); //xóa tất cả các phần tử của hàng đợi

    std::cout<<a.empty()<<"\n"; //lúc này hàng đợi đang rỗng, nên sẽ in ra giá trị 1
    return 0;
}