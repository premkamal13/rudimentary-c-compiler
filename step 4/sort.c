int result=0;
int size=10;
int a[] = {5, 1, 3, 9, 8, 4, 10, 2, 6, 7};

main()
{
	int i, j, temp;

	i = 0;

	while (i < size-1)
	{
		j = i+1;

		while (j < size)
		{
			if (a[j] < a[i])
			{
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
			j = j+1;
		}
		i = i + 1;
	}
}

