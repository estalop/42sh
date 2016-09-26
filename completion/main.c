#include "autocompletion.h"

int main(void)
{
	t_env	*env;

	env = (t_env*)malloc(sizeof(t_env));
	env->next = NULL;
	env->name = "PATH";
	env->value = "test:test2";
	create_tree(env);
	return (0);
}
