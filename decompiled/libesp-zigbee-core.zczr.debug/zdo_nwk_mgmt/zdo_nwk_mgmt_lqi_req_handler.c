/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_nwk_mgmt.o -> zdo_nwk_mgmt_lqi_req_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: req */
/* WARNING: Unknown calling convention */

zdp_status_t zdo_nwk_mgmt_lqi_req_handler(zdo_packet_t *packet,zdo_packet_t *resp)

{
  int iVar1;
  byte bVar2;
  zdp_status_t zVar3;
  undefined1 uVar4;
  uint8_t uVar5;
  undefined1 uVar6;
  undefined2 uVar7;
  undefined3 extraout_var;
  int *piVar8;
  undefined3 extraout_var_00;
  undefined2 *puVar9;
  int iVar10;
  uint uVar11;
  undefined2 uStack_3c;
  undefined2 uStack_3a;
  ezb_extaddr_t ext_addr;
  ezb_extpanid_t extpanid;
  zdp_nwk_mgmt_lqi_rsp_field_t rsp;
  zdp_nwk_mgmt_lqi_req_field_t req;
  uint __nmemb;
  
  rsp.neighbor_table_list._0_1_ = 0;
  extpanid.field_0.u64._4_4_ = 0;
  rsp.status = '\0';
  rsp.neighbor_table_entries = '\0';
  rsp.start_index = '\0';
  rsp.neighbor_table_list_count = '\0';
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
    zVar3 = zdo_op_nwk_mgmt_lqi_req
                      (packet->payload,(zdp_nwk_mgmt_lqi_req_field_t *)&rsp.neighbor_table_list,
                       false);
    if (CONCAT31(extraout_var,zVar3) == 0) {
      ext_addr.field_0.u64._4_4_ = 0;
      extpanid.field_0.u64._0_4_ = 0;
      uVar4 = nwk_neighbor_table_get_size();
      piVar8 = (int *)nwk_get_extended_panid();
      ext_addr.field_0.u64._4_4_ = *piVar8;
      extpanid.field_0.u64._0_4_ = piVar8[1];
      if (ext_addr.field_0.u64._4_4_ == 0 && extpanid.field_0.u64._0_4_ == 0) {
        zVar3 = 0xfe;
      }
      else if ((ext_addr.field_0.u64._4_4_ == -1) && (extpanid.field_0.u64._0_4_ == -1)) {
        zVar3 = 0xfe;
      }
      else {
        uVar5 = zdo_nwk_mgmt_lqi_get_max_entries();
        __nmemb = CONCAT31(extraout_var_00,uVar5);
        rsp._0_4_ = calloc(__nmemb,0x16);
        if ((void *)rsp._0_4_ == (void *)0x0) {
          if (__nmemb != 0) {
            zVar3 = 0xfe;
            goto _L0;
          }
          iVar1 = 0;
          bVar2 = 0;
          uVar11 = 0;
        }
        else {
          iVar1 = 0;
          bVar2 = 0;
          uVar11 = 0;
        }
        while ((iVar1 = nwk_neighbor_table_next(iVar1), iVar1 != 0 && (uVar11 < __nmemb))) {
          if ((byte)rsp.neighbor_table_list <= bVar2) {
            nwk_neighbor_get_extaddr(iVar1,&uStack_3c);
            uVar7 = nwk_neighbor_get_shortaddr(iVar1);
            uVar6 = nwk_neighbor_get_lqa(iVar1);
            puVar9 = (undefined2 *)(rsp._0_4_ + uVar11 * 0x16);
            *puVar9 = ext_addr.field_0.u64._4_2_;
            puVar9[1] = ext_addr.field_0.u64._6_2_;
            puVar9[2] = extpanid.field_0.u64._0_2_;
            puVar9[3] = extpanid.field_0.u64._2_2_;
            iVar10 = rsp._0_4_ + uVar11 * 0x16;
            *(undefined2 *)(iVar10 + 8) = uStack_3c;
            *(undefined2 *)(iVar10 + 10) = uStack_3a;
            *(undefined2 *)(iVar10 + 0xc) = ext_addr.field_0.u64._0_2_;
            *(undefined2 *)(iVar10 + 0xe) = ext_addr.field_0.u64._2_2_;
            *(undefined2 *)(iVar10 + 0x10) = uVar7;
            *(ushort *)(iVar10 + 0x12) =
                 *(ushort *)(iVar10 + 0x12) & 0xfffc | (ushort)*(undefined4 *)(iVar1 + 0xc) & 3;
            *(ushort *)(iVar10 + 0x12) =
                 (ushort)((*(uint *)(iVar1 + 0xc) >> 10 & 1) << 2) |
                 *(ushort *)(iVar10 + 0x12) & 0xfff3;
            *(ushort *)(iVar10 + 0x12) =
                 (ushort)((*(uint *)(iVar1 + 0xc) >> 6 & 7) << 4) |
                 *(ushort *)(iVar10 + 0x12) & 0xff8f;
            *(ushort *)(iVar10 + 0x12) =
                 (ushort)((*(uint *)(iVar1 + 0xc) >> 0xb & 1) << 8) |
                 *(ushort *)(iVar10 + 0x12) & 0xfcff;
            *(byte *)(iVar10 + 0x14) = (byte)(*(uint *)(iVar1 + 0xc) >> 2) & 0xf;
            *(undefined1 *)(iVar10 + 0x15) = uVar6;
            uVar11 = uVar11 + 1 & 0xff;
          }
          bVar2 = bVar2 + 1;
        }
        extpanid.field_0.u64._4_4_ =
             (uint)CONCAT12((char)uVar11,CONCAT11((byte)rsp.neighbor_table_list,uVar4)) << 8;
        zVar3 = zdo_op_nwk_mgmt_lqi_rsp
                          (resp->payload,
                           (zdp_nwk_mgmt_lqi_rsp_field_t *)((int)&extpanid.field_0 + 4),true);
      }
    }
    else {
      zVar3 = 0xfe;
    }
  }
_L0:
  if (rsp._0_4_ != 0) {
    mm_free();
  }
  return zVar3;
}

