/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> thermostat.o -> thermostat_weekly_schedule_context_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t thermostat_weekly_schedule_context_init(uint8_t ep_id)

{
  zcl_attr_desc_t *pzVar1;
  zcl_attr_desc_t *pzVar2;
  zcl_attr_desc_t *pzVar3;
  uint8_t *__s;
  ezb_err_t eVar4;
  byte bVar5;
  byte bVar6;
  
  pzVar1 = thermostat_srv_get_attr_desc(ep_id,0x21);
  pzVar2 = thermostat_srv_get_attr_desc(ep_id,0x22);
  pzVar3 = thermostat_srv_get_attr_desc(ep_id,0xeff0);
  if (pzVar3 == (zcl_attr_desc_t *)0x0) {
    eVar4 = 5;
  }
  else {
    __s = (uint8_t *)calloc(1,0x44);
    pzVar3->data_p = __s;
    if (__s == (uint8_t *)0x0) {
      eVar4 = 1;
    }
    else {
      memset(__s,0,0x44);
      *__s = ep_id;
      if (pzVar1 == (zcl_attr_desc_t *)0x0) {
        bVar5 = 0xff;
      }
      else {
                    /* WARNING: Load size is inaccurate */
        bVar5 = *pzVar1->data_p;
      }
      __s[3] = bVar5;
      if (pzVar2 == (zcl_attr_desc_t *)0x0) {
        bVar6 = 0xff;
      }
      else {
                    /* WARNING: Load size is inaccurate */
        bVar6 = *pzVar2->data_p;
      }
      __s[4] = bVar6;
      if (bVar5 < bVar6) {
        eVar4 = -1;
      }
      else {
        __s[1] = 0xff;
        __s[2] = 0xff;
        milli_timer_init(__s + 0x34,thermostat_weekly_schedule_loop,__s);
        milli_timer_init(__s + 0x24,thermostat_weekly_schedule_hold_on,__s);
        eVar4 = 0;
      }
    }
  }
  return eVar4;
}

