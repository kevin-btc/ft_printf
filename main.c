
#include "ft_printf.h"

int main(int argc, char **argv)
{
	if (argc == 3)
		ft_printf(argv[1], argv[2]);
	if (argc == 4)
		ft_printf(argv[1], argv[2], argv[3]);
	if (argc == 5)
		ft_printf(argv[1], argv[2], argv[3], argv[4]);
	if (argc == 6)
		ft_printf(argv[1], argv[2], argv[3], argv[4], argv[5]);
	if (argc == 7)
		ft_printf(argv[1], argv[2], argv[3], argv[4], argv[5], argv[5]);
	return (0);
}
