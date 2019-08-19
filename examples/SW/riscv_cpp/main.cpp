#include <vector>
#include <cstdio>
#include <iostream>
#include <memory>

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

int main()
{
    // Fails with illegal instruction because newlib was compiled with hardfloats.
    //printf("hello world %.2f\n", 3.1415);

    printf("===== hello world %i %c %08X =====\n", 123, 123, 123);

    std::cout << "hello c++ world" << std::endl;

    auto f = std::make_unique<Cow>();
    f->moo();
    Foo *foo = f.get();
    Cow *cow = dynamic_cast<Cow*>(foo);
    cow->moo();

    // Fails because of hardfloats too at: _Unwind_RaiseException+82
    /*try
    {
        throw 5;
    }
    catch (int i)
    {
        printf("caught: %i\n", i);
    }*/

    static int threadsafe_init = 7;

    std::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    return v[0] + v[1];
}
