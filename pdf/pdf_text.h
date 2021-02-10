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

/* Text operations for the PDF interpreter */

#ifndef PDF_TEXT_OPERATORS
#define PDF_TEXT_OPERATORS

typedef struct pdf_text_tracking_s
{
    int text_block_depth;
    gs_matrix initial_CTM;
    gs_matrix saved_Tm;
    gs_matrix saved_Tl;
    int initial_gsave_depth;
    void *next_block;
} pdf_text_tracking;

int pdfi_BT(pdf_context *ctx);
int pdfi_ET(pdf_context *ctx);
int pdfi_T_star(pdf_context *ctx);
int pdfi_Tc(pdf_context *ctx);
int pdfi_Td(pdf_context *ctx);
int pdfi_TD(pdf_context *ctx);
int pdfi_Tj(pdf_context *ctx);
int pdfi_TJ(pdf_context *ctx);
int pdfi_TL(pdf_context *ctx);
int pdfi_Tm(pdf_context *ctx);
int pdfi_Tr(pdf_context *ctx);
int pdfi_Ts(pdf_context *ctx);
int pdfi_Tw(pdf_context *ctx);
int pdfi_Tz(pdf_context *ctx);
int pdfi_backslash(pdf_context *ctx);
int pdfi_singlequote(pdf_context *ctx);
int pdfi_doublequote(pdf_context *ctx);

/* Returns the bounding box of a string drawn with the current graphics state.
   Stroking implies a slightly larger bounding box - the parameter is ignored
   for Type 3 fonts.
   This can be an expensive operation, so should be used sparingly, with care.
 */
int pdfi_string_bbox(pdf_context *ctx, pdf_string *s, gs_rect *bboxout, bool for_stroke);

#endif