/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> door_lock.o -> door_lock_cluster_srv_check_value_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

uint door_lock_cluster_srv_check_value_handler(uint param_1,byte *param_2)

{
  bool bVar1;
  uint uVar2;
  
  if (param_1 == 2) {
    bVar1 = 1 < *param_2;
_L19:
    return -(uint)bVar1 & 0x87;
  }
  if (param_1 < 3) {
    if (param_1 != 0) {
      bVar1 = 10 < *param_2;
      goto _L19;
    }
    if ((byte)(*param_2 - 3) < 0xfc) {
      return 0x87;
    }
  }
  else if (param_1 == 0x34) {
    uVar2 = zdo_dev_joined();
    return uVar2;
  }
  return 0;
}

