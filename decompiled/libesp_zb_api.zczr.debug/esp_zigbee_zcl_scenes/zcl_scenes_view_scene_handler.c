/*
 * Last changed at upstream commit 5becf8b58fd0c6a13fec507be821364ad0ceba39
 * https://github.com/espressif/esp-zigbee-sdk/commit/5becf8b58fd0c6a13fec507be821364ad0ceba39
 * Upstream date: 2025-01-14 03:03:09 +0000
 * Upstream subject: esp-zigbee-sdk: (acad93d1)
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
    esp_log_write(1,"ESP_ZIGBEE_ZCL_SCENES",&_LC7,uVar9,"ESP_ZIGBEE_ZCL_SCENES",
                  "zcl_scenes_view_scene_handler",0x18d);
    uVar9 = 0xffffffff;
  }
  else {
    iVar5 = zb_buf_get_out_func();
    if (iVar5 == 0) {
      uVar9 = esp_log_timestamp();
      esp_log_write(1,"ESP_ZIGBEE_ZCL_SCENES",&_LC8,uVar9,"ESP_ZIGBEE_ZCL_SCENES",
                    "zcl_scenes_view_scene_handler",0x18e);
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
        else if ((&DAT_00012c7e)[iVar11 * 6] == -1) {
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
        puVar7[1] = (&DAT_00012c80)[iVar11 * 0xc];
        puVar7[2] = (&DAT_00012c81)[iVar11 * 0xc];
        puVar7[3] = 0;
        puVar8 = puVar7 + 4;
        for (puVar10 = (undefined2 *)(&DAT_00012c84)[iVar11 * 3]; puVar10 != (undefined2 *)0x0;
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

