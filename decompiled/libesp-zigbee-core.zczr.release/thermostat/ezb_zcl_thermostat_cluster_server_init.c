/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> thermostat.o -> ezb_zcl_thermostat_cluster_server_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void ezb_zcl_thermostat_cluster_server_init(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined1 *puVar4;
  byte bVar5;
  byte bVar6;
  undefined1 auStack_34 [28];
  
  memcpy(auStack_34,&_LANCHOR0,0x14);
  iVar1 = thermostat_srv_get_attr_desc(param_1,0x21);
  iVar2 = thermostat_srv_get_attr_desc(param_1,0x22);
  iVar3 = thermostat_srv_get_attr_desc_part_0(param_1);
  if (iVar3 != 0) {
    puVar4 = (undefined1 *)calloc(1,0x44);
    *(undefined1 **)(iVar3 + 8) = puVar4;
    if (puVar4 != (undefined1 *)0x0) {
      memset(puVar4 + 1,0,0x43);
      *puVar4 = (char)param_1;
      bVar5 = 0xff;
      if (iVar1 != 0) {
        bVar5 = **(byte **)(iVar1 + 8);
      }
      puVar4[3] = bVar5;
      bVar6 = 0xff;
      if (iVar2 != 0) {
        bVar6 = **(byte **)(iVar2 + 8);
      }
      puVar4[4] = bVar6;
      if (bVar6 <= bVar5) {
        puVar4[1] = 0xff;
        puVar4[2] = 0xff;
        milli_timer_init(puVar4 + 0x34,thermostat_weekly_schedule_loop,puVar4);
        milli_timer_init(puVar4 + 0x24,thermostat_weekly_schedule_hold_on,puVar4);
        iVar1 = zcl_cluster_template_add(auStack_34);
        if (iVar1 == 0) {
          return;
        }
      }
    }
  }
  __assert_func(0,0,0,0);
  return;
}

