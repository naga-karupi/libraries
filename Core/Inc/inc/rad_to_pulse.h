/*
 * rad_to_pulse.h
 *
 *  Created on: Oct 16, 2021
 *      Author: naga_karupi
 */

#include<bits/stdc++.h>

#ifndef INC_INC_RAD_TO_PULSE_H_
#define INC_INC_RAD_TO_PULSE_H_

class rad_to_pulse{
	const int Encoder_Resolution;
public:
	rad_to_pulse(int _Encoder_Resolution) : Encoder_Resolution(_Encoder_Resolution){}

	int operator ()(float rad){
		return (int)Encoder_Resolution / (2*M_PI);
	}
};


#endif /* INC_INC_RAD_TO_PULSE_H_ */
