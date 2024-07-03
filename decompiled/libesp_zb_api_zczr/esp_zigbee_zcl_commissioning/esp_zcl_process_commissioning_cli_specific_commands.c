/*
 * Last changed at upstream commit 144e7499ed4e1cce68f5de0341b465c0d192496c
 * https://github.com/espressif/esp-zigbee-sdk/commit/144e7499ed4e1cce68f5de0341b465c0d192496c
 * Upstream date: 2024-07-03 12:16:21 +0000
 * Upstream subject: esp-zigbee-lib:(290e291c)
 * Source: libesp_zb_api_zczr -> esp_zigbee_zcl_commissioning.o -> esp_zcl_process_commissioning_cli_specific_commands
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zcl_process_commissioning_cli_specific_commands(int param_1)

{
  undefined1 uVar1;
  int iVar2;
  byte *pbVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uStack_3c;
  ushort uStack_38;
  short sStack_36;
  uint uStack_34;
  undefined1 auStack_30 [23];
  byte bStack_19;
  short sStack_18;
  byte bStack_14;
  char cStack_13;
  
  if (param_1 == 0xff) {
    iVar2 = zb_zcl_get_ctx();
    *(undefined1 **)(iVar2 + 0x2e0) = s_commissioning_client_cmd_list;
  }
  else {
    iVar2 = zb_zcl_basic_message_create(auStack_30);
    if (iVar2 == 0) {
      if (sStack_18 != 0x15) {
        zb_assert("/builds/thread_zigbee/esp-zboss/components/esp_zb_sdk/src/zcl/esp_zigbee_zcl_commissioning.c"
                  ,0x2a4);
      }
      if (cStack_13 != '\x01') {
        return 0;
      }
      if (3 < bStack_14) {
        return 0;
      }
      _uStack_38 = CONCAT22(sStack_18,(ushort)bStack_19);
      uStack_3c = 0;
      uStack_34 = 0;
      pbVar3 = (byte *)zb_buf_begin_func(param_1);
      uStack_34 = (uint)*pbVar3;
      uVar4 = esp_zb_core_action_handler_schedule(0x1c,&uStack_3c);
      uVar5 = zb_buf_get_tail_func(param_1,0x1b);
      uVar1 = esp_err_to_zcl_status(uVar4);
      zb_zcl_send_default_handler(param_1,uVar5,uVar1);
    }
  }
  return 1;
}

