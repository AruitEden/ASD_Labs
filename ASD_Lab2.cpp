#include <iostream>
#include <string>
#include "Forward_list.h"
#include "Circular_forward_list.h"






enum class Menu_commands
{
    DEFAULT = 0,
    CLEAR_CONSOLE = 'c',
    QUIT_PROGRAM = 'q',
    PRINT_HELP = 'h'
};

void Print_command_info();



enum class Task_1
{
    DEFAULT = 0,
    CLEAR_CONSOLE = 'c',
    QUIT_TASK = 'q',
    PRINT_HELP = 'h',

    PUSH_FRONT = 'p',
    INSERT_AFTER = 'i',
    MOVE = 'm',
    ERASE = 'e',
    ERASE_EVERY = 'E',
    INCREASE_SORT = 's',
    DECREASE_SORT = 'S',
    CLEAR = 'C',
    COPY = 'k',
    PRINT_LIST = 'P',

    PUSH_SECOND = '1',
    PRINT_SECOND = '2',
    JOIN_LISTS = 'j',
    INTERSECTION = 'I'
};

void Print_task1_info();



enum class Task_2
{
    DEFAULT = 0,
    CLEAR_CONSOLE = 'c',
    QUIT_TASK = 'q',
    PRINT_HELP = 'h',
    ADD_PEOPLE = 'a',
    PRINT_PEOPLE = 'p',
    SHUFFLE_TEAMS = 's',
    ENTER_N = 'n',
    ENTER_M = 'm',
};

void Print_task2_info();



void First_task();

void Second_task();



template <class T>
void Print_list(Forward_list<T>& list) 
{
    for (auto i : list) 
    {
        std::cout << i << '\n';
    }
}

void Print_people(Circular_forward_list<std::string>& list)
{
    Forward_list_iterator<std::string> it = list.begin();
    for (size_t i = 0; i < list.size(); ++i, ++it)
    {
        std::cout << *it << '\n';
    }
}

void Shuffle(Circular_forward_list<std::string>& people1, Circular_forward_list<std::string>& people2,
    Circular_forward_list<std::string>& team1, Circular_forward_list<std::string>& team2, size_t m, size_t n);



int main()
{

    char command;
    bool run = true;
    Print_command_info();

    while (run)
    {

        std::cout << "----- MAIN MENU -----\n" << "Enter command or choose task: ";
        if (std::cin.peek() == '\n')
        {
            std::cin.ignore(1);
        }
        std::cin >> command;

        switch ((Menu_commands)command)
        {

        case Menu_commands::CLEAR_CONSOLE:
            system("cls");
            break;


        case Menu_commands::PRINT_HELP:
            Print_command_info();
            break;


        case Menu_commands::QUIT_PROGRAM:
            run = false;
            break;


        case (Menu_commands)'1':
            First_task();
            break;

        case (Menu_commands)'2':
            Second_task();
            break;


        default:
            std::cout << "There is no such command.\n";
            break;

        }

    }

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

void Print_task1_info()
{
    std::cout << "Commands list:\n"

        << "\'" << (char)Task_1::PRINT_HELP << "\' - print help\n"
        << "\'" << (char)Task_1::CLEAR_CONSOLE << "\' - clear console\n"
        << "\'" << (char)Task_1::QUIT_TASK << "\' - quit task\n"
        << "\'" << (char)Task_1::PUSH_FRONT << "\' - push front\n"
        << "\'" << (char)Task_1::INSERT_AFTER << "\' - insert after\n"
        << "\'" << (char)Task_1::MOVE << "\' - move by\n"
        << "\'" << (char)Task_1::ERASE << "\' - erase\n"
        << "\'" << (char)Task_1::ERASE_EVERY << "\' - erase every\n"
        << "\'" << (char)Task_1::INCREASE_SORT << "\' - increase sort\n"
        << "\'" << (char)Task_1::DECREASE_SORT << "\' - decrease sort\n"
        << "\'" << (char)Task_1::CLEAR << "\' - clear list\n"
        << "\'" << (char)Task_1::COPY << "\' - copy list\n\n"
        << "\'" << (char)Task_1::PRINT_LIST << "\' - print list\n"
        << "\'" << (char)Task_1::PRINT_SECOND << "\' - print second\n"
        << "\'" << (char)Task_1::PUSH_SECOND << "\' - push second\n"
        << "\'" << (char)Task_1::INTERSECTION << "\' - intersection\n"
        << "\'" << (char)Task_1::JOIN_LISTS << "\' - conjoin\n"

        << "\n\n";
}

void Print_task2_info()
{
    std::cout << "Commands list:\n"

        << "\'" << (char)Task_2::PRINT_HELP << "\' - print help\n"
        << "\'" << (char)Task_2::CLEAR_CONSOLE << "\' - clear console\n"
        << "\'" << (char)Task_2::QUIT_TASK << "\' - quit task\n"
        << "\'" << (char)Task_2::ADD_PEOPLE << "\' - add people\n"
        << "\'" << (char)Task_2::PRINT_PEOPLE << "\' - print people\n"
        << "\'" << (char)Task_2::SHUFFLE_TEAMS << "\' - shuffle teams\n"
        << "\'" << (char)Task_2::ENTER_M << "\' - enter m\n"
        << "\'" << (char)Task_2::ENTER_N << "\' - enter n\n"

        << "\n\n";
}



void First_task()
{

    Forward_list<int> list, second_list, conjoined, intersection;


    char command;
    bool task = true;
    Print_task1_info();

    int value;
    size_t index;
    Forward_list_iterator<int> it;
    Forward_list<int> copy;

    while (task)
    {

        std::cout << "----- TASK 1 -----\n" << "Enter command: ";
        if (std::cin.peek() == '\n')
        {
            std::cin.ignore(1);
        }
        std::cin >> command;

        switch((Task_1)command)
        {

        case Task_1::CLEAR_CONSOLE:
            system("cls");
            break;


        case Task_1::PRINT_HELP:
            Print_task1_info();
            break;


        case Task_1::QUIT_TASK:
            task = false;
            break;


        case Task_1::PUSH_FRONT:
            std::cout << "Enter value: ";
            std::cin >> value;
            list.push_front(value);

            std::cout << "List:\n";
            Print_list(list);
            break;


        case Task_1::INSERT_AFTER:
            std::cout << "Enter value: ";
            std::cin >> value;

            std::cout << "Enter index: ";
            std::cin >> index;

            it = list.begin();

            for (size_t i = 0; i < index; ++i, ++it);

            list.insert_after(it, value);

            std::cout << "List:\n";
            Print_list(list);
            break;


        case Task_1::MOVE:
            std::cout << "Enter index: ";
            std::cin >> index;

            it = list.begin();

            for (size_t i = 0; i < index; ++i, ++it);

            std::cout << "Enter distance: ";
            size_t distance;
            std::cin >> distance;

            list.move_by(it, distance);

            std::cout << "List:\n";
            Print_list(list);
            break;


        case Task_1::ERASE:
            std::cout << "Enter index: ";
            std::cin >> index;

            it = list.begin();

            for (size_t i = 0; i < index; ++i, ++it);

            list.erase(it);

            std::cout << "List:\n";
            Print_list(list);
            break;


        case Task_1::ERASE_EVERY:
            std::cout << "Enter n: ";
            std::cin >> index;

            list.erase_every(index);

            std::cout << "List:\n";
            Print_list(list);
            break;


        case Task_1::INCREASE_SORT:
            list.sort();

            std::cout << "List:\n";
            Print_list(list);
            break;


        case Task_1::DECREASE_SORT:
            list.reverse_sort();

            std::cout << "List:\n";
            Print_list(list);
            break;


        case Task_1::CLEAR:
            list.clear();

            std::cout << "List:\n";
            Print_list(list);
            break;


        case Task_1::COPY:
            copy = list;

            std::cout << "Copied list:\n";
            Print_list(copy);
            break;


        case Task_1::PRINT_LIST:
            std::cout << "List:\n";
            Print_list(list);
            break;


        case Task_1::PUSH_SECOND:
            std::cout << "Enter value: ";
            std::cin >> value;
            second_list.push_front(value);

            std::cout << "Second list:\n";
            Print_list(second_list);
            break;


        case Task_1::PRINT_SECOND:
            std::cout << "Second list:\n";
            Print_list(second_list);
            break;


        case Task_1::JOIN_LISTS:
            conjoined = conjoin(list, second_list);
            std::cout << "Conjoined list:\n";
            Print_list(conjoined);
            break;


        case Task_1::INTERSECTION:
            intersection = intersect(list, second_list);
            std::cout << "Intersection list:\n";
            Print_list(intersection);
            break;


        default:
            std::cout << "There is no such command.\n";
            break;

        }

    }

}



void Second_task()
{

    Circular_forward_list<std::string> people1, people2, team1, team2;

    size_t n, m;

    std::string name1, name2;



    char command;
    bool task = true;
    Print_task2_info();


    while (task)
    {

        std::cout << "----- TASK 2 -----\n" << "Enter command: ";
        if (std::cin.peek() == '\n')
        {
            std::cin.ignore(1);
        }
        std::cin >> command;

        switch ((Task_2)command)
        {

        case Task_2::CLEAR_CONSOLE:
            system("cls");
            break;


        case Task_2::PRINT_HELP:
            Print_task2_info();
            break;


        case Task_2::QUIT_TASK:
            task = false;
            break;

            
        case Task_2::ADD_PEOPLE:
            std::cout << "Enter first name: ";
            std::cin >> name1;
            std::cout << "Enter second name: ";
            std::cin >> name2;

            people1.push_front(name1);
            people2.push_front(name2);

            std::cout << "People 1:\n";
            Print_people(people1);
            std::cout << "People 2:\n";
            Print_people(people2);
            break;


        case Task_2::PRINT_PEOPLE:
            std::cout << "People 1:\n";
            Print_people(people1);
            std::cout << "People 2:\n";
            Print_people(people2);
            break;


        case Task_2::SHUFFLE_TEAMS:
            Shuffle(people1, people2, team1, team2, m, n);
            std::cout << "Team 1:\n";
            Print_people(team1);
            std::cout << "Team 2:\n";
            Print_people(team2);
            break;


        case Task_2::ENTER_N:
            std::cout << "Enter n: ";
            std::cin >> n;
            break;


        case Task_2::ENTER_M:
            std::cout << "Enter m: ";
            std::cin >> m;
            break;


        default:
            std::cout << "There is no such command.\n";
            break;

        }

    }

}



void Shuffle(Circular_forward_list<std::string>& people1, Circular_forward_list<std::string>& people2,
    Circular_forward_list<std::string>& team1, Circular_forward_list<std::string>& team2, size_t m, size_t n)
{

    Forward_list_iterator<std::string> it1 = people1.begin(), it2 = people2.begin();

    for (int i = 1; i < n; ++i, ++it1);

    for (int i = 1; i < m; ++i, ++it2);

    bool t = 1;

    while (true)
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

    if (team1.size() > team2.size())
    {
        team2.push_front(*(team1.begin()));
        team1.pop_front();
    }

}
