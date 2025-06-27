#include "minishell.h"

static bool	change_token_value(t_token *token, int new_len);
static void	get_new_token_value(t_token *token, char **new_value);

bool	expand_variables(t_smash *smash)
{
	t_token			*iter;
	t_token_type	last_type;

	iter = smash->first_token;
	last_type = -1;
	while (iter)
	{
		if (iter->type == LITERAL && last_type != HEREDOC
			&& !expand_token(smash, iter, false))
		{
			smash->error_type = INTERNAL;
			return (false);
		}
		last_type = iter->type;
		iter = iter->next;
	}
	return (true);
}

bool	expand_token(t_smash *smash, t_token *token, bool in_heredoc)
{
	int				iter;
	int				new_len;
	t_token_type	type;

	iter = 0;
	type = LITERAL;
	new_len = ft_strlen(token->value);
	while (token->value[iter])
	{
		if (!in_heredoc)
			mutate(&type, token->value[iter]);
		if (token->value[iter] == '$'
			&& !(iter > 0 && token->value[iter - 1] == '$')
			&& (type == LITERAL || type == DOUBLE_QUOTE))
		{
			if (!get_variable(smash, token, iter))
				return (false);
			new_len -= token->last_variable->key_len;
			new_len += token->last_variable->value_len;
		}
		iter++;
	}
	return (change_token_value(token, new_len));
}

static bool	change_token_value(t_token *token, int new_len)
{
	char	*new_value;

	new_value = malloc((new_len + 1) * sizeof(char));
	if (!new_value)
		return (false);
	get_new_token_value(token, &new_value);
	free(token->value);
	token->value = new_value;
	return (true);
}

static void	get_new_token_value(t_token *token, char **new_value)
{
	int		token_iter;
	int		value_iter;
	int		other_iter;
	t_var	*var_iter;

	token_iter = 0;
	value_iter = 0;
	var_iter = token->first_variable;
	while (token->value[token_iter])
	{
		while (var_iter && !var_iter->valid_name)
			var_iter = var_iter->next;
		if (var_iter && token_iter == var_iter->pos)
		{
			other_iter = 0;
			while (other_iter < var_iter->value_len)
				(*new_value)[value_iter++] = var_iter->value[other_iter++];
			token_iter += var_iter->key_len;
			var_iter = var_iter->next;
		}
		else
			(*new_value)[value_iter++] = token->value[token_iter++];
	}
	(*new_value)[value_iter] = 0;
}
