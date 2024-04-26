/*
 * Last changed at upstream commit 438301125bdfa70150622d905094f79315456774
 * https://github.com/espressif/esp-zigbee-sdk/commit/438301125bdfa70150622d905094f79315456774
 * Upstream date: 2024-04-26 19:22:10 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.3.0(a824e1a1)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_zcl_commissioning.o -> esp_zcl_commissioning_sync_with_attributes
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void esp_zcl_commissioning_sync_with_attributes(void)

{
  DAT_000117d0 = DAT_0001355c;
  DAT_000117d1 = (char)_DAT_0001355a;
  DAT_000117d2 = (char)((ushort)_DAT_0001355a >> 8);
  DAT_000117da = DAT_00012295;
  DAT_000117db = DAT_00012296;
  DAT_000117dc = (char)_DAT_00012298;
  return;
}

