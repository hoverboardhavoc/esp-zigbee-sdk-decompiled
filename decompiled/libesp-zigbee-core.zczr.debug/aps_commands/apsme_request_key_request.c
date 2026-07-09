/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> aps_commands.o -> apsme_request_key_request
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int apsme_request_key_request(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iStack_18;
  int iStack_14;
  
  if (param_1 == (int *)0x0) {
    iVar2 = 2;
    iVar3 = 0;
  }
  else if (*param_1 == 0 && param_1[1] == 0) {
    iVar3 = 0;
    iVar2 = 2;
  }
  else if ((*param_1 == -1) && (param_1[1] == -1)) {
    iVar3 = 0;
    iVar2 = 2;
  }
  else {
    iVar3 = zmsg_alloc(0x3c);
    if (iVar3 == 0) {
      iVar2 = 1;
    }
    else {
      aps_frame_append_cmd_hdr(0,1,0);
      iStack_18._0_1_ = 8;
      zmsg_append_bytes(iVar3,1,&iStack_18);
      iStack_18 = CONCAT31(iStack_18._1_3_,(char)param_1[2]);
      zmsg_append_bytes(iVar3,1,&iStack_18);
      if ((char)param_1[2] == '\x02') {
        iVar2 = *(int *)((int)param_1 + 9);
        iVar1 = *(int *)((int)param_1 + 0xd);
        if (iVar2 == 0 && iVar1 == 0) {
          iVar2 = 2;
          goto _L0;
        }
        if ((iVar2 == -1) && (iVar1 == -1)) {
          iVar2 = 2;
          goto _L0;
        }
        iStack_18 = iVar2;
        iStack_14 = iVar1;
        zmsg_append_bytes(iVar3,8,&iStack_18);
      }
      else if ((char)param_1[2] != '\x04') {
        iVar2 = 2;
        goto _L0;
      }
      iVar2 = aps_send_cmd(iVar3,param_1);
      if (iVar2 == 0) {
        return 0;
      }
    }
  }
_L0:
  if (iVar3 != 0) {
    zmsg_free(iVar3);
  }
  return iVar2;
}

