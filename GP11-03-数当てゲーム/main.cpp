#include <iostream>
#include <stdlib.h>
#include <time.h>

int random_int(int upper_limit=100) {
	srand((unsigned)time(nullptr));
	return rand() % 100 + 1;
}

void game() {
	bool is_correct = true;

	std::cout << "数当てゲーム" << std::endl;
	int ans = random_int();

	do {
		int user_input = 0;
		std::cout << "数字を入力してください：";
		std::cin >> user_input;

		if (user_input == ans) {
			std::cout << "おめでとうございます！当てました！" << std::endl;
			is_correct = false;
		}
		else {
			std::cout << "残念、もう一回当ててください！" << std::endl;

			if (user_input > ans) {
				std::cout << "ヒント：数字はもっと小さいです" << std::endl;
			}
			else {
				std::cout << "ヒント：数字はもっと大きいです" << std::endl;
			}
		}
	} while (is_correct);
}

int main() {
	game();

	return 0;
}