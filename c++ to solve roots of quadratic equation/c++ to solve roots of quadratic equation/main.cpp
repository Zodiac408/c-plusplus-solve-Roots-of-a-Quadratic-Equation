
#include<iostream>
#include<Windows.h>
#include<cmath>


// Our Formula b^2 - 4ac
double determinant;

struct Root
{
	double root1;
	double root2;

	double real;
	double fake;

}rt;

struct input
{
	double a;
	double b;
	double c;
}ip;




void ErrorCheck()
{

	if (std::cin.fail() == true)
	{
		system("cls");
		std::cout << "Invaild input, Program will be closed in 2s" << std::endl;
		system("Color C");
		Sleep(1900);
		system("cls");
		std::cout << "Invaild input" << std::endl;
		Sleep(100);
		exit(1);
	}

}


void input()
{
	std::cout << "Enter a: ";
	
	std::cin >> ip.a;
	ErrorCheck(); // Check for everytime when user input    //a

	std::cout << "Enter b: ";
	std::cin >> ip.b;
	ErrorCheck(); // Check for everytime when user input   //b

	std::cout << "Enter c: ";
	std::cin >> ip.c;
	ErrorCheck(); // Check for everytime when user input  //c 

	//store a b c into determinant first
	determinant = (pow(ip.b, 2) - (4 * ip.a * ip.c));
}


void calculate()
{
	input(); //input function



	if (determinant > 0)
	{
		rt.root1 = (-ip.b + sqrt(determinant)) / (2 * ip.a);
		rt.root2 = (-ip.b - sqrt(determinant)) / (2 * ip.a);

		std::cout << "" << std::endl; //create a new line

		std::cout << "Roots are different!" << std::endl;

		std::cout << "" << std::endl; //create a new line
		std::cout << "Root X1 = " << rt.root1 << "\t\t" << "Root X2 = " << rt.root2 << std::endl;
	}
	else if (determinant == 0)
	{
		rt.root1 = -ip.b / (2 * ip.a);	// they are same no need write rt.root2 but i like make it clear
		rt.root2 = rt.root1;

		std::cout << "" << std::endl; //create a new line

		std::cout << "Roots are same!" << std::endl;

		std::cout << "" << std::endl; //create a new line
		std::cout << "Root X1 = " << rt.root1 << "\t\t" << "Root X2 = " << rt.root2 << std::endl;
	}
	else
	{
		rt.real = -ip.b / (2 * ip.a);
		rt.fake = sqrt(-determinant) / (2 * ip.a); //  == sqrt-(b^2 -4ac)

		std::cout << "" << std::endl; //create a new line

		std::cout << "Roots are complex and different." << std::endl;

		std::cout << "" << std::endl; //create a new line
		std::cout << "Root X1 = " << rt.real << " + " << rt.fake << " (i)" << std::endl;
		std::cout << "Root X2 = " << rt.real << " - " << rt.fake << " (i)" << std::endl;
	}

	system("pause");


}


int main()
{

	SetConsoleTitleA("c++ Roots of a Quadratic Equation");
	calculate();

	return 0;
}

//Credit to https://www.programiz.com/cpp-programming/examples/quadratic-roots
//improved By Zodiac