#include "NoApplesState.h"

#include "../AppleTree.h"

#include <iostream>

NoApplesState::NoApplesState() : m_fertilized(0), m_watered(0)
{
    stateMessage = "The tree is fully grown. Hope it will grow apples too...\nShake, water, fertilize, exit?";
};

void NoApplesState::enterState()
{
    std::cout << "Tree state changed, now a grown tree! Water and fertilize it to let it grow apples! :)"
              << std::endl;
}

void NoApplesState::treeFertilized(AppleTree* tree)
{
    if(m_fertilized == 0)
    {
        std::cout << "The tree is now fertilized!" << std::endl;
        m_fertilized++;
    }

    if(m_fertilized > 0 && m_watered > 0)
    {
        std::cout << "Tree is growing apples!" << std::endl;
        tree->setState(tree->m_applesState);
    }
    else
    {
        std::cout << "Tree already fertilized..." << std::endl;
    }
}

void NoApplesState::treeWatered(AppleTree* tree)
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
    }
    else
    {
        std::cout << "The tree drowned... Good job tree killer" << std::endl;
        tree->setState(tree->m_deadState);
    }

    if(m_fertilized > 0 && m_watered > 0)
    {
        std::cout << "Tree is growing apples!" << std::endl;
        tree->setState(tree->m_applesState);
    }
    else
    {
        std::cout << "Tree already watered..." << std::endl;
    }
}

void NoApplesState::treeShook(AppleTree* tree)
{
    m_shakeCount++;

    if(m_shakeCount == 1)
    {
        std::cout << "Nothing happened..." << std::endl;
    }
    else if(m_shakeCount == 2)
    {
        std::cout << "Still nothing happening..." << std::endl;
    }
    else if(m_shakeCount == 3)
    {
        std::cout << "You hear a crack in the tree..." << std::endl;
    }
    else
    {
        std::cout << "The tree snaps, falls and lands on a dog house full of puppies. Good job puppy killer, hope youre happy now!"
                  << std::endl;
        tree->setState(tree->m_deadState);
    }
}