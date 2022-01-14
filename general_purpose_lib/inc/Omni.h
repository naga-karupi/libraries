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
#include"Dense"

class I_omni{
    virtual void operator()(float x_spd, float y_spd, float angular_v) = 0;
};

class three_wheel_omni : public I_omni{
    float x, y, theta;
    Eigen::Vector3f wheel;
    wheel = 0, 0, 0;
public:
    three_wheel_omni();
    ~three_wheel_omni();
    void operator ()(float x_spd, float y_spd, float angular_v)override;  
};

class inv_three_wheel_omni : public I_omni{
    float x, y, theta;
    Eigen::Vector3f wheel;
    wheel << 0, 0, 0;

public:
    inv_three_wheel_omni(float machine);
    ~inv_three_wheel_omni();
    void operator()(float x_spd, float y_spd, float angular_v)override;
};

class four_wheel_omni_1 : public I_omni{
    Eigen::Vector4f wheel;
    wheel << 0, 0, 0, 0;

    const float coeficient = 1/std::sqrt(2);
    const float length_center_to_wheel;

    const Eigen::MatrixXd<float, 3, 4> omni_matrix;
    omni_matrix <<
        -coeficient, coeficient, length_center_to_wheel,
        coeficient, coeficient, length_center_to_wheel,
        coeficient, -coeficient, length_center_to_wheel,
        -coeficient, -coeficient, length_center_to_wheel;

public:
    four_wheel_omni_1(float _length_center_to_wheel) : length_center_to_wheel(_length_center_to_wheel){}
    ~four_wheel_omni_1();
    inline void operator()(float x_spd, float y_spd, float angular_v)override;
};

class four_wheel_omni_2 : public I_omni{
    float x, y, theta;
    std::array<float, 4> wheel = {0};
public:
    four_wheel_omni_2();
    ~four_wheel_omni_2();
    void operator()(float x_spd, float y_spd, float angular_v)override;
};
