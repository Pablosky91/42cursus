#include "minishell.h"

void	parse_line(t_smash *smash)
{
	clear_input(smash);
	smash->error_type = OK;
	smash->user_input = prompt(smash, false);
	if (!smash->user_input)
		smash->error_type = CTRL_D;
	else
	{
		add_history_entry(smash);
		if (!tokenize(smash))
			return ;
		if (!expand_variables(smash))
			return ;
		if (!syntax(smash))
			return ;
		if (!remove_empty_tokens(smash))
			return ;
		if (!remove_quotes(smash))
			return ;
		if (!parse_pipeline(smash))
			return ;
	}
}
