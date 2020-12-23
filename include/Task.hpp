#pragma once
#include <string>
#include <vector>

class Task{
public:
    friend void edit_task( unsigned short int, std::vector< Task > & );
    Task( std::string, unsigned short int, bool, unsigned short int ID );
    Task();
    void set_name();
    void set_ID( const std::vector< Task > & );
    void set_priority();
    void set_favourite();
    std::string get_name() const;
    void complete();

    unsigned short int get_ID() const;
    unsigned short int get_priority() const;
    std::string get_favourite() const;
    bool get_completed() const;

private:
    std::string name = "";
    unsigned short int ID = 0;
    unsigned short int priority = 0;
    bool favourite = false;
    bool is_completed = false;
};