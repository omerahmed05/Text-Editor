#include <iostream>
#include <sstream>
#include <vector>
#include "SinglyLinkedList.h"
#include <fstream>

std::string getQuotedText(const std::string& input, size_t startPos) {
    size_t firstQuote = input.find('"', startPos);

    if (firstQuote == std::string::npos) {
        return ""; // no quote
    }

    size_t secondQuote = input.find('"', firstQuote + 1);

    if (secondQuote == std::string::npos) {
        return ""; // no closing quote
    }
    
    return input.substr(firstQuote + 1, secondQuote - firstQuote - 1); // extract data inside the quotes, excluding quotes
}


int main() {
    std::cout << "Welcome to MiniText!\n";
    std::cout << "Commands: insert <line>, insert <line number> <line>, append <line number> <data>, delete <num>, clear <num>, print, save <file name>, exit\n\n";

    std::ofstream outputFile;
    SinglyLinkedList* lines = new SinglyLinkedList();

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
            int index;

            // try to convert next arg into an int
            if (string_stream >> index ) {
                std::string text;
                std::getline(string_stream >> std::ws, text);
                lines->insert(text, index);
            } else {
                std::string text;
                std::getline(string_stream >> std::ws, text);
                lines->insert(text);
            }
        } else if (command == "append") { 
            int index = std::stoi(args[1]); // convert string to int
            std::string line_to_add = args[2];

            if (index < 0 || index >= lines->getSize()) {
                std::cout << "Error: line " << index + 1 << " does not exist";
            } else {
                ListNode* line_at_index = lines->getNode(index);
                line_at_index->value.append(line_to_add);
            }
        } else if (command == "delete") {
            int index = std::stoi(args[1]); // convert string to int
            
            if (index < 0 || index >= lines->getSize()) {
                std::cout << "Error: line " << index + 1 << " does not exist";
            } else {
                lines->deleteNode(index);
            }
        } else if (command == "clear") { 
            int index = std::stoi(args[1]); // convert string to int
            if (index < 0 || index >= lines->getSize()) {
                std::cout << "Error: line " << index + 1 << " does not exist";
            } else {
                lines->clearData(index);
            }
        } else if (command == "print") { 
            lines->print(std::cout);
        } else if (command == "save") { 
            std::string file_name = args[1];
            outputFile.open(file_name);
            lines->print(outputFile);
            outputFile.close();
            std::cout << "Contents dumped into " << file_name << "!\n"; 
        } else if (command == "exit") { 
            std::cout << "Goodbye!\n";
            break;
        } else { 
            std::cout << command << " is not part of the toolkit. Please enter another command.\n"; 
        }
    }

    delete lines;
    return 0;
}