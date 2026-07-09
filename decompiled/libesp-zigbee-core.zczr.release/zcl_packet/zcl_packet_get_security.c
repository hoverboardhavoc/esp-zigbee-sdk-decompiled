/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> zcl_packet.o -> zcl_packet_get_security
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

ushort zcl_packet_get_security(int param_1)

{
  ushort uVar1;
  ushort uVar2;
  
  if (param_1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = 0;
    if (*(int *)(param_1 + 0x24) != 0) {
      uVar1 = *(ushort *)(*(int *)(param_1 + 0x24) + 0x16);
      uVar2 = 1;
      if ((uVar1 & 2) == 0) {
        return uVar1 >> 1 & 2;
      }
    }
  }
  return uVar2;
}

