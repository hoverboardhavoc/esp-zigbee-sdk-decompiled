/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_packet.o -> zdo_packet_init
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
  zdp_status_t zVar1;
  zdo_packet_payload_t *pzVar2;
  undefined2 in_register_0000202e;
  uint uVar3;
  undefined2 in_register_00002032;
  
  uVar3 = CONCAT22(in_register_0000202e,cluster_id);
  if (packet == (zdo_packet_t *)0x0) {
    return 0x80;
  }
  if (CONCAT22(in_register_00002032,dst_addr) < 0xfff8) {
    (packet->ctx).mode = '\x01';
    goto _L0;
  }
  if (uVar3 == 0x13) {
_L0:
    (packet->ctx).mode = '\0';
  }
  else {
    if (uVar3 < 0x14) {
      if (uVar3 < 2) {
        (packet->ctx).mode = '\x01';
        goto _L0;
      }
      if (uVar3 != 6) {
        return 0x84;
      }
    }
    else {
      if (uVar3 == 0x36) goto _L0;
      if (uVar3 < 0x37) {
        if ((uVar3 != 0x15) && (uVar3 != 0x1f)) {
          return 0x84;
        }
      }
      else if (uVar3 != 0x38) {
        return 0x84;
      }
    }
    (packet->ctx).mode = '\x02';
  }
_L0:
  packet->cluster_id = cluster_id;
  packet->dst_addr = dst_addr;
  packet->tsn = 0xff;
  (packet->ctx).req_ctx.cb = cb;
  (packet->ctx).req_ctx.arg = arg;
  pzVar2 = (zdo_packet_payload_t *)zmsg_alloc(1);
  packet->payload = pzVar2;
  if (pzVar2 == (zdo_packet_payload_t *)0x0) {
    zVar1 = 0x8a;
  }
  else {
    zVar1 = '\0';
  }
  return zVar1;
}

