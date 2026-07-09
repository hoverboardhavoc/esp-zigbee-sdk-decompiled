/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> thermostat.o -> thermostat_weekly_schedule_loop
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Removing unreachable block (ram,0x000107c2) */

void thermostat_weekly_schedule_loop(undefined1 *param_1)

{
  char cVar1;
  short sVar2;
  short sVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  char *pcVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  
  if (param_1 == (undefined1 *)0x0) {
    return;
  }
  iVar4 = thermostat_srv_get_attr_desc(*param_1,0x23);
  if ((iVar4 != 0) && (**(char **)(iVar4 + 8) != '\0')) {
    iVar4 = thermostat_weekly_schedule_context_get(*param_1);
    if (iVar4 != 0) {
      milli_timer_stop();
      milli_timer_init(thermostat_weekly_schedule_hold_on,iVar4);
      milli_timer_start(iVar4 + 0x24,0);
      return;
    }
    return;
  }
  if (((((byte)param_1[1] != 0xff) && ((byte)param_1[2] != 0xff)) &&
      (pcVar8 = *(char **)(param_1 + (uint)(byte)param_1[1] * 4 + 8), pcVar8 != (char *)0x0)) &&
     (*(int *)(pcVar8 + 4) != 0)) {
    cVar1 = *pcVar8;
    iVar4 = *(int *)(pcVar8 + 4) + (uint)(byte)param_1[2] * 6;
    sVar2 = *(short *)(iVar4 + 2);
    sVar3 = *(short *)(iVar4 + 4);
    iVar4 = zcl_message_thermostat_setpoint(*param_1);
    if (iVar4 == 0) {
      thermostat_set_heat_cool_value(*param_1,cVar1 + -1,(int)sVar2,(int)sVar3);
    }
  }
  iVar4 = milli_timer_get_now();
  uVar5 = zcl_time_get_utc_time(*param_1);
  if (uVar5 == 0xffffffff) {
    uVar5 = milli_timer_get_now();
    uVar5 = uVar5 / 1000;
  }
  uVar9 = (uVar5 / 0x15180 + 4) % 7;
  uVar5 = uVar5 % 0x93a80 + 0x54600;
  iVar7 = *(int *)(param_1 + uVar9 * 4 + 8);
  uVar12 = (uVar9 + 1) * 0x15180;
  if ((iVar7 != 0) && (*(char *)(iVar7 + 1) != '\0')) {
    uVar10 = (uint)(byte)param_1[2];
    do {
      uVar11 = uVar10 + 1;
      uVar10 = uVar11 & 0xff;
      uVar6 = (uint)*(ushort *)(*(int *)(iVar7 + 4) + uVar10 * 6) * 0x3c + uVar9 * 0x15180;
    } while (uVar6 < uVar5);
    param_1[1] = (char)uVar9;
    param_1[2] = (char)uVar11;
    iVar7 = uVar6 - uVar5;
    if (uVar12 != uVar6) goto _L0;
  }
  iVar7 = uVar12 - uVar5;
  param_1[1] = 0xff;
  param_1[2] = 0xff;
_L0:
  milli_timer_fire_at(param_1 + 0x34,iVar7 * 1000 + iVar4);
  return;
}

