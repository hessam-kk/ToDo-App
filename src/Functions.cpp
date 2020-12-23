#include <limits>
#include "../include/Functions.hpp"
#include <iomanip>
#include <unistd.h>
#define BORDER std::cout << "===========================================================================" << std::endl;

// Added a task at the end of the vector.
// the whole vector has been passed because of set_id() function 
// which checks for any repeated IDs.
void add_task( Task & new_task,  std::vector< Task > & h ){
    new_task.set_name();
    new_task.set_ID( h );
    new_task.set_priority();
    new_task.set_favourite();
    h.push_back( new_task );
}

// prints a task which passed by reference but const to avoid any changes.
void print_task( const Task & new_task ) { 
    BORDER;
    std::cout << "|| Task Information:" << std::endl
              << "|| Task: " << new_task.get_name() << std::endl
              << "|| ID: "<<  new_task.get_ID()
              << " | " << "Priority: " << new_task.get_priority()
              << " | " << "Favourite: " << new_task.get_favourite() << std::endl;
    BORDER;
}

// When user Wanted to delete a task, this function calls
// and in this functions ID is ask .
void delete_task( std::vector< Task > & h){
    unsigned short int ID;
    std::cout << " Enter Task ID: \n>>> ";
    std::cin >> ID;
    // Search for the given ID in the vector
    for (size_t i = 0; i < h.size(); i++){
        if ( ID == h.at(i).get_ID() ){
            std::cout << "Found! " << h.at(i).get_name() << std::endl;
            std::cout << "Delete? (y/n) \n>>> ";
            char x;
            std::cin >> x;
            // when asked for confirmation,
            // here contorls the yes or no answer which should be correct.
            while ( x != 'y' && x != 'n'){
                std::cerr << "Invalid Input. Only Enter \'y\' or \'n\'. " << std::endl;
                std::cout << "Delete? (y/n)\n>>> ";
                std::cin >> x;
            }
            // if the confirmation was yes, here task will be deleted.
            if ( x == 'y' ){
                h.erase( h.begin() + i );
                std::cout << "\n---Deleted Successfully!---" << std::endl;
                return;
            } else  return;
        } 
    }
    // if for loop cannot find any ID here we have an error.
    std::cerr << "---No Such a Task Found! Try Again!--- " << std::endl;
}

// this function use is to mark a task as completed.
void complete_task( std::vector< Task > & h ){
    unsigned short int ID;
    // ID is ask in this function
    std::cout << "Enter Task ID: \n>>> ";
    std::cin >> ID;
    // Search for the given ID in the vector
    for (size_t i = 0; i < h.size(); i++){
        if ( ID == h.at(i).get_ID() ){
            std::cout << "Found! " << h.at(i).get_name() << std::endl;
            std::cout << "Complete? (y/n) \n>>> ";
            char x;
            std::cin >> x;
            // when asked for confirmation,
            // here contorls the yes or no answer which should be correct.
            while ( x != 'y' && x != 'n'){
                std::cerr << "Invalid Input. Only Enter \'y\' or \'n\'. " << std::endl;
                std::cout << "Delete? (y/n)\n>>> ";
                std::cin >> x;
            }
            // if the confirmation was yes, here task will be deleted.
            if ( x == 'y' ){
                h.at( i ).complete() ;
                std::cout << "\n---Completed Successfully!---" << std::endl;
                return;
            } else  return;
        } 
    }
    // if for loop cannot find any ID here we have an error.
    std::cerr << "---No Such a Task Found! Try Again!--- " << std::endl;
}

// edit a task with ID and whole vector
void edit_task( unsigned short int ID, std::vector< Task > & h ){
    bool found = false;
    int founded_number = 0;
    // search for ID
    for (size_t i = 0; i < h.size(); i++){
        if ( ID == h.at(i).get_ID() ){
            found = true;
            founded_number = i;
            break;
        } 
    }
    if ( found ){
        system("clear");
        std::cout << "Found! " << h.at( founded_number ).get_name() << std::endl;
        std::cout << "Which Attributes Do You Want To Edit?"
        << "\n-n name | -p Priority | -f Favourite | -q Quit"
        << "\n>>> ";
        std::string input;
        getline(std::cin, input);
        // search for given keys.
        if ( input    == "-q" ) return;
        if ( input.find( "-n" ) < input.length() ){
            int first_pos =  input.find( "-n" );
            int next_pos =  input.find( '-' , input.find( "-n" )+1 );
            std::string new_name =
            input.substr( first_pos+3, next_pos-first_pos-4 );
            h.at( founded_number ).name = new_name;
        }
        if ( input.find( "-f" ) < input.length() ){
            int pos =  input.find( "-f" );
            if ( input[ pos + 3 ] == 'y' )
                h.at( founded_number ).favourite = true;
            else if ( input[ pos + 3 ] == 'n' )
                h.at( founded_number ).favourite = false;
            else
                std::cerr << "---Wrong data---";
        }
        if ( input.find( "-p" ) < input.length() ) {
            int pos =  input.find( "-p" );
            switch ( input[pos + 3] ){
            case '1':
                h.at( founded_number ).priority = 1;
                break;
            case '2':
                h.at( founded_number ).priority = 2;
                break;
            case '3':
                h.at( founded_number ).priority = 3;
                break;
            case '4':
                h.at( founded_number ).priority = 4;
                break;
            case '5':
                h.at( founded_number ).priority = 5;
                break;
            default:
                std::cerr << "---Wrong Data---" << std::endl;
                break;
            }
        }
        print_task( h.at( founded_number ) );
        sleep(3);
        std::cout << "Enter Any Key To Return To The Menu... " ;
        getchar();
    }
    // error message
    else  
        std::cerr << "---No Such a Task Found! Try Again!--- " << std::endl;
    return;
}

// a function to show all not compeleted task -> list-todo .
void show_all( const std::vector < Task > & h ){
    // Find Longest Name to Make A Perfect Arrange of Setw() 
    size_t MAX_LENTGH_OF_NAME =  h.front().get_name().length();
    for (size_t i = 0; i < h.size(); i++)
        if( MAX_LENTGH_OF_NAME < h.at(i).get_name().length() )
            MAX_LENTGH_OF_NAME = h.at(i).get_name().length();
    
    system("clear");
    std::cout << "Task" << std::setw( MAX_LENTGH_OF_NAME + 13) << "P    F    ID " << std::endl;
    BORDER;
    int i = 0;
    for (int j = 1; j <= 5; j++){
        for ( i = 0; i < h.size(); i++){
            if( h.at(i).get_priority() == j &&
                h.at(i).get_favourite() == "yes" &&
                h.at(i).get_completed() == false )
                std::cout << "-"<< h.at(i).get_name()
                << std::setw( MAX_LENTGH_OF_NAME + 4 - h.at(i).get_name().length() ) 
                << j << "    y    "<< h.at(i).get_ID() << std::endl;

            if( h.at(i).get_priority() == j &&
                h.at(i).get_favourite() == "no" &&
                h.at(i).get_completed() == false )
                std::cout << "-"<<h.at(i).get_name()
                << std::setw( MAX_LENTGH_OF_NAME + 4 - h.at(i).get_name().length() )
                << j << "    n    "<< h.at(i).get_ID() << std::endl;

        }
        // resets I for the new priority check
        i = 0;
    }
    BORDER;
}

// show completed task for command: list-todo
void show_completed( const std::vector < Task > & h ){
    // Find Longest Name to Make A Perfect Arrange of Setw() 
    size_t MAX_LENTGH_OF_NAME =  h.front().get_name().length();
    for (size_t i = 0; i < h.size(); i++)
        if( MAX_LENTGH_OF_NAME < h.at(i).get_name().length() )
            MAX_LENTGH_OF_NAME = h.at(i).get_name().length();
    
    system("clear");
    std::cout << "Task" << std::setw( MAX_LENTGH_OF_NAME + 4 ) << "ID" << std::endl;
    BORDER;
    // arranging task output
    for (size_t i = 0; i < h.size(); i++){
        if ( h.at(i).get_completed() == true)
            std::cout << "-" << h.at(i).get_name()
            << std::setw( MAX_LENTGH_OF_NAME + 9 - h.at(i).get_name().length() ) 
            << h.at(i).get_ID() << std::endl;
    }
    BORDER;
}

// clears the buffer and ask user to enter a key to countinue.
void enter_a_key(){
    sleep(3);
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    std::cout << "Enter Any Key To Return To The Menu... " ;
    getchar();
}