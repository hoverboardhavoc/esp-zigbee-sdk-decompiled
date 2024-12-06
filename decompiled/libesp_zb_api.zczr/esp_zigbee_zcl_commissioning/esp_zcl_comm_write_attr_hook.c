/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
 * Source: libesp_zb_api.zczr -> esp_zigbee_zcl_commissioning.o -> esp_zcl_comm_write_attr_hook
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void esp_zcl_comm_write_attr_hook(uint param_1,byte *param_2)

{
  if (param_1 == 0x40) {
    _g_zb = CONCAT31(g_zb_1,*param_2);
    return;
  }
  if (0x40 < param_1) {
    if (param_1 == 0x41) {
      _g_zb = CONCAT31(g_zb_1,*param_2);
      return;
    }
    if (param_1 != 0x42) {
      return;
    }
    _g_zb = (uint)*param_2;
    return;
  }
  if (param_1 == 0x20) {
    _g_zb = CONCAT31(g_zb_1,*param_2);
    return;
  }
  if (param_1 != 0x21) {
    return;
  }
  _g_zb = CONCAT22(g_zb_1._1_2_,*(undefined2 *)param_2);
  return;
}

