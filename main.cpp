#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <cstdio>
#include <cstdlib>
#include "Queue.h"

#define BUFFER_SIZE 12
#define FILE_NAME_BUFFER 50

int main()
{
	FILE* input;
	FILE* output;
	char fileName[FILE_NAME_BUFFER];
	scanf("Enter an exisiting file name: %s", fileName);
	input = fopen("./triangle_wave.csv", "r");
	Row row;
	Queue queue;

	initQueue(&queue);
	initRow(&row);
	
	char line[BUFFER_SIZE];

	

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