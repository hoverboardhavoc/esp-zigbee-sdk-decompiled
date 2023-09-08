/*
 * Last changed at upstream commit d50acd5408f73d4459b46a949332bb6e32f97543
 * https://github.com/espressif/esp-zigbee-sdk/commit/d50acd5408f73d4459b46a949332bb6e32f97543
 * Upstream date: 2023-09-08 17:20:56 +0800
 * Upstream subject: esp-zigbee-sdk: release/v0.9.4(89250ad3)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> zb_zcl_privilege_command_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

uint zb_zcl_privilege_command_handler(undefined4 param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  undefined1 auStack_44 [17];
  undefined1 uStack_33;
  undefined2 uStack_32;
  undefined1 uStack_2e;
  char cStack_2d;
  undefined2 uStack_28;
  undefined4 uStack_24;
  
  iVar1 = zb_buf_get_tail_func(0x1b);
  uVar2 = zcl_privilege_command_list_find(uStack_33,uStack_32,uStack_2e);
  uVar5 = uVar2;
  if (uVar2 != 0) {
    iVar3 = zb_zcl_basic_message_create(param_1,auStack_44);
    if (iVar3 == 0) {
      uStack_28 = zb_buf_len_func(param_1);
      uStack_24 = zb_buf_begin_func(param_1);
      iVar3 = 0;
      if (zb_core_action_cb != (code *)0x0) {
        if (cStack_2d == '\x01') {
          iVar3 = (*zb_core_action_cb)(0x1051,auStack_44);
        }
        else {
          iVar3 = (*zb_core_action_cb)(0x1050,auStack_44);
        }
      }
      if ((iVar1 != 0) && (uVar5 = (uint)*(byte *)(iVar1 + 0x17), uVar5 == 0)) {
        zb_zcl_send_default_handler(param_1,iVar1,iVar3 != 0);
        uVar5 = uVar2;
      }
    }
    else {
      uVar4 = esp_log_timestamp();
      esp_log_write(1,"ESP_ZIGBEE_CORE",&_L0,uVar4,"ESP_ZIGBEE_CORE",
                    "zb_zcl_privilege_command_handler",0x660);
    }
  }
  return uVar5;
}

