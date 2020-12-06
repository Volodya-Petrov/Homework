#include "Graph.h"
#include "List.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool addCityToCountry(Graph* graph, List** countries, bool isUsed[], int country)
{	
	int minDist = INT_MAX;
	int cityWithMinDist = 0;
	for (int i = 0; i < length(countries[country]); i++)
	{	
		int city = 0;
		getValue(countries[country], i, &city);
		for (int j = 0; j < getVertices(graph); j++)
		{	
			int distance = getDistance(graph, city, j);
			if (isUsed[j] || distance < 1)
			{
				continue;
			}
			if (distance < minDist)
			{
				minDist = distance;
				cityWithMinDist = j;
			}
		}
	}
	if (minDist != INT_MAX)
	{	
		isUsed[cityWithMinDist] = true;
		append(countries[country], cityWithMinDist);
		return true;
	}
	return false;
}

void buildCountries(Graph* graph, List** countries, int countOfCountries, bool isUsed[])
{
	int numberOfCountry = 0;
	int freeVertices = getVertices(graph) - countOfCountries;
	while (freeVertices > 0)
	{
		if (addCityToCountry(graph, countries, isUsed, numberOfCountry % countOfCountries))
		{
			freeVertices--;
		}
		numberOfCountry++;
	}
}

List** getCountries(char fileName[])
{
	FILE* fileOpen = fopen(fileName, "r");
	int countOfCities = 0;
	fscanf(fileOpen, "%i", &countOfCities);
	int countOfWays = 0;
	fscanf(fileOpen, "%i", &countOfWays);
	Graph* graph = makeGraph(countOfCities);
	for (int i = 0; i < countOfWays; i++)
	{
		int firstCity = 0;
		int secondCity = 0;
		int distance = 0;
		fscanf(fileOpen, "%i %i %i", &firstCity, &secondCity, &distance);
		fillGraph(graph, firstCity - 1, secondCity - 1, distance);
	}
	int countOfCountries = 0;
	fscanf(fileOpen, "%i", &countOfCountries);
	bool* isUsed = calloc(countOfCities, sizeof(bool));
	List** list = calloc(countOfCountries, sizeof(List*));
	for (int i = 0; i < countOfCountries; i++)
	{
		list[i] = createList();
		int capital = 0;
		fscanf(fileOpen, "%i", &capital);
		append(list[i], capital - 1);
		isUsed[capital - 1] = true;
	}
	fclose(fileOpen);
	buildCountries(graph, list, countOfCountries, isUsed);
	free(isUsed);
	deleteGraph(&graph);
	return list;
}