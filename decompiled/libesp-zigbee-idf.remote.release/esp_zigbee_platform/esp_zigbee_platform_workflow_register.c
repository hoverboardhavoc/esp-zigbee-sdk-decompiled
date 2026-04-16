/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-idf.remote.release -> esp_zigbee_platform.o -> esp_zigbee_platform_workflow_register
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

esp_err_t esp_zigbee_platform_workflow_register
                    (char *name,esp_zigbee_platform_update_func update_func,
                    esp_zigbee_platform_process_func process_func)

{
  esp_zigbee_platform_workflow_t *__dest;
  int iVar1;
  esp_err_t eVar2;
  esp_zigbee_platform_workflow_t **ppeVar3;
  esp_zigbee_platform_workflow_t *peVar4;
  
  __dest = (esp_zigbee_platform_workflow_t *)malloc(0x20);
  if (__dest == (esp_zigbee_platform_workflow_t *)0x0) {
    eVar2 = 0x101;
  }
  else {
    if ((update_func == (esp_zigbee_platform_update_func)0x0) ||
       (process_func == (esp_zigbee_platform_process_func)0x0)) {
      __dest = (esp_zigbee_platform_workflow_t *)__assert_func(0,0,0,0);
    }
    strncpy(__dest->name,name,0x10);
    peVar4 = s_workflow_list;
    __dest->name[0x10] = '\0';
    __dest->update_func = update_func;
    __dest->process_func = process_func;
    __dest->next = (esp_zigbee_platform_workflow *)0x0;
    ppeVar3 = &s_workflow_list;
    for (; peVar4 != (esp_zigbee_platform_workflow_t *)0x0; peVar4 = peVar4->next) {
      peVar4 = *ppeVar3;
      iVar1 = strncmp(peVar4->name,name,0x10);
      if (iVar1 == 0) {
        free(__dest);
        goto _L0;
      }
      ppeVar3 = &peVar4->next;
    }
    *ppeVar3 = __dest;
_L0:
    eVar2 = 0;
  }
  return eVar2;
}

