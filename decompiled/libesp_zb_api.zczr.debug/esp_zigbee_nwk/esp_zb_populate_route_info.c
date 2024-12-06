/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_nwk.o -> esp_zb_populate_route_info
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_populate_route_info(undefined2 *param_1,byte *param_2)

{
  *param_1 = *(undefined2 *)(param_2 + 3);
  zb_address_short_by_ref(param_1 + 1,param_2[2]);
  *(byte *)(param_1 + 3) = (byte)((param_2[1] & 0xf) << 2) | *param_2 >> 6;
  param_1[2] = param_1[2] & 0xfff8 | *param_2 >> 1 & 3;
  param_1[2] = (ushort)((*param_2 >> 3 & 1) << 3) | param_1[2] & 0xfff7;
  param_1[2] = (ushort)((*param_2 >> 4 & 1) << 4) | param_1[2] & 0xffef;
  param_1[2] = (ushort)((*param_2 >> 5 & 1) << 5) | param_1[2] & 0xffdf;
  return;
}

