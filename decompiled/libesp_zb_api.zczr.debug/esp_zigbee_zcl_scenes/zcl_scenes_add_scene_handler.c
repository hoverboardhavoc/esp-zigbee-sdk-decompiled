/*
 * Last changed at upstream commit 88dfcd2f3748e37cbfac85eea52d0fdfbe99049b
 * https://github.com/espressif/esp-zigbee-sdk/commit/88dfcd2f3748e37cbfac85eea52d0fdfbe99049b
 * Upstream date: 2025-08-28 11:19:03 +0000
 * Upstream subject: esp-zigbee-sdk: (0166821f)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_zcl_scenes.o -> zcl_scenes_add_scene_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zcl_scenes_add_scene_handler(undefined4 param_1)

{
  undefined1 uVar1;
  int iVar2;
  uint uVar3;
  undefined2 *puVar4;
  undefined2 *puVar5;
  void *__dest;
  undefined4 uVar6;
  byte bVar7;
  undefined2 *puVar8;
  undefined1 *puVar9;
  undefined4 uVar10;
  undefined2 *puVar11;
  int iVar12;
  
  iVar2 = zb_buf_get_tail_func(0x38);
  puVar8 = *(undefined2 **)(iVar2 + 0x10);
  iVar2 = zb_buf_get_tail_func(param_1,0x38);
  puVar9 = *(undefined1 **)(iVar2 + 0x14);
  iVar2 = zb_buf_get_tail_func(param_1,0x38);
  uVar1 = *(undefined1 *)(*(int *)(iVar2 + 0xc) + 0xc);
  iVar2 = esp_zb_zcl_scenes_group_check(uVar1,*puVar8);
  *puVar9 = (char)iVar2;
  if (iVar2 == 0) {
    iVar2 = device_scenes_get_free_entry(uVar1,*puVar8,*(undefined1 *)(puVar8 + 1));
    if (iVar2 == 0xff) {
      *puVar9 = 0x89;
      uVar10 = esp_log_timestamp();
      esp_log_write(2,"ESP_ZIGBEE_ZCL_SCENES",&_LC19,uVar10,"ESP_ZIGBEE_ZCL_SCENES",
                    *(undefined1 *)(puVar8 + 1));
      uVar10 = 0;
    }
    else {
      iVar2 = iVar2 * 0xc;
      if (*(short *)(esp_zb_zcl_scenes_table + iVar2 + 2) == -1) {
        uVar10 = 0;
      }
      else {
        device_scenes_table_record_free();
        uVar10 = esp_log_timestamp();
        esp_log_write(2,"ESP_ZIGBEE_ZCL_SCENES",&_L0,uVar10,"ESP_ZIGBEE_ZCL_SCENES",
                      *(undefined1 *)(puVar8 + 1),*puVar8);
        uVar10 = 0xffffffe5;
      }
      puVar11 = *(undefined2 **)(esp_zb_zcl_scenes_table + iVar2 + 8);
      do {
        uVar3 = zb_buf_len_func(param_1);
        if (uVar3 < 3) {
          puVar4 = (undefined2 *)0x0;
        }
        else {
          puVar4 = (undefined2 *)zb_buf_begin_func(param_1);
          bVar7 = *(char *)(puVar4 + 1) + 3;
          uVar3 = zb_buf_len_func(param_1);
          if (uVar3 < bVar7) {
            puVar4 = (undefined2 *)0x0;
          }
          else {
            zb_buf_cut_left_func(param_1,(uint)bVar7);
            if (puVar4 != (undefined2 *)0x0) {
              iVar12 = esp_zb_zcl_scenes_table + iVar2;
              *(undefined2 *)(iVar12 + 2) = *puVar8;
              *(undefined1 *)(iVar12 + 6) = *(undefined1 *)(puVar8 + 1);
              *(undefined2 *)(iVar12 + 4) = *(undefined2 *)((int)puVar8 + 3);
              *(byte *)(iVar12 + 7) = *(char *)(iVar12 + 7) + bVar7;
              puVar5 = (undefined2 *)malloc(0xc);
              *puVar5 = *puVar4;
              bVar7 = *(byte *)(puVar4 + 1);
              *(byte *)(puVar5 + 1) = bVar7;
              __dest = malloc((uint)bVar7);
              *(void **)(puVar5 + 2) = __dest;
              memcpy(__dest,(void *)((int)puVar4 + 3),(uint)*(byte *)(puVar4 + 1));
              *(undefined4 *)(puVar5 + 4) = 0;
              if (puVar11 == (undefined2 *)0x0) {
                *(undefined2 **)(iVar12 + 8) = puVar5;
                puVar11 = puVar5;
              }
              else {
                *(undefined2 **)(puVar11 + 4) = puVar5;
                puVar11 = puVar5;
              }
            }
          }
        }
      } while (puVar4 != (undefined2 *)0x0);
      zb_zcl_scenes_add_scene_count(uVar1,1);
      *puVar9 = 0;
      iVar2 = zb_nvram_write_dataset(9);
      if (iVar2 == 0) {
        uVar6 = esp_log_timestamp();
        esp_log_write(3,"ESP_ZIGBEE_ZCL_SCENES",&_LC18,uVar6,"ESP_ZIGBEE_ZCL_SCENES",
                      *(undefined1 *)(puVar8 + 1),*puVar8);
      }
      else {
        uVar10 = esp_log_timestamp();
        esp_log_write(1,"ESP_ZIGBEE_ZCL_SCENES",&_LC9,uVar10,"ESP_ZIGBEE_ZCL_SCENES",
                      "zcl_scenes_add_scene_handler",0x171);
        uVar10 = 0xffffffff;
      }
    }
  }
  else {
    uVar10 = 0;
  }
  return uVar10;
}

