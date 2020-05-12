#pragma once
#include <vector>
#include <iostream>

struct Model {
public:
	Model(){}
	Model(std::vector <int> indices, std::vector <float> vertecies);
	Model(const Model& other);
	~Model() {}

	void copy(std::vector <int> in_indices, std::vector <float> in_vertecies);

	std::vector <int> indicies;
	std::vector <float> vertecies;

	friend std::ostream& operator << (std::ostream& stream, const Model& other);
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

Model::Model(std::vector <int> in_indices, std::vector <float> in_vertecies)
{
	int indLenght, vertLenght;
	indLenght = in_indices.size();
	vertLenght = in_vertecies.size();

	this->indicies.resize(indLenght);
	this->vertecies.resize(vertLenght);

	for (int i = 0; i < indLenght; i++)
		this->indicies[i] = in_indices.at(i);

	for (int i = 0; i < vertLenght; i++)
		this->vertecies[i] = in_vertecies.at(i);
}

std::ostream& operator << (std::ostream& stream, const Model& other)
{
	stream << "Vertecies: \n";
	for (int i = 0; i < other.vertecies.size(); i++)
	{
		if ((i+1) % 3)
			stream << other.vertecies.at(i) << " ";
		else
		{
			stream << other.vertecies.at(i) << " ";
			stream << "\n";
		}
	}


	stream << "\n\n";
	stream << "Indicies: \n";

	for (int i = 0; i < other.indicies.size(); i += 3)
		stream << other.indicies.at(i) << " " << other.indicies.at(i + 1) << " " << other.indicies.at(i + 2) << "\n";

	return stream;
}

void Model::copy(std::vector <int> in_indices, std::vector <float> in_vertecies)
{
	int indLenght, vertLenght;
	indLenght = in_indices.size();
	vertLenght = in_vertecies.size();

	this->indicies.resize(indLenght);
	this->vertecies.resize(vertLenght);

	for (int i = 0; i < indLenght; i++)
		this->indicies[i] = in_indices.at(i);

	for (int i = 0; i < vertLenght; i++)
		this->vertecies[i] = in_vertecies.at(i);
}