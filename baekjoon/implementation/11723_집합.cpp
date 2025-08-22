// BOJ 11723 집합 — implementation
// link: https://www.acmicpc.net/problem/11723
// idea: 
// time/space: O(N) / O(1)
// edge: 

//sketch
/*
필요한 데이터
- 집합 클래스
    - 1~20숫자 집합 배열
    - 명령어 수행 매서드들
- 명령어 입력 string
- 숫자 입력

알고리즘
- M을 받고 M번 반복 시작
    - 명령어 입력 받고 해당 명령어에 맞는 함수 호출
*/

//version 1
#if 0

#include <iostream>
class my_set{
private: 
    bool checking_data[21] = {0,};
public: 
    void add(int a){checking_data[a] = true;}
    void remove(int a){checking_data[a] = false;}
    void check(int a) const {std::cout << checking_data[a] << '\n';}
    void toggle(int a){checking_data[a] ^= true;}
    void all(){
        for(int i = 1;i <= 20;i++){
            checking_data[i] |= true;
        }
    }
    void empty(){
        for(int i = 1;i <= 20;i++){
            checking_data[i] &= false;
        }
    }
};

int main(){
    my_set ms;
    int m;
    std::cin >> m;
    for(int i = 0;i < m;i++){
        std::string command;
        int x;
        std::cin >> command;
        if(command == "all"){
            ms.all();
            continue;
        }
        else if(command == "empty"){
            ms.empty();
            continue;
        }
        std::cin >> x;

        if(command == "add") ms.add(x);
        else if(command == "remove") ms.remove(x);
        else if(command == "check") ms.check(x);
        else if(command == "toggle") ms.toggle(x);
    }
    return 0;
}

#endif

//version 2
#if 1

#include <iostream>
#include <string>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int my_set = 0;
    int m;
    cin >> m;
    for(int i = 0;i < m;i++){
        string command;
        int x;
        cin >> command;
        if(command == "all"){
            my_set |= 0xFFFFF;
            continue;
        }
        else if(command == "empty"){
            my_set = 0;
            continue;
        }
        std::cin >> x;
        x -= 1;

        if(command == "add") my_set |= (1 << x);
        else if(command == "remove") my_set &= ~(1 << x);
        else if(command == "check"){cout << ((my_set >> x) & 1) << '\n';}
        else if(command == "toggle") my_set ^= (1 << x);
    }
    return 0;
}
#endif