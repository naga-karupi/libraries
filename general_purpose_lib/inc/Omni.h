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
#include<Eigen/Dense>

template<typename T>
class I_Omni{
    virtual T operator()(T x_spd, T y_spd, T angular_v);
};

template<typename T>
class Three_Wheel_Omni : public I_Omni<T>{
    T x, y, theta;
    std::array<T, 3> wheel = {0};
public:
    Three_Wheel_Omni();
    ~Three_Wheel_Omni();
    std::array<T, 3> operator ()(T x_spd, T y_spd, T angular_v)override;  
};

template<typename T>
class inv_Three_Wheel_Omni : public I_Omni<T>{
    T x, y, theta;
    std::array<T, 3> wheel = {0};
        
    constexpr float coeficient = 1/std::sqrtf(2);
    constexpr float center_to_wheel_length = 0.187;

    Eigen::Matrix<float, 3, 4> omni_matrix = {
        {-coeficient, coeficient, center_to_wheel_length},
        {coeficient, coeficient, center_to_wheel_length},
        {coeficient, -coeficient, center_to_wheel_length},
        {-coeficient, -coeficient, center_to_wheel_length},
    }

public:
    inv_Three_Wheel_Omni();
    ~inv_Three_Wheel_Omni();
    std::array<T, 3> operator()(T x_spd, T y_spd, T angular_v)override;
};

template<typename T>
class Four_Wheel_Omni_1 : public I_Omni<T> {
    T x, y, theta;
    std::array<T, 4> wheel = {0};
public:
    Four_Wheel_Omni_1();
    ~Four_Wheel_Omni_1();
    std::array<T, 4> operator()(T x_spd, T y_spd, T angular_v)override;
};

template<typename T>
class Four_Wheel_Omni_2 : public I_Omni<T>{
    T x, y, theta;
    std::array<T, 4> wheel = {0};
public:
    Four_Wheel_Omni_2();
    ~Four_Wheel_Omni_2();
    std::array<T, 4> operator()(T x_spd, T y_spd, T angular_v)override;
};
