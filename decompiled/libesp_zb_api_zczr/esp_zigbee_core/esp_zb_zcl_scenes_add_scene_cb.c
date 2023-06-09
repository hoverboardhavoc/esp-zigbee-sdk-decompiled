/*
 * Last changed at upstream commit 6fb04b5b77a96f6ce5cb3daff360f54f13d8db16
 * https://github.com/espressif/esp-zigbee-sdk/commit/6fb04b5b77a96f6ce5cb3daff360f54f13d8db16
 * Upstream date: 2023-06-09 17:12:37 +0800
 * Upstream subject: esp-zigbee-sdk: release esp-zigbee-sdk v0.6.2(2626797)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> esp_zb_zcl_scenes_add_scene_cb
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zcl_scenes_add_scene_cb(undefined4 param_1)

{
  char cVar1;
  byte bVar2;
  undefined2 *puVar3;
  int iVar4;
  uint uVar5;
  undefined2 *puVar6;
  undefined2 *puVar7;
  void *pvVar8;
  undefined2 *puVar9;
  undefined4 uVar10;
  int iVar11;
  undefined2 *puVar12;
  uint uVar13;
  undefined1 *puVar14;
  uint uVar15;
  
  iVar4 = zb_buf_get_tail_func(0x38);
  puVar12 = *(undefined2 **)(iVar4 + 0x10);
  iVar4 = zb_buf_get_tail_func(param_1,0x38);
  puVar14 = *(undefined1 **)(iVar4 + 0x14);
  iVar4 = device_scenes_get_free_entry(*puVar12,*(undefined1 *)(puVar12 + 1));
  if (iVar4 == 0xff) {
    *puVar14 = 0x89;
    uVar10 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_CORE",&_LC4,uVar10,"ESP_ZIGBEE_CORE");
  }
  else {
    uVar5 = zb_buf_len_func(param_1);
    if (2 < uVar5) {
      puVar6 = (undefined2 *)zb_buf_begin_func(param_1);
      cVar1 = *(char *)(puVar6 + 1);
      uVar13 = (uint)(byte)(cVar1 + 3U);
      uVar5 = zb_buf_len_func(param_1);
      if ((uVar13 <= uVar5) && (zb_buf_cut_left_func(param_1,uVar13), puVar6 != (undefined2 *)0x0))
      {
        if ((&esp_zb_zcl_scenes_table)[iVar4 * 6] != -1) {
          *puVar14 = 0xe5;
          device_scene_free_fields((&DAT_00012544)[iVar4 * 3]);
        }
        iVar11 = iVar4 * 0xc;
        (&esp_zb_zcl_scenes_table)[iVar4 * 6] = *puVar12;
        (&DAT_00012540)[iVar11] = *(undefined1 *)(puVar12 + 1);
        *(undefined2 *)(&DAT_0001253e + iVar11) = *(undefined2 *)((int)puVar12 + 3);
        (&DAT_00012541)[iVar11] = cVar1 + 3U;
        puVar7 = (undefined2 *)malloc(0xc);
        *puVar7 = *puVar6;
        bVar2 = *(byte *)(puVar6 + 1);
        *(byte *)(puVar7 + 1) = bVar2;
        pvVar8 = malloc((uint)bVar2);
        *(void **)(puVar7 + 2) = pvVar8;
        memcpy(pvVar8,(void *)((int)puVar6 + 3),(uint)*(byte *)(puVar6 + 1));
        *(undefined4 *)(puVar7 + 4) = 0;
        uVar5 = 1;
        puVar12 = puVar7;
        for (uVar15 = (uint)*(byte *)(puVar6 + 1); uVar15 < uVar13;
            uVar15 = *(byte *)(puVar3 + 1) + uVar15 & 0xff) {
          puVar9 = (undefined2 *)malloc(0xc);
          puVar3 = (undefined2 *)(uVar5 * 3 + uVar15 + (int)puVar6);
          *puVar9 = *puVar3;
          bVar2 = *(byte *)(puVar3 + 1);
          *(byte *)(puVar9 + 1) = bVar2;
          pvVar8 = malloc((uint)bVar2);
          *(void **)(puVar9 + 2) = pvVar8;
          memcpy(pvVar8,(void *)((int)puVar3 + 3),(uint)*(byte *)(puVar3 + 1));
          *(undefined4 *)(puVar9 + 4) = 0;
          *(undefined2 **)(puVar12 + 4) = puVar9;
          uVar5 = uVar5 + 1 & 0xff;
          puVar12 = puVar9;
        }
        (&DAT_00012544)[iVar4 * 3] = puVar7;
        *puVar14 = 0;
      }
    }
  }
  return;
}

