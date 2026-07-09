/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> zcl_packet.o -> zcl_packet_clone
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zcl_packet_clone(void *param_1,void *param_2)

{
  undefined4 uVar1;
  
  if (param_1 != (void *)0x0) {
    uVar1 = 0x87;
    if (param_2 != (void *)0x0) {
      memcpy(param_1,param_2,0x22);
      uVar1 = zmsg_clone(*(undefined4 *)((int)param_2 + 0x24));
      *(undefined4 *)((int)param_1 + 0x24) = uVar1;
      uVar1 = 0;
    }
    return uVar1;
  }
  return 0x87;
}

