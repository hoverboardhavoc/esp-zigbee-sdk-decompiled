/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> thermostat.o -> zcl_message_thermostat_setpoint
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

char zcl_message_thermostat_setpoint
               (byte param_1,byte param_2,undefined2 param_3,undefined2 param_4)

{
  short local_20;
  undefined2 uStack_1e;
  int iStack_1c;
  undefined2 uStack_18;
  undefined2 uStack_16;
  undefined2 uStack_14;
  
  _local_20 = CONCAT22(0x201,(ushort)param_1 << 8);
  iStack_1c = (uint)param_2 << 0x10;
  uStack_14 = 0xfe;
  uStack_18 = param_4;
  uStack_16 = param_3;
  zcl_core_action_schedule(0x38,&local_20);
  if ((char)uStack_14 == -2) {
    uStack_14._0_1_ = '\0';
  }
  return (char)uStack_14;
}

