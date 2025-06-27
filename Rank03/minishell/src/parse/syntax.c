#include "minishell.h"

bool	syntax(t_smash *smash)
{
	t_token	*iter;

	smash->error_type = SYNTAX;
	if ((smash->first_token && smash->first_token->type == PIPE)
		|| (smash->last_token && smash->last_token->type == PIPE))
		return (ft_printf_fd(2, "smash: syntax error near '|'\n"), false);
	iter = smash->first_token;
	while (iter)
	{
		if (iter->type == PIPE && (!iter->next || iter->next->type == PIPE))
			return (ft_printf_fd(2, "smash: syntax error near '|'\n"), false);
		if (is_redirection(iter->type))
		{
			if (!iter->next)
				return (ft_printf_fd(2, "smash: syntax error near '\\n'\n"),
					false);
			if (!is_word(iter->next->type))
				return (ft_printf_fd(2, "smash: syntax error near '%s'\n",
						get_token_name(iter->next->type)), false);
		}
		iter = iter->next;
	}
	smash->error_type = OK;
	return (true);
}
