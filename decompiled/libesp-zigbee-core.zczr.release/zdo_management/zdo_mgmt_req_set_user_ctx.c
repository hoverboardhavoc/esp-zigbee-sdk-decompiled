/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> zdo_management.o -> zdo_mgmt_req_set_user_ctx
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void zdo_mgmt_req_set_user_ctx(zdo_mgmt_req_handle_t handle,zdo_mgmt_req_user_ctx_t *ctx)

{
  zdo_mgmt_req_user_ctx_t *extraout_a1;
  
  if (handle == (zdo_mgmt_req_handle_t)0x0) {
    handle = (zdo_mgmt_req_handle_t)__assert_func(0,0,0);
    ctx = extraout_a1;
  }
  *(zdo_mgmt_user_callback_t *)((int)handle + 0x18) = ctx->cb;
  *(void **)((int)handle + 0x1c) = ctx->arg;
  return;
}

