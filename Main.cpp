#include "Color.h"
#include "Pixel.h"
#include "Image.h"
#include "CompositeImage.h"
#include "BinaryImage.h"
#include "Histogram.h"
//#include "ProceduralTexture.h"
#include "ReverseImage.h"
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


void IMT2016072(char* file_name){
	Image I1;
	//cout<<file_name<<endl;
	ifstream file1(file_name,ios::out);
	file1>>I1;
	Brightness Bri(I1);
	//Bri.Analysis();

	for (int i = 0; i < 256; ++i)
	{

		cout<<i<<"--"<<Bri.get_brightness()[i]<<endl;;	
	}
	for (int i = 0; i < 256; ++i)
	{

		cout<<"T"<<i+1<<" = "<<Bri.Threshold()[i]<<endl;;	
	}
	cout<<"ID Combination is 5 :\n";
	ofstream binary1("output_task-5_imt2016072_binary_C.ppm");
	int *thre = Bri.Threshold();
	int T1 = -1;
	Color c1(0,0,255);
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
	Image Image_C = binary11.Binary_Image(T1,c1);
	binary1<<Image_C;
	binary1.close();


	ofstream binary2("output_task-5_imt2016072_binary_D.ppm");
	int T2 = -1;
	Color c2(255,255,0);
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
	Image Image_D = binary22.Binary_Image(T2,c2);
	binary2<<Image_D;
	binary2.close();

	Histogram h(I1);
	ofstream histo("histogram.ppm");
	//cout<<"Correct\n";
	Image H = h.histo_Image();
	//cout<<"Correct\n";
	histo<<H;
	histo.close();



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
		cout<<"\n\nID Combination is 4 :\n";
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
		 
		Histogram b(width, height);

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
		    
		    CompositeImage d(z,g);
		    
		    f=d.Composition(0.4);
	     }
	     else
	     {
		 
    	   CompositeImage d(z,b);
		    f=d.Composition(0.4);
    	    
         }
         output<<f;
	 	 inFile.close();
	 	 

}



int main(int argc,char **argv){
	//Use this line in command prompt
	//g++ Color.cpp Pixel.cpp Image.cpp Brightness.cpp BinaryImage.cpp CompositeImage.cpp Histogram.cpp ReverseImage.cpp Main.cpp

	char* file_name=argv[1];
	cout<<"Our group task ID combination is: 6,7,5,4,3,8\n\n";
	IMT2016072(file_name);
	//IMT2016093(file_name);
	



}