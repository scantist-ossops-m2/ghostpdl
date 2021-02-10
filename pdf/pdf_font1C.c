/* Copyright (C) 2001-2020 Artifex Software, Inc.
   All Rights Reserved.

   This software is provided AS-IS with no warranty, either express or
   implied.

   This software is distributed under license and may not be copied,
   modified or distributed except as expressly authorized under the terms
   of the license contained in the file LICENSE in this distribution.

   Refer to licensing information at http://www.artifex.com or contact
   Artifex Software, Inc.,  1305 Grant Avenue - Suite 200, Novato,
   CA 94945, U.S.A., +1(415)492-9861, for further information.
*/

/* code for CFF (type 1C) font handling */

#include "pdf_int.h"
#include "pdf_types.h"
#include "pdf_font_types.h"
#include "pdf_font.h"
#include "pdf_font1C.h"
#include "pdf_fontps.h"

int pdfi_read_type1C_font(pdf_context *ctx, pdf_dict *font_dict, pdf_dict *stream_dict, pdf_dict *page_dict, gs_font **pfont)
{
    return_error(gs_error_invalidfont);
}