/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-idf.remote.release -> esp_zigbee_platform.o -> esp_zigbee_platform_process
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

esp_err_t esp_zigbee_platform_process(esp_zigbee_mainloop_context_t *ctx)

{
  esp_zigbee_platform_workflow_t *peVar1;
  esp_err_t eVar2;
  
  peVar1 = s_workflow_list;
  while( true ) {
    if (peVar1 == (esp_zigbee_platform_workflow_t *)0x0) {
      return 0;
    }
    eVar2 = (*peVar1->process_func)(ctx);
    if (eVar2 != 0) break;
    peVar1 = peVar1->next;
  }
  return eVar2;
}

