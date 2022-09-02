/*
 * Last changed at upstream commit 161b24f200d3999849a30e5fddeac9123c04dbfe
 * https://github.com/espressif/esp-zigbee-sdk/commit/161b24f200d3999849a30e5fddeac9123c04dbfe
 * Upstream date: 2022-09-02 14:39:54 +0800
 * Upstream subject: Components: Separation of the zigbee_core_api header
 * Source: libesp_zb_api_zczr -> esp_zigbee_api_core.o -> zcl_device_callback_entry
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
      if (uVar2 == 0x53) {
        return;
      }
      if (uVar2 < 0x54) {
        if (uVar2 == 0x1d) {
          return;
        }
      }
      else if (uVar2 - 0x56 < 2) {
        return;
      }
    }
    puVar1[2] = 0xffffffff;
  }
  return;
}

