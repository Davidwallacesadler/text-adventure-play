#include <iostream>
#include <string>

int main() 
{
    std::cout << "------------\n";
    std::cout << "Waiting Room\n";
    std::cout << "------------\n";

    std::cout << "\n";

    // 1. Select charater
    // Who are you?
    // a. Ask the user to select a person -- print the question and assign numbers to characters - middle- aged man (mark), phone lady (Alma), receptionist (stephanie)
    std::cout << "Who are you?\n";

    std::cout << "\n";

    std::cout << "1 - Mark\n";
    std::cout << "2 - Alma\n";
    std::cout << "3 - Stephanie\n";

    std::cout << "\n";
    std::cout << "Enter the number: ";

    // b. Take input from the user when they select a number
    std::string character_selection;
    std::cin >> character_selection;

    // c. Validate entry - create array of strings (the valid entries 1, 2, 3)
    std::string valid_selections[]{"1", "2", "3"};
    bool is_valid = false;
    for (int i = 0; i < 3; i++) {
        std::string selection = valid_selections[i];
        if (character_selection == selection) {
            is_valid = true;
            break;
        }
    }
    if (!is_valid) {
        std::cout << "YOU MESSED UP\n";
        return EXIT_FAILURE;
    }

    // d. Print the name name of the character that was selected
    std::cout << "\n";
    std::cout << "You've selected: ";
    if (character_selection == "1") {
        std::cout << "Mark\n";
    } else if (character_selection == "2") {
        std::cout << "Alma\n";
    } else {
        std::cout << "Stephanie\n";
    }

    // 2. Display Initial writing and options for Mark
    // a. Gather writing and get idea what we want to print out
    // b. Define actions -- check phone, blah.
    // c. Get user input
    // d. based on that go down different narrative path

    // NOTE: Have ascci art intro image to this character's story
    // std::string ascii = R"()";

    return EXIT_SUCCESS;
}