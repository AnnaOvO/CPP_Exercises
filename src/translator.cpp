#include <iostream>
#include <set>
#include <string>

using namespace std;

set<string> make_exit_commands()
{
    return {"q", "quit", "e", "exit"};
}

int main()
{
    while (true)
    {
        string tmp;
        std::cout << "This is a translator, but it does nothing for now..." << std::endl;
        cin >> tmp;
        auto c = make_exit_commands();
        if (auto search = c.find(tmp); search != c.end())
        {
            break;
        }
        
    }

    return 0;
}