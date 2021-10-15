/*
三輪オムニの行列
入力はx,y,θ
→x ↑y
反時計回りθ

出力はホイール1,2,3の順
hree omni
　 　1
     |
     |
   /   \    
 /       \   
2         3  

反転バージョンあり(inv three wheel omni)

four omni wheel 1
1--------2
|        |
|        |
|        |
3--------4

four omni wheel 2
----1----
|       |
2       3
|       |
----4----
初期でこのようなオムニを想定しています
*/

#include<array>

using std::array;

template<typename T>
class I_Omni{
    virtual T operator()();
};

template<typename T>
class Three_Wheel_Omni : public I_Omni<T>{
    T x, y, theta;
    array<T, 3> wheel = {0};
public:
    Three_Wheel_Omni();
    ~Three_Wheel_Omni();
    array<T, 3> operator ()(T, T, T)override;  
};

template<typename T>
class inv_Three_Wheel_Omni : public I_Omni<T>{
    T x, y, theta;
    array<T, 3> wheel = {0};
public:
    inv_Three_Wheel_Omni();
    ~inv_Three_Wheel_Omni();
    array<T, 3> operator()(T, T, T)override;
};

template<typename T>
class Four_Wheel_Omni_1 : public I_Omni<T> {
    T x, y, theta;
    array<T, 4> wheel = {0};
public:
    Four_Wheel_Omni_1();
    ~Four_Wheel_Omni_1();
    array<T, 4> operator()(T, T, T)override;
};

template<typename T>
class Four_Wheel_Omni_2 : public I_Omni<T>{
    T x, y, theta;
    array<T, 4> wheel = {0};
public:
    Four_Wheel_Omni_2();
    ~Four_Wheel_Omni_2();
    array<T, 4> operator()(T, T, T)override;
};