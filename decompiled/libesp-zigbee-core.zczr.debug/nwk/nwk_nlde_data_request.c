/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk.o -> nwk_nlde_data_request
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int nwk_nlde_data_request(int *param_1)

{
  undefined2 uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  char cStack_11;
  
  if (param_1 == (int *)0x0) {
    iVar2 = 2;
  }
  else {
    iVar5 = *param_1;
    if (iVar5 == 0) {
      iVar2 = 2;
    }
    else {
      iVar2 = nwk_is_joined();
      if (iVar2 == 0) {
        iVar2 = 3;
      }
      else {
        zmsg_set_offset(iVar5,0);
        if ((*(byte *)((int)param_1 + 10) & 4) == 0) {
          iVar2 = core_globals_get();
          uVar1 = *(undefined2 *)(iVar2 + 0x9e2);
        }
        else {
          uVar1 = (undefined2)param_1[2];
        }
        iVar2 = nwk_frame_write_hdr(iVar5,uVar1,(short)param_1[1],*(undefined1 *)((int)param_1 + 6),
                                    0,(uint)param_1[2] >> 0x10 & 1,(uint)param_1[2] >> 0x11 & 1);
        if (iVar2 == 0) {
          uVar3 = zmsg_get_length(iVar5);
          if (uVar3 < 0x71) {
            if ((*(byte *)((int)param_1 + 10) & 4) == 0) {
              iVar4 = core_globals_get();
              cStack_11 = *(char *)(iVar4 + 0x9d9);
              *(char *)(iVar4 + 0x9d9) = cStack_11 + '\x01';
            }
            else {
              cStack_11 = *(char *)((int)param_1 + 7);
            }
            zmsg_write_bytes(iVar5,7,1,&cStack_11);
            nwk_fwd_send_msg_delayed(iVar5,0);
          }
          else {
            iVar2 = 4;
          }
        }
      }
    }
  }
  return iVar2;
}

