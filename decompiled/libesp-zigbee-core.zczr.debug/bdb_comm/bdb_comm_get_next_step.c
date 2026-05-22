/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> bdb_comm.o -> bdb_comm_get_next_step
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

bdb_comm_step_t bdb_comm_get_next_step(void)

{
  bdb_comm_step_t step;
  uint uVar1;
  _Bool _Var2;
  int iVar3;
  uint uVar4;
  undefined3 extraout_var;
  
  uVar1 = 6;
  while( true ) {
    iVar3 = core_globals_get();
    if (*(char *)(iVar3 + 0xd4f) == '\0') {
      return (bdb_comm_step_t)uVar1;
    }
    iVar3 = core_globals_get();
    uVar4 = __ctzsi2(*(undefined1 *)(iVar3 + 0xd4f));
    uVar1 = uVar4 & 0xff;
    step = (bdb_comm_step_t)uVar4;
    if (uVar1 == 6) break;
    iVar3 = core_globals_get();
    if ((((int)(uint)*(byte *)(iVar3 + 0xd4f) >> (uVar4 & 0x1f) & 1U) != 0) &&
       (_Var2 = bdb_comm_is_step_capable(step), CONCAT31(extraout_var,_Var2) != 0)) {
      return step;
    }
    iVar3 = core_globals_get();
    *(byte *)(iVar3 + 0xd4f) = ~(byte)(1 << (uVar4 & 0x1f)) & *(byte *)(iVar3 + 0xd4f);
  }
  return step;
}

