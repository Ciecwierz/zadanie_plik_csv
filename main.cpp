#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "Queue.h"

#define BUFFER_SIZE 12
#define FILE_NAME_BUFFER 50

int main()
{
	
	char fileName[FILE_NAME_BUFFER];
	printf("Enter an exisiting file name: ");

	if (scanf("%s", fileName) != 1)
	{
		printf("Error while reading filename!\n");
		return 1;
	}
	size_t len = strlen(fileName);
	if (len < 4 || strcmp(fileName + len - 4, ".csv") != 0)
	{
		printf("Error! Accepted file extension: .csv\n");
		return 1;
	}
	



	FILE* input;
	FILE* output;
	Row row;
	Queue queue;

	initQueue(&queue);
	initRow(&row);
	
	char line[BUFFER_SIZE];

	input = fopen(fileName, "r");

	if (input != NULL)
	{
		output = fopen("./output.csv", "w");
		if (output == NULL)
		{
			printf("Error while creating a file\n");		
			fclose(input);
			return 1;
		}

		fprintf(output, "Wejscie;Avg;Max;Min;\n");

		while (1) 
		{	
			fgets(line, sizeof(line), input);	

			operations(&row, &queue, (float)atof(line));
			fprintf(output, "%.2f;%.2f;%.2f;%.2f;\n", row.data, row.average,
				row.maxValue, row.minValue);
			
			if (feof(input))
			{
				fclose(input);
				fclose(output);
				break;
			}
			
		}
	}
	
	else
	{ 
		printf("Error while opening a file\n");
		return 1;
	}


	return 0;
}