#include <iostream>
#include "GameManager.h"

int main()
{
    Game game = Game::get_instance();

    game.execute();
    
    return 0;
}
