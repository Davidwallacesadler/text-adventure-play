#include <iostream>
#include <string>

// Encapsulates a single action in the story 
struct StoryAction {
    // display text for the action
    std::string display_text;

    // the number that must be input for the action to take place
    std::string number;

    // identifies the next beat in the story via an id 
    std::string next_beat_id;
};

// Encapsulates a single beat in the story
struct StoryBeat {
    // identifies this particular story beat, used to reference beats from actions
    std::string id;

    // image associated with story beat to be displayed at beginning of the beat
    std::string ascii_image;

    // main narrative for beat, to be displayed
    std::string narrative_block;
    
    // array of actions for the beat
    StoryAction actions[3];
};

StoryBeat mark_beats[]{
    StoryBeat{
        "MARK-1",
        R"(
        .:::::::.
      .'     ':::
      :        ::.
      :-  --   ' :
      :        ..:
      :.--    .'::;
      ::.__ .'  ':;_
      ::/""".    .' ""-._
      ::\   |   :        :
     .:::  .'..'          '
    . :'  .         '     ':
    : '  .:        .     . .
    :'   .:        :    .:  "--__
   /'   .::        :   .
  _: . ::::        '   .
.'    '-----------:   .
 :                    '---''--'--
    )",
    R"(
Across from me sits a woman, about my age, young, early-thirties, who hasn't looked up from her phone. 
Behind her are floor toceiling windows.
I start to glance around the room. 
A frost-tinted glass door reads NOT AN EXIT, a fire extinguisher hangs on a wood paneled wall.
I wonder where the door leads, whether or not it's an emergency exit. 
Aren't those marked EMERGENCY EXIT?
)",
   {
    {"Check phone", "1", "mark-1-1"},
    {"Look at ceiling", "2", "mark-1-2"},
    {"Listen to the receptionist", "3", "mark-1-3"}
   }
    },
    StoryBeat{
        "mark-1-1",
        R"(
        .:::::::.
      .'     ':::
      :        ::.
      :**  **  ' :
      :        ..:
      :.--    .'::;
      ::.__ .'  ':;_
      ::/""".    .' ""-._
      ::\   |   :        :
     .:::  .'..'          '
    . :'  .         '     ':
    : '  .:        .     . .
    :'   .:        :    .:  "--__
   /'   .::        :   .
  _: . ::::        '   .
.'    '-----------:   .
 :                    '---''--'--
    )",
    R"(
This is the second beat after choosing check phone
)",
   {
    {"Keep scrolling", "1", "???"},
    {"Respond to text message", "2", "???"},
    {"Open Youtube", "3", "???"}
   }
    }
    // TODO: we need to turn our current text in main into story beats inside array
};

bool validate_input(std::string input) {
    std::string valid_selections[]{"1", "2", "3"};
    bool is_valid = false;
    for (int i = 0; i < 3; i++) {
        std::string selection = valid_selections[i];
        if (input == selection) {
            is_valid = true;
            break;
        }
    }
    return is_valid;
}

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

    StoryBeat current_beat;
    bool has_story_ended = false;
    std::string action_selection = "";

    if (character_selection == "1") {
        // current_beat = find the story beat where id == "mark01"
        current_beat = mark_beats[0];
    } else if (character_selection == "2") {
        // current_beat = alma_beats[0];
    } else {
        // current_beat = steph_beats[0];
    }

    // GAME LOOP
    while(!has_story_ended) {
        std::cout << current_beat.ascii_image << "\n\n";

        std::cout << current_beat.narrative_block << "\n\n";

        std::cout << "What do you do? \n";

        for (int i = 0; i < 3; i++) {
            StoryAction action = current_beat.actions[i];

            std::cout << action.number << " - " << action.display_text << "\n";
        }

        // LOOP
        while (!validate_input(action_selection)) {
            std::cout << "Enter the number: ";
            std::cin >> action_selection;
        }

        std::cout << "SELECTION VALID!! " << action_selection << "\n";

        // Find the selected action OBJECT based on the string entered ("1", "2", or "3")
        StoryAction selected_action;
        for (int i = 0; i < 3; i++) {
            StoryAction action = current_beat.actions[i];
            if (action.number == action_selection) {
                selected_action = action;
                break;
            }
        }

        // Set the currentBeat to the next one by looping over the story beats and finding the one with the id that matches the selected action next_beat_id
        bool did_find_next_beat = false;
        for (int i = 0; i < 2; i++) {
            StoryBeat story_beat = mark_beats[i];

            if (story_beat.id == selected_action.next_beat_id) {
                current_beat = story_beat;
                did_find_next_beat = true;
                break;
            }
        }

        if (!did_find_next_beat) {
            std::cout << "HEY NARRATIVE DESIGNER -- THIS IS BROKEN -- NO NEXT BEAT!!!" << "\n";
            // EXIT GAME LOOP
            has_story_ended = true;
            // return EXIT_FAILURE;
        }

        // Clear the selected action
        action_selection = "";
    }

    



    




    // d. Print the name name of the character that was selected
//     std::cout << "\n";
//     std::cout << "You've selected: ";
//     if (character_selection == "1") {
//         std::cout << "Mark\n";
//     } else if (character_selection == "2") {
//         std::cout << "Alma\n";
//     } else {
//         std::cout << "Stephanie\n";
//     }

//     // 2. Display Initial writing and options for Mark
//     // a. Gather writing and get idea what we want to print out
//     // b. Define actions -- check phone, blah.
//     // c. Get user input
//     // d. based on that go down different narrative path

//     // a. Print ascii image for the selected character (Mark)
//     std::string ascii = R"(
//         .:::::::.
//       .'     ':::
//       :        ::.
//       :-  --   ' :
//       :        ..:
//       :.--    .'::;
//       ::.__ .'  ':;_
//       ::/""".    .' ""-._
//       ::\   |   :        :
//      .:::  .'..'          '
//     . :'  .         '     ':
//     : '  .:        .     . .
//     :'   .:        :    .:  "--__
//    /'   .::        :   .
//   _: . ::::        '   .
// .'    '-----------:   .
//  :                    '---''--'--
//     )";

//     std::cout << ascii;
//     std::cout << "\n";

//     // b. Initial text for Mark
//     std::cout << "I sit down on the hard chair in the waiting room, out of breath and lean my cane against the wall behind me.";
//     std::cout << "\n";

//     std::string mark_one = R"(
// Across from me sits a woman, about my age, young, early-thirties, who hasn't looked up from her phone. 
// Behind her are floor toceiling windows.
// I start to glance around the room. 
// A frost-tinted glass door reads NOT AN EXIT, a fire extinguisher hangs on a wood paneled wall.
// I wonder where the door leads, whether or not it's an emergency exit. 
// Aren't those marked EMERGENCY EXIT?
// )"; 
//     std::cout << mark_one;
//     std::cout << "\n";

//     // c. Define and present actions

//     std::cout << "What do you do?\n";

//     std::cout << "\n";

//     std::cout << "1 - Check phone\n";
//     std::cout << "2 - Look at ceiling\n";
//     std::cout << "3 - Listen to the receiptionists\n";

//     std::cout << "\n";
//     std::cout << "Enter the number: ";

//     std::string action_selection;
//     std::cin >> action_selection;

//     bool is_action_valid = false;
//     for (int i = 0; i < 3; i++) {
//         std::string selection = valid_selections[i];
//         if (action_selection == selection) {
//             is_action_valid = true;
//             break;
//         }
//     }
//     if (!is_action_valid) {
//         std::cout << "YOU MESSED UP\n";
//         return EXIT_FAILURE;
//     }

//     std::cout << "\n";
//     std::cout << "You've selected: ";
//     if (action_selection == "1") {
//         std::cout << "Check phone\n";
//     } else if (action_selection == "2") {
//         std::cout << "Look at ceiling\n";
//     } else {
//         std::cout << "Listen to the receiptionists\n";
//     }

    

    return EXIT_SUCCESS;
}