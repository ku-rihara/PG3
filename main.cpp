#include <stdio.h>
#include<vector>
#include<string>
#include <fstream>
#include<algorithm>

// ソートするための番号を取得
int getNumber(const std::string& ID) {
	size_t pos = ID.find('g');
return	std::stoi(ID.substr(pos + 1, 4));
}

int main() {
	
	const std::string fileName = "PG3_2024_03_02.txt";
	std::vector<std::string>studentID;

	//　ファイルを開く
	std::ifstream file(fileName);
	if (!file.is_open()) {// 開けなかったら
		return 1;
	}

	std::string line;
	// ,区切りで読む
	while (std::getline(file, line, ',')) {
		if (!line.empty()) {
			studentID.push_back(line);//vectorに格納
		}
	}
	file.close();// ファイル閉じる

	// ソート
	std::sort(studentID.begin(), studentID.end(), [](const std::string& a, const std::string& b) {
		return getNumber(a)< getNumber(b);
		});

	// ソート結果を出力
	for (const auto& id : studentID) {
		printf("%s\n", id.c_str());
	}
	return 0;
}
