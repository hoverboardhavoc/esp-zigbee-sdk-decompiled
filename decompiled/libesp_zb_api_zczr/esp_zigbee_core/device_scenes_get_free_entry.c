/*
 * Last changed at upstream commit e1a2ba67503f907a4a18f5b9e27b306ea1eb6a05
 * https://github.com/espressif/esp-zigbee-sdk/commit/e1a2ba67503f907a4a18f5b9e27b306ea1eb6a05
 * Upstream date: 2023-05-15 14:58:37 +0800
 * Upstream subject: esp-zigbee-lib: Support customized attribute read and command(225be55)
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
       ((byte)(&DAT_000121b8)[uVar1 * 0xc] == param_2)) goto _L0;
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

