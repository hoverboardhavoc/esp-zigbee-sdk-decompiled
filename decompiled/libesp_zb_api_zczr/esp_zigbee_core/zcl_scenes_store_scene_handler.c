/*
 * Last changed at upstream commit 0c62d9f04d6c4a739fd0a010d54749e3cd6ae209
 * https://github.com/espressif/esp-zigbee-sdk/commit/0c62d9f04d6c4a739fd0a010d54749e3cd6ae209
 * Upstream date: 2024-01-19 19:10:32 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.0.9(b7135493)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> zcl_scenes_store_scene_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int zcl_scenes_store_scene_handler(undefined4 param_1)

{
  undefined1 uVar1;
  undefined2 *puVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  undefined1 *puVar7;
  undefined4 local_30;
  undefined1 uStack_2c;
  undefined2 uStack_2a;
  undefined1 uStack_28;
  undefined1 uStack_27;
  undefined1 uStack_26;
  undefined2 uStack_24;
  undefined1 uStack_22;
  
  iVar3 = zb_buf_get_tail_func(0x38);
  iVar4 = zb_buf_get_tail_func(param_1,0x38);
  puVar2 = *(undefined2 **)(iVar4 + 0x10);
  iVar4 = zb_buf_get_tail_func(param_1,0x38);
  iVar6 = *(int *)(iVar4 + 0xc);
  iVar4 = zb_buf_get_tail_func(param_1,0x38);
  puVar7 = *(undefined1 **)(iVar4 + 0x14);
  uVar1 = *(undefined1 *)(iVar6 + 0xc);
  local_30 = 0;
  uStack_2c = *(undefined1 *)(iVar3 + 4);
  uStack_2a = 5;
  uStack_28 = *(undefined1 *)(iVar6 + 0x13);
  uStack_27 = *(undefined1 *)(iVar6 + 0x14);
  uStack_26 = *(undefined1 *)(iVar6 + 0x16);
  uStack_24 = *puVar2;
  uStack_22 = *(undefined1 *)(puVar2 + 1);
  iVar3 = esp_zb_zcl_scenes_group_check(uVar1,*puVar2);
  *puVar7 = (char)iVar3;
  if (iVar3 == 0) {
    iVar3 = device_scenes_get_free_entry(uVar1,*puVar2,*(undefined1 *)(puVar2 + 1));
    if (iVar3 == 0xff) {
      *puVar7 = 0x89;
      local_30 = 1;
      uVar5 = esp_log_timestamp();
      esp_log_write(2,"ESP_ZIGBEE_CORE",&_LC60,uVar5,"ESP_ZIGBEE_CORE",*(undefined1 *)(puVar2 + 1));
      iVar3 = 0;
    }
    else {
      if ((&DAT_00017822)[iVar3 * 6] == -1) {
        (&DAT_00017822)[iVar3 * 6] = *puVar2;
        (&DAT_00017826)[iVar3 * 0xc] = *(undefined1 *)(puVar2 + 1);
        *(undefined2 *)(&DAT_00017824 + iVar3 * 0xc) = 0;
        uVar5 = esp_log_timestamp();
        esp_log_write(3,"ESP_ZIGBEE_CORE",&_LC59,uVar5,"ESP_ZIGBEE_CORE",*(undefined1 *)(puVar2 + 1)
                      ,*puVar2);
        iVar3 = 0;
      }
      else {
        uVar5 = esp_log_timestamp();
        esp_log_write(3,"ESP_ZIGBEE_CORE",&_LC58,uVar5,"ESP_ZIGBEE_CORE",*(undefined1 *)(puVar2 + 1)
                      ,*puVar2);
        iVar3 = -0x1b;
      }
      *puVar7 = 0;
    }
  }
  else {
    iVar3 = 0;
  }
  iVar4 = iVar3;
  if (zb_core_action_cb != (code *)0x0) {
    (*zb_core_action_cb)(1,&local_30);
    iVar4 = esp_err_to_zb_ret();
    if ((iVar4 == 0) && (iVar3 == -0x1b)) {
      iVar4 = iVar3;
    }
  }
  return iVar4;
}

