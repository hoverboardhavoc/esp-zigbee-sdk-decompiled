/*
 * Last changed at upstream commit 88dfcd2f3748e37cbfac85eea52d0fdfbe99049b
 * https://github.com/espressif/esp-zigbee-sdk/commit/88dfcd2f3748e37cbfac85eea52d0fdfbe99049b
 * Upstream date: 2025-08-28 11:19:03 +0000
 * Upstream subject: esp-zigbee-sdk: (0166821f)
 * Source: libesp_zb_api.zczr -> esp_zigbee_zcl_scenes.o -> zcl_scenes_add_scene_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zcl_scenes_add_scene_handler(undefined4 param_1)

{
  undefined1 uVar1;
  undefined2 *puVar2;
  byte bVar3;
  int iVar4;
  uint uVar5;
  undefined2 *puVar6;
  undefined2 *puVar7;
  void *__dest;
  undefined4 uVar8;
  undefined1 *puVar9;
  undefined2 *puVar10;
  int iVar11;
  
  iVar4 = zb_buf_get_tail_func(0x38);
  puVar2 = *(undefined2 **)(iVar4 + 0x10);
  iVar4 = zb_buf_get_tail_func(param_1,0x38);
  puVar9 = *(undefined1 **)(iVar4 + 0x14);
  iVar4 = zb_buf_get_tail_func(param_1,0x38);
  uVar1 = *(undefined1 *)(*(int *)(iVar4 + 0xc) + 0xc);
  iVar4 = esp_zb_zcl_scenes_group_check(uVar1,*puVar2);
  *puVar9 = (char)iVar4;
  if (iVar4 == 0) {
    iVar4 = device_scenes_get_free_entry(uVar1,*puVar2,*(undefined1 *)(puVar2 + 1));
    if (iVar4 != 0xff) {
      iVar4 = iVar4 * 0xc;
      uVar8 = 0;
      if (*(short *)(esp_zb_zcl_scenes_table + iVar4 + 2) != -1) {
        device_scenes_table_record_free();
        uVar8 = 0xffffffe5;
      }
      puVar10 = *(undefined2 **)(esp_zb_zcl_scenes_table + iVar4 + 8);
      while (uVar5 = zb_buf_len_func(param_1), 2 < uVar5) {
        puVar6 = (undefined2 *)zb_buf_begin_func(param_1);
        bVar3 = *(char *)(puVar6 + 1) + 3;
        uVar5 = zb_buf_len_func(param_1);
        if (uVar5 < bVar3) break;
        zb_buf_cut_left_func(param_1,(uint)bVar3);
        iVar11 = esp_zb_zcl_scenes_table + iVar4;
        *(undefined2 *)(iVar11 + 2) = *puVar2;
        *(undefined1 *)(iVar11 + 6) = *(undefined1 *)(puVar2 + 1);
        *(undefined2 *)(iVar11 + 4) = *(undefined2 *)((int)puVar2 + 3);
        *(byte *)(iVar11 + 7) = bVar3 + *(char *)(iVar11 + 7);
        puVar7 = (undefined2 *)malloc(0xc);
        *puVar7 = *puVar6;
        bVar3 = *(byte *)(puVar6 + 1);
        *(byte *)(puVar7 + 1) = bVar3;
        __dest = malloc((uint)bVar3);
        *(void **)(puVar7 + 2) = __dest;
        memcpy(__dest,(void *)((int)puVar6 + 3),(uint)bVar3);
        *(undefined4 *)(puVar7 + 4) = 0;
        if (puVar10 == (undefined2 *)0x0) {
          *(undefined2 **)(iVar11 + 8) = puVar7;
          puVar10 = puVar7;
        }
        else {
          *(undefined2 **)(puVar10 + 4) = puVar7;
          puVar10 = puVar7;
        }
      }
      zb_zcl_scenes_add_scene_count(uVar1,1);
      *puVar9 = 0;
      iVar4 = zb_nvram_write_dataset(9);
      if (iVar4 == 0) {
        return uVar8;
      }
      return 0xffffffff;
    }
    *puVar9 = 0x89;
  }
  return 0;
}

