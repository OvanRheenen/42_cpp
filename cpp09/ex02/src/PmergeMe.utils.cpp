#include <string>
#include <algorithm>

bool isPositiveInteger(std::string &str)
{
	if (str.empty())
		return (false);
	
	if (!std::all_of(str.begin(), str.end(), [] (unsigned char c) { return (std::isdigit(c)); }))
		return (false);

	long num = std::stol(str);
	if (num > INT32_MAX)
		return (false);
	
	return (true);
}

unsigned long long jacobsthal(int n)
{
	if (n == 0) return (0);
	if (n == 1) return (1);
	return (jacobsthal(n - 1) + (2 * jacobsthal(n - 2)));
}
