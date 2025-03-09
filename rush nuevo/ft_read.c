#include "ft.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

/* skip_sep: Salta espacios, ':' y espacios siguientes */
static void	skip_sep(int fd, char *c)
{
	while (c[0] == ' ')
	{
		if (read(fd, c, 1) <= 0)
			return ;
	}
	if (c[0] == ':')
	{
		if (read(fd, c, 1) <= 0)
			return ;
	}
	while (c[0] == ' ')
	{
		if (read(fd, c, 1) <= 0)
			return ;
	}
}

/* ft_getnb: Lee un número (como string) del descriptor fd */
char	*ft_getnb(int fd)
{
	int		i;
	char	c[1];
	char	*str;

	str = malloc(sizeof(char) * 128);
	if (!str)
		exit(1);
	i = 0;
	if (read(fd, c, 1) <= 0)
		exit(1);
	while (c[0] == '\n')
	{
		if (read(fd, c, 1) <= 0)
			exit(1);
	}
	while (c[0] >= '0' && c[0] <= '9')
	{
		str[i++] = c[0];
		if (read(fd, c, 1) <= 0)
			break ;
	}
	str[i] = '\0';
	return (str);
}

/* ft_getval: Lee el texto hasta el salto de línea */
char	*ft_getval(int fd, char *c)
{
	int		i;
	char	*str;

	str = malloc(sizeof(char) * 128);
	if (!str)
		exit(1);
	i = 0;
	while (c[0] != '\n')
	{
		str[i++] = c[0];
		if (read(fd, c, 1) <= 0)
			break ;
	}
	str[i] = '\0';
	return (str);
}

/* process_line: Lee una línea del diccionario y la almacena en elem */
/* process_line: Lee una línea del diccionario y almacena el par en elem */
/* process_line: Lee una línea del diccionario y almacena el par en elem */
static void	process_line(int fd, t_list *elem)
{
	char	c[1];
	char	*tmp_nb;
	char	*tmp_val;

	tmp_nb = ft_getnb(fd);
	elem->nb = ft_atoi(tmp_nb);
	free(tmp_nb);
	if (read(fd, c, 1) <= 0)
		return ;
	skip_sep(fd, c);
	tmp_val = ft_getval(fd, c);
	elem->val = ft_strdup(tmp_val);
	free(tmp_val);
}



/* process: Abre el archivo y procesa 32 líneas, almacenándolas en un array de t_list */
t_list	*process(char *file)
{
	int		fd;
	int		i;
	t_list	*tab;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		exit(1);
	tab = malloc(sizeof(t_list) * 33);
	if (!tab)
	{
		close(fd);
		exit(1);
	}
	i = 0;
	while (i < 32)
	{
		process_line(fd, &tab[i]);
		i++;
	}
	close(fd);
	return (tab);
}
