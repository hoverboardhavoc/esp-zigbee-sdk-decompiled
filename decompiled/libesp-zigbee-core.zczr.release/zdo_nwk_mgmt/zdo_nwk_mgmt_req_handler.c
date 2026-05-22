/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.release -> zdo_nwk_mgmt.o -> zdo_nwk_mgmt_req_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

zdp_status_t zdo_nwk_mgmt_req_handler(void *arg)

{
  ushort uVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  zdp_status_t zVar4;
  uint uVar5;
  undefined3 extraout_var;
  int *piVar6;
  zdo_packet_req_callback_t p_Var7;
  undefined1 *puVar8;
  byte *pbVar9;
  ezb_err_t eVar10;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  int iVar11;
  void *pvVar12;
  undefined3 extraout_var_02;
  void *pvVar13;
  int iVar14;
  uint8_t val;
  byte bVar15;
  byte bVar16;
  uint uVar17;
  zmsg_t *pzVar18;
  uint uVar19;
  byte abStack_98 [4];
  zdp_nwk_mgmt_bind_req_field_t req_3;
  byte bStack_93;
  byte bStack_92;
  uint8_t uStack_91;
  channel_page_t iface_supported_1;
  undefined4 uStack_8c;
  zdp_nwk_mgmt_nwk_update_req_field_t req;
  channel_page_t iface_supported;
  undefined1 auStack_70 [4];
  zdo_packet_t resp;
  uint16_t offset;
  undefined4 uStack_50;
  
  memset(auStack_70,0,0x18);
  if (arg == (void *)0x0) {
    uVar5 = 0x80;
    goto _L0;
  }
  uVar5 = zdo_packet_response_init(auStack_70,arg,*(ushort *)((int)arg + 6) | 0x8000);
  if (uVar5 != 0) goto _L0;
  uVar1 = *(ushort *)((int)arg + 6);
  if (uVar1 == 0x34) {
    pzVar18 = *(zmsg_t **)((int)arg + 0x14);
    resp.payload = (zdo_packet_payload_t *)0x0;
    _offset = (undefined2 *)0x0;
    req.nwk_mgmt_addr = 0;
    req._10_2_ = 0;
    if (pzVar18 != (zmsg_t *)0x0) {
      uStack_8c = (uint)uStack_8c._2_2_ << 0x10;
      _req_3 = _req_3 & 0xffffff00;
      uVar5 = zmsg_get_length(pzVar18);
      af_read_bytes(pzVar18,(uint16_t *)&uStack_8c,8,(uint8_t *)&resp.payload);
      af_read_le8(pzVar18,(uint16_t *)&uStack_8c,&req_3.start_index);
      if ((uStack_8c & 0xffff) <= uVar5) {
        uVar1 = *(ushort *)((int)arg + 4);
        pzVar18 = (zmsg_t *)0x1;
        bVar15 = req_3.start_index >> 7;
        uStack_50 = (undefined2 *)(uint)(CONCAT11(bVar15,req_3.start_index >> 6) & 0xff01);
        uVar5 = nwk_get_short_address();
        if (resp.payload != (zdo_packet_payload_t *)0x0) {
          piVar6 = (int *)nwk_get_extended_address();
          pzVar18 = (zmsg_t *)
                    (uint)(resp.payload == (zdo_packet_payload_t *)*piVar6 && piVar6[1] == 0);
        }
        if (uVar1 == uVar5) goto _L0;
        iVar11 = nwk_validate_leave_request
                           (*(undefined2 *)((int)arg + 4),*(undefined2 *)((int)arg + 2),bVar15);
        if (iVar11 != 0) goto _L0;
        iVar11 = nwk_neighbor_table_get_by_extended(&resp.payload);
        if ((iVar11 != 0) && ((*(uint *)(iVar11 + 0xc) & 0x3c0) == 0x40)) goto _L0;
        val = 0x84;
        if (resp.ctx.req_ctx.arg == (zdo_packet_user_ctx_t)0x0) {
_L0:
          do {
            while( true ) {
              __assert_func(0,0,0,0);
_L0:
              p_Var7 = (zdo_packet_req_callback_t)zdo_create_mgmt_req(0x34);
              if (p_Var7 == (zdo_packet_req_callback_t)0x0) goto _L0;
              puVar8 = (undefined1 *)zdo_mgmt_req_get_param();
              *puVar8 = (char)resp.payload;
              puVar8[1] = (char)((uint)resp.payload >> 8);
              puVar8[3] = (char)((uint)resp.payload >> 0x18);
              puVar8[4] = (char)_offset;
              puVar8[5] = (char)((uint)_offset >> 8);
              puVar8[2] = (char)((uint)resp.payload >> 0x10);
              puVar8[6] = (char)((uint)_offset >> 0x10);
              puVar8[7] = (char)((uint)_offset >> 0x18);
              iVar11 = zdo_mgmt_req_get_param(p_Var7);
              *(byte *)(iVar11 + 8) =
                   *(byte *)(iVar11 + 8) & 0xfd | (byte)(((uint)uStack_50 & 1) << 1);
              iVar11 = zdo_mgmt_req_get_param(p_Var7);
              *(byte *)(iVar11 + 8) = *(byte *)(iVar11 + 8) & 0xfe | uStack_50._1_1_ & 1;
              if (pzVar18 != (zmsg_t *)0x0) break;
              if (resp.ctx.req_ctx.arg != (zdo_packet_user_ctx_t)0x0) {
                eVar10 = zmsg_append_u8((zmsg_t *)resp.ctx.req_ctx.arg,'\0');
                if ((eVar10 != 0) || (pvVar12 = calloc(1,0x18), pvVar12 == (void *)0x0)) goto _L0;
                uVar5 = zdo_packet_move(auStack_70);
                uVar5 = uVar5 & 0xff;
                if (uVar5 == 0) {
                  req._8_4_ = zdo_mgmt_leave_sync_rsp_cb;
                  zdo_mgmt_req_set_user_ctx(p_Var7,&req.nwk_mgmt_addr);
                  zdo_send_mgmt_req(p_Var7,0);
                  goto _L0;
                }
                mm_free(pvVar12);
                goto _L0;
              }
            }
          } while (resp.ctx.req_ctx.arg == (zdo_packet_user_ctx_t)0x0);
          eVar10 = zmsg_append_u8((zmsg_t *)resp.ctx.req_ctx.arg,'\0');
          if (eVar10 != 0) goto _L0;
          resp.ctx._0_4_ = zdo_mgmt_leave_rsp_confirm;
          resp.src_addr._0_1_ = 0;
          resp.ctx.req_ctx.cb = p_Var7;
        }
        else {
_L0:
          eVar10 = zmsg_append_u8((zmsg_t *)resp.ctx.req_ctx.arg,val);
          if (eVar10 != 0) {
_L0:
            uVar5 = 0x8a;
            goto _L0;
          }
        }
_L0:
        uVar5 = zdo_packet_send(auStack_70);
        goto _L0;
      }
    }
_L0:
    uVar5 = 0xfe;
  }
  else {
    if (0x34 < uVar1) {
      if (uVar1 == 0x36) {
        pzVar18 = *(zmsg_t **)((int)arg + 0x14);
        uStack_8c = (uint)uStack_8c._2_2_ << 0x10;
        if (pzVar18 != (zmsg_t *)0x0) {
          uVar1 = *(ushort *)((int)arg + 2);
          resp.payload = (zdo_packet_payload_t *)((uint)resp.payload._2_2_ << 0x10);
          uVar5 = zmsg_get_length(pzVar18);
          af_read_le8(pzVar18,(uint16_t *)&resp.payload,(uint8_t *)&uStack_8c);
          af_read_le8(pzVar18,(uint16_t *)&resp.payload,(uint8_t *)((int)&uStack_8c + 1));
          if (((uint)resp.payload & 0xffff) <= uVar5) {
            bVar15 = (byte)uStack_8c;
            uStack_8c._0_2_ = CONCAT11(1,(byte)uStack_8c);
            nwk_is_device_zc();
            iVar11 = nwk_is_device_zczr();
            val = 0x84;
            if (iVar11 != 0) {
              pzVar18 = (zmsg_t *)zdo_create_mgmt_req(0x36,0x84);
              val = 0x80;
              if (pzVar18 != (zmsg_t *)0x0) {
                pbVar9 = (byte *)zdo_mgmt_req_get_param(0x80);
                if (0xfe < bVar15) {
                  bVar15 = 0xfe;
                }
                *pbVar9 = bVar15;
                iVar11 = zdo_send_mgmt_req(pzVar18,1);
                val = (iVar11 != 0) << 7;
              }
            }
            if (uVar1 < 0xfff8) {
              if (resp.ctx.req_ctx.arg == (zdo_packet_user_ctx_t)0x0) goto _L0;
              goto _L0;
            }
          }
        }
      }
      else {
        if (uVar1 != 0x38) goto _L347;
        pzVar18 = *(zmsg_t **)((int)arg + 0x14);
        uStack_8c = 0;
        req.scan_channels = 0;
        req.scan_duration = '\0';
        req.scan_count = '\0';
        req.nwk_update_id = '\0';
        req._7_1_ = 0;
        if (pzVar18 != (zmsg_t *)0x0) {
          uVar1 = *(ushort *)((int)arg + 2);
          uVar5 = zmsg_get_length(pzVar18);
          iVar11 = zmsg_read_bytes(pzVar18,0,4,&uStack_8c);
          if (iVar11 == 0) {
            iVar11 = 0xffff;
          }
          resp.payload = (zdo_packet_payload_t *)CONCAT22(resp.payload._2_2_,(short)iVar11);
          af_read_le8(pzVar18,(uint16_t *)&resp.payload,(uint8_t *)&req);
          if ((byte)req.scan_channels < 6) {
            af_read_le8(pzVar18,(uint16_t *)&resp.payload,(uint8_t *)((int)&req.scan_channels + 1));
          }
          if (0xfd < (byte)req.scan_channels) {
            af_read_le8(pzVar18,(uint16_t *)&resp.payload,(uint8_t *)((int)&req.scan_channels + 2));
            if ((byte)req.scan_channels == -1) {
              af_read_le16(pzVar18,(uint16_t *)&resp.payload,(uint16_t *)&req.scan_duration);
            }
          }
          uVar19 = uStack_8c;
          if (((uint)resp.payload & 0xffff) <= uVar5) {
            uVar5 = req.scan_channels & 0xff;
            uVar17 = uStack_8c & 0x7ffffff;
            if (uVar5 == 0xfe) {
              iVar11 = core_globals_get();
              uVar19 = uVar19 & 0x7ffffff;
              if ((*(int *)(iVar11 + 0xa30) == 0) ||
                 (iVar11 = core_globals_get(), uVar19 == *(uint *)(iVar11 + 0xa30))) {
                bVar15 = 0;
                for (uVar5 = uVar19; uVar5 != 0; uVar5 = uVar5 & uVar5 - 1) {
                  bVar15 = bVar15 + 1;
                }
                if (bVar15 < 2) {
                  iVar11 = 0;
                  if (uVar17 < 0x8000000) {
                    iVar11 = 10;
                  }
                  uVar5 = iVar11 + 1;
                  do {
                    if ((uVar19 >> (uVar5 & 0x1f) & 1) != 0) {
                      uVar5 = uVar5 & 0xff;
                      goto _L0;
                    }
                    uVar5 = uVar5 + 1;
                  } while ((uVar5 & 0xff) != 0x1b);
                  uVar5 = 0xff;
_L0:
                  req.nwk_mgmt_addr = 0;
                  req._10_2_ = 0;
                  iVar11 = nwk_mm_get_pib_attr(0,99,&req.nwk_mgmt_addr,4);
                  if ((iVar11 == 0) && (((req._8_4_ & 0x7ffffff) >> (uVar5 & 0x1f) & 1) != 0)) {
                    resp.payload = (zdo_packet_payload_t *)(1 << (uVar5 & 0x1f));
                    nwk_mm_set_pib_attr(0x61,&resp.payload);
                    goto _L0;
                  }
                }
_L0:
                uVar5 = 0x80;
              }
              else {
                uVar5 = 0x8d;
              }
            }
            else {
              if (uVar5 == 0xff) {
                iVar11 = aps_secur_is_centralized();
                if ((iVar11 == 0) || (req._4_2_ == 0)) {
                  iVar11 = core_globals_get();
                  *(uint *)(iVar11 + 8) = uVar17;
                  iVar11 = core_globals_get();
                  *(undefined2 *)(iVar11 + 0x9dc) = req._4_2_;
                }
                goto _L0;
              }
              if ((5 < uVar5) || (0xfff7 < uVar1)) goto _L0;
              _req_3 = 0;
              nwk_mm_get_pib_attr(0,99,&req_3,4);
              uVar19 = uVar19 & 0x7ffffff;
              uVar5 = 0x86;
              if (uVar19 == (_req_3 & 0x7ffffff & uVar19)) {
                pvVar12 = calloc(1,0x18);
                uVar5 = 0x8a;
                if (pvVar12 != (void *)0x0) {
                  uVar5 = zdo_packet_move(auStack_70);
                  uVar5 = uVar5 & 0xff;
                  if (uVar5 == 0) {
                    uVar3 = *(undefined4 *)((int)pvVar12 + 0x14);
                    req._8_4_ = (uint)CONCAT21(req._10_2_,(byte)req.scan_channels) << 8;
                    memset(&resp.payload,0,0x28);
                    zmsg_add_footer(uVar3,&resp.payload,0x28);
                    nwk_nlme_scan(&req.nwk_mgmt_addr);
                    uVar5 = ezb_err_to_zdp_status();
                    if (uVar5 == 0) goto _L0;
                  }
                  mm_free(pvVar12);
                  if (uVar5 == 0xfe) goto _L0;
                }
              }
            }
            memset(&resp.payload,0,0x28);
            resp.payload = (zdo_packet_payload_t *)CONCAT31(resp.payload._1_3_,(char)uVar5);
            zVar4 = zdo_op_nwk_mgmt_nwk_update_notify
                              ((zdo_packet_payload_t *)resp.ctx.req_ctx.arg,
                               (zdp_nwk_mgmt_nwk_update_notify_field_t *)&resp.payload,true);
            uVar5 = CONCAT31(extraout_var_00,zVar4);
            goto _L0;
          }
        }
      }
      goto _L0;
    }
    if (uVar1 == 0x31) {
      zVar4 = zdo_nwk_mgmt_lqi_req_handler((zdo_packet_t *)arg,(zdo_packet_t *)auStack_70);
      uVar5 = CONCAT31(extraout_var,zVar4);
_L0:
      if (uVar5 == 0) goto _L0;
    }
    else {
      if (uVar1 == 0x33) {
        pzVar18 = *(zmsg_t **)((int)arg + 0x14);
        abStack_98[0] = 0;
        _req_3 = 0;
        if (pzVar18 != (zmsg_t *)0x0) {
          resp.payload = (zdo_packet_payload_t *)((uint)resp.payload._2_2_ << 0x10);
          uVar5 = zmsg_get_length(pzVar18);
          af_read_le8(pzVar18,(uint16_t *)&resp.payload,abStack_98);
          if (((uint)resp.payload & 0xffff) <= uVar5) {
            aps_bind_table_iterator_init(0,&resp.payload);
            bVar15 = 0;
            while (((uint)resp.payload & 0xff) == 0) {
              bVar15 = bVar15 + 1;
              aps_bind_table_iterator_next(&resp.payload);
            }
            if (bVar15 == 0) {
              req_3.start_index = '\0';
              bStack_93 = '\0';
            }
            else {
              if (abStack_98[0] < bVar15) {
                iVar11 = zdo_packet_max_available_space(0x8033);
                uVar5 = iVar11 - 4U & 0xff;
                uVar19 = uVar5 / 0x15;
                pvVar12 = calloc(uVar19,0x18);
                if ((pvVar12 != (void *)0x0) || (uVar5 < 0x15)) {
                  aps_bind_table_iterator_init(0,&resp.payload);
                  bVar16 = 0;
                  uVar5 = 0;
                  while ((((uint)resp.payload & 0xff) == 0 && (uVar5 < uVar19))) {
                    if (abStack_98[0] <= bVar16) {
                      iVar11 = nwk_address_extended_by_ref(*_offset,&uStack_8c);
                      if (iVar11 != 0) goto _L0;
                      iVar11 = uVar5 * 0x18;
                      pvVar13 = memcpy((void *)((int)pvVar12 + iVar11),&uStack_8c,8);
                      *(undefined1 *)((int)pvVar13 + 8) = *(undefined1 *)(_offset + 1);
                      *(undefined2 *)((int)pvVar13 + 10) = _offset[2];
                      uVar2 = *uStack_50;
                      if ((*(byte *)((int)uStack_50 + 5) & 1) == 0) {
                        iVar14 = nwk_address_extended_by_ref(&req.nwk_mgmt_addr);
                        if (iVar14 != 0) goto _L0;
                        *(undefined1 *)((int)pvVar12 + iVar11 + 0xc) = 3;
                        memcpy((void *)((int)pvVar12 + iVar11 + 0xe),&req.nwk_mgmt_addr,8);
                        *(undefined1 *)((int)pvVar12 + iVar11 + 0x16) =
                             *(undefined1 *)(uStack_50 + 1);
                      }
                      else {
                        *(undefined1 *)((int)pvVar13 + 0xc) = 1;
                        *(undefined2 *)((int)pvVar13 + 0xe) = uVar2;
                        *(undefined1 *)((int)pvVar13 + 0x16) = 0;
                      }
                      uVar5 = uVar5 + 1 & 0xff;
                    }
                    bVar16 = bVar16 + 1;
                    aps_bind_table_iterator_next(&resp.payload);
                  }
                  uStack_91 = (uint8_t)uVar5;
                  _req_3 = (uint)CONCAT12(uStack_91,CONCAT11(abStack_98[0],bVar15)) << 8;
                  zVar4 = zdo_op_nwk_mgmt_bind_rsp
                                    ((zdo_packet_payload_t *)resp.ctx.req_ctx.arg,
                                     (zdp_nwk_mgmt_bind_rsp_field_t *)&req_3,true);
                  uVar5 = CONCAT31(extraout_var_02,zVar4);
                  if (pvVar12 != (void *)0x0) {
                    mm_free();
                  }
                  goto _L0;
                }
                goto _L0;
              }
              bStack_93 = bVar15;
              req_3.start_index = 0x8f;
            }
            _req_3 = (uint)CONCAT12(abStack_98[0],_req_3);
            zVar4 = zdo_op_nwk_mgmt_bind_rsp
                              ((zdo_packet_payload_t *)resp.ctx.req_ctx.arg,
                               (zdp_nwk_mgmt_bind_rsp_field_t *)&req_3,true);
            uVar5 = CONCAT31(extraout_var_01,zVar4);
            goto _L0;
          }
        }
        goto _L0;
      }
_L347:
      uVar5 = 0x84;
    }
  }
_L0:
  zdo_packet_free(auStack_70);
_L0:
  return (zdp_status_t)uVar5;
}

