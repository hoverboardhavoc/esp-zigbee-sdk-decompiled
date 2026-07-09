/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> zcl_packet.o -> zcl_packet_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

byte zcl_packet_init(void *param_1,int param_2)

{
  int iVar1;
  
  if (param_1 != (void *)0x0) {
    memset(param_1,0,0x22);
    if (param_2 != 0) {
      *(undefined1 *)((int)param_1 + 0x1a) = 4;
    }
    *(undefined1 *)((int)param_1 + 0x1e) = 0xff;
    iVar1 = zmsg_alloc(0x34);
    *(int *)((int)param_1 + 0x24) = iVar1;
    return -(iVar1 == 0) & 0x89;
  }
  return 0x87;
}

