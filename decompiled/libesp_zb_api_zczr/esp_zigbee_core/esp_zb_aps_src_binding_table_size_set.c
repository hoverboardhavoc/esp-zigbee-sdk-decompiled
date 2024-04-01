/*
 * Last changed at upstream commit 3128a1de3a8a176dac99e12775a60287e9d10fd7
 * https://github.com/espressif/esp-zigbee-sdk/commit/3128a1de3a8a176dac99e12775a60287e9d10fd7
 * Upstream date: 2024-04-01 17:59:07 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.2(4a0e02cc)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> esp_zb_aps_src_binding_table_size_set
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int esp_zb_aps_src_binding_table_size_set(void)

{
  int iVar1;
  
  iVar1 = zb_config_src_binding_table_size();
  if (iVar1 != 0) {
    if (iVar1 == -0x1c) {
      return 0x105;
    }
    if (iVar1 == -0x16) {
      return 0x101;
    }
    if ((iVar1 + 0xdU < 4) || (iVar1 == -0xf)) {
      return 0x102;
    }
    if (iVar1 == -6) {
      return 0x104;
    }
    if (iVar1 != -0x1e) {
      if (iVar1 == -2) {
        return 0x10c;
      }
      iVar1 = -1;
    }
  }
  return iVar1;
}

