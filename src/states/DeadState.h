#pragma once

#include "AppleTreeState.h"

class AppleTree;

class DeadState : virtual public AppleTreeState
{
    public:
        DeadState();
        ~DeadState() = default;

        void enterState() override;
        void exitState() override {};

        void treeFertilized(AppleTree* tree) override;
        void treeWatered(AppleTree* tree) override;
        void treeShook(AppleTree* tree) override;
};