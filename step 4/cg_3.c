int result=0;
int size=10;
int a[] = {5, 1, 3, 9, 8, 40, 10, 2, 6, 7};
int search=4;

main()
{
	int i;

	i = 0;

	result = 0;

	while (i < size)
	{
		if (a[i] == search)
		{
			result = 1;
		}

		i = i + 1;
	}
}

