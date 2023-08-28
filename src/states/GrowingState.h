#pragma once

#include "AppleTreeState.h"

class AppleTree;

class GrowingState : virtual public AppleTreeState
{
    public:
        GrowingState();
        ~GrowingState() = default;

        void enterState() override;
        void exitState() override {};

        void treeFertilized(AppleTree* tree) override;
        void treeWatered(AppleTree* tree) override;
        void treeShook(AppleTree* tree) override;

    private:
        int m_watered;
        int m_fertilized;
};