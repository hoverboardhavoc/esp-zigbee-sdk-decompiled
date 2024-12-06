/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_core.o -> zb_zcl_endpoint_handler_callback
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zb_zcl_endpoint_handler_callback(int param_1)

{
  short sVar1;
  short sVar2;
  int iVar3;
  undefined4 uVar4;
  int *piVar5;
  uint uVar6;
  short sVar7;
  
  uVar6 = param_1 - 1U & 0xff;
  iVar3 = zb_bufpool_storage_bufid_to_buf(uVar6);
  sVar1 = *(short *)(iVar3 + 4);
  iVar3 = zb_bufpool_storage_bufid_to_buf(uVar6);
  sVar2 = *(short *)(iVar3 + 6);
  if (zcl_cli_resp_user_cb == (code *)0x0) {
    iVar3 = zb_buf_get_tail_func(param_1,0x1b);
    if (*(char *)(iVar3 + 0x16) == '\0') {
      iVar3 = zb_buf_get_tail_func(param_1,0x1b);
      sVar7 = *(short *)(iVar3 + 0xf);
      piVar5 = s_endpoint_handler_list;
      if (sVar7 < 0) {
        sVar7 = -0x8000;
      }
      for (; piVar5 + -2 != (int *)0xfffffff8; piVar5 = (int *)*piVar5) {
        if (*(short *)(piVar5 + -2) == sVar7) {
          iVar3 = (*(code *)piVar5[-1])(param_1,(code *)piVar5[-1]);
          goto _L0;
        }
      }
      iVar3 = 0;
_L0:
      if (-1 < sVar7) {
        if (iVar3 != 0) {
          return;
        }
        if (s_privilege_command_handler != (code *)0x0) {
          iVar3 = (*s_privilege_command_handler)(param_1);
        }
      }
    }
    else {
      iVar3 = zb_zcl_general_cmd_handler(param_1);
    }
    if ((iVar3 == 0) && (zcl_raw_command_cb != (code *)0x0)) {
      iVar3 = zb_bufpool_storage_bufid_to_buf(uVar6);
      if ((*(short *)(iVar3 + 4) != sVar1) ||
         (iVar3 = zb_bufpool_storage_bufid_to_buf(uVar6), *(short *)(iVar3 + 6) != sVar2)) {
        iVar3 = zb_bufpool_storage_bufid_to_buf(uVar6);
        *(char *)(iVar3 + 4) = (char)sVar1;
        *(char *)(iVar3 + 5) = (char)((ushort)sVar1 >> 8);
        iVar3 = zb_bufpool_storage_bufid_to_buf(uVar6);
        *(char *)(iVar3 + 6) = (char)sVar2;
        *(char *)(iVar3 + 7) = (char)((ushort)sVar2 >> 8);
        uVar4 = esp_log_timestamp();
        esp_log_write(2,"ESP_ZIGBEE_CORE",&_L0,uVar4,"ESP_ZIGBEE_CORE");
      }
      (*zcl_raw_command_cb)(param_1,zcl_raw_command_cb);
    }
  }
  else {
    (*zcl_cli_resp_user_cb)(param_1);
  }
  return;
}

