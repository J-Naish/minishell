#include "../../include/executor.h"

static t_pipeline	*init_pipeline(void)
{
	t_pipeline	*pipeline;

	pipeline = (t_pipeline *)malloc(sizeof(t_pipeline));
	if (!pipeline)
		return (NULL);
	pipeline->commands = (t_command **)malloc(sizeof(t_command *));
	if (!pipeline->commands)
		return (free(pipeline), NULL);
	pipeline->commands[0] = NULL;
	pipeline->operator = CHAIN_UNDEFINED;
	return (pipeline);
}

static t_pipeline	**init_pipeline_arr(void)
{
	t_pipeline	**pipeline_arr;

	pipeline_arr = (t_pipeline **)malloc(sizeof(t_pipeline *) * 2);
	if (!pipeline_arr)
		return (NULL);
	pipeline_arr[0] = init_pipeline();
	if (!pipeline_arr[0])
		return (free(pipeline_arr), NULL);
	pipeline_arr[1] = NULL;
	return (pipeline_arr);
}

static t_pipeline	**append_pipeline(t_pipeline **pl_arr, t_pipeline *pl)
{
	int			i;
	t_pipeline	**new;

	i = 0;
	while (pl_arr[i])
		i++;
	new = (t_pipeline **)malloc(sizeof(t_pipeline *) * (i + 2));
	if (!new)
		return (NULL);
	i = 0;
	while (pl_arr[i])
	{
		new[i] = pl_arr[i];
		i++;
	}
	new[i] = pl;
	new[i + 1] = NULL;
	free(pl_arr);
	return (new);
}

t_pipeline	**build_pipeline(t_token **tokens)
{
	int			i;
	int			pl_idx;
	int			start;
	t_pipeline	**pipelines;

	i = 0;
	pl_idx = 0;
	start = 0;
	pipelines = init_pipeline_arr();
	while (tokens[i])
	{
		if (is_pipe(tokens[i]))
		{
			if (i == 0)
				return (NULL);
			pipelines[pl_idx]->commands = append_command(pipelines[pl_idx]->commands, create_command(tokens, start, i));
			start = i + 1;
		}
		if (is_chain(tokens[i]))
		{
			if (i == 0)
				return (NULL);
			if (is_same_str(tokens[i]->value, "||"))
				pipelines[pl_idx]->operator = CHAIN_OR;
			else if (is_same_str(tokens[i]->value, "&&"))
				pipelines[pl_idx]->operator = CHAIN_AND;
			pipelines[pl_idx]->commands = append_command(pipelines[pl_idx]->commands, create_command(tokens, start, i));
			pipelines = append_pipeline(pipelines, init_pipeline());
			pl_idx++;
			start = i + 1;
		}
		i++;
	}
	pipelines[pl_idx]->commands = append_command(pipelines[pl_idx]->commands,
			create_command(tokens, start, i));
	return (pipelines);
}

// int main() {
// 	t_token **tokens;
// 	t_pipeline **pipelines;
// 	// test 1
// 	tokens = tokenize("echo hello world");
// 	pipelines = build_pipeline(tokens);
// 	print_pipelines(pipelines);
// 	free_tokens(tokens);
// 	free_pipelines(pipelines);
// 	// test 2
// 	tokens = tokenize("ls -la | grep .txt");
//     pipelines = build_pipeline(tokens);
//     print_pipelines(pipelines);
//     free_tokens(tokens);
//     free_pipelines(pipelines);
// 	// test 3
// 	tokens = tokenize("mkdir test && cd test");
//     pipelines = build_pipeline(tokens);
//     print_pipelines(pipelines);
//     free_tokens(tokens);
//     free_pipelines(pipelines);
// 	// test 4
// 	tokens = tokenize("cat nonexistent.txt || echo 'File not found'");
//     pipelines = build_pipeline(tokens);
//     print_pipelines(pipelines);
//     free_tokens(tokens);
//     free_pipelines(pipelines);
// 	// test 5
// 	tokens = tokenize("cat /etc/passwd | grep root | wc -l");
//     pipelines = build_pipeline(tokens);
//     print_pipelines(pipelines);
//     free_tokens(tokens);
//     free_pipelines(pipelines);
// 	// test 6
// 	tokens = tokenize("cat < input.txt | sort | uniq > output.txt");
//     pipelines = build_pipeline(tokens);
//     print_pipelines(pipelines);
//     free_tokens(tokens);
//     free_pipelines(pipelines);
// 	// test 7
// 	tokens = tokenize("ls -la && echo 'success' || echo 'failure'");
//     pipelines = build_pipeline(tokens);
//     print_pipelines(pipelines);
//     free_tokens(tokens);
//     free_pipelines(pipelines);
// 	// test 8
// 	tokens = tokenize("cat << EOF | grep hello");
//     pipelines = build_pipeline(tokens);
//     print_pipelines(pipelines);
//     free_tokens(tokens);
//     free_pipelines(pipelines);
// }