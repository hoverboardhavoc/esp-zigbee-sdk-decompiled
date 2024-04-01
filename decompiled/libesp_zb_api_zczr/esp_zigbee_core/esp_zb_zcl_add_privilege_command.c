/*
 * Last changed at upstream commit 3128a1de3a8a176dac99e12775a60287e9d10fd7
 * https://github.com/espressif/esp-zigbee-sdk/commit/3128a1de3a8a176dac99e12775a60287e9d10fd7
 * Upstream date: 2024-04-01 17:59:07 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.2(4a0e02cc)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> esp_zb_zcl_add_privilege_command
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_zcl_add_privilege_command(uint param_1,uint param_2,uint param_3)

{
  byte *pbVar1;
  byte *pbVar2;
  undefined4 uVar3;
  
  pbVar2 = s_zcl_privilege_cluster_list;
  pbVar1 = s_zcl_privilege_cluster_list;
  if (s_zcl_privilege_cluster_list != (byte *)0x0) {
    do {
      pbVar1 = pbVar2;
      if (((*pbVar1 == param_1) && (*(ushort *)(pbVar1 + 2) == param_2)) &&
         (pbVar2 = s_zcl_privilege_cluster_list, *(ushort *)(pbVar1 + 4) == param_3)) goto _L0;
      pbVar2 = *(byte **)(pbVar1 + 8);
    } while (*(byte **)(pbVar1 + 8) != (byte *)0x0);
  }
  pbVar2 = (byte *)malloc(0xc);
  uVar3 = 0xffffffff;
  if (pbVar2 != (byte *)0x0) {
    *pbVar2 = (byte)param_1;
    *(short *)(pbVar2 + 2) = (short)param_2;
    *(short *)(pbVar2 + 4) = (short)param_3;
    pbVar2[8] = 0;
    pbVar2[9] = 0;
    pbVar2[10] = 0;
    pbVar2[0xb] = 0;
    if (pbVar1 != (byte *)0x0) {
      *(byte **)(pbVar1 + 8) = pbVar2;
      pbVar2 = s_zcl_privilege_cluster_list;
    }
_L0:
    s_zcl_privilege_cluster_list = pbVar2;
    uVar3 = 0;
  }
  return uVar3;
}

