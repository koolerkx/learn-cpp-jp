#include <iostream>
#include <stdlib.h>
#include <time.h>

struct {
	int  lower = 1;
	int upper = 100;
} hint_range, config;

int random_int(int upper_limit = config.upper) {
	srand((unsigned)time(nullptr));
	return rand() % config.upper + 1;
}

void hint(int input, int ans) {
	// limit hint
	if (input > ans) {
		std::cout << "ヒント：数字はもっと小さいです" << std::endl;
		hint_range.upper = input - 1;
	}
	else {
		std::cout << "ヒント：数字はもっと大きいです" << std::endl;
		hint_range.lower = input + 1;
	}

	// TODO:digit error hint

}

void game() {
	bool is_correct = false;
	int ans = random_int();

	do {
		int input = 0;
		std::cout << "数字を入力してください(" << hint_range.lower << "-" << hint_range.upper << ")：" << std::endl;
		std::cout << "> ";
		std::cin >> input;

		if (input == ans) {
			std::cout << "おめでとうございます！当てました！" << std::endl;
			is_correct = true;
		}
		else {
			std::cout << "残念、はずれです。もう一回当ててください！" << std::endl;

			hint(input, ans);
		}
		std::cout << std::endl;
	} while (!is_correct);
}

int main() {
	// イントロ
	std::cout << "=====数当てゲーム=====" << std::endl;

	// ゲームループ
	bool is_end = false;
	do {
		game();

		std::cout << "もう一回遊びますか。遊ぶなら「Y」を入力してください。" << std::endl;
		std::cout << "> ";
		char input;
		std::cin >> input;
		if (input == 'Y') {
			continue;
		}
		else {
			is_end = true;
		}
	} while (!is_end);

	// アウトロ
	std::cout << std::endl;
	std::cout << "ありがとうございました" << std::endl;
	std::cout << "作者：KOOLER FAN" << std::endl;

	std::cin.ignore();
	std::cin.get();

	return 0;
}