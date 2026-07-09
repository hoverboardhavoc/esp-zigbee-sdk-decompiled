/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> power_config.o -> power_config_alarm
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void power_config_alarm(undefined1 param_1,undefined1 param_2)

{
  int iVar1;
  undefined1 auStack_2c [11];
  undefined1 uStack_21;
  undefined1 uStack_14;
  undefined2 uStack_12;
  
  iVar1 = af_get_ep_desc();
  if ((iVar1 != 0) && (iVar1 = af_endpoint_get_cluster_desc(9,1), iVar1 != 0)) {
    memset(auStack_2c,0,0x1a);
    uStack_12 = 1;
    uStack_21 = param_1;
    uStack_14 = param_2;
    ezb_zcl_alarms_alarm_cmd_req(auStack_2c);
  }
  return;
}

