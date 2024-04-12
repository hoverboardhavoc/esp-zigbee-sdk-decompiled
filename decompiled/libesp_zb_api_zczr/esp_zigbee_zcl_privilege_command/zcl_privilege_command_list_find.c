/*
 * Last changed at upstream commit e28462af08968da8dbda59a317df742f0109ee5f
 * https://github.com/espressif/esp-zigbee-sdk/commit/e28462af08968da8dbda59a317df742f0109ee5f
 * Upstream date: 2024-04-12 14:44:19 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.3(042315bf)
 * Source: libesp_zb_api_zczr -> esp_zigbee_zcl_privilege_command.o -> zcl_privilege_command_list_find
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

byte * zcl_privilege_command_list_find(uint param_1,uint param_2,uint param_3)

{
  byte *pbVar1;
  byte *pbVar2;
  
  pbVar1 = (byte *)&s_zcl_privilege_cluster_list;
  for (pbVar2 = s_zcl_privilege_cluster_list;
      (pbVar2 != (byte *)0x0 &&
      (((*pbVar2 != param_1 || (*(ushort *)(pbVar2 + 2) != param_2)) ||
       (*(ushort *)(pbVar2 + 4) != param_3)))); pbVar2 = *(byte **)(pbVar2 + 8)) {
    pbVar1 = pbVar2 + 8;
  }
  return pbVar1;
}

