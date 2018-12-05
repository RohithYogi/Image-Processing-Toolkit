#include "Histogram.h"
#include "Brightness.h"

#include <iostream>
#include <time.h>
#include<sstream>
#include<fstream>
using namespace std;
#include <math.h>
#include <algorithm>
#include <vector>
#include <cstdlib>

Histogram::Histogram(Image I){
	ima = I;
}
	
Histogram::~Histogram(){

}


Image Histogram::histo_Image(){
	int max=-1;
	Brightness B(ima);
	//B.Analysis();
	for (int i = 0; i < 256; ++i)
	{
		/* code */
		if(max<B.get_brightness()[i]){
			max=B.get_brightness()[i];
		}
	}
	//cout<<max<<endl;
	Image histo(256,max+1);
	//cout<<"corr\n";
	for (unsigned int i = 0; i < max+1; ++i)
	{
		/* code */
		for (unsigned int j = 0; j < 256; ++j)
		{
			/* code */
			Color c(255,255,255);
			histo.get_pix()[i][j].set_c(c);
		}
	}
	//cout<<"corr\n";
	for (unsigned int j = 0; j < 256; ++j)
	{
		/* code */
		int in = max-B.get_brightness()[j];
		//cout<<in<<endl;
		Color c(0,0,0);
		histo.get_pix()[in][j].set_c(c);
		
	}

	for (unsigned int i = 0; i < max+1; ++i)
	{
		/* code */
		for (unsigned int j = 0; j < 256; ++j)
		{
			/* code */
			if(histo.get_pix()[i][j].get_c().get_red()==0){
				int a =i;
				//int b =j;
				while(a!=max+1)
				{
					Color c(0,0,0);
					histo.get_pix()[a][j].set_c(c);
					a++;
				}

			}
		}
	}

	//cout<<"corr\n";

	return histo;
}