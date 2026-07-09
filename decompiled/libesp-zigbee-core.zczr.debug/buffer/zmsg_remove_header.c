/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> buffer.o -> zmsg_remove_header
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zmsg_remove_header(int param_1,uint param_2)

{
  short sVar1;
  
  if (*(ushort *)(param_1 + 0xe) < param_2) {
    param_1 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/common/buffer.c",0x150,
                            "zmsg_remove_header",0x103a0);
  }
  else {
    sVar1 = (short)param_2;
    *(short *)(param_1 + 0xc) = *(short *)(param_1 + 0xc) + sVar1;
    *(ushort *)(param_1 + 0xe) = *(ushort *)(param_1 + 0xe) - sVar1;
    if (param_2 < *(ushort *)(param_1 + 0x12)) {
      *(ushort *)(param_1 + 0x12) = *(ushort *)(param_1 + 0x12) - sVar1;
      return;
    }
  }
  *(undefined2 *)(param_1 + 0x12) = 0;
  return;
}

