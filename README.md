# Coding Test Solutions

이 저장소는 **C++**을 사용하여 푼 코딩 테스트 문제 풀이를 정리한 것입니다.  
풀이 대상 사이트:
- [Baekjoon Online Judge](https://www.acmicpc.net/)
- [Programmers](https://programmers.co.kr/)

---

## 📂 폴더 구조

```
coding_test/
├── baekjoon/              # 백준 문제 (알고리즘별 분류)
│   ├── implementation/    # 구현 문제
│   ├── math/              # 수학 관련 문제
│   └── …
└── programmers/           # 프로그래머스 문제 (레벨별 분류 예정)
```
---

## 📝 파일명 규칙
- `문제번호_문제제목.cpp`
- 공백 대신 `_` 사용, 특수문자 제거
- 예:  
1931_회의실배정.cpp
11047_동전0.cpp

---

## 💡 풀이 작성 규칙
1. **문제 링크, 알고리즘 유형, 시간복잡도**를 코드 상단 주석에 기재
2. 가능한 한 **가독성 있는 변수명** 사용
3. 예외 케이스 및 입력 조건을 주석으로 명시
4. 불필요한 임시 파일은 `.gitignore`로 제외

---

## 🚀 커밋 규칙 예시

[Baekjoon] 1931 회의실 배정 - 그리디
[Programmers] Lv2 기능개발 - 큐

- 사이트 / 문제번호 / 문제제목 / 사용 알고리즘 순

---

## 📌 TODO
- [ ] Programmers 문제 분류 및 업로드
- [ ] README 각 폴더별 설명 추가
- [ ] GitHub Actions로 자동 빌드/테스트 설정