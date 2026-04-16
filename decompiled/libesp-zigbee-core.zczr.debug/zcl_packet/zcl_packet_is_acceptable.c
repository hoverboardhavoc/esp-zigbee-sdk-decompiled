/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_packet.o -> zcl_packet_is_acceptable
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

zcl_status_t zcl_packet_is_acceptable(zcl_packet_t *packet)

{
  zcl_status_t zVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (packet == (zcl_packet_t *)0x0) {
    zVar1 = 0xfe;
  }
  else {
    iVar2 = af_endpoint_is_gateway((packet->header).dst_ep);
    if (iVar2 == 0) {
      iVar2 = af_get_ep_desc((packet->header).dst_ep);
      if (iVar2 == 0) {
        zVar1 = 0x81;
      }
      else if (*(uint16_t *)(iVar2 + 2) == (packet->header).profile_id) {
        if (((packet->header).fc & 8) == 0) {
          uVar3 = 1;
        }
        else {
          uVar3 = 2;
        }
        iVar2 = zcl_get_cluster_desc((packet->header).dst_ep,(packet->header).cluster_id,uVar3);
        if (iVar2 == 0) {
          zVar1 = 0xc3;
        }
        else {
          zVar1 = '\0';
        }
      }
      else {
        zVar1 = 0x81;
      }
    }
    else {
      zVar1 = '\0';
    }
  }
  return zVar1;
}

