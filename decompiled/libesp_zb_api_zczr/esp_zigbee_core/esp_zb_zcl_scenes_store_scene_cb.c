/*
 * Last changed at upstream commit 992d2f5b99d09ff49d4d820bb9dc59b1d40be6d4
 * https://github.com/espressif/esp-zigbee-sdk/commit/992d2f5b99d09ff49d4d820bb9dc59b1d40be6d4
 * Upstream date: 2023-07-28 17:48:58 +0800
 * Upstream subject: esp-zigbee-sdk: release/v0.7.2(e1472baa)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> esp_zb_zcl_scenes_store_scene_cb
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zcl_scenes_store_scene_cb(undefined4 param_1)

{
  undefined2 uVar1;
  undefined2 *puVar2;
  int iVar3;
  undefined4 uVar4;
  undefined1 *puVar5;
  
  iVar3 = zb_buf_get_tail_func(0x38);
  puVar2 = *(undefined2 **)(iVar3 + 0x10);
  iVar3 = zb_buf_get_tail_func(param_1,0x38);
  puVar5 = *(undefined1 **)(iVar3 + 0x14);
  iVar3 = zb_buf_get_tail_func(param_1,0x38);
  iVar3 = esp_zb_zcl_scenes_group_check(*puVar2,*(undefined1 *)(*(int *)(iVar3 + 0xc) + 0xc));
  *puVar5 = (char)iVar3;
  if (iVar3 == 0) {
    uVar1 = *puVar2;
    iVar3 = device_scenes_get_free_entry(uVar1,*(undefined1 *)(puVar2 + 1));
    if (iVar3 == 0xff) {
      *puVar5 = 0x89;
      uVar4 = esp_log_timestamp();
      esp_log_write(2,"ESP_ZIGBEE_CORE",&_LC17,uVar4,"ESP_ZIGBEE_CORE",*(undefined1 *)(puVar2 + 1));
    }
    else {
      if ((&esp_zb_zcl_scenes_table)[iVar3 * 6] == -1) {
        (&esp_zb_zcl_scenes_table)[iVar3 * 6] = uVar1;
        (&DAT_000136e8)[iVar3 * 0xc] = *(undefined1 *)(puVar2 + 1);
        *(undefined2 *)(&DAT_000136e6 + iVar3 * 0xc) = 0;
        uVar4 = esp_log_timestamp();
        esp_log_write(3,"ESP_ZIGBEE_CORE",&_LC16,uVar4,"ESP_ZIGBEE_CORE",*(undefined1 *)(puVar2 + 1)
                      ,*puVar2);
      }
      else {
        *puVar5 = 0xe5;
        uVar4 = esp_log_timestamp();
        esp_log_write(3,"ESP_ZIGBEE_CORE",&_L0,uVar4,"ESP_ZIGBEE_CORE",*(undefined1 *)(puVar2 + 1),
                      *puVar2);
      }
      *puVar5 = 0;
    }
  }
  if (zcl_scenes_store_user_cb != (code *)0x0) {
    (*zcl_scenes_store_user_cb)(*puVar5,*puVar2,*(undefined1 *)(puVar2 + 1));
  }
  return;
}

