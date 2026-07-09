/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> buffer.o -> zmsg_compare_bytes
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

bool zmsg_compare_bytes(void *param_1,int param_2)

{
  uint __n;
  uint uVar1;
  int iVar2;
  undefined2 auStack_22 [3];
  undefined1 auStack_1c [4];
  void *pvStack_18;
  ushort uStack_14;
  
  auStack_22[0] = (undefined2)param_2;
  uVar1 = param_2 << 0x10;
  zmsg_get_first_chunk(auStack_22,auStack_1c);
  while( true ) {
    __n = (uint)uStack_14;
    if ((__n == 0) || (iVar2 = memcmp(param_1,pvStack_18,__n), iVar2 != 0)) break;
    param_1 = (void *)((int)param_1 + __n);
    uVar1 = ((uVar1 >> 0x10) - __n) * 0x10000;
    zmsg_get_next_chunk(auStack_22,auStack_1c);
  }
  return uVar1 >> 0x10 == 0;
}

