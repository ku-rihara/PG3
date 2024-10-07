#include <stdio.h>


int moneyCountRecursion(int workTime) {
	
	if (workTime == 1) {
		return 100;
	}
	return moneyCountRecursion((workTime - 1)) * 2 - 50;
}

int moneyCount(int workTime) {
	return 1072 * workTime;
}

int main() {

	for (int workIndex = 1; workIndex <= 9; workIndex++) {
		printf("一般的な賃金体系:%d\n", moneyCount(workIndex));
		printf("再帰的な賃金体系:%d\n", moneyCountRecursion(workIndex));
		if (moneyCount(workIndex) > moneyCountRecursion(workIndex)) {
			printf("一般的な賃金体系の方が大きい\n");
		}
		else {
			printf("再帰的な賃金体系の方が大きい");
		}
		printf("\n");
	}
	return 0;
}
