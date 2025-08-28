/*
 * Last changed at upstream commit 88dfcd2f3748e37cbfac85eea52d0fdfbe99049b
 * https://github.com/espressif/esp-zigbee-sdk/commit/88dfcd2f3748e37cbfac85eea52d0fdfbe99049b
 * Upstream date: 2025-08-28 11:19:03 +0000
 * Upstream subject: esp-zigbee-sdk: (0166821f)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_zcl_core.o -> zb_zcl_endpoint_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int zb_zcl_endpoint_handler(int param_1)

{
  short sVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int *piVar6;
  uint uVar7;
  
  uVar7 = param_1 - 1U & 0xff;
  iVar3 = zb_bufpool_storage_bufid_to_buf(uVar7);
  sVar2 = *(short *)(iVar3 + 4);
  iVar3 = zb_bufpool_storage_bufid_to_buf(uVar7);
  sVar1 = *(short *)(iVar3 + 6);
  if (zcl_raw_command_cb == (code *)0x0) {
    iVar3 = 0;
  }
  else {
    iVar3 = (*zcl_raw_command_cb)(param_1);
    if (iVar3 != 0) {
      return iVar3;
    }
  }
  iVar4 = zb_bufpool_storage_bufid_to_buf(uVar7);
  if ((*(short *)(iVar4 + 4) != sVar2) ||
     (iVar4 = zb_bufpool_storage_bufid_to_buf(uVar7), *(short *)(iVar4 + 6) != sVar1)) {
    iVar4 = zb_bufpool_storage_bufid_to_buf(uVar7);
    *(char *)(iVar4 + 4) = (char)sVar2;
    *(char *)(iVar4 + 5) = (char)((ushort)sVar2 >> 8);
    iVar4 = zb_bufpool_storage_bufid_to_buf(uVar7);
    *(char *)(iVar4 + 6) = (char)sVar1;
    *(char *)(iVar4 + 7) = (char)((ushort)sVar1 >> 8);
    uVar5 = esp_log_timestamp();
    esp_log_write(2,"ESP_ZIGBEE_ZCL_CORE",&_LC3,uVar5,"ESP_ZIGBEE_ZCL_CORE");
  }
  iVar4 = zb_buf_get_tail_func(param_1,0x1b);
  if (*(char *)(iVar4 + 0x16) == '\0') {
    iVar4 = zb_buf_get_tail_func(param_1,0x1b);
    if ((*(short *)(iVar4 + 0xf) < 0) ||
       (iVar4 = zb_buf_get_tail_func(param_1,0x1b), *(char *)(iVar4 + 0x18) == '\0')) {
      iVar4 = zb_buf_get_tail_func(param_1,0x1b);
      sVar2 = *(short *)(iVar4 + 0xf);
      piVar6 = s_endpoint_handler_list;
      if (sVar2 < 0) {
        sVar2 = -0x8000;
      }
      for (; piVar6 + -2 != (int *)0xfffffff8; piVar6 = (int *)*piVar6) {
        if (sVar2 == *(short *)(piVar6 + -2)) {
          iVar3 = (*(code *)piVar6[-1])(param_1,(code *)piVar6[-1]);
          break;
        }
      }
      if (((-1 < sVar2) && (iVar3 == 0)) && (s_privilege_command_handler != (code *)0x0)) {
        iVar3 = (*s_privilege_command_handler)(param_1);
      }
    }
    else {
      uVar5 = zb_buf_get_tail_func(param_1,0x1b);
      zb_zcl_send_default_handler(param_1,uVar5,0x81);
      iVar3 = 1;
    }
  }
  else {
    iVar3 = zb_zcl_general_cmd_handler(param_1);
  }
  return iVar3;
}

