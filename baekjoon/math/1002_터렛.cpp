/*
문제
===========================
조규현과 백승환은 터렛에 근무하는 직원이다. 하지만 워낙 존재감이 없어서 인구수는 차지하지 않는다. 다음은 조규현과 백승환의 사진이다.
이석원은 조규현과 백승환에게 상대편 마린(류재명)의 위치를 계산하라는 명령을 내렸다. 조규현과 백승환은 각각 자신의 터렛 위치에서 현재 적까지의 거리를 계산했다.

조규현의 좌표 
$(x_1, y_1)$와 백승환의 좌표 
$(x_2, y_2)$가 주어지고, 조규현이 계산한 류재명과의 거리 
$r_1$과 백승환이 계산한 류재명과의 거리 
$r_2$가 주어졌을 때, 류재명이 있을 수 있는 좌표의 수를 출력하는 프로그램을 작성하시오.

입력
===========================
첫째 줄에 테스트 케이스의 개수 
$T$가 주어진다. 각 테스트 케이스는 다음과 같이 이루어져 있다.

한 줄에 공백으로 구분 된 여섯 정수 
$x_1$, 
$y_1$, 
$r_1$, 
$x_2$, 
$y_2$, 
$r_2$가 주어진다.

출력
===========================
각 테스트 케이스마다 류재명이 있을 수 있는 위치의 수를 출력한다. 만약 류재명이 있을 수 있는 위치의 개수가 무한대일 경우에는 
$-1$ 출력한다.

제한
============================
-10000 ≤ $x_1$, $y_1$, $x_2$, $y_2$ ≤ 10000
0 ≤ $r_1$, $r_2$ ≤ 10000

예제 입력
============================
3
0 0 13 40 0 37
0 0 3 0 7 4
1 1 1 1 1 5

예제 출력
============================
2
1
0
*/

// 나의 답안
// ============================

#include <iostream>
#include <cmath>
using namespace std;

#define Min_x -10000
#define Max_x 10000
#define Min_y -10000
#define Max_y 10000

int coordinates_numbers(int x1, int y1, int r1, int x2, int y2, int r2);

int main() {
    int test_cases;
    int x1, y1, r1, x2, y2, r2;
    int cross_cordinates[1000]; // Array to store possible cases for each test case

    // Input the number of test cases
    cin >> test_cases;

    // Loop through each test case
    for(int i = 0; i < test_cases; i++){
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        if(x1 == x2 && y1 == y2 && r1 == r2) {
            // If both coordinates and radii are the same, infinite solutions
            cross_cordinates[i] = -1;
            continue;
        }
        cross_cordinates[i] = coordinates_numbers(x1, y1, r1, x2, y2, r2);
    }

    // Output the results for each test case
    for(int i = 0; i < test_cases; i++){
        cout << cross_cordinates[i] << endl;
    }

    return 0;
}

int coordinates_numbers(int x1, int y1, int r1, int x2, int y2, int r2){
    int cross_cordinates = 0;
    //중심 사이의 거리 구하기
    float sum_radius = (float)r1 + (float)r2;
    float longer_radius = (r1 >= r2) ? r1 : r2;
    float shorter_radius = (r1 >= r2) ? r2 : r1;
    float distance_x = (float)abs(x1-x2);
    float distance_y = (float)abs(y1-y2);
    float distance_center = sqrt(pow(distance_x,2) + pow(distance_y,2));
    
    //반지름 거리와 비교
    if((distance_center > sum_radius)||((distance_center+shorter_radius) < longer_radius)){ // 교점이 0개일 경우
        cross_cordinates = 0;
    }
    else if((distance_center == sum_radius)||((distance_center+shorter_radius) == longer_radius)){ // 교점이 1개일 경우
        cross_cordinates = 1;
    }
    else{ // 교점이 1개일 경우
        cross_cordinates = 2;
    }

    return cross_cordinates;
}

// GPT의 답안
// ============================

#include <iostream>
#include <cmath>
using namespace std;

int getResult(int x1, int y1, int r1, int x2, int y2, int r2) {
    double dx = x2 - x1;
    double dy = y2 - y1;
    double d = sqrt(dx * dx + dy * dy);

    // 같은 위치, 같은 반지름 (무한대)
    if (d == 0 && r1 == r2)
        return -1;

    // 같은 중심, 다른 반지름 (교점 없음)
    if (d == 0 && r1 != r2)
        return 0;

    // 두 원이 멀리 떨어져 있음 (교점 없음)
    if (d > r1 + r2)
        return 0;

    // 두 원이 외접 (교점 1개)
    if (d == r1 + r2)
        return 1;

    // 두 원이 내접 (교점 1개)
    if (d == abs(r1 - r2))
        return 1;

    // 한 원이 다른 원 안에 있음 (교점 없음)
    if (d < abs(r1 - r2))
        return 0;

    // 두 점에서 만남
    return 2;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int x1, y1, r1, x2, y2, r2;
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

        cout << getResult(x1, y1, r1, x2, y2, r2) << endl;
    }

    return 0;
}