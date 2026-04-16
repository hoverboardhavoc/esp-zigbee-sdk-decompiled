/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> thermostat.o -> thermostat_cluster_srv_write_attr_hook
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Removing unreachable block (ram,0x000107c2) */
/* WARNING: Unknown calling convention */

void thermostat_cluster_srv_write_attr_hook
               (uint8_t endpoint,uint16_t attr_id,void *new_value,uint16_t manuf_code)

{
  weekly_schedule_context_t *pwVar1;
  zcl_attr_desc_t *pzVar2;
  undefined2 in_register_0000202e;
  
  if (CONCAT22(in_register_0000202e,attr_id) == 0x1c) {
    pzVar2 = thermostat_srv_get_attr_desc(endpoint,attr_id);
                    /* WARNING: Load size is inaccurate */
                    /* WARNING: Load size is inaccurate */
    if (((pzVar2 == (zcl_attr_desc_t *)0x0) || (new_value == (void *)0x0)) ||
       (*pzVar2->data_p == *new_value)) {
      return;
    }
  }
  else if (1 < (CONCAT22(in_register_0000202e,attr_id) - 0x23U & 0xffff)) {
    return;
  }
  pwVar1 = thermostat_weekly_schedule_context_get(endpoint);
  if (pwVar1 != (weekly_schedule_context_t *)0x0) {
    milli_timer_stop();
    milli_timer_init(thermostat_weekly_schedule_hold_on,pwVar1);
    milli_timer_start(&pwVar1->hold_timer,0);
    return;
  }
  return;
}

