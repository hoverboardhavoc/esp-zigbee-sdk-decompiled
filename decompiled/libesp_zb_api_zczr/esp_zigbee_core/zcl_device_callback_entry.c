/*
 * Last changed at upstream commit 7abab98979b3ea95f88c7b3687103b07986e5dd5
 * https://github.com/espressif/esp-zigbee-sdk/commit/7abab98979b3ea95f88c7b3687103b07986e5dd5
 * Upstream date: 2022-11-14 17:26:16 +0800
 * Upstream subject: examples: support rename esp32h2 to esp32h4
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> zcl_device_callback_entry
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zcl_device_callback_entry(void)

{
  uint *puVar1;
  uint uVar2;
  uint local_20;
  uint uStack_1c;
  uint uStack_18;
  
  puVar1 = (uint *)zb_buf_get_tail_func(0x38);
  uVar2 = *puVar1;
  puVar1[2] = 0;
  if (uVar2 != 7) {
    if (uVar2 < 8) {
      if (uVar2 == 0) {
        local_20 = puVar1[3];
        uStack_1c = puVar1[4];
        uStack_18 = puVar1[5];
        zcl_device_attribute_update(0,(char)puVar1[1],&local_20);
        return;
      }
    }
    else {
      if (uVar2 == 0x54) {
        return;
      }
      if (uVar2 < 0x55) {
        if (uVar2 == 0x1d) {
          return;
        }
      }
      else if (uVar2 - 0x57 < 2) {
        return;
      }
    }
    puVar1[2] = 0xffffffff;
  }
  return;
}

