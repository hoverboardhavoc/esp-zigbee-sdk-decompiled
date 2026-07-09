/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> time.o -> time_cluster_srv_check_value_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

byte time_cluster_srv_check_value_handler
               (uint param_1,undefined4 param_2,byte *param_3,byte *param_4)

{
  byte bVar1;
  int iVar2;
  
  iVar2 = time_server_get_attr_desc(param_2,1);
  if ((iVar2 == 0) || (param_4 = *(byte **)(iVar2 + 8), param_4 == (byte *)0x0)) {
    __assert_func(0,0,0,0);
  }
  if (param_1 == 1) {
    return -(((*param_3 ^ *param_4) & 5) != 0) & 0x88;
  }
  if (param_1 < 2) {
    if ((*param_4 & 1) != 0) {
      return 0x88;
    }
  }
  else {
    if (3 < (param_1 - 2 & 0xffff)) {
      return 0;
    }
    if ((*param_4 & 4) != 0) {
      return 0x88;
    }
  }
  bVar1 = 0x87;
  if (*(int *)param_3 != -1) {
    bVar1 = 0;
  }
  return bVar1;
}

