/*
 * Last changed at upstream commit 2941fbcc815001461b9ea708a1d755b07ce24ea3
 * https://github.com/espressif/esp-zigbee-sdk/commit/2941fbcc815001461b9ea708a1d755b07ce24ea3
 * Upstream date: 2022-08-09 20:36:03 +0800
 * Upstream subject: esp-zigbee-sdk: First sdk release
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
  if (uVar2 == 0x1d) {
    zcl_device_clusters_attr_init(0,(char)puVar1[1]);
    return;
  }
  if (uVar2 < 0x1e) {
    if (uVar2 == 0) {
      local_20 = puVar1[3];
      uStack_1c = puVar1[4];
      uStack_18 = puVar1[5];
      zcl_device_attribute_update(0,&local_20);
      return;
    }
    if (uVar2 == 7) {
      return;
    }
  }
  else {
    if (uVar2 == 0x53) {
      return;
    }
    if ((0x52 < uVar2) && (uVar2 - 0x56 < 2)) {
      return;
    }
  }
  puVar1[2] = 0xffffffff;
  return;
}

