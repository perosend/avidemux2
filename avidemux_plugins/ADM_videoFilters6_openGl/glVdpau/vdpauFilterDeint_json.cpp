// automatically generated by admSerialization.py, do not edit!
#include "ADM_default.h"
#include "ADM_paramList.h"
#include "ADM_coreJson.h"
#include "vdpauFilterDeint.h"
bool  vdpauFilterDeint_jserialize(const char *file, const vdpauFilterDeint *key){
admJson json;
json.addBool("resizeToggle",key->resizeToggle);
json.addUint32("deintMode",key->deintMode);
json.addUint32("targetWidth",key->targetWidth);
json.addUint32("targetHeight",key->targetHeight);
return json.dumpToFile(file);
};
bool  vdpauFilterDeint_jdeserialize(const char *file, const ADM_paramList *tmpl,vdpauFilterDeint *key){
admJsonToCouple json;
CONFcouple *c=json.readFromFile(file);
if(!c) {ADM_error("Cannot read json file");return false;}
bool r= ADM_paramLoadPartial(c,tmpl,key);
delete c;
return r;
};