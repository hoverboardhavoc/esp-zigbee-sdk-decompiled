/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
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
  zdp_status_t zVar7;
  char cVar8;
  undefined2 uVar9;
  ezb_shortaddr_t val_00;
  uint uVar10;
  undefined3 extraout_var;
  ushort *puVar11;
  zdp_simple_desc_req_field_t *pzVar12;
  undefined3 extraout_var_00;
  int iVar13;
  undefined4 *puVar14;
  undefined3 extraout_var_01;
  undefined2 *puVar15;
  void *pvVar16;
  undefined4 uVar17;
  undefined1 *puVar18;
  undefined3 extraout_var_02;
  char *pcVar19;
  ezb_err_t eVar20;
  undefined3 extraout_var_03;
  uint16_t *__src;
  int *piVar21;
  int extraout_a0;
  int extraout_a0_00;
  uint uVar22;
  undefined1 uVar23;
  undefined1 uVar25;
  undefined1 uVar26;
  short *psVar28;
  uint uVar29;
  byte val_01;
  uint8_t uVar30;
  uint uVar31;
  uint16_t val_02;
  uint16_t val_03;
  uint16_t val_04;
  uint8_t uVar32;
  uint16_t val_05;
  uint16_t val_06;
  anon_union_8_2_c961180f_for_ezb_eui64_s_0 ieee_addr;
  zdp_active_ep_req_field_t azStack_bc [2];
  zdp_active_ep_req_field_t req_2;
  zdp_power_desc_req_field_t req_3;
  zdp_node_desc_req_field_t req_8;
  zdp_sys_srv_disc_req_field_t req_7;
  uint8_t auStack_aa [2];
  zdp_simple_desc_req_field_t req_5;
  uint16_t offset;
  void *pvStack_a0;
  undefined4 uStack_9c;
  zdp_nwk_addr_req_field_t req;
  undefined1 auStack_88 [4];
  zdo_packet_t resp;
  zdp_nwk_addr_rsp_field_t rsp;
  undefined1 uVar24;
  undefined1 uVar27;
  
  memset(auStack_88,0,0x18);
  if (arg == (void *)0x0) {
    uVar10 = 0x80;
    goto _L0;
  }
  uVar10 = zdo_packet_response_init(auStack_88,arg,*(ushort *)((int)arg + 6) | 0x8000);
  if (uVar10 != 0) goto _L0;
  uVar1 = *(ushort *)((int)arg + 6);
  if (uVar1 == 5) {
    azStack_bc[0].nwk_addr_of_interest = 0;
    if ((*(zdo_packet_payload_t **)((int)arg + 0x14) == (zdo_packet_payload_t *)0x0) ||
       (zVar7 = zdo_op_active_ep_req(*(zdo_packet_payload_t **)((int)arg + 0x14),azStack_bc,false),
       zVar3.nwk_addr_of_interest = azStack_bc[0].nwk_addr_of_interest,
       CONCAT31(extraout_var_02,zVar7) != 0)) goto _L0;
    uVar10 = (uint)azStack_bc[0].nwk_addr_of_interest;
    if (0xfff7 < uVar10) {
_L0:
      uVar10 = 0x8b;
      goto _L0;
    }
    uVar6 = nwk_get_short_address();
    if (uVar10 == uVar6) {
      arg = (void *)0x0;
      pcVar19 = (char *)0x0;
      while (pcVar19 = (char *)af_device_get_next_endpoint_desc(pcVar19), pcVar19 != (char *)0x0) {
        if (*pcVar19 != '\0') {
          arg = (void *)((int)arg + 1U & 0xff);
        }
      }
      puVar5 = (undefined2 *)0x0;
      if (arg != (void *)0x0) {
        puVar5 = (undefined2 *)calloc((size_t)arg,1);
        uVar10 = 0;
        pcVar19 = (char *)0x0;
        if (puVar5 == (undefined2 *)0x0) goto _L0;
        while (pcVar19 = (char *)af_device_get_next_endpoint_desc(pcVar19), pcVar19 != (char *)0x0)
        {
          if (*pcVar19 != '\0') {
            *(char *)(uVar10 + (int)puVar5) = *pcVar19;
            uVar10 = uVar10 + 1 & 0xff;
          }
        }
      }
      uVar32 = '\0';
    }
    else {
      cVar8 = nwk_is_device_zed();
      uVar32 = 0x81 - cVar8;
      arg = (void *)0x0;
      puVar5 = (undefined2 *)0x0;
    }
    puVar15 = (undefined2 *)0x0;
    if (resp.ctx.req_ctx.arg == (zdo_packet_user_ctx_t)0x0) {
_L0:
      do {
        __assert_func(0,0,0,0);
        do {
          resp.payload = (zdo_packet_payload_t *)CONCAT22((short)arg,(ezb_shortaddr_t)resp.payload);
_L0:
          do {
            puVar15 = (undefined2 *)nwk_neighbor_table_next(puVar15);
            if (puVar15 == (undefined2 *)0x0) goto _L0;
          } while ((undefined2 *)(*(uint *)(puVar15 + 6) & 3) != puVar5);
          nwk_address_short_by_ref(*puVar15,(undefined1 *)((int)&resp.payload + 2));
        } while (resp.payload._2_2_ != req_7.server_mask);
_L0:
        uVar25 = 0x89;
        if (resp.payload._2_2_ == -1) {
          uVar25 = 0x81;
        }
        resp.payload = (zdo_packet_payload_t *)CONCAT31(resp.payload._1_3_,uVar25);
_L0:
        puVar15 = (undefined2 *)resp.ctx.req_ctx.arg;
      } while (resp.ctx.req_ctx.arg == (zdo_packet_user_ctx_t)0x0);
      eVar20 = zmsg_append_u8((zmsg_t *)resp.ctx.req_ctx.arg,(uint8_t)resp.payload);
      if (eVar20 == 0) {
        eVar20 = zmsg_append_le16((zmsg_t *)resp.ctx.req_ctx.arg,resp.payload._2_2_);
        if (eVar20 == 0) {
          uVar17 = zmsg_get_length(resp.ctx.req_ctx.arg);
          eVar20 = zmsg_append_u8((zmsg_t *)resp.ctx.req_ctx.arg,rsp.status);
          if (eVar20 == 0) {
            if (((uint)resp.payload & 0xff) != 0) goto _L0;
            rsp.status = rsp.status + '\b';
            eVar20 = zmsg_append_u8((zmsg_t *)resp.ctx.req_ctx.arg,
                                    rsp.ieee_addr_remote_dev.field_0.u8[3]);
            if (eVar20 == 0) {
              eVar20 = zmsg_append_le16((zmsg_t *)resp.ctx.req_ctx.arg,
                                        rsp.ieee_addr_remote_dev.field_0.u64._5_2_);
              if (eVar20 == 0) {
                eVar20 = zmsg_append_le16((zmsg_t *)resp.ctx.req_ctx.arg,rsp._8_2_);
                if ((eVar20 == 0) &&
                   (eVar20 = zmsg_append_u8((zmsg_t *)resp.ctx.req_ctx.arg,
                                            (byte)((uint)rsp._8_4_ >> 0xc) & 0xf0 |
                                            (byte)((uint)rsp._8_4_ >> 0x14) & 0xf), eVar20 == 0)) {
                  eVar20 = zmsg_append_u8((zmsg_t *)resp.ctx.req_ctx.arg,
                                          rsp.nwk_addr_remote_dev._1_1_);
                  uVar10 = 0;
                  if (eVar20 == 0) {
                    for (; uVar10 < (uint)rsp._8_4_ >> 0x18; uVar10 = uVar10 + 1 & 0xff) {
                      eVar20 = zmsg_append_le16((zmsg_t *)resp.ctx.req_ctx.arg,
                                                rsp.nwk_addr_assoc_dev_list[uVar10]);
                      if (eVar20 != 0) goto _L0;
                      rsp.status = rsp.status + '\x02';
                    }
                    eVar20 = zmsg_append_u8((zmsg_t *)resp.ctx.req_ctx.arg,rsp.num_assoc_dev);
                    if (eVar20 == 0) {
                      for (uVar10 = (uint)rsp._8_4_ >> 0x18; uVar10 = uVar10 & 0xff,
                          uVar10 < ((uint)rsp._8_4_ >> 0x18) + (rsp._12_4_ & 0xff);
                          uVar10 = uVar10 + 1) {
                        eVar20 = zmsg_append_le16((zmsg_t *)resp.ctx.req_ctx.arg,
                                                  rsp.nwk_addr_assoc_dev_list[uVar10]);
                        if (eVar20 != 0) goto _L0;
                        rsp.status = rsp.status + '\x02';
                      }
                      pzVar12 = (zdp_simple_desc_req_field_t *)&uStack_9c;
                      uStack_9c._0_1_ = rsp.status;
                      goto _L543;
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
    eVar20 = zmsg_append_u8((zmsg_t *)resp.ctx.req_ctx.arg,uVar32);
    if (((eVar20 == 0) &&
        (eVar20 = zmsg_append_le16((zmsg_t *)resp.ctx.req_ctx.arg,zVar3.nwk_addr_of_interest),
        eVar20 == 0)) &&
       (eVar20 = zmsg_append_u8((zmsg_t *)resp.ctx.req_ctx.arg,(uint8_t)arg), eVar20 == 0)) {
      uVar10 = 0;
      if ((uVar32 == '\0') && (uVar6 = 0, arg != (void *)0x0)) {
        do {
          eVar20 = zmsg_append_u8((zmsg_t *)resp.ctx.req_ctx.arg,*(uint8_t *)((int)puVar5 + uVar6));
          if (eVar20 != 0) goto _L0;
          uVar6 = uVar6 + 1;
        } while ((void *)(uVar6 & 0xff) < arg);
      }
    }
    else {
_L0:
      uVar10 = 0x8a;
    }
    if (puVar5 == (undefined2 *)0x0) goto _L0;
_L0:
    mm_free(puVar5);
_L0:
    if (uVar10 == 0) {
_L0:
      uVar10 = zdo_packet_send(auStack_88);
      goto _L0;
    }
  }
  else if (uVar1 < 6) {
    if (uVar1 != 2) {
      if (2 < uVar1) {
        if (uVar1 == 3) {
          req_2.nwk_addr_of_interest = 0;
          if ((*(zdo_packet_payload_t **)((int)arg + 0x14) != (zdo_packet_payload_t *)0x0) &&
             (zVar7 = zdo_op_active_ep_req(*(zdo_packet_payload_t **)((int)arg + 0x14),&req_2,false)
             , zVar3 = req_2, CONCAT31(extraout_var,zVar7) == 0)) {
            uVar10 = (uint)req_2.nwk_addr_of_interest;
            if (0xfff7 < uVar10) goto _L0;
            uVar6 = nwk_get_short_address();
            if (uVar10 == uVar6) {
              puVar11 = (ushort *)af_get_node_power_desc();
              puVar15 = (undefined2 *)0x0;
              if (puVar11 == (ushort *)0x0) goto _L0;
              puVar5 = (undefined2 *)(uint)*puVar11;
            }
            else {
              iVar13 = nwk_is_device_zed();
              puVar15 = (undefined2 *)0x80;
              if (iVar13 == 0) {
                puVar5 = (undefined2 *)0x0;
                do {
                  do {
                    puVar5 = (undefined2 *)nwk_neighbor_table_next(puVar5);
                    if (puVar5 == (undefined2 *)0x0) goto _L546;
                  } while ((*(uint *)(puVar5 + 6) & 3) != 2);
                  resp.payload = (zdo_packet_payload_t *)CONCAT22(resp.payload._2_2_,0xffff);
                  nwk_address_short_by_ref(*puVar5,&resp.payload);
                } while (req_2.nwk_addr_of_interest != (ezb_shortaddr_t)resp.payload);
_L546:
                puVar15 = (undefined2 *)0x81;
              }
_L0:
              puVar5 = (undefined2 *)0x0;
            }
            arg = resp.ctx.req_ctx.arg;
            if (resp.ctx.req_ctx.arg == (zdo_packet_user_ctx_t)0x0) goto _L0;
            eVar20 = zmsg_append_u8((zmsg_t *)resp.ctx.req_ctx.arg,(uint8_t)puVar15);
            if ((eVar20 == 0) &&
               (eVar20 = zmsg_append_le16((zmsg_t *)resp.ctx.req_ctx.arg,zVar3.nwk_addr_of_interest)
               , eVar20 == 0)) {
              if (puVar15 == (undefined2 *)0x0) goto _L0;
              goto _L0;
            }
            goto _L0;
          }
        }
        else {
          _req_7 = 0;
          memset(&resp.payload,0,0x18);
          pzVar4 = *(zmsg_t **)((int)arg + 0x14);
          if (pzVar4 != (zmsg_t *)0x0) {
            uStack_9c = (zdp_simple_desc_req_field_t)((uint)uStack_9c & 0xffff0000);
            puVar5 = (undefined2 *)zmsg_get_length(pzVar4);
            af_read_le16(pzVar4,(uint16_t *)&uStack_9c,&req_7.server_mask);
            af_read_le8(pzVar4,(uint16_t *)&uStack_9c,auStack_aa);
            if ((undefined2 *)((uint)uStack_9c & 0xffff) <= puVar5) {
              uVar10 = _req_7 & 0xffff;
              if (uVar10 < 0xfff8) {
                resp.payload = (zdo_packet_payload_t *)
                               CONCAT22(req_7.server_mask,(ezb_shortaddr_t)resp.payload);
                uVar6 = nwk_get_short_address();
                if (uVar10 == uVar6) {
                  if (((_req_7 >> 0x10 & 0xff) - 1 & 0xff) < 0xfe) {
                    pvVar16 = (void *)af_get_simple_desc();
                    if (pvVar16 != (void *)0x0) {
                      resp.payload = (zdo_packet_payload_t *)((uint)resp.payload & 0xffffff00);
                      memcpy((void *)((int)&rsp.ieee_addr_remote_dev.field_0 + 3),pvVar16,0x10);
                      goto _L0;
                    }
                    uVar25 = 0x83;
                  }
                  else {
                    uVar25 = 0x82;
                  }
                  resp.payload = (zdo_packet_payload_t *)CONCAT31(resp.payload._1_3_,uVar25);
                  goto _L0;
                }
                iVar13 = nwk_is_device_zed();
                if (iVar13 == 0) {
                  puVar15 = (undefined2 *)0x0;
                  puVar5 = (undefined2 *)0x2;
                  arg = (void *)0xffffffff;
                  goto _L0;
                }
              }
            }
          }
        }
        goto _L0;
      }
      pzVar4 = *(zmsg_t **)((int)arg + 0x14);
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
          req_5 = (zdp_simple_desc_req_field_t)((uint)(ushort)req_5._2_2_ << 0x10);
          uVar10 = zmsg_get_length(pzVar4);
          af_read_bytes(pzVar4,&req_5.nwk_addr_of_interest,8,(uint8_t *)&uStack_9c);
          af_read_le8(pzVar4,&req_5.nwk_addr_of_interest,req.ieee_addr_of_interest.field_0.u8 + 4);
          af_read_le8(pzVar4,&req_5.nwk_addr_of_interest,req.ieee_addr_of_interest.field_0.u8 + 5);
          if (((uint)req_5 & 0xffff) <= uVar10) {
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
            uVar25 = uStack_9c._1_1_;
            uVar32 = uStack_9c.endpoint;
            uVar30 = uStack_9c._3_1_;
            uVar26 = (undefined1)req.ieee_addr_of_interest.field_0.u64._0_4_;
            uVar23 = (undefined1)((uint)req.ieee_addr_of_interest.field_0._0_4_ >> 8);
            uVar24 = (undefined1)((uint)req.ieee_addr_of_interest.field_0._0_4_ >> 0x10);
            uVar27 = (undefined1)((uint)req.ieee_addr_of_interest.field_0._0_4_ >> 0x18);
            if ((uint)rsp.ieee_addr_remote_dev.field_0.u64._3_4_ >> 0x10 != 0xffff) {
              if ((req.ieee_addr_of_interest.field_0.u64._4_4_ & 0xff) == 0) {
                resp.payload = (zdo_packet_payload_t *)(((uint)uStack_9c & 0xff) << 8);
                resp.payload._0_3_ = CONCAT12(uVar25,(ezb_shortaddr_t)resp.payload);
                rsp.ieee_addr_remote_dev.field_0.u8[0] = uVar26;
                rsp.status = uVar30;
                rsp.ieee_addr_remote_dev.field_0.u8[1] = uVar23;
                resp.payload = (zdo_packet_payload_t *)CONCAT13(uVar32,resp.payload._0_3_);
                rsp.ieee_addr_remote_dev.field_0.u8[2] = uVar24;
                rsp.ieee_addr_remote_dev.field_0.u8[3] = uVar27;
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
                    uVar17 = *puVar14;
                    uVar2 = puVar14[1];
                    resp.payload._0_2_ =
                         CONCAT11((char)*(undefined3 *)puVar14,(uint8_t)resp.payload);
                    resp.payload._0_3_ =
                         CONCAT12((char)((uint)uVar17 >> 8),(ezb_shortaddr_t)resp.payload);
                    resp.payload = (zdo_packet_payload_t *)
                                   CONCAT13((char)((uint)uVar17 >> 0x10),resp.payload._0_3_);
                    rsp.ieee_addr_remote_dev.field_0.u8[0] = (char)*(undefined3 *)(puVar14 + 1);
                    rsp.status = (uint8_t)((uint)uVar17 >> 0x18);
                    rsp.ieee_addr_remote_dev.field_0.u8[1] = (char)((uint)uVar2 >> 8);
                    rsp.ieee_addr_remote_dev.field_0.u8[2] = (char)((uint)uVar2 >> 0x10);
                    rsp.ieee_addr_remote_dev.field_0.u8[3] = (char)((uint)uVar2 >> 0x18);
                    uVar9 = nwk_get_short_address();
                    rsp.ieee_addr_remote_dev.field_0.u64._5_2_ = uVar9;
                    uVar10 = nwk_neighbor_table_get_ed_num();
                    uVar10 = uVar10 & 0xff;
                    if (uVar10 != 0) {
                      rsp._12_4_ = calloc(uVar10,2);
                    }
                    puVar5 = (undefined2 *)0x0;
                    rsp._8_4_ = (uint)CONCAT21(rsp.nwk_addr_remote_dev,
                                               req.ieee_addr_of_interest.field_0.u8[5]) << 8;
                    uVar6 = 0;
                    while ((puVar5 = (undefined2 *)nwk_neighbor_table_next(puVar5),
                           puVar5 != (undefined2 *)0x0 && ((rsp._8_4_ & 0xff) < uVar10))) {
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
                resp.payload._0_3_ = CONCAT12(uVar25,(ezb_shortaddr_t)resp.payload);
                rsp.ieee_addr_remote_dev.field_0.u8[0] = uVar26;
                rsp.status = uVar30;
                rsp.ieee_addr_remote_dev.field_0.u8[1] = uVar23;
                rsp.ieee_addr_remote_dev.field_0.u8[3] = uVar27;
                resp.payload = (zdo_packet_payload_t *)CONCAT13(uVar32,resp.payload._0_3_);
                rsp.ieee_addr_remote_dev.field_0.u8[2] = uVar24;
                rsp.ieee_addr_remote_dev.field_0.u64._5_2_ = 0xffff;
              }
              zVar7 = zdo_op_nwk_addr_rsp((zdo_packet_payload_t *)resp.ctx.req_ctx.arg,
                                          req.ieee_addr_of_interest.field_0.u8[4],
                                          (zdp_nwk_addr_rsp_field_t *)&resp.payload,true);
              uVar10 = CONCAT31(extraout_var_00,zVar7);
              goto _L0;
            }
            if (*(ushort *)((int)arg + 2) < 0xfff8) {
              resp.payload._0_2_ = CONCAT11(uStack_9c.nwk_addr_of_interest,0x81);
              resp.payload._0_3_ = CONCAT12(uVar25,(ezb_shortaddr_t)resp.payload);
              rsp.ieee_addr_remote_dev.field_0.u8[0] = uVar26;
              rsp.status = uVar30;
              rsp.ieee_addr_remote_dev.field_0.u8[1] = uVar23;
              rsp.ieee_addr_remote_dev.field_0.u8[3] = uVar27;
              resp.payload = (zdo_packet_payload_t *)CONCAT13(uVar32,resp.payload._0_3_);
              rsp.ieee_addr_remote_dev.field_0.u8[2] = uVar24;
              rsp.ieee_addr_remote_dev.field_0.u64._5_2_ = 0xffff;
              goto _L0;
            }
          }
        }
_L0:
        uVar10 = 0xfe;
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
        req_5 = (zdp_simple_desc_req_field_t)((uint)(ushort)req_5._2_2_ << 0x10);
        uVar10 = zmsg_get_length(pzVar4);
        af_read_le16(pzVar4,&req_5.nwk_addr_of_interest,(uint16_t *)&uStack_9c);
        af_read_le8(pzVar4,&req_5.nwk_addr_of_interest,(uint8_t *)((int)&uStack_9c + 2));
        af_read_le8(pzVar4,&req_5.nwk_addr_of_interest,(uint8_t *)((int)&uStack_9c + 3));
        if (uVar10 < ((uint)req_5 & 0xffff)) goto _L0;
        uVar10 = (uint)uStack_9c & 0xffff;
        resp.payload._0_2_ = CONCAT11(0xff,(uint8_t)resp.payload);
        resp.payload._0_3_ = CONCAT12(0xff,(ezb_shortaddr_t)resp.payload);
        resp.payload = (zdo_packet_payload_t *)CONCAT13(0xff,resp.payload._0_3_);
        rsp._0_4_ = 0xffffffff;
        rsp.ieee_addr_remote_dev.field_0.u8[3] = 0xff;
        uVar6 = nwk_get_short_address();
        if (uVar10 == uVar6) {
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
              uVar17 = *puVar14;
              uVar2 = puVar14[1];
              resp.payload._0_2_ = CONCAT11((char)*(undefined3 *)puVar14,(uint8_t)resp.payload);
              resp.payload._0_3_ = CONCAT12((char)((uint)uVar17 >> 8),(ezb_shortaddr_t)resp.payload)
              ;
              resp.payload = (zdo_packet_payload_t *)
                             CONCAT13((char)((uint)uVar17 >> 0x10),resp.payload._0_3_);
              rsp.ieee_addr_remote_dev.field_0.u8[0] = (char)*(undefined3 *)(puVar14 + 1);
              rsp.status = (uint8_t)((uint)uVar17 >> 0x18);
              rsp.ieee_addr_remote_dev.field_0.u8[1] = (char)((uint)uVar2 >> 8);
              rsp.ieee_addr_remote_dev.field_0.u8[2] = (char)((uint)uVar2 >> 0x10);
              rsp.ieee_addr_remote_dev.field_0.u8[3] = (char)((uint)uVar2 >> 0x18);
              uVar9 = nwk_get_short_address();
              rsp.ieee_addr_remote_dev.field_0.u64._5_2_ = uVar9;
              uVar10 = nwk_neighbor_table_get_ed_num();
              if ((uVar10 & 0xff) != 0) {
                rsp._12_4_ = calloc(uVar10 & 0xff,2);
              }
              puVar5 = (undefined2 *)0x0;
              rsp._8_4_ = (uint)CONCAT21(rsp.nwk_addr_remote_dev,uStack_9c._3_1_) << 8;
              uVar10 = 0;
              while (puVar5 = (undefined2 *)nwk_neighbor_table_next(puVar5),
                    puVar5 != (undefined2 *)0x0) {
                uVar6 = (uint)rsp._8_4_ >> 8 & 0xff;
                if ((uVar6 <= uVar10) && ((*(uint *)(puVar5 + 6) & 3) == 2)) {
                  nwk_address_short_by_ref(*puVar5,(uVar10 - uVar6) * 2 + rsp._12_4_);
                  rsp.ieee_addr_remote_dev.field_0.u8[7] =
                       rsp.ieee_addr_remote_dev.field_0.u8[7] + '\x01';
                }
                uVar10 = uVar10 + 1 & 0xff;
              }
            }
          }
          else {
            resp.payload = (zdo_packet_payload_t *)CONCAT31(resp.payload._1_3_,0x80);
            puVar14 = (undefined4 *)nwk_get_extended_address();
            uVar17 = *puVar14;
            uVar2 = puVar14[1];
            resp.payload._0_2_ = CONCAT11((char)*(undefined3 *)puVar14,(uint8_t)resp.payload);
            resp.payload._0_3_ = CONCAT12((char)((uint)uVar17 >> 8),(ezb_shortaddr_t)resp.payload);
            resp.payload = (zdo_packet_payload_t *)
                           CONCAT13((char)((uint)uVar17 >> 0x10),resp.payload._0_3_);
            rsp.ieee_addr_remote_dev.field_0.u8[0] = (char)*(undefined3 *)(puVar14 + 1);
            rsp.status = (uint8_t)((uint)uVar17 >> 0x18);
            rsp.ieee_addr_remote_dev.field_0.u8[1] = (char)((uint)uVar2 >> 8);
            rsp.ieee_addr_remote_dev.field_0.u8[2] = (char)((uint)uVar2 >> 0x10);
            rsp.ieee_addr_remote_dev.field_0.u8[3] = (char)((uint)uVar2 >> 0x18);
            uVar9 = nwk_get_short_address();
            rsp.ieee_addr_remote_dev.field_0.u64._5_2_ = uVar9;
          }
        }
        zVar7 = zdo_op_ieee_addr_rsp
                          ((zdo_packet_payload_t *)resp.ctx.req_ctx.arg,uStack_9c._2_1_,
                           (zdp_ieee_addr_rsp_field_t *)&resp.payload,true);
        uVar10 = CONCAT31(extraout_var_01,zVar7);
      }
_L0:
      puVar5 = (undefined2 *)rsp._12_4_;
      if (rsp._12_4_ != 0) goto _L0;
      goto _L0;
    }
    req_3.nwk_addr_of_interest = 0;
    uStack_9c._0_2_ = 0;
    uStack_9c._2_1_ = '\0';
    uStack_9c._3_1_ = 0;
    req.ieee_addr_of_interest.field_0.u64._0_4_ = 0;
    req.ieee_addr_of_interest.field_0.u64._4_4_ = 0;
    stack0xffffff70 = 0;
    if ((*(zdo_packet_payload_t **)((int)arg + 0x14) == (zdo_packet_payload_t *)0x0) ||
       (zVar7 = zdo_op_active_ep_req(*(zdo_packet_payload_t **)((int)arg + 0x14),&req_3,false),
       val = req_3, CONCAT31(extraout_var_03,zVar7) != 0)) goto _L0;
    uVar10 = (uint)req_3.nwk_addr_of_interest;
    if (0xfff7 < uVar10) goto _L0;
    uStack_9c._2_2_ = req_3.nwk_addr_of_interest;
    uVar6 = nwk_get_short_address();
    puVar5 = (undefined2 *)0x0;
    if (uVar10 != uVar6) {
      iVar13 = nwk_is_device_zed();
      puVar5 = (undefined2 *)0x80;
      if (iVar13 == 0) {
        puVar5 = (undefined2 *)0x0;
        do {
          do {
            puVar5 = (undefined2 *)nwk_neighbor_table_next(puVar5);
            if (puVar5 == (undefined2 *)0x0) goto _L0;
          } while ((*(uint *)(puVar5 + 6) & 3) != 2);
          resp.payload = (zdo_packet_payload_t *)CONCAT22(resp.payload._2_2_,0xffff);
          nwk_address_short_by_ref(*puVar5,&resp.payload);
        } while (req_3.nwk_addr_of_interest != (ezb_shortaddr_t)resp.payload);
_L0:
        puVar5 = (undefined2 *)0x81;
      }
    }
    uStack_9c._0_1_ = (uint8_t)puVar5;
    req.ieee_addr_of_interest.field_0.u64._0_4_ = 0;
    req.ieee_addr_of_interest.field_0.u64._4_4_ = 0;
    stack0xffffff70 = 0;
    if ((puVar5 == (undefined2 *)0x0) &&
       (__src = (uint16_t *)af_get_node_desc(), __src != (uint16_t *)0x0)) {
      memcpy(&req,__src,0x10);
      val_06 = *__src;
      arg = (void *)(uint)(byte)__src[1];
      val_05 = __src[2];
      uVar32 = (uint8_t)__src[3];
      val_04 = __src[4];
      val_03 = __src[5];
      val_02 = __src[6];
      uVar30 = (uint8_t)__src[7];
    }
    else {
      uVar30 = '\0';
      uVar32 = '\0';
      val_02 = 0;
      val_03 = 0;
      val_04 = 0;
      val_05 = 0;
      val_06 = 0;
      arg = (void *)0x0;
    }
    puVar15 = (undefined2 *)resp.ctx.req_ctx.arg;
    if (resp.ctx.req_ctx.arg == (zdo_packet_user_ctx_t)0x0) goto _L0;
    eVar20 = zmsg_append_u8((zmsg_t *)resp.ctx.req_ctx.arg,(uint8_t)puVar5);
    if ((eVar20 == 0) &&
       (eVar20 = zmsg_append_le16((zmsg_t *)resp.ctx.req_ctx.arg,val.nwk_addr_of_interest),
       eVar20 == 0)) {
      if (puVar5 != (undefined2 *)0x0) goto _L0;
      eVar20 = zmsg_append_le16((zmsg_t *)resp.ctx.req_ctx.arg,val_06);
      if (((((eVar20 != 0) ||
            (eVar20 = zmsg_append_u8((zmsg_t *)resp.ctx.req_ctx.arg,(uint8_t)arg), eVar20 != 0)) ||
           (eVar20 = zmsg_append_le16((zmsg_t *)resp.ctx.req_ctx.arg,val_05), eVar20 != 0)) ||
          ((eVar20 = zmsg_append_u8((zmsg_t *)resp.ctx.req_ctx.arg,uVar32), eVar20 != 0 ||
           (eVar20 = zmsg_append_le16((zmsg_t *)resp.ctx.req_ctx.arg,val_04), eVar20 != 0)))) ||
         ((eVar20 = zmsg_append_le16((zmsg_t *)resp.ctx.req_ctx.arg,val_03), eVar20 != 0 ||
          (eVar20 = zmsg_append_le16((zmsg_t *)resp.ctx.req_ctx.arg,val_02), eVar20 != 0))))
      goto _L0;
      iVar13 = zmsg_append_u8((zmsg_t *)resp.ctx.req_ctx.arg,uVar30);
      goto _L0;
    }
_L0:
    uVar10 = 0x8a;
  }
  else {
    if (uVar1 != 0x15) {
      if (0x15 < uVar1) {
        if (uVar1 != 0x1f) {
_L544:
          uVar10 = 0x84;
          goto _L0;
        }
        uStack_9c = (zdp_simple_desc_req_field_t)((uint)uStack_9c & 0xffff0000);
        resp.payload = (zdo_packet_payload_t *)0x0;
        rsp._0_4_ = 0;
        rsp.ieee_addr_remote_dev.field_0.u64._3_4_ =
             rsp.ieee_addr_remote_dev.field_0.u64._3_4_ & 0xffffff00;
        if ((*(int *)((int)arg + 0x14) != 0) && (iVar13 = nwk_is_device_zed(), iVar13 == 0)) {
          uVar10 = zmsg_get_length(*(undefined4 *)((int)arg + 0x14));
          af_read_le8(*(zmsg_t **)((int)arg + 0x14),(uint16_t *)&uStack_9c,(uint8_t *)&resp.payload)
          ;
          if (((uint)uStack_9c & 0xffff) <= uVar10) {
            if ((0xfff7 < *(ushort *)((int)arg + 2)) &&
               (iVar13 = core_globals_get(), *(char *)(iVar13 + 0x16) != '\0')) {
              uVar10 = random_noncrypto_range_u32(0,0x2711);
              iVar13 = core_globals_get();
              *(char *)(iVar13 + 0x16) = (char)(uVar10 / 1000) + '\n';
            }
            zmsg_append_u8((zmsg_t *)resp.ctx.req_ctx.arg,'\0');
            cVar8 = '\0';
            for (uVar6 = 0; uVar6 < ((uint)resp.payload & 0xff); uVar6 = uVar6 + 1 & 0xff) {
              af_read_bytes(*(zmsg_t **)((int)arg + 0x14),(uint16_t *)&uStack_9c,8,
                            (uint8_t *)((int)&resp.payload + 1));
              iVar13 = nwk_neighbor_table_get_by_extended((undefined1 *)((int)&resp.payload + 1));
              if (((iVar13 != 0) && ((*(uint *)(iVar13 + 0xc) & 3) == 2)) &&
                 (*(int *)(iVar13 + 0x18) << 7 < 0)) {
                uVar10 = zmsg_append_bytes(resp.ctx.req_ctx.arg,8,
                                           (undefined1 *)((int)&resp.payload + 1));
                uVar10 = uVar10 & 0xff;
                if (uVar10 != 0) goto _L0;
                cVar8 = cVar8 + '\x01';
              }
            }
            if (cVar8 != '\0') {
              req_5.nwk_addr_of_interest._0_1_ = cVar8;
              pzVar12 = &req_5;
              uVar17 = 0;
_L543:
              zmsg_write_bytes(resp.ctx.req_ctx.arg,uVar17,1,pzVar12);
              goto _L0;
            }
          }
        }
        goto _L0;
      }
      if (uVar1 != 6) {
        if (uVar1 != 0x13) goto _L544;
        _req_7 = _req_7 & 0xffff0000;
        resp.payload = (zdo_packet_payload_t *)0x0;
        rsp._0_4_ = 0;
        rsp.ieee_addr_remote_dev.field_0.u64._3_4_ = 0;
        if (*(int *)((int)arg + 0x14) != 0) {
          uVar10 = zmsg_get_length();
          af_read_le16(*(zmsg_t **)((int)arg + 0x14),&req_7.server_mask,
                       (uint16_t *)(rsp.ieee_addr_remote_dev.field_0.u8 + 3));
          af_read_bytes(*(zmsg_t **)((int)arg + 0x14),&req_7.server_mask,8,(uint8_t *)&resp.payload)
          ;
          af_read_le8(*(zmsg_t **)((int)arg + 0x14),&req_7.server_mask,
                      rsp.ieee_addr_remote_dev.field_0.u8 + 5);
          if ((_req_7 & 0xffff) <= uVar10) {
            piVar21 = (int *)nwk_get_extended_address();
            if ((resp.payload != (zdo_packet_payload_t *)*piVar21) || (rsp._0_4_ != piVar21[1])) {
              ieee_addr.u64 = nwk_is_device_zczr();
              if (extraout_a0 != 0) {
                req_5 = (zdp_simple_desc_req_field_t)((uint)req_5 & 0xffff0000);
                ieee_addr.u64 =
                     nwk_address_update(&resp.payload,
                                        rsp.ieee_addr_remote_dev.field_0.u64._3_4_ & 0xffff,&req_5);
                if (extraout_a0_00 == 0xd) {
                  uStack_9c._1_1_ = (char)rsp.ieee_addr_remote_dev.field_0.u64._3_4_;
                  uStack_9c._0_1_ = 0xd;
                  uStack_9c._2_1_ = (char)((uint)rsp.ieee_addr_remote_dev.field_0._3_4_ >> 8);
                  uStack_9c._3_1_ = 0;
                  nwk_send_status(0xfffd,&uStack_9c);
                  nwk_handle_network_status_local(&uStack_9c);
                  goto _L0;
                }
              }
              zdo_device_annce_indication
                        ((ezb_extaddr_t)ieee_addr,(uint16_t)resp.payload,(uint8_t)rsp._0_4_);
            }
          }
        }
        goto _L0;
      }
      pzVar4 = *(zmsg_t **)((int)arg + 0x14);
      req_5.nwk_addr_of_interest = 0;
      req_5.endpoint = '\0';
      req_5._3_1_ = 0;
      _offset = 0;
      pvStack_a0 = (void *)0x0;
      if (pzVar4 == (zmsg_t *)0x0) {
_L0:
        uVar10 = 0xfe;
      }
      else {
        resp.payload = (zdo_packet_payload_t *)((uint)resp.payload._2_2_ << 0x10);
        uVar6 = zmsg_get_length(pzVar4);
        af_read_le16(pzVar4,(uint16_t *)&resp.payload,&req_5.nwk_addr_of_interest);
        af_read_le16(pzVar4,(uint16_t *)&resp.payload,(uint16_t *)&req_5.endpoint);
        af_read_le8(pzVar4,(uint16_t *)&resp.payload,(uint8_t *)&offset);
        uVar31 = _offset & 0xff;
        uVar29 = 0;
        pvVar16 = calloc(uVar31,2);
        pvStack_a0 = pvVar16;
        if (pvVar16 == (void *)0x0) {
          pvStack_a0 = (void *)0x0;
          if (uVar31 != 0) goto _L0;
        }
        else {
          for (; pvVar16 = pvStack_a0, uVar29 < (_offset & 0xff); uVar29 = uVar29 + 1 & 0xff) {
            af_read_le16(pzVar4,(uint16_t *)&resp.payload,(uint16_t *)((int)pvStack_a0 + uVar29 * 2)
                        );
          }
        }
        pvStack_a0 = pvVar16;
        af_read_le8(pzVar4,(uint16_t *)&resp.payload,(uint8_t *)((int)&offset + 1));
        pvStack_a0 = (void *)mm_realloc(pvStack_a0,(_offset & 0xff) + (_offset >> 8 & 0xff),2);
        uVar29 = _offset & 0xff;
        if (pvStack_a0 == (void *)0x0) {
          if ((_offset >> 8 & 0xff) + uVar29 != 0) goto _L0;
        }
        else {
          for (; uVar29 < (_offset & 0xff) + (_offset >> 8 & 0xff); uVar29 = uVar29 + 1 & 0xff) {
            af_read_le16(pzVar4,(uint16_t *)&resp.payload,(uint16_t *)((int)pvStack_a0 + uVar29 * 2)
                        );
          }
        }
        if (uVar6 < ((uint)resp.payload & 0xffff)) goto _L0;
        iVar13 = nwk_is_device_zed();
        uVar6 = (uint)req_5 & 0xffff;
        if (iVar13 == 0) {
          uVar29 = nwk_get_short_address();
          if ((uVar29 != uVar6) && (req_5.nwk_addr_of_interest < 0xfff8)) {
            resp.payload = (zdo_packet_payload_t *)CONCAT22(resp.payload._2_2_,0xffff);
            puVar5 = (undefined2 *)0x0;
            do {
              puVar5 = (undefined2 *)nwk_neighbor_table_next(puVar5);
              if (puVar5 == (undefined2 *)0x0) {
                puVar15 = (undefined2 *)0x81;
                goto _L0;
              }
            } while (((*(uint *)(puVar5 + 6) & 3) != 2) ||
                    (nwk_address_short_by_ref(*puVar5,&resp.payload),
                    ((uint)req_5 & 0xffff) != ((uint)resp.payload & 0xffff)));
          }
_L0:
          puVar15 = (undefined2 *)0x0;
        }
        else {
          uVar29 = nwk_get_short_address();
          if (uVar29 == uVar6) goto _L0;
          puVar15 = (undefined2 *)((uint)(req_5.nwk_addr_of_interest < 0xfff8) << 7);
        }
_L0:
        puVar5 = (undefined2 *)0x0;
        arg = resp.ctx.req_ctx.arg;
        if (resp.ctx.req_ctx.arg == (zdo_packet_user_ctx_t)0x0) goto _L0;
        val_00 = req_5.nwk_addr_of_interest;
        if (0xfff7 < req_5.nwk_addr_of_interest) {
          val_00 = nwk_get_short_address();
        }
        if (puVar15 == (undefined2 *)0x0) {
          uVar10 = _offset & 0xff;
          pvVar16 = (void *)0;
          if (uVar10 != 0) {
            pvVar16 = pvStack_a0;
          }
          uVar6 = _offset >> 8 & 0xff;
          iVar13 = 0;
          if (uVar6 != 0) {
            iVar13 = (int)pvStack_a0 + uVar10 * 2;
          }
          memset(&resp.payload,0,0x40);
          uVar9 = req_5._2_2_;
          uVar29 = 0;
          puVar18 = (undefined1 *)0x0;
_L0:
          while (puVar18 = (undefined1 *)af_get_next_simple_desc(puVar18),
                puVar18 != (undefined1 *)0x0) {
            if ((*(short *)(puVar18 + 2) == uVar9) || (uVar9 == -1)) {
              for (uVar31 = 0; (uVar31 & 0xff) < (uint)(byte)puVar18[7]; uVar31 = uVar31 + 1) {
                uVar22 = 0;
                while ((uVar22 & 0xff) < uVar10) {
                  uVar22 = uVar22 + 1;
                  if (*(short *)(uVar31 * 2 + *(int *)(puVar18 + 0xc)) ==
                      *(short *)(uVar22 * 2 + (int)pvVar16 + -2)) goto _L0;
                }
              }
              psVar28 = (short *)(*(int *)(puVar18 + 0xc) + (uint)(byte)puVar18[7] * 2);
              for (cVar8 = '\0'; puVar18[8] != cVar8; cVar8 = cVar8 + '\x01') {
                uVar31 = 0;
                while ((uVar31 & 0xff) < uVar6) {
                  uVar31 = uVar31 + 1;
                  if (*psVar28 == *(short *)(uVar31 * 2 + iVar13 + -2)) goto _L0;
                }
                psVar28 = psVar28 + 1;
              }
            }
          }
          if (req_5.nwk_addr_of_interest < 0xfff8) {
            val_01 = -(uVar29 == 0) & 0x89;
_L0:
            eVar20 = zmsg_append_u8((zmsg_t *)resp.ctx.req_ctx.arg,val_01);
            if ((((eVar20 != 0) ||
                 (eVar20 = zmsg_append_le16((zmsg_t *)resp.ctx.req_ctx.arg,val_00), eVar20 != 0)) ||
                (eVar20 = zmsg_append_u8((zmsg_t *)resp.ctx.req_ctx.arg,(uint8_t)uVar29),
                eVar20 != 0)) ||
               (((uVar10 = 0, val_01 == 0 && (uVar29 != 0)) &&
                (iVar13 = zmsg_append_bytes(resp.ctx.req_ctx.arg,uVar29,&resp.payload), iVar13 != 0)
                ))) {
              uVar10 = 0x8a;
            }
          }
          else {
            val_01 = 0;
            if (uVar29 != 0) goto _L0;
            uVar10 = 0xfe;
          }
          goto _L0;
        }
        eVar20 = zmsg_append_u8((zmsg_t *)resp.ctx.req_ctx.arg,(uint8_t)puVar15);
        if (((eVar20 != 0) ||
            (eVar20 = zmsg_append_le16((zmsg_t *)resp.ctx.req_ctx.arg,val_00), eVar20 != 0)) ||
           (eVar20 = zmsg_append_u8((zmsg_t *)resp.ctx.req_ctx.arg,'\0'), eVar20 != 0)) {
          uVar10 = 0x8a;
        }
      }
_L0:
      if (pvStack_a0 != (void *)0x0) {
        mm_free();
      }
      goto _L0;
    }
    pzVar4 = *(zmsg_t **)((int)arg + 0x14);
    req_8.nwk_addr_of_interest = 0;
    if (pzVar4 != (zmsg_t *)0x0) {
      resp.payload = (zdo_packet_payload_t *)((uint)resp.payload._2_2_ << 0x10);
      uVar10 = zmsg_get_length(pzVar4);
      af_read_le16(pzVar4,(uint16_t *)&resp.payload,&req_8.nwk_addr_of_interest);
      if (((uint)resp.payload & 0xffff) <= uVar10) {
        iVar13 = af_get_node_desc();
        if (iVar13 != 0) {
          puVar15 = (undefined2 *)((*(ushort *)(iVar13 + 10) & req_8.nwk_addr_of_interest) & 0x1ff);
          if (*(ushort *)(iVar13 + 10) >> 9 == req_8.nwk_addr_of_interest >> 9) {
            puVar15 = (undefined2 *)((uint)puVar15 | req_8.nwk_addr_of_interest & 0xfffffe00);
          }
          if (puVar15 == (undefined2 *)0x0) goto _L0;
          puVar5 = (undefined2 *)resp.ctx.req_ctx.arg;
          arg = arg;
          if (resp.ctx.req_ctx.arg == (zdo_packet_user_ctx_t)0x0) goto _L0;
          eVar20 = zmsg_append_u8((zmsg_t *)resp.ctx.req_ctx.arg,'\0');
          puVar5 = puVar15;
          if (eVar20 != 0) goto _L0;
_L0:
          iVar13 = zmsg_append_le16((zmsg_t *)resp.ctx.req_ctx.arg,(uint16_t)puVar5);
_L0:
          if (iVar13 != 0) goto _L0;
        }
        goto _L0;
      }
    }
_L0:
    uVar10 = 0xfe;
  }
_L0:
  zdo_packet_free(auStack_88);
_L0:
  return (zdp_status_t)uVar10;
_L0:
  *(undefined1 *)((int)&resp.payload + uVar29) = *puVar18;
  uVar29 = uVar29 + 1 & 0xff;
  goto _L0;
}

