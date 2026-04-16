/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> ias_zone.o -> ias_zone_srv_get_zone_ctx
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention */

ias_zone_srv_zone_ctx_t * ias_zone_srv_get_zone_ctx(uint8_t ep_id)

{
  zcl_attr_desc_t *pzVar1;
  
  pzVar1 = ias_zone_srv_get_attr_desc(ep_id,0xeff0);
  if (pzVar1 != (zcl_attr_desc_t *)0x0) {
    return (ias_zone_srv_zone_ctx_t *)pzVar1->data_p;
  }
  __assert_func("//build/esp-zigbee/src/core/api/zcl/cluster/ias_zone.c",0x68,
                "ias_zone_srv_get_zone_ctx","attr_desc");
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

