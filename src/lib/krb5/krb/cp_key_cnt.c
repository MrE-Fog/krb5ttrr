/*
 * lib/krb5/krb/cp_key_cnt.c
 *
 * Copyright 1991 by the Massachusetts Institute of Technology.
 * All Rights Reserved.
 *
 * Export of this software from the United States of America may
 *   require a specific license from the United States Government.
 *   It is the responsibility of any person or organization contemplating
 *   export to obtain such a license before exporting.
 * 
 * WITHIN THAT CONSTRAINT, permission to use, copy, modify, and
 * distribute this software and its documentation for any purpose and
 * without fee is hereby granted, provided that the above copyright
 * notice appear in all copies and that both that copyright notice and
 * this permission notice appear in supporting documentation, and that
 * the name of M.I.T. not be used in advertising or publicity pertaining
 * to distribution of the software without specific, written prior
 * permission.  M.I.T. makes no representations about the suitability of
 * this software for any purpose.  It is provided "as is" without express
 * or implied warranty.
 * 
 *
 * krb5_copy_keyblock()
 */


#include <krb5/krb5.h>
#include <krb5/ext-proto.h>

/*
 * Copy a keyblock, including alloc'ed storage.
 */
krb5_error_code
krb5_copy_keyblock_contents(from, to)
const krb5_keyblock *from;
krb5_keyblock *to;
{
    *to = *from;
    to->contents = (krb5_octet *)malloc(to->length);
    if (!to->contents)
	return ENOMEM;
    memcpy((char *)to->contents, (char *)from->contents, to->length);
    return 0;
}
