/*
 * lib/krb5/free/f_priv_enc.c
 *
 * Copyright 1990 by the Massachusetts Institute of Technology.
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
 * krb5_free_priv_enc_part()
 */


#include <krb5/krb5.h>
#include <krb5/ext-proto.h>

void
krb5_free_priv_enc_part(val)
register krb5_priv_enc_part *val;
{
    if (val->user_data.data)
	krb5_xfree(val->user_data.data);
    if (val->r_address)
	krb5_free_address(val->r_address);
    if (val->s_address)
	krb5_free_address(val->s_address);
    krb5_xfree(val);
    return;
}
