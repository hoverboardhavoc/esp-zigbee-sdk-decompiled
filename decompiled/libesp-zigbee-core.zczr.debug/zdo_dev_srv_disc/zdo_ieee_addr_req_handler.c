/*
 * Last changed at upstream commit 9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * https://github.com/espressif/esp-zigbee-sdk/commit/9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * Upstream date: 2026-07-01 11:36:50 +0800
 * Upstream subject: change: update esp-zigbee-lib (9401bce7)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_dev_srv_disc.o -> zdo_ieee_addr_req_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

zdp_status_t zdo_ieee_addr_req_handler(zdo_packet_t *packet,zdo_packet_t *resp)

{
  bool bVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  zdp_status_t zVar4;
  undefined2 uVar5;
  undefined3 extraout_var;
  uint uVar6;
  undefined2 *puVar7;
  undefined4 *puVar8;
  int iVar9;
  uint uVar10;
  undefined1 auStack_38 [4];
  zdp_ieee_addr_rsp_field_t rsp;
  zdp_ieee_addr_req_field_t req;
  
  rsp.nwk_addr_assoc_dev_list = (ezb_shortaddr_t *)0x0;
  auStack_38 = (undefined1  [4])0x0;
  rsp._0_4_ = 0;
  rsp.ieee_addr_remote_dev.field_0.u64._3_4_ = 0;
  rsp._8_4_ = 0;
  rsp.num_assoc_dev = '\0';
  rsp.start_index = '\0';
  rsp._14_2_ = 0;
  if (packet == (zdo_packet_t *)0x0) {
    zVar4 = 0xfe;
  }
  else if (packet->payload == (zdo_packet_payload_t *)0x0) {
    zVar4 = 0xfe;
  }
  else if (resp == (zdo_packet_t *)0x0) {
    zVar4 = 0xfe;
  }
  else {
    zVar4 = zdo_op_ieee_addr_req
                      (packet->payload,(zdp_ieee_addr_req_field_t *)&rsp.nwk_addr_assoc_dev_list,
                       false);
    if (CONCAT31(extraout_var,zVar4) == 0) {
      auStack_38[1] = 0xff;
      auStack_38[2] = 0xff;
      auStack_38[3] = 0xff;
      rsp._0_4_ = 0xffffffff;
      rsp.ieee_addr_remote_dev.field_0.u8[3] = 0xff;
      uVar10 = (uint)rsp.nwk_addr_assoc_dev_list & 0xffff;
      uVar6 = nwk_get_short_address();
      if (uVar10 == uVar6) {
        nwk_address_extended_by_short((uint)rsp.nwk_addr_assoc_dev_list & 0xffff,auStack_38 + 1);
      }
      else {
        puVar7 = (undefined2 *)
                 nwk_neighbor_table_get_by_short((uint)rsp.nwk_addr_assoc_dev_list & 0xffff);
        if ((puVar7 != (undefined2 *)0x0) && ((*(uint *)(puVar7 + 6) & 3) == 2)) {
          nwk_address_extended_by_ref(*puVar7,auStack_38 + 1);
        }
      }
      if (((rsp._0_4_ << 0x18 | (uint)auStack_38 >> 8) == 0xffffffff) &&
         ((rsp.ieee_addr_remote_dev.field_0.u64._3_4_ << 0x18 | (uint)rsp._0_4_ >> 8) == 0xffffffff)
         ) {
        auStack_38[0] = 0x81;
        rsp.ieee_addr_remote_dev.field_0.u64._5_2_ = rsp.nwk_addr_assoc_dev_list._0_2_;
        zVar4 = zdo_op_ieee_addr_rsp
                          (resp->payload,rsp.nwk_addr_assoc_dev_list._2_1_,
                           (zdp_ieee_addr_rsp_field_t *)auStack_38,true);
      }
      else if (rsp.nwk_addr_assoc_dev_list._2_1_ == '\0') {
        auStack_38 = (undefined1  [4])((uint)(uint3)auStack_38._1_3_ << 8);
        rsp.ieee_addr_remote_dev.field_0.u64._5_2_ = rsp.nwk_addr_assoc_dev_list._0_2_;
        nwk_address_extended_by_short(auStack_38 + 1);
        zVar4 = zdo_op_ieee_addr_rsp
                          (resp->payload,rsp.nwk_addr_assoc_dev_list._2_1_,
                           (zdp_ieee_addr_rsp_field_t *)auStack_38,true);
      }
      else if (rsp.nwk_addr_assoc_dev_list._2_1_ == '\x01') {
        auStack_38 = (undefined1  [4])((uint)(uint3)auStack_38._1_3_ << 8);
        puVar8 = (undefined4 *)nwk_get_extended_address();
        uVar2 = *puVar8;
        uVar3 = puVar8[1];
        auStack_38[1] = (char)*(undefined3 *)puVar8;
        auStack_38[2] = (char)((uint)uVar2 >> 8);
        auStack_38[3] = (char)((uint)uVar2 >> 0x10);
        rsp.ieee_addr_remote_dev.field_0.u8[0] = (char)*(undefined3 *)(puVar8 + 1);
        rsp.status = (uint8_t)((uint)uVar2 >> 0x18);
        rsp.ieee_addr_remote_dev.field_0.u8[1] = (char)((uint)uVar3 >> 8);
        rsp.ieee_addr_remote_dev.field_0.u8[2] = (char)((uint)uVar3 >> 0x10);
        rsp.ieee_addr_remote_dev.field_0.u8[3] = (char)((uint)uVar3 >> 0x18);
        uVar5 = nwk_get_short_address();
        rsp.ieee_addr_remote_dev.field_0.u64._5_2_ = uVar5;
        rsp._8_4_ = (uint)CONCAT21(rsp.nwk_addr_remote_dev,rsp.nwk_addr_assoc_dev_list._3_1_) << 8;
        iVar9 = nwk_is_device_zczr();
        if (iVar9 != 0) {
          uVar6 = nwk_neighbor_table_get_ed_num();
          if ((uVar6 & 0xff) != 0) {
            rsp._12_4_ = calloc(uVar6 & 0xff,2);
          }
          iVar9 = 0;
          uVar6 = 0;
          while (iVar9 = nwk_child_table_next(iVar9), iVar9 != 0) {
            if (((*(uint *)(iVar9 + 0xc) & 0x3c0) == 0x40) &&
               (uVar10 = uVar6 + 1 & 0xff, bVar1 = ((uint)rsp._8_4_ >> 8 & 0xff) <= uVar6,
               uVar6 = uVar10, bVar1)) {
              uVar10 = rsp._8_4_ & 0xff;
              rsp.ieee_addr_remote_dev.field_0.u8[7] = (char)rsp._8_4_ + '\x01';
              puVar7 = (undefined2 *)(rsp._12_4_ + uVar10 * 2);
              uVar5 = nwk_neighbor_get_shortaddr(iVar9);
              *puVar7 = uVar5;
            }
          }
        }
        zVar4 = zdo_op_ieee_addr_rsp
                          (resp->payload,rsp.nwk_addr_assoc_dev_list._2_1_,
                           (zdp_ieee_addr_rsp_field_t *)auStack_38,true);
      }
      else {
        auStack_38[0] = 0x80;
        puVar8 = (undefined4 *)nwk_get_extended_address();
        uVar2 = *puVar8;
        uVar3 = puVar8[1];
        auStack_38[1] = (char)*(undefined3 *)puVar8;
        auStack_38[2] = (char)((uint)uVar2 >> 8);
        auStack_38[3] = (char)((uint)uVar2 >> 0x10);
        rsp.ieee_addr_remote_dev.field_0.u8[0] = (char)*(undefined3 *)(puVar8 + 1);
        rsp.status = (uint8_t)((uint)uVar2 >> 0x18);
        rsp.ieee_addr_remote_dev.field_0.u8[1] = (char)((uint)uVar3 >> 8);
        rsp.ieee_addr_remote_dev.field_0.u8[2] = (char)((uint)uVar3 >> 0x10);
        rsp.ieee_addr_remote_dev.field_0.u8[3] = (char)((uint)uVar3 >> 0x18);
        uVar5 = nwk_get_short_address();
        rsp.ieee_addr_remote_dev.field_0.u64._5_2_ = uVar5;
        zVar4 = zdo_op_ieee_addr_rsp
                          (resp->payload,rsp.nwk_addr_assoc_dev_list._2_1_,
                           (zdp_ieee_addr_rsp_field_t *)auStack_38,true);
      }
    }
    else {
      zVar4 = 0xfe;
    }
  }
  if (rsp._12_4_ != 0) {
    mm_free();
  }
  return zVar4;
}

