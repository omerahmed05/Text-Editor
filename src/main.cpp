#include <iostream>
#include <sstream>
#include <vector>

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

        if (command == "insert") { 
            std::cout << "Inserted!\n"; 
        } else if (command == "append") { 
            std::cout << "Appended!\n"; 
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