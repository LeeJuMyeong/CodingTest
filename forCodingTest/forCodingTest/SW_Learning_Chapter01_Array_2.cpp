/*
	1.1 대표문제. Gravity_2 
	
*/

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif // _MSC_VER

#include <iostream>
#define EMPTY 0
#define BOX 1

int main() {
	int i;
	int testCase, T;
	int roomWidth, roomHeight;
	int maxFallen;
	int room[100][100] = { EMPTY, };	// 2차배열 선언 및 0으로 초기화
	int boxTop[100] = { 0, };
	int countEmptySpace;

	scanf("%d", &testCase);
	
	for (T = 0; T < testCase; T++) {
		scanf("%d%d", &roomWidth, &roomHeight);	// room의 width, height 입력
		maxFallen = 0;

		/* <내 설명> 1. 2차 배열 90도 회전으로 계산
		
		반복문 사용할 때, room의 2차 배열을 이미 90도로 회전됐다고 가정하고 반복문을 작성
		원래, for (i < roomHeight)	->   for (i < roomWidth)
				for (j < roomWidth)			for (j < roomHeight)
		*/

		for (i = 0; i < roomWidth; i++) { // 방에 상자(1)들을 채움
			scanf("%d", &boxTop[i]);
			for (int j = 0; j < boxTop[i]; j++)
				room[i][j] = BOX;	
		}

		// 각 상자 열(column)의 가장 위에 있는 상자의 낙차를 구함
		for (int i = 0; i < roomWidth; i++) {

			// < 내 설명 >
			// *중요한 부분 - 작은 효율성
			// boxTop 배열은 현재 칸에 상자가 존재 유무 확인을 위함 ( 상자 없을 경우, if문 skip )
			if (boxTop[i] > 0) {
				countEmptySpace = 0;	// 빈 칸 개수 초기화

				for (int j = i + 1; j < roomWidth; j++) {	
 
					// room[i][j]가 박스일 때 빈칸의 개수를 셈으로서 낙차를 구함
					// < 내 설명 >
					// ***중요한 부분 - 효율성 상승(빅오가 달라짐)  = O(n^3) -> O(n^2)로 변경
					// 각 상자가 있는 각 칸에서 가장 높이 있는 상자의 낙차만 구함!! 
					// 이중 반복을 사용하지 않기 때문에 
					
					if (room[j][boxTop[i] - 1] == EMPTY) {
						countEmptySpace += 1;
					}
				}
				// 이전에 구한 낙차보다 현재 낙차가 크다면 업데이트
				if (countEmptySpace > maxFallen)
					maxFallen = countEmptySpace;
			}
		}
		printf("%d\n", maxFallen);
	}
}