/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> thermostat.o -> thermostat_get_cool_setpoint_limit
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void thermostat_get_cool_setpoint_limit(uint8_t ep_id,int16_t *min_value,int16_t *max_value)

{
  zcl_attr_desc_t *pzVar1;
  zcl_attr_desc_t *pzVar2;
  int16_t iVar3;
  
  if ((min_value != (int16_t *)0x0) && (max_value != (int16_t *)0x0)) {
    pzVar1 = thermostat_srv_get_attr_desc(ep_id,0x17);
    pzVar2 = thermostat_srv_get_attr_desc(ep_id,5);
    if (pzVar1 == (zcl_attr_desc_t *)0x0) {
      if (pzVar2 == (zcl_attr_desc_t *)0x0) {
        iVar3 = -0x6ab3;
      }
      else {
                    /* WARNING: Load size is inaccurate */
        iVar3 = *pzVar2->data_p;
      }
    }
    else {
                    /* WARNING: Load size is inaccurate */
      iVar3 = *pzVar1->data_p;
    }
    *min_value = iVar3;
    pzVar1 = thermostat_srv_get_attr_desc(ep_id,0x18);
    pzVar2 = thermostat_srv_get_attr_desc(ep_id,6);
    if (pzVar1 == (zcl_attr_desc_t *)0x0) {
      if (pzVar2 == (zcl_attr_desc_t *)0x0) {
        iVar3 = 0x7fff;
      }
      else {
                    /* WARNING: Load size is inaccurate */
        iVar3 = *pzVar2->data_p;
      }
    }
    else {
                    /* WARNING: Load size is inaccurate */
      iVar3 = *pzVar1->data_p;
    }
    *max_value = iVar3;
  }
  return;
}

