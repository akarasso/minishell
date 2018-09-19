#ifndef ENV_H
# define ENV_H

typedef struct	s_env
{
	char	**public;
	char	**private;
	char	**local;
}				t_env;

typedef struct s_varsexp t_varsexp;

typedef struct	s_varsexp_rules
{
	char		*op;
	char		*(*set)(t_varsexp *exp, char *key, char *val, char *word);
	char		*(*null)(t_varsexp *exp, char *key, char *val, char *word);
	char		*(*unset)(t_varsexp *exp, char *key, char *val, char *word);
}				t_varsexp_rules;

struct	s_varsexp
{
	t_env			*env;
	char			*str;
	char			*res;
	t_varsexp_rules	*rule;
	char			format;
};

t_env	*sh_env_init(char **env);
void	sh_env_destroy(t_env *env);
char	**sh_env_get_ref(char **tab, char *key);
char	*sh_env_get(char **tab, char *key);
char	*env_get_first(t_env *env, char *key);
int		sh_env_del(char **tab, char *key);
int		sh_env_set(char	***tab, char *key, char *value, char flag);
int		sh_env_validkey(char *s);
int		sh_env_set_protected(t_env *env, char *key, char *value);

char	*sh_expansion_var(char *str, t_env *env);
char	*sh_exp_sub_param(t_varsexp *exp, char *key, char *val, char *word);
char	*sh_exp_sub_word(t_varsexp *exp, char *key, char *val, char *word);
char	*sh_exp_sub_null(t_varsexp *exp, char *key, char *val, char *word);
char	*sh_exp_sub_error(t_varsexp *exp, char *key, char *val, char *word);
char	*sh_exp_assign(t_varsexp *exp, char *key, char *val, char *word);
char	*sh_exp_unhandle(t_varsexp *exp, char *key, char *val, char *word);

#endif
