#include <stdio.h>
#include <stdlib.h>

int main() {
	// [i][0] : �� ��Ʈ���� �� �μ� Ƚ��, [i][1] : x��ǥ, [i][2] : y��ǥ
	int** queue;
	// [y][x] �� ����, 0�̸� �̹湮, 1�̸� �� ���� �湮, 2�̸� �� �ȱ��� �湮, 3�̸� ��� ��쿡�� �湮
	int** visited, ** map;
	int l = 0, r = 0;
	int length, height, x, y, flag;

	scanf("%d %d", &height, &length);
	queue = (int**)calloc(length * height, sizeof(int*));
	visited = (int**)calloc(length, sizeof(int*));
	map = (int**)calloc(length, sizeof(int*));
	int i, k;
	for (i = 0; i < height; i++) {
		visited[i] = (int*)calloc(length, sizeof(int));
		map[i] = (int*)calloc(length, sizeof(int));
		for (k = 0; k < length; k++) {
			queue[i * length + k] = (int*)calloc(3, sizeof(int));
			scanf("%c", map[i][k]);
			map[i][k] -= '0';
		}
	}

	queue[r][0] = 0; queue[r][1] = 0; queue[r][2] = 0;
	r++;
	
	while (l != r) {
		x = queue[l][1]; y = queue[l][2]; flag = queue[l][0];
		l++;
		if (x > 0) {
			if (map[y][x - 1] == 0) {
				queue[r][0] = flag; queue[r][1] = x - 1; queue[r][2] = y;
				r++;
			}
			else {
				if (flag == 0) {
					queue[r][1] = 1; queue[r][1] = x - 1; queue[r][2] = y;
					r++;
				}
			}
		}
		if (y > 0) {
			if (map[y - 1][x] == 0) {
				queue[r][0] = flag; queue[r][1] = x; queue[r][2] = y - 1;
				r++;
			}
			else {
				if (flag == 0) {
					queue[r][1] = 1; queue[r][1] = x; queue[r][2] = y - 1;
					r++;
				}
			}
		}
		if (x < length - 1) {
			if (map[y][x + 1] == 0) {
				queue[r][0] = flag; queue[r][1] = x + 1; queue[r][2] = y;
				r++;
			}
			else {
				if (flag == 0) {
					queue[r][1] = 1; queue[r][1] = x + 1; queue[r][2] = y;
					r++;
				}
			}
		}
	}
}