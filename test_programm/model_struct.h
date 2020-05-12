#pragma once
#include <vector>

struct Model {
public:
	Model(){}
	Model(const Model& other);
	~Model(){}

	std::vector <int> indicies;
	std::vector <float> vertecies;
};

Model::Model(const Model& other)
{
	int indLenght, vertLenght;
	indLenght = other.indicies.size();
	vertLenght = other.vertecies.size();

	indicies.resize(indLenght);
	vertecies.resize(vertLenght);
	for (int i = 0; i < indLenght; i++)
		indicies[i] = other.indicies.at(i);

	for (int i = 0; i < vertLenght; i++)
		vertecies[i] = other.vertecies.at(i);
}