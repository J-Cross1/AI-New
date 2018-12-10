#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>


float sigmoid(float x, float y, float Theta);
float step(float x, float y, float Theta);
float sign(float x, float y, float Theta);
float sigma(float x, float y, float w);
float linear(float x, float y, float Theta);

float x1[4] = { 0,0,1,1 };
float x2[4] = { 0,1,0,1 };
float Yd[4] = { 0,0,0,1 };

int main()
{
	int Niterations = 20;
	float y = 1.0;
	float w1 = 0.3, w2 = -0.1;

	float Theta = 0, alpha = 0.1;

	std::cout << "x1 \t" << "x2 \t" << "Yd \t" << "y \t" << " e \t" << "w1 \t" << "w2 \n";
	//std::cout << "x \t y \n";
	for (int p = 0; p < Niterations; p++)
	{
		int i = p % 4;
		float x = x1[i] * w1 + x2[i] * w2;
		y = step(x, y, Theta);
	
		float e;
		e = Yd[i] - y;

		w1 = w1 + alpha * x1[i] * e;
		w2 = w2 + alpha * x2[i] * e;

		std::cout << x1[i] << "\t" << x2[i] << "\t" << Yd[i] << "\t" << y << "\t" << e << "\t" << w1 << "\t" << w2 << "\n";


		//std::cout << x << "\t" << y << std::endl;
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