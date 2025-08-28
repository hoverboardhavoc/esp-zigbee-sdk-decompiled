/*
 * Last changed at upstream commit 88dfcd2f3748e37cbfac85eea52d0fdfbe99049b
 * https://github.com/espressif/esp-zigbee-sdk/commit/88dfcd2f3748e37cbfac85eea52d0fdfbe99049b
 * Upstream date: 2025-08-28 11:19:03 +0000
 * Upstream subject: esp-zigbee-sdk: (0166821f)
 * Source: libesp_zb_api.zczr -> esp_zigbee_zcl_core.o -> zb_zcl_endpoint_handler
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
  undefined4 uVar4;
  int *piVar5;
  uint uVar6;
  
  uVar6 = param_1 - 1U & 0xff;
  iVar3 = zb_bufpool_storage_bufid_to_buf(uVar6);
  sVar2 = *(short *)(iVar3 + 4);
  iVar3 = zb_bufpool_storage_bufid_to_buf(uVar6);
  sVar1 = *(short *)(iVar3 + 6);
  if ((zcl_raw_command_cb == (code *)0x0) || (iVar3 = (*zcl_raw_command_cb)(param_1), iVar3 == 0)) {
    iVar3 = zb_bufpool_storage_bufid_to_buf(uVar6);
    if ((*(short *)(iVar3 + 4) != sVar2) ||
       (iVar3 = zb_bufpool_storage_bufid_to_buf(uVar6), *(short *)(iVar3 + 6) != sVar1)) {
      iVar3 = zb_bufpool_storage_bufid_to_buf(uVar6);
      *(char *)(iVar3 + 4) = (char)sVar2;
      *(char *)(iVar3 + 5) = (char)((ushort)sVar2 >> 8);
      iVar3 = zb_bufpool_storage_bufid_to_buf(uVar6);
      *(char *)(iVar3 + 6) = (char)sVar1;
      *(char *)(iVar3 + 7) = (char)((ushort)sVar1 >> 8);
    }
    iVar3 = zb_buf_get_tail_func(param_1,0x1b);
    if (*(char *)(iVar3 + 0x16) != '\0') {
      iVar3 = zb_zcl_general_cmd_handler(param_1);
      return iVar3;
    }
    iVar3 = zb_buf_get_tail_func(param_1,0x1b);
    if ((*(short *)(iVar3 + 0xf) < 0) ||
       (iVar3 = zb_buf_get_tail_func(param_1,0x1b), *(char *)(iVar3 + 0x18) == '\0')) {
      iVar3 = zb_buf_get_tail_func(param_1,0x1b);
      sVar2 = *(short *)(iVar3 + 0xf);
      piVar5 = s_endpoint_handler_list;
      if (sVar2 < 0) {
        sVar2 = -0x8000;
      }
      for (; piVar5 + -2 != (int *)0xfffffff8; piVar5 = (int *)*piVar5) {
        if (*(short *)(piVar5 + -2) == sVar2) {
          iVar3 = (*(code *)piVar5[-1])(param_1,(code *)piVar5[-1]);
          goto _L0;
        }
      }
      iVar3 = 0;
_L0:
      if (sVar2 < 0) {
        return iVar3;
      }
      if (iVar3 == 0) {
        if (s_privilege_command_handler == (code *)0x0) {
          return 0;
        }
                    /* WARNING: Could not recover jumptable at 0x00010448. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        iVar3 = (*s_privilege_command_handler)(param_1);
        return iVar3;
      }
    }
    else {
      uVar4 = zb_buf_get_tail_func(param_1,0x1b);
      zb_zcl_send_default_handler(param_1,uVar4,0x81);
    }
  }
  return 1;
}

