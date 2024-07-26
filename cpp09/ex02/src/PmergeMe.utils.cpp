static bool isPositiveInteger(std::string &str)
{
	if (str.empty())
		return (false);

	for (char c : str)
	{
		if (!isdigit(c))
			return (false);
	}

	long num = std::stol(str);
	if (num > INT32_MAX)
		return (false);
	
	return (true);
}

static unsigned long long jacobsthal(int n)
{
	if (n == 0) return (0);
	if (n == 1) return (1);
	return (jacobsthal(n - 1) + (2 * jacobsthal(n - 2)));
}
