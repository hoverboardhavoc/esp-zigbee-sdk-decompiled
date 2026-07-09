/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-idf.remote.debug -> esp_zigbee_platform.o -> esp_zigbee_platform_workflow_unregister
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zigbee_platform_workflow_unregister(char *param_1)

{
  char *__s1;
  char *pcVar1;
  int iVar2;
  
  pcVar1 = (char *)&s_workflow_list;
  iVar2 = s_workflow_list;
  while( true ) {
    if (iVar2 == 0) {
      return;
    }
    __s1 = *(char **)pcVar1;
    iVar2 = strncmp(__s1,param_1,0x10);
    if (iVar2 == 0) break;
    pcVar1 = __s1 + 0x1c;
    iVar2 = *(int *)(__s1 + 0x1c);
  }
  *(undefined4 *)pcVar1 = *(undefined4 *)(__s1 + 0x1c);
  __s1[0x1c] = '\0';
  __s1[0x1d] = '\0';
  __s1[0x1e] = '\0';
  __s1[0x1f] = '\0';
  free(__s1);
  return;
}

