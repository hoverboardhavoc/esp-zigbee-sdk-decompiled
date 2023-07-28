/*
 * Last changed at upstream commit 992d2f5b99d09ff49d4d820bb9dc59b1d40be6d4
 * https://github.com/espressif/esp-zigbee-sdk/commit/992d2f5b99d09ff49d4d820bb9dc59b1d40be6d4
 * Upstream date: 2023-07-28 17:48:58 +0800
 * Upstream subject: esp-zigbee-sdk: release/v0.7.2(e1472baa)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> esp_zb_zcl_scenes_add_scene_cb
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zcl_scenes_add_scene_cb(undefined4 param_1)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  undefined2 *puVar4;
  undefined2 *puVar5;
  void *__dest;
  undefined4 uVar6;
  int iVar7;
  undefined2 *puVar8;
  undefined2 *puVar9;
  undefined1 *puVar10;
  
  iVar2 = zb_buf_get_tail_func(0x38);
  puVar8 = *(undefined2 **)(iVar2 + 0x10);
  iVar2 = zb_buf_get_tail_func(param_1,0x38);
  puVar10 = *(undefined1 **)(iVar2 + 0x14);
  iVar2 = zb_buf_get_tail_func(param_1,0x38);
  iVar2 = esp_zb_zcl_scenes_group_check(*puVar8,*(undefined1 *)(*(int *)(iVar2 + 0xc) + 0xc));
  *puVar10 = (char)iVar2;
  if (iVar2 == 0) {
    iVar2 = device_scenes_get_free_entry(*puVar8,*(undefined1 *)(puVar8 + 1));
    if (iVar2 == 0xff) {
      *puVar10 = 0x89;
      uVar6 = esp_log_timestamp();
      esp_log_write(2,"ESP_ZIGBEE_CORE",&_LC11,uVar6,"ESP_ZIGBEE_CORE",*(undefined1 *)(puVar8 + 1));
    }
    else {
      if ((&esp_zb_zcl_scenes_table)[iVar2 * 6] != -1) {
        *puVar10 = 0xe5;
        device_scene_free_fields((&DAT_000136ec)[iVar2 * 3]);
      }
      puVar9 = (undefined2 *)(&DAT_000136ec)[iVar2 * 3];
      do {
        uVar3 = zb_buf_len_func(param_1);
        if (uVar3 < 3) {
          puVar4 = (undefined2 *)0x0;
        }
        else {
          puVar4 = (undefined2 *)zb_buf_begin_func(param_1);
          bVar1 = *(char *)(puVar4 + 1) + 3;
          uVar3 = zb_buf_len_func(param_1);
          if (uVar3 < bVar1) {
            puVar4 = (undefined2 *)0x0;
          }
          else {
            zb_buf_cut_left_func(param_1,(uint)bVar1);
            if (puVar4 != (undefined2 *)0x0) {
              iVar7 = iVar2 * 0xc;
              (&esp_zb_zcl_scenes_table)[iVar2 * 6] = *puVar8;
              (&DAT_000136e8)[iVar7] = *(undefined1 *)(puVar8 + 1);
              *(undefined2 *)(&DAT_000136e6 + iVar7) = *(undefined2 *)((int)puVar8 + 3);
              (&DAT_000136e9)[iVar7] = (&DAT_000136e9)[iVar7] + bVar1;
              puVar5 = (undefined2 *)malloc(0xc);
              *puVar5 = *puVar4;
              bVar1 = *(byte *)(puVar4 + 1);
              *(byte *)(puVar5 + 1) = bVar1;
              __dest = malloc((uint)bVar1);
              *(void **)(puVar5 + 2) = __dest;
              memcpy(__dest,(void *)((int)puVar4 + 3),(uint)*(byte *)(puVar4 + 1));
              *(undefined4 *)(puVar5 + 4) = 0;
              if (puVar9 == (undefined2 *)0x0) {
                (&DAT_000136ec)[iVar2 * 3] = puVar5;
                puVar9 = puVar5;
              }
              else {
                *(undefined2 **)(puVar9 + 4) = puVar5;
                puVar9 = puVar5;
              }
            }
          }
        }
      } while (puVar4 != (undefined2 *)0x0);
      *puVar10 = 0;
      uVar6 = esp_log_timestamp();
      esp_log_write(3,"ESP_ZIGBEE_CORE",&_L0,uVar6,"ESP_ZIGBEE_CORE",*(undefined1 *)(puVar8 + 1),
                    *puVar8);
    }
  }
  return;
}

