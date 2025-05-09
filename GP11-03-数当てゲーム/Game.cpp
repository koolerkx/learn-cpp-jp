#include "iostream"
#include "Game.h"

void Game::start() {
	this->msg_welcome();

	bool is_end = false;
	do {
		loop();

		std::cout << "�������V�т܂����B�V�ԂȂ�uY�v����͂��Ă��������B" << std::endl;
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
		std::cout << "��������͂��Ă�������(" << hint_range.lower << "-" << hint_range.upper << ")�F" << std::endl;
		std::cout << "> ";
		std::cin >> input;

		if (input == ans) {
			std::cout << "���߂łƂ��������܂��I���Ă܂����I" << std::endl;
			is_correct = true;
		}
		else {
			std::cout << "�c�O�A�͂���ł��B������񓖂ĂĂ��������I" << std::endl;

			hint(input, ans);
		}
		std::cout << std::endl;
	} while (!is_correct);
}

void Game::hint(int input, int ans) {
	// limit hint
	if (input > ans) {
		std::cout << "�q���g�F�����͂����Ə������ł�" << std::endl;
		hint_range.upper = input - 1;
	}
	else {
		std::cout << "�q���g�F�����͂����Ƒ傫���ł�" << std::endl;
		hint_range.lower = input + 1;
	}
}

void Game::reset() {
	hint_range = config;
}

// plain text output
void Game::msg_welcome() {
	std::cout << "=====�����ăQ�[��=====" << std::endl;
}

void Game::msg_credit() {
	std::cout << "���肪�Ƃ��������܂���" << std::endl;
	std::cout << "��ҁFKOOLER FAN" << std::endl;
}

// utility 
int Game::random_int() {
	return random_int(Game::config.upper);
}

int Game::random_int(int upper_limit) {
	srand((unsigned)time(nullptr));
	return rand() % config.upper + 1;
}