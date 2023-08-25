/*
 * Last changed at upstream commit 62f83e9155a8a668183e90087b29cd6791297d4c
 * https://github.com/espressif/esp-zigbee-sdk/commit/62f83e9155a8a668183e90087b29cd6791297d4c
 * Upstream date: 2023-08-25 15:56:34 +0800
 * Upstream subject: esp-zigbee-sdk: release/v0.9.1(b4845e06)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> zcl_scenes_store_scene_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zcl_scenes_store_scene_handler(undefined4 param_1)

{
  undefined2 uVar1;
  undefined3 *puVar2;
  undefined1 *puVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  undefined4 local_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  
  iVar4 = zb_buf_get_tail_func(0x38);
  iVar5 = zb_buf_get_tail_func(param_1,0x38);
  puVar2 = *(undefined3 **)(iVar5 + 0x10);
  iVar5 = zb_buf_get_tail_func(param_1,0x38);
  iVar7 = *(int *)(iVar5 + 0xc);
  iVar5 = zb_buf_get_tail_func(param_1,0x38);
  puVar3 = *(undefined1 **)(iVar5 + 0x14);
  uStack_30 = 0;
  uStack_2c = CONCAT31(uStack_2c._1_3_,*(undefined1 *)(iVar4 + 4));
  uStack_2c = CONCAT22(5,(undefined2)uStack_2c);
  uStack_28._0_3_ = CONCAT12(*(undefined1 *)(iVar7 + 0x16),*(undefined2 *)(iVar7 + 0x13));
  uStack_24 = CONCAT13(uStack_24._3_1_,*puVar2);
  iVar4 = esp_zb_zcl_scenes_group_check(*(undefined1 *)(iVar7 + 0xc));
  *puVar3 = (char)iVar4;
  if (iVar4 == 0) {
    uVar1 = *(undefined2 *)puVar2;
    iVar4 = device_scenes_get_free_entry(uVar1,*(undefined1 *)((int)puVar2 + 2));
    if (iVar4 == 0xff) {
      *puVar3 = 0x89;
      uStack_30 = 1;
      uVar6 = esp_log_timestamp();
      esp_log_write(2,"ESP_ZIGBEE_CORE",&_LC31,uVar6,"ESP_ZIGBEE_CORE",
                    *(undefined1 *)((int)puVar2 + 2));
      uVar6 = 0;
    }
    else {
      if ((&esp_zb_zcl_scenes_table)[iVar4 * 6] == -1) {
        (&esp_zb_zcl_scenes_table)[iVar4 * 6] = uVar1;
        (&DAT_0001467c)[iVar4 * 0xc] = *(undefined1 *)((int)puVar2 + 2);
        *(undefined2 *)(&DAT_0001467a + iVar4 * 0xc) = 0;
        uVar6 = esp_log_timestamp();
        esp_log_write(3,"ESP_ZIGBEE_CORE",&_LC30,uVar6,"ESP_ZIGBEE_CORE",
                      *(undefined1 *)((int)puVar2 + 2),*(undefined2 *)puVar2);
        uVar6 = 0;
      }
      else {
        uVar6 = esp_log_timestamp();
        esp_log_write(3,"ESP_ZIGBEE_CORE",&_LC29,uVar6,"ESP_ZIGBEE_CORE",
                      *(undefined1 *)((int)puVar2 + 2),*(undefined2 *)puVar2);
        uVar6 = 0xffffffe5;
      }
      *puVar3 = 0;
    }
  }
  else {
    uVar6 = 0;
  }
  if (zcl_scenes_store_user_cb != (code *)0x0) {
    local_40 = uStack_30;
    uStack_3c = uStack_2c;
    uStack_38 = uStack_28;
    uStack_34 = uStack_24;
    (*zcl_scenes_store_user_cb)(&local_40);
    uVar6 = error_to_zb_ret();
  }
  return uVar6;
}

