#include "DeadState.h"

#include "../AppleTree.h"

#include <iostream>

DeadState::DeadState()
{
    stateMessage = "The tree is dead, all is lost...\nShake, water, fertilize, exit?";
};

void DeadState::enterState() { std::cout << "Tree state changed, now... dead... So sad..." << std::endl; }

void DeadState::treeFertilized(AppleTree* tree)
{
    std::cout << "How the f*ck is fertilizer going to help here?" << std::endl;
}

void DeadState::treeWatered(AppleTree* tree)
{
    std::cout << "Good idea! Let's waterboard the dead tree.\nYou are aware how stupid of an idea that was, right?"
              << std::endl;
}

void DeadState::treeShook(AppleTree* tree)
{
    std::cout << "You're enjoying this aren't you? Shaking a dead tree. A tree you killed. So cruel..." << std::endl;
}