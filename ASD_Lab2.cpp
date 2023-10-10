#include <iostream>
#include <string>
#include "Forward_list.h"
#include "Circular_forward_list.h"






enum Menu_commands
{
    DEFAULT = 0,
    PRINT_COLLECTION = 'p',
    ADD_ELEMENT = 'a',
    CLEAR_CONSOLE = 'c',
    QUIT_PROGRAM = 'q',
    SORT_COLLECTION = 's',
    PRINT_HELP = 'h'
};

void Print_command_info();







int main()
{

    Circular_forward_list<std::string> people1, people2, team1, team2;

    size_t n = 2, m = 3;

    people1.push_front("8");
    people1.push_front("7");
    people1.push_front("6");
    people1.push_front("5");

    people2.push_front("4");
    people2.push_front("3");
    people2.push_front("2");
    people2.push_front("1");

    Forward_list_iterator<std::string> it1 = people1.begin(), it2 = people2.begin();

    for (int i = 1; i < n; ++i, ++it1);

    for (int i = 1; i < m; ++i, ++it2);

    bool t = 1;

    while(true)
    {

        if (t)
        {
            team1.push_front(*it1);
            team1.push_front(*it2);
        }
        else 
        {
            team2.push_front(*it1);
            team2.push_front(*it2);
        }

        people1.erase(it1++);
        people2.erase(it2++);

        t = !t;

        size_t i1 = 0, i2 = 0;

        if (people1.size() == 0)
        {
            break;
        }

        for (; i1 < n && i2 < m; ++i1, ++i2, ++it1, ++it2);

        for (; i1 < n; ++i1, ++it1);

        for (; i2 < m; ++i2, ++it2);

    }

    if(team1.size() > team2.size())
    {
        team2.push_front(*(team1.begin()));
        team1.pop_front();
    }

    Forward_list_iterator<std::string> it = team1.begin();
    std::cout << "----- TEAM 1 -----\n";
    for(size_t i = 0; i < team1.size(); ++i, ++it)
    {
        std::cout << *it << '\n';
    }

    it = team2.begin();
    std::cout << "----- TEAM 2 -----\n";
    for (size_t i = 0; i < team2.size(); ++i, ++it)
    {
        std::cout << *it << '\n';
    }

    return 0;

}







void Print_command_info() 
{

    std::cout << "Commands list:\n"

        << "\'" << Menu_commands::PRINT_HELP        << "\' - print help\n"
        << "\'" << Menu_commands::CLEAR_CONSOLE     << "\' - clear console\n"
        << "\'" << Menu_commands::QUIT_PROGRAM      << "\' - quit program\n"
        << "\'" << Menu_commands::PRINT_COLLECTION  << "\' - print collection\n"
        << "\'" << Menu_commands::ADD_ELEMENT       << "\' - add element\n"
        << "\'" << Menu_commands::SORT_COLLECTION   << "\' - sort array\n"

             << "\n\n";

}

