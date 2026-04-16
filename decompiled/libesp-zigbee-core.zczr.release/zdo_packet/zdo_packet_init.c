/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> zdo_packet.o -> zdo_packet_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

zdp_status_t
zdo_packet_init(zdo_packet_t *packet,uint16_t cluster_id,uint16_t dst_addr,
               zdo_packet_req_callback_t cb,zdo_packet_user_ctx_t arg)

{
  zdo_packet_payload_t *pzVar1;
  undefined2 in_register_0000202e;
  uint uVar2;
  undefined2 in_register_00002032;
  uint8_t uVar3;
  
  uVar2 = CONCAT22(in_register_0000202e,cluster_id);
  if (packet == (zdo_packet_t *)0x0) {
    return 0x80;
  }
  if (CONCAT22(in_register_00002032,dst_addr) < 0xfff8) {
    uVar3 = '\x01';
    goto _L0;
  }
  if (uVar2 != 0x13) {
    if (uVar2 < 0x14) {
      uVar3 = '\x01';
      if ((1 < uVar2) && (uVar3 = '\x02', uVar2 != 6)) {
        return 0x84;
      }
      goto _L0;
    }
    if (uVar2 != 0x36) {
      if ((uVar2 != 0x38) && (uVar2 != 0x1f)) {
        return 0x84;
      }
      uVar3 = '\x02';
      goto _L0;
    }
  }
  uVar3 = '\0';
_L0:
  (packet->ctx).mode = uVar3;
  packet->cluster_id = cluster_id;
  packet->dst_addr = dst_addr;
  packet->tsn = 0xff;
  (packet->ctx).req_ctx.cb = cb;
  (packet->ctx).req_ctx.arg = arg;
  pzVar1 = (zdo_packet_payload_t *)zmsg_alloc(1);
  packet->payload = pzVar1;
  return -(pzVar1 == (zdo_packet_payload_t *)0x0) & 0x8a;
}

