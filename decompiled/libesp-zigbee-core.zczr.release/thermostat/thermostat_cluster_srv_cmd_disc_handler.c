/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> thermostat.o -> thermostat_cluster_srv_cmd_disc_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 thermostat_cluster_srv_cmd_disc_handler(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  if (param_1 == 0) {
    puVar2 = (undefined4 *)&send_cmd_list_0;
    uVar1 = 0;
  }
  else {
    puVar2 = &recv_cmd_list_1;
    uVar1 = 4;
  }
  *param_2 = puVar2;
  return uVar1;
}

