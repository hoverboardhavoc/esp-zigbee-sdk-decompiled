/*
 * Last changed at upstream commit 438301125bdfa70150622d905094f79315456774
 * https://github.com/espressif/esp-zigbee-sdk/commit/438301125bdfa70150622d905094f79315456774
 * Upstream date: 2024-04-26 19:22:10 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.3.0(a824e1a1)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_zcl_scenes.o -> zcl_scenes_recall_scene_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zcl_scenes_recall_scene_handler(undefined4 param_1)

{
  undefined1 uVar1;
  undefined2 *puVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  undefined1 *puVar7;
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
  
  iVar3 = zb_buf_get_tail_func(0x38);
  iVar4 = zb_buf_get_tail_func(param_1,0x38);
  puVar2 = *(undefined2 **)(iVar4 + 0x10);
  iVar4 = zb_buf_get_tail_func(param_1,0x38);
  iVar6 = *(int *)(iVar4 + 0xc);
  iVar4 = zb_buf_get_tail_func(param_1,0x38);
  puVar7 = *(undefined1 **)(iVar4 + 0x14);
  uVar1 = *(undefined1 *)(iVar6 + 0xc);
  uStack_38 = 0;
  uStack_34 = *(undefined1 *)(iVar3 + 4);
  uStack_32 = 5;
  uStack_30 = *(undefined1 *)(iVar6 + 0x13);
  uStack_2f = *(undefined1 *)(iVar6 + 0x14);
  uStack_2e = *(undefined1 *)(iVar6 + 0x16);
  uStack_2c = *puVar2;
  uStack_2a = *(undefined1 *)(puVar2 + 1);
  uStack_28 = *(undefined2 *)((int)puVar2 + 3);
  uStack_24 = 0;
  iVar3 = esp_zb_zcl_scenes_group_check(uVar1,*puVar2);
  *puVar7 = (char)iVar3;
  if (iVar3 == 0) {
    iVar3 = device_scenes_get_free_entry(uVar1,*puVar2,*(undefined1 *)(puVar2 + 1));
    if ((iVar3 == 0xff) || ((&DAT_00012bfa)[iVar3 * 6] == -1)) {
      *puVar7 = 0x8b;
      uStack_38 = 0x8b;
      uVar5 = esp_log_timestamp();
      esp_log_write(2,"ESP_ZIGBEE_ZCL_SCENES",&_LC10,uVar5,"ESP_ZIGBEE_ZCL_SCENES",
                    *(undefined1 *)(puVar2 + 1),*puVar2);
    }
    else {
      uStack_24 = (&DAT_00012c00)[iVar3 * 3];
      *puVar7 = 0;
      uVar5 = esp_log_timestamp();
      esp_log_write(3,"ESP_ZIGBEE_ZCL_SCENES",&_LC9,uVar5,"ESP_ZIGBEE_ZCL_SCENES",
                    *(undefined1 *)(puVar2 + 1),*puVar2);
    }
  }
  esp_zb_core_action_handler_schedule(2,&uStack_38);
  esp_err_to_zb_ret();
  return;
}

