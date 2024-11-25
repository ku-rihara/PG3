#include <stdio.h>
#include<memory>
#include<list>
/// class

int main() {
	// 1970年
	std::list<const char*>yamanotesen{
		"Tokyo","Kanda","Akihabara","Okachimachi","Ueno","Uguisudani",
		"Nippori","Tabata","Komagome","Sugamo","Otsuka",
		"Ikebukuro", "Mejiro","Takadanobaba","Shin-Okubo","Shinjuku",
		"Yoyogi","Harajuku","Shibuya","Ebisu","Meguro","Gotanda",
		"Osaki","Shinagawa","Tamachi","Hamamatsucho","Shimbashi", "Yurakucho"
	};

	printf("******************1970年の山手線******************");
	for (std::list<const char*>::iterator itr = yamanotesen.begin(); itr != yamanotesen.end(); ++itr) {/// 駅を回す
		printf("\n%s", *itr);
	}

	/// 2019
	for (std::list<const char*>::iterator itr = yamanotesen.begin(); itr != yamanotesen.end(); ++itr) {///西日暮里の追加
		if (*itr == "Tabata") {
			itr = yamanotesen.insert(itr, "Nishi-Nippori");
			itr++;
		}
	}
	printf("\n******************2019年の山手線******************");
	for (std::list<const char*>::iterator itr = yamanotesen.begin(); itr != yamanotesen.end(); ++itr) {/// 駅を回す
		printf("\n%s", *itr);
	}

	/// 2022
	for (std::list<const char*>::iterator itr = yamanotesen.begin(); itr != yamanotesen.end(); ++itr) {///高輪ゲートウェイの追加
		if (*itr == "Tamachi") {
			itr = yamanotesen.insert(itr, "Takanawa Gateway");
			itr++;
		}
	}

	printf("\n******************2022年の山手線******************");
	for (std::list<const char*>::iterator itr = yamanotesen.begin(); itr != yamanotesen.end(); ++itr) {/// 駅を回す
		printf("\n%s", *itr);
	}


	return 0;
}
