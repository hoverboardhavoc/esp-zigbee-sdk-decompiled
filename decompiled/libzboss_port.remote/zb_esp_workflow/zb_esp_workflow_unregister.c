/*
 * Last changed at upstream commit e883f431f54d7744605c05ac3bc92898d04315c0
 * https://github.com/espressif/esp-zigbee-sdk/commit/e883f431f54d7744605c05ac3bc92898d04315c0
 * Upstream date: 2025-02-14 17:01:07 +0800
 * Upstream subject: esp-zigbee-sdk: (f9a23626)
 * Source: libzboss_port.remote -> zb_esp_workflow.o -> zb_esp_workflow_unregister
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zb_esp_workflow_unregister(char *param_1)

{
  char *__s1;
  size_t __n;
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  
  pcVar2 = s_workflow_list;
  __s1 = (char *)0x0;
  do {
    pcVar3 = __s1;
    __s1 = pcVar2;
    if (__s1 == (char *)0x0) {
      return;
    }
    __n = strnlen(param_1,0x10);
    iVar1 = strncmp(__s1,param_1,__n);
    pcVar2 = *(char **)(__s1 + 0x18);
  } while (iVar1 != 0);
  if (pcVar3 != (char *)0x0) {
    *(char **)(pcVar3 + 0x18) = pcVar2;
    pcVar2 = s_workflow_list;
  }
  s_workflow_list = pcVar2;
  free(__s1);
  return;
}

