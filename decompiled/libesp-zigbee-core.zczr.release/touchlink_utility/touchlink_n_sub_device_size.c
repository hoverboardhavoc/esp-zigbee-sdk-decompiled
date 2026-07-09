/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> touchlink_utility.o -> touchlink_n_sub_device_size
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

char touchlink_n_sub_device_size(void)

{
  char cVar1;
  int iVar2;
  
  iVar2 = 0;
  for (cVar1 = '\0'; (iVar2 = af_get_next_simple_desc(iVar2), iVar2 != 0 && (cVar1 != '\b'));
      cVar1 = cVar1 + '\x01') {
  }
  return cVar1;
}

