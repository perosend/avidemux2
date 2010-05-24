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
void jsAvidemux(void)
{
        printf("Constructor invoked\n");
}

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
jjadmmarkerA_get(JSContext *cx, JSObject *obj, jsval id, jsval *val)
{
    double var2;
    jsval var5;
    JSBool var1;
    var2 = 0.0;
    var5 = JSVAL_NULL;
    var1 = JS_FALSE;
    if (!JS_EnterLocalRootScope(cx)) {
        goto do_return;
    }
    var2 = jsGetMarkerA();
    if (JS_NewNumberValue(cx, var2, &var5) != JS_TRUE) {
        goto do_return;
    }
    if (val) {
        *val = var5;
    }
    var1 = JS_TRUE;
    do_return:
    JS_LeaveLocalRootScope(cx);
    return var1;
}
static JSBool
jjadmmarkerA_set(JSContext *cx, JSObject *obj, jsval id, jsval *val)
{
    double var7;
    jsval var10;
    jsdouble var11;
    JSBool var6;
    var7 = 0.0;
    var10 = JSVAL_NULL;
    var11 = 0.0;
    var6 = JS_FALSE;
    if (!JS_EnterLocalRootScope(cx)) {
        goto do_return;
    }
    var10 = *val;
    if (JS_ValueToNumber(cx, var10, &var11) != JS_TRUE) {
        goto do_return;
    }
    var7 = (double)var11;
    jsSetMarkerA(var7);
    var6 = JS_TRUE;
    do_return:
    JS_LeaveLocalRootScope(cx);
    return var6;
}
static JSBool
jjadmmarkerB_get(JSContext *cx, JSObject *obj, jsval id, jsval *val)
{
    double var13;
    jsval var16;
    JSBool var12;
    var13 = 0.0;
    var16 = JSVAL_NULL;
    var12 = JS_FALSE;
    if (!JS_EnterLocalRootScope(cx)) {
        goto do_return;
    }
    var13 = jsGetMarkerB();
    if (JS_NewNumberValue(cx, var13, &var16) != JS_TRUE) {
        goto do_return;
    }
    if (val) {
        *val = var16;
    }
    var12 = JS_TRUE;
    do_return:
    JS_LeaveLocalRootScope(cx);
    return var12;
}
static JSBool
jjadmmarkerB_set(JSContext *cx, JSObject *obj, jsval id, jsval *val)
{
    double var18;
    jsval var21;
    jsdouble var22;
    JSBool var17;
    var18 = 0.0;
    var21 = JSVAL_NULL;
    var22 = 0.0;
    var17 = JS_FALSE;
    if (!JS_EnterLocalRootScope(cx)) {
        goto do_return;
    }
    var21 = *val;
    if (JS_ValueToNumber(cx, var21, &var22) != JS_TRUE) {
        goto do_return;
    }
    var18 = (double)var22;
    jsSetMarkerB(var18);
    var17 = JS_TRUE;
    do_return:
    JS_LeaveLocalRootScope(cx);
    return var17;
}
static JSBool
jjadmaudioResample_get(JSContext *cx, JSObject *obj, jsval id, jsval *val)
{
    int var24;
    jsval var27;
    JSBool var23;
    var24 = 0;
    var27 = JSVAL_NULL;
    var23 = JS_FALSE;
    if (!JS_EnterLocalRootScope(cx)) {
        goto do_return;
    }
    var24 = jsGetResample();
    if (JS_NewNumberValue(cx, var24, &var27) != JS_TRUE) {
        goto do_return;
    }
    if (val) {
        *val = var27;
    }
    var23 = JS_TRUE;
    do_return:
    JS_LeaveLocalRootScope(cx);
    return var23;
}
static JSBool
jjadmaudioResample_set(JSContext *cx, JSObject *obj, jsval id, jsval *val)
{
    int var29;
    jsval var32;
    int32 var33;
    JSBool var28;
    var29 = 0;
    var32 = JSVAL_NULL;
    var33 = 0;
    var28 = JS_FALSE;
    if (!JS_EnterLocalRootScope(cx)) {
        goto do_return;
    }
    var32 = *val;
    if (JS_ValueToInt32(cx, var32, &var33) != JS_TRUE) {
        goto do_return;
    }
    var29 = (int)var33;
    jsSetResample(var29);
    var28 = JS_TRUE;
    do_return:
    JS_LeaveLocalRootScope(cx);
    return var28;
}
static JSBool
jjadmloadVideo(JSContext *cx, JSObject *obj, uintN argc, jsval *argv, jsval *rval)
{
    JSObject * var35;
    int var36;
    int var39;
    char * var40;
    int var41;
    jsval var42;
    JSString * var43;
    jsval var241;
    size_t var44;
    size_t var45;
    int var47;
    jschar * var48;
    jsval var242;
    jsval var49;
    JSBool var34;
    var35 = NULL;
    var36 = 0;
    var39 = 0;
    var40 = NULL;
    var41 = 0;
    var42 = JSVAL_NULL;
    var43 = NULL;
    var241 = JSVAL_NULL;
    var44 = 0;
    var45 = 0;
    var47 = 0;
    var48 = NULL;
    var242 = JSVAL_NULL;
    var49 = JSVAL_NULL;
    var34 = JS_FALSE;
    var35 = obj;
    var39 = argc;
    var41 = 0;
    var41 = var41 < var39;
    if (var41) {
    var42 = argv[0];
    var43 = JS_ValueToString(cx, var42);
    if (!var43) {
        goto do_return;
    }
    var241 = STRING_TO_JSVAL(var43);
    argv[argc+0] = var241;
    var44 = JS_GetStringLength(var43);
    var45 = 1;
    var45 += var44;
#ifdef HAVE_ALLOCA
    if (var45 < jj_alloca_limit) {
        var40 = alloca(var45);
    } else {
#endif
        var40 = malloc(var45);
        if (!var40) {
            goto do_return;
        } else {
            var47 = 1;
        }
#ifdef HAVE_ALLOCA
    }
#endif
    var48 = JS_GetStringChars(var43);
    var242 = STRING_TO_JSVAL(var43);
    argv[argc+1] = var242;
    {
        size_t i;
        for (i = 0; i < var44; ++i) {
            var40[i] = var48[i];
        }
        var40[var44] = '\0';
    }
    }
    var36 = jsLoadVideo(var40);
    if (JS_NewNumberValue(cx, var36, &var49) != JS_TRUE) {
        goto do_return;
    }
    argv[argc+2] = var49;
    if (rval) {
        *rval = var49;
    }
    var34 = JS_TRUE;
    do_return:
    if (var47) {
        free(var40);
        var40 = NULL;
        var47 = 0;
    }
    return var34;
}
static JSBool
jjadmclearSegments(JSContext *cx, JSObject *obj, uintN argc, jsval *argv, jsval *rval)
{
    JSObject * var51;
    int var52;
    int var55;
    jsval var56;
    JSBool var50;
    var51 = NULL;
    var52 = 0;
    var55 = 0;
    var56 = JSVAL_NULL;
    var50 = JS_FALSE;
    var51 = obj;
    var55 = argc;
    var52 = jsClearSegments();
    if (JS_NewNumberValue(cx, var52, &var56) != JS_TRUE) {
        goto do_return;
    }
    argv[argc+0] = var56;
    if (rval) {
        *rval = var56;
    }
    var50 = JS_TRUE;
    do_return:
    return var50;
}
static JSBool
jjadmappendVideo(JSContext *cx, JSObject *obj, uintN argc, jsval *argv, jsval *rval)
{
    JSObject * var58;
    int var59;
    int var62;
    char * var63;
    int var64;
    jsval var65;
    JSString * var66;
    jsval var245;
    size_t var67;
    size_t var68;
    int var70;
    jschar * var71;
    jsval var246;
    jsval var72;
    JSBool var57;
    var58 = NULL;
    var59 = 0;
    var62 = 0;
    var63 = NULL;
    var64 = 0;
    var65 = JSVAL_NULL;
    var66 = NULL;
    var245 = JSVAL_NULL;
    var67 = 0;
    var68 = 0;
    var70 = 0;
    var71 = NULL;
    var246 = JSVAL_NULL;
    var72 = JSVAL_NULL;
    var57 = JS_FALSE;
    var58 = obj;
    var62 = argc;
    var64 = 0;
    var64 = var64 < var62;
    if (var64) {
    var65 = argv[0];
    var66 = JS_ValueToString(cx, var65);
    if (!var66) {
        goto do_return;
    }
    var245 = STRING_TO_JSVAL(var66);
    argv[argc+0] = var245;
    var67 = JS_GetStringLength(var66);
    var68 = 1;
    var68 += var67;
#ifdef HAVE_ALLOCA
    if (var68 < jj_alloca_limit) {
        var63 = alloca(var68);
    } else {
#endif
        var63 = malloc(var68);
        if (!var63) {
            goto do_return;
        } else {
            var70 = 1;
        }
#ifdef HAVE_ALLOCA
    }
#endif
    var71 = JS_GetStringChars(var66);
    var246 = STRING_TO_JSVAL(var66);
    argv[argc+1] = var246;
    {
        size_t i;
        for (i = 0; i < var67; ++i) {
            var63[i] = var71[i];
        }
        var63[var67] = '\0';
    }
    }
    var59 = jsAppendVideo(var63);
    if (JS_NewNumberValue(cx, var59, &var72) != JS_TRUE) {
        goto do_return;
    }
    argv[argc+2] = var72;
    if (rval) {
        *rval = var72;
    }
    var57 = JS_TRUE;
    do_return:
    if (var70) {
        free(var63);
        var63 = NULL;
        var70 = 0;
    }
    return var57;
}
static JSBool
jjadmaddSegment(JSContext *cx, JSObject *obj, uintN argc, jsval *argv, jsval *rval)
{
    JSObject * var74;
    int var75;
    int var78;
    int var79;
    int var82;
    jsval var83;
    int32 var84;
    double var80;
    int var85;
    jsval var86;
    jsdouble var87;
    double var81;
    int var88;
    jsval var89;
    jsdouble var90;
    jsval var91;
    JSBool var73;
    var74 = NULL;
    var75 = 0;
    var78 = 0;
    var79 = 0;
    var82 = 0;
    var83 = JSVAL_NULL;
    var84 = 0;
    var80 = 0.0;
    var85 = 0;
    var86 = JSVAL_NULL;
    var87 = 0.0;
    var81 = 0.0;
    var88 = 0;
    var89 = JSVAL_NULL;
    var90 = 0.0;
    var91 = JSVAL_NULL;
    var73 = JS_FALSE;
    var74 = obj;
    var78 = argc;
    var82 = 0;
    var82 = var82 < var78;
    if (var82) {
    var83 = argv[0];
    if (JS_ValueToInt32(cx, var83, &var84) != JS_TRUE) {
        goto do_return;
    }
    var79 = (int)var84;
    }
    var85 = 1;
    var85 = var85 < var78;
    if (var85) {
    var86 = argv[1];
    if (JS_ValueToNumber(cx, var86, &var87) != JS_TRUE) {
        goto do_return;
    }
    var80 = (double)var87;
    }
    var88 = 2;
    var88 = var88 < var78;
    if (var88) {
    var89 = argv[2];
    if (JS_ValueToNumber(cx, var89, &var90) != JS_TRUE) {
        goto do_return;
    }
    var81 = (double)var90;
    }
    var75 = jsAddSegment(var79, var80, var81);
    if (JS_NewNumberValue(cx, var75, &var91) != JS_TRUE) {
        goto do_return;
    }
    argv[argc+0] = var91;
    if (rval) {
        *rval = var91;
    }
    var73 = JS_TRUE;
    do_return:
    return var73;
}
static JSBool
jjadmsetPostProc(JSContext *cx, JSObject *obj, uintN argc, jsval *argv, jsval *rval)
{
    JSObject * var93;
    int var94;
    int var97;
    int var98;
    int var101;
    jsval var102;
    int32 var103;
    int var99;
    int var104;
    jsval var105;
    int32 var106;
    int var100;
    int var107;
    jsval var108;
    int32 var109;
    jsval var110;
    JSBool var92;
    var93 = NULL;
    var94 = 0;
    var97 = 0;
    var98 = 0;
    var101 = 0;
    var102 = JSVAL_NULL;
    var103 = 0;
    var99 = 0;
    var104 = 0;
    var105 = JSVAL_NULL;
    var106 = 0;
    var100 = 0;
    var107 = 0;
    var108 = JSVAL_NULL;
    var109 = 0;
    var110 = JSVAL_NULL;
    var92 = JS_FALSE;
    var93 = obj;
    var97 = argc;
    var101 = 0;
    var101 = var101 < var97;
    if (var101) {
    var102 = argv[0];
    if (JS_ValueToInt32(cx, var102, &var103) != JS_TRUE) {
        goto do_return;
    }
    var98 = (int)var103;
    }
    var104 = 1;
    var104 = var104 < var97;
    if (var104) {
    var105 = argv[1];
    if (JS_ValueToInt32(cx, var105, &var106) != JS_TRUE) {
        goto do_return;
    }
    var99 = (int)var106;
    }
    var107 = 2;
    var107 = var107 < var97;
    if (var107) {
    var108 = argv[2];
    if (JS_ValueToInt32(cx, var108, &var109) != JS_TRUE) {
        goto do_return;
    }
    var100 = (int)var109;
    }
    var94 = jsSetPostProc(var98, var99, var100);
    if (JS_NewNumberValue(cx, var94, &var110) != JS_TRUE) {
        goto do_return;
    }
    argv[argc+0] = var110;
    if (rval) {
        *rval = var110;
    }
    var92 = JS_TRUE;
    do_return:
    return var92;
}
static JSBool
jjadmgetWidth(JSContext *cx, JSObject *obj, uintN argc, jsval *argv, jsval *rval)
{
    JSObject * var112;
    int var113;
    int var116;
    jsval var117;
    JSBool var111;
    var112 = NULL;
    var113 = 0;
    var116 = 0;
    var117 = JSVAL_NULL;
    var111 = JS_FALSE;
    var112 = obj;
    var116 = argc;
    var113 = jsGetWidth();
    if (JS_NewNumberValue(cx, var113, &var117) != JS_TRUE) {
        goto do_return;
    }
    argv[argc+0] = var117;
    if (rval) {
        *rval = var117;
    }
    var111 = JS_TRUE;
    do_return:
    return var111;
}
static JSBool
jjadmgetHeight(JSContext *cx, JSObject *obj, uintN argc, jsval *argv, jsval *rval)
{
    JSObject * var119;
    int var120;
    int var123;
    jsval var124;
    JSBool var118;
    var119 = NULL;
    var120 = 0;
    var123 = 0;
    var124 = JSVAL_NULL;
    var118 = JS_FALSE;
    var119 = obj;
    var123 = argc;
    var120 = jsGetHeight();
    if (JS_NewNumberValue(cx, var120, &var124) != JS_TRUE) {
        goto do_return;
    }
    argv[argc+0] = var124;
    if (rval) {
        *rval = var124;
    }
    var118 = JS_TRUE;
    do_return:
    return var118;
}
static JSBool
jjadmgetFps1000(JSContext *cx, JSObject *obj, uintN argc, jsval *argv, jsval *rval)
{
    JSObject * var126;
    int var127;
    int var130;
    jsval var131;
    JSBool var125;
    var126 = NULL;
    var127 = 0;
    var130 = 0;
    var131 = JSVAL_NULL;
    var125 = JS_FALSE;
    var126 = obj;
    var130 = argc;
    var127 = jsGetFps1000();
    if (JS_NewNumberValue(cx, var127, &var131) != JS_TRUE) {
        goto do_return;
    }
    argv[argc+0] = var131;
    if (rval) {
        *rval = var131;
    }
    var125 = JS_TRUE;
    do_return:
    return var125;
}
static JSBool
jjadmgetVideoCodec(JSContext *cx, JSObject *obj, uintN argc, jsval *argv, jsval *rval)
{
    JSObject * var133;
    char * var134;
    int var137;
    jsval var138;
    JSString * var139;
    jsval var253;
    char * var140;
    jsval var254;
    JSBool var132;
    var133 = NULL;
    var134 = NULL;
    var137 = 0;
    var138 = JSVAL_NULL;
    var139 = NULL;
    var253 = JSVAL_NULL;
    var140 = NULL;
    var254 = JSVAL_NULL;
    var132 = JS_FALSE;
    var133 = obj;
    var137 = argc;
    var134 = jsGetVideoCodec();
    if (var134) {
    var139 = JS_NewStringCopyZ(cx, var134);
    if (!var139) {
        goto do_return;
    }
    var253 = STRING_TO_JSVAL(var139);
    argv[argc+0] = var253;
    } else {
    var140 = "";
    var139 = JS_InternString(cx, var140);
    if (!var139) {
        goto do_return;
    }
    var254 = STRING_TO_JSVAL(var139);
    argv[argc+1] = var254;
    }
    var138 = STRING_TO_JSVAL(var139);
    if (rval) {
        *rval = var138;
    }
    var132 = JS_TRUE;
    do_return:
    return var132;
}
static JSBool
jjadmaudioReset(JSContext *cx, JSObject *obj, uintN argc, jsval *argv, jsval *rval)
{
    JSObject * var142;
    int var143;
    int var146;
    jsval var147;
    JSBool var141;
    var142 = NULL;
    var143 = 0;
    var146 = 0;
    var147 = JSVAL_NULL;
    var141 = JS_FALSE;
    var142 = obj;
    var146 = argc;
    var143 = jsAudioReset();
    if (JS_NewNumberValue(cx, var143, &var147) != JS_TRUE) {
        goto do_return;
    }
    argv[argc+0] = var147;
    if (rval) {
        *rval = var147;
    }
    var141 = JS_TRUE;
    do_return:
    return var141;
}
static JSBool
jjadmaudioMixer(JSContext *cx, JSObject *obj, uintN argc, jsval *argv, jsval *rval)
{
    JSObject * var149;
    int var150;
    int var153;
    char * var154;
    int var155;
    jsval var156;
    JSString * var157;
    jsval var256;
    size_t var158;
    size_t var159;
    int var161;
    jschar * var162;
    jsval var257;
    jsval var163;
    JSBool var148;
    var149 = NULL;
    var150 = 0;
    var153 = 0;
    var154 = NULL;
    var155 = 0;
    var156 = JSVAL_NULL;
    var157 = NULL;
    var256 = JSVAL_NULL;
    var158 = 0;
    var159 = 0;
    var161 = 0;
    var162 = NULL;
    var257 = JSVAL_NULL;
    var163 = JSVAL_NULL;
    var148 = JS_FALSE;
    var149 = obj;
    var153 = argc;
    var155 = 0;
    var155 = var155 < var153;
    if (var155) {
    var156 = argv[0];
    var157 = JS_ValueToString(cx, var156);
    if (!var157) {
        goto do_return;
    }
    var256 = STRING_TO_JSVAL(var157);
    argv[argc+0] = var256;
    var158 = JS_GetStringLength(var157);
    var159 = 1;
    var159 += var158;
#ifdef HAVE_ALLOCA
    if (var159 < jj_alloca_limit) {
        var154 = alloca(var159);
    } else {
#endif
        var154 = malloc(var159);
        if (!var154) {
            goto do_return;
        } else {
            var161 = 1;
        }
#ifdef HAVE_ALLOCA
    }
#endif
    var162 = JS_GetStringChars(var157);
    var257 = STRING_TO_JSVAL(var157);
    argv[argc+1] = var257;
    {
        size_t i;
        for (i = 0; i < var158; ++i) {
            var154[i] = var162[i];
        }
        var154[var158] = '\0';
    }
    }
    var150 = jsAudioMixer(var154);
    if (JS_NewNumberValue(cx, var150, &var163) != JS_TRUE) {
        goto do_return;
    }
    argv[argc+2] = var163;
    if (rval) {
        *rval = var163;
    }
    var148 = JS_TRUE;
    do_return:
    if (var161) {
        free(var154);
        var154 = NULL;
        var161 = 0;
    }
    return var148;
}
static JSBool
jjadmclearVideoFilters(JSContext *cx, JSObject *obj, uintN argc, jsval *argv, jsval *rval)
{
    JSObject * var165;
    int var166;
    int var169;
    jsval var170;
    JSBool var164;
    var165 = NULL;
    var166 = 0;
    var169 = 0;
    var170 = JSVAL_NULL;
    var164 = JS_FALSE;
    var165 = obj;
    var169 = argc;
    var166 = jsClearVideoFilters();
    if (JS_NewNumberValue(cx, var166, &var170) != JS_TRUE) {
        goto do_return;
    }
    argv[argc+0] = var170;
    if (rval) {
        *rval = var170;
    }
    var164 = JS_TRUE;
    do_return:
    return var164;
}
static JSBool
jjadmvideoCodec_ignore(JSContext *cx, JSObject *obj, uintN argc, jsval *argv, jsval *rval)
{
    JSObject * var172;
    int var173;
    int var176;
    char * var177;
    int var178;
    jsval var179;
    JSString * var180;
    jsval var260;
    size_t var181;
    size_t var182;
    int var184;
    jschar * var185;
    jsval var261;
    jsval var186;
    JSBool var171;
    var172 = NULL;
    var173 = 0;
    var176 = 0;
    var177 = NULL;
    var178 = 0;
    var179 = JSVAL_NULL;
    var180 = NULL;
    var260 = JSVAL_NULL;
    var181 = 0;
    var182 = 0;
    var184 = 0;
    var185 = NULL;
    var261 = JSVAL_NULL;
    var186 = JSVAL_NULL;
    var171 = JS_FALSE;
    var172 = obj;
    var176 = argc;
    var178 = 0;
    var178 = var178 < var176;
    if (var178) {
    var179 = argv[0];
    var180 = JS_ValueToString(cx, var179);
    if (!var180) {
        goto do_return;
    }
    var260 = STRING_TO_JSVAL(var180);
    argv[argc+0] = var260;
    var181 = JS_GetStringLength(var180);
    var182 = 1;
    var182 += var181;
#ifdef HAVE_ALLOCA
    if (var182 < jj_alloca_limit) {
        var177 = alloca(var182);
    } else {
#endif
        var177 = malloc(var182);
        if (!var177) {
            goto do_return;
        } else {
            var184 = 1;
        }
#ifdef HAVE_ALLOCA
    }
#endif
    var185 = JS_GetStringChars(var180);
    var261 = STRING_TO_JSVAL(var180);
    argv[argc+1] = var261;
    {
        size_t i;
        for (i = 0; i < var181; ++i) {
            var177[i] = var185[i];
        }
        var177[var181] = '\0';
    }
    }
    var173 = jsVideoCodec(var177);
    if (JS_NewNumberValue(cx, var173, &var186) != JS_TRUE) {
        goto do_return;
    }
    argv[argc+2] = var186;
    if (rval) {
        *rval = var186;
    }
    var171 = JS_TRUE;
    do_return:
    if (var184) {
        free(var177);
        var177 = NULL;
        var184 = 0;
    }
    return var171;
}
static JSBool
jjadmaddVideoFilter_ignore(JSContext *cx, JSObject *obj, uintN argc, jsval *argv, jsval *rval)
{
    JSObject * var188;
    int var189;
    int var192;
    char * var193;
    int var194;
    jsval var195;
    JSString * var196;
    jsval var263;
    size_t var197;
    size_t var198;
    int var200;
    jschar * var201;
    jsval var264;
    jsval var202;
    JSBool var187;
    var188 = NULL;
    var189 = 0;
    var192 = 0;
    var193 = NULL;
    var194 = 0;
    var195 = JSVAL_NULL;
    var196 = NULL;
    var263 = JSVAL_NULL;
    var197 = 0;
    var198 = 0;
    var200 = 0;
    var201 = NULL;
    var264 = JSVAL_NULL;
    var202 = JSVAL_NULL;
    var187 = JS_FALSE;
    var188 = obj;
    var192 = argc;
    var194 = 0;
    var194 = var194 < var192;
    if (var194) {
    var195 = argv[0];
    var196 = JS_ValueToString(cx, var195);
    if (!var196) {
        goto do_return;
    }
    var263 = STRING_TO_JSVAL(var196);
    argv[argc+0] = var263;
    var197 = JS_GetStringLength(var196);
    var198 = 1;
    var198 += var197;
#ifdef HAVE_ALLOCA
    if (var198 < jj_alloca_limit) {
        var193 = alloca(var198);
    } else {
#endif
        var193 = malloc(var198);
        if (!var193) {
            goto do_return;
        } else {
            var200 = 1;
        }
#ifdef HAVE_ALLOCA
    }
#endif
    var201 = JS_GetStringChars(var196);
    var264 = STRING_TO_JSVAL(var196);
    argv[argc+1] = var264;
    {
        size_t i;
        for (i = 0; i < var197; ++i) {
            var193[i] = var201[i];
        }
        var193[var197] = '\0';
    }
    }
    var189 = jsVideoFilter(var193);
    if (JS_NewNumberValue(cx, var189, &var202) != JS_TRUE) {
        goto do_return;
    }
    argv[argc+2] = var202;
    if (rval) {
        *rval = var202;
    }
    var187 = JS_TRUE;
    do_return:
    if (var200) {
        free(var193);
        var193 = NULL;
        var200 = 0;
    }
    return var187;
}
static JSBool
jjadmaudioCodec_ignore(JSContext *cx, JSObject *obj, uintN argc, jsval *argv, jsval *rval)
{
    JSObject * var204;
    int var205;
    int var208;
    char * var209;
    int var210;
    jsval var211;
    JSString * var212;
    jsval var266;
    size_t var213;
    size_t var214;
    int var216;
    jschar * var217;
    jsval var267;
    jsval var218;
    JSBool var203;
    var204 = NULL;
    var205 = 0;
    var208 = 0;
    var209 = NULL;
    var210 = 0;
    var211 = JSVAL_NULL;
    var212 = NULL;
    var266 = JSVAL_NULL;
    var213 = 0;
    var214 = 0;
    var216 = 0;
    var217 = NULL;
    var267 = JSVAL_NULL;
    var218 = JSVAL_NULL;
    var203 = JS_FALSE;
    var204 = obj;
    var208 = argc;
    var210 = 0;
    var210 = var210 < var208;
    if (var210) {
    var211 = argv[0];
    var212 = JS_ValueToString(cx, var211);
    if (!var212) {
        goto do_return;
    }
    var266 = STRING_TO_JSVAL(var212);
    argv[argc+0] = var266;
    var213 = JS_GetStringLength(var212);
    var214 = 1;
    var214 += var213;
#ifdef HAVE_ALLOCA
    if (var214 < jj_alloca_limit) {
        var209 = alloca(var214);
    } else {
#endif
        var209 = malloc(var214);
        if (!var209) {
            goto do_return;
        } else {
            var216 = 1;
        }
#ifdef HAVE_ALLOCA
    }
#endif
    var217 = JS_GetStringChars(var212);
    var267 = STRING_TO_JSVAL(var212);
    argv[argc+1] = var267;
    {
        size_t i;
        for (i = 0; i < var213; ++i) {
            var209[i] = var217[i];
        }
        var209[var213] = '\0';
    }
    }
    var205 = jsAudioCodec(var209);
    if (JS_NewNumberValue(cx, var205, &var218) != JS_TRUE) {
        goto do_return;
    }
    argv[argc+2] = var218;
    if (rval) {
        *rval = var218;
    }
    var203 = JS_TRUE;
    do_return:
    if (var216) {
        free(var209);
        var209 = NULL;
        var216 = 0;
    }
    return var203;
}
static JSBool
jjadmsetContainer_ignore(JSContext *cx, JSObject *obj, uintN argc, jsval *argv, jsval *rval)
{
    JSObject * var220;
    int var221;
    int var224;
    char * var225;
    int var226;
    jsval var227;
    JSString * var228;
    jsval var269;
    size_t var229;
    size_t var230;
    int var232;
    jschar * var233;
    jsval var270;
    jsval var234;
    JSBool var219;
    var220 = NULL;
    var221 = 0;
    var224 = 0;
    var225 = NULL;
    var226 = 0;
    var227 = JSVAL_NULL;
    var228 = NULL;
    var269 = JSVAL_NULL;
    var229 = 0;
    var230 = 0;
    var232 = 0;
    var233 = NULL;
    var270 = JSVAL_NULL;
    var234 = JSVAL_NULL;
    var219 = JS_FALSE;
    var220 = obj;
    var224 = argc;
    var226 = 0;
    var226 = var226 < var224;
    if (var226) {
    var227 = argv[0];
    var228 = JS_ValueToString(cx, var227);
    if (!var228) {
        goto do_return;
    }
    var269 = STRING_TO_JSVAL(var228);
    argv[argc+0] = var269;
    var229 = JS_GetStringLength(var228);
    var230 = 1;
    var230 += var229;
#ifdef HAVE_ALLOCA
    if (var230 < jj_alloca_limit) {
        var225 = alloca(var230);
    } else {
#endif
        var225 = malloc(var230);
        if (!var225) {
            goto do_return;
        } else {
            var232 = 1;
        }
#ifdef HAVE_ALLOCA
    }
#endif
    var233 = JS_GetStringChars(var228);
    var270 = STRING_TO_JSVAL(var228);
    argv[argc+1] = var270;
    {
        size_t i;
        for (i = 0; i < var229; ++i) {
            var225[i] = var233[i];
        }
        var225[var229] = '\0';
    }
    }
    var221 = jsSetContainer(var225);
    if (JS_NewNumberValue(cx, var221, &var234) != JS_TRUE) {
        goto do_return;
    }
    argv[argc+2] = var234;
    if (rval) {
        *rval = var234;
    }
    var219 = JS_TRUE;
    do_return:
    if (var232) {
        free(var225);
        var225 = NULL;
        var232 = 0;
    }
    return var219;
}
static JSBool
jjadm__construct__(JSContext *cx, JSObject *obj, uintN argc, jsval *argv, jsval *rval)
{
    JSObject * var236;
    int var240;
    JSBool var235;
    var236 = NULL;
    var240 = 0;
    var235 = JS_FALSE;
    var236 = obj;
    var240 = argc;
    jsAvidemux();
    var235 = JS_TRUE;
    return var235;
}
static JSPropertySpec jj_static_ps[] = {
    {NULL, 0, 0, NULL, NULL}
};
static JSPropertySpec jj_ps[] = {
    {NULL, 0, 0, NULL, NULL}
};
static JSFunctionSpec jj_static_fs[] = {
    JS_FS_END
};
static JSFunctionSpec jj_fs[] = {
    JS_FS_END
};
static JSPropertySpec jjadm_static_ps[] = {
    {"markerA", 0, 0|JSPROP_ENUMERATE, jjadmmarkerA_get, jjadmmarkerA_set},
    {"markerB", 0, 0|JSPROP_ENUMERATE, jjadmmarkerB_get, jjadmmarkerB_set},
    {"audioResample", 0, 0|JSPROP_ENUMERATE, jjadmaudioResample_get, jjadmaudioResample_set},
    {NULL, 0, 0, NULL, NULL}
};
static JSPropertySpec jjadm_ps[] = {
    {NULL, 0, 0, NULL, NULL}
};
static JSFunctionSpec jjadm_static_fs[] = {
    JS_FS("loadVideo", jjadmloadVideo, 1, 0, 3),
    JS_FS("clearSegments", jjadmclearSegments, 0, 0, 1),
    JS_FS("appendVideo", jjadmappendVideo, 1, 0, 3),
    JS_FS("addSegment", jjadmaddSegment, 3, 0, 1),
    JS_FS("setPostProc", jjadmsetPostProc, 3, 0, 1),
    JS_FS("getWidth", jjadmgetWidth, 0, 0, 1),
    JS_FS("getHeight", jjadmgetHeight, 0, 0, 1),
    JS_FS("getFps1000", jjadmgetFps1000, 0, 0, 1),
    JS_FS("getVideoCodec", jjadmgetVideoCodec, 0, 0, 2),
    JS_FS("audioReset", jjadmaudioReset, 0, 0, 1),
    JS_FS("audioMixer", jjadmaudioMixer, 1, 0, 3),
    JS_FS("clearVideoFilters", jjadmclearVideoFilters, 0, 0, 1),
    JS_FS("videoCodec", jsAdmvideoCodec,  1, 0, 3),
    JS_FS("addVideoFilter", jsAdmaddVideoFilter,  1, 0, 3),
    JS_FS("audioCodec", jsAdmaudioCodec,  1, 0, 3),
    JS_FS("setContainer", jsAdmsetContainer,  1, 0, 3),
    JS_FS_END
};
static JSFunctionSpec jjadm_fs[] = {
    JS_FS_END
};
static JSClass jjadm_class = {
    "adm",
    0,
    JS_PropertyStub,
    JS_PropertyStub,
    JS_PropertyStub,
    JS_PropertyStub,
    JS_EnumerateStub,
    JS_ResolveStub,
    JS_ConvertStub,
    JS_FinalizeStub,
    NULL,
    NULL,
    NULL,
    jjadm__construct__,
    NULL,
    NULL,
    NULL,
    NULL
};
static JSObject *
jjadm_init(JSContext *cx, JSObject *obj)
{
    JSObject *parent_proto, *proto;
    JSClass *class;
    if (!cx || !obj) {
        JS_ReportError(cx, "invalid parameter");
        return NULL;
    }
    if (!JS_EnterLocalRootScope(cx)) {
        JS_ReportError(cx, "JS_EnterLocalRootScope failed");
        return NULL;
    }
    parent_proto = NULL;
    proto = NULL;
    parent_proto = JS_NewObject(cx, NULL, NULL, NULL);
    if (!parent_proto) {
        JS_LeaveLocalRootScope(cx);
        JS_ReportError(cx, "failed to create prototype");
        return NULL;
    }
    class = &jjadm_class;
    proto = JS_InitClass(cx, obj, parent_proto, class, jjadm__construct__, 0, jjadm_ps, jjadm_fs, jjadm_static_ps, jjadm_static_fs);
    if (!proto) {
        JS_LeaveLocalRootScope(cx);
        JS_ReportError(cx, "failed to init class");
        return NULL;
    }
    JS_LeaveLocalRootScope(cx);
    return proto;
}


JSObject *jsAvidemuxInit(JSContext *cx,JSObject *obj)
{
          if (JS_DefineFunctions(cx, obj, jj_static_fs) != JS_TRUE) 
          {
                return NULL;
          }
          return jjadm_init(cx,obj);
}

JSFunctionSpec  *jsGetAdmFunctions(void)
{
        return jjadm_static_fs;
}

