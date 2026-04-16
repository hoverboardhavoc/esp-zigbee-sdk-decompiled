/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> scenes.o -> scenes_cluster_get_scene_membership_req_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t
scenes_cluster_get_scene_membership_req_handler(zcl_packet_t *packet,zcl_packet_t *rsp)

{
  uint8_t ep_id;
  ezb_zcl_status_t eVar1;
  uint uVar2;
  zcl_scene_table_t *pzVar3;
  undefined3 extraout_var;
  undefined4 uVar4;
  int iVar5;
  char cVar6;
  char cVar7;
  ushort uStack_36;
  uint16_t uStack_34;
  uint16_t uStack_32;
  uint16_t group_id;
  uint16_t offset;
  
  ep_id = (packet->header).dst_ep;
  uStack_32 = 0;
  uStack_34 = 0;
  af_read_le16(packet->payload,&uStack_32,&uStack_34);
  uVar2 = zmsg_get_length(packet->payload);
  if (uVar2 < uStack_32) {
    cVar6 = '\0';
    iVar5 = 0x80;
  }
  else {
    pzVar3 = scene_table_get(ep_id);
    if (pzVar3 == (zcl_scene_table_t *)0x0) {
      cVar6 = '\0';
      iVar5 = 0x8b;
    }
    else {
      cVar6 = pzVar3->total - *pzVar3->count;
      eVar1 = scenes_check_group_id(uStack_34);
      iVar5 = CONCAT31(extraout_var,eVar1);
      if (iVar5 == 0) {
        uStack_36._0_1_ = eVar1;
        zmsg_append_bytes(rsp->payload,1,&uStack_36);
        uStack_36 = CONCAT11(uStack_36._1_1_,cVar6);
        zmsg_append_bytes(rsp->payload,1,&uStack_36);
        uStack_36 = uStack_34;
        zmsg_append_bytes(rsp->payload,2,&uStack_36);
        uStack_36 = uStack_36 & 0xff00;
        zmsg_append_bytes(rsp->payload,1,&uStack_36);
        if (*pzVar3->count != '\0') {
          uVar4 = zmsg_get_length(rsp->payload);
          uStack_36 = uStack_36 & 0xff00;
          zmsg_append_bytes(rsp->payload,1,&uStack_36);
          cVar7 = '\0';
          for (uVar2 = 0; uVar2 < pzVar3->total; uVar2 = uVar2 + 1 & 0xff) {
            if (*(ushort *)&pzVar3[uVar2 * 4 + 1].field_0x2 == uStack_34) {
              uStack_36 = CONCAT11(uStack_36._1_1_,*(undefined1 *)&pzVar3[uVar2 * 4 + 1].count);
              zmsg_append_bytes(rsp->payload,1,&uStack_36);
              cVar7 = cVar7 + '\x01';
            }
          }
          uStack_36 = CONCAT11(uStack_36._1_1_,cVar7);
          zmsg_write_bytes(rsp->payload,uVar4,1,&uStack_36);
        }
      }
    }
  }
  if ((packet->header).dst_addr.u.short_addr < 0xfff8) {
    if (iVar5 != 0) {
      uStack_36._0_1_ = (char)iVar5;
      zmsg_append_bytes(rsp->payload,1,&uStack_36);
      uStack_36 = CONCAT11(uStack_36._1_1_,cVar6);
      zmsg_append_bytes(rsp->payload,1,&uStack_36);
      uStack_36 = uStack_34;
      zmsg_append_bytes(rsp->payload,2,&uStack_36);
    }
    eVar1 = zcl_packet_setup_response(rsp,packet,6);
  }
  else {
    eVar1 = 0xfe;
  }
  return eVar1;
}

