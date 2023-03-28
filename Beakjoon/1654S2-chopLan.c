/*
int���� �����÷� ���� �ذ�� �ΰ���
1. ������ ������ ���ǵ��� �ʴ� ������ unsigned int �� ����
2. �������� ���, ���� �� ��ȣ�� �ٲ���� ���ǹ� Ȯ��
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
	int numLines, neededLines, gottenLines;
	int* lines;
	int maxLen, l, r;
	unsigned int len;
	scanf("%d %d", &numLines, &neededLines);
	lines = (int*)malloc(numLines * sizeof(int));
	scanf("%d", &lines[0]);
	maxLen = lines[0];
	int i;
	for (i = 1; i < numLines; i++) {
		scanf("%d", &lines[i]);
		if (lines[i] > maxLen)
			maxLen = lines[i];
	}
	r = maxLen; l = 1;
	while (1) {
		if (r - l < 2)
			break;
		len = r + l;
		len /= 2;
		gottenLines = 0;
		for (i = 0; i < numLines; i++) {
			gottenLines += lines[i] / len;
			if (gottenLines < 0) {
				l = len;
				break;
			}
		}
		if (gottenLines < 0)
			continue;
		if (gottenLines >= neededLines) {
			l = len;
		}
		else if (gottenLines < neededLines) {
			r = len;
		}
	}
	if (r == l) {
		printf("%d", l);
	}
	else {
		gottenLines = 0;
		for (i = 0; i < numLines; i++) {
			gottenLines += lines[i] / r;
		}
		if (gottenLines < neededLines)
			printf("%d", l);
		else
			printf("%d", r);
	}
	free(lines);
	return 0;
}