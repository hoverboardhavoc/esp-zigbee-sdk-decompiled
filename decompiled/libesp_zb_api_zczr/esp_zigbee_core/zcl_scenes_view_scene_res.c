/*
 * Last changed at upstream commit 790bc8d6ece1bf5f739debaa4aa4af508982070a
 * https://github.com/espressif/esp-zigbee-sdk/commit/790bc8d6ece1bf5f739debaa4aa4af508982070a
 * Upstream date: 2023-12-21 19:52:25 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.0.7(bdde218a)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> zcl_scenes_view_scene_res
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int zcl_scenes_view_scene_res(undefined4 param_1)

{
  byte bVar1;
  undefined2 *puVar2;
  uint uVar3;
  byte *pbVar4;
  int iVar5;
  undefined4 uVar6;
  undefined2 *puVar7;
  undefined2 *puVar8;
  void *__dest;
  undefined2 *puVar9;
  uint auStack_4c [8];
  undefined2 uStack_2c;
  byte bStack_2a;
  undefined2 uStack_28;
  undefined2 *puStack_24;
  
  uVar3 = zb_buf_len_func();
  if (uVar3 < 4) {
_L0:
    uVar6 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_CORE",&_LC18,uVar6,"ESP_ZIGBEE_CORE","zcl_scenes_view_scene_res",
                  0x839);
    iVar5 = 0;
  }
  else {
    pbVar4 = (byte *)zb_buf_begin_func(param_1);
    if (*pbVar4 == 0) {
      zb_buf_cut_left_func(param_1,pbVar4[6] + 7);
      pbVar4[6] = 0;
    }
    else {
      zb_buf_cut_left_func(param_1,4);
      if (pbVar4 == (byte *)0x0) goto _L0;
    }
    iVar5 = zb_zcl_basic_message_create(param_1,auStack_4c);
    if (iVar5 == 0) {
      auStack_4c[0] = (uint)*pbVar4;
      uStack_2c = *(undefined2 *)(pbVar4 + 1);
      bStack_2a = pbVar4[3];
      uStack_28 = *(undefined2 *)(pbVar4 + 4);
      puStack_24 = (undefined2 *)0x0;
      puVar9 = (undefined2 *)0x0;
      do {
        uVar3 = zb_buf_len_func(param_1);
        puVar8 = puVar9;
        if (uVar3 < 3) {
          puVar7 = (undefined2 *)0x0;
          puVar2 = puStack_24;
        }
        else {
          puVar7 = (undefined2 *)zb_buf_begin_func(param_1);
          bVar1 = *(byte *)(puVar7 + 1);
          uVar3 = zb_buf_len_func(param_1);
          if (uVar3 < bVar1 + 3) {
            puVar7 = (undefined2 *)0x0;
            puVar2 = puStack_24;
          }
          else {
            zb_buf_cut_left_func(param_1,bVar1 + 3);
            puVar2 = puStack_24;
            if (puVar7 != (undefined2 *)0x0) {
              puVar8 = (undefined2 *)malloc(0xc);
              *puVar8 = *puVar7;
              bVar1 = *(byte *)(puVar7 + 1);
              *(byte *)(puVar8 + 1) = bVar1;
              __dest = malloc((uint)bVar1);
              *(void **)(puVar8 + 2) = __dest;
              memcpy(__dest,(void *)((int)puVar7 + 3),(uint)*(byte *)(puVar7 + 1));
              *(undefined4 *)(puVar8 + 4) = 0;
              puVar2 = puVar8;
              if (puVar9 != (undefined2 *)0x0) {
                *(undefined2 **)(puVar9 + 4) = puVar8;
                puVar2 = puStack_24;
              }
            }
          }
        }
        puStack_24 = puVar2;
        puVar9 = puVar8;
      } while (puVar7 != (undefined2 *)0x0);
      iVar5 = (*zb_core_action_cb)(0x1021,auStack_4c,zb_core_action_cb);
      puVar9 = puStack_24;
      while (puVar9 != (undefined2 *)0x0) {
        puVar8 = *(undefined2 **)(puVar9 + 4);
        free(puVar9);
        puVar9 = puVar8;
      }
    }
    else {
      uVar6 = esp_log_timestamp();
      esp_log_write(1,"ESP_ZIGBEE_CORE",&_LC19,uVar6,"ESP_ZIGBEE_CORE","zcl_scenes_view_scene_res",
                    0x83b);
    }
  }
  return iVar5;
}

