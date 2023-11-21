/*
 * Last changed at upstream commit 6663e9a47e70aeb89bdde3d1385b4fa8af6242fa
 * https://github.com/espressif/esp-zigbee-sdk/commit/6663e9a47e70aeb89bdde3d1385b4fa8af6242fa
 * Upstream date: 2023-11-21 18:28:11 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.0.4(be3a8a97)
 * Source: libesp_zb_api_zczr -> esp_zigbee_touchlink.o -> esp_zb_touchlink_clear_factory_new
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_touchlink_clear_factory_new(void)

{
  int iVar1;
  
  iVar1 = zb_zll_get_device_info();
  *(byte *)(iVar1 + 1) = *(byte *)(iVar1 + 1) & 0xfe;
  return;
}

