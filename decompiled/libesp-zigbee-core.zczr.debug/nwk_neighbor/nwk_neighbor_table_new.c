/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_neighbor.o -> nwk_neighbor_table_new
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

short * nwk_neighbor_table_new(int param_1)

{
  int iVar1;
  short *__s;
  uint uVar2;
  
  iVar1 = core_globals_get();
  __s = (short *)nbt_get_new_nbr(iVar1 + 0xb1c,param_1);
  if (param_1 == 0) {
    if (__s == (short *)0x0) {
      return (short *)0x0;
    }
  }
  else if (__s == (short *)0x0) {
    __s = (short *)nbt_get_stale_router(iVar1 + 0xb1c);
    if (__s == (short *)0x0) {
      return (short *)0x0;
    }
    if (*__s != -1) {
      nwk_address_unlock_ref();
    }
  }
  memset(__s,0,0x1c);
  *__s = -1;
  uVar2 = *(uint *)(__s + 6);
  *(uint *)(__s + 6) = uVar2 | 3;
  uVar2 = uVar2 & 0xfffffc3f;
  *(uint *)(__s + 6) = uVar2 | 0xc3;
  *(uint *)(__s + 6) = uVar2 | 0x1c0000c3;
  nwk_neighbor_clear_lqa(__s);
  return __s;
}

