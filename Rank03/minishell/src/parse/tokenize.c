#include "minishell.h"

static bool	iter_input(t_smash *smash, int *start_token);
static bool	is_start_token(int start_token, char c);
static bool	is_end_token(int start_token, char c, t_token_type type);
static bool	add_token(t_smash *smash, int start, int len, t_token_type type);

bool	tokenize(t_smash *smash)
{
	int	start_token;

	start_token = -1;
	if (!iter_input(smash, &start_token))
	{
		smash->error_type = INTERNAL;
		return (false);
	}
	if (start_token != -1)
	{
		ft_printf_fd(STDERR_FILENO, "smash: unclosed quotes\n");
		smash->error_type = UNCLOSED_QUOTES;
		return (false);
	}
	return (true);
}

static bool	iter_input(t_smash *smash, int *start_token)
{
	int				iter;
	t_token_type	type;

	iter = -1;
	type = -1;
	while (smash->user_input[++iter])
	{
		if (is_start_token(*start_token, smash->user_input[iter]))
		{
			get_token_type(&type, &(smash->user_input[iter]));
			*start_token = iter;
			if (type == HEREDOC || type == APPEND)
				iter++;
		}
		mutate(&type, smash->user_input[iter]);
		if (is_end_token(*start_token, smash->user_input[iter + 1], type))
		{
			if (!add_token(smash, *start_token, iter - *start_token + 1, type))
				return (false);
			*start_token = -1;
		}
	}
	return (true);
}

static bool	is_start_token(int start_token, char c)
{
	return (start_token == -1 && c != ' ' && c != '\t' && c != '\n');
}

static bool	is_end_token(int start_token, char c, t_token_type type)
{
	if (start_token == -1 || type == SINGLE_QUOTE || type == DOUBLE_QUOTE)
		return (false);
	else if (type == LITERAL)
		return (c == ' ' || c == '\t' || c == '\n' || c == '\0'
			|| c == '<' || c == '>' || c == '|');
	return (true);
}

static bool	add_token(t_smash *smash, int start, int len, t_token_type type)
{
	t_token	*token;

	token = ft_calloc(1, sizeof(t_token));
	if (!token)
		return (false);
	if (!smash->first_token)
		smash->first_token = token;
	else
		smash->last_token->next = token;
	smash->last_token = token;
	smash->last_token->type = type;
	if (is_word(type))
	{
		smash->last_token->value = ft_substr(smash->user_input, start, len);
		if (!smash->last_token->value)
			return (false);
	}
	return (true);
}
