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
		select_hint_mode();
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

			show_hint(input, ans);
		}
		std::cout << std::endl;
	} while (!is_correct);
}

void Game::select_hint_mode() {
	std::cout << "�q���g���[�h��I�����Ă��������F\n";
	std::cout << "1. �q���g�Ȃ�\n";
	std::cout << "2. �����͈̔�\n";
	std::cout << "3. �Ԉ�������̈ʒu\n";
	std::cout << "\n";

	int input = 0;
	do {
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore();
		}
		std::cout << "�I�����ڂ̐�������͂��Ă��������F" << std::endl;
		std::cout << "> ";
		std::cin >> input;
	} while (std::cin.fail() || input < 1 || input > 3);

	switch (input) {
	case 1:
		hint = nothing;
		break;
	case 2:
		hint = range;
		break;
	case 3:
		hint = digit;
		break;
	default:
		hint = nothing;
		break;
	}
}

void Game::show_hint(int input, int ans) {
	switch (hint) {
	case digit:
		show_hint_digit(input, ans);
		break;
	case range:
		show_hint_range(input, ans);
		break;
	case nothing:
	default:
		break;
	}
}

void Game::show_hint_range(int input, int ans) {
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

void Game::show_hint_digit(const int input, const int ans) {
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