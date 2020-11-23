/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_otool.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 15:19:39 by cpieri            #+#    #+#             */
/*   Updated: 2020/11/23 15:19:56 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_OTOOL_H
# define FT_OTOOL_H

# include "../../libft/include/libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <sys/stat.h>
# include <sys/mman.h>

# include <mach-o/loader.h>
# include <mach-o/fat.h>
# include <ar.h>

# define FAILURE	-1
# define AR_MAGIC 0x72613c21
# define AR_CIGAM 0x213c6172

typedef struct mach_header			t_mach_header;
typedef struct mach_header_64		t_mach_header_64;
typedef struct fat_header			t_fat_header;
typedef struct ar_hdr				t_ar_header;

typedef struct fat_arch				t_fat_arch;
typedef struct fat_arch_64			t_fat_arch_64;

typedef struct load_command			t_load_command;
typedef struct segment_command		t_segment_command;
typedef struct segment_command_64	t_segment_command_64;
typedef struct section				t_section;
typedef struct section_64			t_section_64;

typedef struct	s_file
{
	void 		*ptr;
	char 		*name;
	size_t		len;
}				t_file;

int 	ft_otool(t_file file);

int 	parse_macho(t_file file);
int 	parse_macho_64(t_file file);
int 	parse_fat(t_file file);
int 	parse_fat_64(t_file file);
int 	parse_archive(t_file file);

t_file 	open_file(char *filename);
int 	print_error(const char *prog, const char *msg);
int 	print_msg(const char *prog, const char *msg, int ret);

#endif
