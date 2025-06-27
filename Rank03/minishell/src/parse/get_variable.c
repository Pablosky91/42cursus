#include "minishell.h"

static bool		get_var_exit_status(t_smash *smash, t_token *token);
static bool		get_var_regular_variable(t_smash *smash,
					t_token *token, int pos);
static size_t	len(char *value, int pos);

bool	get_variable(t_smash *smash, t_token *token, int pos)
{
	t_var	*var;

	var = malloc(sizeof(t_var));
	if (!var)
		return (false);
	if (!token->first_variable)
		token->first_variable = var;
	else
		token->last_variable->next = var;
	token->last_variable = var;
	token->last_variable->next = NULL;
	token->last_variable->valid_name = false;
	token->last_variable->pos = pos;
	token->last_variable->value = NULL;
	token->last_variable->key_len = 0;
	token->last_variable->value_len = 0;
	if (token->value[pos + 1] == '?')
		return (get_var_exit_status(smash, token));
	return (get_var_regular_variable(smash, token, pos));
}

static bool	get_var_exit_status(t_smash *smash, t_token *token)
{
	token->last_variable->valid_name = true;
	token->last_variable->value = ft_itoa(smash->exit_status);
	if (!token->last_variable->value)
		return (false);
	token->last_variable->key_len = 2;
	token->last_variable->value_len
		= ft_strlen(token->last_variable->value);
	return (true);
}

static bool	get_var_regular_variable(t_smash *smash, t_token *token, int pos)
{
	char	*key;
	char	*value;
	size_t	key_len;

	key_len = len(token->value, pos + 1);
	if (key_len == 0)
		return (true);
	token->last_variable->valid_name = true;
	token->last_variable->key_len = key_len + 1;
	key = ft_substr(token->value, pos + 1, key_len);
	if (!key)
		return (false);
	value = get_value(smash->envp, key);
	free(key);
	if (!value)
		return (true);
	token->last_variable->value = ft_strdup(value);
	if (!token->last_variable->value)
		return (false);
	token->last_variable->value_len
		= ft_strlen(token->last_variable->value);
	return (true);
}

static size_t	len(char *value, int pos)
{
	size_t	len;

	len = 0;
	if (!(ft_isalpha(value[pos]) || value[pos] == '_'))
		return (len);
	while (ft_isalnum(value[pos]) || value[pos] == '_')
	{
		pos++;
		len++;
	}
	return (len);
}
