#include "AppleTree.h"

#include "states/ApplesState.h"
#include "states/DeadState.h"
#include "states/GrowingState.h"
#include "states/NoApplesState.h"

#include <iostream>

AppleTree::AppleTree()
    : m_currentState(nullptr)
    , growingState(std::make_shared<GrowingState>())
    , noApplesState(std::make_shared<NoApplesState>())
    , applesState(std::make_shared<ApplesState>())
    , deadState(std::make_shared<DeadState>())
{
    setState(growingState);
}

void AppleTree::setState(std::shared_ptr<AppleTreeState> state)
{
    if(m_currentState)
    {
        m_currentState->exitState();
    }

    m_currentState = state;
    m_currentState->enterState();
}

std::string AppleTree::getMessage() const
{
    return m_currentState->stateMessage;
}

void AppleTree::addFertilizer()
{
    std::cout << "You add fertilizer around the tree" << std::endl;
    m_currentState->treeFertilized(this);
}

void AppleTree::waterTree()
{
    std::cout << "You pour water around the tree" << std::endl;
    m_currentState->treeWatered(this);
}

void AppleTree::shakeTree()
{
    std::cout << "You shake the tree with force" << std::endl;
    m_currentState->treeShook(this);
}