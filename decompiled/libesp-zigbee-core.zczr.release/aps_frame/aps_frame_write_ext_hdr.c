/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> aps_frame.o -> aps_frame_write_ext_hdr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void aps_frame_write_ext_hdr(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  char cStack_22;
  char acStack_21 [13];
  
  zmsg_read_u8(0,&cStack_22);
  if (-1 < cStack_22) {
    __assert_func(0,0,0,0);
  }
  iVar1 = aps_fcf_get_hdr_size();
  acStack_21[0] = (param_3 != 0) + '\x01';
  zmsg_write_bytes(param_1,iVar1,1,acStack_21);
  if (param_3 == 0) {
    param_3 = param_2;
  }
  acStack_21[0] = (char)param_3;
  zmsg_write_bytes(param_1,iVar1 + 1U & 0xffff,1,acStack_21);
  return;
}

