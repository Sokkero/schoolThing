#include "ApplesState.h"

#include "../AppleTree.h"

#include <iostream>

ApplesState::ApplesState() : m_applesOnTree(3), m_timesWatered(0)
{
    stateMessage = "The tree seems to have apples.\nShake, water, fertilize, exit?";
};

void ApplesState::enterState()
{
    std::cout << "Tree state changed, now fully grown with apples!" << std::endl;
}

void ApplesState::treeFertilized(AppleTree* tree)
{
    std::cout << "Nothing happened. The tree is already fully grown and has apples..." << std::endl;
}

void ApplesState::treeWatered(AppleTree* tree)
{
    m_timesWatered++;

    switch(m_timesWatered)
    {
        case 1:
            std::cout << "Tree is very healthy now" << std::endl;
            break;
        case 2:
            std::cout << "Dont over water it!" << std::endl;
            break;
        case 3:
            std::cout << "Good job, you watered it too much. Its dead now. You killed. Are you happy now?"
                      << std::endl;
            tree->setState(tree->deadState);
            break;
        default:
            break;
    }
}

void ApplesState::treeShook(AppleTree* tree)
{
    if(m_applesOnTree > 0)
    {
        std::cout << "An apple fell from the tree!" << std::endl;
    }
    else if(m_applesOnTree == 0)
    {
        std::cout << "The tree has no more apples to give. Stop shaking it you greedy human..." << std::endl;
    }
    else if(m_applesOnTree == -1)
    {
        std::cout << "Stop!" << std::endl;
    }
    else if(m_applesOnTree == -2)
    {
        std::cout << "You can already hear it crack! STOP!" << std::endl;
    }
    else
    {
        std::cout << "Nicely done, the tree snapped, fell and landed on a house, killing everyone inside. Hope it was worth it buddy"
                  << std::endl;
        tree->setState(tree->deadState);
    }

    m_applesOnTree--;
}