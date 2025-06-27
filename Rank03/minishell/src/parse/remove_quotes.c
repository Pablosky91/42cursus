#include "minishell.h"

static bool	remove_token(t_token *token);
static bool	change_token_value(t_token *token, int new_len);
static void	get_new_token_value(t_token *token, char **new_value);

bool	remove_quotes(t_smash *smash)
{
	t_token	*iter;

	iter = smash->first_token;
	while (iter)
	{
		if (iter->type == LITERAL && !remove_token(iter))
		{
			smash->error_type = INTERNAL;
			return (false);
		}
		iter = iter->next;
	}
	return (true);
}

static bool	remove_token(t_token *token)
{
	int				iter;
	int				remove_count;
	t_token_type	type;
	t_token_type	last_type;

	iter = 0;
	remove_count = 0;
	type = LITERAL;
	last_type = LITERAL;
	while (token->value[iter])
	{
		mutate(&type, token->value[iter]);
		if (type != last_type)
			remove_count++;
		last_type = type;
		iter++;
	}
	if (remove_count)
		return (change_token_value(token, iter - remove_count));
	return (true);
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
	int				token_iter;
	int				value_iter;
	t_token_type	type;
	t_token_type	last_type;

	token_iter = 0;
	value_iter = 0;
	type = LITERAL;
	last_type = LITERAL;
	while (token->value[token_iter])
	{
		mutate(&type, token->value[token_iter]);
		if (type == last_type)
			(*new_value)[value_iter++] = token->value[token_iter];
		last_type = type;
		token_iter++;
	}
	(*new_value)[value_iter] = 0;
}
