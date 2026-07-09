/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> bdb_comm.o -> bdb_comm_get_next_step
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

uint bdb_comm_get_next_step(void)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  uVar1 = 6;
  while( true ) {
    iVar2 = core_globals_get();
    if (*(char *)(iVar2 + 0xd4f) == '\0') {
      return uVar1;
    }
    iVar2 = core_globals_get();
    uVar3 = __ctzsi2(*(undefined1 *)(iVar2 + 0xd4f));
    uVar1 = uVar3 & 0xff;
    if (uVar1 == 6) break;
    iVar2 = core_globals_get();
    if ((((int)(uint)*(byte *)(iVar2 + 0xd4f) >> (uVar3 & 0x1f) & 1U) != 0) &&
       (iVar2 = bdb_comm_is_step_capable(uVar1), iVar2 != 0)) {
      return uVar1;
    }
    iVar2 = core_globals_get();
    *(byte *)(iVar2 + 0xd4f) = ~(byte)(1 << (uVar3 & 0x1f)) & *(byte *)(iVar2 + 0xd4f);
  }
  return 6;
}

