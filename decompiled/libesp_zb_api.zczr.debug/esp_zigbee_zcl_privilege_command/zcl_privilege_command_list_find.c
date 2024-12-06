/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_zcl_privilege_command.o -> zcl_privilege_command_list_find
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zcl_privilege_command_list_find(uint param_1,uint param_2,uint param_3)

{
  byte *pbVar1;
  
  pbVar1 = (byte *)&s_zcl_privilege_cluster_list;
  while ((pbVar1 = *(byte **)pbVar1, pbVar1 != (byte *)0x0 &&
         (((*pbVar1 != param_1 || (*(ushort *)(pbVar1 + 2) != param_2)) ||
          (*(ushort *)(pbVar1 + 4) != param_3))))) {
    pbVar1 = pbVar1 + 8;
  }
  return;
}

