/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.release -> zdo_nwk_mgmt.o -> zdo_nwk_mgmt_req_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

uint zdo_nwk_mgmt_req_handler(int param_1)

{
  undefined2 uVar1;
  undefined2 uVar2;
  bool bVar3;
  bool bVar4;
  code *pcVar5;
  ushort uVar6;
  uint uVar7;
  undefined4 uVar8;
  uint uVar9;
  undefined2 *puVar10;
  int iVar11;
  uint *puVar12;
  undefined1 *puVar13;
  byte *pbVar14;
  void *pvVar15;
  undefined2 *puVar16;
  byte bVar17;
  byte bVar18;
  undefined2 *puVar19;
  int iVar20;
  char cVar21;
  uint uVar22;
  uint uVar23;
  uint uVar24;
  byte abStack_98 [4];
  undefined4 uStack_94;
  undefined2 *puStack_90;
  code *pcStack_8c;
  undefined4 uStack_88;
  undefined4 uStack_84;
  undefined4 uStack_80;
  code *pcStack_7c;
  code *pcStack_78;
  void *pvStack_74;
  undefined1 auStack_70 [8];
  undefined1 uStack_68;
  code *pcStack_64;
  int iStack_60;
  int iStack_5c;
  undefined4 uStack_58;
  undefined2 *puStack_54;
  undefined4 uStack_50;
  
  memset(auStack_70,0,0x18);
  if (param_1 == 0) {
    return 0x80;
  }
  uVar9 = zdo_packet_response_init(auStack_70,param_1,*(ushort *)(param_1 + 6) | 0x8000);
  if (uVar9 != 0) {
    return uVar9;
  }
  uVar6 = *(ushort *)(param_1 + 6);
  if (uVar6 == 0x34) {
    iVar20 = *(int *)(param_1 + 0x14);
    uStack_58 = 0;
    puStack_54 = (undefined2 *)0x0;
    uStack_50 = (undefined2 *)((uint)uStack_50 & 0xffff0000);
    abStack_98[0] = 0;
    pcStack_8c = (code *)0x0;
    uStack_88 = (void *)0x0;
    if (iVar20 != 0) {
      uStack_80 = (uint)uStack_80._2_2_ << 0x10;
      uStack_94 = uStack_94 & 0xffffff00;
      uVar9 = zmsg_get_length(iVar20);
      af_read_bytes_isra_0(iVar20,&uStack_80,8,&uStack_58);
      af_read_le8_isra_0(iVar20,&uStack_80,&uStack_94);
      if ((uStack_80 & 0xffff) <= uVar9) {
        uVar6 = *(ushort *)(param_1 + 4);
        bVar3 = true;
        uStack_50 = (undefined2 *)
                    (CONCAT22(uStack_50._2_2_,CONCAT11((byte)uStack_94 >> 7,(byte)uStack_94 >> 6)) &
                    0xffffff01);
        uVar9 = nwk_get_short_address();
        if (uStack_58 != 0 || puStack_54 != (undefined2 *)0x0) {
          puVar12 = (uint *)nwk_get_extended_address();
          bVar3 = uStack_58 == *puVar12 && (undefined2 *)puVar12[1] == puStack_54;
        }
        abStack_98[0] = 0;
        if (uVar6 != uVar9) {
          iVar20 = 1;
          if (bVar3) {
            iVar20 = nwk_validate_leave_request
                               (*(undefined2 *)(param_1 + 4),*(undefined2 *)(param_1 + 2),
                                (uint)uStack_50 >> 8 & 0xff);
          }
          iVar11 = nwk_is_device_zed();
          bVar4 = bVar3;
          if (iVar11 == 0) {
            if ((!bVar3) && (iVar11 = nwk_neighbor_table_get_by_extended(&uStack_58), iVar11 != 0))
            {
              bVar4 = (*(uint *)(iVar11 + 0xc) & 0x3c0) == 0x40;
            }
            if (iVar20 != 0) goto _L0;
_L0:
            abStack_98[0] = 0x8d;
          }
          else {
            if (iVar20 == 0) {
              uStack_80 = 0;
              pcStack_7c = (code *)0x0;
              iVar20 = nwk_address_extended_by_short(*(undefined2 *)(param_1 + 4),&uStack_80);
              if ((iVar20 != 0) || (iVar20 = aps_secur_is_addr_tc(&uStack_80), iVar20 == 0))
              goto _L0;
            }
_L0:
            if (bVar4) goto _L0;
            abStack_98[0] = 0x84;
          }
          zdo_op_nwk_mgmt_leave_rsp(iStack_5c,abStack_98,1);
_L0:
          uVar9 = zdo_packet_send(auStack_70);
          return uVar9;
        }
_L0:
        abStack_98[0] = 0;
        iVar20 = zdo_create_mgmt_req(0x34);
        if (iVar20 != 0) {
          puVar13 = (undefined1 *)zdo_mgmt_req_get_param();
          *puVar13 = (char)uStack_58;
          puVar13[1] = (char)(uStack_58 >> 8);
          puVar13[3] = (char)(uStack_58 >> 0x18);
          puVar13[4] = (char)puStack_54;
          puVar13[5] = (char)((uint)puStack_54 >> 8);
          puVar13[2] = (char)(uStack_58 >> 0x10);
          puVar13[6] = (char)((uint)puStack_54 >> 0x10);
          puVar13[7] = (char)((uint)puStack_54 >> 0x18);
          iVar11 = zdo_mgmt_req_get_param(iVar20);
          *(byte *)(iVar11 + 8) = *(byte *)(iVar11 + 8) & 0xfd | (byte)(((uint)uStack_50 & 1) << 1);
          iVar11 = zdo_mgmt_req_get_param(iVar20);
          *(byte *)(iVar11 + 8) = *(byte *)(iVar11 + 8) & 0xfe | (byte)((uint)uStack_50 >> 8) & 1;
          if (bVar3) {
            uVar9 = zdo_op_nwk_mgmt_leave_rsp(iStack_5c,abStack_98,1);
            if (uVar9 == 0) {
              pcStack_64 = zdo_mgmt_leave_rsp_confirm;
              uStack_68 = 0;
              iStack_60 = iVar20;
              goto _L0;
            }
            goto _L0;
          }
          uVar9 = zdo_op_nwk_mgmt_leave_rsp();
          if (uVar9 != 0) goto _L0;
          uStack_88 = calloc(1,0x18);
          if (uStack_88 == (void *)0x0) goto _L0;
          uVar9 = zdo_packet_move(auStack_70);
          uVar9 = uVar9 & 0xff;
          if (uVar9 != 0) {
            mm_free(uStack_88);
            goto _L0;
          }
          pcStack_8c = zdo_mgmt_leave_sync_rsp_cb;
          zdo_mgmt_req_set_user_ctx(iVar20,&pcStack_8c);
          zdo_send_mgmt_req(iVar20,0);
        }
      }
    }
  }
  else if (uVar6 < 0x35) {
    if (uVar6 == 0x32) {
      puVar19 = *(undefined2 **)(param_1 + 0x14);
      pcStack_8c = (code *)((uint)pcStack_8c & 0xffffff00);
      if (puVar19 != (undefined2 *)0x0) {
        if (*(ushort *)(param_1 + 2) < 0xfff8) goto _L0;
        goto _L0;
      }
      goto _L0;
    }
    if (uVar6 != 0x33) {
      if (uVar6 != 0x31) goto _L421;
      uVar9 = zdo_nwk_mgmt_lqi_req_handler(param_1,auStack_70);
      goto _L0;
    }
    iVar20 = *(int *)(param_1 + 0x14);
    abStack_98[0] = 0;
    uStack_94 = 0;
    puStack_90 = (undefined2 *)0x0;
    if (iVar20 != 0) {
      uStack_58 = (uint)uStack_58._2_2_ << 0x10;
      uVar9 = zmsg_get_length(iVar20);
      af_read_le8_isra_0(iVar20,&uStack_58,abStack_98);
      if ((uStack_58 & 0xffff) <= uVar9) {
        aps_bind_table_iterator_init(0,&uStack_58);
        bVar17 = 0;
        while ((uStack_58 & 0xff) == 0) {
          bVar17 = bVar17 + 1;
          aps_bind_table_iterator_next(&uStack_58);
        }
        if ((bVar17 == 0) || (bVar17 <= abStack_98[0])) {
          uStack_94 = (uint)CONCAT11(abStack_98[0],bVar17) << 8;
          puStack_90 = (undefined2 *)0x0;
          uVar9 = zdo_op_nwk_mgmt_bind_rsp(iStack_5c,&uStack_94,1);
          goto _L0;
        }
        iVar20 = zdo_packet_max_available_space(0x8033);
        uVar9 = iVar20 - 4U & 0xff;
        uVar23 = uVar9 / 0x15;
        puStack_90 = (undefined2 *)calloc(uVar23,0x18);
        if ((puStack_90 == (undefined2 *)0x0) && (0x14 < uVar9)) goto _L0;
        aps_bind_table_iterator_init(0,&uStack_58);
        bVar18 = 0;
        uVar9 = 0;
        while (((uStack_58 & 0xff) == 0 && (uVar9 < uVar23))) {
          if (abStack_98[0] <= bVar18) {
            iVar20 = nwk_address_extended_by_ref(*puStack_54,&pcStack_8c);
            if (iVar20 != 0) goto _L0;
            pvVar15 = memcpy(puStack_90 + uVar9 * 0xc,&pcStack_8c,8);
            *(undefined1 *)((int)pvVar15 + 8) = *(undefined1 *)(puStack_54 + 1);
            *(undefined2 *)((int)pvVar15 + 10) = puStack_54[2];
            uVar2 = *uStack_50;
            if ((*(byte *)((int)uStack_50 + 5) & 1) == 0) {
              iVar20 = nwk_address_extended_by_ref(&uStack_80);
              puVar19 = puStack_90;
              if (iVar20 != 0) goto _L0;
              *(undefined1 *)(puStack_90 + uVar9 * 0xc + 6) = 3;
              memcpy(puStack_90 + uVar9 * 0xc + 7,&uStack_80,8);
              *(undefined1 *)(puVar19 + uVar9 * 0xc + 0xb) = *(undefined1 *)(uStack_50 + 1);
            }
            else {
              *(undefined1 *)((int)pvVar15 + 0xc) = 1;
              *(undefined2 *)((int)pvVar15 + 0xe) = uVar2;
              *(undefined1 *)((int)pvVar15 + 0x16) = 0;
            }
            uVar9 = uVar9 + 1 & 0xff;
          }
          bVar18 = bVar18 + 1;
          aps_bind_table_iterator_next(&uStack_58);
        }
        uStack_94._3_1_ = (undefined1)uVar9;
        uStack_94 = (uint)CONCAT12(uStack_94._3_1_,CONCAT11(abStack_98[0],bVar17)) << 8;
        uVar9 = zdo_op_nwk_mgmt_bind_rsp(iStack_5c,&uStack_94,1);
        puVar19 = puStack_90;
        if (puStack_90 == (undefined2 *)0x0) goto _L0;
_L0:
        mm_free(puVar19);
        goto _L0;
      }
    }
  }
  else if (uVar6 == 0x36) {
    iVar20 = *(int *)(param_1 + 0x14);
    uStack_80 = (uint)uStack_80._2_2_ << 0x10;
    if (iVar20 != 0) {
      uVar6 = *(ushort *)(param_1 + 2);
      uStack_58 = (uint)uStack_58._2_2_ << 0x10;
      uVar9 = zmsg_get_length(iVar20);
      af_read_le8_isra_0(iVar20,&uStack_58,&uStack_80);
      af_read_le8_isra_0(iVar20,&uStack_58,(int)&uStack_80 + 1);
      if ((uStack_58 & 0xffff) <= uVar9) {
        bVar17 = (byte)uStack_80;
        uStack_80._0_2_ = CONCAT11(1,(byte)uStack_80);
        nwk_is_device_zc();
        iVar20 = nwk_is_device_zczr();
        iVar11 = 0x84;
        if (iVar20 != 0) {
          iVar20 = zdo_create_mgmt_req(0x36,0x84);
          iVar11 = 0x80;
          if (iVar20 != 0) {
            pbVar14 = (byte *)zdo_mgmt_req_get_param(0x80);
            if (0xfe < bVar17) {
              bVar17 = 0xfe;
            }
            *pbVar14 = bVar17;
            iVar20 = zdo_send_mgmt_req(iVar20,1);
            iVar11 = (uint)(iVar20 != 0) << 7;
          }
        }
        if (uVar6 < 0xfff8) {
          puVar19 = (undefined2 *)0x36;
          if (iStack_5c == 0) {
            do {
              __assert_func(0,0,0,0);
_L0:
              uStack_58 = uStack_58 & 0xffff0000;
              uVar9 = zmsg_get_length(puVar19);
              af_read_le8_isra_0(puVar19,&uStack_58,&pcStack_8c);
              if (uVar9 < (uStack_58 & 0xffff)) goto _L0;
              iVar20 = nwk_is_device_zczr();
              if (iVar20 == 0) {
_L0:
                cVar21 = '\0';
                uVar23 = 0;
                uVar9 = 0;
                puVar19 = (undefined2 *)0x0;
                iVar20 = 0x84;
              }
              else {
                uVar9 = zdo_packet_max_available_space(0x8032);
                uVar22 = 0;
                if (4 < uVar9) {
                  uVar22 = (int)(uVar9 - 4) / 5 & 0xff;
                }
                iVar20 = 0;
                uVar6 = 0;
                while (iVar20 = nwk_route_table_next(iVar20), iVar20 != 0) {
                  uVar6 = uVar6 + 1;
                }
                cVar21 = -1;
                if (uVar6 < 0xff) {
                  iVar20 = 0;
                  cVar21 = '\0';
                  while (iVar20 = nwk_route_table_next(iVar20), iVar20 != 0) {
                    cVar21 = cVar21 + '\x01';
                  }
                }
                uVar9 = (uint)pcStack_8c & 0xff;
                puVar19 = (undefined2 *)calloc(uVar22,6);
                uVar23 = 0;
                uVar24 = 0;
                if ((puVar19 != (undefined2 *)0x0) || (iVar20 = 0x8a, uVar22 == 0)) {
                  puVar10 = (undefined2 *)0x0;
                  uVar23 = 0;
                  while ((puVar10 = (undefined2 *)nwk_route_table_next(puVar10),
                         puVar10 != (undefined2 *)0x0 && (uVar23 < uVar22))) {
                    uVar7 = uVar23;
                    if (((uint)pcStack_8c & 0xff) <= uVar24) {
                      uVar2 = puVar10[7];
                      uVar1 = puVar10[7];
                      uVar7 = uVar23 + 1 & 0xff;
                      puVar16 = puVar19 + uVar23 * 3;
                      *puVar16 = *puVar10;
                      *(byte *)(puVar16 + 1) =
                           *(byte *)(puVar16 + 1) & 0xc0 | (byte)uVar2 & 7 | (byte)uVar1 & 8 |
                           (byte)puVar10[7] & 0x10 | (byte)puVar10[7] & 0x20;
                      puVar16[2] = puVar10[1];
                    }
                    uVar24 = uVar24 + 1 & 0xff;
                    uVar23 = uVar7;
                  }
                  iVar20 = 0;
                }
              }
            } while (iStack_5c == 0);
            iVar11 = zmsg_append_u8(iStack_5c,iVar20);
            if (iVar11 == 0) {
              if (iVar20 == 0) {
                iVar20 = zmsg_append_u8(iStack_5c,cVar21);
                if (((iVar20 == 0) && (iVar20 = zmsg_append_u8(iStack_5c,uVar9), iVar20 == 0)) &&
                   (iVar20 = zmsg_append_u8(iStack_5c,uVar23), iVar20 == 0)) {
                  if (puVar19 == (undefined2 *)0x0) goto _L0;
                  uVar9 = uVar23;
                  if (uVar23 != 0) {
                    uVar22 = 0;
                    puVar10 = puVar19;
                    do {
                      uVar6 = puVar10[1];
                      uStack_58 = CONCAT22(uStack_58._2_2_,*puVar10);
                      iVar20 = zmsg_append_bytes(iStack_5c,2,&uStack_58);
                      if ((iVar20 != 0) ||
                         (iVar20 = zmsg_append_u8(iStack_5c,uVar6 & 0x3f), iVar20 != 0)) {
_L0:
                        uVar9 = 0x8a;
                        break;
                      }
                      uStack_58 = CONCAT22(uStack_58._2_2_,puVar10[2]);
                      iVar20 = zmsg_append_bytes(iStack_5c,2,&uStack_58);
                      if (iVar20 != 0) goto _L0;
                      uVar22 = uVar22 + 1 & 0xff;
                      puVar10 = puVar10 + 3;
                      uVar9 = 0;
                    } while (uVar23 != uVar22);
                  }
                  goto _L0;
                }
                goto _L0;
              }
              uVar9 = 0;
            }
            else {
_L0:
              uVar9 = 0x8a;
            }
            if (puVar19 != (undefined2 *)0x0) goto _L0;
            goto _L0;
          }
          iVar20 = zmsg_append_u8(iVar11);
          if (iVar20 == 0) goto _L0;
_L0:
          uVar9 = 0x8a;
          goto _L0;
        }
      }
    }
  }
  else {
    if (uVar6 != 0x38) {
_L421:
      uVar9 = 0x84;
      goto _L0;
    }
    iVar20 = *(int *)(param_1 + 0x14);
    pcStack_8c = (code *)0x0;
    uStack_88 = (void *)0x0;
    uStack_84 = 0;
    if (iVar20 != 0) {
      uVar6 = *(ushort *)(param_1 + 2);
      uVar9 = zmsg_get_length(iVar20);
      iVar11 = zmsg_read_bytes(iVar20,0,4,&pcStack_8c);
      if (iVar11 == 0) {
        iVar11 = 0xffff;
      }
      uStack_58 = CONCAT22(uStack_58._2_2_,(short)iVar11);
      af_read_le8_isra_0(iVar20,&uStack_58,&uStack_88);
      if (((uint)uStack_88 & 0xff) < 6) {
        af_read_le8_isra_0(iVar20,&uStack_58,(int)&uStack_88 + 1);
      }
      if ((0xfd < ((uint)uStack_88 & 0xff)) &&
         (af_read_le8_isra_0(iVar20,&uStack_58,(int)&uStack_88 + 2),
         ((uint)uStack_88 & 0xff) == 0xff)) {
        af_read_le16_isra_0(iVar20,&uStack_58,&uStack_84);
      }
      pcVar5 = pcStack_8c;
      if ((uStack_58 & 0xffff) <= uVar9) {
        uVar9 = (uint)uStack_88 & 0xff;
        uVar23 = (uint)pcStack_8c & 0x7ffffff;
        if (uVar9 == 0xfe) {
          iVar20 = core_globals_get();
          uVar9 = (uint)pcVar5 & 0x7ffffff;
          if ((*(int *)(iVar20 + 0xa30) == 0) ||
             (iVar20 = core_globals_get(), *(uint *)(iVar20 + 0xa30) == uVar9)) {
            bVar17 = 0;
            for (uVar22 = uVar9; uVar22 != 0; uVar22 = uVar22 & uVar22 - 1) {
              bVar17 = bVar17 + 1;
            }
            if (bVar17 < 2) {
              iVar20 = 0;
              if (uVar23 < 0x8000000) {
                iVar20 = 10;
              }
              uVar23 = iVar20 + 1;
              do {
                if ((uVar9 >> (uVar23 & 0x1f) & 1) != 0) {
                  uVar23 = uVar23 & 0xff;
                  goto _L0;
                }
                uVar23 = uVar23 + 1;
              } while ((uVar23 & 0xff) != 0x1b);
              uVar23 = 0xff;
_L0:
              uStack_80 = 0;
              iVar20 = nwk_mm_get_pib_attr(0,99,&uStack_80,4);
              if ((iVar20 == 0) && (((uStack_80 & 0x7ffffff) >> (uVar23 & 0x1f) & 1) != 0)) {
                uStack_58 = 1 << (uVar23 & 0x1f);
                nwk_mm_set_pib_attr(0x61,&uStack_58);
                goto _L0;
              }
            }
_L0:
            uVar9 = 0x80;
          }
          else {
            uVar9 = 0x8d;
          }
        }
        else {
          if (uVar9 == 0xff) {
            iVar20 = aps_secur_is_centralized();
            if ((iVar20 == 0) || ((short)uStack_84 == 0)) {
              iVar20 = core_globals_get();
              *(uint *)(iVar20 + 8) = uVar23;
              iVar20 = core_globals_get();
              *(short *)(iVar20 + 0x9dc) = (short)uStack_84;
            }
            goto _L0;
          }
          if ((5 < uVar9) || (0xfff7 < uVar6)) goto _L0;
          uStack_94 = 0;
          nwk_mm_get_pib_attr(0,99,&uStack_94,4);
          uVar23 = (uint)pcVar5 & 0x7ffffff;
          uVar9 = 0x86;
          if (uVar23 == (uStack_94 & 0x7ffffff & uVar23)) {
            pvVar15 = calloc(1,0x18);
            uVar9 = 0x8a;
            if (pvVar15 != (void *)0x0) {
              uVar9 = zdo_packet_move(auStack_70);
              uVar9 = uVar9 & 0xff;
              if (uVar9 == 0) {
                uVar8 = *(undefined4 *)((int)pvVar15 + 0x14);
                pcStack_7c = pcStack_8c;
                pcStack_78 = zdo_mgmt_ed_scan_handler;
                uStack_80 = (uint)CONCAT21(uStack_80._2_2_,(undefined1)uStack_88) << 8;
                pvStack_74 = pvVar15;
                memset(&uStack_58,0,0x28);
                zmsg_add_footer(uVar8,&uStack_58,0x28);
                nwk_nlme_scan(&uStack_80);
                uVar9 = ezb_err_to_zdp_status();
                if (uVar9 == 0) goto _L0;
              }
              mm_free(pvVar15);
              if (uVar9 == 0xfe) goto _L0;
            }
          }
        }
        memset(&uStack_58,0,0x28);
        uStack_58 = CONCAT31(uStack_58._1_3_,(char)uVar9);
        uVar9 = zdo_op_nwk_mgmt_nwk_update_notify(iStack_5c,&uStack_58,1);
_L0:
        if (uVar9 == 0) goto _L0;
        goto _L0;
      }
    }
  }
_L0:
  uVar9 = 0xfe;
_L0:
  zdo_packet_free(auStack_70);
  return uVar9;
}

