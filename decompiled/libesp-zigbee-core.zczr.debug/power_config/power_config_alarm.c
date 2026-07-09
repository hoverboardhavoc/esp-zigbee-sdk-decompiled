/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> power_config.o -> power_config_alarm
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void power_config_alarm(int param_1,ushort param_2)

{
  int iVar1;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  int iStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  ushort uStack_14;
  undefined2 uStack_12;
  
  iVar1 = af_get_ep_desc();
  if ((iVar1 != 0) && (iVar1 = af_endpoint_get_cluster_desc(9,1), iVar1 != 0)) {
    uStack_2c = 0;
    uStack_28 = 0;
    uStack_20 = 0;
    uStack_1c = 0;
    uStack_18 = 0;
    iStack_24 = param_1 << 0x18;
    _uStack_14 = CONCAT22(1,param_2 & 0xff);
    ezb_zcl_alarms_alarm_cmd_req(&uStack_2c);
  }
  return;
}

