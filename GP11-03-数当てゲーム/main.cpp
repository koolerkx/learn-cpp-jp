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
		std::cout << "�q���g�F�����͂����Ə������ł�" << std::endl;
		hint_range.upper = input - 1;
	}
	else {
		std::cout << "�q���g�F�����͂����Ƒ傫���ł�" << std::endl;
		hint_range.lower = input + 1;
	}

	// TODO:digit error hint

}

void game() {
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

int main() {
	// �C���g��
	std::cout << "=====�����ăQ�[��=====" << std::endl;

	// �Q�[�����[�v
	bool is_end = false;
	do {
		game();

		std::cout << "�������V�т܂����B�V�ԂȂ�uY�v����͂��Ă��������B" << std::endl;
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

	// �A�E�g��
	std::cout << std::endl;
	std::cout << "���肪�Ƃ��������܂���" << std::endl;
	std::cout << "��ҁFKOOLER FAN" << std::endl;

	std::cin.ignore();
	std::cin.get();

	return 0;
}