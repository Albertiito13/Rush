#include "ft.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int	main(int ac, char **av)
{
	t_list	*tab;
	int		*first;
	int		addr_first;

	addr_first = 1;
	first = &addr_first;
	if (ac == 2)
	{
		if (ft_atoi(av[1]) < 0)
		{
			write(1, "Error\n", 6);
			return (0);
		}
		tab = process("dict.txt");
		ft_print(ft_atoi(av[1]), tab, first);
		free_dictionary(tab);
	}
	return (0);
}
