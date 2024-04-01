/*
 * Last changed at upstream commit 3128a1de3a8a176dac99e12775a60287e9d10fd7
 * https://github.com/espressif/esp-zigbee-sdk/commit/3128a1de3a8a176dac99e12775a60287e9d10fd7
 * Upstream date: 2024-04-01 17:59:07 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.2(4a0e02cc)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> device_scenes_get_free_entry
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

