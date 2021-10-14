/*
二重数の実部をre
虚部(？)をimとします

入力方式
variable(関数名, 引数, 係数);
出力
variable();
variable.dfunc();

もとの関数の値をとる
variable
*/
#include<cmath>
#include<array>

enum Table{
    X = 0x01,
    XX = 0x02,
    EXP = 0x04,
    LOG = 0x08,
    SIN = 0x10,

    CONSTANT = 0X20
};

template<typename T>
class differential {
    unsigned int func_type;
    T num, re,im ,re_s, im_s;
    static T const_num;
    
    void constant(){re_s= 1;          im_s = 0;           }
    void x()  {re_s = num;            im_s = 1;           }
    void xx() {re_s = num*num;        im_s = 2*num;       }
    void exp(){re_s = std::exp(num); im_s = re_s;         }
    void log(){if(!num)num = 1; 
               re_s = std::log(num); im_s = 1/num;        }
    void sin(){re_s = std::sin(num); im_s = std::cos(num);}

public:
    differential(unsigned int _functype = 0, T _num = 0, T _const_num = 1) 
                : func_type(_functype), num(_num){
        const_num = _const_num;
        if(func_type&X)  set(x);
        if(func_type&XX) set(xx);
        if(func_type&EXP)set(exp);
        if(func_type&LOG)set(log);
        if(func_type&SIN)set(sin);
    }
    
    T func(){return const_num*re;}
    T dfunc(){return const_num*im;}

    T operator()();
    constexpr differential* operator + (const differential&);
    constexpr differential* operator - (const differential&);
    constexpr differential* operator * (const differential&);
    constexpr differential* operator / (const differential&);
};
