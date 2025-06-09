#include <iostream>
#include "GameManager.h"

int main()
{
    GameManager& gm = GameManager::get_instance();

    gm.start_loop();
    return 0;
}
