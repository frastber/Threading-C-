#include <iostream>
#include <thread>
using namespace std;

struct someStruct
{
    int j = 0;

    someStruct(int& _i) : j(_i) {}

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

class thread_guard
{
    thread& t;
public:
    explicit thread_guard(thread& _t) : t(_t) {}

    ~thread_guard() {
        if (t.joinable())
            t.join();
    }

    thread_guard(thread_guard const&) = delete;
    thread_guard& operator=(thread_guard const&) = delete;

};


int main()
{
    setlocale(0, "");

    int local = 5;
    someStruct someStruct(local);
    thread th(someStruct);
    thread_guard tg(th);
  

	return 0;
}
