/*
 * Last changed at upstream commit eec5098a388a0960da2662a0145e34c21f0838a0
 * https://github.com/espressif/esp-zigbee-sdk/commit/eec5098a388a0960da2662a0145e34c21f0838a0
 * Upstream date: 2024-08-27 08:46:30 +0000
 * Upstream subject: esp-zigbee-lib:(6bd34178)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_core.o -> esp_zb_stack_main_loop_iteration
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_stack_main_loop_iteration(void)

{
  int iVar1;
  
  iVar1 = esp_zb_lock_acquire(0xffffffff);
  if (iVar1 != 0) {
    zboss_main_loop_iteration();
    esp_zb_lock_release();
  }
  return;
}

