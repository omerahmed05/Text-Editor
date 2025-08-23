#include <iostream>
#include <sstream>
#include <vector>
#include "SinglyLinkedList.h"

int main() {
    std::cout << "Welcome to MiniText!\n";
    std::cout << "Commands: insert <line>, insert <line number> <line>, append <line number> <data>, delete <num>, print, save <file name>, exit\n\n";

    while (true) {
        std::cout << "> ";
        std::string input_line{};
        std::getline(std::cin >> std::ws, input_line);
        
        std::istringstream string_stream(input_line); // treat the string as a stream
        std::vector<std::string> args;
        std::string arg;

        // While there is still input in the stream, extract up until next white space
        while (string_stream >> arg) {
            args.push_back(arg);
        }

        std::string command = args[0];

        SinglyLinkedList* lines = new SinglyLinkedList();

        if (command == "insert") { 
            if (args.size() == 2) {
                lines->insert(args[1]);
            } else if (args.size() == 3) {
                std::string string_to_add = args[2];
                int index = std::stoi(args[1]); // convert string to int
                lines->insert(string_to_add, index);
            } else {
                std::cout << "Invalid number of arguments.\n";
            }
        } else if (command == "append") { 
            int index = std::stoi(args[1]); // convert string to int
            std::string line_to_add = args[2];

            ListNode* line_at_index = lines->getNode(index);
            line_at_index->value.append(line_to_add);
        } else if (command == "delete") { 
            std::cout << "Deleted!\n"; 
        } else if (command == "print") { 
            std::cout << "Printed!\n"; 
        } else if (command == "save") { 
            std::cout << "Saved!\n"; 
        } else if (command == "exit") { 
            std::cout << "Exited!\n"; 
        } else { 
            std::cout << command << " is not part of the toolkit. Please enter another command.\n"; 
        }
    }
    return 0;
}