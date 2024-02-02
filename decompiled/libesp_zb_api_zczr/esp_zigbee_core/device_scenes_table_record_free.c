/*
 * Last changed at upstream commit 2e2b779251f791b76c34cc582bf68595de9ac19b
 * https://github.com/espressif/esp-zigbee-sdk/commit/2e2b779251f791b76c34cc582bf68595de9ac19b
 * Upstream date: 2024-02-02 22:15:44 +0800
 * Upstream subject: feat(spinel): support zigbee radio spinel
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> device_scenes_table_record_free
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
    device_scene_free_fields((&DAT_00017824)[param_1 * 3]);
    (&DAT_00017824)[param_1 * 3] = 0;
    (&DAT_0001781e)[param_1 * 6] = 0xffff;
    (&DAT_00017822)[iVar1] = 0;
    *(undefined2 *)(&DAT_00017820 + iVar1) = 0;
    (&DAT_00017823)[iVar1] = 0;
  }
  return;
}

