/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
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
  byte bVar4;
  zdp_status_t zVar5;
  int iVar6;
  undefined3 extraout_var;
  int *piVar7;
  undefined1 *puVar8;
  ezb_err_t eVar9;
  uint uVar10;
  undefined3 extraout_var_00;
  void *pvVar11;
  undefined3 extraout_var_01;
  void *pvVar12;
  int iVar13;
  uint8_t val;
  byte bVar14;
  uint uVar15;
  zmsg_t *pzVar16;
  uint uVar17;
  byte abStack_94 [4];
  zdp_nwk_mgmt_bind_req_field_t req_1;
  byte bStack_8f;
  byte bStack_8e;
  uint8_t uStack_8d;
  channel_page_t iface_supported_1;
  uint uStack_88;
  zdp_nwk_mgmt_nwk_update_req_field_t req;
  channel_page_t iface_supported;
  undefined1 auStack_70 [4];
  zdo_packet_t resp;
  uint16_t offset;
  undefined4 uStack_50;
  
  memset(auStack_70,0,0x18);
  if (arg == (void *)0x0) {
    iVar6 = 0x80;
    goto _L0;
  }
  iVar6 = zdo_packet_response_init(auStack_70,arg,*(ushort *)((int)arg + 6) | 0x8000);
  if (iVar6 != 0) goto _L0;
  uVar1 = *(ushort *)((int)arg + 6);
  if (uVar1 == 0x34) {
    pzVar16 = *(zmsg_t **)((int)arg + 0x14);
    resp.payload = (zdo_packet_payload_t *)0x0;
    _offset = (undefined2 *)0x0;
    if (pzVar16 != (zmsg_t *)0x0) {
      req._4_4_ = (uint)(ushort)req._6_2_ << 0x10;
      uStack_88 = uStack_88 & 0xffffff00;
      uVar10 = zmsg_get_length(pzVar16);
      af_read_bytes(pzVar16,(uint16_t *)&req.scan_duration,8,(uint8_t *)&resp.payload);
      af_read_le8(pzVar16,(uint16_t *)&req.scan_duration,(uint8_t *)&uStack_88);
      if ((req._4_4_ & 0xffff) <= uVar10) {
        uVar17 = (uint)*(ushort *)((int)arg + 4);
        bVar4 = (byte)uStack_88 >> 7;
        uStack_50 = (undefined2 *)(uint)(CONCAT11(bVar4,(byte)uStack_88 >> 6) & 0xff01);
        uVar10 = nwk_get_short_address();
        if (resp.payload == (zdo_packet_payload_t *)0x0) {
          pzVar16 = (zmsg_t *)0x1;
          if (uVar17 == uVar10) goto _L0;
        }
        else {
          piVar7 = (int *)nwk_get_extended_address();
          pzVar16 = (zmsg_t *)
                    (uint)(resp.payload == (zdo_packet_payload_t *)*piVar7 && piVar7[1] == 0);
          if (uVar17 == uVar10) goto _L0;
        }
        iVar6 = nwk_validate_leave_request
                          (*(undefined2 *)((int)arg + 4),*(undefined2 *)((int)arg + 2),bVar4);
        if (iVar6 == 0) {
          iVar6 = nwk_neighbor_table_get_by_extended(&resp.payload);
          if (iVar6 != 0) goto _L0;
          goto _L0;
        }
_L0:
        if (pzVar16 == (zmsg_t *)0x0) goto _L0;
        goto _L0;
      }
    }
    goto _L0;
  }
  if (uVar1 < 0x35) {
    if (uVar1 == 0x31) {
      zVar5 = zdo_nwk_mgmt_lqi_req_handler((zdo_packet_t *)arg,(zdo_packet_t *)auStack_70);
      iVar6 = CONCAT31(extraout_var,zVar5);
_L0:
      if (iVar6 == 0) {
_L0:
        iVar6 = zdo_packet_send(auStack_70);
        goto _L0;
      }
    }
    else {
      if (uVar1 == 0x33) {
        pzVar16 = *(zmsg_t **)((int)arg + 0x14);
        abStack_94[0] = 0;
        _req_1 = 0;
        if (pzVar16 != (zmsg_t *)0x0) {
          resp.payload = (zdo_packet_payload_t *)((uint)resp.payload._2_2_ << 0x10);
          uVar10 = zmsg_get_length(pzVar16);
          af_read_le8(pzVar16,(uint16_t *)&resp.payload,abStack_94);
          if (((uint)resp.payload & 0xffff) <= uVar10) {
            aps_bind_table_iterator_init(0,&resp.payload);
            bVar4 = 0;
            while (((uint)resp.payload & 0xff) == 0) {
              bVar4 = bVar4 + 1;
              aps_bind_table_iterator_next(&resp.payload);
            }
            if (bVar4 == 0) {
              req_1.start_index = '\0';
              bStack_8f = '\0';
            }
            else {
              if (abStack_94[0] < bVar4) {
                iVar6 = zdo_packet_max_available_space(0x8033);
                uVar10 = iVar6 - 4U & 0xff;
                uVar17 = uVar10 / 0x15;
                pvVar11 = calloc(uVar17,0x18);
                if ((pvVar11 != (void *)0x0) || (uVar10 < 0x15)) {
                  aps_bind_table_iterator_init(0,&resp.payload);
                  bVar14 = 0;
                  uVar10 = 0;
                  while ((((uint)resp.payload & 0xff) == 0 && (uVar10 < uVar17))) {
                    if (abStack_94[0] <= bVar14) {
                      iVar6 = nwk_address_extended_by_ref(*_offset,&uStack_88);
                      if (iVar6 != 0) goto _L0;
                      iVar6 = uVar10 * 0x18;
                      pvVar12 = memcpy((void *)((int)pvVar11 + iVar6),&uStack_88,8);
                      *(undefined1 *)((int)pvVar12 + 8) = *(undefined1 *)(_offset + 1);
                      *(undefined2 *)((int)pvVar12 + 10) = _offset[2];
                      uVar2 = *uStack_50;
                      if ((*(byte *)((int)uStack_50 + 5) & 1) == 0) {
                        iVar13 = nwk_address_extended_by_ref(&req.scan_duration);
                        if (iVar13 != 0) goto _L0;
                        *(undefined1 *)((int)pvVar11 + iVar6 + 0xc) = 3;
                        memcpy((void *)((int)pvVar11 + iVar6 + 0xe),&req.scan_duration,8);
                        *(undefined1 *)((int)pvVar11 + iVar6 + 0x16) =
                             *(undefined1 *)(uStack_50 + 1);
                      }
                      else {
                        *(undefined1 *)((int)pvVar12 + 0xc) = 1;
                        *(undefined2 *)((int)pvVar12 + 0xe) = uVar2;
                        *(undefined1 *)((int)pvVar12 + 0x16) = 0;
                      }
                      uVar10 = uVar10 + 1 & 0xff;
                    }
                    bVar14 = bVar14 + 1;
                    aps_bind_table_iterator_next(&resp.payload);
                  }
                  uStack_8d = (uint8_t)uVar10;
                  _req_1 = (uint)CONCAT12(uStack_8d,CONCAT11(abStack_94[0],bVar4)) << 8;
                  zVar5 = zdo_op_nwk_mgmt_bind_rsp
                                    ((zdo_packet_payload_t *)resp.ctx.req_ctx.arg,
                                     (zdp_nwk_mgmt_bind_rsp_field_t *)&req_1,true);
                  iVar6 = CONCAT31(extraout_var_01,zVar5);
                  if (pvVar11 != (void *)0x0) {
                    mm_free();
                  }
                  goto _L0;
                }
                goto _L0;
              }
              bStack_8f = bVar4;
              req_1.start_index = 0x8f;
            }
            _req_1 = (uint)CONCAT12(abStack_94[0],_req_1);
            zVar5 = zdo_op_nwk_mgmt_bind_rsp
                              ((zdo_packet_payload_t *)resp.ctx.req_ctx.arg,
                               (zdp_nwk_mgmt_bind_rsp_field_t *)&req_1,true);
            iVar6 = CONCAT31(extraout_var_00,zVar5);
            goto _L0;
          }
        }
        goto _L0;
      }
_L311:
      iVar6 = 0x84;
    }
  }
  else {
    if (uVar1 == 0x36) {
      pzVar16 = *(zmsg_t **)((int)arg + 0x14);
      req._4_4_ = (uint)(ushort)req._6_2_ << 0x10;
      if (pzVar16 != (zmsg_t *)0x0) {
        uVar1 = *(ushort *)((int)arg + 2);
        resp.payload = (zdo_packet_payload_t *)((uint)resp.payload._2_2_ << 0x10);
        uVar10 = zmsg_get_length(pzVar16);
        af_read_le8(pzVar16,(uint16_t *)&resp.payload,&req.scan_duration);
        af_read_le8(pzVar16,(uint16_t *)&resp.payload,&req.scan_count);
        if (((uint)resp.payload & 0xffff) <= uVar10) {
          req.scan_count = '\x01';
          uVar17 = (ushort)req._4_2_ & 0xff;
          nwk_is_device_zc();
          iVar13 = nwk_is_device_zczr();
          iVar6 = 0x84;
          if (iVar13 != 0) {
            pzVar16 = (zmsg_t *)zdo_create_mgmt_req(0x36,0x84);
            iVar6 = 0x80;
            if (pzVar16 != (zmsg_t *)0x0) {
              puVar8 = (undefined1 *)zdo_mgmt_req_get_param(0x80);
              uVar10 = uVar17;
              if (0xfe < uVar17) {
                uVar10 = 0xfffffffe;
              }
              *puVar8 = (char)uVar10;
              iVar6 = zdo_send_mgmt_req(pzVar16,1);
              iVar6 = (uint)(iVar6 != 0) << 7;
            }
          }
          if (uVar1 < 0xfff8) {
            uVar10 = 0x36;
            while ((zmsg_t *)resp.ctx.req_ctx.arg == (zmsg_t *)0x0) {
              while( true ) {
                iVar6 = __assert_func(0,0,0,0);
_L0:
                if ((pzVar16 == (zmsg_t *)0x0) || ((*(uint *)(iVar6 + 0xc) & 0x3c0) != 0x40)) break;
_L0:
                pzVar16 = (zmsg_t *)zdo_create_mgmt_req(0x34);
                if (pzVar16 == (zmsg_t *)0x0) goto _L0;
                puVar8 = (undefined1 *)zdo_mgmt_req_get_param();
                uVar15 = 0;
                *puVar8 = (char)resp.payload;
                puVar8[1] = (char)((uint)resp.payload >> 8);
                puVar8[3] = (char)((uint)resp.payload >> 0x18);
                puVar8[4] = (char)_offset;
                puVar8[5] = (char)((uint)_offset >> 8);
                puVar8[2] = (char)((uint)resp.payload >> 0x10);
                puVar8[6] = (char)((uint)_offset >> 0x10);
                puVar8[7] = (char)((uint)_offset >> 0x18);
                if (uVar17 == uVar10) {
                  uVar15 = (uint)uStack_50 & 0xff;
                }
                iVar6 = zdo_mgmt_req_get_param(pzVar16);
                *(byte *)(iVar6 + 8) = *(byte *)(iVar6 + 8) & 0xfd | (byte)((uVar15 & 1) << 1);
                bVar4 = 0;
                if (uVar17 == uVar10) {
                  bVar4 = uStack_50._1_1_;
                }
                iVar6 = zdo_mgmt_req_get_param(pzVar16);
                *(byte *)(iVar6 + 8) = *(byte *)(iVar6 + 8) & 0xfe | bVar4 & 1;
                if (resp.ctx.req_ctx.arg != (zdo_packet_user_ctx_t)0x0) {
                  eVar9 = zmsg_append_u8((zmsg_t *)resp.ctx.req_ctx.arg,'\0');
                  if (eVar9 != 0) goto _L0;
                  resp.ctx._0_4_ = zdo_mgmt_leave_rsp_confirm;
                  resp.src_addr._0_1_ = 0;
                  resp.ctx.req_ctx.cb = (zdo_packet_req_callback_t)pzVar16;
                  goto _L0;
                }
              }
_L0:
              iVar6 = 0x84;
            }
            eVar9 = zmsg_append_u8((zmsg_t *)resp.ctx.req_ctx.arg,(uint8_t)iVar6);
            if (eVar9 != 0) {
_L0:
              iVar6 = 0x8a;
              goto _L0;
            }
            goto _L0;
          }
        }
      }
    }
    else {
      if (uVar1 != 0x38) goto _L311;
      pzVar16 = *(zmsg_t **)((int)arg + 0x14);
      uStack_88 = 0;
      req.scan_channels = 0;
      if (pzVar16 != (zmsg_t *)0x0) {
        uVar1 = *(ushort *)((int)arg + 2);
        uVar10 = zmsg_get_length(pzVar16);
        iVar6 = zmsg_read_bytes(pzVar16,0,4,&uStack_88);
        if (iVar6 == 0) {
          iVar6 = 0xffff;
        }
        resp.payload = (zdo_packet_payload_t *)CONCAT22(resp.payload._2_2_,(short)iVar6);
        af_read_le8(pzVar16,(uint16_t *)&resp.payload,(uint8_t *)&req);
        af_read_le8(pzVar16,(uint16_t *)&resp.payload,(uint8_t *)((int)&req.scan_channels + 1));
        af_read_le8(pzVar16,(uint16_t *)&resp.payload,(uint8_t *)((int)&req.scan_channels + 2));
        af_read_le8(pzVar16,(uint16_t *)&resp.payload,(uint8_t *)((int)&req.scan_channels + 3));
        uVar17 = uStack_88;
        if (((uint)resp.payload & 0xffff) <= uVar10) {
          uVar10 = req.scan_channels & 0xff;
          uVar15 = uStack_88 & 0x7ffffff;
          if (uVar10 == 0xfe) {
            iVar6 = core_globals_get();
            uVar17 = uVar17 & 0x7ffffff;
            if ((*(int *)(iVar6 + 0xa30) == 0) ||
               (iVar6 = core_globals_get(), uVar17 == *(uint *)(iVar6 + 0xa30))) {
              bVar4 = 0;
              for (uVar10 = uVar17; uVar10 != 0; uVar10 = uVar10 & uVar10 - 1) {
                bVar4 = bVar4 + 1;
              }
              if (bVar4 < 2) {
                iVar6 = 0;
                if (uVar15 < 0x8000000) {
                  iVar6 = 10;
                }
                uVar10 = iVar6 + 1;
                do {
                  if ((uVar17 >> (uVar10 & 0x1f) & 1) != 0) {
                    uVar10 = uVar10 & 0xff;
                    goto _L0;
                  }
                  uVar10 = uVar10 + 1;
                } while ((uVar10 & 0xff) != 0x1b);
                uVar10 = 0xff;
_L0:
                req.scan_duration = '\0';
                req.scan_count = '\0';
                req.nwk_update_id = '\0';
                req.nwk_mgmt_addr = '\0';
                iVar6 = nwk_mm_get_pib_attr(0,99,&req.scan_duration,4);
                if ((iVar6 == 0) && (((req._4_4_ & 0x7ffffff) >> (uVar10 & 0x1f) & 1) != 0)) {
                  resp.payload = (zdo_packet_payload_t *)(1 << (uVar10 & 0x1f));
                  nwk_mm_set_pib_attr(0x61,&resp.payload);
                  goto _L0;
                }
              }
_L0:
              val = 0x80;
            }
            else {
              val = 0x8d;
            }
          }
          else {
            if (uVar10 == 0xff) {
              iVar6 = aps_secur_is_centralized();
              if ((iVar6 == 0) || (req.scan_channels._3_1_ == '\0')) {
                iVar6 = core_globals_get();
                *(uint *)(iVar6 + 8) = uVar15;
                bVar4 = req.scan_channels._3_1_;
                iVar6 = core_globals_get();
                *(ushort *)(iVar6 + 0x9dc) = (ushort)bVar4;
              }
              goto _L0;
            }
            if (5 < uVar10) {
              log_write(2,"ZDO_NWK_MGMT","Mgmt_NWK_Update_req: Invalid ScanDuration value: 0x%02x");
              goto _L0;
            }
            val = 0x80;
            if (uVar1 < 0xfff8) {
              _req_1 = 0;
              nwk_mm_get_pib_attr(0,99,&req_1,4);
              uVar17 = uVar17 & 0x7ffffff;
              val = 0x86;
              if (uVar17 == (_req_1 & 0x7ffffff & uVar17)) {
                iVar6 = zdo_packet_clone(auStack_70,0x86);
                if (iVar6 != 0) {
                  req._4_4_ = (uint)CONCAT21(req._6_2_,(undefined1)req.scan_channels) << 8;
                  uVar3 = *(undefined4 *)(iVar6 + 0x14);
                  memset(&resp.payload,0,0x28);
                  zmsg_add_footer(uVar3,&resp.payload,0x28);
                  nwk_nlme_scan(&req.scan_duration);
                  ezb_err_to_zdp_status();
                  goto _L0;
                }
                val = 0x8a;
              }
            }
          }
          zmsg_append_u8((zmsg_t *)resp.ctx.req_ctx.arg,val);
          goto _L0;
        }
      }
    }
_L0:
    iVar6 = 0xfe;
  }
_L0:
  zdo_packet_free(auStack_70);
_L0:
  return (zdp_status_t)iVar6;
}

