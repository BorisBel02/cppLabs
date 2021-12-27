//
// Created by Boris on 24.12.2021.
//

#include "Controller.h"



void Controller::runGame() {
    game = std::make_shared<Game>();
    view = std::make_shared<View>(game);

    std::string player1str;
    std::string player2str;
    std::cout << "Who will be the first player, Bot or Human?" << std::endl;
    std::cin >> player1str;
    std::cout << "Who will be the second player, Bot or Human?" << std::endl;
    std::cin >> player2str;

    std::shared_ptr<Player> player1 = fabric.create(player1str);
    player1->setEnemy('O');

    std::shared_ptr<Player> player2 = fabric.create(player2str);
    player2->setEnemy('X');
    while (true) {

        try {

            std::string line;
            int x;
            int y;
            if(game->getTurn() == 'X'){
                line = player1->action(game->getField());
            }
            else{
                line = player2->action(game->getField());
            }

            std::stringstream parsed(line);
            std::string command;
            if (!std::getline(parsed, command, ' ')) {
                throw gameException("wrong command");
            }
            if (command == "quit") {
                break;
            }
            std::string coord;
            if (!std::getline(parsed, coord, ' ')) {
                throw gameException("wrong command");
            }
            y = std::stoi(coord);
            if (!std::getline(parsed, coord)) {
                throw gameException("wrong command");
            }
            x = std::stoi(coord);

            if (command == "grow") {
                game->grow(x, y);
            }
            else if (command == "kill") {
                game->killEnemy(x, y);
            }


            if (game->getScore().first == 0) {
                std::cout << "Player 2 WIN!!!" << std::endl;
                break;
            }
            if (game->getScore().second == 0) {
                std::cout << "Player 1 WIN!!!" << std::endl;
                break;
            }
        }
        catch (gameException &ex) {
            std::cerr << ex.what() << std::endl;
        }
        catch (std::exception &ex) {
            std::cerr << "input error" << std::endl;
        }
    }
}
