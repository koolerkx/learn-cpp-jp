#pragma once
class Game
{
public:
	void start();
private:
	struct {
		int lower = 1;
		int upper = 100;
	} hint_range, config;

	void hint(int input, int ans);

	void loop();
	void reset();

	// plain text output
	void msg_welcome();
	void msg_credit();

	// utility
	int random_int();
	int random_int(int upper_limit);
};

