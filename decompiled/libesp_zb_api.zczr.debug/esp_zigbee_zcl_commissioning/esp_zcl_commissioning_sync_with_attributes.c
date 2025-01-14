/*
 * Last changed at upstream commit 5becf8b58fd0c6a13fec507be821364ad0ceba39
 * https://github.com/espressif/esp-zigbee-sdk/commit/5becf8b58fd0c6a13fec507be821364ad0ceba39
 * Upstream date: 2025-01-14 03:03:09 +0000
 * Upstream subject: esp-zigbee-sdk: (acad93d1)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_zcl_commissioning.o -> esp_zcl_commissioning_sync_with_attributes
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void esp_zcl_commissioning_sync_with_attributes(void)

{
  DAT_000117e8 = DAT_00013554;
  DAT_000117e9 = (char)_DAT_00013552;
  DAT_000117ea = (char)((ushort)_DAT_00013552 >> 8);
  DAT_000117f2 = DAT_00012291;
  DAT_000117f3 = DAT_00012292;
  DAT_000117f4 = (char)_DAT_00012294;
  return;
}

