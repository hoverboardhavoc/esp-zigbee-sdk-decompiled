/*
 * Last changed at upstream commit 37b2129eea9960f95d70bf2e6607337834e2750d
 * https://github.com/espressif/esp-zigbee-sdk/commit/37b2129eea9960f95d70bf2e6607337834e2750d
 * Upstream date: 2023-10-10 17:40:24 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.0.0(8d71c0ae)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> zb_zcl_custom_cluster_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zb_zcl_custom_cluster_handler(undefined4 param_1)

{
  undefined1 *puVar1;
  undefined1 uVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  byte *pbVar7;
  uint auStack_38 [4];
  undefined1 uStack_27;
  ushort uStack_26;
  undefined1 uStack_22;
  char cStack_21;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined1 uStack_14;
  
  iVar3 = zb_buf_get_tail_func(0x1b);
  iVar4 = zb_zcl_basic_message_create(param_1,auStack_38);
  if (iVar4 == 0) {
    if ((uStack_26 < 0xfc00) || (zb_core_action_cb == (code *)0x0)) {
      uVar6 = esp_log_timestamp();
      esp_log_write(2,"ESP_ZIGBEE_CORE",&_LC29,uVar6,"ESP_ZIGBEE_CORE",uStack_22,uStack_27,uStack_26
                   );
      uVar6 = 0;
    }
    else {
      if (cStack_21 == '\x01') {
        pbVar7 = (byte *)zb_buf_begin_func(param_1);
        auStack_38[0] = (uint)*pbVar7;
        uStack_1c = 0;
        uStack_18 = 0;
        uStack_14 = 0;
        iVar4 = (*zb_core_action_cb)(0x1041,auStack_38,zb_core_action_cb);
      }
      else {
        puVar5 = (undefined4 *)zb_buf_begin_func(param_1);
        auStack_38[0] = (uint)(puVar5 == (undefined4 *)0x0);
        if (puVar5 == (undefined4 *)0x0) {
          uStack_1c = 0;
          uVar2 = 0;
          puVar1 = (undefined1 *)0x0;
        }
        else {
          uStack_1c = *puVar5;
          uVar2 = zb_zcl_get_attribute_size(*(undefined1 *)puVar5,(undefined1 *)((int)puVar5 + 5));
          puVar1 = (undefined1 *)((int)puVar5 + 5);
        }
        uStack_18 = CONCAT13((char)((uint)puVar1 >> 0x10),
                             CONCAT12((char)((uint)puVar1 >> 8),CONCAT11((char)puVar1,uVar2)));
        uStack_14 = (undefined1)((uint)puVar1 >> 0x18);
        iVar4 = (*zb_core_action_cb)(0x1040,auStack_38,zb_core_action_cb);
      }
      if (iVar3 == 0) {
        uVar6 = 1;
      }
      else {
        zb_zcl_send_default_handler(param_1,iVar3,iVar4 != 0);
        uVar6 = 1;
      }
    }
  }
  else {
    uVar6 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_CORE",&_LC28,uVar6,"ESP_ZIGBEE_CORE","zb_zcl_custom_cluster_handler"
                  ,0x69a);
    uVar6 = 1;
  }
  return uVar6;
}

