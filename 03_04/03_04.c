#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 20
#define M 20
#define MAX_MOVES 100000

int main() {
    int tile[N][M] = { 0 };  // �ʱⰪ�� 0���� ����
    int moves = 0;  // ���������� �� �̵� ��
    int x = N / 2, y = M / 2;  // ���������� ���� ��ġ�� �߾�
    int dx[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };  // x ���� �̵�
    int dy[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };  // y ���� �̵�

    srand(time(NULL));  // ���� �õ� �ʱ�ȭ

    tile[x][y] = 1;  // ���� ��ġ�� 1�� ����

    while (moves < MAX_MOVES) {
        int direction = rand() % 8;  // 0~7 ������ ���� ����
        int nx = x + dx[direction];  // ���ο� x ��ġ ���
        int ny = y + dy[direction];  // ���ο� y ��ġ ���

        // ������ ����� �̵����� ����
        if (nx < 0 || nx >= N || ny < 0 || ny >= M) {
            continue;
        }

        // ���ο� ��ġ�� �̵�
        x = nx;
        y = ny;

        // Ÿ�� ���� 1�� �����Ͽ� ���������� ���������� ��Ÿ��
        tile[x][y] = 1;

        moves++;  // �̵� �� ����

        // ��� Ÿ���� 1���� �˻��Ͽ� ����
        int done = 1;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (tile[i][j] == 0) {
                    done = 0;
                    break;
                }
            }
            if (!done) {
                break;
            }
        }
        if (done) {
            break;
        }
    }

    printf("�� �̵� ��: %d\n", moves);

    return 0;
}
