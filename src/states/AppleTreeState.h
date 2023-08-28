#pragma once

#include <string>

class AppleTree;

class AppleTreeState
{
    public:
        AppleTreeState() = default;
        ~AppleTreeState() = default;

        virtual void enterState() = 0;
        virtual void exitState() = 0;

        virtual void treeFertilized(AppleTree* tree) = 0;
        virtual void treeWatered(AppleTree* tree) = 0;
        virtual void treeShook(AppleTree* tree) = 0;

        std::string stateMessage;
};