/*
	1.1 ��ǥ����. Gravity_2 
	
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
	int room[100][100] = { EMPTY, };	// 2���迭 ���� �� 0���� �ʱ�ȭ
	int boxTop[100] = { 0, };
	int countEmptySpace;

	scanf("%d", &testCase);
	
	for (T = 0; T < testCase; T++) {
		scanf("%d%d", &roomWidth, &roomHeight);	// room�� width, height �Է�
		maxFallen = 0;

		/* <�� ����> 1. 2�� �迭 90�� ȸ������ ���
		
		�ݺ��� ����� ��, room�� 2�� �迭�� �̹� 90���� ȸ���ƴٰ� �����ϰ� �ݺ����� �ۼ�
		����, for (i < roomHeight)	->   for (i < roomWidth)
				for (j < roomWidth)			for (j < roomHeight)
		*/

		for (i = 0; i < roomWidth; i++) { // �濡 ����(1)���� ä��
			scanf("%d", &boxTop[i]);
			for (int j = 0; j < boxTop[i]; j++)
				room[i][j] = BOX;	
		}

		// �� ���� ��(column)�� ���� ���� �ִ� ������ ������ ����
		for (int i = 0; i < roomWidth; i++) {

			// < �� ���� >
			// *�߿��� �κ� - ���� ȿ����
			// boxTop �迭�� ���� ĭ�� ���ڰ� ���� ���� Ȯ���� ���� ( ���� ���� ���, if�� skip )
			if (boxTop[i] > 0) {
				countEmptySpace = 0;	// �� ĭ ���� �ʱ�ȭ

				for (int j = i + 1; j < roomWidth; j++) {	
 
					// room[i][j]�� �ڽ��� �� ��ĭ�� ������ �����μ� ������ ����
					// < �� ���� >
					// ***�߿��� �κ� - ȿ���� ���(����� �޶���)  = O(n^3) -> O(n^2)�� ����
					// �� ���ڰ� �ִ� �� ĭ���� ���� ���� �ִ� ������ ������ ����!! 
					// ���� �ݺ��� ������� �ʱ� ������ 
					
					if (room[j][boxTop[i] - 1] == EMPTY) {
						countEmptySpace += 1;
					}
				}
				// ������ ���� �������� ���� ������ ũ�ٸ� ������Ʈ
				if (countEmptySpace > maxFallen)
					maxFallen = countEmptySpace;
			}
		}
		printf("%d\n", maxFallen);
	}
}