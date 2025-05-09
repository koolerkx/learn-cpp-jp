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
		std::cout << "\n";
		select_difficulty();
		std::cout << "\n";

		reset();
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
			std::cout << "数字を入力してください：" << std::endl;
			std::cout << "> ";
			std::cin >> input;
		} while (std::cin.fail());

		if (input == ans) {
			std::cout << "おめでとうございます！当てました！" << std::endl;
			is_correct = true;
		}
		else {
			std::cout << "残念、はずれです。もう一回当ててください！" << std::endl;

			show_hint(input, ans);
		}
		std::cout << std::endl;
	} while (!is_correct);
}

void Game::select_hint_mode() {
	std::cout << "=====《ヒント選択》=====\n";
	std::cout << "ヒントモードを選択してください：\n";
	std::cout << "1. ヒントなし\n";
	std::cout << "2. 答えの範囲\n";
	std::cout << "3. 間違った桁の位置\n";
	std::cout << "\n";

	int input = 0;
	do {
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore();
		}
		std::cout << "選択項目の数字を入力してください：" << std::endl;
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
	std::cout << "=====《難易度選択》=====\n";
	std::cout << "難易度を選択してください：\n";
	std::cout << "1. かんたん（1-128/10回）\n";
	std::cout << "2. のーまる（1-1024/10回）\n";
	std::cout << "3. むずかしい（11111111-99999999/8回）\n";
	std::cout << "\n";

	int input = 0;
	do {
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore();
		}
		std::cout << "選択項目の数字を入力してください：" << std::endl;
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
		std::cout << "ヒント：数字はもっと小さいです" << std::endl;
		hint_range_state.upper = input - 1;
	}
	else {
		std::cout << "ヒント：数字はもっと大きいです" << std::endl;
		hint_range_state.lower = input + 1;
	}
	std::cout << "答えは" << hint_range_state.lower << "と" << hint_range_state.upper << "の間です" << std::endl;
}

void Game::show_hint_digit(const int input, const int ans) {
	// wrong digit check
	// print ^ in digit when incorrect
	const int ans_digit = ans == 0 ? 1 : ((int)log10(ans)) + 1;
	const int input_digit = input == 0 ? 1 : ((int)log10(input)) + 1;

	std::cout << "《ヒント》"<< std::endl;
	std::cout << "入力\t" << input << std::endl;
	std::cout << "間違い\t";
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
			std::cout << "遊びならY、遊ばないならNを入力してください。" << std::endl;
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