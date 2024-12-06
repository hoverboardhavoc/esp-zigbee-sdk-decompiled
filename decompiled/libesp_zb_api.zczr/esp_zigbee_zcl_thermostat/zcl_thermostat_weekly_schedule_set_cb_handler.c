/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
 * Source: libesp_zb_api.zczr -> esp_zigbee_zcl_thermostat.o -> zcl_thermostat_weekly_schedule_set_cb_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zcl_thermostat_weekly_schedule_set_cb_handler(int param_1)

{
  int iVar1;
  undefined4 uStack_24;
  ushort uStack_20;
  undefined2 uStack_1e;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  if (param_1 == 0) {
    zb_assert(0x10000,0x50);
  }
  iVar1 = zb_buf_get_tail_func(0x38);
  uStack_24 = 0;
  uStack_1c = 0;
  uStack_18 = 0;
  uStack_14 = 0;
  _uStack_20 = CONCAT22(0x201,(ushort)*(byte *)(iVar1 + 4));
  uStack_1c = zb_ret_to_esp_err(*(undefined4 *)(iVar1 + 8));
  uStack_18 = CONCAT22(*(undefined2 *)(iVar1 + 0x11),*(undefined2 *)(iVar1 + 0xd));
  uStack_14 = *(undefined4 *)(iVar1 + 0x13);
  esp_zb_core_action_handler_schedule(0x32,&uStack_24);
  esp_err_to_zb_ret();
  return;
}

