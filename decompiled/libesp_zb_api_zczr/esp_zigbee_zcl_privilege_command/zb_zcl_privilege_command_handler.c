/*
 * Last changed at upstream commit e28462af08968da8dbda59a317df742f0109ee5f
 * https://github.com/espressif/esp-zigbee-sdk/commit/e28462af08968da8dbda59a317df742f0109ee5f
 * Upstream date: 2024-04-12 14:44:19 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.3(042315bf)
 * Source: libesp_zb_api_zczr -> esp_zigbee_zcl_privilege_command.o -> zb_zcl_privilege_command_handler
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
  undefined4 uVar4;
  bool bVar5;
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
      return 0;
    }
    uStack_18 = zb_buf_len_func(param_1);
    uStack_14 = zb_buf_begin_func(param_1);
    iVar2 = esp_zb_has_core_action_handler();
    if (iVar2 == 0) {
      bVar5 = false;
      if (iVar1 == 0) {
        return 1;
      }
    }
    else {
      if (cStack_1b == '\x01') {
        uVar4 = 0x1051;
      }
      else {
        uVar4 = 0x1050;
      }
      iVar2 = esp_zb_core_action_handler_schedule(uVar4,auStack_38);
      if (iVar1 == 0) {
        return 1;
      }
      bVar5 = iVar2 != 0;
    }
    zb_zcl_send_default_handler(param_1,iVar1,bVar5);
  }
  return 1;
}

