/*
 * Last changed at upstream commit 6663e9a47e70aeb89bdde3d1385b4fa8af6242fa
 * https://github.com/espressif/esp-zigbee-sdk/commit/6663e9a47e70aeb89bdde3d1385b4fa8af6242fa
 * Upstream date: 2023-11-21 18:28:11 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.0.4(be3a8a97)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> zb_zcl_custom_cluster_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zb_zcl_custom_cluster_handler(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  uint auStack_38 [5];
  undefined1 uStack_21;
  ushort uStack_20;
  undefined1 uStack_1c;
  char cStack_1b;
  undefined1 uStack_18;
  undefined4 uStack_14;
  
  iVar1 = zb_buf_get_tail_func(0x1b);
  iVar2 = zb_zcl_basic_message_create(param_1,auStack_38);
  if (iVar2 == 0) {
    if ((uStack_20 < 0xfc00) || (zb_core_action_cb == (code *)0x0)) {
      uVar3 = esp_log_timestamp();
      esp_log_write(2,"ESP_ZIGBEE_CORE",&_LC18,uVar3,"ESP_ZIGBEE_CORE",uStack_1c,uStack_21,uStack_20
                   );
      uVar3 = 0;
    }
    else {
      auStack_38[0] = (uint)(iVar1 == 0);
      uStack_18 = zb_buf_len_func(param_1);
      uStack_14 = zb_buf_begin_func(param_1);
      iVar2 = 0;
      if (cStack_1b == '\x01') {
        if (zb_core_action_cb != (code *)0x0) {
          iVar2 = (*zb_core_action_cb)(0x1041,auStack_38);
        }
      }
      else if (zb_core_action_cb != (code *)0x0) {
        iVar2 = (*zb_core_action_cb)(0x1040,auStack_38);
      }
      if (iVar1 == 0) {
        uVar3 = 1;
      }
      else {
        zb_zcl_send_default_handler(param_1,iVar1,iVar2 != 0);
        uVar3 = 1;
      }
    }
  }
  else {
    uVar3 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_CORE",&_LC17,uVar3,"ESP_ZIGBEE_CORE","zb_zcl_custom_cluster_handler"
                  ,0x8e5);
    uVar3 = 1;
  }
  return uVar3;
}

