/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.debug -> buffer.o -> zmsg_set_offset
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Control flow encountered bad instruction data */

void zmsg_set_offset(int param_1,uint param_2)

{
  int unaff_s0;
  
  if (param_2 <= *(ushort *)(param_1 + 0xe)) {
    *(short *)(param_1 + 0x12) = (short)param_2;
    return;
  }
  __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/common/buffer.c",200,"zmsg_set_offset",
                "offset <= msg->length");
  FUN_0001034a((int)*(undefined8 *)(unaff_s0 + 0x60));
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

