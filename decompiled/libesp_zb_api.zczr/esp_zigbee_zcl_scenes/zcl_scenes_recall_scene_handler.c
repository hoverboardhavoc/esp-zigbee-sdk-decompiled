/*
 * Last changed at upstream commit 88dfcd2f3748e37cbfac85eea52d0fdfbe99049b
 * https://github.com/espressif/esp-zigbee-sdk/commit/88dfcd2f3748e37cbfac85eea52d0fdfbe99049b
 * Upstream date: 2025-08-28 11:19:03 +0000
 * Upstream subject: esp-zigbee-sdk: (0166821f)
 * Source: libesp_zb_api.zczr -> esp_zigbee_zcl_scenes.o -> zcl_scenes_recall_scene_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zcl_scenes_recall_scene_handler(undefined4 param_1)

{
  undefined1 uVar1;
  undefined2 *puVar2;
  undefined1 *puVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 uStack_38;
  undefined1 uStack_34;
  undefined2 uStack_32;
  undefined1 uStack_30;
  undefined1 uStack_2f;
  undefined1 uStack_2e;
  undefined2 uStack_2c;
  undefined1 uStack_2a;
  undefined2 uStack_28;
  undefined4 uStack_24;
  
  iVar4 = zb_buf_get_tail_func(0x38);
  iVar5 = zb_buf_get_tail_func(param_1,0x38);
  puVar2 = *(undefined2 **)(iVar5 + 0x10);
  iVar5 = zb_buf_get_tail_func(param_1,0x38);
  iVar6 = *(int *)(iVar5 + 0xc);
  iVar5 = zb_buf_get_tail_func(param_1,0x38);
  uStack_34 = *(undefined1 *)(iVar4 + 4);
  uVar1 = *(undefined1 *)(iVar6 + 0xc);
  uStack_38 = 0;
  uStack_32 = 5;
  uStack_30 = *(undefined1 *)(iVar6 + 0x13);
  puVar3 = *(undefined1 **)(iVar5 + 0x14);
  uStack_2f = *(undefined1 *)(iVar6 + 0x14);
  uStack_2e = *(undefined1 *)(iVar6 + 0x16);
  uStack_2c = *puVar2;
  uStack_2a = *(undefined1 *)(puVar2 + 1);
  uStack_28 = *(undefined2 *)((int)puVar2 + 3);
  uStack_24 = 0;
  iVar4 = esp_zb_zcl_scenes_group_check(uVar1);
  *puVar3 = (char)iVar4;
  if (iVar4 == 0) {
    iVar4 = device_scenes_get_free_entry(uVar1,*puVar2,*(undefined1 *)(puVar2 + 1));
    if ((iVar4 == 0xff) ||
       (iVar4 = esp_zb_zcl_scenes_table + iVar4 * 0xc, *(short *)(iVar4 + 2) == -1)) {
      *puVar3 = 0x8b;
      uStack_38 = 0x8b;
    }
    else {
      uStack_24 = *(undefined4 *)(iVar4 + 8);
      *puVar3 = 0;
    }
  }
  esp_zb_core_action_handler_schedule(2,&uStack_38);
  esp_err_to_zb_ret();
  return;
}

