/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_nlme.o -> nwk_build_leave
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_build_leave(undefined4 param_1,uint param_2,int param_3,int param_4)

{
  byte bVar1;
  undefined4 uVar2;
  int iVar3;
  byte abStack_21 [13];
  
  uVar2 = nwk_get_short_address();
  nwk_frame_write_hdr(param_1,uVar2,param_2,1,1,0);
  iVar3 = core_globals_get();
  abStack_21[0] = *(byte *)(iVar3 + 0x9d9);
  *(byte *)(iVar3 + 0x9d9) = abStack_21[0] + 1;
  zmsg_write_bytes(param_1,7,1,abStack_21);
  if (param_3 != 0) {
    param_3 = 0x20;
  }
  bVar1 = (byte)param_3;
  if (param_4 != 0) {
    bVar1 = bVar1 | 0x80;
  }
  if (param_2 < 0xfff8) {
    bVar1 = bVar1 & 0x7f | 0x40;
  }
  abStack_21[0] = 4;
  zmsg_append_bytes(param_1,1,abStack_21);
  abStack_21[0] = bVar1;
  zmsg_append_bytes(param_1,1,abStack_21);
  return;
}

