#include "Color.h"
#include "Pixel.h"
#include "Image.h"
#include "CompositeImage.h"
#include "BinaryImage.h"
#include "Histogram.h"
#include "FinalColoredImg.h"
#include "DFS.h"
#include "Segmentation.h"
//#include "ProceduralTexture.h"
#include "ReverseImage.h"
#include "Scaledimage.h"
#include "Brightness.h"
#include "Gaussian.h"
#include "Labelledim.h"
#include "Labelledpix.h"

#include <iostream>
#include <time.h>
#include<sstream>
#include<fstream>
using namespace std;
#include <math.h>
#include <algorithm>
#include <vector>
#include <cstdlib>


void IMT2016072(char* file_name){
	Image I1;
	//cout<<file_name<<endl;
	ifstream file1(file_name,ios::out);
	file1>>I1;
	Brightness Bri(I1);
	//Bri.Analysis();

	// for (int i = 0; i < 256; ++i)
	// {

	// 	cout<<i<<"--"<<Bri.get_brightness()[i]<<endl;;
	// }
	// for (int i = 0; i < 256; ++i)
	// {

	// 	cout<<"T"<<i+1<<" = "<<Bri.Threshold()[i]<<endl;;
	// }
	cout<<"\n\nID Combination is 5 :\n";
	ofstream binary1("output_task-5_imt2016072_binary_C.ppm");
	int *thre = Bri.Threshold();
	int T1 = -1;
	Color blue(0,0,255);
	for (int i = 0; i < 256; ++i)
	{
		/* code */
		if(thre[i]!=0){
			T1 = i;
			cout<<"T1 is "<<T1<<endl;
			break;
		}
	}
	BinaryImage binary11(I1);
	Image Image_C = binary11.Binary_Image(T1,blue);
	binary1<<Image_C;
	binary1.close();


	ofstream binary2("output_task-5_imt2016072_binary_D.ppm");
	int T2 = -1;
	Color yellow(255,255,0);
	int count=0;
	for (int i = 0; i < 256; ++i)
	{
		/* code */
		if(thre[i]!=0){
			count+=1;
		}

		if(thre[i]!=0 && count==2){
			T2 = i;
			cout<<"T2 is "<<T2<<endl;
		}
	}
	BinaryImage binary22(I1);
	Image Image_D = binary22.Binary_Image(T2,yellow);
	binary2<<Image_D;
	binary2.close();

	// Histogram h(I1);
	// ofstream histo("histogram.ppm");
	// cout<<"Correct\n";
	// Image H = h.histo_Image();
	// cout<<"Correct\n";
	// histo<<H;
	// histo.close();

	//cout<<"Correct\n";
	file1.close();
	if(T1==-1 || T2==-1){
		cout<<"Threshold Not Found\n";
		cout<<"A and B reflections as C and D\n";
		ReverseImage rev(I1);
		rev.Upside_down();
		//mage_D=I1;
		ofstream reverse("Reverse.ppm");
		reverse<<I1;
		reverse.close();
		ifstream r("Reverse.ppm");
		r>>Image_D;
		r.close();

		rev.Upside_down();
		rev.Side_ways();
		Image_C=I1;
		ofstream side("Sideways.ppm");
		side<<I1;
		side.close();

	}
	else{
		cout<<"Threshold Found\n";
	}
	cout<<"Composition of image D with C\n";
	CompositeImage c(Image_D,Image_C);
	//cout<<"Correct\n";
	Image f = c.Composition(0.2);
	//cout<<"Correct\n";
	ofstream output("output_task-5_imt2016072.ppm");
	output<<f;
	output.close();
}


void IMT2016093( char *file_name)
{
		ifstream inFile;
		cout<<"ID Combination is 4 :\n";
		ofstream  output("output_task-4_imt2016093.ppm");
		string Line;
		int width, height, maxval;
		int i = 0;

		inFile.open(file_name);

		if (!inFile) {
			cout << "Unable to open file";
			exit(1); // terminate with error
		}
	
		while (getline(inFile, Line))
		{
			i++;
			if (i == 2)
			{
				width = atoi(Line.c_str());
				height = atoi(Line.c_str());
     	
			}
			if (i == 3)
			{
				maxval = atoi(Line.c_str());
				break;
			}
		}
		 Image z(width, height);
		 
		Segmentation b(width, height);

	     Image g(width,height);
		
		 float red, green, blue;
        for(int i=0;i<height;i++)
         {
        	for(int j=0;j<width;j++)
		 		{
             	inFile >> red >> green >> blue;
					b.get_pix()[i][j].set_c(Color(red,green,blue));
					g.get_pix()[i][j].set_c(Color(red,green,blue));
					z.get_pix()[i][j].set_c(Color(red,green,blue));
		 			b.arithmetic(red, green, blue);
		 		}
       }
       
       
       
		  b.threshold();
		 
	 	  b.color();
	 	  Image f(width,height);
	 	  
	 	    if(b.size()==0)
		  {
		     
		  	ReverseImage rev(g);
       		rev.Side_ways();
       		Image hh = rev.get_ima();
       		g=hh;
		    cout<<"Reversing Sideways\n";
		    CompositeImage d(g,z);
		    
		    f=d.Composition(0.4);
	     }
	     else
	     {
		 
    	   CompositeImage d(b,z);
		    f=d.Composition(0.4);
    	    
         }
         cout<<"Composition of images\n";
         output<<f;
	 	 inFile.close();
}


void IMT2016051(char* file_name){
  string str;
  cout<<"\n\nID Combination is 7 :\n";
  ifstream file(file_name,ios::out);
  Scaledimage s;
  file>>s;
  file.close();
   Image i6=s.half();
   cout<<"Scaling the Image\n";
  ofstream file1("output_task-7_imt2016051.ppm");
  file1<<i6;
  file1.close();
}


void IMT2016023(char* filename){
	Image img;
	ifstream f1(filename);
	f1>>img;
	Brightness b(img);

	cout<<"\n\nID Combination is 6\n";
	ofstream out("output-task6-imt2016023.ppm");
	ofstream out1("output1-task6-imt2016023.ppm");
	vector<int> threshold = b.threshold();
	int median_threshold = b.median(threshold);

	BinaryImage bin_img(img);
	Color black(0,0,0);
	Image BinImg = bin_img.Binary_Image(median_threshold,black);
	out1<<BinImg;
	out1.close();

	FinalColoredImg f_img(BinImg);
	cout<<"Coloring Connected Components\n";
	Image final_img = f_img.ColoredImg();

	out<<final_img;
	out.close();
}

void IMT2016132(char * some) {
	cout<<"\n\nID Combination is 8 :\n";
	Image input_img;
	ifstream inpu(some);
	inpu>>input_img;
	int y[256];
	for (int i = 0;i < 256;i++) {
		y[i]=0;
	}
	Labelledim comp_noise(Image(input_img.get_width(), input_img.get_height()));
	Pixel** temp = input_img.get_pix();
	for (int i = 0;i < input_img.get_height();i++) {
		for (int j = 0;j < input_img.get_width();j++) {
			float sdfg = rand() % 256;
			comp_noise.set_i_j(i, j, Color((int)((temp[i][j].get_c().get_red() + sdfg)/2), (int)((temp[i][j].get_c().get_green() + sdfg)/2 ), (int)((temp[i][j].get_c().get_blue() + sdfg)/2 )));
			int asdf = static_cast<int>((comp_noise.get_pix()[i][j].get_c().get_red() + comp_noise.get_pix()[i][j].get_c().get_blue() + comp_noise.get_pix()[i][j].get_c().get_green()) / 3);
			y[asdf]=y[asdf]+1;
		}
	}
	int thres_t1 = 0;
	for (int i = 15;i < 228;i++) {
		if (y[i-9]>y[i] && y[i-8]>y[i] && y[i - 7]>y[i] && y[i - 6]>y[i] && y[i - 5]>y[i] && y[i - 4]>y[i] && y[i - 3]>y[i] && y[i - 2]>y[i] && y[i - 1] > y[i] && y[i + 1] > y[i] && y[i + 2] > y[i] && y[i + 3] > y[i] && y[i + 4] > y[i] && y[i + 5] > y[i] && y[i + 6] > y[i] && y[i + 7] > y[i] && y[i + 8] > y[i] && y[i + 9] > y[i]) {
			thres_t1 = i;
			break;
		}
	}
	for (int i = 0;i < comp_noise.get_height();i++) {
		for (int j = 0;j < comp_noise.get_width();j++) {
			if ((comp_noise.get_pix()[i][j].get_c().get_red() + comp_noise.get_pix()[i][j].get_c().get_blue() + comp_noise.get_pix()[i][j].get_c().get_green()) / 3 > thres_t1) {
				comp_noise.set_i_j(i, j, Color(255, 255, 255));
				
			}
			else {
				comp_noise.set_i_j(i, j, Color(0, 0, 0));
			}
		}
	}
	int k=0;
	int takef = 0;
	for (int i = 0;i < comp_noise.get_height();i++) {
		for (int j = 0;j < comp_noise.get_width();j++) {
			if (comp_noise.get_pix()[i][j].get_c().get_red() == 0) {
				comp_noise.get_pix()[i][j].set_label(k);
				takef = 1;
				break;
			}
		}
		if (takef == 1) {
			break;
		}
	}
	cout<<"Labelling the Image..\n";
	cout << thres_t1 << endl;
	for (int i = 0;i < comp_noise.get_height();i++) {
		for (int j = 0;j < comp_noise.get_width();j++) {
			if (comp_noise.get_pix()[i][j].get_c().get_red() == 0) {
				if (i == 0 && j != 0) {
					if (comp_noise.get_pix()[i][j].get_c().get_red() == comp_noise.get_pix()[i][j - 1].get_c().get_red()) {
						comp_noise.get_pix()[i][j].set_sl(true);
						comp_noise.get_pix()[i][j].set_label(comp_noise.get_pix()[i][j - 1].get_label());
					}
					else {
						k++;
						comp_noise.get_pix()[i][j].set_sl(true);
						comp_noise.get_pix()[i][j].set_label(k);
					}
				}
				if (i != 0 && j == 0) {
					if (comp_noise.get_pix()[i][j].get_c().get_red() == comp_noise.get_pix()[i - 1][j].get_c().get_red()) {
						comp_noise.get_pix()[i][j].set_label(comp_noise.get_pix()[i - 1][j].get_label());
						comp_noise.get_pix()[i][j].set_sl(true);
					}
					else {
						k++;
						comp_noise.get_pix()[i][j].set_label(k);
						comp_noise.get_pix()[i][j].set_sl(true);
					}
				}
				if (i != 0 && j != 0) {
					if (comp_noise.get_pix()[i][j].get_c().get_red() == comp_noise.get_pix()[i][j - 1].get_c().get_red()) {
						comp_noise.get_pix()[i][j].set_label(comp_noise.get_pix()[i][j - 1].get_label());
						comp_noise.get_pix()[i][j].set_sl(true);
					}
					else if (comp_noise.get_pix()[i][j].get_c().get_red() == comp_noise.get_pix()[i - 1][j].get_c().get_red()) {
						comp_noise.get_pix()[i][j].set_label(comp_noise.get_pix()[i - 1][j].get_label());
						comp_noise.get_pix()[i][j].set_sl(true);
					}
					else {
						k++;
						comp_noise.get_pix()[i][j].set_label(k);
						comp_noise.get_pix()[i][j].set_sl(true);
					}
				}
			}
			else {
				comp_noise.get_pix()[i][j].set_sl(false);
			}
			/*if (i == 0 && j != 0) {
				if (comp_noise.get_pix()[i][j].get_c().get_red() == comp_noise.get_pix()[i][j-1].get_c().get_red()){
					comp_noise.get_pix()[i][j].set_sl(true);
					comp_noise.get_pix()[i][j].set_label(comp_noise.get_pix()[i][j - 1].get_label());
				}
				else {
					k++;
					comp_noise.get_pix()[i][j].set_sl(true);
					comp_noise.get_pix()[i][j].set_label(k);
				}
			}
			if (i != 0 && j == 0) {
				if (comp_noise.get_pix()[i][j].get_c().get_red() == comp_noise.get_pix()[i - 1][j].get_c().get_red()) {
					comp_noise.get_pix()[i][j].set_label(comp_noise.get_pix()[i - 1][j].get_label());
					comp_noise.get_pix()[i][j].set_sl(true);
				}
				else {
					k++;
					comp_noise.get_pix()[i][j].set_label(k);
					comp_noise.get_pix()[i][j].set_sl(true);
				}
			}
			if (i != 0 && j != 0) {
				if (comp_noise.get_pix()[i][j].get_c().get_red() == comp_noise.get_pix()[i][j - 1].get_c().get_red()) {
					comp_noise.get_pix()[i][j].set_label(comp_noise.get_pix()[i][j - 1].get_label());
					comp_noise.get_pix()[i][j].set_sl(true);
				}
				else if (comp_noise.get_pix()[i][j].get_c().get_red() == comp_noise.get_pix()[i - 1][j].get_c().get_red()) {
					comp_noise.get_pix()[i][j].set_label(comp_noise.get_pix()[i - 1][j].get_label());
					comp_noise.get_pix()[i][j].set_sl(true);
				}
				else {
					k++;
					comp_noise.get_pix()[i][j].set_label(k);
					comp_noise.get_pix()[i][j].set_sl(true);
				}
			}*/
		}
	}
	cout<<"Coloring labelled parts..\n";
	Color color_list[] = { Color(255,0,0),Color(0,255,0),Color(0,0,255),Color(255,255,0), Color(0,255,255),Color(255,0,255) };
	int colors_list_size = 6;
	for (int i = 0;i < comp_noise.get_height();i++) {
		for (int j = 0;j < comp_noise.get_width();j++) {
			if (comp_noise.get_pix()[i][j].get_sl()) {
				comp_noise.set_i_j(i, j, color_list[(comp_noise.get_pix()[i][j].get_label())%(colors_list_size+1)]);
			}
			else {
				comp_noise.set_i_j(i, j, Color(0,0,0));
			}
		}
	}
	ofstream outpu("output-task8-imt2016132.ppm");
	outpu<<comp_noise;
}

void IMT2016113(char *file_name){
	Image i1;
	cout<<"\n\nID Combination is 3 :\n";
	ifstream f(file_name);
	f>>i1;
	ReverseImage rev(i1);
	rev.Upside_down();
	Gaussian g(i1);
	f.close();
	cout<<"Applying Gaussian filter\n";
	ofstream of("output-task3-imt2016113.ppm");
	of<<g;
	of.close();
}


int main(int argc,char **argv){
	//Use this line in command prompt
	//g++ Color.cpp Pixel.cpp Image.cpp Brightness.cpp BinaryImage.cpp CompositeImage.cpp Histogram.cpp ReverseImage.cpp Scaledimage.cpp DFS.cpp FinalColoredImg.cpp Main.cpp

	char* file_name=argv[1];
	cout<<"Our group task ID combination is: 6,7,5,4,3,8\n\n";
	IMT2016093(file_name);
	IMT2016072(file_name);
	IMT2016051(file_name);
	IMT2016023(file_name);
	IMT2016113(file_name);
	IMT2016132(file_name);



}
