/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> buffer.o -> zmsg_move_offset
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention */

void zmsg_move_offset(zmsg_t *msg,int delta)

{
  int unaff_s0;
  int iVar1;
  undefined8 in_stack_000000c8;
  
  iVar1 = (uint)msg->offset + delta;
  if ((-1 < iVar1) && (iVar1 <= (int)(uint)msg->length)) {
    msg->offset = msg->offset + (short)delta;
    return;
  }
  iVar1 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/common/buffer.c",0xcd,
                        "zmsg_move_offset",0x10314);
  _L0(*(undefined8 *)(iVar1 + 0x4c),*(undefined8 *)(unaff_s0 + 0x54),in_stack_000000c8);
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

