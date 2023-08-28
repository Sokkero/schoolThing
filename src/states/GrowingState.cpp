#include "GrowingState.h"

#include "../AppleTree.h"

#include <iostream>

GrowingState::GrowingState() : m_fertilized(0), m_watered(0)
{
    stateMessage = "The tree is still happily growing...\nShake, water, fertilize, exit?";
};

void GrowingState::enterState() { std::cout << "Tree state changed, now a growing tree! :)" << std::endl; }

void GrowingState::treeFertilized(AppleTree* tree)
{
    if(m_fertilized == 0)
    {
        std::cout << "The tree is now fertilized!" << std::endl;
        m_fertilized++;
    }
    else
    {
        std::cout << "Tree already fertilized..." << std::endl;
    }

    if(m_fertilized > 0 && m_watered > 0)
    {
        std::cout << "Tree is growing!" << std::endl;
        tree->setState(tree->noApplesState);
    }
}

void GrowingState::treeWatered(AppleTree* tree)
{
    if(m_watered == 0)
    {
        std::cout << "The tree is now watered sufficiently!" << std::endl;
        m_watered++;
    }
    else if(m_watered == 1)
    {
        std::cout << "Be careful not to over water it!" << std::endl;
        m_watered++;
        return;
    }
    else
    {
        std::cout << "The tree drowned... Good job tree child killer" << std::endl;
        tree->setState(tree->deadState);
        return;
    }

    if(m_fertilized > 0 && m_watered > 0)
    {
        std::cout << "Tree is growing!" << std::endl;
        tree->setState(tree->noApplesState);
    }
}

void GrowingState::treeShook(AppleTree* tree)
{
    std::cout << "That was a dumb idea, you just snapped it in half. Why would you attempt to shake a small sapling?!"
              << std::endl;
    tree->setState(tree->deadState);
}