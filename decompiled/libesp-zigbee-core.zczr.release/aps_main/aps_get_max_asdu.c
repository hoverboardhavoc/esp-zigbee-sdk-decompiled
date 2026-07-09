/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> aps_main.o -> aps_get_max_asdu
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

uint aps_get_max_asdu(int param_1,int param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = core_globals_get();
  if (param_1 == 0) {
    uVar2 = 0x52;
    if (param_2 != 0) {
      uVar2 = (-(uint)(param_3 != 0) & 0xfffffff8) + 0x49;
    }
  }
  else {
    uVar2 = (uint)*(ushort *)(iVar1 + 4);
  }
  return uVar2;
}

