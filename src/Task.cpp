#include <iostream>
#include <string>
#include <random>
#include <time.h>
#include <limits>
// using Gnu-Linux running on windows ( wsl ).
// thus cmake couldn`t find the include directories correctly,
// then I need to get the exact address for header files
#include "../include/Task.hpp"

// just a default constructor to create an empty object to push_back in the vector,
// and then add datas when it is already added to vector.
Task::Task(){
};

// its a default constructors which only developer has access on, 
// just to create some test-data, thus it has a very high privilages. 
// but don`t worry, I care about inputs I gave :)
Task::Task(std::string N, unsigned short int P, bool F, unsigned short int ID){
    (*this).name = N;
    (*this).ID = ID;
    (*this).priority = P;
    (*this).favourite = F;
    (*this).is_completed = false;
};

// asks for the name and sets it for the object, 
// considering that it`s just a name and could be anything,
// no innput check needed.
void Task::set_name(){
    std::cout << "Task Name: >>> " ;
    std::string name;
    std::getline(std::cin, name);
    (*this).name = name;
}

// create a random ID for given object,
// whole vector is passed but const because vector is only
// for checking repeated IDs but not writing changes.
void Task::set_ID( const std::vector< Task > & h ){
    srand( time(NULL) );
    unsigned short int tmp = rand() % 9000 + 1000;
    // check if the new ID is not same as another object
    for (size_t i = 0; i < h.size() ; i++){
        // if was same, create another ID and resets the counter to check again
        if ( tmp == h.at(i).get_ID() ){
            srand( time(NULL) );
            tmp = rand() % 9000 + 1000;
            i = 0;
        }
    }
    (*this).ID = tmp;
}

// asks for priority and sets it for object.
void Task::set_priority(){
    std::cout << "Priority(1 - 5) : >>> ";
    unsigned short int x;
    std::cin >> x;
    while ( x < 1 || x > 5 ){
        std::cerr << "Invalid Priority. Enter A Number Between 1-5 " << std::endl;
        std::cout << "Priority(1 - 5) : >>> ";
        std::cin >> x;
    }
    (*this).priority = x;
}

// ask for setting the task as favourite or not.
void Task::set_favourite(){
    std::cout << "Favourite(y/n) : >>> ";
    char x;
    std::cin >> x;
    while ( x != 'y' && x != 'n'){
        std::cerr << "Invalid Input. Only Enter \'y\' or \'n\'. " << std::endl
        << "Favourite(y/n) : >>>";
        std::cin >> x;
    }
    if( x == 'y' )
        (*this).favourite = true;
    else 
        (*this).favourite = false;
    
}

// returns the name of object.
std::string Task::get_name() const {
    return (*this).name;
}

// returns the ID of object. 
unsigned short int Task::get_ID() const{
    return (*this).ID;
}

// returns priority of object
unsigned short int Task::get_priority() const{
    return (*this).priority;
}

// returns favourite state of object
std::string Task::get_favourite() const{
    if( (*this).favourite )
        return "yes";
    else 
        return "no";
}

// marks a task as complete
void Task::complete(){
    (*this).is_completed = true;
}

// returns priority of object
bool Task::get_completed() const {
    if( (*this).is_completed == true )
        return true;
    else 
        return false;
}