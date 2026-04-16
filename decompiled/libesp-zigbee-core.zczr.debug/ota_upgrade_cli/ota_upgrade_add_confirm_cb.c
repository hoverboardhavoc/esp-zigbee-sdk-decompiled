/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> ota_upgrade_cli.o -> ota_upgrade_add_confirm_cb
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void ota_upgrade_add_confirm_cb(zcl_packet_cnf_ctx_t *cnf_ctx,void *user_ctx)

{
  if (cnf_ctx != (zcl_packet_cnf_ctx_t *)0x0) {
    cnf_ctx->cb = ota_upgrade_data_confirm_handler;
    cnf_ctx->user_ctx = user_ctx;
  }
  return;
}

