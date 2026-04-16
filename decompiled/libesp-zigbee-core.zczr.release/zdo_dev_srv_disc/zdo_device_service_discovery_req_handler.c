/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> zdo_dev_srv_disc.o -> zdo_device_service_discovery_req_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

zdp_status_t zdo_device_service_discovery_req_handler(void *arg)

{
  ushort uVar1;
  undefined4 uVar2;
  zdp_active_ep_req_field_t zVar3;
  zdp_power_desc_req_field_t val;
  zmsg_t *pzVar4;
  undefined2 *puVar5;
  uint uVar6;
  void *pvVar7;
  zdp_status_t zVar8;
  char cVar9;
  undefined2 uVar10;
  ezb_shortaddr_t val_00;
  uint uVar11;
  zdp_simple_desc_req_field_t *pzVar12;
  undefined3 extraout_var;
  int iVar13;
  undefined4 *puVar14;
  undefined3 extraout_var_00;
  void *__src;
  undefined4 uVar15;
  undefined1 *puVar16;
  undefined3 extraout_var_01;
  char *pcVar17;
  undefined3 extraout_var_02;
  ushort *puVar18;
  ezb_err_t eVar19;
  undefined3 extraout_var_03;
  uint16_t *__src_00;
  int *piVar20;
  int extraout_a0;
  int extraout_a0_00;
  int extraout_a0_01;
  uint uVar21;
  undefined1 uVar22;
  undefined1 uVar24;
  undefined1 uVar25;
  short *psVar27;
  uint uVar28;
  byte val_01;
  uint8_t uVar29;
  uint uVar30;
  uint16_t val_02;
  uint16_t val_03;
  uint16_t val_04;
  uint8_t uVar31;
  uint16_t val_05;
  uint16_t val_06;
  anon_union_8_2_c961180f_for_ezb_eui64_s_0 ieee_addr;
  zdp_active_ep_req_field_t azStack_b8 [2];
  zdp_active_ep_req_field_t req_2;
  zdp_power_desc_req_field_t req_6;
  zdp_node_desc_req_field_t req_7;
  uint8_t auStack_aa [2];
  zdp_simple_desc_req_field_t req_4;
  uint16_t offset;
  void *pvStack_a0;
  undefined4 uStack_9c;
  zdp_nwk_addr_req_field_t req;
  undefined1 auStack_88 [4];
  zdo_packet_t resp;
  zdp_nwk_addr_rsp_field_t rsp;
  undefined1 uVar23;
  undefined1 uVar26;
  
  memset(auStack_88,0,0x18);
  if (arg == (void *)0x0) {
    uVar11 = 0x80;
    goto _L0;
  }
  uVar11 = zdo_packet_response_init(auStack_88,arg,*(ushort *)((int)arg + 6) | 0x8000);
  if (uVar11 != 0) goto _L0;
  uVar1 = *(ushort *)((int)arg + 6);
  if (uVar1 == 4) {
    _req_7 = 0;
    memset(&resp.payload,0,0x18);
    pzVar4 = *(zmsg_t **)((int)arg + 0x14);
    if (pzVar4 != (zmsg_t *)0x0) {
      uStack_9c = (zdp_simple_desc_req_field_t)((uint)uStack_9c & 0xffff0000);
      pvVar7 = (void *)zmsg_get_length(pzVar4);
      af_read_le16(pzVar4,(uint16_t *)&uStack_9c,&req_7.nwk_addr_of_interest);
      af_read_le8(pzVar4,(uint16_t *)&uStack_9c,auStack_aa);
      if ((void *)((uint)uStack_9c & 0xffff) <= pvVar7) {
        uVar11 = _req_7 & 0xffff;
        if (uVar11 < 0xfff8) {
          resp.payload = (zdo_packet_payload_t *)
                         CONCAT22(req_7.nwk_addr_of_interest,(ezb_shortaddr_t)resp.payload);
          uVar6 = nwk_get_short_address();
          if (uVar11 == uVar6) {
            if (((_req_7 >> 0x10 & 0xff) - 1 & 0xff) < 0xfe) {
              __src = (void *)af_get_simple_desc();
              if (__src != (void *)0x0) {
                resp.payload = (zdo_packet_payload_t *)((uint)resp.payload & 0xffffff00);
                memcpy((void *)((int)&rsp.ieee_addr_remote_dev.field_0 + 3),__src,0x10);
                goto _L0;
              }
              uVar24 = 0x83;
            }
            else {
              uVar24 = 0x82;
            }
            resp.payload = (zdo_packet_payload_t *)CONCAT31(resp.payload._1_3_,uVar24);
            goto _L0;
          }
          iVar13 = nwk_is_device_zed();
          if (iVar13 == 0) {
            puVar5 = (undefined2 *)0x0;
            pvVar7 = (void *)0x2;
            arg = (void *)0xffffffff;
            goto _L0;
          }
        }
      }
    }
    goto _L0;
  }
  if (uVar1 < 5) {
    pzVar4 = *(zmsg_t **)((int)arg + 0x14);
    if (uVar1 == 2) {
      req_6.nwk_addr_of_interest = 0;
      uStack_9c._0_2_ = 0;
      uStack_9c._2_1_ = '\0';
      uStack_9c._3_1_ = 0;
      req.ieee_addr_of_interest.field_0.u64._0_4_ = 0;
      req.ieee_addr_of_interest.field_0.u64._4_4_ = 0;
      stack0xffffff70 = 0;
      if ((pzVar4 == (zmsg_t *)0x0) ||
         (zVar8 = zdo_op_active_ep_req(pzVar4,&req_6,false), val = req_6,
         CONCAT31(extraout_var_03,zVar8) != 0)) goto _L0;
      uVar11 = (uint)req_6.nwk_addr_of_interest;
      if (uVar11 < 0xfff8) {
        uStack_9c._2_2_ = req_6.nwk_addr_of_interest;
        uVar6 = nwk_get_short_address();
        pvVar7 = (void *)0x0;
        if (uVar11 != uVar6) {
          iVar13 = nwk_is_device_zed();
          pvVar7 = (void *)0x80;
          if (iVar13 == 0) {
            puVar5 = (undefined2 *)0x0;
            do {
              do {
                puVar5 = (undefined2 *)nwk_neighbor_table_next(puVar5);
                if (puVar5 == (undefined2 *)0x0) goto _L0;
              } while ((*(uint *)(puVar5 + 6) & 3) != 2);
              resp.payload = (zdo_packet_payload_t *)CONCAT22(resp.payload._2_2_,0xffff);
              nwk_address_short_by_ref(*puVar5,&resp.payload);
            } while (req_6.nwk_addr_of_interest != (ezb_shortaddr_t)resp.payload);
_L0:
            pvVar7 = (void *)0x81;
          }
        }
        uStack_9c._0_1_ = (uint8_t)pvVar7;
        req.ieee_addr_of_interest.field_0.u64._0_4_ = 0;
        req.ieee_addr_of_interest.field_0.u64._4_4_ = 0;
        stack0xffffff70 = 0;
        if ((pvVar7 == (void *)0x0) &&
           (__src_00 = (uint16_t *)af_get_node_desc(), __src_00 != (uint16_t *)0x0)) {
          memcpy(&req,__src_00,0x10);
          val_06 = *__src_00;
          arg = (void *)(uint)(byte)__src_00[1];
          val_05 = __src_00[2];
          uVar31 = (uint8_t)__src_00[3];
          val_04 = __src_00[4];
          val_03 = __src_00[5];
          val_02 = __src_00[6];
          uVar29 = (uint8_t)__src_00[7];
        }
        else {
          uVar29 = '\0';
          uVar31 = '\0';
          val_02 = 0;
          val_03 = 0;
          val_04 = 0;
          val_05 = 0;
          val_06 = 0;
          arg = (void *)0x0;
        }
        puVar5 = (undefined2 *)resp.ctx.req_ctx.arg;
        if (resp.ctx.req_ctx.arg != (zdo_packet_user_ctx_t)0x0) {
          eVar19 = zmsg_append_u8((zmsg_t *)resp.ctx.req_ctx.arg,(uint8_t)pvVar7);
          if ((eVar19 == 0) &&
             (eVar19 = zmsg_append_le16((zmsg_t *)resp.ctx.req_ctx.arg,val.nwk_addr_of_interest),
             eVar19 == 0)) {
            if (pvVar7 == (void *)0x0) {
              eVar19 = zmsg_append_le16((zmsg_t *)resp.ctx.req_ctx.arg,val_06);
              if (((((eVar19 != 0) ||
                    (eVar19 = zmsg_append_u8((zmsg_t *)resp.ctx.req_ctx.arg,(uint8_t)arg),
                    eVar19 != 0)) ||
                   (eVar19 = zmsg_append_le16((zmsg_t *)resp.ctx.req_ctx.arg,val_05), eVar19 != 0))
                  || ((eVar19 = zmsg_append_u8((zmsg_t *)resp.ctx.req_ctx.arg,uVar31), eVar19 != 0
                      || (eVar19 = zmsg_append_le16((zmsg_t *)resp.ctx.req_ctx.arg,val_04),
                         eVar19 != 0)))) ||
                 ((eVar19 = zmsg_append_le16((zmsg_t *)resp.ctx.req_ctx.arg,val_03), eVar19 != 0 ||
                  (eVar19 = zmsg_append_le16((zmsg_t *)resp.ctx.req_ctx.arg,val_02), eVar19 != 0))))
              goto _L0;
              iVar13 = zmsg_append_u8((zmsg_t *)resp.ctx.req_ctx.arg,uVar29);
              goto _L0;
            }
            goto _L0;
          }
          goto _L0;
        }
        goto _L0;
      }
_L0:
      uVar11 = 0x8b;
      goto _L0;
    }
    if (uVar1 != 3) {
      if (uVar1 == 0) {
        uStack_9c._0_2_ = 0;
        uStack_9c._2_1_ = '\0';
        uStack_9c._3_1_ = 0;
        req.ieee_addr_of_interest.field_0.u64._0_4_ = 0;
        req.ieee_addr_of_interest.field_0.u64._4_4_ =
             req.ieee_addr_of_interest.field_0.u64._4_4_ & 0xffff0000;
        resp.payload = (zdo_packet_payload_t *)0x0;
        rsp._0_4_ = 0;
        rsp.ieee_addr_remote_dev.field_0.u64._3_4_ = 0;
        rsp._8_4_ = 0;
        rsp.num_assoc_dev = '\0';
        rsp.start_index = '\0';
        rsp._14_2_ = 0;
        if (pzVar4 != (zmsg_t *)0x0) {
          req_4 = (zdp_simple_desc_req_field_t)((uint)(ushort)req_4._2_2_ << 0x10);
          uVar11 = zmsg_get_length(pzVar4);
          af_read_bytes(pzVar4,&req_4.nwk_addr_of_interest,8,(uint8_t *)&uStack_9c);
          af_read_le8(pzVar4,&req_4.nwk_addr_of_interest,req.ieee_addr_of_interest.field_0.u8 + 4);
          af_read_le8(pzVar4,&req_4.nwk_addr_of_interest,req.ieee_addr_of_interest.field_0.u8 + 5);
          if (((uint)req_4 & 0xffff) <= uVar11) {
            resp.payload._0_2_ = CONCAT11(uStack_9c.nwk_addr_of_interest,(uint8_t)resp.payload);
            resp.payload._0_3_ = CONCAT12(uStack_9c._1_1_,(ezb_shortaddr_t)resp.payload);
            rsp.ieee_addr_remote_dev.field_0.u8[0] =
                 (char)req.ieee_addr_of_interest.field_0.u64._0_4_;
            rsp.status = uStack_9c._3_1_;
            rsp.ieee_addr_remote_dev.field_0.u8[1] =
                 (char)((uint)req.ieee_addr_of_interest.field_0._0_4_ >> 8);
            rsp.ieee_addr_remote_dev.field_0.u8[3] =
                 (char)((uint)req.ieee_addr_of_interest.field_0._0_4_ >> 0x18);
            resp.payload = (zdo_packet_payload_t *)CONCAT13(uStack_9c.endpoint,resp.payload._0_3_);
            rsp.ieee_addr_remote_dev.field_0.u8[2] =
                 (char)((uint)req.ieee_addr_of_interest.field_0._0_4_ >> 0x10);
            rsp.ieee_addr_remote_dev.field_0.u64._5_2_ = 0xffff;
            pzVar12 = (zdp_simple_desc_req_field_t *)nwk_get_extended_address();
            if ((*pzVar12 == uStack_9c) &&
               (pzVar12[1] ==
                (zdp_simple_desc_req_field_t)req.ieee_addr_of_interest.field_0.u64._0_4_)) {
              nwk_address_short_by_extended
                        (&uStack_9c,(undefined1 *)((int)&rsp.ieee_addr_remote_dev.field_0 + 5));
            }
            else {
              puVar5 = (undefined2 *)nwk_neighbor_table_get_by_extended(&uStack_9c);
              if ((puVar5 != (undefined2 *)0x0) && ((*(uint *)(puVar5 + 6) & 3) == 2)) {
                nwk_address_short_by_ref
                          (*puVar5,(undefined1 *)((int)&rsp.ieee_addr_remote_dev.field_0 + 5));
              }
            }
            uVar24 = uStack_9c._1_1_;
            uVar31 = uStack_9c.endpoint;
            uVar29 = uStack_9c._3_1_;
            uVar25 = (undefined1)req.ieee_addr_of_interest.field_0.u64._0_4_;
            uVar22 = (undefined1)((uint)req.ieee_addr_of_interest.field_0._0_4_ >> 8);
            uVar23 = (undefined1)((uint)req.ieee_addr_of_interest.field_0._0_4_ >> 0x10);
            uVar26 = (undefined1)((uint)req.ieee_addr_of_interest.field_0._0_4_ >> 0x18);
            if ((uint)rsp.ieee_addr_remote_dev.field_0.u64._3_4_ >> 0x10 != 0xffff) {
              if ((req.ieee_addr_of_interest.field_0.u64._4_4_ & 0xff) == 0) {
                resp.payload = (zdo_packet_payload_t *)(((uint)uStack_9c & 0xff) << 8);
                resp.payload._0_3_ = CONCAT12(uVar24,(ezb_shortaddr_t)resp.payload);
                rsp.ieee_addr_remote_dev.field_0.u8[0] = uVar25;
                rsp.status = uVar29;
                rsp.ieee_addr_remote_dev.field_0.u8[1] = uVar22;
                resp.payload = (zdo_packet_payload_t *)CONCAT13(uVar31,resp.payload._0_3_);
                rsp.ieee_addr_remote_dev.field_0.u8[2] = uVar23;
                rsp.ieee_addr_remote_dev.field_0.u8[3] = uVar26;
                nwk_address_short_by_extended
                          ((undefined1 *)((int)&resp.payload + 1),
                           (undefined1 *)((int)&rsp.ieee_addr_remote_dev.field_0 + 5));
_L0:
              }
              else {
                if ((req.ieee_addr_of_interest.field_0.u64._4_4_ & 0xff) == 1) {
                  iVar13 = nwk_is_device_zczr();
                  if (iVar13 != 0) {
                    resp.payload = (zdo_packet_payload_t *)((uint)resp.payload & 0xffffff00);
                    puVar14 = (undefined4 *)nwk_get_extended_address();
                    uVar15 = *puVar14;
                    uVar2 = puVar14[1];
                    resp.payload._0_2_ =
                         CONCAT11((char)*(undefined3 *)puVar14,(uint8_t)resp.payload);
                    resp.payload._0_3_ =
                         CONCAT12((char)((uint)uVar15 >> 8),(ezb_shortaddr_t)resp.payload);
                    resp.payload = (zdo_packet_payload_t *)
                                   CONCAT13((char)((uint)uVar15 >> 0x10),resp.payload._0_3_);
                    rsp.ieee_addr_remote_dev.field_0.u8[0] = (char)*(undefined3 *)(puVar14 + 1);
                    rsp.status = (uint8_t)((uint)uVar15 >> 0x18);
                    rsp.ieee_addr_remote_dev.field_0.u8[1] = (char)((uint)uVar2 >> 8);
                    rsp.ieee_addr_remote_dev.field_0.u8[2] = (char)((uint)uVar2 >> 0x10);
                    rsp.ieee_addr_remote_dev.field_0.u8[3] = (char)((uint)uVar2 >> 0x18);
                    uVar10 = nwk_get_short_address();
                    rsp.ieee_addr_remote_dev.field_0.u64._5_2_ = uVar10;
                    uVar11 = nwk_neighbor_table_get_ed_num();
                    uVar11 = uVar11 & 0xff;
                    if (uVar11 != 0) {
                      rsp._12_4_ = calloc(uVar11,2);
                    }
                    puVar5 = (undefined2 *)0x0;
                    rsp._8_4_ = (uint)CONCAT21(rsp.nwk_addr_remote_dev,
                                               req.ieee_addr_of_interest.field_0.u8[5]) << 8;
                    uVar6 = 0;
                    while ((puVar5 = (undefined2 *)nwk_neighbor_table_next(puVar5),
                           puVar5 != (undefined2 *)0x0 && ((rsp._8_4_ & 0xff) < uVar11))) {
                      if ((((uint)rsp._8_4_ >> 8 & 0xff) <= uVar6) &&
                         ((*(uint *)(puVar5 + 6) & 3) == 2)) {
                        nwk_address_short_by_ref(*puVar5,(rsp._8_4_ & 0xff) * 2 + rsp._12_4_);
                        rsp.ieee_addr_remote_dev.field_0.u8[7] = (char)rsp._8_4_ + '\x01';
                      }
                      uVar6 = uVar6 + 1 & 0xff;
                    }
                  }
                  goto _L0;
                }
                if (0xfff7 < *(ushort *)((int)arg + 2)) goto _L0;
                resp.payload._0_2_ = CONCAT11(uStack_9c.nwk_addr_of_interest,0x80);
                resp.payload._0_3_ = CONCAT12(uVar24,(ezb_shortaddr_t)resp.payload);
                rsp.ieee_addr_remote_dev.field_0.u8[0] = uVar25;
                rsp.status = uVar29;
                rsp.ieee_addr_remote_dev.field_0.u8[1] = uVar22;
                rsp.ieee_addr_remote_dev.field_0.u8[3] = uVar26;
                resp.payload = (zdo_packet_payload_t *)CONCAT13(uVar31,resp.payload._0_3_);
                rsp.ieee_addr_remote_dev.field_0.u8[2] = uVar23;
                rsp.ieee_addr_remote_dev.field_0.u64._5_2_ = 0xffff;
              }
              zVar8 = zdo_op_nwk_addr_rsp((zdo_packet_payload_t *)resp.ctx.req_ctx.arg,
                                          req.ieee_addr_of_interest.field_0.u8[4],
                                          (zdp_nwk_addr_rsp_field_t *)&resp.payload,true);
              uVar11 = CONCAT31(extraout_var,zVar8);
              goto _L0;
            }
            if (*(ushort *)((int)arg + 2) < 0xfff8) {
              resp.payload._0_2_ = CONCAT11(uStack_9c.nwk_addr_of_interest,0x81);
              resp.payload._0_3_ = CONCAT12(uVar24,(ezb_shortaddr_t)resp.payload);
              rsp.ieee_addr_remote_dev.field_0.u8[0] = uVar25;
              rsp.status = uVar29;
              rsp.ieee_addr_remote_dev.field_0.u8[1] = uVar22;
              rsp.ieee_addr_remote_dev.field_0.u8[3] = uVar26;
              resp.payload = (zdo_packet_payload_t *)CONCAT13(uVar31,resp.payload._0_3_);
              rsp.ieee_addr_remote_dev.field_0.u8[2] = uVar23;
              rsp.ieee_addr_remote_dev.field_0.u64._5_2_ = 0xffff;
              goto _L0;
            }
          }
        }
_L0:
        uVar11 = 0xfe;
      }
      else {
        uStack_9c._0_2_ = 0;
        uStack_9c._2_1_ = '\0';
        uStack_9c._3_1_ = 0;
        resp.payload = (zdo_packet_payload_t *)0x0;
        rsp._0_4_ = 0;
        rsp.ieee_addr_remote_dev.field_0.u64._3_4_ = 0;
        rsp._8_4_ = 0;
        rsp.num_assoc_dev = '\0';
        rsp.start_index = '\0';
        rsp._14_2_ = 0;
        if (pzVar4 == (zmsg_t *)0x0) goto _L0;
        req_4 = (zdp_simple_desc_req_field_t)((uint)(ushort)req_4._2_2_ << 0x10);
        uVar11 = zmsg_get_length(pzVar4);
        af_read_le16(pzVar4,&req_4.nwk_addr_of_interest,(uint16_t *)&uStack_9c);
        af_read_le8(pzVar4,&req_4.nwk_addr_of_interest,(uint8_t *)((int)&uStack_9c + 2));
        af_read_le8(pzVar4,&req_4.nwk_addr_of_interest,(uint8_t *)((int)&uStack_9c + 3));
        if (uVar11 < ((uint)req_4 & 0xffff)) goto _L0;
        uVar11 = (uint)uStack_9c & 0xffff;
        resp.payload._0_2_ = CONCAT11(0xff,(uint8_t)resp.payload);
        resp.payload._0_3_ = CONCAT12(0xff,(ezb_shortaddr_t)resp.payload);
        resp.payload = (zdo_packet_payload_t *)CONCAT13(0xff,resp.payload._0_3_);
        rsp._0_4_ = 0xffffffff;
        rsp.ieee_addr_remote_dev.field_0.u8[3] = 0xff;
        uVar6 = nwk_get_short_address();
        if (uVar11 == uVar6) {
          nwk_address_extended_by_short((undefined1 *)((int)&resp.payload + 1));
        }
        else {
          puVar5 = (undefined2 *)nwk_neighbor_table_get_by_short((uint)uStack_9c & 0xffff);
          if ((puVar5 != (undefined2 *)0x0) && ((*(uint *)(puVar5 + 6) & 3) == 2)) {
            nwk_address_extended_by_ref(*puVar5,(undefined1 *)((int)&resp.payload + 1));
          }
        }
        if (((rsp._0_4_ << 0x18 | (uint)resp.payload >> 8) == 0xffffffff) &&
           ((rsp.ieee_addr_remote_dev.field_0.u64._3_4_ << 0x18 | (uint)rsp._0_4_ >> 8) ==
            0xffffffff)) {
          resp.payload = (zdo_packet_payload_t *)CONCAT31(resp.payload._1_3_,0x81);
          rsp.ieee_addr_remote_dev.field_0.u64._5_2_ = (ezb_shortaddr_t)uStack_9c;
        }
        else {
          if (uStack_9c._2_1_ == '\0') {
            resp.payload = (zdo_packet_payload_t *)((uint)resp.payload._1_3_ << 8);
            rsp.ieee_addr_remote_dev.field_0.u64._5_2_ = (ezb_shortaddr_t)uStack_9c;
            nwk_address_extended_by_short((undefined1 *)((int)&resp.payload + 1));
          }
          else if (uStack_9c._2_1_ == '\x01') {
            iVar13 = nwk_is_device_zczr();
            if (iVar13 != 0) {
              resp.payload = (zdo_packet_payload_t *)((uint)resp.payload & 0xffffff00);
              puVar14 = (undefined4 *)nwk_get_extended_address();
              uVar15 = *puVar14;
              uVar2 = puVar14[1];
              resp.payload._0_2_ = CONCAT11((char)*(undefined3 *)puVar14,(uint8_t)resp.payload);
              resp.payload._0_3_ = CONCAT12((char)((uint)uVar15 >> 8),(ezb_shortaddr_t)resp.payload)
              ;
              resp.payload = (zdo_packet_payload_t *)
                             CONCAT13((char)((uint)uVar15 >> 0x10),resp.payload._0_3_);
              rsp.ieee_addr_remote_dev.field_0.u8[0] = (char)*(undefined3 *)(puVar14 + 1);
              rsp.status = (uint8_t)((uint)uVar15 >> 0x18);
              rsp.ieee_addr_remote_dev.field_0.u8[1] = (char)((uint)uVar2 >> 8);
              rsp.ieee_addr_remote_dev.field_0.u8[2] = (char)((uint)uVar2 >> 0x10);
              rsp.ieee_addr_remote_dev.field_0.u8[3] = (char)((uint)uVar2 >> 0x18);
              uVar10 = nwk_get_short_address();
              rsp.ieee_addr_remote_dev.field_0.u64._5_2_ = uVar10;
              uVar11 = nwk_neighbor_table_get_ed_num();
              if ((uVar11 & 0xff) != 0) {
                rsp._12_4_ = calloc(uVar11 & 0xff,2);
              }
              puVar5 = (undefined2 *)0x0;
              rsp._8_4_ = (uint)CONCAT21(rsp.nwk_addr_remote_dev,uStack_9c._3_1_) << 8;
              uVar11 = 0;
              while (puVar5 = (undefined2 *)nwk_neighbor_table_next(puVar5),
                    puVar5 != (undefined2 *)0x0) {
                uVar6 = (uint)rsp._8_4_ >> 8 & 0xff;
                if ((uVar6 <= uVar11) && ((*(uint *)(puVar5 + 6) & 3) == 2)) {
                  nwk_address_short_by_ref(*puVar5,(uVar11 - uVar6) * 2 + rsp._12_4_);
                  rsp.ieee_addr_remote_dev.field_0.u8[7] =
                       rsp.ieee_addr_remote_dev.field_0.u8[7] + '\x01';
                }
                uVar11 = uVar11 + 1 & 0xff;
              }
            }
          }
          else {
            resp.payload = (zdo_packet_payload_t *)CONCAT31(resp.payload._1_3_,0x80);
            puVar14 = (undefined4 *)nwk_get_extended_address();
            uVar15 = *puVar14;
            uVar2 = puVar14[1];
            resp.payload._0_2_ = CONCAT11((char)*(undefined3 *)puVar14,(uint8_t)resp.payload);
            resp.payload._0_3_ = CONCAT12((char)((uint)uVar15 >> 8),(ezb_shortaddr_t)resp.payload);
            resp.payload = (zdo_packet_payload_t *)
                           CONCAT13((char)((uint)uVar15 >> 0x10),resp.payload._0_3_);
            rsp.ieee_addr_remote_dev.field_0.u8[0] = (char)*(undefined3 *)(puVar14 + 1);
            rsp.status = (uint8_t)((uint)uVar15 >> 0x18);
            rsp.ieee_addr_remote_dev.field_0.u8[1] = (char)((uint)uVar2 >> 8);
            rsp.ieee_addr_remote_dev.field_0.u8[2] = (char)((uint)uVar2 >> 0x10);
            rsp.ieee_addr_remote_dev.field_0.u8[3] = (char)((uint)uVar2 >> 0x18);
            uVar10 = nwk_get_short_address();
            rsp.ieee_addr_remote_dev.field_0.u64._5_2_ = uVar10;
          }
        }
        zVar8 = zdo_op_ieee_addr_rsp
                          ((zdo_packet_payload_t *)resp.ctx.req_ctx.arg,uStack_9c._2_1_,
                           (zdp_ieee_addr_rsp_field_t *)&resp.payload,true);
        uVar11 = CONCAT31(extraout_var_00,zVar8);
      }
_L0:
      pvVar7 = (void *)rsp._12_4_;
      if (rsp._12_4_ != 0) {
_L0:
        mm_free(pvVar7);
      }
      goto _L0;
    }
    req_2.nwk_addr_of_interest = 0;
    if ((pzVar4 == (zmsg_t *)0x0) ||
       (zVar8 = zdo_op_active_ep_req(pzVar4,&req_2,false), zVar3 = req_2,
       CONCAT31(extraout_var_02,zVar8) != 0)) goto _L0;
    uVar11 = (uint)req_2.nwk_addr_of_interest;
    if (0xfff7 < uVar11) goto _L0;
    uVar6 = nwk_get_short_address();
    if (uVar11 == uVar6) {
      puVar18 = (ushort *)af_get_node_power_desc();
      puVar5 = (undefined2 *)0x0;
      if (puVar18 == (ushort *)0x0) goto _L0;
      pvVar7 = (void *)(uint)*puVar18;
    }
    else {
      iVar13 = nwk_is_device_zed();
      puVar5 = (undefined2 *)0x80;
      if (iVar13 == 0) {
        puVar5 = (undefined2 *)0x0;
        do {
          do {
            puVar5 = (undefined2 *)nwk_neighbor_table_next(puVar5);
            if (puVar5 == (undefined2 *)0x0) goto _L529;
          } while ((*(uint *)(puVar5 + 6) & 3) != 2);
          resp.payload = (zdo_packet_payload_t *)CONCAT22(resp.payload._2_2_,0xffff);
          nwk_address_short_by_ref(*puVar5,&resp.payload);
        } while (req_2.nwk_addr_of_interest != (ezb_shortaddr_t)resp.payload);
_L529:
        puVar5 = (undefined2 *)0x81;
      }
_L0:
      pvVar7 = (void *)0x0;
    }
    arg = resp.ctx.req_ctx.arg;
    if (resp.ctx.req_ctx.arg == (zdo_packet_user_ctx_t)0x0) {
_L0:
      do {
        __assert_func(0,0,0,0);
        do {
          resp.payload = (zdo_packet_payload_t *)CONCAT22((short)arg,(ezb_shortaddr_t)resp.payload);
_L0:
          do {
            puVar5 = (undefined2 *)nwk_neighbor_table_next(puVar5);
            if (puVar5 == (undefined2 *)0x0) goto _L0;
          } while ((void *)(*(uint *)(puVar5 + 6) & 3) != pvVar7);
          nwk_address_short_by_ref(*puVar5,(undefined1 *)((int)&resp.payload + 2));
        } while (resp.payload._2_2_ != req_7.nwk_addr_of_interest);
_L0:
        uVar24 = 0x89;
        if (resp.payload._2_2_ == -1) {
          uVar24 = 0x81;
        }
        resp.payload = (zdo_packet_payload_t *)CONCAT31(resp.payload._1_3_,uVar24);
_L0:
        puVar5 = (undefined2 *)resp.ctx.req_ctx.arg;
      } while (resp.ctx.req_ctx.arg == (zdo_packet_user_ctx_t)0x0);
      eVar19 = zmsg_append_u8((zmsg_t *)resp.ctx.req_ctx.arg,(uint8_t)resp.payload);
      if (eVar19 == 0) {
        eVar19 = zmsg_append_le16((zmsg_t *)resp.ctx.req_ctx.arg,resp.payload._2_2_);
        if (eVar19 == 0) {
          uVar15 = zmsg_get_length(resp.ctx.req_ctx.arg);
          eVar19 = zmsg_append_u8((zmsg_t *)resp.ctx.req_ctx.arg,rsp.status);
          if (eVar19 == 0) {
            if (((uint)resp.payload & 0xff) != 0) goto _L0;
            rsp.status = rsp.status + '\b';
            eVar19 = zmsg_append_u8((zmsg_t *)resp.ctx.req_ctx.arg,
                                    rsp.ieee_addr_remote_dev.field_0.u8[3]);
            if (eVar19 == 0) {
              eVar19 = zmsg_append_le16((zmsg_t *)resp.ctx.req_ctx.arg,
                                        rsp.ieee_addr_remote_dev.field_0.u64._5_2_);
              if (eVar19 == 0) {
                eVar19 = zmsg_append_le16((zmsg_t *)resp.ctx.req_ctx.arg,rsp._8_2_);
                if ((eVar19 == 0) &&
                   (eVar19 = zmsg_append_u8((zmsg_t *)resp.ctx.req_ctx.arg,
                                            (byte)((uint)rsp._8_4_ >> 0xc) & 0xf0 |
                                            (byte)((uint)rsp._8_4_ >> 0x14) & 0xf), eVar19 == 0)) {
                  eVar19 = zmsg_append_u8((zmsg_t *)resp.ctx.req_ctx.arg,
                                          rsp.nwk_addr_remote_dev._1_1_);
                  uVar11 = 0;
                  if (eVar19 == 0) {
                    for (; uVar11 < (uint)rsp._8_4_ >> 0x18; uVar11 = uVar11 + 1 & 0xff) {
                      eVar19 = zmsg_append_le16((zmsg_t *)resp.ctx.req_ctx.arg,
                                                rsp.nwk_addr_assoc_dev_list[uVar11]);
                      if (eVar19 != 0) goto _L0;
                      rsp.status = rsp.status + '\x02';
                    }
                    eVar19 = zmsg_append_u8((zmsg_t *)resp.ctx.req_ctx.arg,rsp.num_assoc_dev);
                    if (eVar19 == 0) {
                      for (uVar11 = (uint)rsp._8_4_ >> 0x18; uVar11 = uVar11 & 0xff,
                          uVar11 < ((uint)rsp._8_4_ >> 0x18) + (rsp._12_4_ & 0xff);
                          uVar11 = uVar11 + 1) {
                        eVar19 = zmsg_append_le16((zmsg_t *)resp.ctx.req_ctx.arg,
                                                  rsp.nwk_addr_assoc_dev_list[uVar11]);
                        if (eVar19 != 0) goto _L0;
                        rsp.status = rsp.status + '\x02';
                      }
                      pzVar12 = (zdp_simple_desc_req_field_t *)&uStack_9c;
                      uStack_9c._0_1_ = rsp.status;
                      goto _L526;
                    }
                  }
                }
              }
            }
          }
        }
      }
      goto _L0;
    }
    eVar19 = zmsg_append_u8((zmsg_t *)resp.ctx.req_ctx.arg,(uint8_t)puVar5);
    if ((eVar19 != 0) ||
       (eVar19 = zmsg_append_le16((zmsg_t *)resp.ctx.req_ctx.arg,zVar3.nwk_addr_of_interest),
       eVar19 != 0)) {
_L0:
      uVar11 = 0x8a;
      goto _L0;
    }
    if (puVar5 == (undefined2 *)0x0) {
      iVar13 = zmsg_append_le16((zmsg_t *)resp.ctx.req_ctx.arg,(uint16_t)pvVar7);
_L0:
      if (iVar13 != 0) goto _L0;
    }
  }
  else {
    if (uVar1 == 0x13) {
      req_6.nwk_addr_of_interest = 0;
      resp.payload = (zdo_packet_payload_t *)0x0;
      rsp._0_4_ = 0;
      rsp.ieee_addr_remote_dev.field_0.u64._3_4_ = 0;
      if (*(int *)((int)arg + 0x14) != 0) {
        uVar11 = zmsg_get_length();
        af_read_le16(*(zmsg_t **)((int)arg + 0x14),&req_6.nwk_addr_of_interest,
                     (uint16_t *)(rsp.ieee_addr_remote_dev.field_0.u8 + 3));
        af_read_bytes(*(zmsg_t **)((int)arg + 0x14),&req_6.nwk_addr_of_interest,8,
                      (uint8_t *)&resp.payload);
        af_read_le8(*(zmsg_t **)((int)arg + 0x14),&req_6.nwk_addr_of_interest,
                    rsp.ieee_addr_remote_dev.field_0.u8 + 5);
        if (req_6.nwk_addr_of_interest <= uVar11) {
          piVar20 = (int *)nwk_get_extended_address();
          if ((resp.payload != (zdo_packet_payload_t *)*piVar20) || (rsp._0_4_ != piVar20[1])) {
            iVar13 = nwk_is_device_zczr();
            if (iVar13 == 0) {
_L0:
              req_4 = (zdp_simple_desc_req_field_t)((uint)req_4 & 0xffff0000);
              ieee_addr.u64 =
                   nwk_address_update(&resp.payload,
                                      rsp.ieee_addr_remote_dev.field_0.u64._3_4_ & 0xffff,&req_4);
              if ((rsp._0_4_ + 1 != (uint)(resp.payload == (zdo_packet_payload_t *)0x0)) ||
                 ((undefined1 *)((int)&resp.payload[-1].timestamp.val + 3U) <
                  (undefined1 *)0xfffffffe)) {
                _req_7 = _req_7 & 0xffff0000;
                ieee_addr.u64 =
                     nwk_address_ref_by_short
                               (rsp.ieee_addr_remote_dev.field_0.u64._3_4_ & 0xffff,&req_7);
                if (extraout_a0 == 0) {
                  uStack_9c._0_2_ = 0;
                  uStack_9c._2_1_ = '\0';
                  uStack_9c._3_1_ = 0;
                  req.ieee_addr_of_interest.field_0.u64._0_4_ = 0;
                  ieee_addr.u64 = nwk_address_extended_by_ref(_req_7 & 0xffff,&uStack_9c);
                  if (((extraout_a0_00 == 0) &&
                      (((zdp_simple_desc_req_field_t)resp.payload != uStack_9c ||
                       (rsp._0_4_ != req.ieee_addr_of_interest.field_0.u64._0_4_)))) &&
                     ((req.ieee_addr_of_interest.field_0.u64._0_4_ + 1 !=
                       (uint)(uStack_9c == (zdp_simple_desc_req_field_t)0x0) ||
                      ((undefined1 *)((int)uStack_9c - 1U) < (undefined1 *)0xfffffffe)))) {
                    ieee_addr.u64 = core_globals_get();
                    if ((_req_7 & 0xffff) < (uint)*(ushort *)(extraout_a0_01 + 0xcb8)) {
                      *(undefined2 *)
                       ((_req_7 & 0xffff) * 0x10 + *(int *)(extraout_a0_01 + 0xcb4) + 6) = 0xffff;
                    }
                  }
                }
              }
              zdo_device_annce_indication
                        ((ezb_extaddr_t)ieee_addr,(uint16_t)resp.payload,(uint8_t)rsp._0_4_);
            }
            else {
              _req_7 = CONCAT22(auStack_aa,0xffff);
              iVar13 = nwk_address_ref_by_extended(&resp.payload,&req_4);
              if ((((iVar13 != 0) ||
                   (iVar13 = nwk_address_short_by_ref((uint)req_4 & 0xffff,&req_7), iVar13 != 0)) ||
                  ((_req_7 & 0xffff) == 0xffff)) ||
                 ((rsp.ieee_addr_remote_dev.field_0.u64._3_4_ & 0xffff) == (_req_7 & 0xffff))) {
                iVar13 = 0;
                do {
                  iVar13 = nwk_neighbor_table_next(iVar13);
                  if (iVar13 == 0) goto _L0;
                  nwk_neighbor_get_extaddr(&uStack_9c);
                } while ((((zdp_simple_desc_req_field_t)resp.payload != uStack_9c) ||
                         (rsp._0_4_ != req.ieee_addr_of_interest.field_0.u64._0_4_)) ||
                        (uVar11 = nwk_neighbor_get_shortaddr(iVar13),
                        (rsp.ieee_addr_remote_dev.field_0.u64._3_4_ & 0xffff) == uVar11));
                if ((*(uint *)(iVar13 + 0xc) & 0x3c0) == 0x180) {
                  *(uint *)(iVar13 + 0xc) = *(uint *)(iVar13 + 0xc) & 0xfffffc3f | 0x1c0;
                }
              }
            }
          }
        }
      }
      goto _L0;
    }
    if (0x13 < uVar1) {
      if (uVar1 != 0x1f) {
_L527:
        uVar11 = 0x84;
        goto _L0;
      }
      uStack_9c = (zdp_simple_desc_req_field_t)((uint)uStack_9c & 0xffff0000);
      resp.payload = (zdo_packet_payload_t *)0x0;
      rsp._0_4_ = 0;
      rsp.ieee_addr_remote_dev.field_0.u64._3_4_ =
           rsp.ieee_addr_remote_dev.field_0.u64._3_4_ & 0xffffff00;
      if ((*(int *)((int)arg + 0x14) != 0) && (iVar13 = nwk_is_device_zed(), iVar13 == 0)) {
        uVar11 = zmsg_get_length(*(undefined4 *)((int)arg + 0x14));
        af_read_le8(*(zmsg_t **)((int)arg + 0x14),(uint16_t *)&uStack_9c,(uint8_t *)&resp.payload);
        if (((uint)uStack_9c & 0xffff) <= uVar11) {
          if ((0xfff7 < *(ushort *)((int)arg + 2)) &&
             (iVar13 = core_globals_get(), *(char *)(iVar13 + 0x16) != '\0')) {
            uVar11 = random_noncrypto_range_u32(0,0x2711);
            iVar13 = core_globals_get();
            *(char *)(iVar13 + 0x16) = (char)(uVar11 / 1000) + '\n';
          }
          zmsg_append_u8((zmsg_t *)resp.ctx.req_ctx.arg,'\0');
          cVar9 = '\0';
          for (uVar6 = 0; uVar6 < ((uint)resp.payload & 0xff); uVar6 = uVar6 + 1 & 0xff) {
            af_read_bytes(*(zmsg_t **)((int)arg + 0x14),(uint16_t *)&uStack_9c,8,
                          (uint8_t *)((int)&resp.payload + 1));
            iVar13 = nwk_neighbor_table_get_by_extended((undefined1 *)((int)&resp.payload + 1));
            if (((iVar13 != 0) && ((*(uint *)(iVar13 + 0xc) & 3) == 2)) &&
               (*(int *)(iVar13 + 0x18) << 7 < 0)) {
              uVar11 = zmsg_append_bytes(resp.ctx.req_ctx.arg,8,
                                         (undefined1 *)((int)&resp.payload + 1));
              uVar11 = uVar11 & 0xff;
              if (uVar11 != 0) goto _L0;
              cVar9 = cVar9 + '\x01';
            }
          }
          if (cVar9 != '\0') {
            req_4.nwk_addr_of_interest._0_1_ = cVar9;
            pzVar12 = &req_4;
            uVar15 = 0;
_L526:
            zmsg_write_bytes(resp.ctx.req_ctx.arg,uVar15,1,pzVar12);
            goto _L0;
          }
        }
      }
_L0:
      uVar11 = 0xfe;
      goto _L0;
    }
    if (uVar1 == 5) {
      azStack_b8[0].nwk_addr_of_interest = 0;
      if ((*(zdo_packet_payload_t **)((int)arg + 0x14) == (zdo_packet_payload_t *)0x0) ||
         (zVar8 = zdo_op_active_ep_req(*(zdo_packet_payload_t **)((int)arg + 0x14),azStack_b8,false)
         , zVar3.nwk_addr_of_interest = azStack_b8[0].nwk_addr_of_interest,
         CONCAT31(extraout_var_01,zVar8) != 0)) goto _L0;
      uVar11 = (uint)azStack_b8[0].nwk_addr_of_interest;
      if (0xfff7 < uVar11) goto _L0;
      uVar6 = nwk_get_short_address();
      if (uVar11 == uVar6) {
        arg = (void *)0x0;
        pcVar17 = (char *)0x0;
        while (pcVar17 = (char *)af_device_get_next_endpoint_desc(pcVar17), pcVar17 != (char *)0x0)
        {
          if (*pcVar17 != '\0') {
            arg = (void *)((int)arg + 1U & 0xff);
          }
        }
        pvVar7 = (void *)0x0;
        if (arg != (void *)0x0) {
          pvVar7 = calloc((size_t)arg,1);
          uVar11 = 0;
          pcVar17 = (char *)0x0;
          if (pvVar7 == (void *)0x0) goto _L0;
          while (pcVar17 = (char *)af_device_get_next_endpoint_desc(pcVar17), pcVar17 != (char *)0x0
                ) {
            if (*pcVar17 != '\0') {
              *(char *)(uVar11 + (int)pvVar7) = *pcVar17;
              uVar11 = uVar11 + 1 & 0xff;
            }
          }
        }
        uVar31 = '\0';
      }
      else {
        cVar9 = nwk_is_device_zed();
        uVar31 = 0x81 - cVar9;
        arg = (void *)0x0;
        pvVar7 = (void *)0x0;
      }
      puVar5 = (undefined2 *)0x0;
      if (resp.ctx.req_ctx.arg == (zdo_packet_user_ctx_t)0x0) goto _L0;
      eVar19 = zmsg_append_u8((zmsg_t *)resp.ctx.req_ctx.arg,uVar31);
      if (((eVar19 == 0) &&
          (eVar19 = zmsg_append_le16((zmsg_t *)resp.ctx.req_ctx.arg,zVar3.nwk_addr_of_interest),
          eVar19 == 0)) &&
         (eVar19 = zmsg_append_u8((zmsg_t *)resp.ctx.req_ctx.arg,(uint8_t)arg), eVar19 == 0)) {
        uVar11 = 0;
        if ((uVar31 == '\0') && (uVar6 = 0, arg != (void *)0x0)) {
          do {
            eVar19 = zmsg_append_u8((zmsg_t *)resp.ctx.req_ctx.arg,*(uint8_t *)((int)pvVar7 + uVar6)
                                   );
            if (eVar19 != 0) goto _L0;
            uVar6 = uVar6 + 1;
          } while ((void *)(uVar6 & 0xff) < arg);
        }
      }
      else {
_L0:
        uVar11 = 0x8a;
      }
      if (pvVar7 == (void *)0x0) goto _L0;
      goto _L0;
    }
    if (uVar1 != 6) goto _L527;
    pzVar4 = *(zmsg_t **)((int)arg + 0x14);
    req_4.nwk_addr_of_interest = 0;
    req_4.endpoint = '\0';
    req_4._3_1_ = 0;
    _offset = 0;
    pvStack_a0 = (void *)0x0;
    if (pzVar4 == (zmsg_t *)0x0) {
_L0:
      uVar11 = 0xfe;
    }
    else {
      resp.payload = (zdo_packet_payload_t *)((uint)resp.payload & 0xffff0000);
      uVar6 = zmsg_get_length(pzVar4);
      af_read_le16(pzVar4,(uint16_t *)&resp.payload,&req_4.nwk_addr_of_interest);
      af_read_le16(pzVar4,(uint16_t *)&resp.payload,(uint16_t *)&req_4.endpoint);
      af_read_le8(pzVar4,(uint16_t *)&resp.payload,(uint8_t *)&offset);
      uVar30 = _offset & 0xff;
      uVar28 = 0;
      pvVar7 = calloc(uVar30,2);
      pvStack_a0 = pvVar7;
      if (pvVar7 == (void *)0x0) {
        pvStack_a0 = (void *)0x0;
        if (uVar30 != 0) goto _L0;
      }
      else {
        for (; pvVar7 = pvStack_a0, uVar28 < (_offset & 0xff); uVar28 = uVar28 + 1 & 0xff) {
          af_read_le16(pzVar4,(uint16_t *)&resp.payload,(uint16_t *)((int)pvStack_a0 + uVar28 * 2));
        }
      }
      pvStack_a0 = pvVar7;
      af_read_le8(pzVar4,(uint16_t *)&resp.payload,(uint8_t *)((int)&offset + 1));
      pvStack_a0 = (void *)mm_realloc(pvStack_a0,(_offset & 0xff) + (_offset >> 8 & 0xff),2);
      uVar28 = _offset & 0xff;
      if (pvStack_a0 == (void *)0x0) {
        if ((_offset >> 8 & 0xff) + uVar28 != 0) goto _L0;
      }
      else {
        for (; uVar28 < (_offset & 0xff) + (_offset >> 8 & 0xff); uVar28 = uVar28 + 1 & 0xff) {
          af_read_le16(pzVar4,(uint16_t *)&resp.payload,(uint16_t *)((int)pvStack_a0 + uVar28 * 2));
        }
      }
      if (uVar6 < ((uint)resp.payload & 0xffff)) goto _L0;
      iVar13 = nwk_is_device_zed();
      uVar6 = (uint)req_4 & 0xffff;
      if (iVar13 == 0) {
        uVar28 = nwk_get_short_address();
        if ((uVar28 != uVar6) && (req_4.nwk_addr_of_interest < 0xfff8)) {
          resp.payload = (zdo_packet_payload_t *)CONCAT22(resp.payload._2_2_,0xffff);
          puVar5 = (undefined2 *)0x0;
          do {
            puVar5 = (undefined2 *)nwk_neighbor_table_next(puVar5);
            if (puVar5 == (undefined2 *)0x0) {
              puVar5 = (undefined2 *)0x81;
              goto _L0;
            }
          } while (((*(uint *)(puVar5 + 6) & 3) != 2) ||
                  (nwk_address_short_by_ref(*puVar5,&resp.payload),
                  ((uint)req_4 & 0xffff) != ((uint)resp.payload & 0xffff)));
        }
_L0:
        puVar5 = (undefined2 *)0x0;
      }
      else {
        uVar28 = nwk_get_short_address();
        if (uVar28 == uVar6) goto _L0;
        puVar5 = (undefined2 *)((uint)(req_4.nwk_addr_of_interest < 0xfff8) << 7);
      }
_L0:
      pvVar7 = (void *)0x0;
      arg = resp.ctx.req_ctx.arg;
      if (resp.ctx.req_ctx.arg == (zdo_packet_user_ctx_t)0x0) goto _L0;
      val_00 = req_4.nwk_addr_of_interest;
      if (0xfff7 < req_4.nwk_addr_of_interest) {
        val_00 = nwk_get_short_address();
      }
      if (puVar5 == (undefined2 *)0x0) {
        uVar11 = _offset & 0xff;
        pvVar7 = (void *)0;
        if (uVar11 != 0) {
          pvVar7 = pvStack_a0;
        }
        uVar6 = _offset >> 8 & 0xff;
        iVar13 = 0;
        if (uVar6 != 0) {
          iVar13 = (int)pvStack_a0 + uVar11 * 2;
        }
        memset(&resp.payload,0,0x40);
        uVar10 = req_4._2_2_;
        uVar28 = 0;
        puVar16 = (undefined1 *)0x0;
_L0:
        while (puVar16 = (undefined1 *)af_get_next_simple_desc(puVar16),
              puVar16 != (undefined1 *)0x0) {
          if ((*(short *)(puVar16 + 2) == uVar10) || (uVar10 == -1)) {
            for (uVar30 = 0; (uVar30 & 0xff) < (uint)(byte)puVar16[7]; uVar30 = uVar30 + 1) {
              uVar21 = 0;
              while ((uVar21 & 0xff) < uVar11) {
                uVar21 = uVar21 + 1;
                if (*(short *)(uVar30 * 2 + *(int *)(puVar16 + 0xc)) ==
                    *(short *)(uVar21 * 2 + (int)pvVar7 + -2)) goto _L0;
              }
            }
            psVar27 = (short *)(*(int *)(puVar16 + 0xc) + (uint)(byte)puVar16[7] * 2);
            for (cVar9 = '\0'; puVar16[8] != cVar9; cVar9 = cVar9 + '\x01') {
              uVar30 = 0;
              while ((uVar30 & 0xff) < uVar6) {
                uVar30 = uVar30 + 1;
                if (*psVar27 == *(short *)(uVar30 * 2 + iVar13 + -2)) goto _L0;
              }
              psVar27 = psVar27 + 1;
            }
          }
        }
        if (req_4.nwk_addr_of_interest < 0xfff8) {
          val_01 = -(uVar28 == 0) & 0x89;
_L0:
          eVar19 = zmsg_append_u8((zmsg_t *)resp.ctx.req_ctx.arg,val_01);
          if ((((eVar19 != 0) ||
               (eVar19 = zmsg_append_le16((zmsg_t *)resp.ctx.req_ctx.arg,val_00), eVar19 != 0)) ||
              (eVar19 = zmsg_append_u8((zmsg_t *)resp.ctx.req_ctx.arg,(uint8_t)uVar28), eVar19 != 0)
              ) || (((uVar11 = 0, val_01 == 0 && (uVar28 != 0)) &&
                    (iVar13 = zmsg_append_bytes(resp.ctx.req_ctx.arg,uVar28,&resp.payload),
                    iVar13 != 0)))) {
            uVar11 = 0x8a;
          }
        }
        else {
          val_01 = 0;
          if (uVar28 != 0) goto _L0;
          uVar11 = 0xfe;
        }
        goto _L0;
      }
      eVar19 = zmsg_append_u8((zmsg_t *)resp.ctx.req_ctx.arg,(uint8_t)puVar5);
      if (((eVar19 != 0) ||
          (eVar19 = zmsg_append_le16((zmsg_t *)resp.ctx.req_ctx.arg,val_00), eVar19 != 0)) ||
         (eVar19 = zmsg_append_u8((zmsg_t *)resp.ctx.req_ctx.arg,'\0'), eVar19 != 0)) {
        uVar11 = 0x8a;
      }
    }
_L0:
    if (pvStack_a0 != (void *)0x0) {
      mm_free();
    }
_L0:
    if (uVar11 != 0) {
_L0:
      zdo_packet_free(auStack_88);
      goto _L0;
    }
  }
_L0:
  uVar11 = zdo_packet_send(auStack_88);
_L0:
  return (zdp_status_t)uVar11;
_L0:
  *(undefined1 *)((int)&resp.payload + uVar28) = *puVar16;
  uVar28 = uVar28 + 1 & 0xff;
  goto _L0;
}

