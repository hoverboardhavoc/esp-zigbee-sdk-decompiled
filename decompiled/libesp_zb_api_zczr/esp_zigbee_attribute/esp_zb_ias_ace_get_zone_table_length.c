/*
 * Last changed at upstream commit 9b2a25d84666d8bc8515f84abcf92271524d2896
 * https://github.com/espressif/esp-zigbee-sdk/commit/9b2a25d84666d8bc8515f84abcf92271524d2896
 * Upstream date: 2024-05-24 08:27:18 +0000
 * Upstream subject: esp-zigbee-lib:(73447d7e)
 * Source: libesp_zb_api_zczr -> esp_zigbee_attribute.o -> esp_zb_ias_ace_get_zone_table_length
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_ias_ace_get_zone_table_length(undefined1 *param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 uVar3;
  
  iVar1 = zb_zcl_get_attr_desc_a(0x501,1,0xeffe);
  if (iVar1 == 0) {
    uVar3 = 0;
    uVar2 = 0x105;
  }
  else {
    uVar2 = 0;
    uVar3 = **(undefined1 **)(iVar1 + 6);
  }
  *param_1 = uVar3;
  return uVar2;
}

