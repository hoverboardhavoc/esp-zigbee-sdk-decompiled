/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> groups.o -> groups_cluster_get_group_membership_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t
groups_cluster_get_group_membership_cmd_handler(zcl_packet_t *packet,zcl_packet_t *rsp)

{
  uint unaff_s0;
  ezb_zcl_status_t eVar1;
  undefined1 uVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  void *unaff_s2;
  char cVar6;
  zcl_packet_payload_t *pzVar7;
  uint unaff_s5;
  short *psVar8;
  undefined2 uStack_36;
  byte bStack_33;
  uint16_t uStack_32;
  uint8_t group_count;
  uint16_t offset;
  
  uStack_32 = 0;
  bStack_33 = 0;
  if ((packet == (zcl_packet_t *)0x0) || (rsp == (zcl_packet_t *)0x0)) {
    __assert_func("//build/esp-zigbee/src/core/api/zcl/cluster/groups.c",0x18d,
                  "groups_cluster_get_group_membership_cmd_handler","packet && rsp");
    goto _L0;
  }
  unaff_s5 = (uint)(packet->header).dst_ep;
  af_read_le8(packet->payload,&uStack_32,&bStack_33);
  unaff_s0 = (uint)bStack_33;
  unaff_s2 = calloc(unaff_s0,2);
  if (unaff_s0 != 0) {
    if (unaff_s2 == (void *)0x0) {
      uVar5 = 0xfe;
      goto _L0;
    }
    unaff_s0 = 0;
  }
  for (; unaff_s0 < bStack_33; unaff_s0 = unaff_s0 + 1 & 0xff) {
_L0:
    af_read_le16(packet->payload,&uStack_32,(uint16_t *)(unaff_s0 * 2 + (int)unaff_s2));
  }
  uVar3 = zmsg_get_length(packet->payload);
  if (uVar3 < uStack_32) {
    uVar5 = 0x80;
_L0:
    eVar1 = zcl_packet_setup_default_response(rsp,packet,uVar5);
    return eVar1;
  }
  pzVar7 = rsp->payload;
  uVar2 = aps_group_table_get_free_size();
  uStack_36._0_1_ = uVar2;
  zmsg_append_bytes(pzVar7,1,&uStack_36);
  uVar5 = zmsg_get_length(rsp->payload);
  uStack_36 = (ushort)uStack_36._1_1_ << 8;
  zmsg_append_bytes(rsp->payload,1,&uStack_36);
  if (bStack_33 == 0) {
    psVar8 = (short *)0x0;
    cVar6 = '\0';
    while (psVar8 = (short *)aps_group_table_next_by_endpoint(unaff_s5,psVar8),
          psVar8 != (short *)0x0) {
      uStack_36 = *psVar8;
      zmsg_append_bytes(rsp->payload,2,&uStack_36);
      cVar6 = cVar6 + '\x01';
    }
  }
  else {
    cVar6 = '\0';
    for (uVar3 = 0; uVar3 < bStack_33; uVar3 = uVar3 + 1 & 0xff) {
      psVar8 = (short *)(uVar3 * 2 + (int)unaff_s2);
      iVar4 = aps_group_table_find(*psVar8);
      if ((iVar4 != 0) &&
         (iVar4 = aps_group_table_is_endpoint_in_group(unaff_s5,*psVar8), iVar4 != 0)) {
        uStack_36 = *psVar8;
        zmsg_append_bytes(rsp->payload,2,&uStack_36);
        cVar6 = cVar6 + '\x01';
      }
    }
    if ((cVar6 != '\0') && (0xfff7 < (packet->header).dst_addr.u.short_addr)) {
      uVar5 = 0xfe;
      goto _L0;
    }
  }
  uStack_36 = CONCAT11(uStack_36._1_1_,cVar6);
  zmsg_write_bytes(rsp->payload,uVar5,1,&uStack_36);
  eVar1 = zcl_packet_setup_response(rsp,packet,2);
  return eVar1;
}

