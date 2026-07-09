/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> time.o -> time_server_get_time_ctx
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int time_server_get_time_ctx(void)

{
  int iVar1;
  
  iVar1 = time_server_get_manufacturer_attr_desc(0xeffe);
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = *(int *)(iVar1 + 8);
    if (iVar1 == 0) {
      iVar1 = 0;
    }
  }
  return iVar1;
}

