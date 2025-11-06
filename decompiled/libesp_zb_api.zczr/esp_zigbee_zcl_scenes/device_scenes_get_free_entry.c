/*
 * Last changed at upstream commit ef60059b4d605d61a0103f81567229692f238007
 * https://github.com/espressif/esp-zigbee-sdk/commit/ef60059b4d605d61a0103f81567229692f238007
 * Upstream date: 2025-11-06 11:58:56 +0800
 * Upstream subject: esp-zigbee-sdk: (79cb709a)
 * Source: libesp_zb_api.zczr -> esp_zigbee_zcl_scenes.o -> device_scenes_get_free_entry
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

char device_scenes_get_free_entry(uint param_1,uint param_2,uint param_3)

{
  char cVar1;
  char cVar2;
  byte *pbVar3;
  char cVar4;
  
  cVar1 = esp_zb_zcl_scenes_table_capacity;
  cVar2 = -1;
  cVar4 = '\0';
  pbVar3 = esp_zb_zcl_scenes_table;
  while( true ) {
    if (cVar1 == cVar4) {
      return cVar2;
    }
    if (((*pbVar3 == param_1) && (*(ushort *)(pbVar3 + 2) == param_2)) && (pbVar3[6] == param_3))
    break;
    if ((cVar2 == -1) && (*(short *)(pbVar3 + 2) == -1)) {
      *pbVar3 = (byte)param_1;
      cVar2 = cVar4;
    }
    cVar4 = cVar4 + '\x01';
    pbVar3 = pbVar3 + 0xc;
  }
  if (cVar4 != -1) {
    cVar2 = cVar4;
  }
  return cVar2;
}

