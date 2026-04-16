/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_nwk_mgmt.o -> zdo_nwk_mgmt_bind_req_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

zdp_status_t zdo_nwk_mgmt_bind_req_handler(zdo_packet_t *packet,zdo_packet_t *resp)

{
  byte bVar1;
  byte bVar2;
  zdp_status_t zVar3;
  uint8_t uVar4;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  int iVar5;
  undefined2 *puVar6;
  int iVar7;
  uint uVar8;
  undefined2 local_48;
  undefined2 uStack_46;
  ezb_extaddr_t src_addr;
  ezb_extaddr_t dst_extaddr;
  aps_bind_table_iterator_t itor;
  zdp_nwk_mgmt_bind_rsp_field_t rsp;
  zdp_nwk_mgmt_bind_req_field_t req;
  uint __nmemb;
  
  rsp.binding_table_list._0_1_ = 0;
  itor.dst = (aps_bind_dst_t *)0x0;
  rsp.status = '\0';
  rsp.binding_table_entries = '\0';
  rsp.start_index = '\0';
  rsp.binding_table_list_count = '\0';
  if (packet == (zdo_packet_t *)0x0) {
    zVar3 = 0xfe;
  }
  else if (packet->payload == (zdo_packet_payload_t *)0x0) {
    zVar3 = 0xfe;
  }
  else if (resp == (zdo_packet_t *)0x0) {
    zVar3 = 0xfe;
  }
  else {
    zVar3 = zdo_op_nwk_mgmt_bind_req
                      (packet->payload,(zdp_nwk_mgmt_bind_req_field_t *)&rsp.binding_table_list,
                       false);
    if (CONCAT31(extraout_var,zVar3) == 0) {
      aps_bind_table_iterator_init(0,(undefined1 *)((int)&dst_extaddr.field_0 + 4));
      bVar2 = 0;
      while (dst_extaddr.field_0.u8[4] == '\0') {
        bVar2 = bVar2 + 1;
        aps_bind_table_iterator_next((undefined1 *)((int)&dst_extaddr.field_0 + 4));
      }
      if (bVar2 == 0) {
        itor.dst = (aps_bind_dst_t *)((uint)(byte)rsp.binding_table_list << 0x10);
        rsp.status = '\0';
        rsp.binding_table_entries = '\0';
        rsp.start_index = '\0';
        rsp.binding_table_list_count = '\0';
        zVar3 = zdo_op_nwk_mgmt_bind_rsp
                          (resp->payload,(zdp_nwk_mgmt_bind_rsp_field_t *)&itor.dst,true);
      }
      else if ((byte)rsp.binding_table_list < bVar2) {
        uVar4 = zdo_nwk_mgmt_bind_get_max_entries();
        __nmemb = CONCAT31(extraout_var_00,uVar4);
        rsp._0_4_ = calloc(__nmemb,0x18);
        if (((void *)rsp._0_4_ == (void *)0x0) && (__nmemb != 0)) {
          zVar3 = 0xfe;
        }
        else {
          aps_bind_table_iterator_init(0,(undefined1 *)((int)&dst_extaddr.field_0 + 4));
          bVar1 = 0;
          uVar8 = 0;
          while ((dst_extaddr.field_0.u8[4] == '\0' && (uVar8 < __nmemb))) {
            if ((byte)rsp.binding_table_list <= bVar1) {
              iVar5 = nwk_address_extended_by_ref(*(undefined2 *)itor._0_4_,&local_48);
              if (iVar5 != 0) {
                return 0xfe;
              }
              iVar5 = uVar8 * 0x18;
              puVar6 = (undefined2 *)(rsp._0_4_ + iVar5);
              *puVar6 = local_48;
              puVar6[1] = uStack_46;
              puVar6[2] = src_addr.field_0.u64._0_2_;
              puVar6[3] = src_addr.field_0.u64._2_2_;
              iVar7 = rsp._0_4_ + iVar5;
              *(undefined1 *)(iVar7 + 8) = *(undefined1 *)(itor._0_4_ + 2);
              *(undefined2 *)(iVar7 + 10) = *(undefined2 *)(itor._0_4_ + 4);
              if (((itor.src)->cluster_id & 0x100) == 0) {
                iVar7 = nwk_address_extended_by_ref
                                  ((itor.src)->addr_ref,(undefined1 *)((int)&src_addr.field_0 + 4));
                if (iVar7 != 0) {
                  return 0xfe;
                }
                iVar5 = rsp._0_4_ + iVar5;
                *(undefined1 *)(iVar5 + 0xc) = 3;
                *(undefined2 *)(iVar5 + 0xe) = src_addr.field_0.u64._4_2_;
                *(undefined2 *)(iVar5 + 0x10) = src_addr.field_0.u64._6_2_;
                *(undefined2 *)(iVar5 + 0x12) = dst_extaddr.field_0.u64._0_2_;
                *(undefined2 *)(iVar5 + 0x14) = dst_extaddr.field_0.u64._2_2_;
                *(uint8_t *)(iVar5 + 0x16) = (itor.src)->src_ep;
              }
              else {
                *(undefined1 *)(iVar7 + 0xc) = 1;
                *(nwk_addr_ref_t *)(iVar7 + 0xe) = (itor.src)->addr_ref;
                *(undefined1 *)(iVar7 + 0x16) = 0;
              }
              uVar8 = uVar8 + 1 & 0xff;
            }
            bVar1 = bVar1 + 1;
            aps_bind_table_iterator_next((undefined1 *)((int)&dst_extaddr.field_0 + 4));
          }
          itor.dst = (aps_bind_dst_t *)
                     ((uint)CONCAT12((char)uVar8,CONCAT11((byte)rsp.binding_table_list,bVar2)) << 8)
          ;
          zVar3 = zdo_op_nwk_mgmt_bind_rsp
                            (resp->payload,(zdp_nwk_mgmt_bind_rsp_field_t *)&itor.dst,true);
          if (rsp._0_4_ != 0) {
            mm_free();
          }
        }
      }
      else {
        itor.dst = (aps_bind_dst_t *)
                   CONCAT13(0,CONCAT12((byte)rsp.binding_table_list,CONCAT11(bVar2,0x8f)));
        rsp.status = '\0';
        rsp.binding_table_entries = '\0';
        rsp.start_index = '\0';
        rsp.binding_table_list_count = '\0';
        zVar3 = zdo_op_nwk_mgmt_bind_rsp
                          (resp->payload,(zdp_nwk_mgmt_bind_rsp_field_t *)&itor.dst,true);
      }
    }
    else {
      zVar3 = 0xfe;
    }
  }
  return zVar3;
}

