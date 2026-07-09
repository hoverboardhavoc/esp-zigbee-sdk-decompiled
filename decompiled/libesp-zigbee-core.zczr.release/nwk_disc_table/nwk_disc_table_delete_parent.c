/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> nwk_disc_table.o -> nwk_disc_table_delete_parent
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_disc_table_delete_parent(int param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  iVar3 = core_globals_get();
  iVar3 = iVar3 + 0xb2c;
  uVar4 = (param_1 - iVar3 >> 2) * -0x33333333;
  if ((uVar4 & 0xffff) < 6) goto _L0;
  do {
    iVar3 = __assert_func(0,0,0,0);
_L0:
    uVar1 = 1 << (uVar4 & 7) & 0xff;
    uVar4 = (uVar4 << 0x10) >> 0x13;
    uVar2 = __atomic_fetch_and_1(iVar3 + 0x78 + uVar4,~uVar1 & 0xff);
  } while ((uVar1 & uVar2) == 0);
  return;
}

