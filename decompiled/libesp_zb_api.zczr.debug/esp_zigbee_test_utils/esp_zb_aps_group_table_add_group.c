/*
 * Last changed at upstream commit ef60059b4d605d61a0103f81567229692f238007
 * https://github.com/espressif/esp-zigbee-sdk/commit/ef60059b4d605d61a0103f81567229692f238007
 * Upstream date: 2025-11-06 11:58:56 +0800
 * Upstream subject: esp-zigbee-sdk: (79cb709a)
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
      esp_log(1,0x10000,"E (%lu) %s: %s(%d): Invalid endpoint\n",uVar2,0x10000,
              "esp_zb_aps_group_table_add_group",0x56);
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
    esp_log(1,0x10000,"E (%lu) %s: %s(%d): Invalid groupid\n",uVar2,0x10000,
            "esp_zb_aps_group_table_add_group",0x55);
    iVar1 = 0x102;
  }
  return iVar1;
}

