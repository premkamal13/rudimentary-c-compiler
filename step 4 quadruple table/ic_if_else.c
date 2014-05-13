main()
{
	int i, j, output;
	
	if (i < 9)
		output=6;
	else
		output=7;
	output = output+1;

	if (i < 55)
	{
		if(i < 5)
		{
			output=99;
		}
		else
		{
			output=98;
		}
	}
	else
	{
		output=97;
	}
	output = output+1;

	if (j < 8)
	{
		output=999;
	} 
	else if (j < 88)
	{
		output=998;
	}
	else
	{
		output=997;
	}
	output = output+1;
}
