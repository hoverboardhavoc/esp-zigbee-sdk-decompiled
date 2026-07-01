/*
 * Last changed at upstream commit 9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * https://github.com/espressif/esp-zigbee-sdk/commit/9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * Upstream date: 2026-07-01 11:36:50 +0800
 * Upstream subject: change: update esp-zigbee-lib (9401bce7)
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
  short sVar2;
  undefined4 uVar3;
  zdp_active_ep_req_field_t zVar4;
  zdp_power_desc_req_field_t val;
  zmsg_t *pzVar5;
  undefined2 *puVar6;
  void *pvVar7;
  uint uVar8;
  zdp_status_t zVar9;
  char cVar10;
  undefined2 uVar11;
  ezb_shortaddr_t val_00;
  uint uVar12;
  undefined3 extraout_var;
  ushort *puVar13;
  int *piVar14;
  undefined3 extraout_var_00;
  int iVar15;
  undefined4 *puVar16;
  undefined3 extraout_var_01;
  zdo_packet_user_ctx_t pvVar17;
  void *pvVar18;
  undefined4 uVar19;
  undefined1 *puVar20;
  undefined3 extraout_var_02;
  char *pcVar21;
  ezb_err_t eVar22;
  undefined3 extraout_var_03;
  uint16_t *__src;
  uint *puVar23;
  int extraout_a0;
  int extraout_a0_00;
  short *psVar24;
  char cVar25;
  uint16_t **ppuVar26;
  undefined1 uVar27;
  undefined1 uVar31;
  short *psVar32;
  uint8_t val_01;
  uint uVar33;
  zdo_packet_user_ctx_t unaff_s4;
  byte bVar34;
  uint16_t val_02;
  uint __nmemb;
  uint16_t val_03;
  uint16_t val_04;
  uint8_t uVar35;
  uint16_t uVar36;
  uint16_t val_05;
  undefined2 val_06;
  anon_union_8_2_c961180f_for_ezb_eui64_s_0 ieee_addr;
  zdp_active_ep_req_field_t azStack_d4 [2];
  zdp_active_ep_req_field_t req_2;
  zdp_power_desc_req_field_t req_3;
  zdp_node_desc_req_field_t req_8;
  zdp_sys_srv_disc_req_field_t req_7;
  uint8_t auStack_c2 [2];
  zdp_simple_desc_req_field_t req_5;
  zdp_match_desc_req_field_t req_6;
  uint16_t offset;
  undefined4 uStack_ac;
  undefined4 uStack_a8;
  undefined4 uStack_a4;
  undefined1 auStack_a0 [4];
  zdo_packet_t resp;
  zdp_nwk_addr_req_field_t req;
  byte bStack_78;
  zdo_packet_user_ctx_t pvStack_74;
  undefined1 auStack_70 [4];
  zdp_nwk_addr_rsp_field_t rsp;
  undefined1 uVar28;
  undefined1 uVar29;
  undefined1 uVar30;
  
  memset(auStack_a0,0,0x18);
  if (arg == (void *)0x0) {
    uVar12 = 0x80;
    goto _L0;
  }
  uVar12 = zdo_packet_response_init(auStack_a0,arg,*(ushort *)((int)arg + 6) | 0x8000);
  if (uVar12 != 0) goto _L0;
  uVar1 = *(ushort *)((int)arg + 6);
  if (uVar1 == 5) {
    azStack_d4[0].nwk_addr_of_interest = 0;
    if ((*(zdo_packet_payload_t **)((int)arg + 0x14) == (zdo_packet_payload_t *)0x0) ||
       (zVar9 = zdo_op_active_ep_req(*(zdo_packet_payload_t **)((int)arg + 0x14),azStack_d4,false),
       zVar4.nwk_addr_of_interest = azStack_d4[0].nwk_addr_of_interest,
       CONCAT31(extraout_var_02,zVar9) != 0)) goto _L0;
    uVar12 = (uint)azStack_d4[0].nwk_addr_of_interest;
    if (0xfff7 < uVar12) {
_L0:
      uVar12 = 0x8b;
      goto _L0;
    }
    uVar8 = nwk_get_short_address();
    if (uVar12 == uVar8) {
      arg = (void *)0x0;
      pcVar21 = (char *)0x0;
      while (pcVar21 = (char *)af_device_get_next_endpoint_desc(pcVar21), pcVar21 != (char *)0x0) {
        if (*pcVar21 != '\0') {
          arg = (void *)((int)arg + 1U & 0xff);
        }
      }
      pvVar7 = (void *)0x0;
      if (arg != (void *)0x0) {
        pvVar7 = calloc((size_t)arg,1);
        uVar12 = 0;
        pcVar21 = (char *)0x0;
        if (pvVar7 == (void *)0x0) goto _L0;
        while (pcVar21 = (char *)af_device_get_next_endpoint_desc(pcVar21), pcVar21 != (char *)0x0)
        {
          if (*pcVar21 != '\0') {
            *(char *)(uVar12 + (int)pvVar7) = *pcVar21;
            uVar12 = uVar12 + 1 & 0xff;
          }
        }
      }
      uVar35 = '\0';
    }
    else {
      cVar10 = nwk_is_device_zed();
      uVar35 = 0x81 - cVar10;
      arg = (void *)0x0;
      pvVar7 = (void *)0x0;
    }
    pvStack_74 = (zdo_packet_user_ctx_t)0x0;
    unaff_s4 = resp.ctx.req_ctx.arg;
    if (resp.ctx.req_ctx.arg == (zdo_packet_user_ctx_t)0x0) {
_L0:
      do {
        __assert_func(0,0,0,0);
        do {
          if (((void *)(*(uint *)((int)pvStack_74 + 0xc) & 0x3c0) == arg) &&
             (uVar8 = _req_7 & 0xffff, uVar12 = nwk_neighbor_get_shortaddr(), uVar8 == uVar12)) {
            uVar12 = 0;
            arg = (void *)0x0;
            pvStack_74 = (zdo_packet_user_ctx_t)0x0;
            bVar34 = 0;
            uVar8 = 0;
            uVar35 = 0x89;
            val_06 = 0;
            uVar36 = 0;
            goto _L0;
          }
_L0:
          pvStack_74 = (zdo_packet_user_ctx_t)nwk_child_table_next(pvStack_74);
        } while (pvStack_74 != (zdo_packet_user_ctx_t)0x0);
        uVar12 = 0;
        arg = (void *)0x0;
        bVar34 = 0;
        uVar8 = 0;
        uVar35 = 0x81;
        val_06 = 0;
        uVar36 = 0;
_L0:
      } while (resp.ctx.req_ctx.arg == (zdo_packet_user_ctx_t)0x0);
      eVar22 = zmsg_append_u8((zmsg_t *)resp.ctx.req_ctx.arg,uVar35);
      if ((eVar22 == 0) &&
         (eVar22 = zmsg_append_le16((zmsg_t *)resp.ctx.req_ctx.arg,(uint16_t)unaff_s4), eVar22 == 0)
         ) {
        uVar19 = zmsg_get_length(resp.ctx.req_ctx.arg);
        eVar22 = zmsg_append_u8((zmsg_t *)resp.ctx.req_ctx.arg,'\0');
        if (eVar22 == 0) {
          if (uVar35 != '\0') goto _L0;
          eVar22 = zmsg_append_u8((zmsg_t *)resp.ctx.req_ctx.arg,(uint8_t)pvVar7);
          if ((((eVar22 == 0) &&
               (eVar22 = zmsg_append_le16((zmsg_t *)resp.ctx.req_ctx.arg,val_06), eVar22 == 0)) &&
              (eVar22 = zmsg_append_le16((zmsg_t *)resp.ctx.req_ctx.arg,uVar36), eVar22 == 0)) &&
             (eVar22 = zmsg_append_u8((zmsg_t *)resp.ctx.req_ctx.arg,(byte)(uVar8 << 4) | bVar34),
             eVar22 == 0)) {
            iVar15 = zmsg_append_u8((zmsg_t *)resp.ctx.req_ctx.arg,(uint8_t)arg);
            uVar8 = 0;
            for (; iVar15 == 0;
                iVar15 = zmsg_append_le16((zmsg_t *)resp.ctx.req_ctx.arg,
                                          *(uint16_t *)(iVar15 + (int)pvStack_74))) {
              if (arg <= (void *)(uVar8 & 0xff)) {
                eVar22 = zmsg_append_u8((zmsg_t *)resp.ctx.req_ctx.arg,(uint8_t)uVar12);
                if (eVar22 == 0) {
                  uVar8 = (int)(uVar8 & 0xff) * 2 + 8;
                  pvVar7 = (void *)(uVar12 + (int)arg);
                  goto _L0;
                }
                break;
              }
              iVar15 = uVar8 * 2;
              uVar8 = uVar8 + 1;
            }
          }
        }
      }
      goto _L0;
    }
    eVar22 = zmsg_append_u8((zmsg_t *)resp.ctx.req_ctx.arg,uVar35);
    if (((eVar22 == 0) &&
        (eVar22 = zmsg_append_le16((zmsg_t *)resp.ctx.req_ctx.arg,zVar4.nwk_addr_of_interest),
        eVar22 == 0)) &&
       (eVar22 = zmsg_append_u8((zmsg_t *)resp.ctx.req_ctx.arg,(uint8_t)arg), eVar22 == 0)) {
      uVar12 = 0;
      if ((uVar35 == '\0') && (uVar8 = 0, arg != (void *)0x0)) {
        do {
          eVar22 = zmsg_append_u8((zmsg_t *)resp.ctx.req_ctx.arg,*(uint8_t *)((int)pvVar7 + uVar8));
          if (eVar22 != 0) goto _L0;
          uVar8 = uVar8 + 1;
        } while ((void *)(uVar8 & 0xff) < arg);
      }
    }
    else {
_L0:
      uVar12 = 0x8a;
    }
    if (pvVar7 == (void *)0x0) goto _L0;
_L0:
    mm_free(pvVar7);
_L0:
    if (uVar12 == 0) goto _L0;
  }
  else {
    pvVar7 = (void *)0x0;
    if (uVar1 < 6) {
      if (uVar1 != 2) {
        if (2 < uVar1) {
          if (uVar1 == 3) {
            req_2.nwk_addr_of_interest = 0;
            if ((*(zdo_packet_payload_t **)((int)arg + 0x14) != (zdo_packet_payload_t *)0x0) &&
               (zVar9 = zdo_op_active_ep_req
                                  (*(zdo_packet_payload_t **)((int)arg + 0x14),&req_2,false),
               zVar4 = req_2, CONCAT31(extraout_var,zVar9) == 0)) {
              uVar12 = (uint)req_2.nwk_addr_of_interest;
              if (0xfff7 < uVar12) goto _L0;
              uVar8 = nwk_get_short_address();
              if (uVar12 == uVar8) {
                puVar13 = (ushort *)af_get_node_power_desc();
                pvStack_74 = (zdo_packet_user_ctx_t)0x0;
                if (puVar13 == (ushort *)0x0) goto _L0;
                pvVar7 = (void *)(uint)*puVar13;
              }
              else {
                iVar15 = nwk_is_device_zed();
                pvStack_74 = (zdo_packet_user_ctx_t)0x80;
                if (iVar15 == 0) {
                  puVar6 = (undefined2 *)0x0;
                  do {
                    do {
                      puVar6 = (undefined2 *)nwk_neighbor_table_next(puVar6);
                      if (puVar6 == (undefined2 *)0x0) goto _L531;
                    } while ((*(uint *)(puVar6 + 6) & 3) != 2);
                    auStack_70._0_2_ = 0xffff;
                    nwk_address_short_by_ref(*puVar6,auStack_70);
                  } while (req_2.nwk_addr_of_interest != auStack_70._0_2_);
_L531:
                  pvStack_74 = (zdo_packet_user_ctx_t)0x81;
                }
_L0:
                pvVar7 = (void *)0x0;
              }
              uVar36 = (uint16_t)pvVar7;
              arg = resp.ctx.req_ctx.arg;
              if (resp.ctx.req_ctx.arg == (zdo_packet_user_ctx_t)0x0) goto _L0;
              eVar22 = zmsg_append_u8((zmsg_t *)resp.ctx.req_ctx.arg,(uint8_t)pvStack_74);
              if ((eVar22 == 0) &&
                 (eVar22 = zmsg_append_le16((zmsg_t *)resp.ctx.req_ctx.arg,
                                            zVar4.nwk_addr_of_interest), eVar22 == 0)) {
                if (pvStack_74 != (zdo_packet_user_ctx_t)0x0) goto _L0;
                goto _L0;
              }
              goto _L0;
            }
          }
          else {
            _req_7 = 0;
            memset(&resp.payload,0,0x18);
            pzVar5 = *(zmsg_t **)((int)arg + 0x14);
            if (pzVar5 != (zmsg_t *)0x0) {
              auStack_70 = (undefined1  [4])((uint)auStack_70 & 0xffff0000);
              uVar12 = zmsg_get_length(pzVar5);
              af_read_le16(pzVar5,(uint16_t *)auStack_70,&req_7.server_mask);
              af_read_le8(pzVar5,(uint16_t *)auStack_70,auStack_c2);
              if (((uint)auStack_70 & 0xffff) <= uVar12) {
                unaff_s4 = (zdo_packet_user_ctx_t)(_req_7 & 0xffff);
                if (unaff_s4 < (zdo_packet_user_ctx_t)0xfff8) {
                  resp.payload = (zdo_packet_payload_t *)
                                 CONCAT22(req_7.server_mask,resp.payload._0_2_);
                  pvVar17 = (zdo_packet_user_ctx_t)nwk_get_short_address();
                  if (unaff_s4 != pvVar17) {
                    iVar15 = nwk_is_device_zczr();
                    if (iVar15 == 0) {
                      uVar12 = 0;
                      arg = (void *)0x0;
                      pvStack_74 = (zdo_packet_user_ctx_t)0x0;
                      bVar34 = 0;
                      uVar8 = 0;
                      uVar35 = 0x80;
                      val_06 = 0;
                      uVar36 = 0;
                      goto _L0;
                    }
                    pvStack_74 = (zdo_packet_user_ctx_t)0x0;
                    arg = (void *)0x40;
                    goto _L0;
                  }
                  if (0xfd < ((_req_7 >> 0x10 & 0xff) - 1 & 0xff)) {
                    uVar12 = 0;
                    arg = (void *)0x0;
                    pvStack_74 = (zdo_packet_user_ctx_t)0x0;
                    bVar34 = 0;
                    uVar8 = 0;
                    uVar36 = 0;
                    val_06 = 0;
                    uVar35 = 0x82;
                    goto _L0;
                  }
                  pvVar18 = (void *)af_get_simple_desc();
                  if (pvVar18 != (void *)0x0) {
                    memcpy((void *)((int)&req.ieee_addr_of_interest.field_0 + 4),pvVar18,0x10);
                    arg = (void *)(stack0xffffff84 >> 0x18);
                    uVar12 = (uint)bStack_78;
                    pvVar7 = (void *)(uint)req.ieee_addr_of_interest.field_0.u8[4];
                    uVar8 = stack0xffffff84 >> 0x10 & 0xf;
                    bVar34 = (byte)(stack0xffffff84 >> 0x14) & 0xf;
                    uVar35 = '\0';
                    val_06 = req.ieee_addr_of_interest.field_0.u64._6_2_;
                    uVar36 = req._8_2_;
                    goto _L0;
                  }
                  uVar12 = 0;
                  arg = (void *)0x0;
                  bVar34 = 0;
                  uVar8 = 0;
                  uVar36 = 0;
                  val_06 = 0;
                  uVar35 = 0x83;
                  pvStack_74 = (zdo_packet_user_ctx_t)0x0;
                  goto _L0;
                }
              }
            }
          }
          goto _L0;
        }
        pzVar5 = *(zmsg_t **)((int)arg + 0x14);
        if (uVar1 == 0) {
          resp.payload = (zdo_packet_payload_t *)0x0;
          req.ieee_addr_of_interest.field_0.u64._0_4_ = 0;
          req.ieee_addr_of_interest.field_0.u64._4_2_ = 0;
          auStack_70 = (undefined1  [4])0x0;
          rsp._0_4_ = 0;
          rsp.ieee_addr_remote_dev.field_0.u64._3_4_ = 0;
          rsp._8_4_ = 0;
          rsp.num_assoc_dev = '\0';
          rsp.start_index = '\0';
          rsp._14_2_ = 0;
          if (pzVar5 == (zmsg_t *)0x0) goto _L0;
          req_6.cluster_list = (uint16_t *)((uint)req_6.cluster_list._2_2_ << 0x10);
          uVar12 = zmsg_get_length(pzVar5);
          af_read_bytes(pzVar5,(uint16_t *)&req_6.cluster_list,8,(uint8_t *)&resp.payload);
          af_read_le8(pzVar5,(uint16_t *)&req_6.cluster_list,
                      req.ieee_addr_of_interest.field_0.u8 + 4);
          af_read_le8(pzVar5,(uint16_t *)&req_6.cluster_list,
                      req.ieee_addr_of_interest.field_0.u8 + 5);
          if (uVar12 < ((uint)req_6.cluster_list & 0xffff)) goto _L0;
          auStack_70[1] = (char)resp.payload;
          auStack_70[2] = (char)((uint)resp.payload >> 8);
          auStack_70[3] = (char)((uint)resp.payload >> 0x10);
          rsp.ieee_addr_remote_dev.field_0.u8[0] = (char)req.ieee_addr_of_interest.field_0.u64._0_4_
          ;
          rsp.status = (uint8_t)((uint)resp.payload >> 0x18);
          rsp.ieee_addr_remote_dev.field_0.u8[1] =
               (char)((uint)req.ieee_addr_of_interest.field_0._0_4_ >> 8);
          rsp.ieee_addr_remote_dev.field_0.u8[3] =
               (char)((uint)req.ieee_addr_of_interest.field_0._0_4_ >> 0x18);
          rsp.ieee_addr_remote_dev.field_0.u8[2] =
               (char)((uint)req.ieee_addr_of_interest.field_0._0_4_ >> 0x10);
          rsp.ieee_addr_remote_dev.field_0.u64._5_2_ = 0xffff;
          piVar14 = (int *)nwk_get_extended_address();
          if ((resp.payload == (zdo_packet_payload_t *)*piVar14) &&
             (req.ieee_addr_of_interest.field_0.u64._0_4_ == piVar14[1])) {
            nwk_address_short_by_extended
                      (&resp.payload,(undefined1 *)((int)&rsp.ieee_addr_remote_dev.field_0 + 5));
          }
          else {
            puVar6 = (undefined2 *)nwk_neighbor_table_get_by_extended(&resp.payload);
            if ((puVar6 != (undefined2 *)0x0) && ((*(uint *)(puVar6 + 6) & 3) == 2)) {
              nwk_address_short_by_ref
                        (*puVar6,(undefined1 *)((int)&rsp.ieee_addr_remote_dev.field_0 + 5));
            }
          }
          uVar27 = (undefined1)((uint)resp.payload >> 8);
          uVar28 = (undefined1)((uint)resp.payload >> 0x10);
          uVar35 = (uint8_t)((uint)resp.payload >> 0x18);
          uVar29 = (undefined1)((uint)req.ieee_addr_of_interest.field_0._0_4_ >> 8);
          uVar30 = (undefined1)((uint)req.ieee_addr_of_interest.field_0._0_4_ >> 0x10);
          uVar31 = (undefined1)((uint)req.ieee_addr_of_interest.field_0._0_4_ >> 0x18);
          if ((uint)rsp.ieee_addr_remote_dev.field_0.u64._3_4_ >> 0x10 == 0xffff) {
            if (0xfff7 < *(ushort *)((int)arg + 2)) goto _L0;
            auStack_70[1] = (char)resp.payload;
            auStack_70[0] = 0x81;
            auStack_70[2] = uVar27;
            auStack_70[3] = uVar28;
            rsp.ieee_addr_remote_dev.field_0.u8[0] =
                 (char)req.ieee_addr_of_interest.field_0.u64._0_4_;
            rsp.status = uVar35;
            rsp.ieee_addr_remote_dev.field_0.u8[1] = uVar29;
            rsp.ieee_addr_remote_dev.field_0.u8[3] = uVar31;
            rsp.ieee_addr_remote_dev.field_0.u8[2] = uVar30;
            rsp.ieee_addr_remote_dev.field_0.u64._5_2_ = 0xffff;
          }
          else {
            if (req.ieee_addr_of_interest.field_0.u8[4] == '\0') {
              auStack_70[0] = '\0';
            }
            else {
              if (req.ieee_addr_of_interest.field_0.u8[4] == '\x01') {
                iVar15 = nwk_is_device_zczr();
                if (iVar15 != 0) {
                  auStack_70 = (undefined1  [4])((uint)auStack_70 & 0xffffff00);
                  puVar16 = (undefined4 *)nwk_get_extended_address();
                  uVar19 = *puVar16;
                  uVar3 = puVar16[1];
                  auStack_70[1] = (char)*(undefined3 *)puVar16;
                  auStack_70[2] = (char)((uint)uVar19 >> 8);
                  auStack_70[3] = (char)((uint)uVar19 >> 0x10);
                  rsp.ieee_addr_remote_dev.field_0.u8[0] = (char)*(undefined3 *)(puVar16 + 1);
                  rsp.status = (uint8_t)((uint)uVar19 >> 0x18);
                  rsp.ieee_addr_remote_dev.field_0.u8[1] = (char)((uint)uVar3 >> 8);
                  rsp.ieee_addr_remote_dev.field_0.u8[2] = (char)((uint)uVar3 >> 0x10);
                  rsp.ieee_addr_remote_dev.field_0.u8[3] = (char)((uint)uVar3 >> 0x18);
                  uVar11 = nwk_get_short_address();
                  rsp.ieee_addr_remote_dev.field_0.u64._5_2_ = uVar11;
                  uVar12 = nwk_neighbor_table_get_ed_num();
                  uVar12 = uVar12 & 0xff;
                  if (uVar12 != 0) {
                    rsp._12_4_ = calloc(uVar12,2);
                  }
                  puVar6 = (undefined2 *)0x0;
                  rsp._8_4_ = (uint)CONCAT21(rsp.nwk_addr_remote_dev,
                                             req.ieee_addr_of_interest.field_0.u8[5]) << 8;
                  uVar8 = 0;
                  while ((puVar6 = (undefined2 *)nwk_neighbor_table_next(puVar6),
                         puVar6 != (undefined2 *)0x0 && ((rsp._8_4_ & 0xff) < uVar12))) {
                    if ((((uint)rsp._8_4_ >> 8 & 0xff) <= uVar8) &&
                       ((*(uint *)(puVar6 + 6) & 3) == 2)) {
                      nwk_address_short_by_ref(*puVar6,(rsp._8_4_ & 0xff) * 2 + rsp._12_4_);
                      rsp.ieee_addr_remote_dev.field_0.u8[7] = (char)rsp._8_4_ + '\x01';
                    }
                    uVar8 = uVar8 + 1 & 0xff;
                  }
                }
                goto _L0;
              }
              if (0xfff7 < *(ushort *)((int)arg + 2)) goto _L0;
              auStack_70[0] = 0x80;
            }
            auStack_70[1] = (char)resp.payload;
            auStack_70[2] = uVar27;
            auStack_70[3] = uVar28;
            rsp.ieee_addr_remote_dev.field_0.u8[0] =
                 (char)req.ieee_addr_of_interest.field_0.u64._0_4_;
            rsp.status = uVar35;
            rsp.ieee_addr_remote_dev.field_0.u8[1] = uVar29;
            rsp.ieee_addr_remote_dev.field_0.u8[2] = uVar30;
            rsp.ieee_addr_remote_dev.field_0.u8[3] = uVar31;
            nwk_address_short_by_extended
                      (auStack_70 + 1,(undefined1 *)((int)&rsp.ieee_addr_remote_dev.field_0 + 5));
          }
_L0:
          zVar9 = zdo_op_nwk_addr_rsp((zdo_packet_payload_t *)resp.ctx.req_ctx.arg,
                                      req.ieee_addr_of_interest.field_0.u8[4],
                                      (zdp_nwk_addr_rsp_field_t *)auStack_70,true);
          uVar12 = CONCAT31(extraout_var_00,zVar9);
        }
        else {
          resp.payload = (zdo_packet_payload_t *)0x0;
          auStack_70 = (undefined1  [4])0x0;
          rsp._0_4_ = 0;
          rsp.ieee_addr_remote_dev.field_0.u64._3_4_ = 0;
          rsp._8_4_ = 0;
          rsp.num_assoc_dev = '\0';
          rsp.start_index = '\0';
          rsp._14_2_ = 0;
          if (pzVar5 != (zmsg_t *)0x0) {
            req_6.cluster_list = (uint16_t *)((uint)req_6.cluster_list._2_2_ << 0x10);
            uVar12 = zmsg_get_length(pzVar5);
            af_read_le16(pzVar5,(uint16_t *)&req_6.cluster_list,(uint16_t *)&resp.payload);
            af_read_le8(pzVar5,(uint16_t *)&req_6.cluster_list,(uint8_t *)((int)&resp.payload + 2));
            af_read_le8(pzVar5,(uint16_t *)&req_6.cluster_list,(uint8_t *)((int)&resp.payload + 3));
            if (((uint)req_6.cluster_list & 0xffff) <= uVar12) {
              uVar12 = (uint)resp.payload & 0xffff;
              auStack_70[1] = 0xff;
              auStack_70[2] = 0xff;
              auStack_70[3] = 0xff;
              rsp._0_4_ = 0xffffffff;
              rsp.ieee_addr_remote_dev.field_0.u8[3] = 0xff;
              uVar8 = nwk_get_short_address();
              if (uVar12 == uVar8) {
                nwk_address_extended_by_short(auStack_70 + 1);
              }
              else {
                puVar6 = (undefined2 *)nwk_neighbor_table_get_by_short((uint)resp.payload & 0xffff);
                if ((puVar6 != (undefined2 *)0x0) && ((*(uint *)(puVar6 + 6) & 3) == 2)) {
                  nwk_address_extended_by_ref(*puVar6,auStack_70 + 1);
                }
              }
              if (((rsp._0_4_ << 0x18 | (uint)auStack_70 >> 8) == 0xffffffff) &&
                 ((rsp.ieee_addr_remote_dev.field_0.u64._3_4_ << 0x18 | (uint)rsp._0_4_ >> 8) ==
                  0xffffffff)) {
                auStack_70[0] = 0x81;
                rsp.ieee_addr_remote_dev.field_0.u64._5_2_ = resp.payload._0_2_;
              }
              else {
                if (resp.payload._2_1_ == '\0') {
                  auStack_70 = (undefined1  [4])((uint)(uint3)auStack_70._1_3_ << 8);
                  rsp.ieee_addr_remote_dev.field_0.u64._5_2_ = resp.payload._0_2_;
                  nwk_address_extended_by_short(auStack_70 + 1);
                }
                else if (resp.payload._2_1_ == '\x01') {
                  auStack_70 = (undefined1  [4])((uint)(uint3)auStack_70._1_3_ << 8);
                  puVar16 = (undefined4 *)nwk_get_extended_address();
                  uVar19 = *puVar16;
                  uVar3 = puVar16[1];
                  auStack_70[1] = (char)*(undefined3 *)puVar16;
                  auStack_70[2] = (char)((uint)uVar19 >> 8);
                  rsp.ieee_addr_remote_dev.field_0.u8[3] = (char)((uint)uVar3 >> 0x18);
                  auStack_70[3] = (char)((uint)uVar19 >> 0x10);
                  rsp.ieee_addr_remote_dev.field_0.u8[0] = (char)*(undefined3 *)(puVar16 + 1);
                  rsp.status = (uint8_t)((uint)uVar19 >> 0x18);
                  rsp.ieee_addr_remote_dev.field_0.u8[1] = (char)((uint)uVar3 >> 8);
                  rsp.ieee_addr_remote_dev.field_0.u8[2] = (char)((uint)uVar3 >> 0x10);
                  uVar11 = nwk_get_short_address();
                  rsp.ieee_addr_remote_dev.field_0.u64._5_2_ = uVar11;
                  rsp._8_4_ = (uint)CONCAT21(rsp.nwk_addr_remote_dev,resp.payload._3_1_) << 8;
                  iVar15 = nwk_is_device_zczr();
                  if (iVar15 != 0) {
                    uVar12 = nwk_neighbor_table_get_ed_num();
                    if ((uVar12 & 0xff) != 0) {
                      rsp._12_4_ = calloc(uVar12 & 0xff,2);
                    }
                    iVar15 = 0;
                    uVar12 = 0;
                    while (iVar15 = nwk_child_table_next(iVar15), iVar15 != 0) {
                      if ((*(uint *)(iVar15 + 0xc) & 0x3c0) == 0x40) {
                        if (((uint)rsp._8_4_ >> 8 & 0xff) <= uVar12) {
                          puVar6 = (undefined2 *)(rsp._12_4_ + (rsp._8_4_ & 0xff) * 2);
                          rsp.ieee_addr_remote_dev.field_0.u8[7] = (char)rsp._8_4_ + '\x01';
                          uVar11 = nwk_neighbor_get_shortaddr();
                          *puVar6 = uVar11;
                        }
                        uVar12 = uVar12 + 1 & 0xff;
                      }
                    }
                  }
                }
                else {
                  auStack_70[0] = 0x80;
                  puVar16 = (undefined4 *)nwk_get_extended_address();
                  uVar19 = *puVar16;
                  uVar3 = puVar16[1];
                  auStack_70[1] = (char)*(undefined3 *)puVar16;
                  auStack_70[2] = (char)((uint)uVar19 >> 8);
                  auStack_70[3] = (char)((uint)uVar19 >> 0x10);
                  rsp.ieee_addr_remote_dev.field_0.u8[0] = (char)*(undefined3 *)(puVar16 + 1);
                  rsp.status = (uint8_t)((uint)uVar19 >> 0x18);
                  rsp.ieee_addr_remote_dev.field_0.u8[1] = (char)((uint)uVar3 >> 8);
                  rsp.ieee_addr_remote_dev.field_0.u8[2] = (char)((uint)uVar3 >> 0x10);
                  rsp.ieee_addr_remote_dev.field_0.u8[3] = (char)((uint)uVar3 >> 0x18);
                  uVar11 = nwk_get_short_address();
                  rsp.ieee_addr_remote_dev.field_0.u64._5_2_ = uVar11;
                }
              }
              zVar9 = zdo_op_ieee_addr_rsp
                                ((zdo_packet_payload_t *)resp.ctx.req_ctx.arg,resp.payload._2_1_,
                                 (zdp_ieee_addr_rsp_field_t *)auStack_70,true);
              uVar12 = CONCAT31(extraout_var_01,zVar9);
              goto _L0;
            }
          }
_L0:
          uVar12 = 0xfe;
        }
_L0:
        pvVar7 = (void *)rsp._12_4_;
        if (rsp._12_4_ != 0) goto _L0;
        goto _L0;
      }
      req_3.nwk_addr_of_interest = 0;
      req_6.cluster_list = (uint16_t *)0x0;
      _offset = 0;
      uStack_ac = 0;
      uStack_a8 = 0;
      uStack_a4 = 0;
      if ((*(zdo_packet_payload_t **)((int)arg + 0x14) == (zdo_packet_payload_t *)0x0) ||
         (zVar9 = zdo_op_active_ep_req(*(zdo_packet_payload_t **)((int)arg + 0x14),&req_3,false),
         val = req_3, CONCAT31(extraout_var_03,zVar9) != 0)) goto _L0;
      unaff_s4 = (zdo_packet_user_ctx_t)(uint)req_3.nwk_addr_of_interest;
      if ((zdo_packet_user_ctx_t)0xfff7 < unaff_s4) goto _L0;
      req_6.cluster_list = (uint16_t *)CONCAT22(req_3.nwk_addr_of_interest,req_6.cluster_list._0_2_)
      ;
      pvVar17 = (zdo_packet_user_ctx_t)nwk_get_short_address();
      pvVar7 = (void *)0x0;
      if (unaff_s4 != pvVar17) {
        iVar15 = nwk_is_device_zed();
        pvVar7 = (void *)0x80;
        if (iVar15 == 0) {
          puVar6 = (undefined2 *)0x0;
          do {
            do {
              puVar6 = (undefined2 *)nwk_neighbor_table_next(puVar6);
              if (puVar6 == (undefined2 *)0x0) goto _L0;
            } while ((*(uint *)(puVar6 + 6) & 3) != 2);
            auStack_70._0_2_ = 0xffff;
            nwk_address_short_by_ref(*puVar6,auStack_70);
          } while (req_3.nwk_addr_of_interest != auStack_70._0_2_);
_L0:
          pvVar7 = (void *)0x81;
        }
      }
      req_6.cluster_list = (uint16_t *)CONCAT31(req_6.cluster_list._1_3_,(uint8_t)pvVar7);
      _offset = 0;
      uStack_ac = 0;
      uStack_a8 = 0;
      uStack_a4 = 0;
      if ((pvVar7 == (void *)0x0) &&
         (__src = (uint16_t *)af_get_node_desc(), __src != (uint16_t *)0x0)) {
        memcpy(&offset,__src,0x10);
        uVar36 = *__src;
        arg = (void *)(uint)(byte)__src[1];
        val_05 = __src[2];
        uVar35 = (uint8_t)__src[3];
        val_04 = __src[4];
        val_03 = __src[5];
        val_02 = __src[6];
        val_01 = (uint8_t)__src[7];
      }
      else {
        val_01 = '\0';
        uVar35 = '\0';
        val_02 = 0;
        val_03 = 0;
        val_04 = 0;
        val_05 = 0;
        uVar36 = 0;
        arg = (void *)0x0;
      }
      pvStack_74 = resp.ctx.req_ctx.arg;
      if (resp.ctx.req_ctx.arg == (zdo_packet_user_ctx_t)0x0) goto _L0;
      eVar22 = zmsg_append_u8((zmsg_t *)resp.ctx.req_ctx.arg,(uint8_t)pvVar7);
      if ((eVar22 == 0) &&
         (eVar22 = zmsg_append_le16((zmsg_t *)resp.ctx.req_ctx.arg,val.nwk_addr_of_interest),
         eVar22 == 0)) {
        if (pvVar7 != (void *)0x0) goto _L0;
        eVar22 = zmsg_append_le16((zmsg_t *)resp.ctx.req_ctx.arg,uVar36);
        if ((((eVar22 != 0) ||
             (eVar22 = zmsg_append_u8((zmsg_t *)resp.ctx.req_ctx.arg,(uint8_t)arg), eVar22 != 0)) ||
            ((eVar22 = zmsg_append_le16((zmsg_t *)resp.ctx.req_ctx.arg,val_05), eVar22 != 0 ||
             (((eVar22 = zmsg_append_u8((zmsg_t *)resp.ctx.req_ctx.arg,uVar35), eVar22 != 0 ||
               (eVar22 = zmsg_append_le16((zmsg_t *)resp.ctx.req_ctx.arg,val_04), eVar22 != 0)) ||
              (eVar22 = zmsg_append_le16((zmsg_t *)resp.ctx.req_ctx.arg,val_03), eVar22 != 0))))))
           || (eVar22 = zmsg_append_le16((zmsg_t *)resp.ctx.req_ctx.arg,val_02), eVar22 != 0))
        goto _L0;
        iVar15 = zmsg_append_u8((zmsg_t *)resp.ctx.req_ctx.arg,val_01);
        goto _L0;
      }
_L0:
      uVar12 = 0x8a;
    }
    else {
      if (uVar1 == 0x15) {
        pzVar5 = *(zmsg_t **)((int)arg + 0x14);
        req_8.nwk_addr_of_interest = 0;
        if (pzVar5 != (zmsg_t *)0x0) {
          auStack_70 = (undefined1  [4])((uint)(ushort)auStack_70._2_2_ << 0x10);
          uVar12 = zmsg_get_length(pzVar5);
          af_read_le16(pzVar5,(uint16_t *)auStack_70,&req_8.nwk_addr_of_interest);
          if (((uint)auStack_70 & 0xffff) <= uVar12) {
            iVar15 = af_get_node_desc();
            if (iVar15 == 0) goto _L0;
            pvStack_74 = (zdo_packet_user_ctx_t)
                         ((*(ushort *)(iVar15 + 10) & req_8.nwk_addr_of_interest) & 0x1ff);
            if (*(ushort *)(iVar15 + 10) >> 9 == req_8.nwk_addr_of_interest >> 9) {
              pvStack_74 = (zdo_packet_user_ctx_t)
                           ((uint)pvStack_74 | req_8.nwk_addr_of_interest & 0xfffffe00);
            }
            if (pvStack_74 == (zdo_packet_user_ctx_t)0x0) goto _L0;
            pvVar7 = resp.ctx.req_ctx.arg;
            if (resp.ctx.req_ctx.arg == (zdo_packet_user_ctx_t)0x0) goto _L0;
            eVar22 = zmsg_append_u8((zmsg_t *)resp.ctx.req_ctx.arg,'\0');
            if (eVar22 != 0) goto _L0;
            uVar36 = (uint16_t)pvStack_74;
_L0:
            iVar15 = zmsg_append_le16((zmsg_t *)resp.ctx.req_ctx.arg,uVar36);
_L0:
            if (iVar15 == 0) goto _L0;
            goto _L0;
          }
        }
      }
      else if (uVar1 < 0x16) {
        if (uVar1 == 6) {
          pzVar5 = *(zmsg_t **)((int)arg + 0x14);
          req_5.nwk_addr_of_interest = 0;
          req_5.endpoint = '\0';
          req_5._3_1_ = 0;
          req_6.nwk_addr_of_interest = 0;
          req_6.profile_id = 0;
          req_6.num_in_clusters = '\0';
          req_6.num_out_clusters = '\0';
          req_6._6_2_ = 0;
          if (pzVar5 == (zmsg_t *)0x0) {
_L0:
            uVar12 = 0xfe;
          }
          else {
            auStack_70 = (undefined1  [4])((uint)(ushort)auStack_70._2_2_ << 0x10);
            uVar8 = zmsg_get_length(pzVar5);
            af_read_le16(pzVar5,(uint16_t *)auStack_70,&req_5.nwk_addr_of_interest);
            af_read_le16(pzVar5,(uint16_t *)auStack_70,(uint16_t *)&req_5.endpoint);
            af_read_le8(pzVar5,(uint16_t *)auStack_70,(uint8_t *)&req_6);
            __nmemb = req_6._0_4_ & 0xff;
            uVar33 = 0;
            pvVar18 = calloc(__nmemb,2);
            req_6._4_4_ = pvVar18;
            if (pvVar18 == (void *)0x0) {
              req_6.num_in_clusters = '\0';
              req_6.num_out_clusters = '\0';
              req_6._6_2_ = 0;
              if (__nmemb != 0) goto _L0;
            }
            else {
              for (; pvVar18 = (void *)req_6._4_4_, uVar33 < (req_6._0_4_ & 0xff);
                  uVar33 = uVar33 + 1 & 0xff) {
                af_read_le16(pzVar5,(uint16_t *)auStack_70,(uint16_t *)(req_6._4_4_ + uVar33 * 2));
              }
            }
            req_6._4_4_ = pvVar18;
            af_read_le8(pzVar5,(uint16_t *)auStack_70,
                        (uint8_t *)((int)&req_6.nwk_addr_of_interest + 1));
            req_6._4_4_ = mm_realloc(req_6._4_4_,
                                     (req_6._0_4_ & 0xff) + ((uint)req_6._0_4_ >> 8 & 0xff),2);
            uVar33 = req_6._0_4_ & 0xff;
            if (req_6._4_4_ == 0) {
              if (((uint)req_6._0_4_ >> 8 & 0xff) + uVar33 != 0) goto _L0;
            }
            else {
              for (; uVar33 < (req_6._0_4_ & 0xff) + ((uint)req_6._0_4_ >> 8 & 0xff);
                  uVar33 = uVar33 + 1 & 0xff) {
                af_read_le16(pzVar5,(uint16_t *)auStack_70,(uint16_t *)(req_6._4_4_ + uVar33 * 2));
              }
            }
            if (uVar8 < ((uint)auStack_70 & 0xffff)) goto _L0;
            val_00 = req_5.nwk_addr_of_interest;
            if (0xfff7 < req_5.nwk_addr_of_interest) {
              val_00 = nwk_get_short_address();
            }
            memset(auStack_70,0,0x40);
            uVar8 = (uint)req_5 & 0xffff;
            uVar33 = nwk_get_short_address();
            if ((uVar8 == uVar33) || (0xfff7 < ((uint)req_5 & 0xffff))) {
              pvStack_74 = (zdo_packet_user_ctx_t)0x0;
              puVar20 = (undefined1 *)0x0;
_L0:
              while (puVar20 = (undefined1 *)af_get_next_simple_desc(puVar20),
                    puVar20 != (undefined1 *)0x0) {
                if ((*(short *)(puVar20 + 2) == req_5._2_2_) || (req_5._2_2_ == -1)) {
                  for (uVar8 = 0; (uVar8 & 0xff) < (uint)(byte)puVar20[7]; uVar8 = uVar8 + 1) {
                    uVar33 = 0;
                    while ((uVar33 & 0xff) < (req_6._0_4_ & 0xff)) {
                      uVar33 = uVar33 + 1;
                      if (*(short *)(uVar8 * 2 + *(int *)(puVar20 + 0xc)) ==
                          *(short *)(uVar33 * 2 + req_6._4_4_ + -2)) goto _L0;
                    }
                  }
                  psVar32 = (short *)(*(int *)(puVar20 + 0xc) + (uint)(byte)puVar20[7] * 2);
                  for (cVar10 = '\0'; puVar20[8] != cVar10; cVar10 = cVar10 + '\x01') {
                    psVar24 = (short *)(req_6._4_4_ + (req_6._0_4_ & 0xff) * 2);
                    for (cVar25 = '\0'; req_6.nwk_addr_of_interest._1_1_ != cVar25;
                        cVar25 = cVar25 + '\x01') {
                      sVar2 = *psVar24;
                      psVar24 = psVar24 + 1;
                      if (*psVar32 == sVar2) goto _L0;
                    }
                    psVar32 = psVar32 + 1;
                  }
                }
              }
              if ((pvStack_74 == (zdo_packet_user_ctx_t)0x0) &&
                 (0xfff7 < req_5.nwk_addr_of_interest)) goto _L0;
              arg = (void *)0x0;
              goto _L0;
            }
            iVar15 = nwk_is_device_zed();
            if (iVar15 == 0) {
              iVar15 = 0;
              do {
                iVar15 = nwk_child_table_next(iVar15);
                if (iVar15 == 0) {
                  arg = (void *)0x81;
                  pvStack_74 = (zdo_packet_user_ctx_t)0x0;
                  goto _L0;
                }
              } while (((*(uint *)(iVar15 + 0xc) & 0x3c0) != 0x40) ||
                      (uVar33 = (uint)req_5 & 0xffff, uVar8 = nwk_neighbor_get_shortaddr(),
                      uVar33 != uVar8));
              pvStack_74 = (zdo_packet_user_ctx_t)0x0;
              arg = (void *)0x89;
            }
            else {
              if (0xfff7 < *(ushort *)((int)arg + 2)) goto _L0;
              pvStack_74 = (zdo_packet_user_ctx_t)0x0;
              arg = (void *)0x80;
            }
_L0:
            unaff_s4 = resp.ctx.req_ctx.arg;
            if (resp.ctx.req_ctx.arg == (zdo_packet_user_ctx_t)0x0) goto _L0;
            eVar22 = zmsg_append_u8((zmsg_t *)resp.ctx.req_ctx.arg,(uint8_t)arg);
            if ((((eVar22 != 0) ||
                 (eVar22 = zmsg_append_le16((zmsg_t *)resp.ctx.req_ctx.arg,val_00), eVar22 != 0)) ||
                (eVar22 = zmsg_append_u8((zmsg_t *)resp.ctx.req_ctx.arg,(uint8_t)pvStack_74),
                eVar22 != 0)) ||
               (((arg == (void *)0x0 && (pvStack_74 != (zdo_packet_user_ctx_t)0x0)) &&
                (iVar15 = zmsg_append_bytes(resp.ctx.req_ctx.arg,pvStack_74,auStack_70), iVar15 != 0
                )))) {
              uVar12 = 0x8a;
            }
          }
          if (req_6._4_4_ != 0) {
            mm_free();
          }
          goto _L0;
        }
        if (uVar1 != 0x13) goto _L529;
        req_5 = (zdp_simple_desc_req_field_t)((uint)req_5 & 0xffff0000);
        auStack_70 = (undefined1  [4])0x0;
        rsp._0_4_ = 0;
        rsp.ieee_addr_remote_dev.field_0.u64._3_4_ = 0;
        if (*(int *)((int)arg + 0x14) != 0) {
          uVar12 = zmsg_get_length();
          af_read_le16(*(zmsg_t **)((int)arg + 0x14),&req_5.nwk_addr_of_interest,
                       (uint16_t *)(rsp.ieee_addr_remote_dev.field_0.u8 + 3));
          af_read_bytes(*(zmsg_t **)((int)arg + 0x14),&req_5.nwk_addr_of_interest,8,auStack_70);
          af_read_le8(*(zmsg_t **)((int)arg + 0x14),&req_5.nwk_addr_of_interest,
                      rsp.ieee_addr_remote_dev.field_0.u8 + 5);
          if (((uint)req_5 & 0xffff) <= uVar12) {
            puVar23 = (uint *)nwk_get_extended_address();
            if ((auStack_70 != (undefined1  [4])*puVar23) || (rsp._0_4_ != puVar23[1])) {
              ieee_addr.u64 = nwk_is_device_zczr();
              if (extraout_a0 != 0) {
                req_6.cluster_list = (uint16_t *)((uint)req_6.cluster_list & 0xffff0000);
                ieee_addr.u64 =
                     nwk_address_update(auStack_70,
                                        rsp.ieee_addr_remote_dev.field_0.u64._3_4_ & 0xffff,
                                        &req_6.cluster_list);
                if (extraout_a0_00 == 0xd) {
                  resp.payload._0_2_ =
                       CONCAT11((char)rsp.ieee_addr_remote_dev.field_0.u64._3_4_,0xd);
                  resp.payload = (zdo_packet_payload_t *)
                                 CONCAT13(0,CONCAT12((char)((uint)rsp.ieee_addr_remote_dev.field_0.
                                                                  _3_4_ >> 8),resp.payload._0_2_));
                  nwk_send_status(0xfffd,&resp.payload);
                  nwk_handle_network_status_local(&resp.payload);
                  goto _L0;
                }
              }
              zdo_device_annce_indication
                        ((ezb_extaddr_t)ieee_addr,auStack_70._0_2_,(uint8_t)rsp._0_4_);
            }
          }
        }
      }
      else {
        if (uVar1 != 0x1f) {
_L529:
          uVar12 = 0x84;
          goto _L0;
        }
        resp.payload = (zdo_packet_payload_t *)((uint)resp.payload & 0xffff0000);
        auStack_70 = (undefined1  [4])0x0;
        rsp._0_4_ = 0;
        rsp.ieee_addr_remote_dev.field_0.u64._3_4_ =
             rsp.ieee_addr_remote_dev.field_0.u64._3_4_ & 0xffffff00;
        if ((*(int *)((int)arg + 0x14) != 0) && (iVar15 = nwk_is_device_zed(), iVar15 == 0)) {
          uVar12 = zmsg_get_length(*(undefined4 *)((int)arg + 0x14));
          af_read_le8(*(zmsg_t **)((int)arg + 0x14),(uint16_t *)&resp.payload,auStack_70);
          if (((uint)resp.payload & 0xffff) <= uVar12) {
            if ((0xfff7 < *(ushort *)((int)arg + 2)) &&
               (iVar15 = core_globals_get(), *(char *)(iVar15 + 0x16) != '\0')) {
              uVar12 = random_noncrypto_range_u32(0,0x2711);
              iVar15 = core_globals_get();
              *(char *)(iVar15 + 0x16) = (char)(uVar12 / 1000) + '\n';
            }
            zmsg_append_u8((zmsg_t *)resp.ctx.req_ctx.arg,'\0');
            cVar10 = '\0';
            for (uVar8 = 0; uVar8 < ((uint)auStack_70 & 0xff); uVar8 = uVar8 + 1 & 0xff) {
              af_read_bytes(*(zmsg_t **)((int)arg + 0x14),(uint16_t *)&resp.payload,8,auStack_70 + 1
                           );
              iVar15 = nwk_neighbor_table_get_by_extended(auStack_70 + 1);
              if (((iVar15 != 0) && ((*(uint *)(iVar15 + 0xc) & 3) == 2)) &&
                 (*(int *)(iVar15 + 0x14) << 7 < 0)) {
                uVar12 = zmsg_append_bytes(resp.ctx.req_ctx.arg,8,auStack_70 + 1);
                uVar12 = uVar12 & 0xff;
                if (uVar12 != 0) goto _L0;
                cVar10 = cVar10 + '\x01';
              }
            }
            if (cVar10 != '\0') {
              req_6.cluster_list = (uint16_t *)CONCAT31(req_6.cluster_list._1_3_,cVar10);
              ppuVar26 = &req_6.cluster_list;
              uVar19 = 0;
              goto _L528;
            }
          }
        }
      }
_L0:
      uVar12 = 0xfe;
    }
  }
_L0:
  zdo_packet_free(auStack_a0);
  goto _L0;
_L0:
  auStack_70[(int)pvStack_74] = *puVar20;
  pvStack_74 = (zdo_packet_user_ctx_t)((int)pvStack_74 + 1U & 0xff);
  goto _L0;
_L0:
  if (pvVar7 <= arg) goto _L0;
  uVar8 = (uVar8 & 0xff) + 2;
  eVar22 = zmsg_append_le16((zmsg_t *)resp.ctx.req_ctx.arg,
                            *(uint16_t *)((int)arg * 2 + (int)pvStack_74));
  if (eVar22 != 0) goto _L0;
  arg = (void *)((int)arg + 1U & 0xff);
  goto _L0;
_L0:
  auStack_70[0] = (char)uVar8;
  ppuVar26 = (uint16_t **)auStack_70;
_L528:
  zmsg_write_bytes(resp.ctx.req_ctx.arg,uVar19,1,ppuVar26);
_L0:
  uVar12 = zdo_packet_send(auStack_a0);
_L0:
  return (zdp_status_t)uVar12;
}

