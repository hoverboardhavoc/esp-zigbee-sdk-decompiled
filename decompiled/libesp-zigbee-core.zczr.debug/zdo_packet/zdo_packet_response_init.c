/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_packet.o -> zdo_packet_response_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

zdp_status_t zdo_packet_response_init(zdo_packet_t *resp,zdo_packet_t *req,uint16_t cluster_id)

{
  zdp_status_t zVar1;
  zdo_packet_payload_t *pzVar2;
  
  if (resp == (zdo_packet_t *)0x0) {
    zVar1 = 0x80;
  }
  else if (req == (zdo_packet_t *)0x0) {
    zVar1 = 0x80;
  }
  else {
    resp->cluster_id = cluster_id;
    resp->dst_addr = req->src_addr;
    resp->src_addr = req->dst_addr;
    resp->tsn = req->tsn;
    (resp->ctx).mode = '\0';
    (resp->ctx).req_ctx.cb = (zdo_packet_req_callback_t)0x0;
    (resp->ctx).req_ctx.arg = (zdo_packet_user_ctx_t)0x0;
    pzVar2 = (zdo_packet_payload_t *)zmsg_alloc(1);
    resp->payload = pzVar2;
    if (pzVar2 == (zdo_packet_payload_t *)0x0) {
      zVar1 = 0x8a;
    }
    else {
      zVar1 = '\0';
    }
  }
  return zVar1;
}

