/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> nwk_nlme.o -> nwk_build_leave
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_build_leave(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  char acStack_21 [13];
  
  uVar1 = nwk_get_short_address();
  nwk_frame_write_hdr(param_1,uVar1,param_2,1,1,0);
  iVar2 = core_globals_get();
  acStack_21[0] = *(char *)(iVar2 + 0x9d9);
  *(char *)(iVar2 + 0x9d9) = acStack_21[0] + '\x01';
  zmsg_write_bytes(param_1,7,1,acStack_21);
  zmsg_append_u8_isra_0(param_1,4);
  zmsg_append_bytes(param_1,1,&stack0xffffffef);
  return;
}

