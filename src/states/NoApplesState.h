#pragma once

#include "AppleTreeState.h"

class AppleTree;

class NoApplesState : virtual public AppleTreeState
{
    public:
        NoApplesState();
        ~NoApplesState() = default;

        void enterState() override;
        void exitState() override {};

        void treeFertilized(AppleTree* tree) override;
        void treeWatered(AppleTree* tree) override;
        void treeShook(AppleTree* tree) override;

    private:
        int m_watered;
        int m_fertilized;
        int m_shakeCount;
};