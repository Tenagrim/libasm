/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshona <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 21:45:20 by gshona            #+#    #+#             */
/*   Updated: 2020/12/11 21:56:12 by gshona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

static void	cmp(char *str1, char *str2)
{
	printf("|%s| |%s|\n", str1, str2);
	printf("cmp my: %d\n", ft_strcmp(str1, str2));
	printf("cmp st: %d\n",    strcmp(str1, str2));
	printf("\n");
}

static void	len(char *str1)
{
	printf("len my: %zu\n", ft_strlen(str1));
	printf("len st: %zu\n",    strlen(str1));
	printf("\n");
}

static void	dup_t(char *str1)
{
	char	*line;
	line = ft_strdup(str1);
	printf("dupped line:\n|%s|\n", line);
	printf("\n");
	free(line);
}

static void	copy_t(char *str1)
{
	char	*line;
	line = malloc(2000);

	line = ft_strcpy(line, str1);
	printf("copied line:\n|%s|\n", line);
	printf("\n");
	free(line);
}

static void read_t(int fd, char *buf, size_t count)
{
	int ret = 0;
	errno = 0;
	buf[0] = 0;
	printf("fd: %d  count: %zu\n", fd, count);
	ret = ft_read(fd, buf, count);
	printf("ret: %d\n", ret);
	buf[ret] = 0;
	printf("errno: %d\n", errno);
	printf("%s\n", strerror(errno));
	printf("line: |%s|\n", buf);
	printf("\n");
}

static void write_t(int fd, char *buf, size_t count)
{
	int ret = 0;
	errno = 0;
	printf("fd: %d  count: %zu\n", fd, count);
	ret = write(fd, buf, count);
	printf("\nret: %d\n", ret);
	printf("errno: %d\n", errno);
	printf("%s\n", strerror(errno));
	printf("\n");
}

static void piped_out(int fd, char *line, int n)
{
	int tmp;
	tmp = read(fd, line, n);
	line[tmp] = 0;
	printf("%s\n\n", line);
}

int		main (void)
{
	char str[20];
	char *long_str = "Sed ut perspiciatis, unde omnis iste natus error sit voluptatem accusantium doloremque laudantium, totam rem aperiam eaque ipsa, quae ab illo inventore veritatis et quasi architecto beatae vitae dicta sunt, explicabo. Nemo enim ipsam voluptatem, quia voluptas sit, aspernatur aut odit aut fugit, sed quia consequuntur magni dolores eos, qui ratione voluptatem sequi nesciunt, neque porro quisquam est, qui dolorem ipsum, quia dolor sit, amet, consectetur, adipisci velit, sed quia non numquam eius modi tempora incidunt, ut labore et dolore magnam aliquam quaerat voluptatem. Ut enim ad minima veniam, quis nostrum exercitationem ullam corporis suscipit laboriosam, nisi ut aliquid ex ea commodi consequatur? Quis autem vel eum iure reprehenderit, qui in ea voluptate velit esse, quam nihil molestiae consequatur, vel illum, qui dolorem eum fugiat, quo voluptas nulla pariatur? At vero eos et accusamus et iusto odio dignissimos ducimus, qui blanditiis praesentium voluptatum deleniti atque corrupti, quos dolores et quas molestias excepturi sint, obcaecati cupiditate non provident, similique sunt in culpa, qui officia deserunt mollitia animi, id est laborum et dolorum fuga. Et harum quidem rerum facilis est et expedita distinctio. Nam libero tempore, cum soluta nobis est eligendi optio, cumque nihil impedit, quo minus id, quod maxime placeat, facere possimus, omnis voluptas assumenda est, omnis dolor repellendus. Temporibus autem quibusdam et aut officiis debitis aut rerum necessitatibus saepe eveniet, ut et voluptates repudiandae sint et molestiae non recusandae. Itaque earum rerum hic tenetur a sapiente delectus, ut aut reiciendis voluptatibus maiores alias consequatur aut perferendis doloribus asperiores repellat.";
	char *empty_str = "";
	char *short_str = "123";

	printf("*************STRLEN***************\n");
	printf("long:\n");
	len(long_str);
	printf("short:\n");
	len(short_str);
	printf("empty:\n");
	len(empty_str);

	printf("*************STRDUP***************\n");
	printf("long:\n");
	dup_t(long_str);
	printf("short:\n");
	dup_t(short_str);
	printf("empty:\n");
	dup_t(empty_str);

	printf("*************STRCPY***************\n");
	printf("long:\n");
	copy_t(long_str);
	printf("short:\n");
	copy_t(short_str);
	printf("empty:\n");
	copy_t(empty_str);

	printf("*************STRCMP***************\n");
	cmp("","");
	cmp(" "," ");
	cmp("abc","bca");
	cmp("abc","aca");
	cmp("bbc","aca");
	cmp("000","100");
	cmp("000","0000");
	cmp("","000");
	cmp("000","");

	cmp("\xff\x00","\xff\x00");
	cmp("\xff\x01","\xff\x00");
	cmp("\xff\x00","\xff\x01");

	cmp(long_str, long_str);

	cmp("fusro","fus");
	cmp("fus","fusro");



	printf("**************WRITE****************\n");
	system("rm out;  touch out");
	int fd;
	int p[2];
	char line[100];
	int n;
	if (pipe(p) < 0)
		exit(EXIT_FAILURE);
	printf("Uninitialized fd:\n");
	write_t(fd, long_str, 10);
	printf("NULL line:\n");
	write_t(fd, NULL, 5);

	printf("Piped line write:\n");
	write_t(p[1], long_str, 10);
	printf("Piped line read:\n");
	read_t(p[0], line, 10);

   	fd = open("out", O_RDWR);
	write_t(-1, long_str, 10);
	write_t(100, long_str, 10);
	write_t(fd, long_str, 100);
	write_t(1, short_str, ft_strlen(short_str));
	close(fd);
	system("cat out");
	ft_write(1, "\n\n", 2);

	printf("PIPES: *********\n\n");
	write_t(p[1], NULL, 5);
	write_t(p[1], "test", 0);
	write_t(p[1], "test", 5);
	piped_out(p[0], line, 5);
	write_t(p[1], "t", (n = 1));
	piped_out(p[0], line, n);
	write_t(p[1], "", (n = 0));
	piped_out(p[0], line, n);
	write_t(p[1], "test", (n = 4));
	piped_out(p[0], line, n);
	write_t(p[1], "test", (n = 2));
	piped_out(p[0], line, n);
	write_t(p[1], NULL, (n = 2));
	//piped_out(p[0], line, n);
	(void)(close(p[0]) + close(p[1]));



/*
	printf("**************READ****************\n");

	char *line = malloc(2000);
	fd = open("testfile", O_RDONLY);
	read_t(-1, line, 10);
	read_t(100, line, 10);
	read_t(fd, line, 100);
	close(fd);
	system("cat testfile");
	printf("\n");
	//read_t(1, line, 10);
	free(line);
*/
}
