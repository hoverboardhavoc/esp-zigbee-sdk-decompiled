/*
 * Last changed at upstream commit e883f431f54d7744605c05ac3bc92898d04315c0
 * https://github.com/espressif/esp-zigbee-sdk/commit/e883f431f54d7744605c05ac3bc92898d04315c0
 * Upstream date: 2025-02-14 17:01:07 +0800
 * Upstream subject: esp-zigbee-sdk: (f9a23626)
 * Source: libzboss_port.remote -> zb_esp_workflow.o -> zb_esp_workflow_register
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zb_esp_workflow_register(undefined4 param_1,undefined4 param_2,char *param_3)

{
  size_t sVar1;
  char *__dest;
  int iVar2;
  undefined4 uVar3;
  char *pcVar4;
  char *__s1;
  
  sVar1 = strnlen(param_3,0x10);
  __s1 = s_workflow_list;
  __dest = (char *)malloc(0x1c);
  if (__dest == (char *)0x0) {
    uVar3 = 0x101;
  }
  else {
    strncpy(__dest,param_3,sVar1 & 0xff);
    *(undefined4 *)(__dest + 0x10) = param_1;
    *(undefined4 *)(__dest + 0x14) = param_2;
    __dest[0x18] = '\0';
    __dest[0x19] = '\0';
    __dest[0x1a] = '\0';
    __dest[0x1b] = '\0';
    pcVar4 = (char *)0x0;
    for (; __s1 != (char *)0x0; __s1 = *(char **)(__s1 + 0x18)) {
      iVar2 = strncmp(__s1,param_3,sVar1 & 0xff);
      if (iVar2 == 0) {
        free(__dest);
        __dest = s_workflow_list;
        goto _L0;
      }
      pcVar4 = __s1;
    }
    if (pcVar4 != (char *)0x0) {
      *(char **)(pcVar4 + 0x18) = __dest;
      __dest = s_workflow_list;
    }
_L0:
    s_workflow_list = __dest;
    uVar3 = 0;
  }
  return uVar3;
}

