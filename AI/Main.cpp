#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>


float sigmoid(float x, float y, float Theta);
float step(float x, float y, float Theta);
float sign(float x, float y, float Theta);
float sigma(float x, float y, float w);
float linear(float x, float y, float Theta);

int x1[4] = { 0,0,1,1 };
int x2[4] = { 0,1,0,1 };
int Yd[4] = { 0,0,0,1 };

int main()
{
	int Niterations = 20;
	int y = 1;
	float w1 = 0.3, w2 = -0.1;

	float Theta = 0.2, alpha = 0.1;

	for (int p = 0; p < Niterations; p++)
	{
		int i = p % 4;
		int x = x1[i] * w1 + x2[i] * w2;
		y = step(x, y, Theta);
	
		int e = Yd[i] - y;

		w1 = w1 + alpha * x1[i] * e;
		w2 = w2 + alpha * x2[i] * e;

		std::cout << x1[i] << "\t" << x2[i] << "\t" << Yd[i] << "\t"  << y << "\t" << e << "e" <<  w1 << "\t" << w2 << "\n";
	}
	
	system("pause");
}

float sign(float x, float y, float Theta)
{
	if (x >= (Theta - 0.00000001f))
	{
		y = 1;
	}
	else if (x < Theta)
	{
		y = -1;

	}

	return y;
}

float step(float x, float y, float Theta)
{
	if (x >= (Theta - 0.00000001f))
	{
		y = 1;
	}
	else if (x < Theta)
	{
		y = 0;

	}

	return y;
}


float sigmoid(float x, float y, float Theta)
{


	float epow = pow(M_E, (-(x - Theta)));

	y = 1 / (1 + epow);

	return y;
}


float sigma(float x, float y, float w)
{

	y += x * w;
	return y;
}

float linear(float x, float y, float Theta)
{


	return x - Theta;
}