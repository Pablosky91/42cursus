#include "minishell.h"

bool	remove_empty_tokens(t_smash *smash)
{
	t_token	*iter;
	t_token	*previous;
	t_token	*next;

	iter = smash->first_token;
	smash->error_type = EMPTY_PROMPT;
	while (iter)
	{
		next = iter->next;
		if (is_word(iter->type) && !iter->value[0])
		{
			if (iter == smash->first_token)
				smash->first_token = next;
			else
				previous->next = iter->next;
			free_token(iter);
		}
		else
		{
			smash->error_type = OK;
			previous = iter;
		}
		iter = next;
	}
	return (smash->error_type != EMPTY_PROMPT);
}
