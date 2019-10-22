#include <vector>
#include <cstdio>
#include <iostream>
#include <memory>
#include <chrono>
#ifdef CHECK_ATOMIC
#include <atomic>
#endif



class Foo
{
public:
    virtual void moo() const { printf("foo!\n"); }
};
class Cow : public Foo
{
public:
    void moo() const override { printf("moo!\n"); }
};

void decoy(void *p); // To avoid devirtualization.
class Voo
{
public:
    Voo() { decoy(this); }
    virtual void voo() = 0;
};
class VooDoo : public Voo
{
public:
    void voo() override {}
};
void decoy(void *p)
{
    ((VooDoo*)p)->voo();
}


int main()
{
    using Clock = std::chrono::high_resolution_clock;
    auto t = Clock::now();

    // Fails with illegal instruction because newlib was compiled with hardfloats.
    //printf("hello world %.2f\n", 3.1415);

    printf("===== hello world %i %c %08X =====\n", 123, 123, 123);

    std::cout << "hello c++ world" << std::endl;
    std::cerr << "hello error world" << std::endl;

    auto f = std::make_unique<Cow>();
    f->moo();
    Foo *foo = f.get();
    Cow *cow = dynamic_cast<Cow*>(foo);
    cow->moo();

    try
    {
        // Fails because of hardfloats too at: _Unwind_RaiseException+82
        //throw 5;
    }
    catch (int i)
    {
        printf("caught: %i\n", i);
    }

    static int threadsafe_init = 7;

    auto t2 = Clock::now();
    auto diff = std::chrono::duration_cast<std::chrono::nanoseconds>(t - Clock::now());
    printf("time elapsed: %llu\n", diff.count());

#ifdef CHECK_ATOMIC
    std::atomic_int ai;
    ai = 5;
    int expected = 5;
    if (ai.compare_exchange_strong(expected, 6))
        printf("got expected atomic\n");
#endif
    // Correctly terminates with pure virtual call error.
    //VooDoo vd;

    struct Bye
    {
        ~Bye() { printf("===== DONE =====\n"); }
    } bye;

    std::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    return v[0] + v[1];
}
