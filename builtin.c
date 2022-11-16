#include "shell.h"

/**
 * _myexit - exits the shell
 *
 * @info: structure containing the arguments
 *
 * Return: exists with a given exit status
 */
int _myexit(info_t *info)
{
	int exitcheck;

	if (info->argv[1])
	{
		exitcheck = erratio(info->argv[1]);
		if (exitcheck == -1)
		{
			info->status = 2;
			print_error(info, "Illegal number: ");
			_eputs(info->argv[1]);
			_eputchar('\n');
			return (1);
		}
		info->err_num = _erratoi(info->argv[1]);
		return (-2);
	}
	info->err_num = -1;
	return (-2);
}
/**
 * _mycd - changes the current directory of the process
 * 
 * @info: structure containing potential argument
 *
 * Return: always 0
 */
int _mycd(info_t *info)
{
	char *s; *dir, buffer[1024];
	int chdir_ret;

	s = getcwd(buffer, 1024);
	if (!s)
	{
		_puts{

