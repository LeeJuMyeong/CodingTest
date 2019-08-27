/*
	Chapter 1. 배열(Array)

	1.1 대표문제. Gravity
*/
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif // _MSC_VER

#include <iostream>

#define EMPTY 0
#define BOX 1

int main() {
	int i, j, k;
	int testCase;
	int T;
	int room[100][100];
	int roomWidth, roomHeight;
	int boxHeight;
	int maxFallen;
	int countEmptySpace;

	scanf("%d", &testCase);

	for (T = 0; T < testCase; T++) {
		scanf("%d%d", &roomWidth, &roomHeight);

		//초기화
		for (i = 0; i < roomWidth; i++) {
			for (j = 0; j < roomHeight; j++) {
				room[i][j] = EMPTY;
			}
			maxFallen = 0;
		}
		for (i = 0; i < roomWidth; i++) {	// 방에 상자들을 채움
			scanf("%d", &boxHeight);
			for (j = 0; j < boxHeight; j++) {
				room[i][j] = BOX;
			}
		}

		// 각 상자의 낙차를 구함
		for (i = 0; i < roomWidth; i++) {
			for (j = 0; j < roomHeight; j++) {
				// room[i][j]가 박스일때 빈칸의 개수를 셈으로서 낙차를 구함
				if (room[i][j] == BOX) {
					countEmptySpace = 0;

					for (k = i + 1; k < roomWidth; k++) {
						if (room[k][j] == EMPTY)
							countEmptySpace += 1;
					}
					// 이전에 구한 낙차보다 현재 낙차가 크다면 업데이트
					if (countEmptySpace > maxFallen)
						maxFallen = countEmptySpace;
				}
			}
		}
		printf("%d\n", maxFallen);
	}
}