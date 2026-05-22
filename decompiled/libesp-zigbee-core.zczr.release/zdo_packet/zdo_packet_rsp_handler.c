/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.release -> zdo_packet.o -> zdo_packet_rsp_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

zdp_status_t zdo_packet_rsp_handler(zdo_packet_t *packet)

{
  uint8_t uVar1;
  ushort uVar2;
  int *piVar3;
  zdo_packet_ctx_entry_t *ent;
  int iVar4;
  
  iVar4 = 0x80;
  if (packet != (zdo_packet_t *)0x0) {
    uVar1 = packet->tsn;
    iVar4 = core_globals_get();
    piVar3 = *(int **)(iVar4 + 0xcac);
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

