/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> thermostat.o -> thermostat_weekly_schedule_context_get
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

weekly_schedule_context_t * thermostat_weekly_schedule_context_get(uint8_t ep_id)

{
  uint8_t ep_id_00;
  zcl_attr_desc_t *pzVar1;
  weekly_schedule_context_t *pwVar2;
  
  pzVar1 = thermostat_srv_get_attr_desc(ep_id,0xeff0);
  if (pzVar1 != (zcl_attr_desc_t *)0x0) {
    return (weekly_schedule_context_t *)pzVar1->data_p;
  }
  ep_id_00 = __assert_func("//build/esp-zigbee/src/core/api/zcl/cluster/thermostat.c",0x137,
                           "thermostat_weekly_schedule_context_get","sched_ctx_attr_desc");
  pzVar1 = thermostat_srv_get_attr_desc(ep_id_00,0x23);
  if (pzVar1 == (zcl_attr_desc_t *)0x0) {
    pwVar2 = (weekly_schedule_context_t *)0x0;
  }
  else {
                    /* WARNING: Load size is inaccurate */
    if (*pzVar1->data_p == '\0') {
      pwVar2 = (weekly_schedule_context_t *)0x0;
    }
    else {
      pwVar2 = (weekly_schedule_context_t *)0x1;
    }
  }
  return pwVar2;
}

