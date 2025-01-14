/*
 * Last changed at upstream commit 5becf8b58fd0c6a13fec507be821364ad0ceba39
 * https://github.com/espressif/esp-zigbee-sdk/commit/5becf8b58fd0c6a13fec507be821364ad0ceba39
 * Upstream date: 2025-01-14 03:03:09 +0000
 * Upstream subject: esp-zigbee-sdk: (acad93d1)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_zcl_scenes.o -> device_scenes_table_record_free
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void device_scenes_table_record_free(uint param_1)

{
  int iVar1;
  
  if (param_1 < 0x10) {
    iVar1 = param_1 * 0xc;
    device_scene_free_fields((&DAT_00012c84)[param_1 * 3]);
    (&DAT_00012c84)[param_1 * 3] = 0;
    (&DAT_00012c7e)[param_1 * 6] = 0xffff;
    (&DAT_00012c82)[iVar1] = 0;
    *(undefined2 *)(&DAT_00012c80 + iVar1) = 0;
    (&DAT_00012c83)[iVar1] = 0;
  }
  return;
}

