#include "iostream"
#include "Game.h"

void Game::start() {
	msg_welcome();
	std::cout << "\n";
	replay_loop();
	std::cout << "\n";
	msg_credit();
}

void Game::replay_loop() {
	do {
		select_hint_mode();
		std::cout << "\n";
		select_difficulty();
		std::cout << "\n";

		reset();
		game_loop();

		std::cout << "\n";
		bool is_end = !is_replay_dialog();
		if (is_end) {
			break;
		}
	} while (true);
}

void Game::game_loop() {
	bool is_correct = false;
	int ans = random_int();

	for(int i=0; i<retry_limit; i++) {
		int input = 0;

		do {
			if (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
			std::cout << "��������͂��Ă��������F" << std::endl;
			std::cout << "> ";
			std::cin >> input;
		} while (std::cin.fail());

		std::cout << "\n";

		if (input == ans) {
			std::cout << "���߂łƂ��������܂��I���Ă܂����I" << std::endl;
			return;
		}
		else {
			if (i != retry_limit - 1) {
				std::cout << "�c�O�A�͂���ł��B������񓖂ĂĂ��������I" << std::endl;
				std::cout << "�`�����X�c��" << (retry_limit - i - 1) << "��I" << std::endl;

				std::cout << "\n";
				show_hint(input, ans);
			}
			else {
				std::cout << "�I���ł�" << std::endl;
				std::cout << "������" << ans << "�ł�" << std::endl;
			}
		}
		std::cout << std::endl;
	};
}

void Game::select_hint_mode() {
	std::cout << "=====�s�q���g�I���t=====\n";
	std::cout << "�q���g���[�h��I�����Ă��������F\n";
	std::cout << "1. �q���g�Ȃ�\n";
	std::cout << "2. �����͈̔�\n";
	std::cout << "3. �Ԉ�������̈ʒu\n";
	std::cout << "\n";

	int input = 0;
	do {
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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

void Game::select_difficulty() {
	std::cout << "=====�s��Փx�I���t=====\n";
	std::cout << "��Փx��I�����Ă��������F\n";
	std::cout << "1. ���񂽂�i1-128/10��j\n";
	std::cout << "2. �́[�܂�i1-1024/10��j\n";
	std::cout << "3. �ނ��������i11111111-99999999/8��j\n";
	std::cout << "\n";

	int input = 0;
	do {
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		std::cout << "�I�����ڂ̐�������͂��Ă��������F" << std::endl;
		std::cout << "> ";
		std::cin >> input;
	} while (std::cin.fail() || input < 1 || input > 3);

	switch (input) {
	case 1:
		difficulty = easy;
		config.lower = 1;
		config.upper = 128;
		retry_limit = 7;
		break;
	case 2:
		difficulty = normal;
		config.lower = 1;
		config.upper = 1024;
		retry_limit = 10;
		break;
	case 3:
		difficulty = hard;
		config.lower = 11111111;
		config.upper = 99999999;
		retry_limit = 8;
		break;
	default:
		difficulty = easy;
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
		hint_range_state.upper = input - 1;
	}
	else {
		std::cout << "�q���g�F�����͂����Ƒ傫���ł�" << std::endl;
		hint_range_state.lower = input + 1;
	}
	std::cout << "������" << hint_range_state.lower << "��" << hint_range_state.upper << "�̊Ԃł�" << std::endl;
}

void Game::show_hint_digit(const int input, const int ans) {
	// wrong digit check
	// print ^ in digit when incorrect
	const int ans_digit = ans == 0 ? 1 : ((int)log10(ans)) + 1;
	const int input_digit = input == 0 ? 1 : ((int)log10(input)) + 1;

	std::cout << "�s�q���g�t"<< std::endl;
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
	hint_range_state = config;
}

// plain text output
void Game::msg_welcome() {
	std::cout << "=====�����ăQ�[��=====" << std::endl;
}

void Game::msg_credit() {
	std::cout << "���肪�Ƃ��������܂����B�܂��V�т܂��傤�I" << std::endl;
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
	return random_int(Game::config.lower, Game::config.upper);
}

int Game::random_int(int lower_limit, int upper_limit) {
	// include lower_limit and upper_limit
	srand((unsigned)time(nullptr));
	return rand() % ((upper_limit + 1) - lower_limit) + lower_limit;
}

int Game::nth_digit(int num, int n) {
	return (int)(num / pow(10, n)) % 10;
}