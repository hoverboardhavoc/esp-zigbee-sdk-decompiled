/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> zdo_core.o -> zdo_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int zdo_init(void)

{
  int iVar1;
  int iVar2;
  
  zdo_comm_init();
  zdo_secur_init();
  iVar1 = zdo_management_init();
  iVar2 = -1;
  if (iVar1 == 0) {
    iVar1 = zdo_packet_scheduler_init(0xffffffff);
    iVar2 = -(uint)(iVar1 != 0);
  }
  return iVar2;
}

