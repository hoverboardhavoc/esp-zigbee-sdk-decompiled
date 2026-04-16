/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> thermostat.o -> thermostat_cluster_srv_write_attr_hook
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void thermostat_cluster_srv_write_attr_hook
               (uint8_t endpoint,uint16_t attr_id,void *new_value,uint16_t manuf_code)

{
  zcl_attr_desc_t *pzVar1;
  undefined2 in_register_0000202e;
  uint uVar2;
  
  uVar2 = CONCAT22(in_register_0000202e,attr_id);
  if (uVar2 == 0x1c) {
    pzVar1 = thermostat_srv_get_attr_desc(endpoint,0x1c);
                    /* WARNING: Load size is inaccurate */
                    /* WARNING: Load size is inaccurate */
    if (((pzVar1 != (zcl_attr_desc_t *)0x0) && (new_value != (void *)0x0)) &&
       (*pzVar1->data_p != *new_value)) {
      thermostat_weekly_schedule_hold(endpoint,true,0);
    }
  }
  else if ((0x1b < uVar2) && ((uVar2 - 0x23 & 0xffff) < 2)) {
    thermostat_weekly_schedule_hold(endpoint,true,0);
  }
  return;
}

