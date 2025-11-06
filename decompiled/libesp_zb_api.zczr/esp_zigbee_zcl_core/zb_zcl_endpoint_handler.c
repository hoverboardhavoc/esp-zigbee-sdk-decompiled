/*
 * Last changed at upstream commit ef60059b4d605d61a0103f81567229692f238007
 * https://github.com/espressif/esp-zigbee-sdk/commit/ef60059b4d605d61a0103f81567229692f238007
 * Upstream date: 2025-11-06 11:58:56 +0800
 * Upstream subject: esp-zigbee-sdk: (79cb709a)
 * Source: libesp_zb_api.zczr -> esp_zigbee_zcl_core.o -> zb_zcl_endpoint_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int zb_zcl_endpoint_handler(int param_1)

{
  short sVar1;
  int iVar2;
  undefined4 uVar3;
  short sVar4;
  int *piVar5;
  uint uVar6;
  
  uVar6 = param_1 - 1U & 0xff;
  iVar2 = zb_bufpool_storage_bufid_to_buf(uVar6);
  sVar4 = *(short *)(iVar2 + 4);
  iVar2 = zb_bufpool_storage_bufid_to_buf(uVar6);
  sVar1 = *(short *)(iVar2 + 6);
  if ((zcl_raw_command_cb == (code *)0x0) || (iVar2 = (*zcl_raw_command_cb)(param_1), iVar2 == 0)) {
    iVar2 = zb_bufpool_storage_bufid_to_buf(uVar6);
    if ((*(short *)(iVar2 + 4) != sVar4) ||
       (iVar2 = zb_bufpool_storage_bufid_to_buf(uVar6), *(short *)(iVar2 + 6) != sVar1)) {
      iVar2 = zb_bufpool_storage_bufid_to_buf(uVar6);
      *(char *)(iVar2 + 4) = (char)sVar4;
      *(char *)(iVar2 + 5) = (char)((ushort)sVar4 >> 8);
      iVar2 = zb_bufpool_storage_bufid_to_buf(uVar6);
      *(char *)(iVar2 + 6) = (char)sVar1;
      *(char *)(iVar2 + 7) = (char)((ushort)sVar1 >> 8);
    }
    iVar2 = zb_buf_get_tail_func(param_1,0x1b);
    if (*(char *)(iVar2 + 0x16) != '\0') {
      iVar2 = zb_zcl_general_cmd_handler(param_1);
      return iVar2;
    }
    iVar2 = zb_buf_get_tail_func(param_1,0x1b);
    if ((*(short *)(iVar2 + 0xf) < 0) ||
       (iVar2 = zb_buf_get_tail_func(param_1,0x1b), *(char *)(iVar2 + 0x18) == '\0')) {
      iVar2 = zb_buf_get_tail_func(param_1,0x1b);
      sVar4 = *(short *)(iVar2 + 0xf);
      piVar5 = s_endpoint_handler_list;
      if (sVar4 < 0) {
        sVar4 = -0x8000;
      }
      do {
        if (piVar5 + -2 == (int *)0xfffffff8) {
          if (-1 < sVar4) {
_L0:
            if (s_privilege_command_handler != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00010446. Too many branches */
                    /* WARNING: Treating indirect jump as call */
              iVar2 = (*s_privilege_command_handler)(param_1);
              return iVar2;
            }
          }
          return 0;
        }
        if (*(short *)(piVar5 + -2) == sVar4) {
          iVar2 = (*(code *)piVar5[-1])(param_1,(code *)piVar5[-1]);
          if (sVar4 < 0) {
            return iVar2;
          }
          if (iVar2 != 0) {
            return 1;
          }
          goto _L0;
        }
        piVar5 = (int *)*piVar5;
      } while( true );
    }
    uVar3 = zb_buf_get_tail_func(param_1,0x1b);
    zb_zcl_send_default_handler(param_1,uVar3,0x81);
  }
  return 1;
}

