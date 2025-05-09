#include "iostream"
#include "Game.h"

void Game::start() {
	msg_welcome();
	replay_loop();
	std::cout << std::endl;
	msg_credit();
}

void Game::replay_loop() {
	do {
		game_loop();

		bool is_end = !is_replay_dialog();
		if (is_end) {
			break;
		}
	} while (true);
}

void Game::game_loop() {
	bool is_correct = false;
	int ans = random_int();

	do {
		int input = 0;

		do {
			if (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore();
			}
			std::cout << "��������͂��Ă��������F" << std::endl;
			std::cout << "> ";
			std::cin >> input;
		} while (std::cin.fail());

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
	hint_range(input, ans);
	hint_digit(input, ans);
}

void Game::hint_range(int input, int ans) {
	// show the answer range
	if (input > ans) {
		std::cout << "�q���g�F�����͂����Ə������ł�" << std::endl;
		range_state.upper = input - 1;
	}
	else {
		std::cout << "�q���g�F�����͂����Ƒ傫���ł�" << std::endl;
		range_state.lower = input + 1;
	}
	std::cout << "������" << range_state.lower << "��" << range_state.upper << "�̊Ԃł�" << std::endl;
}

void Game::hint_digit(const int input, const int ans) {
	// wrong digit check
	// print ^ in digit when incorrect
	const int ans_digit = ans == 0 ? 1 : ((int)log10(ans)) + 1;
	const int input_digit = input == 0 ? 1 : ((int)log10(input)) + 1;

	std::cout << ans_digit << "===" << input_digit << std::endl;

	std::cout << "����\t" << input << std::endl;
	std::cout << "�ԈႢ\t";
	for (int i = std::max(input_digit, ans_digit) - 1; i >= 0; i--) {
		if (nth_digit(ans, i) != nth_digit(input, i)) {
			std::cout << "^";
		}
		else {
			std::cout << " ";
		}
	}
	std::cout << std::endl;
}

void Game::reset() {
	range_state = config;
}

// plain text output
void Game::msg_welcome() {
	std::cout << "=====�����ăQ�[��=====" << std::endl;
}

void Game::msg_credit() {
	std::cout << "���肪�Ƃ��������܂���" << std::endl;
	std::cout << "��ҁFKOOLER FAN" << std::endl;
}

bool Game::is_replay_dialog() {
	std::cout << "�������V�т܂����B(Y/N)" << std::endl;

	char input;
	bool is_replay = false;

	do {
		std::cout << "> ";
		std::cin >> input;

		if (input == 'Y') {
			is_replay = true;
			break;
		}
		else if (input == 'N') {
			is_replay = false;
			break;
		}
		else {
			std::cout << "�V�тȂ�Y�A�V�΂Ȃ��Ȃ�N����͂��Ă��������B" << std::endl;
		}
	} while (true);
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

int Game::nth_digit(int num, int n) {
	return (int)(num / pow(10, n)) % 10;
}