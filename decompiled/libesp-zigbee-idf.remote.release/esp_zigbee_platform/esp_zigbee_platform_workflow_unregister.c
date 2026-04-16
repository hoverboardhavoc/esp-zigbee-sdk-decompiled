/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-idf.remote.release -> esp_zigbee_platform.o -> esp_zigbee_platform_workflow_unregister
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void esp_zigbee_platform_workflow_unregister(char *name)

{
  esp_zigbee_platform_workflow_t **ppeVar1;
  esp_zigbee_platform_workflow_t *__s1;
  int iVar2;
  esp_zigbee_platform_workflow_t *peVar3;
  
  ppeVar1 = &s_workflow_list;
  peVar3 = s_workflow_list;
  while( true ) {
    if (peVar3 == (esp_zigbee_platform_workflow_t *)0x0) {
      return;
    }
    __s1 = *ppeVar1;
    iVar2 = strncmp(__s1->name,name,0x10);
    if (iVar2 == 0) break;
    peVar3 = __s1->next;
    ppeVar1 = &__s1->next;
  }
  *ppeVar1 = __s1->next;
  free(__s1);
  return;
}

