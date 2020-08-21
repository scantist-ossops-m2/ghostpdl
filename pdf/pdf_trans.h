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

#ifndef PDF_TRANSPARENCY_OPERATORS
#define PDF_TRANSPARENCY_OPERATORS

/* these names are to match the PS code (pdf_ops.ps/OPSaveDstack, setup_trans, teardown_trans) */
typedef struct {
    bool GroupPushed;
    bool ChangeBM;
    float saveStrokeAlpha;
    float saveFillAlpha;
    gs_blend_mode_t saveBM;
} pdfi_trans_state_t;

typedef enum {
    TRANSPARENCY_Caller_Other,
    TRANSPARENCY_Caller_Image,
    TRANSPARENCY_Caller_Stroke,
    TRANSPARENCY_Caller_Fill,
    TRANSPARENCY_Caller_EOFill
} pdfi_transparency_caller_t;

int pdfi_trans_setup(pdf_context *ctx, pdfi_trans_state_t *state, pdfi_transparency_caller_t caller);
int pdfi_trans_teardown(pdf_context *ctx, pdfi_trans_state_t *state);

int pdfi_trans_begin_simple_group(pdf_context *ctx, bool stroked_bbox, bool isolated, bool knockout);
int pdfi_trans_begin_page_group(pdf_context *ctx, pdf_dict *page_dict, pdf_dict *group_dict);
int pdfi_trans_begin_form_group(pdf_context *ctx, pdf_dict *page_dict, pdf_dict *form_dict);
int pdfi_trans_end_group(pdf_context *ctx);
int pdfi_trans_end_simple_group(pdf_context *ctx);
int pdfi_trans_set_params(pdf_context *ctx);
int pdfi_trans_begin_isolated_group(pdf_context *ctx, bool image_with_SMask);
int pdfi_trans_end_isolated_group(pdf_context *ctx);
int pdfi_trans_end_smask_notify(pdf_context *ctx);
void pdfi_trans_set_needs_OP(pdf_context *ctx);

#endif