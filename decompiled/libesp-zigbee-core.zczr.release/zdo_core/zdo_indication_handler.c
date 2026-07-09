/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> zdo_core.o -> zdo_indication_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int zdo_indication_handler(int param_1)

{
  int iVar1;
  undefined1 auStack_28 [32];
  
  memset(auStack_28,0,0x18);
  iVar1 = 0x80;
  if ((param_1 != 0) && (iVar1 = zdo_packet_init_with_msg(auStack_28,param_1), iVar1 == 0)) {
    iVar1 = zdo_packet_indication_handler(auStack_28);
  }
  return iVar1;
}

