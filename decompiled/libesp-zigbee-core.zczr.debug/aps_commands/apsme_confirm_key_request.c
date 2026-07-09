/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> aps_commands.o -> apsme_confirm_key_request
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int apsme_confirm_key_request(int *param_1)

{
  int iVar1;
  int iVar2;
  int iStack_18;
  int iStack_14;
  
  if (param_1 == (int *)0x0) {
    iVar1 = 2;
    iVar2 = 0;
  }
  else if (*param_1 == 0 && param_1[1] == 0) {
    iVar2 = 0;
    iVar1 = 2;
  }
  else if ((*param_1 == -1) && (param_1[1] == -1)) {
    iVar2 = 0;
    iVar1 = 2;
  }
  else {
    if ((char)param_1[2] == '\x03') {
      iVar2 = aps_secur_is_addr_tc(param_1);
      if (iVar2 != 0) {
        iVar2 = 0;
        iVar1 = 0x3a6;
        goto _L0;
      }
    }
    else if ((char)param_1[2] == '\x04') {
      iVar2 = aps_secur_is_tc();
      if (iVar2 == 0) {
        iVar2 = 0;
        iVar1 = 0x3a3;
      }
      else {
        iVar2 = zmsg_alloc(0x3c);
        if (iVar2 == 0) {
          iVar1 = 1;
        }
        else {
          aps_frame_append_cmd_hdr(0,1,0);
          iStack_18._0_1_ = 0x10;
          zmsg_append_bytes(iVar2,1,&iStack_18);
          iStack_18._0_1_ = *(undefined1 *)((int)param_1 + 9);
          zmsg_append_bytes(iVar2,1,&iStack_18);
          iStack_18 = CONCAT31(iStack_18._1_3_,(char)param_1[2]);
          zmsg_append_bytes(iVar2,1,&iStack_18);
          iStack_18 = *param_1;
          iStack_14 = param_1[1];
          zmsg_append_bytes(iVar2,8,&iStack_18);
          iVar1 = aps_send_cmd(iVar2,param_1);
          if (iVar1 == 0) {
            return 0;
          }
        }
      }
      goto _L0;
    }
    iVar2 = 0;
    iVar1 = 0x3aa;
  }
_L0:
  if (iVar2 != 0) {
    zmsg_free(iVar2);
  }
  return iVar1;
}

