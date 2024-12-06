/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
 * Source: libesp_zb_api.zczr -> esp_zigbee_zcl_scenes.o -> device_scenes_get_free_entry
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

char device_scenes_get_free_entry(uint param_1,uint param_2,uint param_3)

{
  char cVar1;
  byte *pbVar2;
  char cVar3;
  
  pbVar2 = &esp_zb_zcl_scenes_table;
  cVar3 = -1;
  cVar1 = '\0';
  do {
    if (((*pbVar2 == param_1) && (*(ushort *)(pbVar2 + 2) == param_2)) && (pbVar2[6] == param_3)) {
      return cVar1;
    }
    if ((cVar3 == -1) && (*(short *)(pbVar2 + 2) == -1)) {
      *pbVar2 = (byte)param_1;
      cVar3 = cVar1;
    }
    cVar1 = cVar1 + '\x01';
    pbVar2 = pbVar2 + 0xc;
  } while (cVar1 != '\x10');
  return cVar3;
}

