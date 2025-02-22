#ifndef FT_RUSH02_H
# define FT_RUSH02_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# define BUFFER_SIZE 4096
# define MAX_NUM_LEN 1024
# define DEFAULT_DICT "numbers.dict"

/* Main program functions */
void	print_error(void);
void	print_dict_error(void);
int		process_number(char *dict_path, char *number);

/* Dictionary parsing and management */
char	**parse_dictionary(char *dict_path);
void	free_dictionary(char **dict);
char	*find_exact_match(char **dict, char *number);

/* Number validation and conversion */
int		is_valid_number(char *str);
char	*get_written_form(char **dict, char *number);

/* String utility functions */
int		ft_strlen(char *str);
char	*ft_strdup(char *str);
char	*ft_strndup(const char *str, size_t n);
char	*ft_strtrim(char *str);
char	**ft_split(char *str, char delimiter);
int		ft_strcmp(char *str1, char *str2);
char	*ft_itoa(int n);

#endif