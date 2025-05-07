///////////////////////////////////////////////////////////////
// I UNDERSTAND THAT COPYING PROGRAMS FROM OTHERS WILL BE DEALT
// WITH DISCIPLINARY RULES OF CCNY.
// STUDENT NAME: Daniel Schur
// LOGIN_NAME: ee259
// EE259 SECTION (DAY/EVE): Day
///////////////////////////////////////////////////////////////
//
//THIS IS SAMPLE P8
//
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctype.h>

using namespace std;

ofstream o_f_8("output_8.txt", ios::out);

class EZ_DIFF_INTEGRATE
{
   public:
	EZ_DIFF_INTEGRATE(char *); // constructor; 
		// example: s.EZ_DIFF_INTEGRATE("in.txt");
		// input data file is given;

	void EZ_DIFF_BY_ME(float, float, int);
		// example: s.EZ_DIFF_BY_ME(a, b, n);
		// differentiate the function defined in input file;
		
	void EZ_INTEG_BY_ME(float, float, int);
		// example: s.EZ_INTEG_BY_ME(a, b, n);
		// integrate the function defined in input file;
		
   private:
	int np; // number of data pairs
	char func_type[10]; // sin, cos, or poly
	int exp; // exponent of sin or cos 
	int arg; // argument to include in function
};

EZ_DIFF_INTEGRATE::EZ_DIFF_INTEGRATE(char * in_fn)
{
	char TYPE[10];
	char char_tempo[10]; // temp var to hold a string;
	string str_tempo; // temp var to hold a string;
	int i_tempo; // temp var to hold an integer;

	o_f_8 << "CONSTRUCTOR WITH INPUT FILE: " << in_fn << endl;
	cout << "CONSTRUCTOR WITH INPUT FILE: " << in_fn << endl;
	// start parsing the input:
	ifstream i_f(in_fn, ios::in);

    //Check; I NEED TO DO FURTHER PARSING TO BE ABLE TO HANDLE THE POLYNOMIAL SITUATION
	i_f >> TYPE; //feeds the data from the input file into this variable
	cout << "1. I just read: " << TYPE << endl;

//_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/
    // parse to see if any part of our string exactly matches 'sin' or 'cos'
    //this tells us what kind of functions type we have


    if (strcmp(TYPE, "sin") == 0 or strcmp(TYPE, "cos") == 0)
    {
        strcpy(func_type, TYPE); // if we get sin or cos, we save that as our 
        //function type
    }
    else
    {
        // if it didn't match sin or cos throw an error
        cout << "ERROR: function type not sin or cos" << endl;
        return;
    }
//_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/
    //after parsing the first part of our string, we look for an open
    // parentheses to check if we have an exponent for our function


    i_f >> char_tempo;
    cout << "2. I just read: " << char_tempo << endl;

    if (strcmp(char_tempo, "(") == 0)
    {
        exp = 1; // if we see a parentheses assume no exponent
        // default value is 1;
        i_f >> i_tempo; // check this
        cout << "2.5 I just read: " << i_tempo << endl;
        arg = i_tempo;

    }

//_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/
    // if we don't see parantheses, we look for ** to indicate an exponent
    //

    else if (strcmp(char_tempo,"**") == 0)
    {
        i_f >> i_tempo;
        cout << "2.52. I just read: " << i_tempo << endl;
        exp = i_tempo;
        i_f >> char_tempo;
        if (strcmp(char_tempo,"(") == 0)
        {
        cout << "2.53. I just read: " << char_tempo << endl;
        i_f >> i_tempo;
        cout << "2.54. I just read: " << i_tempo << endl;
        arg = i_tempo;
        }
    }
    else
    {
        cout << "ERROR: couldn't determine exponent for function" << endl;
        return;
    }

//_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/
    // our input takes a very specific pattern it goes
    // either sin/cos ( integer * x )
    // or sin/cos ** integer ( integer * x)
   
    i_f >> char_tempo;
	cout << "3. I just read: " << char_tempo << endl;
	if (strcmp(char_tempo,"*") != 0)
	{
		cout << "some error after exponent" << endl;
		return;
	}
	i_f >> char_tempo;
	cout << "4. I just read: " << char_tempo << endl;
	if (strcmp(char_tempo,"x") != 0)
	{
		cout << "some error after exponent" << endl;
		return;
	}
	i_f >> char_tempo;
	cout << "5. I just read: " << char_tempo << endl;
	if (strcmp(char_tempo,")") != 0)
	{
		cout << "some error after exponent" << endl;
		return;
	}
	i_f >> char_tempo;
	cout << "6. I just read: " << char_tempo << endl;
	if (strcmp(char_tempo,";") != 0)
	{
		cout << "some error after exponent" << endl;
		return;
	}
    

    o_f_8 << "FUNCTION IS PARSED AS: " << func_type << " ** " << exp << " " << arg << "x" << endl;
    

 

	cout << "exp is: " << exp << "\targ is: " << arg << "\tfunc is: " << func_type << endl;
	cout << "I parsed the input file nicely;" << endl;

}

void
EZ_DIFF_INTEGRATE::EZ_DIFF_BY_ME(float a , float b, int n)
{
	int i, coeff;
	float x_new, x_old;
	float x[30]; // x coordinate;
	float df[30]; // first derivative;
	
	if (strcmp(func_type,"sin") == 0)
	{
        x_new = a; 
        coeff = (b - a)/(2 * n);
        
        for(i=0; i <= n; i++)
        {
            //float
        }
		// your code to compute differentiation for sin:

	}
	else if (strcmp(func_type,"cos") == 0)
	{
		// your code to compute differentiation for cos:

	}

	// report extreme points:

}

void
EZ_DIFF_INTEGRATE::EZ_INTEG_BY_ME(float a , float b, int n)
{
	int i, j, k;
	float x_new, x_old;
	float x[30]; // x coordinate;
	float df[30]; // first derivative;
	float ddf[30]; // second derivative;
	float integral = 0.0;
	float coeff = 0.0;
	float new_term = 1.0;
	
	if (strcmp(func_type,"sin") == 0)
	{
		// your code to compute integration for sin:
        x_new =a;
        coeff = (b - a)/(2 * n);

        for (i = 0; i <= n; i++)
        {
            float new_term = 1.0;
            for( k = 0; k < exp; k++)
            {
                new_term *= sin(arg*x_new);
            
            
            }
            if (i ==0 or i == (n))
            {
                integral += fabs(new_term);
            }
            else
            {
                integral += (2 * fabs(new_term));

            }
            x_new += (b-a)/n;
        }
        integral *= coeff;
	}
	else if (strcmp(func_type,"cos") == 0)
	{
        x_new =a;
        coeff = (b - a)/(2 * n);

        for (i = 0; i <= n; i++)
        {
            float new_term = 1.0;
            for( k = 0; k < exp; k++)
            {
                new_term *= cos(arg*x_new);
            
            
            }
            if (i ==0 or i == (n))
            {
                integral += fabs(new_term);
            }
            else
            {
                integral += (2 * fabs(new_term));

            }
            x_new += (b-a)/n;
        }
        integral *= coeff;

	}
    else{}
   // o_f_8 << " func type: " << func_type << " coeff: " << coeff << " arg: " << arg << endl;
    o_f_8 << "THE INTEGRATION OF THIS " << func_type << " FUNCTION " << endl;
    o_f_8 << "IN THE INTERVAL OF " << a << " AND " << b << " WITH " << n << " POINTS IS " << integral << endl;
}
