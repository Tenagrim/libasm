#include <libasm.h>

int		main (void)
{
	printf("len: %zu\n", ft_strlen("hell"));
	printf("cmp my: %d\n", ft_strcmp("hell", "hello"));
	printf("cmp st: %d\n",    strcmp("hell", "hello"));
	printf("cmp my: %d\n", ft_strcmp("hell", "hell"));
	printf("cmp st: %d\n",    strcmp("hell", "hell"));
	printf("cmp my: %d\n", ft_strcmp("hello", "hell"));
	printf("cmp st: %d\n",    strcmp("hello", "hell"));
	printf("cmp my: %d\n",    ft_strcmp("b", "a"));
	printf("cmp st: %d\n",    strcmp("b", "a"));
	printf("\n");

	char str[20];
	ft_strcpy(str, "hello");
	printf("str: |%s|\n", str);
}
