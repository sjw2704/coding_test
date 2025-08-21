// BOJ 1475 통계학 — implementation
// link: https://www.acmicpc.net/problem/1475
// idea: 6과 9는 하나의 숫자로 봐야하기 때문에 똑같은 메모리에서 카운트 한다
// time/space: O(N) / O(1)
// edge: 

//sketch
/*
변수
- 0~9까지 갯수를 카운트 하는 배열
- 8사이즈의 입력 배열

알고리즘
- 문자열 끝까지 읽으면서 숫자 하나씩 처리
    - 해당 숫자의 index에 +1
    - 만약 숫자가 6이나 9이면 6에만 +1(임의로 정함)
- 6의 갯수를 2로 나누고 반올림 함
- 갯수 배열에서 max값을 찾은 후에 출력함
*/

//version 1
#if 0
#include <iostream>

int main(){
    int count[10] = {0,};
    char input[8] = {0,};
    std::cin >> input;
    int i = 0;
    while(input[i] != 0){
        int index = input[i] - '0';
        if(index == 9) index = 6;
        count[index]++;
        i++;
    }
    count[6] = (count[6]/2) + (count[6]%2);
    int maxResult = 0;
    for(i = 0;i < 10;i++){
        maxResult = count[i] > maxResult ? count[i] : maxResult;
    }
    std::cout << maxResult << '\n';
}
#endif

//version 2
#if 1
#include <iostream>
#include <string>
#include <algorithm>

int main(){
    int count[10] = {0,};
    std::string input;
    std::cin >> input;
    for(char c:input){
        int digit = c - '0';
        if(digit == 9) digit = 6;
        count[digit]++;
    }
    count[6] = (count[6]+1)/2;
    int answer = *std::max_element(count, count + 10);
    std::cout << answer << '\n';
}
#endif