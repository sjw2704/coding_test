// BOJ 1316 그룹단어체커 — implementation, string
// link: https://www.acmicpc.net/problem/1316
// idea: 연속되는 문자는 하나의 문자로 처리, 이전에 들어온 문자가 다시 반복되면 제외
// time/space: O(L) / O(1)
// edge: 
// 개선사항 : 변수명 일관되게 네이밍할 것,이중 루프를 최대한 피할 것, 데이터 특성에 맞는 타입 설정할 것

#include <iostream>
#include <string>
using namespace std;

#define kAlpha 26

bool isGroupWord(const string& s){
    bool seen[kAlpha] = {'\0'};
    //연속되는 단어는 한 번만 체크함, 중복 체크되는 경우 return false
    for(int i = 0;i < s.size();i++){
        if((i!=0)&&(s[i-1]==s[i])) continue;
        int index = s[i] - 'a';
        if(seen[index] == true) return false;
        seen[index] = true;
    }
    return true;
}

int main(){
    int cnt = 0;
    int n;
    cin >> n;

    for(int i = 0;i < n;i++){
        string s;
        cin >> s;
        cnt += isGroupWord(s);
    }

    cout << cnt << '\n';
    return 0;
}