#include <iostream>
#include <stdlib.h>
#include <time.h>

int random_int(int upper_limit=100) {
	srand((unsigned)time(nullptr));
	return rand() % 100 + 1;
}

void game() {
	bool is_correct = true;

	std::cout << "�����ăQ�[��" << std::endl;
	int ans = random_int();

	do {
		int user_input = 0;
		std::cout << "��������͂��Ă��������F";
		std::cin >> user_input;

		if (user_input == ans) {
			std::cout << "���߂łƂ��������܂��I���Ă܂����I" << std::endl;
			is_correct = false;
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
	} while (is_correct);
}

int main() {
	game();

	return 0;
}