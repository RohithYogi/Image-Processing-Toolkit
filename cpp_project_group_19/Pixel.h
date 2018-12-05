#ifndef Pixel_h_
#define Pixel_h_

#include <iostream>
#include<fstream>
using namespace std;
#include <math.h>
#include <algorithm>
#include <vector>
#include <cstdlib>

#include "Color.h"

class Pixel{
	private:
		unsigned int xlocation;
		unsigned int ylocation;
		Color colour;
	public:
		Pixel();

		Pixel(unsigned int x,unsigned int y);

		~Pixel();

		Pixel(const Pixel& p);

		void set_x(unsigned int x);

		void set_y(unsigned int x);

		void set_c(Color c);

		int get_x();

		int get_y();

		vector<unsigned int> fib(unsigned int n);

		void set();

		Color get_c();

	
};

#endif
