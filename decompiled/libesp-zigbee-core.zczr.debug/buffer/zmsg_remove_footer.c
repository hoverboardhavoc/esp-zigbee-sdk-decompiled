/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> buffer.o -> zmsg_remove_footer
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Control flow encountered bad instruction data */

void zmsg_remove_footer(int param_1,uint param_2)

{
  uint in_t2;
  int iVar1;
  uint uVar2;
  
  if (*(ushort *)(param_1 + 0x10) < param_2) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/common/buffer.c",400,
                  "zmsg_remove_footer","len <= msg->tail");
  }
  else {
    *(ushort *)(param_1 + 0x10) = *(ushort *)(param_1 + 0x10) - (short)param_2;
    iVar1 = zmsg_resize(*(undefined2 *)(param_1 + 0xe));
    if (iVar1 == 0) {
      return;
    }
  }
  uVar2 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/common/buffer.c",0x192,
                        "zmsg_remove_footer",0x105bc);
  if (in_t2 <= uVar2) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

