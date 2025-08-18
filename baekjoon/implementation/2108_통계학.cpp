// BOJ 2108 통계학 — implementation, math
// link: https://www.acmicpc.net/problem/2108
// idea: 최빈값을 구할 때, 배열을 정렬한 후에 값은 값이 연속으로 나오면 카운트하여 최빈값 계산함
// time/space: O(N \log N) / O(N)
// edge: 

/*
- 클래스 구성
    정수 배열
    수 추가 매서드
    정렬 매서드
    산술 평균 매서드
    중앙값 매서드
    최빈값 매서드
    범위 매서드

- N크기 만큼 동적 배열 할당
- 배열에 입력 받음
- 오름차순으로 정렬함
    산술평균 함수 호출후 출력
    중앙값 추출 함수 호출 출력
    최빈값 추출 함수 호출 및 출력
    범위 함수 호출 및 출력
- 종료
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

class statistics {
private :
    vector<int> numbers;

public :
    //수 추가
    void addNumbers(const int x){
         numbers.push_back(x);
    }
    // 정렬 함수
    void sortNumbers(){
        sort(numbers.begin(),numbers.end());
    }
    // 산술 평균
    int averageNumbers(const int n) const{
        int sum = 0;
        for(int i : numbers){
            sum+=i;
        }
        int a = (int)round(sum/(float)n);
        return a;
    }
    //중앙값
    int middleNumbers(const int n){
        int middleIndex = (int)ceil(n/2.0) - 1;
        return numbers[middleIndex];
    }
    //최빈값
    int freqNumbers(const int n) const{
        vector<pair<int,int>> data;
        int prev = numbers[0];
        int cnt = 0;
        for(int i : numbers){
            if(prev == i){
                cnt++;
            }
            else{
                data.push_back({prev,cnt});
                prev = i;
                cnt = 1;
            }
        }
        data.push_back({prev,cnt});
        sort(data.begin(), data.end(),
        [](const pair<int,int>& a, const pair<int,int>& b) {
            if (a.second == b.second) {
                return a.first < b.first;   // 두 번째 값이 같으면 첫 번째 값 기준 오름차순
            }
            return a.second > b.second;     // 두 번째 값 기준 내림차순
        });

        if(data[0].second == data[1].second && n > 1) return data[1].first;
        else return data[0].first;
    }
    //범위
    int rangeNumbers(const int n) const{
        int range = numbers[n-1] - numbers[0];
        return range;
    }
};

int main(){
    statistics st;
    int n,temp;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> temp;
        st.addNumbers(temp);
    }
    st.sortNumbers();
    cout << st.averageNumbers(n) << '\n';
    cout << st.middleNumbers(n) << '\n';
    cout << st.freqNumbers(n) << '\n';
    cout << st.rangeNumbers(n) << '\n';
}