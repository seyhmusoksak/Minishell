/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekose <ekose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 16:53:36 by ekose             #+#    #+#             */
/*   Updated: 2024/08/12 14:39:17 by ekose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/minishell.h"


static void	ft_dir_check(t_state **state, char *dir)
{
	struct stat	file_info;

	(void) state;
	if (stat(dir, &file_info) == 0) //dizinin infosu alınır
	{
		if (S_ISDIR(file_info.st_mode))//S_ISDIR ile dizinmi kontrol edilir
		{
			if (access(dir, R_OK) == 0) //dsoya okunabilir mi
			{
				if (chdir(dir) != 0) //dizine gidilir
					perror("CHDIR");
				else
					(*state)->error = 0;
			}
			else
				ft_cd_error(dir,*state);
		}
		else
			ft_cd_error(dir,*state);
	}
	else
		ft_cd_error(dir,*state);
}

static void	ft_env_find(t_state *state, char *key)
{
	t_env		*tmp;
	t_cluster	*cluster;
	char		*tmp_dir;

	cluster = state->cluster;
	tmp = state->env;
	while (tmp)
	{
		if (ft_strncmp(tmp->key, key, ft_strlen(key)) == 0)
		{
			tmp_dir = ft_strjoin(tmp->value, cluster->cmd[1] + 1);
			free(cluster->cmd[1]);
			cluster->cmd[1] = tmp_dir;
		}
		tmp = tmp->next;
	}
	ft_dir_check(&state, cluster->cmd[1]);
}
static void	ft_select_dir(t_state **state, char *type)//home dizinimi oldpwd mi
{
	t_env	*tmp_env;
	char	*dir;

	tmp_env = (*state)->env;
	if (ft_strncmp(type, "HOME", ft_strlen(type)) == 0)
		while (tmp_env && ft_strncmp(tmp_env->key, "HOME", ft_strlen("HOME"))) //envde home aranır
			tmp_env = tmp_env->next;
	else if (ft_strncmp(type, "OLDPWD", ft_strlen(type)) == 0)
		while (tmp_env && ft_strncmp(tmp_env->key,
				"OLDPWD", ft_strlen("OLDPWD"))) //envde oldpwd aranır
			tmp_env = tmp_env->next;
	if (tmp_env == NULL)//dizin bulunmuş mu bulunmadı ise notset yazdır
	{
		ft_notdefine_dir(type, *state); //notdefine fonkiyonunu geliştirilebilir
		return ;
	}
	dir = tmp_env->value;
	ft_dir_check(state, dir);
	if (ft_strcmp("OLDPWD", type) == 0)
	{
		write((*state)->cluster->files->fd_output, dir, ft_strlen(dir));
		write((*state)->cluster->files->fd_output, "\n", 1);
	}
}

static void	ft_up_dir(t_state **state)
{
	char		cwd[1024];
	char		*dir;
	size_t		len;

	if (getcwd(cwd, sizeof(cwd)) == NULL)	//şuan ki dizin alınır
	{
		perror("getcwd");
		return ;
	}
	len = ft_strlen(ft_strrchr(cwd, '/'));
	dir = ft_substr(cwd, 0, ft_strlen(cwd) - len);
	if (ft_strlen(dir) == 0)
	{
		free(dir);
		dir = ft_strdup("/");
	}
	ft_dir_check(state, dir);
	free(dir);
	(*state)->error = 0;
}

void	ft_cd(t_state **state)
{
	t_cluster	*tmp;
	char		pwd[1024];
	char		*oldpwd;

	getcwd(pwd, sizeof(pwd));
	oldpwd = ft_strjoin("OLDPWD=", pwd);
	ft_add_exp(state, oldpwd);
	ft_add_env(state, oldpwd);
	tmp = (*state)->cluster;
	if (tmp->cmd == NULL || tmp->cmd[1] == NULL)
		ft_select_dir(state, "HOME");
	else if (ft_strncmp(tmp->cmd[1], "~", ft_strlen(tmp->cmd[0])) == 0)
		ft_select_dir(state, "HOME");
	else if (ft_strncmp(tmp->cmd[1], "-", ft_strlen(tmp->cmd[1])) == 0)
		ft_select_dir(state, "OLDPWD");
	else if (ft_strncmp(tmp->cmd[1], ".", ft_strlen(tmp->cmd[1])) == 0)
		return ;
	else if (ft_strncmp(tmp->cmd[1], "..", ft_strlen(tmp->cmd[1])) == 0)
		ft_up_dir(state);
	else if (tmp->cmd[1][0] == '~')
		ft_env_find(*state, "HOME");
	else
		ft_dir_check(state, tmp->cmd[1]);
	free(oldpwd);
}