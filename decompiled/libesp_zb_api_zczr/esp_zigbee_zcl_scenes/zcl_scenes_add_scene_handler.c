/*
 * Last changed at upstream commit e28462af08968da8dbda59a317df742f0109ee5f
 * https://github.com/espressif/esp-zigbee-sdk/commit/e28462af08968da8dbda59a317df742f0109ee5f
 * Upstream date: 2024-04-12 14:44:19 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.3(042315bf)
 * Source: libesp_zb_api_zczr -> esp_zigbee_zcl_scenes.o -> zcl_scenes_add_scene_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zcl_scenes_add_scene_handler(undefined4 param_1)

{
  undefined1 uVar1;
  undefined2 *puVar2;
  int iVar3;
  uint uVar4;
  undefined2 *puVar5;
  undefined2 *puVar6;
  void *__dest;
  byte bVar7;
  int iVar8;
  undefined1 *puVar9;
  undefined4 uVar10;
  undefined2 *puVar11;
  
  iVar3 = zb_buf_get_tail_func(0x38);
  puVar2 = *(undefined2 **)(iVar3 + 0x10);
  iVar3 = zb_buf_get_tail_func(param_1,0x38);
  puVar9 = *(undefined1 **)(iVar3 + 0x14);
  iVar3 = zb_buf_get_tail_func(param_1,0x38);
  uVar1 = *(undefined1 *)(*(int *)(iVar3 + 0xc) + 0xc);
  iVar3 = esp_zb_zcl_scenes_group_check(uVar1,*puVar2);
  *puVar9 = (char)iVar3;
  if (iVar3 == 0) {
    iVar3 = device_scenes_get_free_entry(uVar1,*puVar2,*(undefined1 *)(puVar2 + 1));
    if (iVar3 != 0xff) {
      uVar10 = 0;
      if ((&DAT_00011592)[iVar3 * 6] != -1) {
        device_scenes_table_record_free();
        uVar10 = 0xffffffe5;
      }
      iVar8 = iVar3 * 0xc;
      puVar11 = (undefined2 *)(&DAT_00011598)[iVar3 * 3];
      while (uVar4 = zb_buf_len_func(param_1), 2 < uVar4) {
        puVar5 = (undefined2 *)zb_buf_begin_func(param_1);
        bVar7 = *(char *)(puVar5 + 1) + 3;
        uVar4 = zb_buf_len_func(param_1);
        if (uVar4 < bVar7) break;
        zb_buf_cut_left_func(param_1,(uint)bVar7);
        (&DAT_00011592)[iVar3 * 6] = *puVar2;
        (&DAT_00011596)[iVar8] = *(undefined1 *)(puVar2 + 1);
        (&DAT_00011594)[iVar3 * 6] = *(undefined2 *)((int)puVar2 + 3);
        (&DAT_00011597)[iVar8] = bVar7 + (&DAT_00011597)[iVar8];
        puVar6 = (undefined2 *)malloc(0xc);
        *puVar6 = *puVar5;
        bVar7 = *(byte *)(puVar5 + 1);
        *(byte *)(puVar6 + 1) = bVar7;
        __dest = malloc((uint)bVar7);
        *(void **)(puVar6 + 2) = __dest;
        memcpy(__dest,(void *)((int)puVar5 + 3),(uint)bVar7);
        *(undefined4 *)(puVar6 + 4) = 0;
        if (puVar11 == (undefined2 *)0x0) {
          (&DAT_00011598)[iVar3 * 3] = puVar6;
          puVar11 = puVar6;
        }
        else {
          *(undefined2 **)(puVar11 + 4) = puVar6;
          puVar11 = puVar6;
        }
      }
      *puVar9 = 0;
      iVar3 = zb_nvram_write_dataset(9);
      if (iVar3 == 0) {
        return uVar10;
      }
      return 0xffffffff;
    }
    *puVar9 = 0x89;
  }
  return 0;
}

