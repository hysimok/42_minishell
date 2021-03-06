/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_struct.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjung <hjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 00:17:46 by hjung             #+#    #+#             */
/*   Updated: 2021/01/05 23:19:19 by hjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_STRUCT_H
# define MINISHELL_STRUCT_H

typedef	struct		s_lstenv
{
	char			*key;
	char			*value;
	struct s_lstenv	*next;
}					t_lstenv;

typedef struct		s_rdir
{
	char			*file;
	int				fd;
	int				is_dbl;
	int				std;
	struct s_rdir	*next;
}					t_rdir;

typedef	struct		s_lstcmd
{
	char			**argv;
	int				is_pipe;
	int				is_rdir;
	int				has_path;
	t_rdir			*in;
	t_rdir			*out;
	struct s_lstcmd	*next;
}					t_lstcmd;

typedef struct		s_minishell
{
	char			*line;				//입력된 라인이 저장되는 변수
	char			**tokens;			//입력된 라인을 단위별로 자른 내용이 저장되는 변수
	int				executed;
	int				excode;
	int				eof;
	int				ret;				//get_next_line() 함수의 리턴값이 저장됨
	t_lstenv		*env;				//환경변수가 차례로 저장되는 연결리스트
	t_lstcmd		*cmd;				//파이프 쓸 때 명령어가 차례로 저장되는 연결리스트 
}					t_minishell;

t_minishell			*g_minish;

#endif