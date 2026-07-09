/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-idf.remote.debug -> esp_zigbee_platform.o -> esp_zigbee_platform_workflow_register
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int esp_zigbee_platform_workflow_register(char *param_1,int param_2,int param_3)

{
  char *__s1;
  char *__dest;
  int iVar1;
  char *pcVar2;
  
  __dest = (char *)malloc(0x20);
  if (__dest == (char *)0x0) {
    esp_log(0x11,"ESP-ZIGBEE",0x10000,"esp_zigbee_platform_workflow_register",0x1a);
    param_2 = 0x101;
  }
  else if ((param_2 == 0) || (param_3 == 0)) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/platform_esp/esp-zigbee/platform/esp_zigbee_platform.c"
                  ,0x1e,"esp_zigbee_platform_workflow_register",
                  "((update_func && process_func) && \"workflow functions couldn\'t be NULL\")");
_L0:
    free(__dest);
  }
  else {
    strncpy(__dest,param_1,0x10);
    __dest[0x10] = '\0';
    *(int *)(__dest + 0x14) = param_2;
    *(int *)(__dest + 0x18) = param_3;
    __dest[0x1c] = '\0';
    __dest[0x1d] = '\0';
    __dest[0x1e] = '\0';
    __dest[0x1f] = '\0';
    pcVar2 = (char *)&s_workflow_list;
    iVar1 = s_workflow_list;
    while (iVar1 != 0) {
      __s1 = *(char **)pcVar2;
      param_2 = strncmp(__s1,param_1,0x10);
      if (param_2 == 0) goto _L0;
      pcVar2 = __s1 + 0x1c;
      iVar1 = *(int *)(__s1 + 0x1c);
    }
    *(char **)pcVar2 = __dest;
    param_2 = 0;
  }
  return param_2;
}

