#include <stdio.h>
#include <stdlib.h>

/* BFS ����
bfs �� visited �� �����Ҷ���, �ش� ��带 queue�� �߰��� �� �̴�.
�ش� ���� ó�� Ž�� ��ǥ�� ã���������� Ž�� ���̸� ��ȯ�ϰ� �ʹٸ�
push -> ������ Ǫ���� �������� pop (count++) -> push ... ����� ����ϴµ�
�̶� while �ȿ� for �� �ְ�, for���� pop�� �ϰ� �ȴ�
pop �� for���� �ϹǷ�, ��ǥ�� �߰��ϰ� break �ϸ� ���� while���� ���������� ���Ѵ�
�׷��Ƿ� for�� ����, for�� �߰��� break�� �������Դ��� üũ�ؾ��Ѵ�.

����� for�� ���ǹ��� true ���, �߰��� break�� ���� ���� Ȯ���� �� �ִ� (���⼱ r != endPop)
*/

int main() {
	int Subin, brother;
	int l = 0, r = 0, count = 0, endPop;
	int* nextPointqueue = (int*)malloc(300000 * sizeof(int));
	int* searched = (int*)calloc(100001 , sizeof(int));
	scanf("%d %d", &Subin, &brother);
	nextPointqueue[r] = Subin;
	r++;
	count = -1;
	while (r != l) {
		count++;
		endPop = r;
		for (; l < endPop; l++) {
			if (nextPointqueue[l] == brother) {
				break;
			}
			//printf("count %d : searching %d\n", count, nextPointqueue[l]);
			if (nextPointqueue[l] < 100000) {
				if (searched[nextPointqueue[l] + 1] == 0) {
					nextPointqueue[r] = nextPointqueue[l] + 1;
					searched[nextPointqueue[l] + 1] = 1;
					r++;
				}
				if (nextPointqueue[l] <= 50000) {
					if (searched[nextPointqueue[l] * 2] == 0) {
						nextPointqueue[r] = nextPointqueue[l] * 2;
						searched[nextPointqueue[l] * 2] = 1;
						r++;
					}
				}
			}
			if (nextPointqueue[l] > 0) {
				if (searched[nextPointqueue[l] - 1] == 0) {
					nextPointqueue[r] = nextPointqueue[l] - 1;
					searched[nextPointqueue[l] - 1] = 1;
					r++;
				}
			}
		}
		if (endPop != l) {
			break;
		}
	}
	printf("%d", count);
	free(nextPointqueue);
	free(searched);
	return 0;
}