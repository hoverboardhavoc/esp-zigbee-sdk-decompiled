/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_packet.o -> zdo_packet_ctx_create_entry
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

zdo_packet_ctx_entry_t * zdo_packet_ctx_create_entry(uint8_t tsn,zdo_packet_ctx_t *ctx)

{
  byte bVar1;
  zdo_packet_ctx_entry_t *pzVar2;
  undefined4 *in_a1;
  
  pzVar2 = (zdo_packet_ctx_entry_t *)calloc(1,0x28);
  if (pzVar2 != (zdo_packet_ctx_entry_t *)0x0) {
    pzVar2->tsn = tsn;
    *(undefined4 *)&pzVar2->ctx = *in_a1;
    (pzVar2->ctx).req_ctx.cb = (zdo_packet_req_callback_t)in_a1[1];
    (pzVar2->ctx).req_ctx.arg = (zdo_packet_user_ctx_t)in_a1[2];
    bVar1 = pzVar2->field_0x14;
    pzVar2->field_0x14 = bVar1 & 0xfe;
    pzVar2->field_0x14 = bVar1 & 0xfc;
    (pzVar2->node).next = &pzVar2->node;
  }
  return pzVar2;
}

