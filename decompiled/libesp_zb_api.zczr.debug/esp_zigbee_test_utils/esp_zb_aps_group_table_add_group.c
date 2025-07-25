/*
 * Last changed at upstream commit 232ecc4094b2fa86cc70f7e95820b15daf5d0bff
 * https://github.com/espressif/esp-zigbee-sdk/commit/232ecc4094b2fa86cc70f7e95820b15daf5d0bff
 * Upstream date: 2025-07-25 14:23:12 +0800
 * Upstream subject: esp-zigbee-sdk: (5de57b2b)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_test_utils.o -> esp_zb_aps_group_table_add_group
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int esp_zb_aps_group_table_add_group(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((param_1 - 1U & 0xffff) < 0xfff7) {
    if (param_2 == 0) {
      uVar2 = esp_log_timestamp();
      esp_log_write(1,0x10000,&_LC5,uVar2,0x10000,"esp_zb_aps_group_table_add_group",0x56);
      iVar1 = 0x102;
    }
    else {
      iVar1 = zb_aps_group_table_add(&g_zb,param_1);
      if (iVar1 != 0) {
        if (iVar1 == -0x4ae) {
          iVar1 = 0x101;
        }
        else {
          iVar1 = -1;
        }
      }
    }
  }
  else {
    uVar2 = esp_log_timestamp(param_2);
    esp_log_write(1,0x10000,&_LC4,uVar2,0x10000,"esp_zb_aps_group_table_add_group",0x55);
    iVar1 = 0x102;
  }
  return iVar1;
}

