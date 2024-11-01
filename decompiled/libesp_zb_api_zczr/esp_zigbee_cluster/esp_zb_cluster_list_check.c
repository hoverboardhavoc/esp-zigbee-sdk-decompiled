/*
 * Last changed at upstream commit b16fd900dd0b442e8e677ff001b10a2e9e95729b
 * https://github.com/espressif/esp-zigbee-sdk/commit/b16fd900dd0b442e8e677ff001b10a2e9e95729b
 * Upstream date: 2024-11-01 15:37:53 +0800
 * Upstream subject: esp-zigbee-lib:(4f5d21fb)
 * Source: libesp_zb_api_zczr -> esp_zigbee_cluster.o -> esp_zb_cluster_list_check
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_cluster_list_check(int param_1,int param_2,uint param_3)

{
  ushort uVar1;
  
  if (param_1 != 0) {
    if (param_2 == 0) {
      return 0x102;
    }
    if (*(int *)(param_2 + 0xc) == 0) {
      return 0x102;
    }
    uVar1 = *(ushort *)(*(int *)(param_2 + 0xc) + 10);
    if (-1 < (short)param_3) {
      if (uVar1 != param_3) {
        return 0x102;
      }
      return 0;
    }
    if (param_3 != 0x8000) {
      return 0;
    }
    if ((short)uVar1 < 0) {
      return 0;
    }
  }
  return 0x102;
}

