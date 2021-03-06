/*
   +----------------------------------------------------------------------+
   | Xdebug                                                               |
   +----------------------------------------------------------------------+
   | Copyright (c) 2002-2011 Derick Rethans                               |
   +----------------------------------------------------------------------+
   | This source file is subject to version 1.0 of the Xdebug license,    |
   | that is bundled with this package in the file LICENSE, and is        |
   | available at through the world-wide-web at                           |
   | http://xdebug.derickrethans.nl/license.php                           |
   | If you did not receive a copy of the Xdebug license and are unable   |
   | to obtain it through the world-wide-web, please send a note to       |
   | xdebug@derickrethans.nl so we can mail you a copy immediately.       |
   +----------------------------------------------------------------------+
   | Authors: Harald Radi <harald.radi@nme.at>                            |
   +----------------------------------------------------------------------+
 */

#ifndef __HAVE_XDEBUG_SUPERGLOBALS_H__
#define __HAVE_XDEBUG_SUPERGLOBALS_H__

#include "php.h"

void xdebug_superglobals_dump_dtor(void *, void*);
char *xdebug_get_printable_superglobals(int html TSRMLS_DC);
void xdebug_superglobals_dump_tok(xdebug_llist *l, char *str);

#define DUMP_TOK(__llist) \
	xdebug_llist_empty(&XG(__llist), NULL); \
	if (new_value && *new_value) { \
		char *str = estrndup(new_value, new_value_length); \
		xdebug_superglobals_dump_tok(&XG(__llist), str); \
		efree(str); \
	} \
	return SUCCESS;

#endif /* __HAVE_XDEBUG_SUPERGLOBALS_H__ */
