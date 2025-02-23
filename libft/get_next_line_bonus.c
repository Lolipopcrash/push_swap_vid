/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelevequ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:50:39 by kelevequ          #+#    #+#             */
/*   Updated: 2024/11/12 15:11:13 by kelevequ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_read_line(char *line)
{
	char	*storage;
	int		i;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == '\0' || line[1] == '\0')
		return (NULL);
	storage = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (!storage)
		return (NULL);
	if (*storage == '\0')
	{
		free(storage);
		storage = NULL;
	}
	line[i + 1] = '\0';
	return (storage);
}

char	*ft_fill_buffer(int fd, char *storage, char *buffer)
{
	char	*temp;
	int		bytes;

	if (!storage)
		storage = ft_strdup("");
	bytes = read(fd, buffer, BUFFER_SIZE);
	while (bytes > 0)
	{
		buffer[bytes] = '\0';
		temp = storage;
		storage = ft_strjoin(temp, buffer);
		free(temp);
		if (ft_strchr(buffer, '\n'))
			bytes = 0;
		else
			bytes = read(fd, buffer, BUFFER_SIZE);
	}
	if (bytes == -1 || (bytes == 0 && *storage == '\0'))
	{
		free(storage);
		return (NULL);
	}
	return (storage);
}

char	*get_next_line(int fd)
{
	static char	*storage[MAX_FD];
	char		*buffer;
	char		*line;

	buffer = (char *) malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer || fd < 0 || BUFFER_SIZE <= 0)
	{
		free(storage[fd]);
		free(buffer);
		storage[fd] = NULL;
		buffer = NULL;
		return (NULL);
	}
	if (!buffer)
		return (NULL);
	line = ft_fill_buffer(fd, storage[fd], buffer);
	free(buffer);
	buffer = NULL;
	if (!line)
		return (NULL);
	storage[fd] = ft_read_line(line);
	return (line);
}
/*
#include <stdio.h>

int main(int argc, char **argv)
{
    int     fd;
    char    *line;

    if (argc != 2) // Ensure a file name is provided
    {
        printf("Usage: %s <file>\n", argv[0]);
        return (1);
    }

    // Open the file
    fd = open(argv[1], O_RDONLY);
    if (fd < 0)
    {
        perror("Error opening file");
        return (1);
    }

    // Read and print lines until EOF
    printf("Reading file: %s\n", argv[1]);
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line); // Print the line
        free(line);         // Free the memory allocated for the line
    }

    // Close the file and end the program
    close(fd);
    return (0);
}*/
