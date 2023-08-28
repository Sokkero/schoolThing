#pragma once

#include <string>

class AppleTreeState;

class AppleTree
{
    public:
        AppleTree();
        ~AppleTree() = default;

        void addFertilizer();
        void waterTree();
        void shakeTree();

        void setState(std::shared_ptr<AppleTreeState> state);
        std::string getMessage() const;

        std::shared_ptr<AppleTreeState> growingState;
        std::shared_ptr<AppleTreeState> noApplesState;
        std::shared_ptr<AppleTreeState> applesState;
        std::shared_ptr<AppleTreeState> deadState;

    private:
        std::shared_ptr<AppleTreeState> m_currentState;
};