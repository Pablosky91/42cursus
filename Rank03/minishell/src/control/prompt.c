#include "minishell.h"

static char	get_char(char *c);

char	*prompt(t_smash *smash, bool in_heredoc)
{
	char	*prompt;

	if (in_heredoc)
	{
		prompt = get_value(smash->envp, "PS2");
		if (!prompt)
			prompt = HEREDOC_PROMPT;
	}
	else
	{
		prompt = get_value(smash->envp, "PS1");
		if (!prompt)
			prompt = PROMPT;
	}
	if (smash->debug_mode)
	{
		ft_printf("%s", prompt);
		return (ft_get_next_line_no_nl(STDIN_FILENO));
	}
	return (readline(prompt));
}

char	*parse_octals_prompt(char *prompt)
{
	char	*new;
	int		prompt_iter;
	int		new_iter;

	prompt_iter = -1;
	new_iter = 0;
	while (prompt[++prompt_iter])
	{
		new_iter++;
		if (prompt[prompt_iter] != get_char(&(prompt[prompt_iter])))
			prompt_iter += 3;
	}
	new = ft_calloc(new_iter + 1, sizeof(char));
	prompt_iter = -1;
	new_iter = 0;
	while (prompt[++prompt_iter])
	{
		new[new_iter++] = get_char(&prompt[prompt_iter]);
		if (prompt[prompt_iter] != get_char(&(prompt[prompt_iter])))
			prompt_iter += 3;
	}
	return (new);
}

static char	get_char(char *c)
{
	if (*c && *c == '\\'
		&& *(c + 1) && *(c + 1) == '0'
		&& *(c + 2) && *(c + 2) == '0'
		&& *(c + 3) && *(c + 3) == '1')
		return ('\001');
	if (*c && *c == '\\'
		&& *(c + 1) && *(c + 1) == '0'
		&& *(c + 2) && *(c + 2) == '0'
		&& *(c + 3) && *(c + 3) == '2')
		return ('\002');
	if (*c && *c == '\\'
		&& *(c + 1) && *(c + 1) == '0'
		&& *(c + 2) && *(c + 2) == '3'
		&& *(c + 3) && *(c + 3) == '3')
		return ('\033');
	return (*c);
}
