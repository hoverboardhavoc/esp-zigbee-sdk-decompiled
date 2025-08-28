/*
 * Last changed at upstream commit 88dfcd2f3748e37cbfac85eea52d0fdfbe99049b
 * https://github.com/espressif/esp-zigbee-sdk/commit/88dfcd2f3748e37cbfac85eea52d0fdfbe99049b
 * Upstream date: 2025-08-28 11:19:03 +0000
 * Upstream subject: esp-zigbee-sdk: (0166821f)
 * Source: libesp_zb_api.zczr -> esp_zigbee_zcl_scenes.o -> zcl_scenes_view_scene_handler
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
  undefined2 *puVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  int iVar9;
  undefined1 *puVar10;
  undefined1 *puVar11;
  
  iVar6 = zb_buf_get_tail_func(0x38);
  puVar4 = *(undefined2 **)(iVar6 + 0x10);
  iVar6 = zb_buf_get_tail_func(param_1,0x38);
  iVar6 = *(int *)(iVar6 + 0xc);
  if (((puVar4 == (undefined2 *)0x0) || (iVar6 == 0)) || (iVar8 = zb_buf_get_out_func(), iVar8 == 0)
     ) {
    uVar7 = 0xffffffff;
  }
  else {
    uVar3 = *puVar4;
    uVar1 = *(undefined1 *)(iVar6 + 0xc);
    uVar2 = *(undefined1 *)(puVar4 + 1);
    iVar9 = esp_zb_zcl_scenes_group_check(uVar1,uVar3);
    iVar5 = 0xff;
    if ((iVar9 == 0) &&
       ((iVar5 = device_scenes_get_free_entry(uVar1,uVar3,uVar2), iVar5 == 0xff ||
        (*(short *)(esp_zb_zcl_scenes_table + iVar5 * 0xc + 2) == -1)))) {
      iVar9 = 0x8b;
    }
    puVar10 = (undefined1 *)zb_buf_reuse_func(iVar8);
    *puVar10 = 0x19;
    uVar1 = *(undefined1 *)(iVar6 + 0x15);
    puVar10[3] = (char)iVar9;
    puVar10[1] = uVar1;
    puVar10[2] = 1;
    puVar10 = (undefined1 *)zb_put_next_htole16(puVar10 + 4,uVar3);
    *puVar10 = uVar2;
    puVar11 = puVar10 + 1;
    if (iVar9 == 0) {
      iVar5 = esp_zb_zcl_scenes_table + iVar5 * 0xc;
      puVar10[1] = *(undefined1 *)(iVar5 + 4);
      puVar10[2] = *(undefined1 *)(iVar5 + 5);
      puVar10[3] = 0;
      puVar11 = puVar10 + 4;
      for (puVar4 = *(undefined2 **)(iVar5 + 8); puVar4 != (undefined2 *)0x0;
          puVar4 = *(undefined2 **)(puVar4 + 4)) {
        puVar11 = (undefined1 *)zb_put_next_htole16(*puVar4);
        *puVar11 = *(undefined1 *)(puVar4 + 1);
        iVar5 = 0;
        while( true ) {
          puVar11 = puVar11 + 1;
          if ((int)(uint)*(byte *)(puVar4 + 1) <= iVar5) break;
          puVar10 = (undefined1 *)(*(int *)(puVar4 + 2) + iVar5);
          iVar5 = iVar5 + 1;
          *puVar11 = *puVar10;
        }
      }
    }
    zb_zcl_finish_and_send_packet
              (iVar8,puVar11,iVar6 + 1,2,*(undefined1 *)(iVar6 + 0xb),*(undefined1 *)(iVar6 + 0xc),
               *(undefined2 *)(iVar6 + 0x11),5);
    uVar7 = 0;
  }
  return uVar7;
}

