/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> mac.o -> mac_iface_mcps_data_request
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int mac_iface_mcps_data_request(int *param_1,int *param_2)

{
  undefined2 uVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  undefined2 local_40;
  undefined2 uStack_3e;
  undefined1 auStack_3c [40];
  
  iVar5 = *param_1;
  iVar2 = 3;
  if ((((*(uint *)(iVar5 + 0x9c) & 1) != 0) && (iVar2 = 2, param_2 != (int *)0x0)) &&
     (iVar6 = *param_2, iVar6 != 0)) {
    uVar1 = *(undefined2 *)(iVar5 + 10);
    memset(auStack_3c,0,0x1c);
    uStack_3e = (undefined2)param_2[6];
    local_40 = uVar1;
    uVar3 = mac_frame_write_hdr(auStack_3c,param_2 + 1,&local_40,0,1,0);
    iVar2 = zmsg_prepend_bytes(iVar6,uVar3,auStack_3c);
    if (iVar2 == 0) {
      uVar4 = zmsg_get_length(iVar6);
      if (uVar4 < 0x7e) {
        if ((*(byte *)((int)param_2 + 0x1a) & 2) == 0) {
          zmsg_queue_enqueue(iVar5 + 0x48,iVar6);
          if ((*(char *)(iVar5 + 0x2e) != '\x04') && ((*(ushort *)(iVar5 + 0x30) & 0x10) == 0)) {
            mac_start_op(iVar5);
          }
        }
        else {
          mac_indirect_transmit(iVar5,(int)param_2 + 0xe,iVar6);
        }
      }
      else {
        iVar2 = 4;
      }
    }
  }
  return iVar2;
}

