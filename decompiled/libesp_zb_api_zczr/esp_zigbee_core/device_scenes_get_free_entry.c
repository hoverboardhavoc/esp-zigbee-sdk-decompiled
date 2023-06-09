/*
 * Last changed at upstream commit 6fb04b5b77a96f6ce5cb3daff360f54f13d8db16
 * https://github.com/espressif/esp-zigbee-sdk/commit/6fb04b5b77a96f6ce5cb3daff360f54f13d8db16
 * Upstream date: 2023-06-09 17:12:37 +0800
 * Upstream subject: esp-zigbee-sdk: release esp-zigbee-sdk v0.6.2(2626797)
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
  
  uVar2 = 0xff;
  for (uVar1 = 0; uVar1 < 10; uVar1 = uVar1 + 1 & 0xff) {
    if (((ushort)(&esp_zb_zcl_scenes_table)[uVar1 * 6] == param_1) &&
       ((byte)(&DAT_00012540)[uVar1 * 0xc] == param_2)) goto _L0;
    if ((uVar2 == 0xff) && ((ushort)(&esp_zb_zcl_scenes_table)[uVar1 * 6] == 0xffff)) {
      uVar2 = uVar1;
    }
  }
  uVar1 = 0xff;
_L0:
  if (uVar1 == 0xff) {
    uVar1 = uVar2;
  }
  return uVar1;
}

