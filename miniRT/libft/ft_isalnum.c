int ft_isalnum(int c)
{
	if (97 <= c && c <= 122)
	{
		return (2);
	}
	else if (65 <= c && c <= 90)
	{
		return (1);
	}
	else if (48 <= c && c <= 57)
	{
		return (4);
	}
	else
		return (0);
}
