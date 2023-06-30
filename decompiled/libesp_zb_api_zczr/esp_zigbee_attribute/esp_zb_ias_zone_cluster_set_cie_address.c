/*
 * Last changed at upstream commit e81a64f4a72a1b96e84882b938e8d601ccb424df
 * https://github.com/espressif/esp-zigbee-sdk/commit/e81a64f4a72a1b96e84882b938e8d601ccb424df
 * Upstream date: 2023-06-30 20:22:10 +0800
 * Upstream subject: esp-zigbee-sdk: release esp-zigbee-sdk v0.7.0(8b8bde0)
 * Source: libesp_zb_api_zczr -> esp_zigbee_attribute.o -> esp_zb_ias_zone_cluster_set_cie_address
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int esp_zb_ias_zone_cluster_set_cie_address(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined1 uStack_13;
  undefined2 auStack_12 [3];
  
  auStack_12[0] = zb_address_short_by_ieee(param_2);
  uStack_13 = 1;
  iVar1 = esp_zb_zcl_set_attribute_val(param_1,0x500,1,0xe002,auStack_12,0);
  if (iVar1 == 0) {
    iVar1 = esp_zb_zcl_set_attribute_val(param_1,0x500,1,0x10,param_2,0);
    if (iVar1 == 0) {
      iVar1 = esp_zb_zcl_set_attribute_val(param_1,0x500,1,0xe000,&uStack_13,0);
      if (iVar1 != 0) {
        iVar1 = -1;
      }
    }
    else {
      iVar1 = -1;
    }
  }
  else {
    iVar1 = -1;
  }
  return iVar1;
}

