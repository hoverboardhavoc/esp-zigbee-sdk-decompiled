/*
 * Last changed at upstream commit ef60059b4d605d61a0103f81567229692f238007
 * https://github.com/espressif/esp-zigbee-sdk/commit/ef60059b4d605d61a0103f81567229692f238007
 * Upstream date: 2025-11-06 11:58:56 +0800
 * Upstream subject: esp-zigbee-sdk: (79cb709a)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_zcl_scenes.o -> zcl_scenes_store_scene_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int zcl_scenes_store_scene_handler(undefined4 param_1)

{
  undefined1 uVar1;
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
  uVar1 = *(undefined1 *)(iVar7 + 0xc);
  local_30 = 0;
  uStack_2c = *(undefined1 *)(iVar4 + 4);
  uStack_2a = 5;
  uStack_28 = *(undefined1 *)(iVar7 + 0x13);
  uStack_27 = *(undefined1 *)(iVar7 + 0x14);
  uStack_26 = *(undefined1 *)(iVar7 + 0x16);
  uStack_24 = *puVar2;
  uStack_22 = *(undefined1 *)(puVar2 + 1);
  iVar4 = esp_zb_zcl_scenes_group_check(uVar1,*puVar2);
  *puVar3 = (char)iVar4;
  if (iVar4 == 0) {
    iVar4 = device_scenes_get_free_entry(uVar1,*puVar2,*(undefined1 *)(puVar2 + 1));
    if (iVar4 == 0xff) {
      *puVar3 = 0x89;
      local_30 = 1;
      uVar6 = esp_log_timestamp();
      esp_log(2,"ESP_ZIGBEE_ZCL_SCENES",
              "W (%lu) %s: Insufficient scenes table for scene(0x%x), fail to store it\n",uVar6,
              "ESP_ZIGBEE_ZCL_SCENES",*(undefined1 *)(puVar2 + 1));
      iVar4 = 0;
    }
    else {
      iVar4 = iVar4 * 0xc + esp_zb_zcl_scenes_table;
      if (*(short *)(iVar4 + 2) == -1) {
        *(undefined2 *)(iVar4 + 2) = *puVar2;
        *(undefined1 *)(iVar4 + 6) = *(undefined1 *)(puVar2 + 1);
        *(undefined2 *)(iVar4 + 4) = 0;
        uVar6 = esp_log_timestamp();
        esp_log(3,"ESP_ZIGBEE_ZCL_SCENES",
                "I (%lu) %s: Store new scene(0x%x) of group(0x%x) to scenes table\n",uVar6,
                "ESP_ZIGBEE_ZCL_SCENES",*(undefined1 *)(puVar2 + 1),*puVar2);
        iVar4 = 0;
      }
      else {
        uVar6 = esp_log_timestamp();
        esp_log(3,"ESP_ZIGBEE_ZCL_SCENES","I (%lu) %s: Update existed scene(0x%x) for group(0x%x)\n"
                ,uVar6,"ESP_ZIGBEE_ZCL_SCENES",*(undefined1 *)(puVar2 + 1),*puVar2);
        iVar4 = -0x1b;
      }
      *puVar3 = 0;
    }
  }
  else {
    iVar4 = 0;
  }
  iVar7 = esp_zb_has_core_action_handler();
  iVar5 = iVar4;
  if (iVar7 != 0) {
    esp_zb_core_action_handler_schedule(1,&local_30);
    iVar7 = esp_err_to_zb_ret();
    iVar5 = iVar7;
    if ((iVar7 == 0) && (iVar5 = iVar4, iVar4 != -0x1b)) {
      iVar5 = iVar7;
    }
  }
  return iVar5;
}

