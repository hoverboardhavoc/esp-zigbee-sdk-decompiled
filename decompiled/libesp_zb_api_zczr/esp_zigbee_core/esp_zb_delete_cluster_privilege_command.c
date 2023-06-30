/*
 * Last changed at upstream commit e81a64f4a72a1b96e84882b938e8d601ccb424df
 * https://github.com/espressif/esp-zigbee-sdk/commit/e81a64f4a72a1b96e84882b938e8d601ccb424df
 * Upstream date: 2023-06-30 20:22:10 +0800
 * Upstream subject: esp-zigbee-sdk: release esp-zigbee-sdk v0.7.0(8b8bde0)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> esp_zb_delete_cluster_privilege_command
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_delete_cluster_privilege_command(uint param_1,uint param_2,uint param_3)

{
  byte *pbVar1;
  byte *__ptr;
  undefined4 uVar2;
  byte *pbVar3;
  
  if (s_zcl_privilege_cluster_list == (byte *)0x0) {
    uVar2 = 0;
  }
  else {
    pbVar1 = (byte *)0x0;
    __ptr = s_zcl_privilege_cluster_list;
    while (__ptr != (byte *)0x0) {
      if (((*__ptr == param_1) && (*(ushort *)(__ptr + 2) == param_2)) &&
         (*(ushort *)(__ptr + 4) == param_3)) {
        if (pbVar1 == (byte *)0x0) {
          pbVar3 = *(byte **)(__ptr + 0xc);
          s_zcl_privilege_cluster_list = pbVar3;
          free(__ptr);
          __ptr = pbVar3;
        }
        else {
          *(undefined4 *)(pbVar1 + 0xc) = *(undefined4 *)(__ptr + 0xc);
          free(__ptr);
          __ptr = *(byte **)(pbVar1 + 0xc);
        }
      }
      else {
        pbVar1 = __ptr;
        __ptr = *(byte **)(__ptr + 0xc);
      }
    }
    uVar2 = 1;
  }
  return uVar2;
}

