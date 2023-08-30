/*
 * Last changed at upstream commit c1113e88ee047f0eb31a91352a6fd0fc5318b6fd
 * https://github.com/espressif/esp-zigbee-sdk/commit/c1113e88ee047f0eb31a91352a6fd0fc5318b6fd
 * Upstream date: 2023-08-30 15:00:29 +0800
 * Upstream subject: esp-zigbee-sdk: release/v0.9.3(6da46788)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> zcl_scenes_recall_scene_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zcl_scenes_recall_scene_handler(undefined4 param_1)

{
  undefined2 *puVar1;
  undefined1 *puVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
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
  
  iVar3 = zb_buf_get_tail_func(0x38);
  iVar4 = zb_buf_get_tail_func(param_1,0x38);
  puVar1 = *(undefined2 **)(iVar4 + 0x10);
  iVar4 = zb_buf_get_tail_func(param_1,0x38);
  iVar6 = *(int *)(iVar4 + 0xc);
  iVar4 = zb_buf_get_tail_func(param_1,0x38);
  puVar2 = *(undefined1 **)(iVar4 + 0x14);
  uStack_38 = 0;
  uStack_34 = *(undefined1 *)(iVar3 + 4);
  uStack_32 = 5;
  uStack_30 = *(undefined1 *)(iVar6 + 0x13);
  uStack_2f = *(undefined1 *)(iVar6 + 0x14);
  uStack_2e = *(undefined1 *)(iVar6 + 0x16);
  uStack_2c = *puVar1;
  uStack_2a = *(undefined1 *)(puVar1 + 1);
  uStack_28 = *(undefined2 *)((int)puVar1 + 3);
  uStack_24 = 0;
  iVar3 = esp_zb_zcl_scenes_group_check(*puVar1,*(undefined1 *)(iVar6 + 0xc));
  *puVar2 = (char)iVar3;
  if (iVar3 == 0) {
    iVar3 = device_scenes_get_free_entry(*puVar1,*(undefined1 *)(puVar1 + 1));
    if ((iVar3 == 0xff) || ((&esp_zb_zcl_scenes_table)[iVar3 * 6] == -1)) {
      *puVar2 = 0x8b;
      uStack_38 = 0x8b;
      uVar5 = esp_log_timestamp();
      esp_log_write(2,"ESP_ZIGBEE_CORE",&_LC42,uVar5,"ESP_ZIGBEE_CORE",*(undefined1 *)(puVar1 + 1),
                    *puVar1);
    }
    else {
      uStack_24 = (&DAT_000156a8)[iVar3 * 3];
      *puVar2 = 0;
      uVar5 = esp_log_timestamp();
      esp_log_write(3,"ESP_ZIGBEE_CORE",&_LC41,uVar5,"ESP_ZIGBEE_CORE",*(undefined1 *)(puVar1 + 1),
                    *puVar1);
    }
  }
  if (zb_core_action_cb == (code *)0x0) {
    uVar5 = 0;
  }
  else {
    (*zb_core_action_cb)(2,&uStack_38);
    uVar5 = error_to_zb_ret();
  }
  return uVar5;
}

