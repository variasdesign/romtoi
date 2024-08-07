#include <unistd.h>

const char roman_chars[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
const int roman_values[] = {1, 5, 10, 50, 100, 500, 1000};

int get_roman_index(char a)
{
	int i;

	i = 0;
	while (roman_chars[i] != a && i < 7)
		i++;
	if (i >= 7)
		return (-1);
	return (i);
}

void ft_putchar(char c)
{
	write(1, &c, 1);
}

int ft_strlen(char *str)
{
		int len;

		len = 0;
		while (str[len])
			len++;
		return (len);
}

int check_roman_numeral_base(char c)
{
	if (get_roman_index(c) % 2 != 0)
		return (5);
	else
		return (10);
}

int check_invalid_chars(char *str, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		if (get_roman_index(str[i]) == -1)
			return (0);
		i++;
	}
	return (1);
}

int check_addition(char *str, int i)
{
	int repeated_count;

	repeated_count = 1;
	if (check_roman_numeral_base(str[i]) == 5)
		return (0);
	while (str[i + repeated_count] == str[i])
		repeated_count++;
	if (repeated_count > 3)
		return (0);
	return (repeated_count);
}

int check_substraction(char a, char b)
{
	if (check_roman_numeral_base(a) == 5)
		if (check_roman_numeral_base(b) == 5)
			return (0);
	if (get_roman_index(b) - get_roman_index(a) > 2)
			return (0);
	return (1);
}

int check_rules(char *str, int len)
{
	int i;
	int max_roman;
	int repeated_count;

	max_roman = 7;
	i = 0;
	while(i < len)
	{
		if (get_roman_index(str[i]) < max_roman)
		{
			if (i != len - 1)
			{
				if (get_roman_index(str[i]) < get_roman_index(str[i + 1]))
				{
					if (!check_substraction(str[i], str[i + 1]))
						return (0);
					max_roman = get_roman_index(str[i]);
					i += 2;
					continue;
				}
				if (str[i] == str[i + 1])
				{
					repeated_count = check_addition(str, i);
					if (!repeated_count)
						return (0);
					max_roman = get_roman_index(str[i]);
					i = i + repeated_count;
					continue;
				}
			}
		}
		else
			return (0);
		i++;
	}
	return (1);
}

int validate_roman_chars(char *str, int len)
{
	if(!check_invalid_chars(str, len)
		|| !check_rules(str, len))
			return(0);
	return (1);
}

int process_string(char *str, int len)
{
	int num;
	int i;

	num = 0;
	i = 0;
	while (i < len)
	{
		if (get_roman_index(str[i]) < get_roman_index(str[i + 1]))
		{
			num = num + (roman_values[get_roman_index(str[i + 1])] - roman_values[get_roman_index(str[i])]);
			i += 2;
			continue;
		}
		num = num + roman_values[get_roman_index(str[i])];
		i++;
	}
	return (num);
}

void ft_putnbr(int nbr)
{
	if (nbr == -2147483648)
	{
		write(1, "-2147483648", 11);
	}
	if (nbr < 0)
	{
		nbr = -nbr;
		write(1, "-", 1);
	}
	if (nbr / 10 != 0)
		ft_putnbr(nbr / 10);
	ft_putchar(nbr % 10 + '0');
}

int main(int argc, char **argv)
{
	int len;

	if (argc != 2)
	{
		write(1, "The number of arguments must be one.\n", 37);
		return (1);
	}
	len = ft_strlen(argv[1]);
	if (!validate_roman_chars(argv[1], len))
	{
		write(1, "The argument must contain a valid roman numeral.\n", 50);
		return (1);
	}

	ft_putnbr(process_string(argv[1], len));
	ft_putchar('\n');
	return (0);
}
