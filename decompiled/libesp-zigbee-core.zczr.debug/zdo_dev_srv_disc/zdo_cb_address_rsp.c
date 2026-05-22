/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_dev_srv_disc.o -> zdo_cb_address_rsp
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention */

zdp_status_t zdo_cb_address_rsp(zdp_address_rsp_field_t *rsp,zdo_packet_ctx_t *ctx)

{
  if ((rsp != (zdp_address_rsp_field_t *)0x0) && (ctx != (zdo_packet_ctx_t *)0x0)) {
    zdo_packet_notify_result(ctx,0);
    return '\0';
  }
  __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/zdo/zdo_dev_srv_disc.c",0x1c9,
                "zdo_cb_address_rsp","rsp && ctx");
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

