/*
--- DO NOT EDIT THIS FILE !!! ---

This file has been generated automatically with 'jsapigen'.

jsapigen is a glue-code generator for SpiderMonkey. It is distributed
under the conditions of version 3 of the GNU General Public License.
Please have a look at http://jsapigen.sourceforge.net.

This file is NOT part of jsapigen and is NOT necessarily covered by
jsapigen's license. For licensing information regarding this file,
please refer to the software package which it is part of.

*/

#include "stdio.h"
#include "ADM_jsAvidemux.h"
#include "ADM_scriptDebug.h"

#ifdef HAVE_ALLOCA_H
#include <alloca.h>
static size_t jj_alloca_limit = 0;
#endif
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#ifdef HAVE_ALLOCA_H
#endif
#include <jsapi.h>
#ifndef JS_THREADSAFE
#if JS_VERSION <= 170
#define jsrefcount int
#define JS_BeginRequest(cx)
#define JS_EndRequest(cx)
#define JS_SuspendRequest(cx)
#define JS_ResumeRequest(cx, saveDepth)
#endif
#endif
#ifndef JS_FS
#define JS_FS(name, call, nargs, flags, extra) {name, call, nargs, flags, extra}
#endif
#ifndef JS_FS_END
#define JS_FS_END {NULL, NULL, 0, 0, 0}
#endif

static JSBool
jjadmPopupError(JSContext *cx, JSObject *obj, uintN argc, jsval *argv, jsval *rval)
{
    JSObject * var2;
    int var6;
    char * var7;
    int var8;
    jsval var9;
    JSString * var10;
    jsval var86;
    size_t var11;
    size_t var12;
    int var14;
    jschar * var15;
    jsval var87;
    JSBool var1;
    var2 = NULL;
    var6 = 0;
    var7 = NULL;
    var8 = 0;
    var9 = JSVAL_NULL;
    var10 = NULL;
    var86 = JSVAL_NULL;
    var11 = 0;
    var12 = 0;
    var14 = 0;
    var15 = NULL;
    var87 = JSVAL_NULL;
    var1 = JS_FALSE;
    var2 = obj;
    var6 = argc;
    var8 = 0;
    var8 = var8 < var6;
    if (var8) {
    var9 = argv[0];
    var10 = JS_ValueToString(cx, var9);
    if (!var10) {
        goto do_return;
    }
    var86 = STRING_TO_JSVAL(var10);
    argv[argc+0] = var86;
    var11 = JS_GetStringLength(var10);
    var12 = 1;
    var12 += var11;
#ifdef HAVE_ALLOCA
    if (var12 < jj_alloca_limit) {
        var7 = alloca(var12);
    } else {
#endif
        var7 = malloc(var12);
        if (!var7) {
            goto do_return;
        } else {
            var14 = 1;
        }
#ifdef HAVE_ALLOCA
    }
#endif
    var15 = JS_GetStringChars(var10);
    var87 = STRING_TO_JSVAL(var10);
    argv[argc+1] = var87;
    {
        size_t i;
        for (i = 0; i < var11; ++i) {
            var7[i] = var15[i];
        }
        var7[var11] = '\0';
    }
    }
    jsPopupError(var7);
    var1 = JS_TRUE;
    do_return:
    if (var14) {
        free(var7);
        var7 = NULL;
        var14 = 0;
    }
    return var1;
}
static JSBool
jjadmpPopupInfo(JSContext *cx, JSObject *obj, uintN argc, jsval *argv, jsval *rval)
{
    JSObject * var17;
    int var21;
    char * var22;
    int var23;
    jsval var24;
    JSString * var25;
    jsval var88;
    size_t var26;
    size_t var27;
    int var29;
    jschar * var30;
    jsval var89;
    JSBool var16;
    var17 = NULL;
    var21 = 0;
    var22 = NULL;
    var23 = 0;
    var24 = JSVAL_NULL;
    var25 = NULL;
    var88 = JSVAL_NULL;
    var26 = 0;
    var27 = 0;
    var29 = 0;
    var30 = NULL;
    var89 = JSVAL_NULL;
    var16 = JS_FALSE;
    var17 = obj;
    var21 = argc;
    var23 = 0;
    var23 = var23 < var21;
    if (var23) {
    var24 = argv[0];
    var25 = JS_ValueToString(cx, var24);
    if (!var25) {
        goto do_return;
    }
    var88 = STRING_TO_JSVAL(var25);
    argv[argc+0] = var88;
    var26 = JS_GetStringLength(var25);
    var27 = 1;
    var27 += var26;
#ifdef HAVE_ALLOCA
    if (var27 < jj_alloca_limit) {
        var22 = alloca(var27);
    } else {
#endif
        var22 = malloc(var27);
        if (!var22) {
            goto do_return;
        } else {
            var29 = 1;
        }
#ifdef HAVE_ALLOCA
    }
#endif
    var30 = JS_GetStringChars(var25);
    var89 = STRING_TO_JSVAL(var25);
    argv[argc+1] = var89;
    {
        size_t i;
        for (i = 0; i < var26; ++i) {
            var22[i] = var30[i];
        }
        var22[var26] = '\0';
    }
    }
    jsPopupInfo(var22);
    var16 = JS_TRUE;
    do_return:
    if (var29) {
        free(var22);
        var22 = NULL;
        var29 = 0;
    }
    return var16;
}
static JSBool
jjadmPrint(JSContext *cx, JSObject *obj, uintN argc, jsval *argv, jsval *rval)
{
    JSObject * var32;
    int var36;
    char * var37;
    int var38;
    jsval var39;
    JSString * var40;
    jsval var90;
    size_t var41;
    size_t var42;
    int var44;
    jschar * var45;
    jsval var91;
    JSBool var31;
    var32 = NULL;
    var36 = 0;
    var37 = NULL;
    var38 = 0;
    var39 = JSVAL_NULL;
    var40 = NULL;
    var90 = JSVAL_NULL;
    var41 = 0;
    var42 = 0;
    var44 = 0;
    var45 = NULL;
    var91 = JSVAL_NULL;
    var31 = JS_FALSE;
    var32 = obj;
    var36 = argc;
    var38 = 0;
    var38 = var38 < var36;
    if (var38) {
    var39 = argv[0];
    var40 = JS_ValueToString(cx, var39);
    if (!var40) {
        goto do_return;
    }
    var90 = STRING_TO_JSVAL(var40);
    argv[argc+0] = var90;
    var41 = JS_GetStringLength(var40);
    var42 = 1;
    var42 += var41;
#ifdef HAVE_ALLOCA
    if (var42 < jj_alloca_limit) {
        var37 = alloca(var42);
    } else {
#endif
        var37 = malloc(var42);
        if (!var37) {
            goto do_return;
        } else {
            var44 = 1;
        }
#ifdef HAVE_ALLOCA
    }
#endif
    var45 = JS_GetStringChars(var40);
    var91 = STRING_TO_JSVAL(var40);
    argv[argc+1] = var91;
    {
        size_t i;
        for (i = 0; i < var41; ++i) {
            var37[i] = var45[i];
        }
        var37[var41] = '\0';
    }
    }
    jsPrint(var37);
    var31 = JS_TRUE;
    do_return:
    if (var44) {
        free(var37);
        var37 = NULL;
        var44 = 0;
    }
    return var31;
}
static JSBool
jjprint(JSContext *cx, JSObject *obj, uintN argc, jsval *argv, jsval *rval)
{
    JSObject * var47;
    int var51;
    char * var52;
    int var53;
    jsval var54;
    JSString * var55;
    jsval var92;
    size_t var56;
    size_t var57;
    int var59;
    jschar * var60;
    jsval var93;
    JSBool var46;
    var47 = NULL;
    var51 = 0;
    var52 = NULL;
    var53 = 0;
    var54 = JSVAL_NULL;
    var55 = NULL;
    var92 = JSVAL_NULL;
    var56 = 0;
    var57 = 0;
    var59 = 0;
    var60 = NULL;
    var93 = JSVAL_NULL;
    var46 = JS_FALSE;
    var47 = obj;
    var51 = argc;
    var53 = 0;
    var53 = var53 < var51;
    if (var53) {
    var54 = argv[0];
    var55 = JS_ValueToString(cx, var54);
    if (!var55) {
        goto do_return;
    }
    var92 = STRING_TO_JSVAL(var55);
    argv[argc+0] = var92;
    var56 = JS_GetStringLength(var55);
    var57 = 1;
    var57 += var56;
#ifdef HAVE_ALLOCA
    if (var57 < jj_alloca_limit) {
        var52 = alloca(var57);
    } else {
#endif
        var52 = malloc(var57);
        if (!var52) {
            goto do_return;
        } else {
            var59 = 1;
        }
#ifdef HAVE_ALLOCA
    }
#endif
    var60 = JS_GetStringChars(var55);
    var93 = STRING_TO_JSVAL(var55);
    argv[argc+1] = var93;
    {
        size_t i;
        for (i = 0; i < var56; ++i) {
            var52[i] = var60[i];
        }
        var52[var56] = '\0';
    }
    }
    jsPrint2(var52);
    var46 = JS_TRUE;
    do_return:
    if (var59) {
        free(var52);
        var52 = NULL;
        var59 = 0;
    }
    return var46;
}
static JSBool
jjhelp(JSContext *cx, JSObject *obj, uintN argc, jsval *argv, jsval *rval)
{
    JSObject * var62;
    int var66;
    char * var67;
    int var68;
    jsval var69;
    JSString * var70;
    jsval var94;
    size_t var71;
    size_t var72;
    int var74;
    jschar * var75;
    jsval var95;
    JSBool var61;
    var62 = NULL;
    var66 = 0;
    var67 = NULL;
    var68 = 0;
    var69 = JSVAL_NULL;
    var70 = NULL;
    var94 = JSVAL_NULL;
    var71 = 0;
    var72 = 0;
    var74 = 0;
    var75 = NULL;
    var95 = JSVAL_NULL;
    var61 = JS_FALSE;
    var62 = obj;
    var66 = argc;
    var68 = 0;
    var68 = var68 < var66;
    if (var68) {
    var69 = argv[0];
    var70 = JS_ValueToString(cx, var69);
    if (!var70) {
        goto do_return;
    }
    var94 = STRING_TO_JSVAL(var70);
    argv[argc+0] = var94;
    var71 = JS_GetStringLength(var70);
    var72 = 1;
    var72 += var71;
#ifdef HAVE_ALLOCA
    if (var72 < jj_alloca_limit) {
        var67 = alloca(var72);
    } else {
#endif
        var67 = malloc(var72);
        if (!var67) {
            goto do_return;
        } else {
            var74 = 1;
        }
#ifdef HAVE_ALLOCA
    }
#endif
    var75 = JS_GetStringChars(var70);
    var95 = STRING_TO_JSVAL(var70);
    argv[argc+1] = var95;
    {
        size_t i;
        for (i = 0; i < var71; ++i) {
            var67[i] = var75[i];
        }
        var67[var71] = '\0';
    }
    }
    jsHelp(var67);
    var61 = JS_TRUE;
    do_return:
    if (var74) {
        free(var67);
        var67 = NULL;
        var74 = 0;
    }
    return var61;
}
static JSBool
jjsetSuccess(JSContext *cx, JSObject *obj, uintN argc, jsval *argv, jsval *rval)
{
    JSObject * var77;
    int var81;
    int var82;
    int var83;
    jsval var84;
    int32 var85;
    JSBool var76;
    var77 = NULL;
    var81 = 0;
    var82 = 0;
    var83 = 0;
    var84 = JSVAL_NULL;
    var85 = 0;
    var76 = JS_FALSE;
    var77 = obj;
    var81 = argc;
    var83 = 0;
    var83 = var83 < var81;
    if (var83) {
    var84 = argv[0];
    if (JS_ValueToInt32(cx, var84, &var85) != JS_TRUE) {
        goto do_return;
    }
    var82 = (int)var85;
    }
    jsSetSuccess(var82);
    var76 = JS_TRUE;
    do_return:
    return var76;
}
static JSPropertySpec jj_static_ps[] = {
    {NULL, 0, 0, NULL, NULL}
};
static JSPropertySpec jj_ps[] = {
    {NULL, 0, 0, NULL, NULL}
};
static JSFunctionSpec jj_static_fs[] = {
    JS_FS("admPopupError", jjadmPopupError, 1, 0, 2),
    JS_FS("admpPopupInfo", jjadmpPopupInfo, 1, 0, 2),
    JS_FS("admPrint", jjadmPrint, 1, 0, 2),
    JS_FS("print", jjprint, 1, 0, 2),
    JS_FS("help", jjhelp, 1, 0, 2),
    JS_FS("setSuccess", jjsetSuccess, 1, 0, 0),
    JS_FS_END
};
static JSFunctionSpec jj_fs[] = {
    JS_FS("admPopupError", jjadmPopupError, 1, 0, 2),
    JS_FS("admpPopupInfo", jjadmpPopupInfo, 1, 0, 2),
    JS_FS("admPrint", jjadmPrint, 1, 0, 2),
    JS_FS("print", jjprint, 1, 0, 2),
    JS_FS("help", jjhelp, 1, 0, 2),
    JS_FS("setSuccess", jjsetSuccess, 1, 0, 0),
    JS_FS_END
};

JSFunctionSpec  *jsGetIfFunctions(void)
{
        return jj_static_fs;
}

