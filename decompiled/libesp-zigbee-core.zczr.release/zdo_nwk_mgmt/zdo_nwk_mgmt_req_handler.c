/*
 * Last changed at upstream commit 9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * https://github.com/espressif/esp-zigbee-sdk/commit/9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * Upstream date: 2026-07-01 11:36:50 +0800
 * Upstream subject: change: update esp-zigbee-lib (9401bce7)
 * Source: libesp-zigbee-core.zczr.release -> zdo_nwk_mgmt.o -> zdo_nwk_mgmt_req_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

zdp_status_t zdo_nwk_mgmt_req_handler(void *arg)

{
  undefined2 uVar1;
  undefined2 uVar2;
  bool bVar3;
  ushort uVar4;
  uint uVar5;
  undefined4 uVar6;
  zdp_status_t zVar7;
  uint uVar8;
  undefined3 extraout_var;
  undefined2 *puVar9;
  ezb_err_t eVar10;
  zmsg_t *pzVar11;
  int *piVar12;
  zdo_packet_req_callback_t p_Var13;
  undefined1 *puVar14;
  byte *pbVar15;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  int iVar16;
  undefined3 extraout_var_02;
  void *pvVar17;
  uint8_t uVar18;
  undefined2 *puVar19;
  byte bVar20;
  byte bVar21;
  zmsg_t *pzVar22;
  uint8_t val;
  uint uVar23;
  uint uVar24;
  uint uVar25;
  byte abStack_98 [4];
  zdp_nwk_mgmt_bind_req_field_t req_2;
  undefined1 auStack_93 [3];
  channel_page_t iface_supported_1;
  undefined4 uStack_8c;
  zdp_nwk_mgmt_nwk_update_req_field_t req;
  channel_page_t iface_supported;
  undefined1 auStack_70 [4];
  zdo_packet_t resp;
  uint16_t offset;
  undefined2 *puStack_50;
  
  memset(auStack_70,0,0x18);
  if (arg == (void *)0x0) {
    uVar8 = 0x80;
    goto _L0;
  }
  uVar8 = zdo_packet_response_init(auStack_70,arg,*(ushort *)((int)arg + 6) | 0x8000);
  if (uVar8 != 0) goto _L0;
  uVar4 = *(ushort *)((int)arg + 6);
  if (uVar4 == 0x34) {
    pzVar22 = *(zmsg_t **)((int)arg + 0x14);
    resp.payload = (zdo_packet_payload_t *)0x0;
    req.nwk_mgmt_addr = 0;
    req._10_2_ = 0;
    if (pzVar22 != (zmsg_t *)0x0) {
      uStack_8c = (uint)uStack_8c._2_2_ << 0x10;
      _req_2 = (uint)(uint3)auStack_93 << 8;
      uVar8 = zmsg_get_length(pzVar22);
      af_read_bytes(pzVar22,(uint16_t *)&uStack_8c,8,(uint8_t *)&resp.payload);
      af_read_le8(pzVar22,(uint16_t *)&uStack_8c,&req_2.start_index);
      if ((uStack_8c & 0xffff) <= uVar8) {
        pzVar22 = (zmsg_t *)(uint)*(ushort *)((int)arg + 4);
        bVar3 = true;
        bVar20 = req_2.start_index >> 7;
        puStack_50._0_2_ = CONCAT11(bVar20,req_2.start_index >> 6) & 0xff01;
        pzVar11 = (zmsg_t *)nwk_get_short_address();
        if (resp.payload != (zdo_packet_payload_t *)0x0) {
          piVar12 = (int *)nwk_get_extended_address();
          bVar3 = resp.payload == (zdo_packet_payload_t *)*piVar12 && piVar12[1] == 0;
        }
        if (((pzVar22 != pzVar11) &&
            (iVar16 = nwk_validate_leave_request
                                (*(undefined2 *)((int)arg + 4),*(undefined2 *)((int)arg + 2),bVar20)
            , iVar16 == 0)) &&
           ((iVar16 = nwk_neighbor_table_get_by_extended(&resp.payload), iVar16 == 0 ||
            ((*(uint *)(iVar16 + 0xc) & 0x3c0) != 0x40)))) {
          uVar18 = 0x84;
          if (resp.ctx.req_ctx.arg == (zdo_packet_user_ctx_t)0x0) goto _L0;
_L0:
          eVar10 = zmsg_append_u8((zmsg_t *)resp.ctx.req_ctx.arg,uVar18);
          if (eVar10 != 0) goto _L0;
_L0:
          uVar8 = zdo_packet_send(auStack_70);
          goto _L0;
        }
        p_Var13 = (zdo_packet_req_callback_t)zdo_create_mgmt_req(0x34);
        if (p_Var13 != (zdo_packet_req_callback_t)0x0) {
          puVar14 = (undefined1 *)zdo_mgmt_req_get_param();
          *puVar14 = (char)resp.payload;
          puVar14[1] = (char)((uint)resp.payload >> 8);
          puVar14[3] = (char)((uint)resp.payload >> 0x18);
          puVar14[4] = 0;
          puVar14[5] = 0;
          puVar14[2] = (char)((uint)resp.payload >> 0x10);
          puVar14[6] = 0;
          puVar14[7] = 0;
          iVar16 = zdo_mgmt_req_get_param(p_Var13);
          *(byte *)(iVar16 + 8) =
               *(byte *)(iVar16 + 8) & 0xfd | (byte)(((ushort)puStack_50 & 1) << 1);
          iVar16 = zdo_mgmt_req_get_param(p_Var13);
          *(byte *)(iVar16 + 8) = *(byte *)(iVar16 + 8) & 0xfe | bVar20;
          if (bVar3) {
            if (resp.ctx.req_ctx.arg == (zdo_packet_user_ctx_t)0x0) goto _L0;
            eVar10 = zmsg_append_u8((zmsg_t *)resp.ctx.req_ctx.arg,'\0');
            if (eVar10 == 0) {
              resp.ctx._0_4_ = zdo_mgmt_leave_rsp_confirm;
              resp.src_addr._0_1_ = 0;
              resp.ctx.req_ctx.cb = p_Var13;
              goto _L0;
            }
          }
          else {
            if (resp.ctx.req_ctx.arg == (zdo_packet_user_ctx_t)0x0) goto _L0;
            eVar10 = zmsg_append_u8((zmsg_t *)resp.ctx.req_ctx.arg,'\0');
            if ((eVar10 == 0) && (pvVar17 = calloc(1,0x18), pvVar17 != (void *)0x0)) {
              uVar8 = zdo_packet_move(auStack_70);
              uVar8 = uVar8 & 0xff;
              if (uVar8 != 0) {
                mm_free(pvVar17);
                goto _L0;
              }
              req._8_4_ = zdo_mgmt_leave_sync_rsp_cb;
              zdo_mgmt_req_set_user_ctx(p_Var13,&req.nwk_mgmt_addr);
              zdo_send_mgmt_req(p_Var13,0);
              goto _L0;
            }
          }
_L0:
          uVar8 = 0x8a;
          goto _L0;
        }
      }
    }
_L0:
    uVar8 = 0xfe;
  }
  else {
    if (uVar4 < 0x35) {
      if (uVar4 == 0x32) {
        pzVar22 = *(zmsg_t **)((int)arg + 0x14);
        _req_2 = (uint)(uint3)auStack_93 << 8;
        if (pzVar22 != (zmsg_t *)0x0) {
          if (*(ushort *)((int)arg + 2) < 0xfff8) goto _L0;
          do {
            val = '\0';
            uVar8 = 0;
            pzVar22 = (zmsg_t *)0x0;
            uVar18 = 0x84;
            uVar24 = 0;
_L0:
            if (resp.ctx.req_ctx.arg != (zdo_packet_user_ctx_t)0x0) {
              eVar10 = zmsg_append_u8((zmsg_t *)resp.ctx.req_ctx.arg,uVar18);
              if (eVar10 == 0) {
                if (uVar18 == '\0') {
                  eVar10 = zmsg_append_u8((zmsg_t *)resp.ctx.req_ctx.arg,val);
                  if (((eVar10 != 0) ||
                      (eVar10 = zmsg_append_u8((zmsg_t *)resp.ctx.req_ctx.arg,(uint8_t)uVar8),
                      eVar10 != 0)) ||
                     (eVar10 = zmsg_append_u8((zmsg_t *)resp.ctx.req_ctx.arg,(uint8_t)uVar24),
                     eVar10 != 0)) goto _L0;
                  if (pzVar22 == (zmsg_t *)0x0) goto _L0;
                  uVar8 = uVar24;
                  if (uVar24 == 0) goto _L0;
                  uVar23 = 0;
                  pzVar11 = pzVar22;
                  goto _L0;
                }
                uVar8 = 0;
              }
              else {
_L0:
                uVar8 = 0x8a;
              }
              if (pzVar22 == (zmsg_t *)0x0) goto _L0;
              goto _L0;
            }
_L0:
            __assert_func(0,0,0,0);
_L0:
            resp.payload = (zdo_packet_payload_t *)((uint)resp.payload & 0xffff0000);
            uVar8 = zmsg_get_length(pzVar22);
            af_read_le8(pzVar22,(uint16_t *)&resp.payload,&req_2.start_index);
            if (uVar8 < ((uint)resp.payload & 0xffff)) goto _L0;
            iVar16 = nwk_is_device_zczr();
          } while (iVar16 == 0);
          uVar8 = zdo_packet_max_available_space(0x8032);
          uVar23 = 0;
          if (4 < uVar8) {
            uVar23 = (int)(uVar8 - 4) / 5 & 0xff;
          }
          iVar16 = 0;
          uVar4 = 0;
          while (iVar16 = nwk_route_table_next(iVar16), iVar16 != 0) {
            uVar4 = uVar4 + 1;
          }
          val = 0xff;
          if (uVar4 < 0xff) {
            iVar16 = 0;
            val = '\0';
            while (iVar16 = nwk_route_table_next(iVar16), iVar16 != 0) {
              val = val + '\x01';
            }
          }
          uVar8 = _req_2 & 0xff;
          pzVar22 = (zmsg_t *)calloc(uVar23,6);
          uVar5 = 0;
          uVar25 = 0;
          if ((pzVar22 != (zmsg_t *)0x0) || (uVar18 = 0x8a, uVar24 = 0, uVar23 == 0)) {
            puVar9 = (undefined2 *)0x0;
            while ((puVar9 = (undefined2 *)nwk_route_table_next(puVar9), puVar9 != (undefined2 *)0x0
                   && (uVar5 < uVar23))) {
              if ((_req_2 & 0xff) <= uVar25) {
                iVar16 = uVar5 * 6;
                uVar2 = puVar9[7];
                uVar1 = puVar9[7];
                uVar5 = uVar5 + 1 & 0xff;
                puVar19 = (undefined2 *)((int)&(pzVar22->node).next + iVar16);
                *puVar19 = *puVar9;
                *(byte *)(puVar19 + 1) =
                     *(byte *)(puVar19 + 1) & 0xc0 | (byte)uVar2 & 7 | (byte)uVar1 & 8 |
                     (byte)puVar9[7] & 0x10 | (byte)puVar9[7] & 0x20;
                puVar19[2] = puVar9[1];
              }
              uVar25 = uVar25 + 1 & 0xff;
            }
            uVar18 = '\0';
            uVar24 = uVar5;
          }
          goto _L0;
        }
      }
      else {
        if (uVar4 != 0x33) {
          if (uVar4 != 0x31) goto _L411;
          zVar7 = zdo_nwk_mgmt_lqi_req_handler((zdo_packet_t *)arg,(zdo_packet_t *)auStack_70);
          uVar8 = CONCAT31(extraout_var,zVar7);
          goto _L0;
        }
        pzVar22 = *(zmsg_t **)((int)arg + 0x14);
        abStack_98[0] = 0;
        _req_2 = 0;
        if (pzVar22 != (zmsg_t *)0x0) {
          resp.payload = (zdo_packet_payload_t *)((uint)resp.payload._2_2_ << 0x10);
          uVar8 = zmsg_get_length(pzVar22);
          af_read_le8(pzVar22,(uint16_t *)&resp.payload,abStack_98);
          if (((uint)resp.payload & 0xffff) <= uVar8) {
            aps_bind_table_iterator_init(0,&resp.payload);
            bVar20 = 0;
            while (((uint)resp.payload & 0xff) == 0) {
              bVar20 = bVar20 + 1;
              aps_bind_table_iterator_next(&resp.payload);
            }
            if ((bVar20 == 0) || (bVar20 <= abStack_98[0])) {
              _req_2 = (uint)CONCAT11(abStack_98[0],bVar20) << 8;
              zVar7 = zdo_op_nwk_mgmt_bind_rsp
                                ((zdo_packet_payload_t *)resp.ctx.req_ctx.arg,
                                 (zdp_nwk_mgmt_bind_rsp_field_t *)&req_2,true);
              uVar8 = CONCAT31(extraout_var_01,zVar7);
            }
            else {
              iVar16 = zdo_packet_max_available_space(0x8033);
              uVar8 = iVar16 - 4U & 0xff;
              uVar24 = uVar8 / 0x15;
              pzVar22 = (zmsg_t *)calloc(uVar24,0x18);
              if ((pzVar22 == (zmsg_t *)0x0) && (0x14 < uVar8)) goto _L0;
              aps_bind_table_iterator_init(0,&resp.payload);
              bVar21 = 0;
              uVar8 = 0;
              while ((((uint)resp.payload & 0xff) == 0 && (uVar8 < uVar24))) {
                if (abStack_98[0] <= bVar21) {
                  iVar16 = nwk_address_extended_by_ref(*_offset,&uStack_8c);
                  if (iVar16 != 0) goto _L0;
                  pvVar17 = memcpy(&pzVar22->node + uVar8 * 3,&uStack_8c,8);
                  *(undefined1 *)((int)pvVar17 + 8) = *(undefined1 *)(_offset + 1);
                  *(undefined2 *)((int)pvVar17 + 10) = _offset[2];
                  uVar2 = *puStack_50;
                  if ((*(byte *)((int)puStack_50 + 5) & 1) == 0) {
                    iVar16 = nwk_address_extended_by_ref(&req.nwk_mgmt_addr);
                    if (iVar16 != 0) goto _L0;
                    *(undefined1 *)(&pzVar22->header + uVar8 * 0xc) = 3;
                    memcpy(&pzVar22->length + uVar8 * 0xc,&req.nwk_mgmt_addr,8);
                    *(undefined1 *)(&pzVar22->flags + uVar8 * 0xc) = *(undefined1 *)(puStack_50 + 1)
                    ;
                  }
                  else {
                    *(undefined1 *)((int)pvVar17 + 0xc) = 1;
                    *(undefined2 *)((int)pvVar17 + 0xe) = uVar2;
                    *(undefined1 *)((int)pvVar17 + 0x16) = 0;
                  }
                  uVar8 = uVar8 + 1 & 0xff;
                }
                bVar21 = bVar21 + 1;
                aps_bind_table_iterator_next(&resp.payload);
              }
              auStack_93[2] = (uint8_t)uVar8;
              _req_2 = (uint)CONCAT12(auStack_93[2],CONCAT11(abStack_98[0],bVar20)) << 8;
              zVar7 = zdo_op_nwk_mgmt_bind_rsp
                                ((zdo_packet_payload_t *)resp.ctx.req_ctx.arg,
                                 (zdp_nwk_mgmt_bind_rsp_field_t *)&req_2,true);
              uVar8 = CONCAT31(extraout_var_02,zVar7);
              if (pzVar22 != (zmsg_t *)0x0) goto _L0;
            }
_L0:
            if (uVar8 == 0) goto _L0;
            goto _L0;
          }
        }
      }
      goto _L0;
    }
    if (uVar4 == 0x36) {
      pzVar22 = *(zmsg_t **)((int)arg + 0x14);
      uStack_8c = (uint)uStack_8c._2_2_ << 0x10;
      if (pzVar22 != (zmsg_t *)0x0) {
        uVar4 = *(ushort *)((int)arg + 2);
        resp.payload = (zdo_packet_payload_t *)((uint)resp.payload._2_2_ << 0x10);
        uVar8 = zmsg_get_length(pzVar22);
        af_read_le8(pzVar22,(uint16_t *)&resp.payload,(uint8_t *)&uStack_8c);
        af_read_le8(pzVar22,(uint16_t *)&resp.payload,(uint8_t *)((int)&uStack_8c + 1));
        if (((uint)resp.payload & 0xffff) <= uVar8) {
          bVar20 = (byte)uStack_8c;
          uStack_8c._0_2_ = CONCAT11(1,(byte)uStack_8c);
          nwk_is_device_zc();
          iVar16 = nwk_is_device_zczr();
          uVar18 = 0x84;
          if (iVar16 != 0) {
            iVar16 = zdo_create_mgmt_req(0x36,0x84);
            uVar18 = 0x80;
            if (iVar16 != 0) {
              pbVar15 = (byte *)zdo_mgmt_req_get_param(0x80);
              if (0xfe < bVar20) {
                bVar20 = 0xfe;
              }
              *pbVar15 = bVar20;
              iVar16 = zdo_send_mgmt_req(iVar16,1);
              uVar18 = (iVar16 != 0) << 7;
            }
          }
          if (uVar4 < 0xfff8) {
            if (resp.ctx.req_ctx.arg == (zdo_packet_user_ctx_t)0x0) {
              pzVar22 = (zmsg_t *)0x36;
              goto _L0;
            }
            goto _L0;
          }
        }
      }
      goto _L0;
    }
    if (uVar4 == 0x38) {
      pzVar22 = *(zmsg_t **)((int)arg + 0x14);
      uStack_8c = 0;
      req.scan_channels = 0;
      req.scan_duration = '\0';
      req.scan_count = '\0';
      req.nwk_update_id = '\0';
      req._7_1_ = 0;
      if (pzVar22 != (zmsg_t *)0x0) {
        uVar4 = *(ushort *)((int)arg + 2);
        uVar8 = zmsg_get_length(pzVar22);
        iVar16 = zmsg_read_bytes(pzVar22,0,4,&uStack_8c);
        if (iVar16 == 0) {
          iVar16 = 0xffff;
        }
        resp.payload = (zdo_packet_payload_t *)CONCAT22(resp.payload._2_2_,(short)iVar16);
        af_read_le8(pzVar22,(uint16_t *)&resp.payload,(uint8_t *)&req);
        if ((byte)req.scan_channels < 6) {
          af_read_le8(pzVar22,(uint16_t *)&resp.payload,(uint8_t *)((int)&req.scan_channels + 1));
        }
        if (0xfd < (byte)req.scan_channels) {
          af_read_le8(pzVar22,(uint16_t *)&resp.payload,(uint8_t *)((int)&req.scan_channels + 2));
          if ((byte)req.scan_channels == -1) {
            af_read_le16(pzVar22,(uint16_t *)&resp.payload,(uint16_t *)&req.scan_duration);
          }
        }
        uVar24 = uStack_8c;
        if (((uint)resp.payload & 0xffff) <= uVar8) {
          uVar8 = req.scan_channels & 0xff;
          uVar23 = uStack_8c & 0x7ffffff;
          if (uVar8 == 0xfe) {
            iVar16 = core_globals_get();
            uVar24 = uVar24 & 0x7ffffff;
            if ((*(int *)(iVar16 + 0xa30) == 0) ||
               (iVar16 = core_globals_get(), uVar24 == *(uint *)(iVar16 + 0xa30))) {
              bVar20 = 0;
              for (uVar8 = uVar24; uVar8 != 0; uVar8 = uVar8 & uVar8 - 1) {
                bVar20 = bVar20 + 1;
              }
              if (bVar20 < 2) {
                iVar16 = 0;
                if (uVar23 < 0x8000000) {
                  iVar16 = 10;
                }
                uVar8 = iVar16 + 1;
                do {
                  if ((uVar24 >> (uVar8 & 0x1f) & 1) != 0) {
                    uVar8 = uVar8 & 0xff;
                    goto _L0;
                  }
                  uVar8 = uVar8 + 1;
                } while ((uVar8 & 0xff) != 0x1b);
                uVar8 = 0xff;
_L0:
                req.nwk_mgmt_addr = 0;
                req._10_2_ = 0;
                iVar16 = nwk_mm_get_pib_attr(0,99,&req.nwk_mgmt_addr,4);
                if ((iVar16 == 0) && (((req._8_4_ & 0x7ffffff) >> (uVar8 & 0x1f) & 1) != 0)) {
                  resp.payload = (zdo_packet_payload_t *)(1 << (uVar8 & 0x1f));
                  nwk_mm_set_pib_attr(0x61,&resp.payload);
                  goto _L0;
                }
              }
_L0:
              uVar8 = 0x80;
            }
            else {
              uVar8 = 0x8d;
            }
          }
          else {
            if (uVar8 == 0xff) {
              iVar16 = aps_secur_is_centralized();
              if ((iVar16 == 0) || (req._4_2_ == 0)) {
                iVar16 = core_globals_get();
                *(uint *)(iVar16 + 8) = uVar23;
                iVar16 = core_globals_get();
                *(undefined2 *)(iVar16 + 0x9dc) = req._4_2_;
              }
              goto _L0;
            }
            if ((5 < uVar8) || (0xfff7 < uVar4)) goto _L0;
            _req_2 = 0;
            nwk_mm_get_pib_attr(0,99,&req_2,4);
            uVar24 = uVar24 & 0x7ffffff;
            uVar8 = 0x86;
            if (uVar24 == (_req_2 & 0x7ffffff & uVar24)) {
              pvVar17 = calloc(1,0x18);
              uVar8 = 0x8a;
              if (pvVar17 != (void *)0x0) {
                uVar8 = zdo_packet_move(auStack_70);
                uVar8 = uVar8 & 0xff;
                if (uVar8 == 0) {
                  uVar6 = *(undefined4 *)((int)pvVar17 + 0x14);
                  req._8_4_ = (uint)CONCAT21(req._10_2_,(byte)req.scan_channels) << 8;
                  memset(&resp.payload,0,0x28);
                  zmsg_add_footer(uVar6,&resp.payload,0x28);
                  nwk_nlme_scan(&req.nwk_mgmt_addr);
                  uVar8 = ezb_err_to_zdp_status();
                  if (uVar8 == 0) goto _L0;
                }
                mm_free(pvVar17);
                if (uVar8 == 0xfe) goto _L0;
              }
            }
          }
          memset(&resp.payload,0,0x28);
          resp.payload = (zdo_packet_payload_t *)CONCAT31(resp.payload._1_3_,(char)uVar8);
          zVar7 = zdo_op_nwk_mgmt_nwk_update_notify
                            ((zdo_packet_payload_t *)resp.ctx.req_ctx.arg,
                             (zdp_nwk_mgmt_nwk_update_notify_field_t *)&resp.payload,true);
          uVar8 = CONCAT31(extraout_var_00,zVar7);
          goto _L0;
        }
      }
      goto _L0;
    }
_L411:
    uVar8 = 0x84;
  }
_L0:
  zdo_packet_free(auStack_70);
_L0:
  return (zdp_status_t)uVar8;
  while( true ) {
    resp.payload = (zdo_packet_payload_t *)
                   CONCAT22(resp.payload._2_2_,*(undefined2 *)&(pzVar11->node).prev);
    iVar16 = zmsg_append_bytes(resp.ctx.req_ctx.arg,2,&resp.payload);
    if (iVar16 != 0) goto _L0;
    uVar23 = uVar23 + 1 & 0xff;
    pzVar11 = (zmsg_t *)((int)&(pzVar11->node).prev + 2);
    uVar8 = 0;
    if (uVar23 == uVar24) break;
_L0:
    uVar2 = *(undefined2 *)((int)&(pzVar11->node).next + 2);
    resp.payload = (zdo_packet_payload_t *)
                   CONCAT22(resp.payload._2_2_,*(undefined2 *)&(pzVar11->node).next);
    iVar16 = zmsg_append_bytes(resp.ctx.req_ctx.arg,2,&resp.payload);
    if ((iVar16 != 0) ||
       (eVar10 = zmsg_append_u8((zmsg_t *)resp.ctx.req_ctx.arg,(byte)uVar2 & 0x3f), eVar10 != 0)) {
_L0:
      uVar8 = 0x8a;
      break;
    }
  }
_L0:
  mm_free(pzVar22);
  goto _L0;
}

