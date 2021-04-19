#include <iostream>
#include <string>
#include "TodoList.h"
using namespace std;

int main(int argc, char* argv[]){
    if(argc > 1){
        std::string command = argv[1];
        TodoList todolist;
        try{
            if(command == "add"){ todolist.add(argv[2], argv[3]);}
            else if (command == "remove"){ todolist.remove(argv[2]);}
            else if (command == "printlist"){ todolist.printTodoList();}
            else if (command == "printday"){ todolist.printDaysTasks(argv[2]);}
            else{throw command;}
        }
        catch(std::string error){
            std::cout << "\" " << error << "\" " "is not a valid command, please enter a valid command" << std::endl;
        }
    }
}