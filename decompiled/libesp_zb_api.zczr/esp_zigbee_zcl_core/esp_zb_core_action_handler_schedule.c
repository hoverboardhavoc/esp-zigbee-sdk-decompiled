/*
 * Last changed at upstream commit d4fdccd9eea771602c7571d5f751435deed089e9
 * https://github.com/espressif/esp-zigbee-sdk/commit/d4fdccd9eea771602c7571d5f751435deed089e9
 * Upstream date: 2025-05-21 11:16:30 +0000
 * Upstream subject: esp-zigbee-sdk: (5d895722)
 * Source: libesp_zb_api.zczr -> esp_zigbee_zcl_core.o -> esp_zb_core_action_handler_schedule
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_core_action_handler_schedule(void)

{
  undefined4 uVar1;
  
  if (zb_core_action_cb != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00010834. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (*zb_core_action_cb)();
    return uVar1;
  }
  return 0;
}

