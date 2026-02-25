# 📚 2023 Data Structure

이 저장소는 **2023년 데이터구조(자료구조)** 과목의 실습 및 프로젝트 코드를 기록한 공간입니다. 
C/C++ 언어를 기반으로 메모리 구조와 포인터를 깊이 이해하고, 스택, 큐, 연결 리스트, 트리 등 다양한 핵심 자료구조를 기초부터 응용 프로그램까지 직접 구현했습니다. 특히 동일한 알고리즘을 **배열(Array) 기반과 연결 리스트(Linked List) 기반으로 각각 구현하여 구조적 차이와 장단점을 비교 분석**하는 데 중점을 두었습니다.

## 🛠 Tech Stack
* **Language:** C (97.7%), C++ (2.3%)
* **Environment:** Visual Studio / Windows

---

## 📂 Repository Structure & Key Implementations

### 1. C Language Review & Arrays (`03_*`, `textbook program`)
자료구조 구현에 필수적인 C 언어의 핵심 개념과 메모리 제어 기법을 실습했습니다.
* **Array & Pointers:** 1/2차원 배열과 포인터의 관계 이해, 다중 포인터 연산, `swap` 함수(Call-by-Reference) 구현.
* **Dynamic Memory Allocation:** `malloc`과 `free`를 이용한 1차원 및 2차원 배열의 동적 할당과 메모리 누수 방지 실습.
* **Struct & Array Application:** 구조체를 활용한 성적 처리 및 2차원 배열 위에서 난수를 이용해 8방향으로 움직이는 '딱정벌레 랜덤 이동(Random Bug Walk)' 시뮬레이션 구현.

### 2. Stack Application (`1st`, `3rd`, `example.c`)

LIFO(Last-In-First-Out) 구조인 스택을 배열 기반으로 구현하고, 이를 활용한 문자열 처리 알고리즘을 작성했습니다.
* **Palindrome Checker (`1(palindrome).c`):** 입력된 문자열에서 공백과 구두점을 무시하고 대소문자를 통일한 후, 스택을 이용해 회문(Palindrome) 여부를 판별하는 프로그램.
* **Parenthesis Matching (`2.c`, `example.c`):** 수식 내의 소괄호`()`, 중괄호`{}`, 대괄호`[]`의 쌍과 중첩이 올바르게 구성되었는지 스택의 `push`, `pop` 연산을 통해 검사하는 알고리즘.

### 3. Queue Application (`3rd/3-1.c`, `3rd/3-2.c`)

FIFO(First-In-First-Out) 구조인 큐를 활용하여 남녀 미팅 주선 프로그램을 두 가지 방식으로 구현 및 비교했습니다.
* **Array Circular Queue (`3-1.c`):** 2차원 문자열 배열과 `% MAX_SIZE` 연산을 이용한 원형 큐 구현 (메모리 재사용).
* **Linked Queue (`3-2.c`):** 구조체 노드(Node)와 포인터를 동적으로 할당하여 메모리 크기 제한이 없는 연결 리스트 기반 큐 구현.

### 4. Linked List & Advanced Applications (`textbook program`, `Project1`)

데이터의 동적 추가/삭제가 용이한 연결 리스트의 특성을 응용한 고급 알고리즘을 구현했습니다.
* **List Merge Algorithm (`3.7.c` vs `4.17.c`):** 관객 수 기준으로 정렬된 국내/해외 영화 흥행 목록(`Movie` 구조체)을 병합하는 알고리즘. 배열 리스트(`ArrayBO`) 방식과 단순 연결 리스트(`LinkedBO`) 방식을 모두 구현하여 차이점 분석.
* **Circular Doubly Linked List (`Project1/소스.c`):** 왼쪽/오른쪽 링크(`llink`, `rlink`)를 모두 가지는 원형 이중 연결 리스트를 구현하여, 조세푸스 문제(Josephus Problem)를 응용한 '순차적 학생 제거 프로그램'을 제작. 

### 5. Tree & Binary Search Tree (`4th/4th.c`)


[Image of Binary Search Tree]

계층형 자료구조인 트리를 활용하여 효율적인 텍스트 데이터 탐색 및 빈도수 추적 프로그램을 구현했습니다.
* **Word Frequency & Line Tracker:** * `input.txt` 파일을 읽어와 구두점을 제거하고 소문자로 변환(`strtok`, `ispunct`, `tolower` 활용).
  * 문자열 비교(`strcmp` 로직)를 통해 이진 탐색 트리(BST)에 노드(`TNode`) 삽입 및 단어 출현 횟수 카운트.
  * 단어가 등장한 줄(Line) 번호를 자릿수 연산(`line * 10 + line`)으로 누적 저장하여, 중위 순회(In-order Traversal)로 오름차순 출력.

---

## 🚀 How to Build & Run
각 디렉토리 내의 소스 코드는 Visual Studio 환경에 최적화되어 있습니다.
1. 각 폴더(예: `Project1`, `4th`) 내의 `.sln` 또는 `.vcxproj` 파일을 Visual Studio로 실행합니다.
2. 텍스트 파일 입력이 필요한 과제(예: `4th`의 `input.txt`)는 실행 파일과 동일한 디렉토리에 위치해야 합니다.
3. `Ctrl + F5`를 눌러 프로젝트를 빌드하고 콘솔 환경에서 실행합니다.
