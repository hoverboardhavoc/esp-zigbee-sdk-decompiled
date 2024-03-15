/*
 * Last changed at upstream commit ba8582df6bc62b9e5e69a4c6f3ae02f0e1da194a
 * https://github.com/espressif/esp-zigbee-sdk/commit/ba8582df6bc62b9e5e69a4c6f3ae02f0e1da194a
 * Upstream date: 2024-03-15 18:43:30 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.1(aaf0078d)
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
  
  uVar2 = 0xff;
  for (uVar1 = 0; uVar1 < 0x10; uVar1 = uVar1 + 1 & 0xff) {
    if ((((byte)(&esp_zb_zcl_scenes_table)[uVar1 * 0xc] == param_1) &&
        ((ushort)(&DAT_00018f0e)[uVar1 * 6] == param_2)) &&
       ((byte)(&DAT_00018f12)[uVar1 * 0xc] == param_3)) goto _L0;
    if ((uVar2 == 0xff) && ((&DAT_00018f0e)[uVar1 * 6] == -1)) {
      (&esp_zb_zcl_scenes_table)[uVar1 * 0xc] = (char)param_1;
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

