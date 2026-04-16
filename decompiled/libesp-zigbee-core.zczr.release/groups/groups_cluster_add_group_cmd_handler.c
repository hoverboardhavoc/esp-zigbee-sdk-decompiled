/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> groups.o -> groups_cluster_add_group_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: offset */
/* WARNING: Unknown calling convention */

ezb_zcl_status_t groups_cluster_add_group_cmd_handler(zcl_packet_t *packet,zcl_packet_t *rsp)

{
  bool bVar1;
  bool bVar2;
  zcl_packet_t *unaff_s1;
  ezb_zcl_status_t eVar3;
  uint8_t uVar4;
  uint uVar5;
  int iVar6;
  uint16_t uStack_14;
  uint16_t uStack_12;
  uint16_t offset;
  uint16_t group_id;
  
  uStack_14 = 0;
  uStack_12 = 0xffff;
  if ((packet == (zcl_packet_t *)0x0) || (unaff_s1 = rsp, rsp == (zcl_packet_t *)0x0)) {
    packet = (zcl_packet_t *)__assert_func(0,0,0,0);
  }
  uVar5 = zmsg_get_length(packet->payload);
  af_read_le16(packet->payload,&uStack_14,&uStack_12);
  if (uVar5 < uStack_14) {
    bVar1 = false;
    bVar2 = true;
  }
  else {
    uVar4 = (packet->header).cmd_id;
    bVar1 = uVar4 == '\x05';
    if ((uVar4 == '\x05') && (iVar6 = ezb_zcl_is_identifying((packet->header).dst_ep), iVar6 == 0))
    {
      bVar1 = true;
    }
    else if ((ushort)(uStack_12 - 1) < 0xfff7) {
      aps_group_table_add((packet->header).dst_ep);
      uVar4 = err_to_zcl_status();
      zmsg_append_u8(unaff_s1->payload,uVar4);
      zmsg_append_le16(unaff_s1->payload,uStack_12);
    }
    else {
      zmsg_append_u8(unaff_s1->payload,0x87);
    }
    bVar2 = false;
  }
  eVar3 = 0xfe;
  if ((packet->header).dst_addr.u.short_addr < 0xfff8) {
    if ((bVar2) || (bVar1)) {
      eVar3 = zcl_packet_setup_default_response(unaff_s1,packet);
    }
    else {
      eVar3 = zcl_packet_setup_response();
    }
  }
  return eVar3;
}

