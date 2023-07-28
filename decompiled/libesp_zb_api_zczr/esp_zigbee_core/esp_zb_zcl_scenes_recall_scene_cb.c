/*
 * Last changed at upstream commit 992d2f5b99d09ff49d4d820bb9dc59b1d40be6d4
 * https://github.com/espressif/esp-zigbee-sdk/commit/992d2f5b99d09ff49d4d820bb9dc59b1d40be6d4
 * Upstream date: 2023-07-28 17:48:58 +0800
 * Upstream subject: esp-zigbee-sdk: release/v0.7.2(e1472baa)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> esp_zb_zcl_scenes_recall_scene_cb
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zcl_scenes_recall_scene_cb(undefined4 param_1)

{
  undefined2 *puVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined1 *puVar5;
  
  iVar2 = zb_buf_get_tail_func(0x38);
  puVar1 = *(undefined2 **)(iVar2 + 0x10);
  iVar2 = zb_buf_get_tail_func(param_1,0x38);
  puVar5 = *(undefined1 **)(iVar2 + 0x14);
  iVar2 = zb_buf_get_tail_func(param_1,0x38);
  iVar2 = esp_zb_zcl_scenes_group_check(*puVar1,*(undefined1 *)(*(int *)(iVar2 + 0xc) + 0xc));
  *puVar5 = (char)iVar2;
  if (iVar2 == 0) {
    iVar2 = device_scenes_get_free_entry(*puVar1,*(undefined1 *)(puVar1 + 1));
    if ((iVar2 == 0xff) || ((&esp_zb_zcl_scenes_table)[iVar2 * 6] == -1)) {
      *puVar5 = 0x8b;
      uVar3 = esp_log_timestamp();
      esp_log_write(2,"ESP_ZIGBEE_CORE",&_LC19,uVar3,"ESP_ZIGBEE_CORE",*(undefined1 *)(puVar1 + 1),
                    *puVar1);
      uVar3 = 0;
    }
    else {
      uVar3 = (&DAT_000136ec)[iVar2 * 3];
      *puVar5 = 0;
      uVar4 = esp_log_timestamp();
      esp_log_write(3,"ESP_ZIGBEE_CORE",&_L0,uVar4,"ESP_ZIGBEE_CORE",*(undefined1 *)(puVar1 + 1),
                    *puVar1);
    }
  }
  else {
    uVar3 = 0;
  }
  if (zcl_scenes_recall_user_cb != (code *)0x0) {
    (*zcl_scenes_recall_user_cb)(*puVar5,uVar3);
  }
  return;
}

