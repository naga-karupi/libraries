#include"../inc/MD.h"

int main(){
    unsigned char pin_a, pin_b;
    pin_b = 10;
    pin_a = 9;
    MD motor1(pin_a, pin_b);

    motor1 = 10;
}