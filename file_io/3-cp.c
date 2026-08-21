#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

/**
 * open_source - opens the source file
 * @filename: name of the source file
 *
 * Return: file descriptor on success, -1 on failure
 */
int open_source(char *filename)
{
	int fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't read from file %s\n", filename);
		return (-1);
	}

	return (fd);
}

/**
 * open_destination - opens the destination file
 * @filename: name of the destination file
 *
 * Return: file descriptor on success, -1 on failure
 */
int open_destination(char *filename)
{
	int fd;

	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd == -1)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't write to %s\n", filename);
		return (-1);
	}

	return (fd);
}

/**
 * copy_file - copies the contents of one file to another
 * @fd_from: source file descriptor
 * @fd_to: destination file descriptor
 * @file_from: source filename
 * @file_to: destination filename
 *
 * Return: 0 on success, 98 on read failure, 99 on write failure
 */
int copy_file(int fd_from, int fd_to, char *file_from, char *file_to)
{
	char buffer[1024];
	ssize_t bytes_read;
	ssize_t bytes_written;

	while ((bytes_read = read(fd_from, buffer, 1024)) > 0)
	{
		bytes_written = write(fd_to, buffer, bytes_read);
		if (bytes_written != bytes_read)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", file_to);
			return (99);
		}
	}

	if (bytes_read == -1)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't read from file %s\n", file_from);
		return (98);
	}

	return (0);
}

/**
 * close_files - closes file descriptors
 * @fd_from: source file descriptor
 * @fd_to: destination file descriptor
 *
 * Return: 0 on success, 100 if a file descriptor cannot be closed
 */
int close_files(int fd_from, int fd_to)
{
	if (close(fd_from) == -1)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't close fd %d\n", fd_from);
		if (fd_to != -1)
			close(fd_to);
		return (100);
	}

	if (fd_to != -1 && close(fd_to) == -1)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't close fd %d\n", fd_to);
		return (100);
	}

	return (0);
}

/**
 * main - copies the content of one file to another
 * @ac: argument count
 * @av: argument vector
 *
 * Return: 0 on success, or an error code on failure
 */
int main(int ac, char **av)
{
	int fd_from;
	int fd_to;
	int result;
	int close_result;

	if (ac != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		return (97);
	}

	fd_from = open_source(av[1]);
	if (fd_from == -1)
		return (98);

	fd_to = open_destination(av[2]);
	if (fd_to == -1)
	{
		close_result = close_files(fd_from, -1);
		if (close_result == 100)
			return (100);
		return (99);
	}

	result = copy_file(fd_from, fd_to, av[1], av[2]);
	close_result = close_files(fd_from, fd_to);

	if (close_result == 100)
		return (100);

	return (result);
}
