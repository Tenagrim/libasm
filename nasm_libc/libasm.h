#ifndef LIBASM_H
# define LIBASM_H
# include <unistd.h>

size_t				ft_strlen(const char *str);
char				*ft_strcpy(char *dest, const char *src);
int					ft_strcmp(const char *string1, const char *string2);
char				*ft_strdup(const char *str);
ssize_t				ft_write(int fildes, const void *buf, size_t nbytes);
ssize_t				ft_read(int fildes, void *buf, size_t nbytes);
#endif
