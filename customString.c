#include "customString.h"

char	*_strstr(const char *haystack, const char *needle)
{
	int	primary;
	int	head;
	int	tail;

	primary = 0;
	if (!needle)
		return ((char *)needle);
	while (haystack[primary] != '\0')
	{
		head = 0;
		tail = 0;
		if (haystack[primary] == needle[head])
		{
			tail = primary;
			while ((haystack[tail] != '\0' && needle[head] != '\0')
				&& haystack[tail] == needle[head])
			{
				tail++;
				head++;
			}
			if (needle[head] == '\0')
			{
				return (char *)(haystack + primary);
			}
		}
		primary++;
	}
	return (NULL);
}

char	*_strchr(const char *s, int c)
{
	unsigned char	*ptr;
	char			t;

	if (!c || !s)
		return (NULL);
	ptr = (unsigned char *)s;
	t = (char)c;
	while (*ptr)
	{
		if (*ptr == t)
			return ((char *)ptr);
		ptr++;
	}
	return ((t == '\0') ? (char *)ptr : NULL);
}

int	_strcmp(const char *s1, const char *s2)
{
	const unsigned char	*str;
	const unsigned char	*cs;

	str = (const unsigned char *)s1;
	cs = (const unsigned char *)s2;
	while (*str != '\0' && *cs != '\0')
	{
		if (*str != *cs)
			return (*str - *cs);
		str++;
		cs++;
	}
	return (*str - *cs);
}

void	_bzero(void *s, size_t n)
{
	unsigned char	*p;

	p = (unsigned char *)s;
	while (n > 0)
	{
		n--;
		p[n] = 0;
	}
}

void	*_memset(void *b, int c, size_t len)
{
	unsigned char	*d;
	unsigned char	e;
	size_t			i;

	d = (unsigned char *)b;
	e = (unsigned char)c;
	if (len == 0)
		return (b);
	i = 0;
	while (i < len)
	{
		d[i] = e;
		i++;
	}
	return (void *)(d);
}

// void	*_memchr(const void *s, int c, size_t len)
// {
// 	const unsigned char	*d;
// 	const unsigned char	e;
// 	size_t				i;

// 	d = (const unsigned char *)s;
// 	e = (unsigned char)c;
// 	i = 0;
// 	if (len == 0)
// 		return (void *)(s);
// 	while (i < len)
// 	{
// 		if (d[i] == e)
// 			return (void *)(d + i);
// 		i++;
// 	}
// 	return (void *)(s);
// }

// void *_memcpy(void *restrict dst, const void *restrict src, size_t n) {

// }

size_t	_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*_substr(char const *s, unsigned int start, size_t len)
{
	size_t	length;
	char	*ptr;
	size_t	i;

	length = _strlen(s);
	if (start >= length || length == 0)
		return (NULL);
	ptr = (char *)malloc((len + 1) * sizeof(char));
	i = 0;
	while (s[start])
	{
		if (i == len)
			break ;
		ptr[i] = s[start];
		start++;
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*_strdup(const char *s1)
{
	size_t	len;
	char	*str;
	int		i;

	len = _strlen(s1);
	if (!s1)
		return (NULL);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return ((char *)str);
}

int	_atoi(const char *str)
{
	int	i;
	int	neg;
	int	nbr;

	i = 0;
	neg = 0;
	nbr = 0;
	while (str[i] != '\0' && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
			|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r'))
	{
		i++;
	}
	if (str[i] != '\0' && (str[i] == '-' || str[i] == '+'))
	{
		if (str[i] == '-')
			neg = 1;
		i++;
	}
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			nbr = (nbr * 10) + (str[i] - '0');
		else
			break ;
		i++;
	}
	return (neg ? (-nbr) : nbr);
}

char	*_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	char	*ptr;
	int		i;
	int		j;

	len1 = _strlen(s1);
	len2 = _strlen(s2);
	ptr = (char *)malloc((len1 + len2 + 1) * sizeof(char));
	i = 0;
	if (s1)
	{
		while (s1[i] != '\0')
		{
			ptr[i] = s1[i];
			i++;
		}
	}
	j = 0;
	if (s2)
	{
		while (s2[j] != '\0')
		{
			ptr[i] = s2[j];
			i++;
			j++;
		}
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*_strtrim(char const *s1, char const *set)
{
	size_t	len;
	int		i;
	int		trimmedLen;
	char	*ptr;
	int		outer;
	int		primary;
	int		inner;

	if (!s1)
		return (NULL);
	len = _strlen(s1) - 1;
	i = 0;
	while (s1[i] != '\0' && _strchr(set, s1[i]))
	{
		i++;
	}
	while (s1[len] != '\0' && _strchr(set, s1[len]))
	{
		len--;
	}
	trimmedLen = len - i + 1;
	ptr = (char *)malloc(sizeof(char) * (trimmedLen));
	if (!ptr)
		return (NULL);
	outer = 0;
	primary = 0;
	while (s1[outer] != '\0')
	{
		inner = 0;
		while (set[inner] != '\0')
		{
			if (set[inner] == s1[outer])
				break ;
			inner++;
		}
		if (set[inner] != s1[outer])
		{
			ptr[primary] = s1[outer];
			primary++;
		}
		outer++;
	}
	ptr[primary] = '\0';
	return (ptr);
}

int	wordCounter(const char *s, char c)
{
	size_t	numDelim;
	size_t	lead;
	size_t	tail;

	numDelim = 0;
	lead = 0;
	tail = 0;
	while (s[lead] != '\0')
	{
		while (s[lead] != '\0' && s[lead] == c)
			lead++;
		tail = lead;
		while (s[lead] != '\0' && s[lead] != c)
			lead++;
		if (lead != tail)
			numDelim++;
	}
	return (numDelim);
}

char	**_split(char const *s, char c)
{
	size_t	wordCount;
	char	**ptr;
	size_t	head;
	size_t	tail;
	size_t	outer;

	if (!s || !c)
		return (NULL);
	wordCount = wordCounter(s, c);
	ptr = (char **)malloc(sizeof(char *) * wordCount);
	if (!ptr)
		return (NULL);
	head = 0;
	tail = 0;
	outer = 0;
	while (s[head] != '\0')
	{
		while (s[head] != '\0' && s[head] == c)
			head++;
		tail = head;
		while (s[head] != '\0' && s[head] != c)
			head++;
		if (tail != head)
		{
			ptr[outer] = _substr(s, tail, head - tail);
			outer++;
		}
	}
	return (ptr);
}

void	neg_zero_num(char *ptr, int n)
{
	if (n < 0)
		ptr[0] = '-';
	if (n == 0)
		ptr[0] = '0';
}
int	counter(int n)
{
	int	num_length;

	num_length = 0;
	while (n)
	{
		n /= 10;
		num_length++;
	}
	if (n <= 0)
		num_length++;
	return (num_length);
}
char	converter(int n)
{
	if (n < 0)
		n *= -1;

	return n % 10 + '0';
}

char	*_itoa(int n)
{
	int		num_length;
	char	*ptr;

	num_length = counter(n);
	ptr = (char *)malloc(sizeof(char) * num_length);
	ptr[num_length] = '\0';
	if (n <= 0)
		neg_zero_num(ptr, n);
	while (n)
	{
		num_length--;
		if (num_length >= 0)
			ptr[num_length] = converter(n);
		n = n / 10;
	}
	printf("%s\n", ptr);
	return (ptr);
}
