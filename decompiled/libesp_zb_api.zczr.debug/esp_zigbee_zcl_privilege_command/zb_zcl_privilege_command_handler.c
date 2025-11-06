/*
 * Last changed at upstream commit ef60059b4d605d61a0103f81567229692f238007
 * https://github.com/espressif/esp-zigbee-sdk/commit/ef60059b4d605d61a0103f81567229692f238007
 * Upstream date: 2025-11-06 11:58:56 +0800
 * Upstream subject: esp-zigbee-sdk: (79cb709a)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_zcl_privilege_command.o -> zb_zcl_privilege_command_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zb_zcl_privilege_command_handler(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  undefined4 uVar5;
  undefined1 auStack_38 [23];
  undefined1 uStack_21;
  undefined2 uStack_20;
  undefined1 uStack_1c;
  char cStack_1b;
  undefined2 uStack_18;
  undefined4 uStack_14;
  
  iVar1 = zb_buf_get_tail_func(0x1b);
  iVar2 = zb_zcl_basic_message_create(param_1,auStack_38);
  if (iVar2 == 0) {
    piVar3 = (int *)zcl_privilege_command_list_find(uStack_21,uStack_20,uStack_1c);
    if (*piVar3 == 0) {
      uVar5 = 0;
    }
    else {
      uStack_18 = zb_buf_len_func(param_1);
      uStack_14 = zb_buf_begin_func(param_1);
      iVar4 = esp_zb_has_core_action_handler();
      iVar2 = 0;
      if (iVar4 != 0) {
        if (cStack_1b == '\x01') {
          iVar2 = esp_zb_core_action_handler_schedule(0x1051,auStack_38);
        }
        else {
          iVar2 = esp_zb_core_action_handler_schedule(0x1050,auStack_38);
        }
      }
      if (iVar1 == 0) {
        uVar5 = 1;
      }
      else {
        zb_zcl_send_default_handler(param_1,iVar1,iVar2 != 0);
        uVar5 = 1;
      }
    }
  }
  else {
    uVar5 = esp_log_timestamp();
    esp_log(1,"ESP_ZIGBEE_ZCL_PRIVILEGE_COMMAND",
            "E (%lu) %s: %s(%d): Failed to create privilege_command message\n",uVar5,
            "ESP_ZIGBEE_ZCL_PRIVILEGE_COMMAND","zb_zcl_privilege_command_handler",0x4d);
    uVar5 = 1;
  }
  return uVar5;
}

