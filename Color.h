#ifndef Color_h_
#define Color_h_

#include <iostream>
#include<fstream>
using namespace std;
#include <math.h>
#include <algorithm>
#include <vector>
#include <cstdlib>

class Color{
	
	private:
		float red;
		float green;
		float blue;

	public:
		Color();


		Color(float r,float g,float b);

		~Color();

		Color(const Color& c);

		bool get_status();

		void set_red(float a);
		
		void set_green(float a);

		void set_blue(float a);

		float get_red();
		
		float get_green();

		float get_blue();
};

#endif
