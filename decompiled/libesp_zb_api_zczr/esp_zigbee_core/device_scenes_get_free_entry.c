/*
 * Last changed at upstream commit 0c62d9f04d6c4a739fd0a010d54749e3cd6ae209
 * https://github.com/espressif/esp-zigbee-sdk/commit/0c62d9f04d6c4a739fd0a010d54749e3cd6ae209
 * Upstream date: 2024-01-19 19:10:32 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.0.9(b7135493)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> device_scenes_get_free_entry
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
        ((ushort)(&DAT_00017822)[uVar2 * 6] == param_2)) &&
       ((byte)(&DAT_00017826)[uVar2 * 0xc] == param_3)) goto _L0;
    if ((uVar1 == 0xff) && ((&DAT_00017822)[uVar2 * 6] == -1)) {
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

