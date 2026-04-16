/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> ias_zone.o -> ias_zone_srv_get_zone_ctx__1
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ias_zone_srv_zone_ctx_t * ias_zone_srv_get_zone_ctx(uint8_t ep_id)

{
  undefined3 in_register_00002029;
  ias_zone_srv_zone_ctx_t *piVar1;
  
  piVar1 = (ias_zone_srv_zone_ctx_t *)
           ezb_zcl_get_attr_desc(CONCAT31(in_register_00002029,ep_id),0x500,1,0xeff0,0x131b);
  if (piVar1 == (ias_zone_srv_zone_ctx_t *)0x0) {
    piVar1 = ias_zone_srv_get_zone_ctx('\0');
  }
  return (ias_zone_srv_zone_ctx_t *)(piVar1->restore_normal_mode_timer).timer_func;
}

