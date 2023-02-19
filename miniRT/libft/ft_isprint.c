int ft_isprint(int c)
{
	if (32 <= c && c <= 126)
	{
		return (1);
	}
	else
		return (0);
}
