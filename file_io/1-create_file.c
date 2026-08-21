#include "main.h"
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

/**
 * create_file - creates a file and writes text to it
 * @filename: name of the file to create
 * @text_content: text to write to the file
 *
 * Return: 1 on success, -1 on failure
 */
int create_file(const char *filename, char *text_content)
{
	int fd;
	int i;
	ssize_t written;

	if (filename == NULL)
		return (-1);

	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);
	if (fd == -1)
		return (-1);

	if (text_content != NULL)
	{
		i = 0;
		while (text_content[i] != '\0')
			i++;

		written = write(fd, text_content, i);
		if (written != (ssize_t)i)
		{
			close(fd);
			return (-1);
		}
	}

	if (close(fd) == -1)
		return (-1);

	return (1);
}
