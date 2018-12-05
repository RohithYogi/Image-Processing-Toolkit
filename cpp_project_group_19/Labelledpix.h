#pragma once
#include "Pixel.h"
#include "Color.h"
using namespace std;
class Labelledpix :
	public Pixel
{
private:
	int label;
	bool setl;
public:
	void set_sl(bool);
	bool get_sl();
	void set_label(int);
	int get_label();
	Labelledpix();
	Labelledpix(Pixel);
	~Labelledpix();
};

