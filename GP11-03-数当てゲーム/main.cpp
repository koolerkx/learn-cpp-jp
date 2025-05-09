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
		std::cout << "��������͂��Ă��������F";
		std::cin >> user_input;

		if (user_input == ans) {
			std::cout << "���߂łƂ��������܂��I���Ă܂����I" << std::endl;
			is_correct = true;
		}
		else {
			std::cout << "�c�O�A������񓖂ĂĂ��������I" << std::endl;

			if (user_input > ans) {
				std::cout << "�q���g�F�����͂����Ə������ł�" << std::endl;
			}
			else {
				std::cout << "�q���g�F�����͂����Ƒ傫���ł�" << std::endl;
			}
		}
	} while (!is_correct);
}

int main() {
	// �C���g��
	std::cout << "=====�����ăQ�[��=====" << std::endl;

	// �Q�[�����[�v
	bool is_continue = true;
	do {
		game();

		std::cout << "�������V�т܂����B�V�ԂȂ�uY�v����͂��Ă��������B" << std::endl;
		char input;
		std::cin >> input;
		if (input == 'Y') {
			continue;
		}
		else {
			is_continue = false;
		}
	} while (is_continue);

	// �A�E�g��
	std::cout << "���肪�Ƃ��������܂���" << std::endl;
	std::cout << "��ҁFKOOLER FAN" << std::endl;

	std::cin.ignore();
	std::cin.get();

	return 0;
}