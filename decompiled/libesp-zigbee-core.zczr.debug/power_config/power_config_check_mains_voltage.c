/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> power_config.o -> power_config_check_mains_voltage
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void power_config_check_mains_voltage(undefined4 param_1,ushort *param_2)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  
  if (param_2 != (ushort *)0x0) {
    uVar1 = *param_2;
    iVar2 = zcl_get_attr_desc(1,0x10,0);
    if (iVar2 != 0) {
      iVar3 = zcl_get_attr_desc(param_1,1,0x11,0);
      if (((iVar3 != 0) && (uVar1 < **(ushort **)(iVar3 + 8))) &&
         (**(ushort **)(iVar3 + 8) != 0xffff)) {
        **(byte **)(iVar2 + 8) = **(byte **)(iVar2 + 8) | 1;
        power_config_alarm(param_1,0);
      }
      iVar3 = zcl_get_attr_desc(param_1,1,0x12,0);
      if ((iVar3 != 0) && (**(ushort **)(iVar3 + 8) < uVar1)) {
        **(byte **)(iVar2 + 8) = **(byte **)(iVar2 + 8) | 2;
        power_config_alarm(param_1,1);
      }
    }
  }
  return;
}

