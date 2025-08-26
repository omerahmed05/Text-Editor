#include <iostream>
#include <sstream>
#include <vector>
#include "SinglyLinkedList.h"
#include <fstream>

std::string getQuotedText(const std::string &input, size_t startPos)
{
    size_t firstQuote = input.find('"', startPos);

    if (firstQuote == std::string::npos)
    {
        return ""; // no quote
    }

    size_t secondQuote = input.find('"', firstQuote + 1);

    if (secondQuote == std::string::npos)
    {
        return ""; // no closing quote
    }

    return input.substr(firstQuote + 1, secondQuote - firstQuote - 1); // extract data inside the quotes, excluding quotes
}

int main()
{
    std::cout << "Welcome to MiniText!\n";
    std::cout << "Commands: insert <line>, insert <line number> <line>, append <line number> <data>, delete <num>, clear <num>, print, save <file name>, exit\n\n";

    std::ofstream outputFile;
    SinglyLinkedList *lines = new SinglyLinkedList();

    while (true)
    {
        std::cout << "> ";
        std::string input_line{};
        std::getline(std::cin >> std::ws, input_line);

        std::istringstream string_stream(input_line);
        std::string command;
        string_stream >> command;

        if (command == "insert")
        {
            int index;
            if (string_stream >> index)
            { // try to read an index
                index -= 1; // convert to 0-based index 
                std::string text;
                std::getline(string_stream >> std::ws, text); // read the rest of the line
                lines->insert(text, index);
            }
            else
            { // no index, just insert at the end
                string_stream.clear(); // clear fail state
                std::string text;
                std::getline(string_stream >> std::ws, text);
                lines->insert(text);
            }
        }
        else if (command == "append")
        {
            int index;
            if (string_stream >> index)
            {
                index -= 1; // convert to 0-based index 
                std::string text_to_append;
                std::getline(string_stream >> std::ws, text_to_append);

                if (index < 0 || index >= lines->getSize())
                {
                    std::cout << "Error: line " << index + 1 << " does not exist.\n";
                }
                else
                {
                    ListNode *line_at_index = lines->getNode(index);
                    line_at_index->value.append(text_to_append);
                }
            }
        }
        else if (command == "delete")
        {
            int index;

            if (string_stream >> index)
            {
                index -= 1; // convert to 0-based index
                if (index < 0 || index >= lines->getSize())
                {
                    std::cout << "Error: line " << index + 1 << " does not exist.\n";
                }
                else
                {
                    lines->deleteNode(index);
                }
            }
            else
            {
                std::cout << "Second argument provided is not an integer.\n";
            }
        }
        else if (command == "clear")
        {
            int index;

            if (string_stream >> index)
            {
                index -= 1; // convert to 0-based index 
                if (index < 0 || index >= lines->getSize())
                {
                    std::cout << "Error: line " << index + 1 << " does not exist.\n";
                }
                else
                {
                    lines->clearData(index);
                }
            }
            else
            {
                std::cout << "Second argument provided is not an integer.\n";
            }
        }
        else if (command == "print")
        {
            lines->print(std::cout);
        }
        else if (command == "save")
        {
            std::string file_name;
            std::getline(string_stream >> std::ws, file_name);
            if (file_name.empty())
            {
                std::cout << "Error: no file name provided.\n";
            }
            else
            {
                outputFile.open(file_name);
                lines->print(outputFile);
                outputFile.close();
                std::cout << "Contents dumped into " << file_name << "!\n";
            }
        }
        else if (command == "exit")
        {
            std::cout << "Goodbye!\n";
            break;
        }
        else
        {
            std::cout << command << " is not part of the toolkit. Please enter another command.\n";
        }
    }

    delete lines;
    return 0;
}