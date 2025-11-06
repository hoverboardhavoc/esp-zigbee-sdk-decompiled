/*
 * Last changed at upstream commit ef60059b4d605d61a0103f81567229692f238007
 * https://github.com/espressif/esp-zigbee-sdk/commit/ef60059b4d605d61a0103f81567229692f238007
 * Upstream date: 2025-11-06 11:58:56 +0800
 * Upstream subject: esp-zigbee-sdk: (79cb709a)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_zcl_scenes.o -> zcl_scenes_view_scene_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zcl_scenes_view_scene_handler(undefined4 param_1)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined2 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  undefined4 uVar9;
  undefined2 *puVar10;
  int iVar11;
  
  iVar4 = zb_buf_get_tail_func(0x38);
  puVar10 = *(undefined2 **)(iVar4 + 0x10);
  iVar4 = zb_buf_get_tail_func(param_1,0x38);
  iVar4 = *(int *)(iVar4 + 0xc);
  if ((puVar10 == (undefined2 *)0x0) || (iVar4 == 0)) {
    uVar9 = esp_log_timestamp();
    esp_log(1,"ESP_ZIGBEE_ZCL_SCENES","E (%lu) %s: %s(%d): Invalid view_scene request\n",uVar9,
            "ESP_ZIGBEE_ZCL_SCENES","zcl_scenes_view_scene_handler",0x1b9);
    uVar9 = 0xffffffff;
  }
  else {
    iVar5 = zb_buf_get_out_func();
    if (iVar5 == 0) {
      uVar9 = esp_log_timestamp();
      esp_log(1,"ESP_ZIGBEE_ZCL_SCENES",
              "E (%lu) %s: %s(%d): No buffer available to respond to view_scene request\n",uVar9,
              "ESP_ZIGBEE_ZCL_SCENES","zcl_scenes_view_scene_handler",0x1ba);
      uVar9 = 0xffffffff;
    }
    else {
      uVar1 = *(undefined1 *)(iVar4 + 0xc);
      uVar3 = *puVar10;
      uVar2 = *(undefined1 *)(puVar10 + 1);
      iVar6 = esp_zb_zcl_scenes_group_check(uVar1,uVar3);
      if (iVar6 == 0) {
        iVar11 = device_scenes_get_free_entry(uVar1,uVar3,uVar2);
        if (iVar11 == 0xff) {
          iVar6 = 0x8b;
        }
        else if (*(short *)(iVar11 * 0xc + esp_zb_zcl_scenes_table + 2) == -1) {
          iVar6 = 0x8b;
        }
      }
      else {
        iVar11 = 0xff;
      }
      puVar7 = (undefined1 *)zb_buf_reuse_func(iVar5);
      *puVar7 = 0x19;
      puVar7[1] = *(undefined1 *)(iVar4 + 0x15);
      puVar7[2] = 1;
      puVar7[3] = (char)iVar6;
      puVar7 = (undefined1 *)zb_put_next_htole16(puVar7 + 4,uVar3);
      *puVar7 = uVar2;
      puVar8 = puVar7 + 1;
      if (iVar6 == 0) {
        iVar6 = esp_zb_zcl_scenes_table + iVar11 * 0xc;
        puVar7[1] = *(undefined1 *)(iVar6 + 4);
        puVar7[2] = *(undefined1 *)(iVar6 + 5);
        puVar7[3] = 0;
        puVar8 = puVar7 + 4;
        for (puVar10 = *(undefined2 **)(iVar6 + 8); puVar10 != (undefined2 *)0x0;
            puVar10 = *(undefined2 **)(puVar10 + 4)) {
          puVar8 = (undefined1 *)zb_put_next_htole16(*puVar10);
          *puVar8 = *(undefined1 *)(puVar10 + 1);
          iVar6 = 0;
          while( true ) {
            puVar8 = puVar8 + 1;
            if ((int)(uint)*(byte *)(puVar10 + 1) <= iVar6) break;
            *puVar8 = *(undefined1 *)(*(int *)(puVar10 + 2) + iVar6);
            iVar6 = iVar6 + 1;
          }
        }
      }
      zb_zcl_finish_and_send_packet
                (iVar5,puVar8,iVar4 + 1,2,*(undefined1 *)(iVar4 + 0xb),*(undefined1 *)(iVar4 + 0xc),
                 *(undefined2 *)(iVar4 + 0x11),5);
      uVar9 = 0;
    }
  }
  return uVar9;
}

