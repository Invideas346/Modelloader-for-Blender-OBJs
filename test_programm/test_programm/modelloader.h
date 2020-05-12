#pragma once
#include "model_struct.h"
#include <string.h>

bool modelloader(const char* filepath, Model& model)
{
	std::vector <int> indicies;
	std::vector <float> vertecies;

	float temp_vert[3] = { 0 };
	int temp_ind[9] = { 0 };

	char buffer[50];

	FILE* fp = fopen(filepath, "r");
	if (fp == NULL)
	{
		std::cout << "error: could not open file" << std::endl;
		return false;
	}

	while (1)
	{
		if (fgets(buffer, 50, fp) == NULL)
			break;
		if(strstr(buffer, "v "))
		{
			sscanf(&buffer[1], "%f %f %f", &temp_vert[0], &temp_vert[1], &temp_vert[2]);
			for(int i = 0; i < 3; i++)
			vertecies.push_back(temp_vert[i]);		
		}

		if (strstr(buffer, "f "))
		{
			sscanf(&buffer[1], "%d/%d/%d %d/%d/%d %d/%d/%d", &temp_ind[0], &temp_ind[1], &temp_ind[2], &temp_ind[3], &temp_ind[4], &temp_ind[5], &temp_ind[6], &temp_ind[7], &temp_ind[8]);
			for (int i = 0; i < 9; i++)
				indicies.push_back(temp_ind[i]);
		}
	}

	fclose(fp);
	model.copy(indicies, vertecies);
	return true;
}