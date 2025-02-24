/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rush02.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkhoder <ahkhoder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 01:33:13 by ahkhoder          #+#    #+#             */
/*   Updated: 2025/02/24 04:05:45 by ahkhoder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
char	*find_exact_match(char **dict, char *number);
void	parse_and_add_entry(char ***dict, int *line_count, char *buffer);
void	free_dictionary(char **dict);
int		parse_line(char *line, char **number, char **word);
int		count_dict_entries(char **dict);

/* Number validation and conversion */
int		is_valid_number(char *str);
char	*get_written_form(char **dict, char *number);
char	*handle_tens(char **dict, char *num, char *result);
char	*handle_hundreds(char **dict, char *num, char *result);
char	*handle_below_20(char **dict, char *num, char *result);
void	handle_remaining_digits(char **dict, char *num, char *result);
void	append_hundred(char **dict, char *result);
char	*get_power_word(char **dict, int power);
void	write_word(char *result, char *word, int need_space);

/* String utility functions */
int		ft_strlen(char *str);
char	*ft_strdup(char *str);
char	*ft_strndup(const char *str, size_t n);
char	*ft_strtrim(char *str);
int		ft_strcmp(char *str1, char *str2);
void	ft_strlcpy(char *dst, const char *src, size_t size);

/*get written form*/
void	convert_group(char **dict, char *group, char *result, int power);
void	extract_group(char *number, int start, int size, char *group);
void	get_group_info(int len, int i, int *start, int *size);
void	process_groups(char **dict, char *number, char *result, int groups);
char	*get_written_form(char **dict, char *number);

#endif
