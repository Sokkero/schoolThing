#pragma once

class AppleTreeState;

class AppleTree
{
    public:
        AppleTree();
        ~AppleTree() = default;

        void addFertilizer();
        void waterTree();
        void shakeTree();
    private:
        AppleTreeState* GrowingState;
        AppleTreeState* NoApplesState;
        AppleTreeState* ApplesState;
        AppleTreeState* DeadState;

        AppleTreeState* CurrentState;
};