/*
 * Last changed at upstream commit 438301125bdfa70150622d905094f79315456774
 * https://github.com/espressif/esp-zigbee-sdk/commit/438301125bdfa70150622d905094f79315456774
 * Upstream date: 2024-04-26 19:22:10 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.3.0(a824e1a1)
 * Source: libesp_zb_api_zczr -> esp_zigbee_zcl_commissioning.o -> esp_zcl_commissioning_sync_with_attributes
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void esp_zcl_commissioning_sync_with_attributes(void)

{
  DAT_00010de1 = (char)_DAT_0001255a;
  DAT_00010de2 = (char)((ushort)_DAT_0001255a >> 8);
  DAT_00010de0 = DAT_0001255c;
  DAT_00010dea = DAT_00011295;
  DAT_00010deb = DAT_00011296;
  DAT_00010dec = (char)_DAT_00011298;
  return;
}

