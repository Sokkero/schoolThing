#pragma once

#include "AppleTreeState.h"

class AppleTree;

class ApplesState : virtual public AppleTreeState
{
    public:
        ApplesState();
        ~ApplesState() = default;

        void enterState() override;
        void exitState() override {};

        void treeFertilized(AppleTree* tree) override;
        void treeWatered(AppleTree* tree) override;
        void treeShook(AppleTree* tree) override;

    private:
        int m_applesOnTree;
        int m_timesWatered;
};