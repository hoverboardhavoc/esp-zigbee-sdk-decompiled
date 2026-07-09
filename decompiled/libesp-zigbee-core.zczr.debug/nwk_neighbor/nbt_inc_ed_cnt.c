/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_neighbor.o -> nbt_inc_ed_cnt
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Control flow encountered bad instruction data */

void nbt_inc_ed_cnt(int param_1)

{
  int iVar1;
  char *pcVar2;
  undefined4 in_stack_000000e8;
  
  if (*(ushort *)(param_1 + 0xc) < *(ushort *)(param_1 + 10)) {
    *(ushort *)(param_1 + 0xc) = *(ushort *)(param_1 + 0xc) + 1;
    return;
  }
  pcVar2 = "nbt_inc_ed_cnt";
  iVar1 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/nwk/nwk_neighbor.c",0xdf,0x1010c
                       );
  iVar1 = _LVL34(in_stack_000000e8,*(undefined8 *)(iVar1 + 0xd8),*(undefined8 *)(pcVar2 + 0x44));
  if (*(short *)(iVar1 + 0xc) != 0) {
    *(short *)(iVar1 + 0xc) = *(short *)(iVar1 + 0xc) + -1;
    return;
  }
  __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/nwk/nwk_neighbor.c",0xe5,
                "nbt_dec_ed_cnt",0x1016c);
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

