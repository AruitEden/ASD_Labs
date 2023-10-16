#include <iostream>
#include <string>
#include "Forward_list.h"
#include "Stack.h"






enum class Menu_commands
{
    DEFAULT = 0,
    CLEAR_CONSOLE = 'c',
    QUIT_PROGRAM = 'q',
    PRINT_HELP = 'h'
};

void Print_command_info();







int main()
{

    Stack<int> st;

    st.push(5);
    st.push(1);
    st.push(-2);
    st.push(4);
    
    std::cout << "----- STACK -----\n";
    for(auto i : st)
    {
        std::cout << i << '\n';
    }
    std::cout << "\n\n";
    
    std::cout << "----- Clear -----\n";
    //std::cout << std::boolalpha << st.contains(15) << '\n';
    st.clear();
    for (auto i : st)
    {
        std::cout << i << '\n';
    }
    std::cout << "\n\n";

    return 0;

}







void Print_command_info() 
{

    std::cout << "Commands list:\n"

        << "\'" << (char)Menu_commands::PRINT_HELP        << "\' - print help\n"
        << "\'" << (char)Menu_commands::CLEAR_CONSOLE     << "\' - clear console\n"
        << "\'" << (char)Menu_commands::QUIT_PROGRAM      << "\' - quit program\n"

             << "\n\n";

}

