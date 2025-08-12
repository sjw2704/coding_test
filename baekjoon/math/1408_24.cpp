/*
문제
===========================
도현이는 Counter Terror Unit (CTU)에서 일하는 특수요원이다. 도현이는 모든 사건을 정확하게 24시간이 되는 순간 해결하는 것으로 유명하다.
도현이는 1시간 만에 범인을 잡을 수 있어도 잡지 않는다. 정확하게 24시간이 되는 순간이 아니면 잡지 않는 CTU 특수요원이다.

2008년 3월 3일 월요일, CTU는 새학기에 맞춰 핵폭탄을 날리겠다는 테러 정보를 입수했다. 
CTU에서는 특수요원 도현이에게 이 임무를 맡겼다. CTU의 프로그래머 준규는 이 사건의 배후가 김선영이란 것을 해킹을 통해 밝혀내었다.

도현이는 선영이를 임무를 시작한지 정확하게 24시간이 되는 순간에 잡으려고 한다.

만약 지금 시간이 13:52:30이고, 임무를 시작한 시간이 14:00:00 이라면 도현이에게 남은시간은 00:07:30 이다.

모든 시간은 00:00:00 ~ 23:59:59로 표현할 수 있다. 입력과 출력에 주어지는 모든 시간은 XX:XX:XX 형태이며, 
숫자가 2자리가 아닐 경우에는 0으로 채운다.

도현이가 임무를 시작한 시간과, 현재 시간이 주어졌을 때, 도현이에게 남은 시간을 구하는 프로그램을 작성하시오.

입력
===========================
첫째 줄에는 현재 시간이, 둘째 줄에는 도현이가 임무를 시작한 시간이 주어진다. 임무를 시작한 시간과 현재 시간이 같은 경우는 주어지지 않는다.

출력
===========================
첫째 줄에 도현이가 임무를 수행하는데 남은 시간을 문제에서 주어지는 시간의 형태 (XX:XX:XX)에 맞춰 출력한다.

제한
============================


예제 입력1
============================
13:52:30
14:00:00

예제 출력1
============================
00:07:30

예제 입력2
============================


예제 출력2
============================

*/

// 나의 답안
// ============================
// #include <iostream>
// #include <iomanip>
// using namespace std;

// struct Time {
//     int hour,minute,second;

//     bool isBeforeAfter(const Time& now) const {
//         if(hour != now.hour) return hour < now.hour;
//         if(minute != now.minute) return minute < now.minute;
//         return second < now.second;
//     }
//     struct Time afterMission(const Time& now){
//         struct Time leftOver;
//         leftOver.second = (60-now.second);
//         leftOver.minute = 59-now.minute;
//         leftOver.hour = 23-now.hour;

//         leftOver.second += second;
//         leftOver.minute += minute;
//         leftOver.hour += hour;

//         calLeft(leftOver);
//         return leftOver;
//     }
//     struct Time beforeMission(const Time& now){
//         struct Time leftOver;
//         hour -= 1;
//         minute += 60;
//         minute -= 1;
//         second += 60;

//         leftOver.second = second - now.second;
//         leftOver.minute = minute - now.minute;
//         leftOver.hour = hour - now.hour;

//         calLeft(leftOver);
//         return leftOver;
//     }
//     void calLeft(Time& leftOver){
//         if(leftOver.second >= 60){
//             leftOver.minute += leftOver.second/60;
//             leftOver.second = leftOver.second%60;
//         }
//         if(leftOver.minute >= 60){
//             leftOver.hour += leftOver.minute/60;
//             leftOver.minute = leftOver.minute%60;
//         }
//     }
// };

// int main(){
//     struct Time missionStart,now,timeLeft;
//     char buffer;
//     cin >> now.hour >> buffer >> now.minute >> buffer >> now.second; // 현재 시간 입력
//     cin >> missionStart.hour >> buffer >> missionStart.minute >> buffer >> missionStart.second; // 미션 시작 시간 입력

//     if(missionStart.isBeforeAfter(now)) timeLeft = missionStart.afterMission(now);
//     else timeLeft = missionStart.beforeMission(now);

//     cout << setw(2) << setfill('0') << timeLeft.hour << ":" << setw(2) << setfill('0') << timeLeft.minute << ":" << setw(2) << setfill('0') << timeLeft.second << endl;

//     return 0;
// }

// GPT 답안
// ============================
#include <iostream>
#include <iomanip>
using namespace std;

struct Time {
    int hour, minute, second;

    int toSeconds() const {
        return hour * 3600 + minute * 60 + second;
    }

    static Time fromSeconds(int totalSeconds){
        Time t;
        t.hour = totalSeconds / 3600;
        totalSeconds %= 3600;
        t.minute = totalSeconds / 60;
        t.second = totalSeconds % 60;
        return t;
    }
};

int main(){
    struct Time now, start;
    char buffer;

    cin >> now.hour >> buffer >> now.minute >> buffer >> now.second;
    cin >> start.hour >> buffer >> start.minute >> buffer >> start.second;

    int nowSec = now.toSeconds();
    int startSec = start.toSeconds();

    int delta = (startSec - nowSec + 86400) % 86400;

    Time result = Time::fromSeconds(delta);
    cout << setw(2) << setfill('0') << result.hour << ":"
         << setw(2) << setfill('0') << result.minute << ":"
         << setw(2) << setfill('0') << result.second << endl;

    return 0;
}