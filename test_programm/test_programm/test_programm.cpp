#include <iostream>
#include "modelloader.h"

int main()
{
	Model model;
	modelloader("test_models/cube.obj", model);
	std::cout << model << std::endl;
}