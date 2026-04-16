/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_bind_mgmt.o -> zdo_bind_mgmt_req_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

zdp_status_t zdo_bind_mgmt_req_handler(void *arg)

{
  zdp_status_t zVar1;
  int iVar2;
  undefined3 extraout_var;
  undefined1 auStack_28 [4];
  zdo_packet_t resp;
  
  auStack_28[0] = '\0';
  auStack_28[1] = 0;
  auStack_28._2_2_ = 0;
  resp.tsn = '\0';
  resp._1_1_ = 0;
  resp.dst_addr = 0;
  resp.src_addr = 0;
  resp.cluster_id = 0;
  resp.ctx.mode = '\0';
  resp.ctx._1_3_ = 0;
  resp.ctx.req_ctx.cb = (zdo_packet_req_callback_t)0x0;
  resp.ctx.req_ctx.arg = (zdo_packet_user_ctx_t)0x0;
  if (arg == (void *)0x0) {
    iVar2 = 0x80;
  }
  else {
    iVar2 = zdo_packet_response_init(auStack_28,arg,*(ushort *)((int)arg + 6) | 0x8000);
    if (iVar2 == 0) {
      if (*(ushort *)((int)arg + 6) - 0x21 < 2) {
        zVar1 = zdo_bind_and_unbindreq_handler((zdo_packet_t *)arg,(zdo_packet_t *)auStack_28);
        iVar2 = CONCAT31(extraout_var,zVar1);
        if (iVar2 == 0) {
          iVar2 = zdo_packet_send(auStack_28);
          goto _L0;
        }
      }
      else {
        iVar2 = 0x84;
      }
      zdo_packet_free(auStack_28);
    }
  }
_L0:
  return (zdp_status_t)iVar2;
}

