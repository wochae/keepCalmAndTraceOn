int ft_isalpha(int c)
{
	if (97 <= c && c <= 122)
	{
		return (2);
	}
	else if (65 <= c && c <= 90)
	{
		return (1);
	}
	else
		return (0);
}
