#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 4
#endif

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

int     ft_notnewline(char *s);
int     ft_linelen(char *s);
int     ft_strlen(char *s);
char    *ft_strndup(char *save, int len);
char    *save_rest(char *save, int len);
char    *get_next_line(int fd);
char    *read_data(int fd, char *save);
char    *unite_data(char *save, char *s2, int i, int j);

#endif