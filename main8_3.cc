#include "p8.h"
// example program: main8_3.cc
int main()
{
	//EZ_DIFF_INTEGRATE e("/mnt/ee259dir/tools/pro_8/input_8_3.txt"); // constructor; 
	EZ_DIFF_INTEGRATE e("/Users/dschur/EE259_Work/pro_8/input_8_3.txt"); // constructor; 
	e.EZ_INTEG_BY_ME(-5, 5, 20);
	return 0;
}
