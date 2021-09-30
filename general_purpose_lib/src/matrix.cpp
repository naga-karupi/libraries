#include<array>
#include<iostream>


namespace naga{
    template<typename T, typename T2>
    auto operator + (T& op, T& op2){
        return 1;
    }
}

using namespace naga;

int main(){
    std::array<int, 4> i, j;
    int p = i + j;
    std::cout<<p<<std::endl;

    return 0;
}