/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.debug -> aps_commands.o -> apsme_remove_device_request
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int apsme_remove_device_request(int *param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iStack_18;
  int iStack_14;
  
  if (param_1 == (int *)0x0) {
    iVar3 = 2;
    iVar2 = 0;
  }
  else if (*param_1 == 0 && param_1[1] == 0) {
    iVar2 = 0;
    iVar3 = 2;
  }
  else if ((*param_1 == -1) && (param_1[1] == -1)) {
    iVar2 = 0;
    iVar3 = 2;
  }
  else if (param_1[2] == 0 && param_1[3] == 0) {
    iVar2 = 0;
    iVar3 = 2;
  }
  else if ((param_1[2] == -1) && (param_1[3] == -1)) {
    iVar2 = 0;
    iVar3 = 2;
  }
  else {
    piVar1 = (int *)nwk_get_extended_address();
    if ((*param_1 == *piVar1) && (param_1[1] == piVar1[1])) {
      apsme_remove_device_indication(param_1);
      return 0;
    }
    iVar2 = zmsg_alloc(0x3c);
    if (iVar2 == 0) {
      iVar3 = 1;
    }
    else {
      aps_frame_append_cmd_hdr(0,1,0);
      iStack_18 = CONCAT31(iStack_18._1_3_,7);
      zmsg_append_bytes(iVar2,1,&iStack_18);
      iStack_18 = param_1[2];
      iStack_14 = param_1[3];
      zmsg_append_bytes(iVar2,8,&iStack_18);
      iVar3 = aps_send_cmd(iVar2,param_1);
      if (iVar3 == 0) {
        return 0;
      }
    }
  }
  if (iVar2 != 0) {
    zmsg_free(iVar2);
  }
  return iVar3;
}

