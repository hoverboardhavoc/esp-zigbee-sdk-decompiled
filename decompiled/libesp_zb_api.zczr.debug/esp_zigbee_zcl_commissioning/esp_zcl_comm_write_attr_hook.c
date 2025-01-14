/*
 * Last changed at upstream commit 5becf8b58fd0c6a13fec507be821364ad0ceba39
 * https://github.com/espressif/esp-zigbee-sdk/commit/5becf8b58fd0c6a13fec507be821364ad0ceba39
 * Upstream date: 2025-01-14 03:03:09 +0000
 * Upstream subject: esp-zigbee-sdk: (acad93d1)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_zcl_commissioning.o -> esp_zcl_comm_write_attr_hook
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void esp_zcl_comm_write_attr_hook(uint param_1,byte *param_2)

{
  if (param_1 == 0x40) {
    DAT_00012291 = *param_2;
    return;
  }
  if (param_1 < 0x41) {
    if (param_1 == 0x20) {
      DAT_00013554 = *param_2;
      return;
    }
    if (param_1 == 0x21) {
      _DAT_00013552 = *(undefined2 *)param_2;
      return;
    }
    return;
  }
  if (param_1 == 0x41) {
    DAT_00012292 = *param_2;
    return;
  }
  if (param_1 == 0x42) {
    _DAT_00012294 = (uint)*param_2;
    return;
  }
  return;
}

