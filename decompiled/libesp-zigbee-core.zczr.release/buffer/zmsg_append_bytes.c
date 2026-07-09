/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> buffer.o -> zmsg_append_bytes
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int zmsg_append_bytes(int param_1,int param_2,undefined4 param_3)

{
  ushort uVar1;
  int iVar2;
  
  uVar1 = *(ushort *)(param_1 + 0xe);
  iVar2 = zmsg_set_length(param_2 + (uint)uVar1 & 0xffff);
  if (iVar2 == 0) {
    zmsg_write_bytes(param_1,(uint)uVar1,param_2,param_3);
  }
  return iVar2;
}

