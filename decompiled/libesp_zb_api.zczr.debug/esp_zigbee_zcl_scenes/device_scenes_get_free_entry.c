/*
 * Last changed at upstream commit 88dfcd2f3748e37cbfac85eea52d0fdfbe99049b
 * https://github.com/espressif/esp-zigbee-sdk/commit/88dfcd2f3748e37cbfac85eea52d0fdfbe99049b
 * Upstream date: 2025-08-28 11:19:03 +0000
 * Upstream subject: esp-zigbee-sdk: (0166821f)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_zcl_scenes.o -> device_scenes_get_free_entry
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

uint device_scenes_get_free_entry(uint param_1,uint param_2,uint param_3)

{
  uint uVar1;
  byte *pbVar2;
  uint uVar3;
  
  uVar1 = 0xff;
  for (uVar3 = 0; uVar3 < esp_zb_zcl_scenes_table_capacity; uVar3 = uVar3 + 1 & 0xff) {
    pbVar2 = (byte *)(uVar3 * 0xc + esp_zb_zcl_scenes_table);
    if (((*pbVar2 == param_1) && (*(ushort *)(pbVar2 + 2) == param_2)) && (pbVar2[6] == param_3))
    goto _L0;
    if ((uVar1 == 0xff) && (*(short *)(pbVar2 + 2) == -1)) {
      *pbVar2 = (byte)param_1;
      uVar1 = uVar3;
    }
  }
  uVar3 = 0xff;
_L0:
  if (uVar3 != 0xff) {
    uVar1 = uVar3;
  }
  return uVar1;
}

