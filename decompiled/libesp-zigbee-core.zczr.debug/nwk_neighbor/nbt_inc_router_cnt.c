/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_neighbor.o -> nbt_inc_router_cnt
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Removing unreachable block (ram,0x000108b8) */
/* WARNING: Removing unreachable block (ram,0x0001090e) */
/* WARNING: Removing unreachable block (ram,0x000108c0) */
/* WARNING: Removing unreachable block (ram,0x000108c8) */

undefined8 nbt_inc_router_cnt(int param_1)

{
  int unaff_s0;
  int iVar1;
  char *pcVar2;
  int unaff_s7;
  undefined8 in_fa0;
  undefined4 in_csr726;
  undefined4 in_stack_0000000c;
  undefined4 in_stack_000000e8;
  
  if ((int)(uint)*(ushort *)(param_1 + 0xe) <
      (int)((uint)*(ushort *)(param_1 + 8) - (uint)*(ushort *)(param_1 + 10))) {
    *(ushort *)(param_1 + 0xe) = *(ushort *)(param_1 + 0xe) + 1;
    return in_fa0;
  }
  pcVar2 = "nbt_inc_router_cnt";
  iVar1 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/nwk/nwk_neighbor.c",0xd3);
  iVar1 = FUN_000101c0(in_stack_000000e8,*(undefined8 *)(iVar1 + 0xd8),
                       *(undefined8 *)(pcVar2 + 0x44));
  if (unaff_s7 == 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  FUN_0001073e(in_csr726,in_stack_0000000c,*(undefined8 *)(iVar1 + 0xd8),
               *(undefined8 *)(iVar1 + 0x44),*(undefined8 *)(unaff_s0 + 0x40));
  func_0x00010574();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

