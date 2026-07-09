/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> thermostat.o -> thermostat_is_occupied
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

byte thermostat_is_occupied(void)

{
  byte bVar1;
  int iVar2;
  
  iVar2 = thermostat_srv_get_attr_desc(2);
  if (iVar2 == 0) {
    bVar1 = 1;
  }
  else {
    bVar1 = **(byte **)(iVar2 + 8) & 1;
  }
  return bVar1;
}

