#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 20
#define M 20
#define MAX_MOVES 100000

int main() {
    int tile[N][M] = { 0 };  // 초기값은 0으로 설정
    int moves = 0;  // 딱정벌레의 총 이동 수
    int x = N / 2, y = M / 2;  // 딱정벌레의 시작 위치는 중앙
    int dx[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };  // x 방향 이동
    int dy[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };  // y 방향 이동

    srand(time(NULL));  // 랜덤 시드 초기화

    tile[x][y] = 1;  // 시작 위치에 1로 설정

    while (moves < MAX_MOVES) {
        int direction = rand() % 8;  // 0~7 랜덤한 방향 생성
        int nx = x + dx[direction];  // 새로운 x 위치 계산
        int ny = y + dy[direction];  // 새로운 y 위치 계산

        // 범위를 벗어나면 이동하지 않음
        if (nx < 0 || nx >= N || ny < 0 || ny >= M) {
            continue;
        }

        // 새로운 위치로 이동
        x = nx;
        y = ny;

        // 타일 값을 1로 설정하여 딱정벌레가 지나갔음을 나타냄
        tile[x][y] = 1;

        moves++;  // 이동 수 증가

        // 모든 타일이 1인지 검사하여 종료
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

    printf("총 이동 수: %d\n", moves);

    return 0;
}
