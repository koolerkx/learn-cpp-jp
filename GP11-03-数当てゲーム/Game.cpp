#include "iostream"
#include "Game.h"

void Game::start() {
	this->msg_welcome();

	bool is_end = false;
	do {
		loop();

		std::cout << "もう一回遊びますか。遊ぶなら「Y」を入力してください。" << std::endl;
		std::cout << "> ";
		char input;
		std::cin >> input;
		if (input == 'Y') {
			reset();
			continue;
		}
		else {
			is_end = true;
		}
	} while (!is_end);

	std::cout << std::endl;
	this->msg_credit();
}

void Game::loop() {
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

void Game::hint(int input, int ans) {
	// limit hint
	if (input > ans) {
		std::cout << "ヒント：数字はもっと小さいです" << std::endl;
		hint_range.upper = input - 1;
	}
	else {
		std::cout << "ヒント：数字はもっと大きいです" << std::endl;
		hint_range.lower = input + 1;
	}
}

void Game::reset() {
	hint_range = config;
}

// plain text output
void Game::msg_welcome() {
	std::cout << "=====数当てゲーム=====" << std::endl;
}

void Game::msg_credit() {
	std::cout << "ありがとうございました" << std::endl;
	std::cout << "作者：KOOLER FAN" << std::endl;
}

// utility 
int Game::random_int() {
	return random_int(Game::config.upper);
}

int Game::random_int(int upper_limit) {
	srand((unsigned)time(nullptr));
	return rand() % config.upper + 1;
}