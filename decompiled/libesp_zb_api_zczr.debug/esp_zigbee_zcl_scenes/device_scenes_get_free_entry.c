/*
 * Last changed at upstream commit b16fd900dd0b442e8e677ff001b10a2e9e95729b
 * https://github.com/espressif/esp-zigbee-sdk/commit/b16fd900dd0b442e8e677ff001b10a2e9e95729b
 * Upstream date: 2024-11-01 15:37:53 +0800
 * Upstream subject: esp-zigbee-lib:(4f5d21fb)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_zcl_scenes.o -> device_scenes_get_free_entry
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

uint device_scenes_get_free_entry(uint param_1,uint param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = 0xff;
  for (uVar2 = 0; uVar2 < 0x10; uVar2 = uVar2 + 1 & 0xff) {
    if ((((byte)(&esp_zb_zcl_scenes_table)[uVar2 * 0xc] == param_1) &&
        ((ushort)(&DAT_00012bfa)[uVar2 * 6] == param_2)) &&
       ((byte)(&DAT_00012bfe)[uVar2 * 0xc] == param_3)) goto _L0;
    if ((uVar1 == 0xff) && ((&DAT_00012bfa)[uVar2 * 6] == -1)) {
      (&esp_zb_zcl_scenes_table)[uVar2 * 0xc] = (char)param_1;
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

