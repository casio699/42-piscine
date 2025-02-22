#include "ft_rush02.h"

void    print_error(void)
{
    write(2, "Error\n", 6);
}

void    print_dict_error(void)
{
    write(2, "Dict Error\n", 11);
}

int process_number(char *dict_path, char *number)
{
    char **dict;
    char *result;

    if (!is_valid_number(number))
    {
        print_error();
        return (0);
    }
    dict = parse_dictionary(dict_path);
    if (!dict)
    {
        print_dict_error();
        return (0);
    }
    result = get_written_form(dict, number);
    if (!result)
    {
        free_dictionary(dict);
        print_dict_error();
        return (0);
    }
    write(1, result, ft_strlen(result));
    write(1, "\n", 1);
    free(result);
    free_dictionary(dict);
    return (1);
}

int    main(int argc, char **argv)
{
    if (argc != 2 && argc != 3)
    {
        print_error();
        return (1);
    }
    if (argc == 2)
        return (!process_number(DEFAULT_DICT, argv[1]));
    return (!process_number(argv[1], argv[2]));
}
