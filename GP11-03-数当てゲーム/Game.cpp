#include "iostream"
#include "Game.h"

void Game::start() {
	msg_welcome();

	bool is_end = false;
	// replay loop
	do {
		// game loop
		loop();

		is_end = !is_replay_dialog();
	} while (!is_end);

	std::cout << std::endl;
	msg_credit();
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

bool Game::is_replay_dialog() {
	std::cout << "もう一回遊びますか。(Y/N)" << std::endl;

	char input;
	bool is_replay = false;

	bool is_exit = false;
	do {
		std::cout << "> ";
		std::cin >> input;

		if (input == 'Y') {
			is_replay = true;
			is_exit = true;
		}
		else if (input == 'N') {
			is_replay = false;
			is_exit = true;
		}
		else {
			std::cout << "遊びならY、遊ばないならNを入力してください。" << std::endl;
		}
	} while (is_exit);
	return is_replay;
}

// utility 
int Game::random_int() {
	return random_int(Game::config.upper);
}

int Game::random_int(int upper_limit) {
	srand((unsigned)time(nullptr));
	return rand() % config.upper + 1;
}