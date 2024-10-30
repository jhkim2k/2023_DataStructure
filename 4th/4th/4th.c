#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
// �ʿ��� ���̺귯�� ����
// ���� Ž�� Ʈ���� ����� ����ü�� �����Ѵ�.
typedef struct TNode {
    struct TNode* left;
    char* word;
    int count;
    int line;
    struct TNode* right;
} TNode; // Ʈ���� �ڽ� ��ҷ� ���� ���� left, right �����͸� �����ϰ�, �ܾ ������ word, �ܾ� ���� �� ��ȣ�� ���� ���� count, line ���� ����.
// ��Ʈ ��带 ���� ����ü�� �����Ѵ�.
typedef struct LinkedBT {
    TNode* root;
} LinkedBT;
// Ʈ���� �ʱ�ȭ �ϴ� �Լ�
void init_BT(TNode** root) {
    *root = NULL;
}
// ���ο� ��带 �����ϴ� �Լ��̴�.
TNode* createNode(char* word, int line) {
    TNode* newNode = (TNode*)malloc(sizeof(TNode));
    newNode->word = _strdup(word);
    newNode->count = 1;
    newNode->line = line;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
} // �Է¹��� �ܾ �����ϰ�, count�� 1�� ������ �� �� ��ȣ�� �Է¹޴´�.
// ���� Ž�� Ʈ���� ��带 �����ϰ� �Ǵ� �Լ��̴�.
void insertNode(TNode** root, char* word, int line) {
    if (*root == NULL) {
        *root = createNode(word, line);
        return *root;
    }
    // ���� ���ο� ��带 �����.
    int compareResult = compare(word, (*root)->word);
    if (compareResult == 0) {
        (*root)->count++;
        (*root)->line = (*root)->line * 10 + line;
    } // ���� ��ȣ�� �����ϱ� ���Ͽ� 10�� ���� ���� ��ȣ�� �ٸ� �ڸ����� �����.
    else if (compareResult < 0) {
        insertNode(&(*root)->left, word, line);
    } // ���� 0���� ������ ���� Ž�� Ʈ���̱⿡ ���� �ڽ����� ����.
    else {
        insertNode(&(*root)->right, word, line);
    } // �ƴ϶�� ������ �ڽ����� ����.
}
// �ܾ ���ϴ� �Լ��̴�.
int compare(const char* word1, const char* word2) {
    while (*word1 && *word2) {
        if (tolower(*word1) != tolower(*word2)) {
            return tolower(*word1) - tolower(*word2);
        }
        word1++;
        word2++;
    }
    return tolower(*word1) - tolower(*word2);
} // tolower�� ����Ͽ� ��ҹ��� ���о��� �ܾ ���Ѵ�.
// ���� ��ȸ�� �ϸ鼭 ����Ѵ�.��
void print(TNode* root) {
    if (root != NULL) {
        print(root->left);
        if (root->line > 9) {
            printf("�ܾ�: %s, Ƚ��: %d, ��: %d, %d\n", root->word, root->count, root->line / 10, root->line % 10);
        } // ���� �ι� �̻� ���Դٸ� �ٸ� �ڸ����� �� ��ȣ�� ����Ǿ� �����Ƿ� ������ ���� ������ �����Ͽ� ����Ѵ�.
        else {
            printf("�ܾ�: %s, Ƚ��: %d, ��: %d\n", root->word, root->count, root->line);
        } // �ƴ϶�� ����� ������� ����Ѵ�.
        print(root->right);
    }
}
// �ܾ�� �������� �����ϱ� ���� �Լ��̴�.
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
// ������ ���� ������ �а�, ���� Ž�� Ʈ���� �����Ѵ�.��
void processFile(const char* filename, TNode** root) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("������ �ҷ����µ� �����Ͽ����ϴ�.\n");
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
} // ����, Ʈ���� �ʱ�ȭ �� �� ���Ͽ��� ���� ������ �����鼭 �����ϰ� ����ϴ� ������ ����� ����ȴ�.
