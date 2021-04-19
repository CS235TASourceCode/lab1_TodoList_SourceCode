#pragma once
#include <vector>
#include <string>
#include <fstream>
#include "TodoListInterface.h"
using namespace std;

class TodoList : public TodoListInterface{
    private:
    vector<std::string> todoList;
    public:
    TodoList() {
        ifstream in("TODOList.txt");
        std::string line;
        while(getline(in,line)){ todoList.push_back(line);}
    }
    ~TodoList() {
        ofstream out("TODOList.txt");
        for(string i : todoList){ out << i << endl;}
    }

    /*
    *   Adds an item to the todo list with the data specified by the string "_duedate" and the task specified by "_task"
    */
    void add(string _duedate, string _task){
        todoList.push_back(_duedate+" "+_task);
    }

    /*
    *   Removes an item from the todo list with the specified task name
    *
    *   Returns 1 if it removes an item, 0 otherwise
    */
    int remove(string _task){
        for(unsigned int i = 0; i < todoList.size(); i++){
            if(todoList.at(i).find(_task) != string::npos){
                todoList.erase(todoList.begin()+i);
                i--;
            }
        }
        return 1;
    }

    /*
    *   Prints out the full todo list to the console
    */
    void printTodoList(){
        for(string i : todoList){
            cout << i << endl;
        }
    }

    /*
    *   Prints out all items of a todo list with a particular due date (specified by _duedate)
    */
    void printDaysTasks(string _date){
        for (unsigned int i = 0; i < todoList.size(); ++i)
        {
            if(todoList.at(i).find(_date) != string::npos)
            cout << todoList.at(i) << endl;
        }
    }
};