#ifndef _DIRTREE_H_
#define _DIRTREE_H_

#include "refArray.h"
#include "strShare.h"
#include "fileInfo.h"

#ifndef DT_DIR
# define DT_UNKNOWN	0
# define DT_FIFO	1
# define DT_CHR		2
# define DT_DIR		4
# define DT_BLK		6
# define DT_REG		8
# define DT_LNK		10
# define DT_SOCK	12
# define DT_WHT		14
#endif

void scanDirTree( char *path, StrShare *pathShare, RefArray *origRef, RefArray *sortRef );

#endif

