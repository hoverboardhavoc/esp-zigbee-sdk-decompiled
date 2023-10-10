/*
 * Last changed at upstream commit 37b2129eea9960f95d70bf2e6607337834e2750d
 * https://github.com/espressif/esp-zigbee-sdk/commit/37b2129eea9960f95d70bf2e6607337834e2750d
 * Upstream date: 2023-10-10 17:40:24 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.0.0(8d71c0ae)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> zb_zcl_privilege_command_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int zb_zcl_privilege_command_handler(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  undefined1 auStack_44 [17];
  undefined1 uStack_33;
  undefined2 uStack_32;
  undefined1 uStack_2e;
  char cStack_2d;
  undefined2 uStack_28;
  undefined4 uStack_24;
  
  iVar1 = zb_buf_get_tail_func(0x1b);
  iVar2 = zb_zcl_basic_message_create(param_1,auStack_44);
  if (iVar2 == 0) {
    iVar2 = zcl_privilege_command_list_find(uStack_33,uStack_32,uStack_2e);
    if (iVar2 != 0) {
      uStack_28 = zb_buf_len_func(param_1);
      uStack_24 = zb_buf_begin_func(param_1);
      iVar4 = 0;
      if (zb_core_action_cb != (code *)0x0) {
        if (cStack_2d == '\x01') {
          iVar4 = (*zb_core_action_cb)(0x1051,auStack_44);
        }
        else {
          iVar4 = (*zb_core_action_cb)(0x1050,auStack_44);
        }
      }
      if (iVar1 != 0) {
        zb_zcl_send_default_handler(param_1,iVar1,iVar4 != 0);
      }
    }
  }
  else {
    uVar3 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_CORE",&_L0,uVar3,"ESP_ZIGBEE_CORE",
                  "zb_zcl_privilege_command_handler",0x67f);
    iVar2 = 1;
  }
  return iVar2;
}

