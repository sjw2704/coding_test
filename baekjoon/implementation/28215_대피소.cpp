/*
문제
===========================
KOI 마을의 집들의 위치와 설치할 대피소의 개수가 주어질 때, 대피소를 설치하는 모든 방법 중
가장 가까운 대피소와 집 사이의 거리 중 가장 큰 값이 가장 작을 때의 거리를 구해라.

입력
===========================
첫 번째 줄에 
$N$과 
$K$가 공백을 사이에 두고 주어진다.

다음 
$N$개의 줄에는 집의 위치가 주어지는데, 이 중 
$i$ (
$1 ≤ i ≤ N$)번째 줄에는 
$X_i$와 
$Y_i$가 공백을 사이에 두고 주어진다.

출력
===========================
첫 번째 줄에 답을 출력한다.

제한
============================
주어지는 모든 수는 정수이다.
 
$1 ≤ K ≤ 3$ 
 
$K ≤ N ≤ 50$ 
 
$0 ≤ X_i ≤ 100\,000$ 
 
$0 ≤ Y_i ≤ 100\,000$ 
같은 위치에 집이 여럿 존재하지 않는다. 즉, 
$(X_1, Y_1)$, 
$(X_2, Y_2)$, 
$\cdots$, 
$(X_N , Y_N )$는 서로 다르다.

예제 입력1
============================
5 2
1 5
3 0
3 3
6 12
8 9

예제 출력1
============================
5

예제 입력2
============================
2 1
20 23
5 14

예제 출력2
============================
24
*/

// 나의 답안
// ============================

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

#define Max_x 100000
#define Max_y 100000

int houses_coordinates[50][2]; // 집들의 좌표 배열
int dist[50][50];//각 집부터 은신처까지의 거리 중에 최대값 저장

int cal_distance(int N,int K); // 최대값 저장
int one_shelter(int N,int K); // 대피소가 하나일 경우
int morethanone_shelter(int N,int K); // 대피소가 하나 이상일 경우
int possible_d(int d,int N,int K);

int main() {
    int temp; // Number of shelters
    cin >> temp;
    const int N = temp; // Number of houses
    cin >> temp;
    const int K = temp; // Number of shelters

    for(int i = 0;i < N;i++){
        cin >> houses_coordinates[i][0] >> houses_coordinates[i][1];
    }

    int answer = cal_distance(N,K);
    cout << answer << endl; 

    return 0;
}

int cal_distance(int N,int K){
    int answer;
    switch (K)
    {
    case 1:
        answer = one_shelter(N,K);
        break;
    default:
        answer = morethanone_shelter(N,K);
        break;
    }
    return answer;
}

int one_shelter(int N,int K){
    for(int i = 0;i < N;i++){
        int max = 0;
        for(int j = 0;j < N;j++){
            int temp_distance = abs(houses_coordinates[i][0] - houses_coordinates[j][0]) + abs(houses_coordinates[i][1] - houses_coordinates[j][1]);
            max = temp_distance > max ? temp_distance : max;
        }
        dist[0][i] = max;
    }
    sort(dist[0],dist[0]+N);
    return dist[0][K-1];
}

int morethanone_shelter(int N,int K){
    int max = 0;
    for(int i = 0;i < N;i++){ // 각 집사이의 거리 모두 구하기
        for(int j = 0;j < N;j++){
            int temp_distance = abs(houses_coordinates[i][0] - houses_coordinates[j][0]) + abs(houses_coordinates[i][1] - houses_coordinates[j][1]);
            max = temp_distance > max ? temp_distance : max; // 가장 최대 거리의 크기 구하기
            dist[i][j] = temp_distance;
        }
    }

    while(1){
        int temp_max = possible_d(max,N,K);
        // cout << "temp_min: "<<temp_max<< endl;
        if(temp_max < max){
            max = temp_max;
        }
        else if(temp_max == max){
            return max;
        }
    }
}

int possible_d(int d,int N,int K){
    
    if(K==2){
        for(int shelter1 = 0;shelter1 < N;shelter1++){
            for(int shelter2 = shelter1;shelter2 < N;shelter2++){
                if(shelter1==shelter2) continue;
                int max = 0;
                for(int num = 0;num < N;num++){
                    if(dist[num][shelter1] <= dist[num][shelter2]){
                        max = dist[num][shelter1] > max ? dist[num][shelter1] : max;
                    }
                    else{
                        max = dist[num][shelter2] > max ? dist[num][shelter2] : max;
                    }
                } 
                // cout << "i:"<<i<<",j:"<<j<<" = "<<max<<endl;
                if(max < d) return max;
            }
        }
    }
    else{
        for(int shelter1 = 0;shelter1 < N;shelter1++){
            for(int shelter2 = shelter1+1;shelter2 < N;shelter2++){
                for(int shelter3 = shelter2+1;shelter3 < N;shelter3++){
                    int max = 0;
                    for(int num = 0;num < N;num++){
                        if((dist[num][shelter1] <= dist[num][shelter2])&&(dist[num][shelter1] <= dist[num][shelter3])){
                            max = dist[num][shelter1] > max ? dist[num][shelter1] : max;
                        }
                        else if((dist[num][shelter2] <= dist[num][shelter1])&&(dist[num][shelter2] <= dist[num][shelter3])){
                            max = dist[num][shelter2] > max ? dist[num][shelter2] : max;
                        }
                        else{
                            max = dist[num][shelter3] > max ? dist[num][shelter3] : max;
                        }
                    }
                    if(max < d) return max;
                } 
            }
        }
    }
    return d;
}

// GPT의 답안
// ============================
