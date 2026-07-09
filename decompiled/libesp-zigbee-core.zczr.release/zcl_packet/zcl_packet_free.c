/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> zcl_packet.o -> zcl_packet_free
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zcl_packet_free(void *param_1)

{
  if (param_1 == (void *)0x0) {
    return;
  }
  memset(param_1,0,0x22);
  *(undefined1 *)((int)param_1 + 0x1e) = 0xff;
  if (*(int *)((int)param_1 + 0x24) != 0) {
    zmsg_free();
    return;
  }
  return;
}

