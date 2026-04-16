/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> ias_zone.o -> ias_zone_ctx_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention */

ezb_err_t ias_zone_ctx_init(uint8_t ep_id)

{
  void *pvVar1;
  zcl_attr_desc_t *pzVar2;
  
  pvVar1 = calloc(1,0x14);
  if (pvVar1 != (void *)0x0) {
    pzVar2 = ias_zone_srv_get_attr_desc(ep_id,0xeff0);
    pzVar2->data_p = pvVar1;
    return 0;
  }
  __assert_func("//build/esp-zigbee/src/core/api/zcl/cluster/ias_zone.c",0x217,"ias_zone_ctx_init",
                "ctx != ((void *)0)");
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

