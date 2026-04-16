/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> zdo_packet.o -> zdo_packet_indication_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

zdp_status_t zdo_packet_indication_handler(zdo_packet_t *packet)

{
  uint8_t uVar1;
  ushort uVar2;
  int *piVar3;
  zdo_packet_ctx_entry_t *ent;
  int iVar4;
  zdp_status_t zVar5;
  
  if (packet == (zdo_packet_t *)0x0) {
    return 0x80;
  }
  if (-1 < (short)packet->cluster_id) {
    if (packet == (zdo_packet_t *)0x0) {
      zVar5 = 0x80;
    }
    else {
      uVar2 = packet->cluster_id;
      if (uVar2 < 0x20) {
        zVar5 = zdo_device_service_discovery_req_handler();
        return zVar5;
      }
      if (uVar2 < 0x30) {
        zVar5 = zdo_bind_mgmt_req_handler();
        return zVar5;
      }
      zVar5 = 0x84;
      if (uVar2 < 0x40) {
        zVar5 = zdo_nwk_mgmt_req_handler();
        return zVar5;
      }
    }
    return zVar5;
  }
  iVar4 = 0x80;
  if (packet != (zdo_packet_t *)0x0) {
    uVar1 = packet->tsn;
    iVar4 = core_globals_get();
    piVar3 = *(int **)(iVar4 + 0xd10);
    iVar4 = 0xfe;
    if (piVar3 != (int *)0x0) {
      for (; ent = (zdo_packet_ctx_entry_t *)(piVar3 + -9),
          ent != (zdo_packet_ctx_entry_t *)0xffffffdc; piVar3 = (int *)*piVar3) {
        if (ent->tsn == uVar1) {
          memcpy(&packet->ctx,piVar3 + -3,0xc);
          uVar2 = packet->cluster_id;
          if (uVar2 < 0x8020) {
            iVar4 = zdo_device_service_discovery_rsp_handler(packet);
          }
          else if (uVar2 < 0x8030) {
            iVar4 = zdo_bind_mgmt_rsp_handler(packet);
          }
          else {
            iVar4 = 0x84;
            if (0x803f < uVar2) goto _L0;
            iVar4 = zdo_nwk_mgmt_rsp_handler(packet);
          }
          if ((iVar4 == 0) &&
             (*(byte *)(piVar3 + -4) = *(byte *)(piVar3 + -4) | 1, *(char *)(piVar3 + -3) == '\x01')
             ) {
            zdo_packet_ctx_list_remove_entry(ent);
            zdo_packet_ctx_free_entry(ent);
          }
          goto _L0;
        }
      }
      iVar4 = 0xfe;
    }
  }
_L0:
  return (zdp_status_t)iVar4;
}

