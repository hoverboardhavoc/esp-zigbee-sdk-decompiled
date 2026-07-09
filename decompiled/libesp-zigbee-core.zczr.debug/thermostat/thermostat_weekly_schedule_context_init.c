/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> thermostat.o -> thermostat_weekly_schedule_context_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 thermostat_weekly_schedule_context_init(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined1 *__s;
  undefined4 uVar4;
  byte bVar5;
  byte bVar6;
  
  iVar1 = thermostat_srv_get_attr_desc(0x21);
  iVar2 = thermostat_srv_get_attr_desc(param_1,0x22);
  iVar3 = thermostat_srv_get_attr_desc(param_1,0xeff0);
  if (iVar3 == 0) {
    uVar4 = 5;
  }
  else {
    __s = (undefined1 *)calloc(1,0x44);
    *(undefined1 **)(iVar3 + 8) = __s;
    if (__s == (undefined1 *)0x0) {
      uVar4 = 1;
    }
    else {
      memset(__s,0,0x44);
      *__s = (char)param_1;
      if (iVar1 == 0) {
        bVar5 = 0xff;
      }
      else {
        bVar5 = **(byte **)(iVar1 + 8);
      }
      __s[3] = bVar5;
      if (iVar2 == 0) {
        bVar6 = 0xff;
      }
      else {
        bVar6 = **(byte **)(iVar2 + 8);
      }
      __s[4] = bVar6;
      if (bVar5 < bVar6) {
        uVar4 = 0xffffffff;
      }
      else {
        __s[1] = 0xff;
        __s[2] = 0xff;
        milli_timer_init(__s + 0x34,thermostat_weekly_schedule_loop,__s);
        milli_timer_init(__s + 0x24,thermostat_weekly_schedule_hold_on,__s);
        uVar4 = 0;
      }
    }
  }
  return uVar4;
}

