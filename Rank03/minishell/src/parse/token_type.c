#include "minishell.h"

void	get_token_type(t_token_type *type, char *c)
{
	*type = LITERAL;
	if (*c == '<' && *(c + 1) && *(c + 1) == '<')
		*type = HEREDOC;
	else if (*c == '<')
		*type = INPUT;
	else if (*c == '>' && *(c + 1) && *(c + 1) == '>')
		*type = APPEND;
	else if (*c == '>')
		*type = OUTPUT;
	else if (*c == '|')
		*type = PIPE;
}

void	mutate(t_token_type *type, char c)
{
	if (*type == LITERAL && c == '\'')
		*type = SINGLE_QUOTE;
	else if (*type == LITERAL && c == '"')
		*type = DOUBLE_QUOTE;
	else if (*type == SINGLE_QUOTE && c == '\'')
		*type = LITERAL;
	else if (*type == DOUBLE_QUOTE && c == '"')
		*type = LITERAL;
}

bool	is_redirection(t_token_type type)
{
	return (type == INPUT || type == HEREDOC
		|| type == OUTPUT || type == APPEND);
}

bool	is_word(t_token_type type)
{
	return (type == LITERAL || type == SINGLE_QUOTE || type == DOUBLE_QUOTE);
}

char	*get_token_name(t_token_type type)
{
	if (type == INPUT)
		return ("<");
	if (type == OUTPUT)
		return (">");
	if (type == HEREDOC)
		return ("<<");
	if (type == APPEND)
		return (">>");
	return (NULL);
}
