/*
 * Last changed at upstream commit 3a2e620f73272cd71b1255d9566d72d6c662dd1c
 * https://github.com/espressif/esp-zigbee-sdk/commit/3a2e620f73272cd71b1255d9566d72d6c662dd1c
 * Upstream date: 2023-11-24 19:53:05 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.0.5(909d273b)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> device_scenes_get_free_entry
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

uint device_scenes_get_free_entry(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = 0xff;
  for (uVar2 = 0; uVar2 < 10; uVar2 = uVar2 + 1 & 0xff) {
    if (((ushort)(&esp_zb_zcl_scenes_table)[uVar2 * 6] == param_1) &&
       ((byte)(&DAT_00016f3c)[uVar2 * 0xc] == param_2)) goto _L0;
    if ((uVar1 == 0xff) && ((ushort)(&esp_zb_zcl_scenes_table)[uVar2 * 6] == 0xffff)) {
      uVar1 = uVar2;
    }
  }
  uVar2 = 0xff;
_L0:
  if (uVar2 != 0xff) {
    uVar1 = uVar2;
  }
  return uVar1;
}

