/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_packet.o -> zcl_packet_init_with_intrp_ind
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

zcl_status_t zcl_packet_init_with_intrp_ind(zcl_packet_t *packet,void *arg)

{
  ezb_shortaddr_t eVar1;
  ezb_shortaddr_t eVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  zcl_status_t zVar5;
  undefined3 extraout_var;
  int iVar6;
  
  if (packet == (zcl_packet_t *)0x0) {
    iVar6 = 0x87;
  }
  else if (arg == (void *)0x0) {
    iVar6 = 0x87;
  }
  else {
    packet->payload = *(zcl_packet_payload_t **)((int)arg + 0x20);
    zVar5 = zcl_packet_load_header(packet);
    iVar6 = CONCAT31(extraout_var,zVar5);
    if (iVar6 == 0) {
      (packet->header).src_ep = '\0';
      (packet->header).dst_ep = '\0';
      (packet->header).cluster_id = *(uint16_t *)((int)arg + 0x1a);
      (packet->header).profile_id = *(uint16_t *)((int)arg + 0x18);
      eVar1 = *(ezb_shortaddr_t *)((int)arg + 4);
      eVar2 = *(ezb_shortaddr_t *)((int)arg + 6);
      uVar3 = *(undefined2 *)((int)arg + 8);
      uVar4 = *(undefined2 *)((int)arg + 10);
      *(undefined2 *)&(packet->header).src_addr = *(undefined2 *)((int)arg + 2);
      (packet->header).src_addr.u.short_addr = eVar1;
      (packet->header).src_addr.u.group_addr.bcast = eVar2;
      *(undefined2 *)((int)&(packet->header).src_addr.u + 4) = uVar3;
      *(undefined2 *)((int)&(packet->header).src_addr.u + 6) = uVar4;
      eVar1 = *(ezb_shortaddr_t *)((int)arg + 0x10);
      eVar2 = *(ezb_shortaddr_t *)((int)arg + 0x12);
      uVar3 = *(undefined2 *)((int)arg + 0x14);
      uVar4 = *(undefined2 *)((int)arg + 0x16);
      *(undefined2 *)&(packet->header).dst_addr = *(undefined2 *)((int)arg + 0xe);
      (packet->header).dst_addr.u.short_addr = eVar1;
      (packet->header).dst_addr.u.group_addr.bcast = eVar2;
      *(undefined2 *)((int)&(packet->header).dst_addr.u + 4) = uVar3;
      *(undefined2 *)((int)&(packet->header).dst_addr.u + 6) = uVar4;
      (packet->header).rssi = *(int8_t *)((int)arg + 0x25);
    }
  }
  return (zcl_status_t)iVar6;
}

