
#include "src/AppleTree.h"

#include <iostream>

int main()
{
    const std::unique_ptr<AppleTree> appleTree = std::make_unique<AppleTree>();

    std::cout << "You come across a cute little sapling. Its happily growing in the dry earth." << std::endl;
    std::string input;
    while(true)
    {
        std::cout << "\n" << appleTree->getMessage() << std::endl;
        std::cin >> input;

        std::transform(input.begin(), input.end(), input.begin(), [](unsigned char c){ return std::tolower(c); });

        if(input == "exit")
        {
            std::cout << "You left" << std::endl;
            return 0;
        }
        else if(input == "water")
        {
            appleTree->waterTree();
        }
        else if(input == "fertilize")
        {
            appleTree->addFertilizer();
        }
        else if(input == "shake")
        {
            appleTree->shakeTree();
        }
        else
        {
            std::cout << "Let's try this again..." << std::endl;
        }
    }
}
