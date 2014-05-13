main()
{
	int i, j, k, output;
	
	output = -1;
	if ((i < 9) || (j > 8) && (k==7))
		output=6;

	if (i != 5)
	{
		if(j >= 4)
		{
			if(k)
			{
				output = output+1;
			}
			output = output+1;
		}
		output = output+1;
	}
	output = output+1;
}

