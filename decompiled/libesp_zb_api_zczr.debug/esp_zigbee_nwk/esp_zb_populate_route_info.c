/*
 * Last changed at upstream commit 280ac146dc8285567eab4df113b3f6356493fe0b
 * https://github.com/espressif/esp-zigbee-sdk/commit/280ac146dc8285567eab4df113b3f6356493fe0b
 * Upstream date: 2024-07-19 11:49:15 +0800
 * Upstream subject: esp-zigbee-lib:(94bd7a1a)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_nwk.o -> esp_zb_populate_route_info
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

