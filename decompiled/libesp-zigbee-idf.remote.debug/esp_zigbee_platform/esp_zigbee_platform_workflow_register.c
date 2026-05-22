/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-idf.remote.debug -> esp_zigbee_platform.o -> esp_zigbee_platform_workflow_register
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
  esp_zigbee_platform_workflow_t *peVar1;
  esp_zigbee_platform_workflow *__dest;
  esp_zigbee_platform_workflow_t **ppeVar2;
  
  __dest = (esp_zigbee_platform_workflow *)malloc(0x20);
  if (__dest == (esp_zigbee_platform_workflow *)0x0) {
    esp_log(0x11,"ESP-ZIGBEE",0x10000,"esp_zigbee_platform_workflow_register",0x1a);
    update_func = (esp_zigbee_platform_update_func)0x101;
  }
  else if ((update_func == (esp_zigbee_platform_update_func)0x0) ||
          (process_func == (esp_zigbee_platform_process_func)0x0)) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/platform_esp/esp-zigbee/platform/esp_zigbee_platform.c"
                  ,0x1e,"esp_zigbee_platform_workflow_register",
                  "((update_func && process_func) && \"workflow functions couldn\'t be NULL\")");
_L0:
    free(__dest);
  }
  else {
    strncpy((char *)__dest,name,0x10);
    __dest->name[0x10] = '\0';
    __dest->update_func = update_func;
    __dest->process_func = process_func;
    __dest->next = (esp_zigbee_platform_workflow *)0x0;
    ppeVar2 = &s_workflow_list;
    for (peVar1 = s_workflow_list; peVar1 != (esp_zigbee_platform_workflow_t *)0x0;
        peVar1 = peVar1->next) {
      peVar1 = *ppeVar2;
      update_func = (esp_zigbee_platform_update_func)strncmp(peVar1->name,name,0x10);
      if (update_func == (esp_zigbee_platform_update_func)0x0) goto _L0;
      ppeVar2 = &peVar1->next;
    }
    *ppeVar2 = __dest;
    update_func = (esp_zigbee_platform_update_func)0x0;
  }
  return (esp_err_t)update_func;
}

