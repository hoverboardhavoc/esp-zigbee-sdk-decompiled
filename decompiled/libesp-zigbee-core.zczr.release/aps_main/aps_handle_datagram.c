/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> aps_main.o -> aps_handle_datagram
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void aps_handle_datagram(void *param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  byte bVar3;
  undefined1 auStack_24 [12];
  undefined1 uStack_18;
  undefined1 uStack_17;
  int iStack_14;
  
  if (((((0xfff7 < *(ushort *)((int)param_1 + 2)) || ((*(byte *)((int)param_1 + 0xc) & 2) != 0)) ||
       ((*(byte *)((int)param_1 + 0xc) & 0x40) == 0)) || (iVar2 = aps_send_ack(0,0xff), iVar2 == 0))
     && (iVar2 = aps_check_duplicates(param_1), iVar2 == 0)) {
    bVar3 = *(byte *)((int)param_1 + 0xc) & 3;
    if (bVar3 == 1) {
      aps_handle_cmd(param_1,param_2);
      return;
    }
    if (bVar3 == 2) {
      aps_retrans_handle_ack(param_1,param_2);
      return;
    }
    if ((*(byte *)((int)param_1 + 0xc) & 3) == 0) {
      memcpy(auStack_24,param_1,0xc);
      uStack_18 = *(undefined1 *)((int)param_1 + 0xf);
      uStack_17 = *(undefined1 *)((int)param_1 + 0x10);
      iStack_14 = param_2;
      uVar1 = zmsg_get_offset(param_2);
      zmsg_remove_header(param_2,uVar1);
      iVar2 = aps_apsde_user_data_indication(auStack_24);
      if (iVar2 == 0) {
        aps_apsde_data_indication(auStack_24);
      }
      return;
    }
  }
  if (param_2 == 0) {
    return;
  }
  zmsg_free(param_2);
  return;
}

