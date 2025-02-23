#include <stdio.h>
#include <float.h>
#include <stdlib.h>
#include <string.h>

float average(float number, float avrg, unsigned int i)
{
	float new;

	new = avrg - (avrg / i) + (number / i);
	return new;
}

void	ft_array_sort(float *arr)
{
	float	temp;
	int		size;
	int		i;
	int		j;

	i = 0;
	size = sizeof(*arr) / sizeof(float);
	while (i < size)
	{
		j = 0;
		while (j + i < size)
		{
			if (arr[i + j] < arr[i])
			{
				temp = arr[i];
				arr[i] = arr[i + j];
				arr[i + j] = temp;
			}
			j++;
		}
		i++;
	}
}

int main(int argc, char *argv[]) {
	char status[10];
	unsigned int size;
	unsigned int i;
	unsigned int j;
	float	max = FLT_MIN;
	float	min = FLT_MAX;
	float	median = 0;
	float *array;
	float number;
	float avrg = 0.0;

	if (argc != 2)
	{
		printf("Usage: %s <file>\n", argv[0]);
		return (0);
	}
	FILE *file = fopen(argv[1], "r");

	if (file == NULL) {
		perror("Failed to open file");
		return (1);
	}

	size = 0;
	while (fscanf(file, "%s %f", status, &number) == 2)
	{
		if (!strcmp(status, "KO"))
		{
			printf("KO");
			fclose(file);
			return (1);
		}
		size++;
	}
	fclose(file);

	file = fopen(argv[1], "r");
	array = malloc(sizeof(float) * size);
	i = 0;
	while (fscanf(file, "%s %f", status, &array[i]) == 2)
	{
		if (array[i] > max)
			max = array[i];
		else if (array[i] < min && array[i] != 0)
			min = array[i];
		avrg = average(array[i], avrg, i + 1);
		i++;
	}
	fclose(file);

	//Print Average
	printf("Number of tests: %u\n", i);
	printf("Avg number of operations: %.2f\n", avrg);
	printf("Min number of operations: %.0f\n", min);
	printf("Max number of operations: %.0f\n", max);

	printf("Sorting...\n");
	ft_array_sort(array);
	j = (i - 1) / 2;
	if (i % 2 == 1)
		printf("Median: %.0f\n", median = array[j]);
	else
		printf("Median: %.0f\n", median = average(array[j], array[j + 1], 2));
	printf("Lower Deviance: %.0f\n", median - min);
	printf("Upper Deviance: %.0f\n", max - median);

	avrg = 0;
	i = 0;
	while (i < size)
	{
		if (array[i] < median)
			avrg = average(median - array[i], avrg, i + 1);
		else if (array[i] > median)
			avrg = average(array[i] - median, avrg, i + 1);
		i++;
	}
	printf("Average Deviance: %.2f\n", avrg);

	free(array);
	return 0;
}
