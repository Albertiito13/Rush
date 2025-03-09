#ifndef FT_H
# define FT_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int		nb;
	char	*val;
}	t_list;

/* Utilidades */
int		ft_atoi(const char *str);
char	*ft_strdup(char *src);
void	ft_putstr(char *str);

/* Funciones de lectura */
char	*ft_getnb(int fd);
char	*ft_getval(int fd, char *c);
t_list	*process(char *file);

/* Funciones de impresión */
int		getdec(int nb);
int		getmult(int nb);
void	ft_print(int n, t_list *tab, int *first);

#endif
