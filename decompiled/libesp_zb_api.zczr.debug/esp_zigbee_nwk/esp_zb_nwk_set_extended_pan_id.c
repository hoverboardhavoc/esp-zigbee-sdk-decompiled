/*
 * Last changed at upstream commit ef60059b4d605d61a0103f81567229692f238007
 * https://github.com/espressif/esp-zigbee-sdk/commit/ef60059b4d605d61a0103f81567229692f238007
 * Upstream date: 2025-11-06 11:58:56 +0800
 * Upstream subject: esp-zigbee-sdk: (79cb709a)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_nwk.o -> esp_zb_nwk_set_extended_pan_id
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_nwk_set_extended_pan_id(undefined1 *param_1)

{
  DAT_00011230 = *param_1;
  DAT_00011231 = param_1[1];
  DAT_00011232 = param_1[2];
  DAT_00011233 = param_1[3];
  DAT_00011234 = param_1[4];
  DAT_00011235 = param_1[5];
  DAT_00011236 = param_1[6];
  DAT_00011237 = param_1[7];
  return;
}

