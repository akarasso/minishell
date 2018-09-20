#ifndef ENV_H
# define ENV_H

typedef struct	s_env
{
	char	**public;
	char	**private;
	char	**local;
}				t_env;

t_env	*sh_env_init(char **env);
void	sh_env_destroy(t_env *env);
char	**sh_env_get_ref(char **tab, char *key);
char	*sh_env_get(char **tab, char *key);
char	*env_get_first(t_env *env, char *key);
int		sh_env_del(char **tab, char *key);
int		sh_env_set(char	***tab, char *key, char *value, char flag);
int		sh_env_validkey(char *s);
int		sh_env_set_protected(t_env *env, char *key, char *value);

#endif
