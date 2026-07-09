/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> thermostat.o -> thermostat_weekly_schedule_loop
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void thermostat_weekly_schedule_loop(undefined1 *param_1)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  char *pcVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  
  if (param_1 != (undefined1 *)0x0) {
    iVar2 = thermostat_weekly_schedule_is_holden(*param_1);
    if (iVar2 == 0) {
      if (((((byte)param_1[1] != 0xff) && ((byte)param_1[2] != 0xff)) &&
          (pcVar6 = *(char **)(param_1 + (uint)(byte)param_1[1] * 4 + 8), pcVar6 != (char *)0x0)) &&
         (*(int *)(pcVar6 + 4) != 0)) {
        cVar1 = *pcVar6;
        iVar2 = *(int *)(pcVar6 + 4) + (uint)(byte)param_1[2] * 6;
        iVar10 = (int)*(short *)(iVar2 + 2);
        iVar11 = (int)*(short *)(iVar2 + 4);
        iVar2 = zcl_message_thermostat_setpoint(*param_1,cVar1 + -1,iVar10,iVar11);
        if (iVar2 == 0) {
          thermostat_set_heat_cool_value(*param_1,cVar1 + -1,iVar10,iVar11);
        }
      }
      iVar10 = milli_timer_get_now();
      uVar3 = thermostat_weekly_schedule_get_utc_time(*param_1);
      uVar4 = (uVar3 / 0x15180 + 4) % 7;
      uVar9 = uVar3 % 0x93a80 + 0x54600;
      iVar2 = (uVar4 + 1) * 0x15180 - uVar9;
      iVar11 = *(int *)(param_1 + uVar4 * 4 + 8);
      uVar3 = (uint)(byte)param_1[2];
      do {
        uVar5 = uVar3 + 1;
        uVar3 = uVar5 & 0xff;
        iVar8 = iVar2;
        if ((iVar11 == 0) || (*(char *)(iVar11 + 1) == '\0')) goto _L0;
        uVar7 = uVar4 * 0x15180 + (uint)*(ushort *)(uVar3 * 6 + *(int *)(iVar11 + 4)) * 0x3c;
      } while (uVar7 < uVar9);
      param_1[1] = (char)uVar4;
      param_1[2] = (char)uVar5;
      iVar8 = uVar7 - uVar9;
_L0:
      if (iVar8 == iVar2) {
        param_1[1] = 0xff;
        param_1[2] = 0xff;
      }
      milli_timer_fire_at(param_1 + 0x34,iVar8 * 1000 + iVar10);
    }
    else {
      thermostat_weekly_schedule_hold(*param_1,1,0);
    }
  }
  return;
}

