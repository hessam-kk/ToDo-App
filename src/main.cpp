#include <iostream>
#include <string>
#include <unistd.h>
#include "Task.hpp"
#include <limits>
#include <vector>
// using Gnu-Linux running on windows ( wsl ).
// thus cmake couldn`t find the include directories correctly,
// then I need to get the exact address for header files
#include "../include/Functions.hpp"
using namespace std;

#define BORDER std::cout << "=====================================================" << std::endl;


int main(){
    // creates the main vector to store task in it
    vector< Task > my_tasks;

    // Declaring some default data to test the app
    Task one("Buy Vegtables", 1, 1, 1269);
    my_tasks.push_back(one);
    Task one_half("Search About IT & Technology", 1, 1, 8969);
    my_tasks.push_back(one_half);
    Task two("Read A Book", 2, 1, 8969);
    my_tasks.push_back(two);
    Task three("Call Mom", 2, 0, 3599);
    my_tasks.push_back(three);
    Task four("Text My Friend This Night", 2, 0, 2368);
    my_tasks.push_back(four);
    Task five("Learn Fast Typing in The Google.com", 3, 1, 9999);
    my_tasks.push_back(five);
    Task six("Clean My Room", 3, 0, 7830);
    my_tasks.push_back(six);
    Task seven("Meditate", 4, 1, 5979);
    my_tasks.push_back(seven);
    Task eight("Go to The bath And Wash My Hair", 4, 0, 7710);
    my_tasks.push_back(eight);
    Task nine("Play Call Of Duty Mobile With My New Friend", 5, 1, 1036);
    my_tasks.push_back(nine);
    Task ten("Study A Little Advance Programming", 5, 0, 8585);
    my_tasks.push_back(ten);
    my_tasks.at(1).complete();
    my_tasks.at(5).complete();
    my_tasks.at(8).complete();
    // End of Declaring test data

while( 1 ){
    system("clear");
    BORDER;
    cout 
    << "-- To Add A Task Enter \"add\"           \n"
    << "-- To Delete A Task Enter \"delete\"     \n"
    << "-- To Complete A Task Enter \"complete\" \n"
    << "-- To Edit A Task Enter \"edit ID\"      \n"
    << "-- To View ToDo List Enter \"list-todo\" \n"
    << "-- To View All Completed Tasks Enter \"list-complete\" \n"
    << "-- To Delete All of Task Enter \"clear\" \n"
    << "-- To Quit The App Enter \"quit\"        \n";
    BORDER;
    cout << ">>> ";
    string input;
    cin >> input;

    if ( input == "add" ){
        cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        Task new_one;
        add_task( new_one, my_tasks );
        system("clear");
        print_task( * my_tasks.rbegin() );
        enter_a_key();
    }

    else if ( input == "delete" ){
        cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        delete_task( my_tasks );
        enter_a_key();
    }

    else if ( input == "complete" ){
        complete_task( my_tasks );
        enter_a_key();
    }

    else if ( input == "edit"){
        unsigned short int ID;
        cin >> ID;
        cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        edit_task( ID, my_tasks );
    }

    else if( input == "list-todo"){
        show_all( my_tasks );
        enter_a_key();
    }

    else if( input == "list-complete"){
        show_completed( my_tasks );
        enter_a_key();
    }

    else if ( input == "clear" ){
        system("clear");
        my_tasks.erase(my_tasks.begin(), my_tasks.end() );
        cout << "---All of The Tasks Are Now Deleted--- "  << endl;
        enter_a_key();
    }

    else if ( input == "quit" ){
        system("clear");
        cout << "\n---Goodbye!!---" << endl;
        sleep(2);
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        return 0;
    }

    else {
        if( input == "edit" ) continue;
        cerr << "Please Enter A Valid Command!!" << endl;
        sleep(2);
    }
}
}