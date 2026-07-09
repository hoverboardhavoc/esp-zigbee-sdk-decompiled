/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> time.o -> ezb_zcl_time_server_interface_register
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 ezb_zcl_time_server_interface_register(int param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  
  if (param_1 == 0) {
    uVar2 = 2;
  }
  else if (param_2 == 0) {
    uVar2 = 2;
  }
  else {
    piVar1 = (int *)time_server_get_interface();
    if (piVar1 == (int *)0x0) {
      uVar2 = 5;
    }
    else {
      *piVar1 = param_1;
      piVar1[1] = param_2;
      uVar2 = 0;
    }
  }
  return uVar2;
}

