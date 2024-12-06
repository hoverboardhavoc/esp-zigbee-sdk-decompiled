/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
 * Source: libesp_zb_api.zczr -> esp_zigbee_zcl_commissioning.o -> esp_zcl_commissioning_sync_with_attributes
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void esp_zcl_commissioning_sync_with_attributes(void)

{
  DAT_00010e01 = (char)_DAT_0001255a;
  DAT_00010e02 = (char)((ushort)_DAT_0001255a >> 8);
  DAT_00010e00 = DAT_0001255c;
  DAT_00010e0a = DAT_00011295;
  DAT_00010e0b = DAT_00011296;
  DAT_00010e0c = (char)_DAT_00011298;
  return;
}

