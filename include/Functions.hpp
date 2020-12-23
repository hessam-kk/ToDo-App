#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "Task.hpp"

// Added a task at the end of the vector.
// the whole vector has been passed because of set_id() function 
// which checks for any repeated IDs.
void add_task( Task &, std::vector< Task > & );

// prints a task which passed by reference but const to avoid any changes.
void print_task( const Task & );

// When user Wanted to delete a task, this function calls
// and in this functions ID is ask .
void delete_task( std::vector< Task > & );

// this function use is to mark a task as completed.
void complete_task( std::vector< Task > & );

// edit a task with ID and whole vector
void edit_task( unsigned short int , std::vector< Task > & );

// a function to show all not compeleted task -> list-todo .
void show_all(const std::vector < Task > & );

// show completed task for command: list-todo
void show_completed( const std::vector < Task > & );

// clears the buffer and ask user to enter a key to countinue.
void enter_a_key();