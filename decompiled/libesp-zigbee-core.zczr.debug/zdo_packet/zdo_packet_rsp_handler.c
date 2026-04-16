/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_packet.o -> zdo_packet_rsp_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

zdp_status_t zdo_packet_rsp_handler(zdo_packet_t *packet)

{
  ushort uVar1;
  undefined3 uVar2;
  int iVar3;
  zdo_packet_ctx_entry_t *ent;
  
  if (packet == (zdo_packet_t *)0x0) {
    iVar3 = 0x80;
  }
  else {
    ent = zdo_packet_ctx_list_find_entry(packet->tsn);
    if (ent == (zdo_packet_ctx_entry_t *)0x0) {
      iVar3 = 0xfe;
    }
    else {
      uVar2 = *(undefined3 *)&(ent->ctx).field_0x1;
      (packet->ctx).mode = (ent->ctx).mode;
      *(undefined3 *)&(packet->ctx).field_0x1 = uVar2;
      (packet->ctx).req_ctx.cb = (ent->ctx).req_ctx.cb;
      (packet->ctx).req_ctx.arg = (ent->ctx).req_ctx.arg;
      uVar1 = packet->cluster_id;
      if (uVar1 < 0x8020) {
        iVar3 = zdo_device_service_discovery_rsp_handler(packet);
      }
      else if (uVar1 < 0x8030) {
        iVar3 = zdo_bind_mgmt_rsp_handler(packet);
      }
      else {
        if (0x803f < uVar1) {
          iVar3 = 0x84;
          goto _L0;
        }
        iVar3 = zdo_nwk_mgmt_rsp_handler(packet);
      }
      if ((iVar3 == 0) && (ent->field_0x14 = ent->field_0x14 | 1, (ent->ctx).mode == '\x01')) {
        zdo_packet_ctx_list_remove_entry(ent);
        zdo_packet_ctx_free_entry(ent);
      }
    }
  }
_L0:
  return (zdp_status_t)iVar3;
}

