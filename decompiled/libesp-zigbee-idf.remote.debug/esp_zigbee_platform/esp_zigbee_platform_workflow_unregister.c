/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-idf.remote.debug -> esp_zigbee_platform.o -> esp_zigbee_platform_workflow_unregister
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void esp_zigbee_platform_workflow_unregister(char *name)

{
  esp_zigbee_platform_workflow_t *peVar1;
  esp_zigbee_platform_workflow_t **ppeVar2;
  int iVar3;
  
  ppeVar2 = &s_workflow_list;
  peVar1 = s_workflow_list;
  while( true ) {
    if (peVar1 == (esp_zigbee_platform_workflow_t *)0x0) {
      return;
    }
    peVar1 = *ppeVar2;
    iVar3 = strncmp(peVar1->name,name,0x10);
    if (iVar3 == 0) break;
    ppeVar2 = &peVar1->next;
    peVar1 = peVar1->next;
  }
  *ppeVar2 = peVar1->next;
  peVar1->next = (esp_zigbee_platform_workflow *)0x0;
  free(peVar1);
  return;
}

