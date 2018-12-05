#pragma once
#include "Image.h"
#include "Labelledpix.h"
using namespace std;
class Labelledim :
	public Image
{
private:
	Labelledpix** lpix;
public:
	Labelledim(Image img);
	Labelledpix ** get_pix();
	Labelledim();
	~Labelledim();
	void set_i_j(int, int, Color);
	friend ostream& operator<<(ostream &os, Labelledim &m);
};