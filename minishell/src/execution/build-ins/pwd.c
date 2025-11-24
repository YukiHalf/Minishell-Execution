#include "execution.h"

int	b_pwd(void)
{
	char	*buf;

	buf = getcwd(NULL, 0);
	if (buf == NULL)
		return (perror("pwd"), 1);
	printf("%s\n", buf);
	free(buf);
	return (0);
}
