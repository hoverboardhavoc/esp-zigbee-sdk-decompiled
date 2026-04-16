/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> thermostat.o -> thermostat_is_occupied
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

_Bool thermostat_is_occupied(uint8_t ep_id)

{
  _Bool _Var1;
  zcl_attr_desc_t *pzVar2;
  
  pzVar2 = thermostat_srv_get_attr_desc(ep_id,2);
  if (pzVar2 == (zcl_attr_desc_t *)0x0) {
    _Var1 = true;
  }
  else {
                    /* WARNING: Load size is inaccurate */
    _Var1 = (_Bool)(*pzVar2->data_p & 1);
  }
  return _Var1;
}

