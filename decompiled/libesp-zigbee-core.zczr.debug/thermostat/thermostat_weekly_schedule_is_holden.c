/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> thermostat.o -> thermostat_weekly_schedule_is_holden
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

_Bool thermostat_weekly_schedule_is_holden(uint8_t ep_id)

{
  _Bool _Var1;
  zcl_attr_desc_t *pzVar2;
  
  pzVar2 = thermostat_srv_get_attr_desc(ep_id,0x23);
  if (pzVar2 == (zcl_attr_desc_t *)0x0) {
    _Var1 = false;
  }
  else {
                    /* WARNING: Load size is inaccurate */
    if (*pzVar2->data_p == '\0') {
      _Var1 = false;
    }
    else {
      _Var1 = true;
    }
  }
  return _Var1;
}

