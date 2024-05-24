/*
 * Last changed at upstream commit 9b2a25d84666d8bc8515f84abcf92271524d2896
 * https://github.com/espressif/esp-zigbee-sdk/commit/9b2a25d84666d8bc8515f84abcf92271524d2896
 * Upstream date: 2024-05-24 08:27:18 +0000
 * Upstream subject: esp-zigbee-lib:(73447d7e)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_nwk.o -> esp_zb_set_route_info
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_set_route_info(undefined2 *param_1,byte *param_2)

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

