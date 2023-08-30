/*
 * Last changed at upstream commit c1113e88ee047f0eb31a91352a6fd0fc5318b6fd
 * https://github.com/espressif/esp-zigbee-sdk/commit/c1113e88ee047f0eb31a91352a6fd0fc5318b6fd
 * Upstream date: 2023-08-30 15:00:29 +0800
 * Upstream subject: esp-zigbee-sdk: release/v0.9.3(6da46788)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> zcl_privilege_command_list_find
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zcl_privilege_command_list_find(uint param_1,uint param_2,uint param_3)

{
  byte *pbVar1;
  
  pbVar1 = s_zcl_privilege_cluster_list;
  while( true ) {
    if (pbVar1 == (byte *)0x0) {
      return 0;
    }
    if (((*pbVar1 == param_1) && (*(ushort *)(pbVar1 + 2) == param_2)) &&
       (*(ushort *)(pbVar1 + 4) == param_3)) break;
    pbVar1 = *(byte **)(pbVar1 + 8);
  }
  return 1;
}

