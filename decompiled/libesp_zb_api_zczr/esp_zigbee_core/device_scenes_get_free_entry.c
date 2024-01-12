/*
 * Last changed at upstream commit 9e7fde9a71fb6810604eb3f5a1a644975d98cdc9
 * https://github.com/espressif/esp-zigbee-sdk/commit/9e7fde9a71fb6810604eb3f5a1a644975d98cdc9
 * Upstream date: 2024-01-12 14:14:49 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.0.8(0e41638c)
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
        (*(ushort *)(&DAT_000176fa + uVar2 * 0xc) == param_2)) &&
       ((byte)(&DAT_000176fe)[uVar2 * 0xc] == param_3)) goto _L0;
    if ((uVar1 == 0xff) && (*(short *)(&DAT_000176fa + uVar2 * 0xc) == -1)) {
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

