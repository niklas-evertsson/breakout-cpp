#include "CSVReader.h"
#include <fstream>
#include <sstream>

std::vector<std::vector<std::string>> CSVReader::Read(std::string filePath)
{
	std::fstream fStream;
	fStream.open(filePath, std::ios::in);

	std::string line, word;
	std::vector<std::string> row;
	std::vector<std::vector<std::string>> data;

	while(fStream >> line)
	{
		row.clear();

		std::stringstream sStream(line);

		while(std::getline(sStream, word, ',') && word != "EOL")
		{
			row.push_back((word));
		}

		data.push_back(row);
	}

	return data;
}
