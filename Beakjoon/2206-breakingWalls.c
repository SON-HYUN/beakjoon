#include <stdio.h>
#include <stdlib.h>

void push(int** queue, int* r, int x, int y, int flag) {
	queue[*r][0] = flag; queue[*r][1] = x; queue[*r][2] = y;
	(*r)++;
}

int main() {
	// [i][0] : �� ��Ʈ���� �� �μ� Ƚ��, [i][1] : x��ǥ, [i][2] : y��ǥ
	int** queue;
	// [y][x] �� ����, 0�̸� �̹湮, 1�̸� �� ���� �湮, 2�̸� �̹� �湮
	char** visited;
	char** map;
	int l = 0, r = 0;
	int length, height, x, y, flag, endPop, dist  = 0;
	int isFailed = -1;
	char ch = '\n';

	scanf("%d %d", &height, &length);
	visited = (char**)malloc(height * sizeof(char*));
	map = (char**)malloc(height * sizeof(char*));
	int i, k;
	for (i = 0; i < height; i++) {
		visited[i] = (char*)calloc(length, sizeof(char));
		map[i] = (char*)calloc(length, sizeof(char));
		for (k = 0; k < length; k++) {
			scanf("%c", &ch);
			while (ch == '\n') {
				scanf("%c", &ch);
			}
			map[i][k] = ch - '0';
		}
	}

	queue = (int**)calloc(2 * length * height, sizeof(int*));
	for (k = 0; k < 2 * height * length; k++) {
		queue[k] = (int*)calloc(3, sizeof(int));
	}

	queue[r][0] = 0; queue[r][1] = 0; queue[r][2] = 0;
	r++;
	visited[0][0] = 2;
	
	while (l != r) {
		//printf("\n***%d\n" ,dist);
		dist++;
		endPop = r;
		for (; l < endPop; l++) {
			x = queue[l][1]; y = queue[l][2]; flag = queue[l][0];
			if (x == length - 1 && y == height - 1) {
				break;
			}
			if (flag == 0) {
				if (x > 0) {
					if (map[y][x - 1] == 0) {
						if (visited[y][x - 1] < 2) {
							push(queue, &r, x - 1, y, 0);
							//printf("%d %d => %d %d\n", x, y, x - 1, y);
							visited[y][x - 1] = 2;
						}
					}
					else {
						if (visited[y][x-1] < 1) {
							push(queue, &r, x - 1, y, 1);
							//printf("%d %d => %d %d\n", x, y, x - 1, y);
							visited[y][x - 1] = 1;
						}
					}
				}
				if (y > 0) {
					if (map[y - 1][x] == 0) {
						if (visited[y - 1][x] < 2) {
							push(queue, &r, x, y - 1, 0);
							//printf("%d %d => %d %d\n", x, y, x, y - 1);
							visited[y - 1][x] += 2;
						}
					}
					else {
						if (visited[y-1][x] < 1) {
							push(queue, &r, x, y - 1, 1);
							//printf("%d %d => %d %d\n", x, y, x, y - 1);
							visited[y - 1][x] = 1;
						}
					}
				}
				if (x < length - 1) {
					if (map[y][x + 1] == 0) {
						if (visited[y][x + 1] < 2) {
							push(queue, &r, x + 1, y, 0);
							//printf("%d %d => %d %d\n", x, y, x + 1, y);
							visited[y][x + 1] = 2;
						}
					}
					else {
						if (visited[y][x+1] < 1) {
							push(queue, &r, x + 1, y, 1);
							//printf("%d %d => %d %d\n", x, y, x + 1, y);
							visited[y][x + 1] = 1;
						}
					}
				}
				if (y < height - 1) {
					if (map[y + 1][x] == 0) {
						if (visited[y + 1][x] < 2) {
							push(queue, &r, x, y + 1, 0);
							//printf("%d %d => %d %d\n", x, y, x, y + 1);
							visited[y + 1][x] = 2;
						}
					}
					else {
						if (visited[y + 1][x] < 1) {
							push(queue, &r, x, y + 1, 1);
							//printf("%d %d => %d %d\n", x, y, x, y + 1);
							visited[y + 1][x] = 1;
						}
					}
				}
			}
			else {
				if (x > 0 && visited[y][x - 1] == 0 && map[y][x - 1] == 0) {
					push(queue, &r, x - 1, y, 1);
					//printf("%d %d => %d %d\n", x, y, x - 1, y);
					visited[y][x - 1] = 1;
				}
				if (y > 0 && visited[y - 1][x] == 0 && map[y - 1][x] == 0) {
					push(queue, &r, x, y - 1, 1);
					//printf("%d %d => %d %d\n", x, y, x, y - 1);
					visited[y - 1][x] = 1;
				}
				if (x < length - 1 && visited[y][x + 1] == 0 && map[y][x + 1] == 0) {
					push(queue, &r, x + 1, y, 1);
					//printf("%d %d => %d %d\n", x, y, x + 1, y);
					visited[y][x + 1] = 1;
				}
				if (y < height - 1 && visited[y + 1][x] == 0 && map[y + 1][x] == 0) {
					push(queue, &r, x, y + 1, 1);
					//printf("%d %d => %d %d\n", x, y, x, y + 1);
					visited[y + 1][x] = 1;
				}
			}
		}
		if (l != endPop) {
			isFailed = 0;
			break;
		}
	}

	if (isFailed != -1) {
		printf("%d", dist);
	}
	else {
		printf("-1");
	}

	for (i = 0; i < height; i++) {
		free(visited[i]);
		free(map[i]);
	}
	for (k = 0; k < 2 * height * length; k++) {
		free(queue[k]);
	}
	free(visited);
	free(map);
	free(queue);
	return 0;
}