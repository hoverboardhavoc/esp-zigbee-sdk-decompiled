/*
 * Last changed at upstream commit 3a2e620f73272cd71b1255d9566d72d6c662dd1c
 * https://github.com/espressif/esp-zigbee-sdk/commit/3a2e620f73272cd71b1255d9566d72d6c662dd1c
 * Upstream date: 2023-11-24 19:53:05 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.0.5(909d273b)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> zcl_scenes_store_scene_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zcl_scenes_store_scene_handler(undefined4 param_1)

{
  undefined2 uVar1;
  undefined2 *puVar2;
  undefined1 *puVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  undefined4 local_30;
  undefined1 uStack_2c;
  undefined2 uStack_2a;
  undefined1 uStack_28;
  undefined1 uStack_27;
  undefined1 uStack_26;
  undefined2 uStack_24;
  undefined1 uStack_22;
  
  iVar4 = zb_buf_get_tail_func(0x38);
  iVar5 = zb_buf_get_tail_func(param_1,0x38);
  puVar2 = *(undefined2 **)(iVar5 + 0x10);
  iVar5 = zb_buf_get_tail_func(param_1,0x38);
  iVar7 = *(int *)(iVar5 + 0xc);
  iVar5 = zb_buf_get_tail_func(param_1,0x38);
  puVar3 = *(undefined1 **)(iVar5 + 0x14);
  local_30 = 0;
  uStack_2c = *(undefined1 *)(iVar4 + 4);
  uStack_2a = 5;
  uStack_28 = *(undefined1 *)(iVar7 + 0x13);
  uStack_27 = *(undefined1 *)(iVar7 + 0x14);
  uStack_26 = *(undefined1 *)(iVar7 + 0x16);
  uStack_24 = *puVar2;
  uStack_22 = *(undefined1 *)(puVar2 + 1);
  iVar4 = esp_zb_zcl_scenes_group_check(*puVar2,*(undefined1 *)(iVar7 + 0xc));
  *puVar3 = (char)iVar4;
  if (iVar4 == 0) {
    uVar1 = *puVar2;
    iVar4 = device_scenes_get_free_entry(uVar1,*(undefined1 *)(puVar2 + 1));
    if (iVar4 == 0xff) {
      *puVar3 = 0x89;
      local_30 = 1;
      uVar6 = esp_log_timestamp();
      esp_log_write(2,"ESP_ZIGBEE_CORE",&_LC57,uVar6,"ESP_ZIGBEE_CORE",*(undefined1 *)(puVar2 + 1));
      uVar6 = 0;
    }
    else {
      if ((&esp_zb_zcl_scenes_table)[iVar4 * 6] == -1) {
        (&esp_zb_zcl_scenes_table)[iVar4 * 6] = uVar1;
        (&DAT_00016f3c)[iVar4 * 0xc] = *(undefined1 *)(puVar2 + 1);
        (&DAT_00016f3a)[iVar4 * 6] = 0;
        uVar6 = esp_log_timestamp();
        esp_log_write(3,"ESP_ZIGBEE_CORE",&_LC56,uVar6,"ESP_ZIGBEE_CORE",*(undefined1 *)(puVar2 + 1)
                      ,*puVar2);
        uVar6 = 0;
      }
      else {
        uVar6 = esp_log_timestamp();
        esp_log_write(3,"ESP_ZIGBEE_CORE",&_L0,uVar6,"ESP_ZIGBEE_CORE",*(undefined1 *)(puVar2 + 1),
                      *puVar2);
        uVar6 = 0xffffffe5;
      }
      *puVar3 = 0;
    }
  }
  else {
    uVar6 = 0;
  }
  if (zb_core_action_cb != (code *)0x0) {
    (*zb_core_action_cb)(1,&local_30);
    uVar6 = esp_err_to_zb_ret();
  }
  return uVar6;
}

