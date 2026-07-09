/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> aps_commands.o -> apsme_update_device_request
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int apsme_update_device_request(int *param_1)

{
  short sVar1;
  short sVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  int iStack_28;
  int iStack_24;
  
  if (param_1 == (int *)0x0) {
    iVar5 = 2;
    iVar4 = 0;
  }
  else if (*param_1 == 0 && param_1[1] == 0) {
    iVar4 = 0;
    iVar5 = 2;
  }
  else if ((*param_1 == -1) && (param_1[1] == -1)) {
    iVar4 = 0;
    iVar5 = 2;
  }
  else {
    piVar3 = (int *)nwk_get_extended_address();
    if ((*param_1 == *piVar3) && (param_1[1] == piVar3[1])) {
      apsme_update_device_indication(param_1);
      return 0;
    }
    iVar4 = zmsg_alloc(0x3c);
    if (iVar4 == 0) {
      iVar5 = 1;
    }
    else {
      aps_frame_append_cmd_hdr(0,1,0);
      iStack_28 = CONCAT31(iStack_28._1_3_,6);
      zmsg_append_bytes(iVar4,1,&iStack_28);
      iStack_28 = param_1[2];
      iStack_24 = param_1[3];
      zmsg_append_bytes(iVar4,8,&iStack_28);
      iStack_28 = CONCAT22(iStack_28._2_2_,(short)param_1[4]);
      zmsg_append_bytes(iVar4,2,&iStack_28);
      iStack_28 = CONCAT31(iStack_28._1_3_,*(undefined1 *)((int)param_1 + 0x12));
      zmsg_append_bytes(iVar4,1,&iStack_28);
      iVar5 = aps_secur_get_key_pair_by_addr(param_1);
      if (((iVar5 == 0) || ((*(ushort *)(iVar5 + 0x34) & 1) != 0)) &&
         (iVar5 = zmsg_alloc(0x2f), iVar5 != 0)) {
        aps_frame_append_cmd_hdr(0,1,0,0);
        uVar6 = zmsg_get_offset(iVar4);
        sVar1 = zmsg_get_length(iVar4);
        sVar2 = zmsg_get_offset(iVar4);
        iVar7 = zmsg_append_bytes_from_msg(iVar5,iVar4,uVar6,sVar1 - sVar2);
        if ((iVar7 != 0) || (iVar7 = aps_send_cmd(iVar5,param_1), iVar7 != 0)) {
          zmsg_free(iVar5);
        }
      }
      iVar5 = aps_send_cmd(iVar4,param_1);
      if (iVar5 == 0) {
        return 0;
      }
    }
  }
  if (iVar4 != 0) {
    zmsg_free(iVar4);
  }
  return iVar5;
}

