/*
 * Last changed at upstream commit 3128a1de3a8a176dac99e12775a60287e9d10fd7
 * https://github.com/espressif/esp-zigbee-sdk/commit/3128a1de3a8a176dac99e12775a60287e9d10fd7
 * Upstream date: 2024-04-01 17:59:07 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.2(4a0e02cc)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> esp_zb_zcl_delete_privilege_command
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_zcl_delete_privilege_command(uint param_1,uint param_2,uint param_3)

{
  byte *pbVar1;
  byte *pbVar2;
  byte *__ptr;
  undefined4 uVar3;
  
  if (s_zcl_privilege_cluster_list == (byte *)0x0) {
    uVar3 = 0;
  }
  else {
    pbVar2 = (byte *)0x0;
    __ptr = s_zcl_privilege_cluster_list;
    do {
      pbVar1 = *(byte **)(__ptr + 8);
      if (((*__ptr == param_1) && (*(ushort *)(__ptr + 2) == param_2)) &&
         (*(ushort *)(__ptr + 4) == param_3)) {
        if (pbVar2 == (byte *)0x0) {
          s_zcl_privilege_cluster_list = pbVar1;
          free(__ptr);
          __ptr = (byte *)0x0;
        }
        else {
          *(byte **)(pbVar2 + 8) = pbVar1;
          free(__ptr);
          pbVar1 = *(byte **)(pbVar2 + 8);
          __ptr = pbVar2;
        }
      }
      pbVar2 = __ptr;
      __ptr = pbVar1;
    } while (pbVar1 != (byte *)0x0);
    uVar3 = 1;
  }
  return uVar3;
}

