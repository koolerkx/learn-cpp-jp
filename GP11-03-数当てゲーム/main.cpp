#include <iostream>
#include <stdlib.h>
#include <time.h>

int random_int(int upper_limit=100) {
	srand((unsigned)time(nullptr));
	return rand() % upper_limit + 1;
}

void game() {
	bool is_correct = false;
	int ans = random_int();

	do {
		int user_input = 0;
		std::cout << "数字を入力してください：";
		std::cin >> user_input;

		if (user_input == ans) {
			std::cout << "おめでとうございます！当てました！" << std::endl;
			is_correct = true;
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
	} while (!is_correct);
}

int main() {
	// イントロ
	std::cout << "=====数当てゲーム=====" << std::endl;

	// ゲームループ
	bool is_continue = true;
	do {
		game();

		std::cout << "もう一回遊びますか。遊ぶなら「Y」を入力してください。" << std::endl;
		char input;
		std::cin >> input;
		if (input == 'Y') {
			continue;
		}
		else {
			is_continue = false;
		}
	} while (is_continue);

	// アウトロ
	std::cout << "ありがとうございました" << std::endl;
	std::cout << "作者：KOOLER FAN" << std::endl;

	std::cin.ignore();
	std::cin.get();

	return 0;
}