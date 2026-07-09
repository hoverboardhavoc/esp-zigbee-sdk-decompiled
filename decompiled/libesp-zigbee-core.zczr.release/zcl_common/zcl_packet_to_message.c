/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> zcl_common.o -> zcl_packet_to_message
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zcl_packet_to_message(undefined1 *param_1,int param_2)

{
  if ((param_1 != (undefined1 *)0x0) && (param_2 != 0)) {
    *param_1 = 0;
    param_1[1] = *(undefined1 *)(param_2 + 0x15);
    *(undefined2 *)(param_1 + 2) = *(undefined2 *)(param_2 + 0x16);
    param_1[4] = ((*(byte *)(param_2 + 0x1a) & 8) != 0) + '\x01';
    return 0;
  }
  return 0x87;
}

