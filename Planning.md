To implement this project, I will define a `ListNode` object that stores a `prev` pointer, a `next` pointer, and the string content. I plan to use a struct for this.  

Next, I will create a `LinkedList` class that implements the `insert`, `delete`, and `insertAtLine` functions.  

Finally, there will be a main class that serves as the entry point of the program. The user can interact with the text editor using commands:  

- If the user types `insert`, the input is added to the end of the linked list.  
- If the user types `insert <line number>`, the line is added at the specified line number.
- If the user types `append <line number> <data>`, data is appended to the specified line number. If no line exists with that line number, we print an error.
- If the user types `print`, the current state of the text editor is displayed, with each line numbered.  
- If the user types `save <file name>`, a new file is created in the current directory and the contents of text editor is dispensed into that file.
- If the user types `delete`, the specified line number is removed from the linked list.  

## Example Run

### Example Run Through

Welcome to MiniText!  
Commands: insert <line>, insert <line number> <line>, append <line number> <data>, delete <num>, clear <num>, print, save <file name>, exit

> insert "Hello world"
> insert "This is line 2"
> insert "Another line"
> print
1: Hello world
2: This is line 2
3: Another line

> insert 2 "Hello"
> print
1: Hello world
2: Hello
3: This is line 2
4: Another line

> append 3 " - appended text"
> print
1: Hello world
2: Hello
3: This is line 2 - appended text
4: Another line

> delete 2
Deleted line 2

> print
1: Hello world
2: This is line 2 - appended text
3: Another line

> delete 5
Error: line 5 does not exist