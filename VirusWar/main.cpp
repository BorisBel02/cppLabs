#include <iostream>
#include <memory>
#include "Controller.h"

int main() {
    std::shared_ptr<Controller> instance;
    instance = std::make_shared<Controller>();
    instance->runGame();
}
