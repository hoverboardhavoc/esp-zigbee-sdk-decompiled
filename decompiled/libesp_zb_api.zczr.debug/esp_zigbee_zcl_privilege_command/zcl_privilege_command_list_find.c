/*
 * Last changed at upstream commit ef60059b4d605d61a0103f81567229692f238007
 * https://github.com/espressif/esp-zigbee-sdk/commit/ef60059b4d605d61a0103f81567229692f238007
 * Upstream date: 2025-11-06 11:58:56 +0800
 * Upstream subject: esp-zigbee-sdk: (79cb709a)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_zcl_privilege_command.o -> zcl_privilege_command_list_find
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zcl_privilege_command_list_find(uint param_1,uint param_2,uint param_3)

{
  byte *pbVar1;
  int iVar2;
  byte *pbVar3;
  
  pbVar1 = (byte *)&s_zcl_privilege_cluster_list;
  iVar2 = s_zcl_privilege_cluster_list;
  while ((iVar2 != 0 &&
         (((pbVar3 = *(byte **)pbVar1, *pbVar3 != param_1 || (*(ushort *)(pbVar3 + 2) != param_2))
          || (*(ushort *)(pbVar3 + 4) != param_3))))) {
    pbVar1 = pbVar3 + 8;
    iVar2 = *(int *)(pbVar3 + 8);
  }
  return;
}

