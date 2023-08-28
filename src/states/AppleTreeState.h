#pragma once

class AppleTree;

class AppleTreeState
{
    public:
        AppleTreeState() = default;
        ~AppleTreeState() = default;

        virtual void treeFertilized(AppleTree tree) = 0;
        virtual void treeWatered(AppleTree tree) = 0;
        virtual void treeShook(AppleTree tree) = 0;
};