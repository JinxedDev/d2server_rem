#ifndef INCLUDED_NET_D2CS_D2GS_CHARACTER_H
#define INCLUDED_NET_D2CS_D2GS_CHARACTER_H

#include "bn_types.h"

#pragma pack(push, 1)

#define D2CHARINFO_MAGICWORD		0x12345678
#define D2CHARINFO_VERSION			0x00010000
#define D2CHARINFO_PORTRAIT_PADSIZE	30

typedef struct
{
	bn_int		magicword;	/* static for check */
	bn_int		version;	/* charinfo file version */
	bn_int		create_time;	/* character creation time */
	bn_int		last_time;	/* character last access time */
	bn_int		checksum;
	bn_int          total_play_time;        /* total in game play time */
	bn_int		reserved[6];
	char	charname[MAX_CHARNAME_LEN];
	char	account[MAX_ACCTNAME_LEN];
	char	realmname[MAX_REALMNAME_LEN];
} t_d2charinfo_header;

typedef struct
{
	bn_int		experience;
	bn_int		charstatus;
	bn_int		charlevel;
	bn_int		charclass;
} t_d2charinfo_summary;

typedef struct
{
	bn_short        header;	/* 0x84 0x80 */
	bn_byte         gfx[11];
	bn_byte         char_class;
	bn_byte         color[11];
	bn_byte         level;
	bn_byte         status;
	bn_byte         u1[3];
	bn_byte		    ladder;	/* need not be 0xff and 0 to make character displayed as ladder character */ /* client only check this bit */
	bn_byte         u2[2];
	bn_byte         end;	/* 0x00 */
} t_d2charinfo_portrait;

typedef struct
{
	t_d2charinfo_header		header;
	t_d2charinfo_portrait	portrait;
	bn_byte					pad[D2CHARINFO_PORTRAIT_PADSIZE];
	t_d2charinfo_summary	summary;
} t_d2charinfo_file;

#pragma pack(pop)

#include <string>
std::string assemble_charinfo(std::string& acctname, std::string charname, int char_class, int char_level,
	int exp_low, int char_status, std::string& portrait, int create_time, std::string realmname);

#endif
