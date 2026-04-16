/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> identify.o -> identify_timer_ctx_deinit
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention */

void identify_timer_ctx_deinit(uint8_t ep_id)

{
  zcl_attr_desc_t *pzVar1;
  
  pzVar1 = identify_srv_get_attr_desc(ep_id,0xeff0);
  if (pzVar1 != (zcl_attr_desc_t *)0x0) {
    milli_timer_stop((int)pzVar1->data_p + 4);
    mm_free(pzVar1->data_p);
    pzVar1->data_p = (void *)0x0;
    return;
  }
  __assert_func("//build/esp-zigbee/src/core/api/zcl/cluster/identify.c",0xa9,
                "identify_timer_ctx_deinit","timer_ctx_attr_desc");
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

