/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
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
  ushort uVar4;
  uint uVar5;
  undefined4 uVar6;
  uint uVar7;
  undefined2 *puVar8;
  int iVar9;
  uint *puVar10;
  undefined1 *puVar11;
  byte *pbVar12;
  void *pvVar13;
  undefined2 *puVar14;
  byte bVar15;
  byte bVar16;
  undefined2 *puVar17;
  int iVar18;
  char cVar19;
  uint uVar20;
  uint uVar21;
  uint uVar22;
  byte abStack_98 [4];
  undefined4 uStack_94;
  undefined2 *puStack_90;
  undefined4 uStack_8c;
  undefined4 uStack_88;
  undefined4 uStack_84;
  undefined4 uStack_80;
  void *pvStack_7c;
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
  uVar7 = zdo_packet_response_init(auStack_70,param_1,*(ushort *)(param_1 + 6) | 0x8000);
  if (uVar7 != 0) {
    return uVar7;
  }
  uVar4 = *(ushort *)(param_1 + 6);
  if (uVar4 == 0x34) {
    iVar18 = *(int *)(param_1 + 0x14);
    uStack_58 = 0;
    puStack_54 = (undefined2 *)0x0;
    uStack_50 = (undefined2 *)((uint)uStack_50 & 0xffff0000);
    uStack_80 = (code *)0x0;
    pvStack_7c = (void *)0x0;
    if (iVar18 != 0) {
      uStack_8c = (void *)((uint)uStack_8c._2_2_ << 0x10);
      uStack_94 = (uint)uStack_94._1_3_ << 8;
      uVar7 = zmsg_get_length(iVar18);
      af_read_bytes_isra_0(iVar18,&uStack_8c,8,&uStack_58);
      af_read_le8_isra_0(iVar18,&uStack_8c,&uStack_94);
      if (((uint)uStack_8c & 0xffff) <= uVar7) {
        puVar17 = (undefined2 *)(uint)*(ushort *)(param_1 + 4);
        bVar3 = true;
        uStack_50 = (undefined2 *)
                    (CONCAT22(uStack_50._2_2_,CONCAT11((byte)uStack_94 >> 7,(byte)uStack_94 >> 6)) &
                    0xffffff01);
        puVar8 = (undefined2 *)nwk_get_short_address();
        if (uStack_58 != 0 || puStack_54 != (undefined2 *)0x0) {
          puVar10 = (uint *)nwk_get_extended_address();
          bVar3 = uStack_58 == *puVar10 && (undefined2 *)puVar10[1] == puStack_54;
        }
        if (((puVar17 != puVar8) &&
            (iVar18 = nwk_validate_leave_request
                                (*(undefined2 *)(param_1 + 4),*(undefined2 *)(param_1 + 2),
                                 (uint)uStack_50 >> 8 & 0xff), iVar18 == 0)) &&
           ((iVar18 = nwk_neighbor_table_get_by_extended(&uStack_58), iVar18 == 0 ||
            ((*(uint *)(iVar18 + 0xc) & 0x3c0) != 0x40)))) {
          iVar18 = 0x84;
          if (iStack_5c == 0) goto _L0;
_L0:
          iVar18 = zmsg_append_u8(iVar18);
          if (iVar18 == 0) goto _L0;
_L0:
          uVar7 = 0x8a;
          goto _L0;
        }
        iVar18 = zdo_create_mgmt_req(0x34);
        if (iVar18 == 0) goto _L0;
        puVar11 = (undefined1 *)zdo_mgmt_req_get_param();
        *puVar11 = (char)uStack_58;
        puVar11[1] = (char)(uStack_58 >> 8);
        puVar11[3] = (char)(uStack_58 >> 0x18);
        puVar11[4] = (char)puStack_54;
        puVar11[5] = (char)((uint)puStack_54 >> 8);
        puVar11[2] = (char)(uStack_58 >> 0x10);
        puVar11[6] = (char)((uint)puStack_54 >> 0x10);
        puVar11[7] = (char)((uint)puStack_54 >> 0x18);
        iVar9 = zdo_mgmt_req_get_param(iVar18);
        *(byte *)(iVar9 + 8) = *(byte *)(iVar9 + 8) & 0xfd | (byte)(((uint)uStack_50 & 1) << 1);
        iVar9 = zdo_mgmt_req_get_param(iVar18);
        *(byte *)(iVar9 + 8) = *(byte *)(iVar9 + 8) & 0xfe | (byte)((uint)uStack_50 >> 8) & 1;
        if (bVar3) {
          if (iStack_5c != 0) {
            iVar9 = zmsg_append_u8(0);
            if (iVar9 == 0) {
              pcStack_64 = zdo_mgmt_leave_rsp_confirm;
              uStack_68 = 0;
              iStack_60 = iVar18;
              goto _L0;
            }
            goto _L0;
          }
        }
        else if (iStack_5c != 0) {
          iVar9 = zmsg_append_u8(0);
          if ((iVar9 != 0) || (pvStack_7c = calloc(1,0x18), pvStack_7c == (void *)0x0)) goto _L0;
          uVar7 = zdo_packet_move(auStack_70);
          uVar7 = uVar7 & 0xff;
          if (uVar7 != 0) {
            mm_free(pvStack_7c);
            goto _L0;
          }
          uStack_80 = zdo_mgmt_leave_sync_rsp_cb;
          zdo_mgmt_req_set_user_ctx(iVar18,&uStack_80);
          zdo_send_mgmt_req(iVar18,0);
          goto _L0;
        }
_L0:
        do {
          __assert_func(0,0,0,0);
_L0:
          uStack_58 = uStack_58 & 0xffff0000;
          uVar7 = zmsg_get_length(puVar17);
          af_read_le8_isra_0(puVar17,&uStack_58,&uStack_94);
          if (uVar7 < (uStack_58 & 0xffff)) goto _L0;
          iVar18 = nwk_is_device_zczr();
          if (iVar18 == 0) {
_L0:
            cVar19 = '\0';
            uVar21 = 0;
            uVar7 = 0;
            puVar17 = (undefined2 *)0x0;
            iVar18 = 0x84;
          }
          else {
            uVar7 = zdo_packet_max_available_space(0x8032);
            uVar20 = 0;
            if (4 < uVar7) {
              uVar20 = (int)(uVar7 - 4) / 5 & 0xff;
            }
            iVar18 = 0;
            uVar4 = 0;
            while (iVar18 = nwk_route_table_next(iVar18), iVar18 != 0) {
              uVar4 = uVar4 + 1;
            }
            cVar19 = -1;
            if (uVar4 < 0xff) {
              iVar18 = 0;
              cVar19 = '\0';
              while (iVar18 = nwk_route_table_next(iVar18), iVar18 != 0) {
                cVar19 = cVar19 + '\x01';
              }
            }
            uVar7 = uStack_94 & 0xff;
            puVar17 = (undefined2 *)calloc(uVar20,6);
            uVar21 = 0;
            uVar22 = 0;
            if ((puVar17 != (undefined2 *)0x0) || (iVar18 = 0x8a, uVar20 == 0)) {
              puVar8 = (undefined2 *)0x0;
              uVar21 = 0;
              while ((puVar8 = (undefined2 *)nwk_route_table_next(puVar8),
                     puVar8 != (undefined2 *)0x0 && (uVar21 < uVar20))) {
                uVar5 = uVar21;
                if ((uStack_94 & 0xff) <= uVar22) {
                  uVar2 = puVar8[7];
                  uVar1 = puVar8[7];
                  uVar5 = uVar21 + 1 & 0xff;
                  puVar14 = puVar17 + uVar21 * 3;
                  *puVar14 = *puVar8;
                  *(byte *)(puVar14 + 1) =
                       *(byte *)(puVar14 + 1) & 0xc0 | (byte)uVar2 & 7 | (byte)uVar1 & 8 |
                       (byte)puVar8[7] & 0x10 | (byte)puVar8[7] & 0x20;
                  puVar14[2] = puVar8[1];
                }
                uVar22 = uVar22 + 1 & 0xff;
                uVar21 = uVar5;
              }
              iVar18 = 0;
            }
          }
        } while (iStack_5c == 0);
        iVar9 = zmsg_append_u8(iStack_5c,iVar18);
        if (iVar9 == 0) {
          if (iVar18 == 0) {
            iVar18 = zmsg_append_u8(iStack_5c,cVar19);
            if (((iVar18 == 0) && (iVar18 = zmsg_append_u8(iStack_5c,uVar7), iVar18 == 0)) &&
               (iVar18 = zmsg_append_u8(iStack_5c,uVar21), iVar18 == 0)) {
              if (puVar17 == (undefined2 *)0x0) goto _L0;
              uVar7 = uVar21;
              if (uVar21 != 0) {
                uVar20 = 0;
                puVar8 = puVar17;
                do {
                  uVar4 = puVar8[1];
                  uStack_58 = CONCAT22(uStack_58._2_2_,*puVar8);
                  iVar18 = zmsg_append_bytes(iStack_5c,2,&uStack_58);
                  if ((iVar18 != 0) ||
                     (iVar18 = zmsg_append_u8(iStack_5c,uVar4 & 0x3f), iVar18 != 0)) {
_L0:
                    uVar7 = 0x8a;
                    break;
                  }
                  uStack_58 = CONCAT22(uStack_58._2_2_,puVar8[2]);
                  iVar18 = zmsg_append_bytes(iStack_5c,2,&uStack_58);
                  if (iVar18 != 0) goto _L0;
                  uVar20 = uVar20 + 1 & 0xff;
                  puVar8 = puVar8 + 3;
                  uVar7 = 0;
                } while (uVar20 != uVar21);
              }
              goto _L0;
            }
            goto _L0;
          }
          uVar7 = 0;
        }
        else {
_L0:
          uVar7 = 0x8a;
        }
        if (puVar17 != (undefined2 *)0x0) {
_L0:
          mm_free(puVar17);
        }
_L0:
        if (uVar7 == 0) {
_L0:
          uVar7 = zdo_packet_send(auStack_70);
          return uVar7;
        }
        goto _L0;
      }
    }
  }
  else if (uVar4 < 0x35) {
    if (uVar4 == 0x32) {
      puVar17 = *(undefined2 **)(param_1 + 0x14);
      uStack_94 = (uint)uStack_94._1_3_ << 8;
      if (puVar17 != (undefined2 *)0x0) {
        if (*(ushort *)(param_1 + 2) < 0xfff8) goto _L0;
        goto _L0;
      }
      goto _L0;
    }
    if (uVar4 != 0x33) {
      if (uVar4 != 0x31) goto _L411;
      uVar7 = zdo_nwk_mgmt_lqi_req_handler(param_1,auStack_70);
      goto _L0;
    }
    iVar18 = *(int *)(param_1 + 0x14);
    abStack_98[0] = 0;
    uStack_94 = 0;
    puStack_90 = (undefined2 *)0x0;
    if (iVar18 != 0) {
      uStack_58 = (uint)uStack_58._2_2_ << 0x10;
      uVar7 = zmsg_get_length(iVar18);
      af_read_le8_isra_0(iVar18,&uStack_58,abStack_98);
      if ((uStack_58 & 0xffff) <= uVar7) {
        aps_bind_table_iterator_init(0,&uStack_58);
        bVar15 = 0;
        while ((uStack_58 & 0xff) == 0) {
          bVar15 = bVar15 + 1;
          aps_bind_table_iterator_next(&uStack_58);
        }
        if ((bVar15 == 0) || (bVar15 <= abStack_98[0])) {
          uStack_94 = (uint)CONCAT11(abStack_98[0],bVar15) << 8;
          puStack_90 = (undefined2 *)0x0;
          uVar7 = zdo_op_nwk_mgmt_bind_rsp(iStack_5c,&uStack_94,1);
          goto _L0;
        }
        iVar18 = zdo_packet_max_available_space(0x8033);
        uVar7 = iVar18 - 4U & 0xff;
        uVar21 = uVar7 / 0x15;
        puStack_90 = (undefined2 *)calloc(uVar21,0x18);
        if ((puStack_90 == (undefined2 *)0x0) && (0x14 < uVar7)) goto _L0;
        aps_bind_table_iterator_init(0,&uStack_58);
        bVar16 = 0;
        uVar7 = 0;
        while (((uStack_58 & 0xff) == 0 && (uVar7 < uVar21))) {
          if (abStack_98[0] <= bVar16) {
            iVar18 = nwk_address_extended_by_ref(*puStack_54,&uStack_8c);
            if (iVar18 != 0) goto _L0;
            pvVar13 = memcpy(puStack_90 + uVar7 * 0xc,&uStack_8c,8);
            *(undefined1 *)((int)pvVar13 + 8) = *(undefined1 *)(puStack_54 + 1);
            *(undefined2 *)((int)pvVar13 + 10) = puStack_54[2];
            uVar2 = *uStack_50;
            if ((*(byte *)((int)uStack_50 + 5) & 1) == 0) {
              iVar18 = nwk_address_extended_by_ref(&uStack_80);
              puVar17 = puStack_90;
              if (iVar18 != 0) goto _L0;
              *(undefined1 *)(puStack_90 + uVar7 * 0xc + 6) = 3;
              memcpy(puStack_90 + uVar7 * 0xc + 7,&uStack_80,8);
              *(undefined1 *)(puVar17 + uVar7 * 0xc + 0xb) = *(undefined1 *)(uStack_50 + 1);
            }
            else {
              *(undefined1 *)((int)pvVar13 + 0xc) = 1;
              *(undefined2 *)((int)pvVar13 + 0xe) = uVar2;
              *(undefined1 *)((int)pvVar13 + 0x16) = 0;
            }
            uVar7 = uVar7 + 1 & 0xff;
          }
          bVar16 = bVar16 + 1;
          aps_bind_table_iterator_next(&uStack_58);
        }
        uStack_94._3_1_ = (undefined1)uVar7;
        uStack_94 = (uint)CONCAT12(uStack_94._3_1_,CONCAT11(abStack_98[0],bVar15)) << 8;
        uVar7 = zdo_op_nwk_mgmt_bind_rsp(iStack_5c,&uStack_94,1);
        puVar17 = puStack_90;
        if (puStack_90 == (undefined2 *)0x0) goto _L0;
        goto _L0;
      }
    }
  }
  else {
    if (uVar4 == 0x36) {
      iVar18 = *(int *)(param_1 + 0x14);
      uStack_8c = (void *)((uint)uStack_8c._2_2_ << 0x10);
      if (iVar18 != 0) {
        uVar4 = *(ushort *)(param_1 + 2);
        uStack_58 = (uint)uStack_58._2_2_ << 0x10;
        uVar7 = zmsg_get_length(iVar18);
        af_read_le8_isra_0(iVar18,&uStack_58,&uStack_8c);
        af_read_le8_isra_0(iVar18,&uStack_58,(int)&uStack_8c + 1);
        if ((uStack_58 & 0xffff) <= uVar7) {
          bVar15 = (byte)uStack_8c;
          uStack_8c._0_2_ = CONCAT11(1,(byte)uStack_8c);
          nwk_is_device_zc();
          iVar9 = nwk_is_device_zczr();
          iVar18 = 0x84;
          if (iVar9 != 0) {
            iVar9 = zdo_create_mgmt_req(0x36,0x84);
            iVar18 = 0x80;
            if (iVar9 != 0) {
              pbVar12 = (byte *)zdo_mgmt_req_get_param(0x80);
              if (0xfe < bVar15) {
                bVar15 = 0xfe;
              }
              *pbVar12 = bVar15;
              iVar18 = zdo_send_mgmt_req(iVar9,1);
              iVar18 = (uint)(iVar18 != 0) << 7;
            }
          }
          if (uVar4 < 0xfff8) {
            if (iStack_5c == 0) {
              puVar17 = (undefined2 *)0x36;
              goto _L0;
            }
            goto _L0;
          }
        }
      }
      goto _L0;
    }
    if (uVar4 != 0x38) {
_L411:
      uVar7 = 0x84;
      goto _L0;
    }
    iVar18 = *(int *)(param_1 + 0x14);
    uStack_8c = (void *)0x0;
    uStack_88 = 0;
    uStack_84 = 0;
    if (iVar18 != 0) {
      uVar4 = *(ushort *)(param_1 + 2);
      uVar7 = zmsg_get_length(iVar18);
      iVar9 = zmsg_read_bytes(iVar18,0,4,&uStack_8c);
      if (iVar9 == 0) {
        iVar9 = 0xffff;
      }
      uStack_58 = CONCAT22(uStack_58._2_2_,(short)iVar9);
      af_read_le8_isra_0(iVar18,&uStack_58,&uStack_88);
      if ((uStack_88 & 0xff) < 6) {
        af_read_le8_isra_0(iVar18,&uStack_58,(int)&uStack_88 + 1);
      }
      if ((0xfd < (uStack_88 & 0xff)) &&
         (af_read_le8_isra_0(iVar18,&uStack_58,(int)&uStack_88 + 2), (uStack_88 & 0xff) == 0xff)) {
        af_read_le16_isra_0(iVar18,&uStack_58,&uStack_84);
      }
      pvVar13 = uStack_8c;
      if ((uStack_58 & 0xffff) <= uVar7) {
        uVar7 = uStack_88 & 0xff;
        uVar21 = (uint)uStack_8c & 0x7ffffff;
        if (uVar7 == 0xfe) {
          iVar18 = core_globals_get();
          uVar7 = (uint)pvVar13 & 0x7ffffff;
          if ((*(int *)(iVar18 + 0xa30) == 0) ||
             (iVar18 = core_globals_get(), uVar7 == *(uint *)(iVar18 + 0xa30))) {
            bVar15 = 0;
            for (uVar20 = uVar7; uVar20 != 0; uVar20 = uVar20 & uVar20 - 1) {
              bVar15 = bVar15 + 1;
            }
            if (bVar15 < 2) {
              iVar18 = 0;
              if (uVar21 < 0x8000000) {
                iVar18 = 10;
              }
              uVar21 = iVar18 + 1;
              do {
                if ((uVar7 >> (uVar21 & 0x1f) & 1) != 0) {
                  uVar21 = uVar21 & 0xff;
                  goto _L0;
                }
                uVar21 = uVar21 + 1;
              } while ((uVar21 & 0xff) != 0x1b);
              uVar21 = 0xff;
_L0:
              uStack_80 = (code *)0x0;
              iVar18 = nwk_mm_get_pib_attr(0,99,&uStack_80,4);
              if ((iVar18 == 0) && ((((uint)uStack_80 & 0x7ffffff) >> (uVar21 & 0x1f) & 1) != 0)) {
                uStack_58 = 1 << (uVar21 & 0x1f);
                nwk_mm_set_pib_attr(0x61,&uStack_58);
                goto _L0;
              }
            }
_L0:
            uVar7 = 0x80;
          }
          else {
            uVar7 = 0x8d;
          }
        }
        else {
          if (uVar7 == 0xff) {
            iVar18 = aps_secur_is_centralized();
            if ((iVar18 == 0) || ((short)uStack_84 == 0)) {
              iVar18 = core_globals_get();
              *(uint *)(iVar18 + 8) = uVar21;
              iVar18 = core_globals_get();
              *(short *)(iVar18 + 0x9dc) = (short)uStack_84;
            }
            goto _L0;
          }
          if ((5 < uVar7) || (0xfff7 < uVar4)) goto _L0;
          uStack_94 = 0;
          nwk_mm_get_pib_attr(0,99,&uStack_94,4);
          uVar21 = (uint)pvVar13 & 0x7ffffff;
          uVar7 = 0x86;
          if (uVar21 == (uStack_94 & 0x7ffffff & uVar21)) {
            pvVar13 = calloc(1,0x18);
            uVar7 = 0x8a;
            if (pvVar13 != (void *)0x0) {
              uVar7 = zdo_packet_move(auStack_70);
              uVar7 = uVar7 & 0xff;
              if (uVar7 == 0) {
                uVar6 = *(undefined4 *)((int)pvVar13 + 0x14);
                pvStack_7c = uStack_8c;
                pcStack_78 = zdo_mgmt_ed_scan_handler;
                uStack_80 = (code *)((uint)CONCAT21(uStack_80._2_2_,(undefined1)uStack_88) << 8);
                pvStack_74 = pvVar13;
                memset(&uStack_58,0,0x28);
                zmsg_add_footer(uVar6,&uStack_58,0x28);
                nwk_nlme_scan(&uStack_80);
                uVar7 = ezb_err_to_zdp_status();
                if (uVar7 == 0) goto _L0;
              }
              mm_free(pvVar13);
              if (uVar7 == 0xfe) goto _L0;
            }
          }
        }
        memset(&uStack_58,0,0x28);
        uStack_58 = CONCAT31(uStack_58._1_3_,(char)uVar7);
        uVar7 = zdo_op_nwk_mgmt_nwk_update_notify(iStack_5c,&uStack_58,1);
        goto _L0;
      }
    }
  }
_L0:
  uVar7 = 0xfe;
_L0:
  zdo_packet_free(auStack_70);
  return uVar7;
}

