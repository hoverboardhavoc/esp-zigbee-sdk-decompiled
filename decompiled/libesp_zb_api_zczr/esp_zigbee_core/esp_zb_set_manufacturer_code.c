/*
 * Last changed at upstream commit 9e7fde9a71fb6810604eb3f5a1a644975d98cdc9
 * https://github.com/espressif/esp-zigbee-sdk/commit/9e7fde9a71fb6810604eb3f5a1a644975d98cdc9
 * Upstream date: 2024-01-12 14:14:49 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.0.8(0e41638c)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> esp_zb_set_manufacturer_code
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_set_manufacturer_code(void)

{
  int iVar1;
  undefined2 auStack_14 [8];
  
  iVar1 = zb_production_configuration_check_presence();
  if (iVar1 != 0) {
    zb_production_cfg_read(auStack_14,2,0xc0);
    zb_set_node_descriptor_manufacturer_code_req(auStack_14[0],0);
  }
  return;
}

