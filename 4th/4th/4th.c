#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
// 필요한 라이브러리 선언
// 이진 탐색 트리의 노드의 구조체를 정의한다.
typedef struct TNode {
    struct TNode* left;
    char* word;
    int count;
    int line;
    struct TNode* right;
} TNode; // 트리의 자식 요소로 가기 위한 left, right 포인터를 선언하고, 단어를 저장할 word, 단어 수와 줄 번호를 세기 위한 count, line 변수 선언.
// 루트 노드를 위한 구조체를 정의한다.
typedef struct LinkedBT {
    TNode* root;
} LinkedBT;
// 트리를 초기화 하는 함수
void init_BT(TNode** root) {
    *root = NULL;
}
// 새로운 노드를 생성하는 함수이다.
TNode* createNode(char* word, int line) {
    TNode* newNode = (TNode*)malloc(sizeof(TNode));
    newNode->word = _strdup(word);
    newNode->count = 1;
    newNode->line = line;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
} // 입력받은 단어를 저장하고, count를 1로 설정한 후 줄 번호를 입력받는다.
// 이진 탐색 트리에 노드를 삽입하게 되는 함수이다.
void insertNode(TNode** root, char* word, int line) {
    if (*root == NULL) {
        *root = createNode(word, line);
        return *root;
    }
    // 먼저 새로운 노드를 만든다.
    int compareResult = compare(word, (*root)->word);
    if (compareResult == 0) {
        (*root)->count++;
        (*root)->line = (*root)->line * 10 + line;
    } // 라인 번호를 저장하기 위하여 10을 곱해 기존 번호와 다른 자릿수로 만든다.
    else if (compareResult < 0) {
        insertNode(&(*root)->left, word, line);
    } // 만약 0보다 작으면 이진 탐색 트리이기에 왼쪽 자식으로 간다.
    else {
        insertNode(&(*root)->right, word, line);
    } // 아니라면 오른쪽 자식으로 간다.
}
// 단어를 비교하는 함수이다.
int compare(const char* word1, const char* word2) {
    while (*word1 && *word2) {
        if (tolower(*word1) != tolower(*word2)) {
            return tolower(*word1) - tolower(*word2);
        }
        word1++;
        word2++;
    }
    return tolower(*word1) - tolower(*word2);
} // tolower을 사용하여 대소문자 구분없이 단어를 비교한다.
// 중위 순회를 하면서 출력한다.ㄴ
void print(TNode* root) {
    if (root != NULL) {
        print(root->left);
        if (root->line > 9) {
            printf("단어: %s, 횟수: %d, 줄: %d, %d\n", root->word, root->count, root->line / 10, root->line % 10);
        } // 만약 두번 이상 나왔다면 다른 자릿수에 줄 번호가 저장되어 있으므로 각각의 값을 가져와 추출하여 출력한다.
        else {
            printf("단어: %s, 횟수: %d, 줄: %d\n", root->word, root->count, root->line);
        } // 아니라면 평범한 방식으로 출력한다.
        print(root->right);
    }
}
// 단어에서 구두점을 제거하기 위한 함수이다.
void punctuation(char* word) {
    size_t len = strlen(word);
    int i, j = 0;
    for (i = 0; i < len; i++) {
        if (!ispunct(word[i])) {
            word[j++] = word[i];
        }
    }
    word[j] = '\0';
}
// 파일의 값을 가져와 읽고, 이진 탐색 트리에 삽입한다.ㄴ
void processFile(const char* filename, TNode** root) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("파일을 불러오는데 실패하였습니다.\n");
        return;
    }
    char line[256];
    int num = 1;
    while (fgets(line, sizeof(line), file)) {
        char* word = strtok(line, " \t\n");
        while (word != NULL) {
            punctuation(word);
            insertNode(root, word, num);
            word = strtok(NULL, " \t\n");
        }
        num++;
    }
    fclose(file);
}

int main() {
    LinkedBT T;
    init_BT(&(T.root));
    const char* filename = "input.txt";
    processFile(filename, &T.root);
    print(T.root);
    return 0;
} // 먼저, 트리를 초기화 한 후 파일에서 값을 가져와 읽으면서 진행하고 출력하는 순으로 계산이 진행된다.
