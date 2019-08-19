#include <vector>
#include <cstdio>
#include <iostream>

int main()
{
    // Fails with illegal instruction because newlib was compiled with hardfloats.
    //printf("hello world %.2f\n", 3.1415);

    printf("===== hello world %i %c %08X =====\n", 123, 123, 123);

    std::cout << "hello c++ world" << std::endl;

    std::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    return v[0] + v[1];
}
