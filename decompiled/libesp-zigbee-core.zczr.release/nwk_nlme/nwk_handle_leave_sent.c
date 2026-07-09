/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> nwk_nlme.o -> nwk_handle_leave_sent
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_handle_leave_sent(int param_1,int param_2)

{
  byte bVar1;
  uint uVar2;
  short sVar3;
  int iVar4;
  byte bStack_21;
  undefined1 uStack_20;
  undefined1 uStack_1f;
  undefined1 auStack_1e [2];
  undefined1 auStack_1c [8];
  byte bStack_14;
  
  bStack_21 = 0;
  sVar3 = zmsg_get_offset();
  zmsg_read_bytes(param_1,sVar3 + 1,1,&bStack_21);
  bVar1 = bStack_21;
  uVar2 = (uint)bStack_21;
  if ((bStack_21 & 0x40) == 0) {
    iVar4 = core_globals_get();
    if (*(char *)(iVar4 + 0xac0) != '\x04') {
      __assert_func(0,0,0,0);
    }
    nwk_do_leave_continue_constprop_0(bStack_21 >> 5 & 1,bStack_21 >> 7);
  }
  else {
    if (param_2 == 0x1f0) {
      param_2 = 0;
    }
    memset(&uStack_1f,0,0xd);
    bStack_14 = (byte)((uVar2 & 1) << 1) | bVar1 >> 5 & 1;
    uStack_20 = (undefined1)param_2;
    iVar4 = nwk_frame_get_dst_extaddr(param_1,auStack_1c);
    if (iVar4 == 0) {
      zmsg_read_bytes(param_1,2,auStack_1e);
      nwk_handle_device_leave(auStack_1e);
      nwk_leave_confirm(&uStack_20);
    }
  }
  if (param_1 != 0) {
    zmsg_free(param_1);
  }
  return;
}

