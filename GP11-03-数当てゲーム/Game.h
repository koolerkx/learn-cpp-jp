#pragma once
class Game
{
public:
	void start();
private:
	struct Range {
		int lower = 1;
		int upper = 100;
	};
	Range hint_range, config;

	void hint(int input, int ans);

	void replay_loop();
	void game_loop();
	void reset();

	// plain text output
	void msg_welcome();
	void msg_credit();
	bool is_replay_dialog();

	// utility
	int random_int();
	int random_int(int upper_limit);
};

