/*
 * Copyright (C) 2008 Search Solution Corporation. All rights reserved by Search Solution.
 *
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation; either version 2 of the License, or
 *   (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 *
 */


/*
 * broker_filename.h -
 */

#ifndef _BROKER_FILENAME_H_
#define _BROKER_FILENAME_H_

#ident "$Id$"

#include "porting.h"

#if defined(CUBRID_SHARD)
#define APPL_SERVER_CAS_NAME		"shard_cas"
#define APPL_SERVER_CAS_ORACLE_NAME		"shard_cas_oracle"
#define APPL_SERVER_CAS_MYSQL_NAME		"shard_cas_mysql"
#else
#define APPL_SERVER_CAS_NAME		"cub_cas"
#define APPL_SERVER_CAS_ORACLE_NAME		"cub_cas_oracle"
#define APPL_SERVER_CAS_MYSQL_NAME		"cub_cas_mysql"
#endif /* CUBRID_SHARD */

#define NAME_BROKER			"Tbroker"
#if defined(CUBRID_SHARD)
#define NAME_CAS_BROKER			"shard_broker"
#define NAME_PROXY			"shard_proxy"
#else
#define NAME_CAS_BROKER			"cub_broker"
#endif
#if defined(WINDOWS)
#define NAME_CAS_BROKER2		"Cbroker2"
#define NAME_UC_SHM			"broker_shm"
#endif

#define CUBRID_BASE_DIR                 "log/broker/"

#ifdef DISPATCHER
#define ERROR_MSG_FILE			"uw_er.msg"
#endif

#define BROKER_PATH_MAX             (1024)

/* default values */
#define DEFAULT_LOG_DIR               "log/broker/sql_log/"
#define DEFAULT_SLOW_LOG_DIR          DEFAULT_LOG_DIR
#define DEFAULT_ERR_DIR               "log/broker/error_log/"
#define DEFAULT_SHARD_PROXY_LOG_DIR   "log/broker/proxy_log/"

typedef enum t_cubrid_file_id T_CUBRID_FILE_ID;
enum t_cubrid_file_id
{
  FID_CUBRID_BROKER_CONF,
  FID_UV_ERR_MSG,
  FID_V3_OUTFILE_DIR,
  FID_CAS_TMPGLO_DIR,
  FID_CAS_TMP_DIR,
  FID_VAR_DIR,
  FID_SOCK_DIR,
  FID_AS_PID_DIR,
  FID_ADMIND_PID,
  FID_SQL_LOG_DIR,
  FID_SQL_LOG2_DIR,
  FID_ADMIND_LOG,
  FID_MONITORD_LOG,
  FID_ER_HTML,
  FID_CUBRID_ERR_DIR,
  FID_CAS_FOR_ORACLE_DBINFO,
  FID_CAS_FOR_MYSQL_DBINFO,
  FID_ACCESS_CONTROL_FILE,
  FID_SLOW_LOG_DIR,
  FID_SHARD_DBINFO,
  FID_SHARD_PROXY_LOG_DIR,
  MAX_CUBRID_FILE
};

typedef struct t_cubrid_file_info T_CUBRID_FILE_INFO;
struct t_cubrid_file_info
{
  T_CUBRID_FILE_ID fid;
  char file_name[BROKER_PATH_MAX];
};

extern void set_cubrid_home (void);
extern void set_cubrid_file (T_CUBRID_FILE_ID fid, char *value);
extern char *get_cubrid_file (T_CUBRID_FILE_ID fid, char *buf, size_t len);
extern char *get_cubrid_file_ptr (T_CUBRID_FILE_ID fid);
extern char *get_cubrid_home (void);
extern const char *getenv_cubrid_broker (void);

#endif /* _BROKER_FILENAME_H_ */
