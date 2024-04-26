/*
 * Last changed at upstream commit 438301125bdfa70150622d905094f79315456774
 * https://github.com/espressif/esp-zigbee-sdk/commit/438301125bdfa70150622d905094f79315456774
 * Upstream date: 2024-04-26 19:22:10 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.3.0(a824e1a1)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> esp_zb_core_action_handler_schedule
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_core_action_handler_schedule(void)

{
  undefined4 uVar1;
  
  if (zb_core_action_cb != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00010942. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (*zb_core_action_cb)();
    return uVar1;
  }
  return 0;
}

