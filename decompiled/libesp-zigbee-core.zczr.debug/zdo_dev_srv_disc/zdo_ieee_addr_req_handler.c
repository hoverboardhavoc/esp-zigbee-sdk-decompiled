/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_dev_srv_disc.o -> zdo_ieee_addr_req_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: req */
/* WARNING: Unknown calling convention */

zdp_status_t zdo_ieee_addr_req_handler(zdo_packet_t *packet,zdo_packet_t *resp)

{
  undefined4 uVar1;
  undefined4 uVar2;
  zdp_status_t zVar3;
  undefined2 uVar4;
  undefined3 extraout_var;
  uint uVar5;
  undefined2 *puVar6;
  undefined4 *puVar7;
  int iVar8;
  uint uVar9;
  undefined1 auStack_28 [4];
  zdp_ieee_addr_rsp_field_t rsp;
  zdp_ieee_addr_req_field_t req;
  
  rsp.nwk_addr_assoc_dev_list = (ezb_shortaddr_t *)0x0;
  auStack_28 = (undefined1  [4])0x0;
  rsp._0_4_ = 0;
  rsp.ieee_addr_remote_dev.field_0.u64._3_4_ = 0;
  rsp._8_4_ = 0;
  rsp.num_assoc_dev = '\0';
  rsp.start_index = '\0';
  rsp._14_2_ = 0;
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
    zVar3 = zdo_op_ieee_addr_req
                      (packet->payload,(zdp_ieee_addr_req_field_t *)&rsp.nwk_addr_assoc_dev_list,
                       false);
    if (CONCAT31(extraout_var,zVar3) == 0) {
      auStack_28[1] = 0xff;
      auStack_28[2] = 0xff;
      auStack_28[3] = 0xff;
      rsp._0_4_ = 0xffffffff;
      rsp.ieee_addr_remote_dev.field_0.u8[3] = 0xff;
      uVar9 = (uint)rsp.nwk_addr_assoc_dev_list & 0xffff;
      uVar5 = nwk_get_short_address();
      if (uVar9 == uVar5) {
        nwk_address_extended_by_short((uint)rsp.nwk_addr_assoc_dev_list & 0xffff,auStack_28 + 1);
      }
      else {
        puVar6 = (undefined2 *)
                 nwk_neighbor_table_get_by_short((uint)rsp.nwk_addr_assoc_dev_list & 0xffff);
        if ((puVar6 != (undefined2 *)0x0) && ((*(uint *)(puVar6 + 6) & 3) == 2)) {
          nwk_address_extended_by_ref(*puVar6,auStack_28 + 1);
        }
      }
      if (((rsp._0_4_ << 0x18 | (uint)auStack_28 >> 8) == 0xffffffff) &&
         ((rsp.ieee_addr_remote_dev.field_0.u64._3_4_ << 0x18 | (uint)rsp._0_4_ >> 8) == 0xffffffff)
         ) {
        auStack_28[0] = 0x81;
        rsp.ieee_addr_remote_dev.field_0.u64._5_2_ = rsp.nwk_addr_assoc_dev_list._0_2_;
        zVar3 = zdo_op_ieee_addr_rsp
                          (resp->payload,rsp.nwk_addr_assoc_dev_list._2_1_,
                           (zdp_ieee_addr_rsp_field_t *)auStack_28,true);
      }
      else if (rsp.nwk_addr_assoc_dev_list._2_1_ == '\0') {
        auStack_28 = (undefined1  [4])((uint)(uint3)auStack_28._1_3_ << 8);
        rsp.ieee_addr_remote_dev.field_0.u64._5_2_ = rsp.nwk_addr_assoc_dev_list._0_2_;
        nwk_address_extended_by_short(auStack_28 + 1);
        zVar3 = zdo_op_ieee_addr_rsp
                          (resp->payload,rsp.nwk_addr_assoc_dev_list._2_1_,
                           (zdp_ieee_addr_rsp_field_t *)auStack_28,true);
      }
      else if (rsp.nwk_addr_assoc_dev_list._2_1_ == '\x01') {
        iVar8 = nwk_is_device_zczr();
        if (iVar8 != 0) {
          auStack_28 = (undefined1  [4])((uint)auStack_28 & 0xffffff00);
          puVar7 = (undefined4 *)nwk_get_extended_address();
          uVar1 = *puVar7;
          uVar2 = puVar7[1];
          auStack_28[1] = (char)*(undefined3 *)puVar7;
          auStack_28[2] = (char)((uint)uVar1 >> 8);
          auStack_28[3] = (char)((uint)uVar1 >> 0x10);
          rsp.ieee_addr_remote_dev.field_0.u8[0] = (char)*(undefined3 *)(puVar7 + 1);
          rsp.status = (uint8_t)((uint)uVar1 >> 0x18);
          rsp.ieee_addr_remote_dev.field_0.u8[1] = (char)((uint)uVar2 >> 8);
          rsp.ieee_addr_remote_dev.field_0.u8[2] = (char)((uint)uVar2 >> 0x10);
          rsp.ieee_addr_remote_dev.field_0.u8[3] = (char)((uint)uVar2 >> 0x18);
          uVar4 = nwk_get_short_address();
          rsp.ieee_addr_remote_dev.field_0.u64._5_2_ = uVar4;
          uVar5 = nwk_neighbor_table_get_ed_num();
          if ((uVar5 & 0xff) != 0) {
            rsp._12_4_ = calloc(uVar5 & 0xff,2);
          }
          rsp._8_4_ = (uint)CONCAT21(rsp.nwk_addr_remote_dev,rsp.nwk_addr_assoc_dev_list._3_1_) << 8
          ;
          puVar6 = (undefined2 *)0x0;
          uVar5 = 0;
          while (puVar6 = (undefined2 *)nwk_neighbor_table_next(puVar6), puVar6 != (undefined2 *)0x0
                ) {
            uVar9 = (uint)rsp._8_4_ >> 8 & 0xff;
            if ((uVar9 <= uVar5) && ((*(uint *)(puVar6 + 6) & 3) == 2)) {
              nwk_address_short_by_ref(*puVar6,rsp._12_4_ + (uVar5 - uVar9) * 2);
              rsp.ieee_addr_remote_dev.field_0.u8[7] = (char)rsp._8_4_ + '\x01';
            }
            uVar5 = uVar5 + 1 & 0xff;
          }
        }
        zVar3 = zdo_op_ieee_addr_rsp
                          (resp->payload,rsp.nwk_addr_assoc_dev_list._2_1_,
                           (zdp_ieee_addr_rsp_field_t *)auStack_28,true);
      }
      else {
        auStack_28[0] = 0x80;
        puVar7 = (undefined4 *)nwk_get_extended_address();
        uVar1 = *puVar7;
        uVar2 = puVar7[1];
        auStack_28[1] = (char)*(undefined3 *)puVar7;
        auStack_28[2] = (char)((uint)uVar1 >> 8);
        auStack_28[3] = (char)((uint)uVar1 >> 0x10);
        rsp.ieee_addr_remote_dev.field_0.u8[0] = (char)*(undefined3 *)(puVar7 + 1);
        rsp.status = (uint8_t)((uint)uVar1 >> 0x18);
        rsp.ieee_addr_remote_dev.field_0.u8[1] = (char)((uint)uVar2 >> 8);
        rsp.ieee_addr_remote_dev.field_0.u8[2] = (char)((uint)uVar2 >> 0x10);
        rsp.ieee_addr_remote_dev.field_0.u8[3] = (char)((uint)uVar2 >> 0x18);
        uVar4 = nwk_get_short_address();
        rsp.ieee_addr_remote_dev.field_0.u64._5_2_ = uVar4;
        zVar3 = zdo_op_ieee_addr_rsp
                          (resp->payload,rsp.nwk_addr_assoc_dev_list._2_1_,
                           (zdp_ieee_addr_rsp_field_t *)auStack_28,true);
      }
    }
    else {
      zVar3 = 0xfe;
    }
  }
  if (rsp._12_4_ != 0) {
    mm_free();
  }
  return zVar3;
}

