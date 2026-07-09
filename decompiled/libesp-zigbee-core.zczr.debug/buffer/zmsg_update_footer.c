/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> buffer.o -> zmsg_update_footer
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Control flow encountered bad instruction data */

void zmsg_update_footer(int param_1,void *param_2,uint param_3)

{
  ushort uVar1;
  void *__dest;
  
  uVar1 = *(ushort *)(param_1 + 0x10);
  if (param_3 <= uVar1) {
    buffers_get_last(*(undefined4 *)(param_1 + 8));
    __dest = (void *)buffer_get_tail((uint)uVar1);
    memcpy(__dest,param_2,param_3);
    return;
  }
  __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/common/buffer.c",0x188,
                "len <= msg->tail");
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

