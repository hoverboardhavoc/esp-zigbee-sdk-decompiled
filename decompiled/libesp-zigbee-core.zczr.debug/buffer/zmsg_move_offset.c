/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> buffer.o -> zmsg_move_offset
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Control flow encountered bad instruction data */

void zmsg_move_offset(int param_1,int param_2)

{
  int unaff_s0;
  int iVar1;
  undefined8 in_stack_000000c8;
  
  iVar1 = (uint)*(ushort *)(param_1 + 0x12) + param_2;
  if ((-1 < iVar1) && (iVar1 <= (int)(uint)*(ushort *)(param_1 + 0xe))) {
    *(ushort *)(param_1 + 0x12) = *(ushort *)(param_1 + 0x12) + (short)param_2;
    return;
  }
  iVar1 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/common/buffer.c",0xcd,
                        "zmsg_move_offset",0x10314);
  _L0(*(undefined8 *)(iVar1 + 0x4c),*(undefined8 *)(unaff_s0 + 0x54),in_stack_000000c8);
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

