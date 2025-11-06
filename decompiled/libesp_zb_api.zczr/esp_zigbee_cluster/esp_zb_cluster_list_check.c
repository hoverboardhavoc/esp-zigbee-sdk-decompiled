/*
 * Last changed at upstream commit ef60059b4d605d61a0103f81567229692f238007
 * https://github.com/espressif/esp-zigbee-sdk/commit/ef60059b4d605d61a0103f81567229692f238007
 * Upstream date: 2025-11-06 11:58:56 +0800
 * Upstream subject: esp-zigbee-sdk: (79cb709a)
 * Source: libesp_zb_api.zczr -> esp_zigbee_cluster.o -> esp_zb_cluster_list_check
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

ushort esp_zb_cluster_list_check(int param_1,int param_2,uint param_3)

{
  ushort uVar1;
  ushort uVar2;
  
  if (param_1 == 0) {
    uVar2 = 0x102;
  }
  else {
    uVar2 = 0x102;
    if ((param_2 != 0) && (*(int *)(param_2 + 0xc) != 0)) {
      uVar1 = *(ushort *)(*(int *)(param_2 + 0xc) + 10);
      if ((short)param_3 < 0) {
        uVar2 = 0;
        if (param_3 == 0x8000) {
          return (short)~uVar1 >> 0x1f & 0x102;
        }
      }
      else if (uVar1 == param_3) {
        return 0;
      }
    }
  }
  return uVar2;
}

