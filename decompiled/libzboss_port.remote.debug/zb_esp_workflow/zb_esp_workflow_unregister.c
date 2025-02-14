/*
 * Last changed at upstream commit e883f431f54d7744605c05ac3bc92898d04315c0
 * https://github.com/espressif/esp-zigbee-sdk/commit/e883f431f54d7744605c05ac3bc92898d04315c0
 * Upstream date: 2025-02-14 17:01:07 +0800
 * Upstream subject: esp-zigbee-sdk: (f9a23626)
 * Source: libzboss_port.remote.debug -> zb_esp_workflow.o -> zb_esp_workflow_unregister
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zb_esp_workflow_unregister(char *param_1)

{
  char *pcVar1;
  char *__s1;
  size_t __n;
  int iVar2;
  char *pcVar3;
  
  pcVar1 = s_workflow_list;
  pcVar3 = (char *)0x0;
  while( true ) {
    __s1 = pcVar1;
    if (__s1 == (char *)0x0) {
      return;
    }
    __n = strnlen(param_1,0x10);
    iVar2 = strncmp(__s1,param_1,__n);
    if (iVar2 == 0) break;
    pcVar1 = *(char **)(__s1 + 0x18);
    pcVar3 = __s1;
  }
  if (pcVar3 == (char *)0x0) {
    s_workflow_list = *(char **)(__s1 + 0x18);
  }
  else {
    *(undefined4 *)(pcVar3 + 0x18) = *(undefined4 *)(__s1 + 0x18);
  }
  free(__s1);
  return;
}

