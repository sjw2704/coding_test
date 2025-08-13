// BOJ 1966 프린터큐 — data_structure, implementation
// link: https://www.acmicpc.net/problem/1966
// idea: 최댓값을 추적하여 print와 goback판단을 빠르게 내림
// time/space: O(N) / O(N)
// edge: 
// 개선사항 : 

#include <iostream>
#include <algorithm>
#include <functional>
#include <queue>
using namespace std;
#define blank -1

int sequence_doc(queue<pair<int,int>>& docQueue, int *priority, const int docNumbers, int target){
    int printed = 0;       
    int freq[10] = {0}; 

    // priority 배열 기반으로 빈도 구축 (네가 유지하던 동적배열 활용)
    for (int i = 0; i < docNumbers; ++i) freq[priority[i]]++;

    // 현재 최댓값 추적 (9→1로 단조 감소)
    int curMax = 9;
    while (curMax > 0 && freq[curMax] == 0) --curMax;

    while (!docQueue.empty()) {
        auto [p, idx] = docQueue.front();
        docQueue.pop();

        if (p == curMax) { 
            ++printed;
            --freq[p];
            if (idx == target)        
                return printed;

            while (curMax > 0 && freq[curMax] == 0) --curMax; 
        } else {
            docQueue.push({p, idx});
        }
    }
    return printed;
}

int main(){
    int T;
    cin >> T;

    while (T--){
        int docNumbers, target;
        cin >> docNumbers >> target;

        queue<pair<int,int>> docQueue;  
        int *priority = new int[docNumbers];

        for (int j = 0; j < docNumbers; j++){
            int temp; 
            cin >> temp;
            priority[j] = temp;         
            docQueue.push({temp, j});
        }

        int cnt = sequence_doc(docQueue, priority, docNumbers, target);
        cout << cnt << '\n';

        delete[] priority;
    }
    return 0;
}