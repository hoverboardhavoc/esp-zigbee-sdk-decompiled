/*
 * Last changed at upstream commit e28462af08968da8dbda59a317df742f0109ee5f
 * https://github.com/espressif/esp-zigbee-sdk/commit/e28462af08968da8dbda59a317df742f0109ee5f
 * Upstream date: 2024-04-12 14:44:19 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.3(042315bf)
 * Source: libesp_zb_api_zczr -> esp_zigbee_zcl_thermostat.o -> zcl_thermostat_value_cb_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zcl_thermostat_value_cb_handler(void)

{
  int iVar1;
  undefined4 local_20;
  undefined1 uStack_1c;
  undefined2 uStack_1a;
  undefined1 uStack_18;
  undefined2 uStack_16;
  undefined2 uStack_14;
  
  iVar1 = zb_buf_get_tail_func(0x38);
  uStack_1c = *(undefined1 *)(iVar1 + 4);
  local_20 = 0;
  uStack_1a = 0x201;
  uStack_18 = *(undefined1 *)(iVar1 + 0xc);
  uStack_16 = *(undefined2 *)(iVar1 + 0xe);
  uStack_14 = *(undefined2 *)(iVar1 + 0x10);
  esp_zb_core_action_handler_schedule(7,&local_20);
  esp_err_to_zb_ret();
  return;
}

