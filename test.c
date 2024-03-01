#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

bool ft_valid_argv(char *argv)
{
    int i = 0;
    if (argv[i] == '-' || argv[i] == '+')
        i++;
    if (!ft_isdigit(argv[i]))
        return false;
    while (ft_isdigit(argv[i]) && argv[i] != '\0')
        i++;
    if (argv[i] == '.')
        i++;
    while (ft_isdigit(argv[i]) && argv[i] != '\0')
        i++;
    if (!ft_isdigit(argv[i]) && argv[i] != '\0')
        return false;
    if (!ft_isdigit(argv[i - 1]) && argv[i] == '\0')
        return false;
    return true;
}


int    main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("Invalid argusfdsdfgsdgdments\n");
        return (0);
    }
    if (!ft_valid_argv(argv[1]))
    {
        printf("Invalid arguments\n");
        return (0);
    }
    return (0);
}