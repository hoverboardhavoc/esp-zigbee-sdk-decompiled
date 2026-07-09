/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> touchlink.o -> touchlink_commissioning_identify_timeout
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void touchlink_commissioning_identify_timeout(void)

{
  short sVar1;
  int iVar2;
  
  iVar2 = touchlink_commissioning_get();
  sVar1 = *(short *)(iVar2 + 0x20);
  *(short *)(iVar2 + 0x20) = sVar1 + -1;
  if (sVar1 == 0) {
    touchlink_commissioning_stop_identify();
  }
  else {
    iVar2 = touchlink_commissioning_get();
    touchlink_commissioning_start_identify(*(undefined2 *)(iVar2 + 0x20));
  }
  return;
}

