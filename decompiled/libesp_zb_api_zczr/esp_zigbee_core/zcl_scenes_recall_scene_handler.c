/*
 * Last changed at upstream commit fdd7b02c333322a6b0be71e313fe2aad2eac22c5
 * https://github.com/espressif/esp-zigbee-sdk/commit/fdd7b02c333322a6b0be71e313fe2aad2eac22c5
 * Upstream date: 2023-08-11 14:15:41 +0800
 * Upstream subject: esp-zigbee-sdk: release/v0.9.0(793f8578)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> zcl_scenes_recall_scene_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zcl_scenes_recall_scene_handler(undefined4 param_1)

{
  undefined3 *puVar1;
  undefined1 *puVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 local_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  
  iVar3 = zb_buf_get_tail_func(0x38);
  iVar4 = zb_buf_get_tail_func(param_1,0x38);
  puVar1 = *(undefined3 **)(iVar4 + 0x10);
  iVar4 = zb_buf_get_tail_func(param_1,0x38);
  iVar6 = *(int *)(iVar4 + 0xc);
  iVar4 = zb_buf_get_tail_func(param_1,0x38);
  puVar2 = *(undefined1 **)(iVar4 + 0x14);
  uStack_38 = 0;
  uStack_34 = CONCAT31(uStack_34._1_3_,*(undefined1 *)(iVar3 + 4));
  uStack_34 = CONCAT22(5,(undefined2)uStack_34);
  uStack_30._0_3_ = CONCAT12(*(undefined1 *)(iVar6 + 0x16),*(undefined2 *)(iVar6 + 0x13));
  uStack_2c = CONCAT13(uStack_2c._3_1_,*puVar1);
  uStack_28 = CONCAT22(uStack_28._2_2_,*(undefined2 *)((int)puVar1 + 3));
  uStack_24 = 0;
  iVar3 = esp_zb_zcl_scenes_group_check(*(undefined1 *)(iVar6 + 0xc));
  *puVar2 = (char)iVar3;
  if (iVar3 == 0) {
    iVar3 = device_scenes_get_free_entry(*(undefined2 *)puVar1,*(undefined1 *)((int)puVar1 + 2));
    if ((iVar3 == 0xff) || ((&esp_zb_zcl_scenes_table)[iVar3 * 6] == -1)) {
      *puVar2 = 0x8b;
      uStack_38 = 0x8b;
      uVar5 = esp_log_timestamp();
      esp_log_write(2,"ESP_ZIGBEE_CORE",&_LC26,uVar5,"ESP_ZIGBEE_CORE",
                    *(undefined1 *)((int)puVar1 + 2),*(undefined2 *)puVar1);
    }
    else {
      uStack_24 = (&DAT_000145cc)[iVar3 * 3];
      *puVar2 = 0;
      uVar5 = esp_log_timestamp();
      esp_log_write(3,"ESP_ZIGBEE_CORE",&_LC25,uVar5,"ESP_ZIGBEE_CORE",
                    *(undefined1 *)((int)puVar1 + 2),*(undefined2 *)puVar1);
    }
  }
  if (zcl_scenes_recall_user_cb == (code *)0x0) {
    uVar5 = 0;
  }
  else {
    local_60 = uStack_38;
    uStack_5c = uStack_34;
    uStack_58 = uStack_30;
    uStack_54 = uStack_2c;
    uStack_50 = uStack_28;
    uStack_4c = uStack_24;
    (*zcl_scenes_recall_user_cb)(&local_60);
    uVar5 = error_to_zb_ret();
  }
  return uVar5;
}

