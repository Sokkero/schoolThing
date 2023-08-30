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

        std::shared_ptr<AppleTreeState> m_growingState;
        std::shared_ptr<AppleTreeState> m_noApplesState;
        std::shared_ptr<AppleTreeState> m_applesState;
        std::shared_ptr<AppleTreeState> m_deadState;

    private:
        std::shared_ptr<AppleTreeState> m_currentState;
};