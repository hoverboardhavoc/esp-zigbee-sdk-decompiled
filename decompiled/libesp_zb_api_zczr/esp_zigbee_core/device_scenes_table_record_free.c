/*
 * Last changed at upstream commit d50acd5408f73d4459b46a949332bb6e32f97543
 * https://github.com/espressif/esp-zigbee-sdk/commit/d50acd5408f73d4459b46a949332bb6e32f97543
 * Upstream date: 2023-09-08 17:20:56 +0800
 * Upstream subject: esp-zigbee-sdk: release/v0.9.4(89250ad3)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> device_scenes_table_record_free
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void device_scenes_table_record_free(uint param_1)

{
  int iVar1;
  
  if (9 < param_1) {
    return;
  }
  iVar1 = param_1 * 0xc;
  device_scene_free_fields((&DAT_000158e8)[param_1 * 3]);
  (&DAT_000158e8)[param_1 * 3] = 0;
  (&esp_zb_zcl_scenes_table)[param_1 * 6] = 0xffff;
  (&DAT_000158e4)[iVar1] = 0;
  *(undefined2 *)(&DAT_000158e2 + iVar1) = 0;
  (&DAT_000158e5)[iVar1] = 0;
  return;
}

