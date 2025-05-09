#pragma once

enum Hint { nothing, range, digit};
enum Difficulty {easy, normal, hard};

class Game
{
public:
	void start();
private:
	struct Range {
		int lower = 1;
		int upper = 100;
	};
	int retry_limit = 10;
	Range hint_range_state, config;
	Hint hint = nothing;
	Difficulty difficulty = easy;

	// game control
	void show_hint(int input, int ans);
	void show_hint_range(int input, int ans);
	void show_hint_digit(int input, int ans);

	void replay_loop();
	void game_loop();

	void select_hint_mode();
	void select_difficulty();
	void reset();

	// plain text output
	void msg_welcome();
	void msg_credit();
	bool is_replay_dialog();

	// utility
	int random_int();
	int random_int(int lower_limit, int upper_limit);
	int nth_digit(int num, int n);
};

