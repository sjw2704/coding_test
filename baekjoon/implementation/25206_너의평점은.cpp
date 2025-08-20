// BOJ 25206 통계학 — implementation, math
// link: https://www.acmicpc.net/problem/25206
// idea: 문자열 성적을 계산 할 수 있는 수로 바꿔주는 함수를 만듦, 성적이 P일 경우 계산에서 제외함
// time/space: O(N) / O(N)
// edge: 

//sketch
/*
변수
- 총 취득 학점
- 학점 x 등급 합산
- 학점 이름 받는 버퍼

- 20번 반복하며 이름, 학점, 성적 받음
- 스위치 케이스로 성적(문자)에 대한 값 반환
- 총 취득 학점에 누적하고, 학점 x 성적 계산하여 누적
- 누적된 학점 x 성적에 대하여 총 취득학점으로 나눔
*/

//version 1
#if 0

#include <iostream>
#include <iomanip>
#include <unordered_map>
using namespace std;

float cal_grade(string grade){
    if(grade == "A+"){
        return 4.5;
    }
    else if(grade == "A0"){
        return 4.0;
    }
    else if(grade == "B+"){
        return 3.5;
    }
    else if(grade == "B0"){
        return 3.0;
    }
    else if(grade == "C+"){
        return 2.5;
    }
    else if(grade == "C0"){
        return 2.0;
    }
    else if(grade == "D+"){
        return 1.5;
    }
    else if(grade == "D0"){
        return 1.0;
    }
    else return 0.0;
}

int main(){
    string subjectName;
    string gradeChar;
    double subjectSum = 0;
    double gradeSum = 0;
    double subjectGrade;
    for(int i = 0;i < 20;i++){
        cin >> subjectName >> subjectGrade >> gradeChar;
        if(gradeChar == "P")continue;
        gradeSum += cal_grade(gradeChar) * subjectGrade;
        subjectSum += subjectGrade;
    }
    cout << fixed << setprecision(6) << gradeSum/subjectSum << endl;
    return 0;
}

#endif

//version 2
#if 1

#include <iostream>
#include <iomanip>
#include <unordered_map>
using namespace std;

static const unordered_map<string, double> grade_table = {
    {"A+", 4.5}, {"A0", 4.0},
    {"B+", 3.5}, {"B0", 3.0},
    {"C+", 2.5}, {"C0", 2.0},
    {"D+", 1.5}, {"D0", 1.0},
    {"F",  0.0}
};

int main(){
    string subjectName;
    string gradeChar;
    double subjectSum = 0;
    double gradeSum = 0;
    double subjectGrade;
    for(int i = 0;i < 20;i++){
        cin >> subjectName >> subjectGrade >> gradeChar;
        if(gradeChar == "P")continue;
        gradeSum += grade_table.find(gradeChar)->second * subjectGrade;
        subjectSum += subjectGrade;
    }
    cout << fixed << setprecision(6) << gradeSum/subjectSum << endl;
    return 0;
}

#endif