/*
 * Last changed at upstream commit 2fe15bae2e4382ac99f249a0934066f5d5a5c684
 * https://github.com/espressif/esp-zigbee-sdk/commit/2fe15bae2e4382ac99f249a0934066f5d5a5c684
 * Upstream date: 2024-03-08 17:10:04 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.0(9d7e9ff2)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> zcl_scenes_add_scene_handler
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
  int iVar7;
  byte bVar8;
  undefined2 *puVar9;
  undefined1 *puVar10;
  undefined4 uVar11;
  undefined2 *puVar12;
  
  iVar2 = zb_buf_get_tail_func(0x38);
  puVar9 = *(undefined2 **)(iVar2 + 0x10);
  iVar2 = zb_buf_get_tail_func(param_1,0x38);
  puVar10 = *(undefined1 **)(iVar2 + 0x14);
  iVar2 = zb_buf_get_tail_func(param_1,0x38);
  uVar1 = *(undefined1 *)(*(int *)(iVar2 + 0xc) + 0xc);
  iVar2 = esp_zb_zcl_scenes_group_check(uVar1,*puVar9);
  *puVar10 = (char)iVar2;
  if (iVar2 == 0) {
    iVar2 = device_scenes_get_free_entry(uVar1,*puVar9,*(undefined1 *)(puVar9 + 1));
    if (iVar2 == 0xff) {
      *puVar10 = 0x89;
      uVar11 = esp_log_timestamp();
      esp_log_write(2,"ESP_ZIGBEE_CORE",&_LC51,uVar11,"ESP_ZIGBEE_CORE",*(undefined1 *)(puVar9 + 1))
      ;
      uVar11 = 0;
    }
    else {
      if ((&DAT_00018ef6)[iVar2 * 6] == -1) {
        uVar11 = 0;
      }
      else {
        device_scenes_table_record_free();
        uVar11 = esp_log_timestamp();
        esp_log_write(2,"ESP_ZIGBEE_CORE",&_L0,uVar11,"ESP_ZIGBEE_CORE",*(undefined1 *)(puVar9 + 1),
                      *puVar9);
        uVar11 = 0xffffffe5;
      }
      puVar12 = (undefined2 *)(&DAT_00018efc)[iVar2 * 3];
      do {
        uVar3 = zb_buf_len_func(param_1);
        if (uVar3 < 3) {
          puVar4 = (undefined2 *)0x0;
        }
        else {
          puVar4 = (undefined2 *)zb_buf_begin_func(param_1);
          bVar8 = *(char *)(puVar4 + 1) + 3;
          uVar3 = zb_buf_len_func(param_1);
          if (uVar3 < bVar8) {
            puVar4 = (undefined2 *)0x0;
          }
          else {
            zb_buf_cut_left_func(param_1,(uint)bVar8);
            if (puVar4 != (undefined2 *)0x0) {
              iVar7 = iVar2 * 0xc;
              (&DAT_00018ef6)[iVar2 * 6] = *puVar9;
              (&DAT_00018efa)[iVar7] = *(undefined1 *)(puVar9 + 1);
              (&DAT_00018ef8)[iVar2 * 6] = *(undefined2 *)((int)puVar9 + 3);
              (&DAT_00018efb)[iVar7] = (&DAT_00018efb)[iVar7] + bVar8;
              puVar5 = (undefined2 *)malloc(0xc);
              *puVar5 = *puVar4;
              bVar8 = *(byte *)(puVar4 + 1);
              *(byte *)(puVar5 + 1) = bVar8;
              __dest = malloc((uint)bVar8);
              *(void **)(puVar5 + 2) = __dest;
              memcpy(__dest,(void *)((int)puVar4 + 3),(uint)*(byte *)(puVar4 + 1));
              *(undefined4 *)(puVar5 + 4) = 0;
              if (puVar12 == (undefined2 *)0x0) {
                (&DAT_00018efc)[iVar2 * 3] = puVar5;
                puVar12 = puVar5;
              }
              else {
                *(undefined2 **)(puVar12 + 4) = puVar5;
                puVar12 = puVar5;
              }
            }
          }
        }
      } while (puVar4 != (undefined2 *)0x0);
      *puVar10 = 0;
      iVar2 = zb_nvram_write_dataset(9);
      if (iVar2 == 0) {
        uVar6 = esp_log_timestamp();
        esp_log_write(3,"ESP_ZIGBEE_CORE",&_LC50,uVar6,"ESP_ZIGBEE_CORE",*(undefined1 *)(puVar9 + 1)
                      ,*puVar9);
      }
      else {
        uVar11 = esp_log_timestamp();
        esp_log_write(1,"ESP_ZIGBEE_CORE",&_LC46,uVar11,"ESP_ZIGBEE_CORE",
                      "zcl_scenes_add_scene_handler",0x30e);
        uVar11 = 0xffffffff;
      }
    }
  }
  else {
    uVar11 = 0;
  }
  return uVar11;
}

