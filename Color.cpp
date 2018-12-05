#include "Color.h"

#include <iostream>
#include <time.h>
#include<sstream>
#include<fstream>
using namespace std;
#include <math.h>
#include <algorithm>
#include <vector>
#include <cstdlib>

Color:: Color(){

}

Color::Color(float r,float g,float b){
	red=r;
	green=g;
	blue=b;
}

Color::~Color(){

}

Color::Color(const Color& c){
	red=c.red;
	green=c.green;
	blue=c.blue;
}

bool Color::get_status(){
	if(red==0 && green==0 && blue==0){
		return true;
	}
	else{
		return false;
	}
}

void Color::set_red(float a){
	red=a;
}

void Color::set_green(float a){
	green=a;
}

void Color::set_blue(float a){
	blue=a;
}

float Color::get_red(){
	return red;
}
		
float Color::get_green(){
	return green;
}

float Color::get_blue(){
	return blue;
}