/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> buffer.o -> zmsg_compare_bytes
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

bool zmsg_compare_bytes(void *param_1,ushort param_2)

{
  uint uVar1;
  int iVar2;
  uint __n;
  ushort auStack_22 [3];
  undefined1 auStack_1c [4];
  void *pvStack_18;
  ushort uStack_14;
  
  uVar1 = (uint)param_2;
  auStack_22[0] = param_2;
  zmsg_get_first_chunk(auStack_22,auStack_1c);
  while ((__n = (uint)uStack_14, __n != 0 && (iVar2 = memcmp(param_1,pvStack_18,__n), iVar2 == 0)))
  {
    param_1 = (void *)((int)param_1 + __n);
    uVar1 = uVar1 - __n & 0xffff;
    zmsg_get_next_chunk(auStack_22,auStack_1c);
  }
  return uVar1 == 0;
}

