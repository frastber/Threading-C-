#include <iostream>
#include <thread>
using namespace std;

struct someStruct
{
    int j = 0;
    void operator()()
    {
        for (int i = 0; i < 10; ++i)
        {
            ++j;
        }
    }
};

void doSomething() {
    for (int i = 0; i < 10;)
    {
        ++i;
    }
}

int main()
{
    setlocale(0, "");

    someStruct structure;
    thread th(structure);

    try
    {
        doSomething();
    }
    catch (...)
    {
        th.join();
        throw;
    }

    th.join();

  

	return 0;
}
