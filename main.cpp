#include <stdio.h>


int moneyCountRecursion(int workTime) {
	
	if (workTime == 1) {
		return 100;
	}
	return moneyCountRecursion((workTime - 1)) * 2 - 50;
}
// 全体のもらえる金額を計算する関数
int totalMoney(int workTime) {
	int total = 0;
	for (int i = 1; i <= workTime; i++) {
		total += moneyCountRecursion(i);
	}
	return total;
}

int moneyCount(int workTime) {
	return 1072 * workTime;
}

int main() {
	

	for (int workIndex = 1; workIndex <= 9; workIndex++) {
		printf("一般的な賃金体系:%d\n", moneyCount(workIndex));
		printf("再帰的な賃金体系:%d\n", totalMoney(workIndex));

		if (moneyCount(workIndex) > totalMoney(workIndex)) {
			printf("一般的な賃金体系の方が大きい\n");
		}

		else {
			printf("再帰的な賃金体系の方が大きい\n");
		}

		printf("\n");
	}
	return 0;
}
