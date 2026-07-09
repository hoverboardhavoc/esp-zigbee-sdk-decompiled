/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> zdo_dev_srv_disc.o -> zdo_device_service_discovery_req_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

uint zdo_device_service_discovery_req_handler(void *param_1)

{
  ushort uVar1;
  short sVar2;
  undefined4 uVar3;
  int iVar4;
  undefined2 *puVar5;
  void *pvVar6;
  uint uVar7;
  char cVar8;
  undefined2 uVar9;
  uint uVar10;
  ushort *puVar11;
  uint *puVar12;
  undefined4 *puVar13;
  void *pvVar14;
  int iVar15;
  undefined4 uVar16;
  undefined1 *puVar17;
  char *pcVar18;
  short *psVar19;
  char cVar20;
  undefined1 uVar21;
  undefined1 uVar25;
  short *psVar27;
  void *unaff_s4;
  undefined2 uVar28;
  undefined2 uVar29;
  undefined2 uVar30;
  uint uVar31;
  undefined2 uVar32;
  uint uVar33;
  ushort auStack_d4 [2];
  ushort auStack_d0 [2];
  ushort auStack_cc [2];
  ushort auStack_c8 [2];
  undefined4 uStack_c4;
  undefined4 uStack_c0;
  undefined4 uStack_bc;
  void *pvStack_b8;
  undefined4 uStack_b4;
  undefined4 uStack_b0;
  undefined4 uStack_ac;
  undefined4 uStack_a8;
  undefined4 uStack_a4;
  undefined1 auStack_a0 [20];
  void *pvStack_8c;
  undefined4 uStack_88;
  uint uStack_84;
  undefined2 uStack_80;
  undefined2 uStack_7e;
  uint uStack_7c;
  byte bStack_78;
  void *pvStack_74;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  void *pvStack_60;
  undefined1 uVar22;
  undefined1 uVar23;
  undefined1 uVar24;
  undefined1 uVar26;
  
  memset(auStack_a0,0,0x18);
  if (param_1 == (void *)0x0) {
    return 0x80;
  }
  uVar10 = zdo_packet_response_init(auStack_a0,param_1,*(ushort *)((int)param_1 + 6) | 0x8000);
  if (uVar10 != 0) {
    return uVar10;
  }
  uVar1 = *(ushort *)((int)param_1 + 6);
  if (uVar1 == 5) {
    auStack_d4[0] = 0;
    if ((*(int *)((int)param_1 + 0x14) == 0) ||
       (iVar4 = zdo_op_node_desc_req(auStack_d4,0), iVar4 != 0)) goto _L0;
    uVar10 = (uint)auStack_d4[0];
    if (0xfff7 < uVar10) {
_L0:
      uVar10 = 0x8b;
      goto _L0;
    }
    uVar7 = nwk_get_short_address();
    if (uVar10 == uVar7) {
      param_1 = (void *)0x0;
      pcVar18 = (char *)0x0;
      while (pcVar18 = (char *)af_device_get_next_endpoint_desc(pcVar18), pcVar18 != (char *)0x0) {
        if (*pcVar18 != '\0') {
          param_1 = (void *)((int)param_1 + 1U & 0xff);
        }
      }
      pvVar6 = (void *)0x0;
      if (param_1 != (void *)0x0) {
        pvVar6 = calloc((size_t)param_1,1);
        uVar7 = 0;
        pcVar18 = (char *)0x0;
        if (pvVar6 == (void *)0x0) goto _L0;
        while (pcVar18 = (char *)af_device_get_next_endpoint_desc(pcVar18), pcVar18 != (char *)0x0)
        {
          if (*pcVar18 != '\0') {
            *(char *)(uVar7 + (int)pvVar6) = *pcVar18;
            uVar7 = uVar7 + 1 & 0xff;
          }
        }
      }
      cVar8 = '\0';
    }
    else {
      cVar8 = nwk_is_device_zed();
      cVar8 = -0x7f - cVar8;
      param_1 = (void *)0x0;
      pvVar6 = (void *)0x0;
    }
    pvVar14 = (void *)0x0;
    unaff_s4 = pvStack_8c;
    if (pvStack_8c == (void *)0x0) {
_L0:
      do {
        __assert_func(0,0,0,0);
        do {
          if (((void *)(*(uint *)((int)pvVar14 + 0xc) & 0x3c0) == param_1) &&
             (uVar7 = uStack_c4 & 0xffff, uVar10 = nwk_neighbor_get_shortaddr(), uVar7 == uVar10)) {
            uVar10 = 0;
            param_1 = (void *)0x0;
            uVar7 = 0;
            uVar31 = 0;
            uVar33 = 0;
            iVar4 = 0x89;
            pvVar14 = (void *)0x0;
            uVar9 = 0;
            goto _L0;
          }
_L0:
          pvVar14 = (void *)nwk_child_table_next(pvVar14);
        } while (pvVar14 != (void *)0x0);
        uVar10 = 0;
        param_1 = (void *)0x0;
        uVar7 = 0;
        uVar31 = 0;
        uVar33 = 0;
        iVar4 = 0x81;
        uVar9 = 0;
_L0:
      } while (pvStack_8c == (void *)0x0);
      iVar15 = zmsg_append_u8(pvStack_8c,iVar4);
      if ((iVar15 == 0) && (iVar15 = zmsg_append_le16(pvStack_8c,unaff_s4), iVar15 == 0)) {
        uVar16 = zmsg_get_length(pvStack_8c);
        iVar15 = zmsg_append_u8(pvStack_8c,0);
        if (iVar15 == 0) {
          if (iVar4 != 0) goto _L0;
          iVar4 = zmsg_append_u8(pvStack_8c,pvVar6);
          if ((((iVar4 == 0) && (iVar4 = zmsg_append_le16(pvStack_8c,uVar9), iVar4 == 0)) &&
              (iVar4 = zmsg_append_le16(pvStack_8c,uVar33), iVar4 == 0)) &&
             (iVar4 = zmsg_append_u8(pvStack_8c,uVar31 << 4 | uVar7), iVar4 == 0)) {
            iVar4 = zmsg_append_u8(pvStack_8c,param_1);
            uVar7 = 0;
            for (; iVar4 == 0;
                iVar4 = zmsg_append_le16(pvStack_8c,*(undefined2 *)(iVar4 + (int)pvVar14))) {
              if (param_1 <= (void *)(uVar7 & 0xff)) {
                iVar4 = zmsg_append_u8(pvStack_8c,uVar10);
                if (iVar4 == 0) {
                  uVar7 = (int)(uVar7 & 0xff) * 2 + 8;
                  pvVar6 = (void *)(uVar10 + (int)param_1);
                  goto _L0;
                }
                break;
              }
              iVar4 = uVar7 * 2;
              uVar7 = uVar7 + 1;
            }
          }
        }
      }
      goto _L0;
    }
    iVar4 = zmsg_append_u8(pvStack_8c,cVar8);
    if (((iVar4 == 0) && (iVar4 = zmsg_append_le16(pvStack_8c,uVar10), iVar4 == 0)) &&
       (iVar4 = zmsg_append_u8(pvStack_8c,param_1), iVar4 == 0)) {
      uVar10 = 0;
      if ((cVar8 == '\0') && (uVar7 = 0, param_1 != (void *)0x0)) {
        do {
          iVar4 = zmsg_append_u8(pvStack_8c,*(undefined1 *)((int)pvVar6 + uVar7));
          if (iVar4 != 0) goto _L0;
          uVar7 = uVar7 + 1;
        } while ((void *)(uVar7 & 0xff) < param_1);
      }
    }
    else {
_L0:
      uVar10 = 0x8a;
    }
    if (pvVar6 == (void *)0x0) goto _L0;
_L0:
    mm_free(pvVar6);
  }
  else {
    pvVar6 = (void *)0x0;
    if (5 < uVar1) {
      if (uVar1 == 0x15) {
        iVar4 = *(int *)((int)param_1 + 0x14);
        auStack_c8[0] = 0;
        if (iVar4 != 0) {
          uStack_70 = (uint)uStack_70._2_2_ << 0x10;
          uVar10 = zmsg_get_length(iVar4);
          af_read_le16_isra_0(iVar4,&uStack_70,auStack_c8);
          if ((uStack_70 & 0xffff) <= uVar10) {
            iVar4 = af_get_node_desc();
            if (iVar4 == 0) goto _L0;
            pvVar14 = (void *)((*(ushort *)(iVar4 + 10) & auStack_c8[0]) & 0x1ff);
            if (*(ushort *)(iVar4 + 10) >> 9 == auStack_c8[0] >> 9) {
              pvVar14 = (void *)((uint)pvVar14 | auStack_c8[0] & 0xfffffe00);
            }
            if (pvVar14 == (void *)0x0) goto _L0;
            pvVar6 = pvStack_8c;
            if (pvStack_8c == (void *)0x0) goto _L0;
            iVar4 = zmsg_append_u8(pvStack_8c,0);
            pvVar6 = pvVar14;
            if (iVar4 != 0) goto _L0;
_L0:
            iVar4 = zmsg_append_le16(pvStack_8c,pvVar6);
_L0:
            if (iVar4 == 0) goto _L0;
            goto _L0;
          }
        }
      }
      else if (uVar1 < 0x16) {
        if (uVar1 == 6) {
          iVar4 = *(int *)((int)param_1 + 0x14);
          uStack_c0 = 0;
          uStack_bc = 0;
          pvStack_b8 = (void *)0x0;
          if (iVar4 == 0) {
_L0:
            uVar10 = 0xfe;
          }
          else {
            uStack_70 = (uint)uStack_70._2_2_ << 0x10;
            uVar10 = zmsg_get_length(iVar4);
            af_read_le16_isra_0(iVar4,&uStack_70,&uStack_c0);
            af_read_le16_isra_0(iVar4,&uStack_70,(int)&uStack_c0 + 2);
            af_read_le8_isra_0(iVar4,&uStack_70,&uStack_bc);
            uVar31 = uStack_bc & 0xff;
            uVar7 = 0;
            pvVar14 = calloc(uVar31,2);
            pvStack_b8 = pvVar14;
            if (pvVar14 == (void *)0x0) {
              pvStack_b8 = (void *)0x0;
              if (uVar31 != 0) goto _L0;
            }
            else {
              for (; pvVar14 = pvStack_b8, uVar7 < (uStack_bc & 0xff); uVar7 = uVar7 + 1 & 0xff) {
                af_read_le16_isra_0(iVar4,&uStack_70,(void *)((int)pvStack_b8 + uVar7 * 2));
              }
            }
            pvStack_b8 = pvVar14;
            af_read_le8_isra_0(iVar4,&uStack_70,(int)&uStack_bc + 1);
            pvStack_b8 = (void *)mm_realloc(pvStack_b8,(uStack_bc & 0xff) + (uStack_bc >> 8 & 0xff),
                                            2);
            uVar7 = uStack_bc & 0xff;
            if (pvStack_b8 == (void *)0x0) {
              if ((uStack_bc >> 8 & 0xff) + uVar7 != 0) goto _L0;
            }
            else {
              for (; uVar7 < (uStack_bc & 0xff) + (uStack_bc >> 8 & 0xff); uVar7 = uVar7 + 1 & 0xff)
              {
                af_read_le16_isra_0(iVar4,&uStack_70,(int)pvStack_b8 + uVar7 * 2);
              }
            }
            if (uVar10 < (uStack_70 & 0xffff)) goto _L0;
            uVar10 = uStack_c0 & 0xffff;
            if (0xfff7 < uVar10) {
              uVar10 = nwk_get_short_address();
            }
            memset(&uStack_70,0,0x40);
            uVar7 = uStack_c0 & 0xffff;
            uVar31 = nwk_get_short_address();
            if ((uVar7 == uVar31) || (0xfff7 < (uStack_c0 & 0xffff))) {
              pvVar14 = (void *)0x0;
              puVar17 = (undefined1 *)0x0;
_L0:
              while (puVar17 = (undefined1 *)af_get_next_simple_desc(puVar17),
                    puVar17 != (undefined1 *)0x0) {
                if ((*(short *)(puVar17 + 2) == uStack_c0._2_2_) || (uStack_c0._2_2_ == -1)) {
                  for (uVar7 = 0; (uVar7 & 0xff) < (uint)(byte)puVar17[7]; uVar7 = uVar7 + 1) {
                    uVar31 = 0;
                    while ((uVar31 & 0xff) < (uStack_bc & 0xff)) {
                      uVar31 = uVar31 + 1;
                      if (*(short *)(uVar7 * 2 + *(int *)(puVar17 + 0xc)) ==
                          *(short *)(uVar31 * 2 + (int)pvStack_b8 + -2)) goto _L0;
                    }
                  }
                  psVar27 = (short *)(*(int *)(puVar17 + 0xc) + (uint)(byte)puVar17[7] * 2);
                  for (cVar8 = '\0'; puVar17[8] != cVar8; cVar8 = cVar8 + '\x01') {
                    psVar19 = (short *)((int)pvStack_b8 + (uStack_bc & 0xff) * 2);
                    for (cVar20 = '\0'; uStack_bc._1_1_ != cVar20; cVar20 = cVar20 + '\x01') {
                      sVar2 = *psVar19;
                      psVar19 = psVar19 + 1;
                      if (*psVar27 == sVar2) goto _L0;
                    }
                    psVar27 = psVar27 + 1;
                  }
                }
              }
              if ((pvVar14 == (void *)0x0) && (0xfff7 < (ushort)uStack_c0)) goto _L0;
              param_1 = (void *)0x0;
              goto _L0;
            }
            iVar4 = nwk_is_device_zed();
            if (iVar4 == 0) {
              iVar4 = 0;
              do {
                iVar4 = nwk_child_table_next(iVar4);
                if (iVar4 == 0) {
                  param_1 = (void *)0x81;
                  pvVar14 = (void *)0x0;
                  goto _L0;
                }
              } while (((*(uint *)(iVar4 + 0xc) & 0x3c0) != 0x40) ||
                      (uVar31 = uStack_c0 & 0xffff, uVar7 = nwk_neighbor_get_shortaddr(),
                      uVar31 != uVar7));
              pvVar14 = (void *)0x0;
              param_1 = (void *)0x89;
            }
            else {
              if (0xfff7 < *(ushort *)((int)param_1 + 2)) goto _L0;
              pvVar14 = (void *)0x0;
              param_1 = (void *)0x80;
            }
_L0:
            unaff_s4 = pvStack_8c;
            if (pvStack_8c == (void *)0x0) goto _L0;
            iVar4 = zmsg_append_u8(pvStack_8c,param_1);
            if ((((iVar4 != 0) || (iVar4 = zmsg_append_le16(pvStack_8c,uVar10), iVar4 != 0)) ||
                (iVar4 = zmsg_append_u8(pvStack_8c,pvVar14), iVar4 != 0)) ||
               (((uVar10 = 0, param_1 == (void *)0x0 && (pvVar14 != (void *)0x0)) &&
                (iVar4 = zmsg_append_bytes(pvStack_8c,pvVar14,&uStack_70), iVar4 != 0)))) {
              uVar10 = 0x8a;
            }
          }
          if (pvStack_b8 != (void *)0x0) {
            mm_free();
          }
          goto _L0;
        }
        if (uVar1 != 0x13) goto _L529;
        uStack_c0 = uStack_c0 & 0xffff0000;
        uStack_70 = 0;
        uStack_6c = 0;
        uStack_68 = 0;
        if (*(int *)((int)param_1 + 0x14) != 0) {
          uVar10 = zmsg_get_length();
          af_read_le16_isra_0(*(undefined4 *)((int)param_1 + 0x14),&uStack_c0,&uStack_68);
          af_read_bytes_isra_0(*(undefined4 *)((int)param_1 + 0x14),&uStack_c0,8,&uStack_70);
          af_read_le8_isra_0(*(undefined4 *)((int)param_1 + 0x14),&uStack_c0,(int)&uStack_68 + 2);
          if ((uStack_c0 & 0xffff) <= uVar10) {
            puVar12 = (uint *)nwk_get_extended_address();
            if ((uStack_70 != *puVar12) || (uStack_6c != puVar12[1])) {
              iVar4 = nwk_is_device_zczr();
              if (iVar4 != 0) {
                uStack_b4 = uStack_b4 & 0xffff0000;
                iVar4 = nwk_address_update(&uStack_70,uStack_68 & 0xffff,&uStack_b4);
                if (iVar4 == 0xd) {
                  uStack_88._0_2_ = CONCAT11((char)uStack_68,0xd);
                  uStack_88 = (uint)CONCAT12((char)(uStack_68 >> 8),(undefined2)uStack_88);
                  nwk_send_status(0xfffd,&uStack_88);
                  nwk_handle_network_status_local(&uStack_88);
                  goto _L0;
                }
              }
              zdo_device_annce_indication
                        (uStack_70,uStack_6c,uStack_68 & 0xffff,uStack_68 >> 0x10 & 0xff);
            }
          }
        }
      }
      else {
        if (uVar1 != 0x1f) {
_L529:
          uVar10 = 0x84;
          goto _L0;
        }
        uStack_88 = uStack_88 & 0xffff0000;
        uStack_70 = 0;
        uStack_6c = 0;
        uStack_68 = uStack_68 & 0xffffff00;
        if ((*(int *)((int)param_1 + 0x14) != 0) && (iVar4 = nwk_is_device_zed(), iVar4 == 0)) {
          uVar10 = zmsg_get_length(*(undefined4 *)((int)param_1 + 0x14));
          af_read_le8_isra_0(*(undefined4 *)((int)param_1 + 0x14),&uStack_88,&uStack_70);
          if ((uStack_88 & 0xffff) <= uVar10) {
            if ((0xfff7 < *(ushort *)((int)param_1 + 2)) &&
               (iVar4 = core_globals_get(), *(char *)(iVar4 + 0x16) != '\0')) {
              uVar10 = random_noncrypto_range_u32(0,0x2711);
              iVar4 = core_globals_get();
              *(char *)(iVar4 + 0x16) = (char)(uVar10 / 1000) + '\n';
            }
            zmsg_append_u8(pvStack_8c,0);
            cVar8 = '\0';
            for (uVar7 = 0; uVar7 < (uStack_70 & 0xff); uVar7 = uVar7 + 1 & 0xff) {
              af_read_bytes_isra_0
                        (*(undefined4 *)((int)param_1 + 0x14),&uStack_88,8,(int)&uStack_70 + 1);
              iVar4 = nwk_neighbor_table_get_by_extended((int)&uStack_70 + 1);
              if (((iVar4 != 0) && ((*(uint *)(iVar4 + 0xc) & 3) == 2)) &&
                 (*(int *)(iVar4 + 0x14) << 7 < 0)) {
                uVar10 = zmsg_append_bytes(pvStack_8c,8,(int)&uStack_70 + 1);
                uVar10 = uVar10 & 0xff;
                if (uVar10 != 0) goto _L0;
                cVar8 = cVar8 + '\x01';
              }
            }
            if (cVar8 != '\0') {
              uStack_b4 = CONCAT31(uStack_b4._1_3_,cVar8);
              puVar13 = &uStack_b4;
              uVar16 = 0;
              goto _L528;
            }
          }
        }
      }
_L0:
      uVar10 = 0xfe;
      goto _L0;
    }
    if (uVar1 == 2) {
      auStack_cc[0] = 0;
      uStack_b4 = 0;
      uStack_b0 = 0;
      uStack_ac = 0;
      uStack_a8 = 0;
      uStack_a4 = 0;
      if ((*(int *)((int)param_1 + 0x14) == 0) ||
         (iVar4 = zdo_op_node_desc_req(auStack_cc,0), iVar4 != 0)) goto _L0;
      unaff_s4 = (void *)(uint)auStack_cc[0];
      if ((void *)0xfff7 < unaff_s4) goto _L0;
      uStack_b4 = CONCAT22(auStack_cc[0],(undefined2)uStack_b4);
      pvVar14 = (void *)nwk_get_short_address();
      pvVar6 = (void *)0x0;
      if (unaff_s4 != pvVar14) {
        iVar4 = nwk_is_device_zed();
        pvVar6 = (void *)0x80;
        if (iVar4 == 0) {
          puVar5 = (undefined2 *)0x0;
          do {
            do {
              puVar5 = (undefined2 *)nwk_neighbor_table_next(puVar5);
              if (puVar5 == (undefined2 *)0x0) goto _L0;
            } while ((*(uint *)(puVar5 + 6) & 3) != 2);
            uStack_70 = CONCAT22(uStack_70._2_2_,0xffff);
            nwk_address_short_by_ref(*puVar5,&uStack_70);
          } while (auStack_cc[0] != (ushort)uStack_70);
_L0:
          pvVar6 = (void *)0x81;
        }
      }
      uStack_b4 = CONCAT31(uStack_b4._1_3_,(char)pvVar6);
      uStack_b0 = 0;
      uStack_ac = 0;
      uStack_a8 = 0;
      uStack_a4 = 0;
      if ((pvVar6 == (void *)0x0) &&
         (puVar5 = (undefined2 *)af_get_node_desc(), puVar5 != (undefined2 *)0x0)) {
        memcpy(&uStack_b0,puVar5,0x10);
        uVar9 = *puVar5;
        param_1 = (void *)(uint)*(byte *)(puVar5 + 1);
        uVar32 = puVar5[2];
        uVar21 = *(undefined1 *)(puVar5 + 3);
        uVar30 = puVar5[4];
        uVar29 = puVar5[5];
        uVar28 = puVar5[6];
        uVar22 = *(undefined1 *)(puVar5 + 7);
      }
      else {
        uVar22 = 0;
        uVar21 = 0;
        uVar28 = 0;
        uVar29 = 0;
        uVar30 = 0;
        uVar32 = 0;
        uVar9 = 0;
        param_1 = (void *)0x0;
      }
      pvVar14 = pvStack_8c;
      if (pvStack_8c == (void *)0x0) goto _L0;
      iVar4 = zmsg_append_u8(pvStack_8c,pvVar6);
      if ((iVar4 == 0) && (iVar4 = zmsg_append_le16(pvStack_8c,unaff_s4), iVar4 == 0)) {
        if (pvVar6 != (void *)0x0) goto _L0;
        iVar4 = zmsg_append_le16(pvStack_8c,uVar9);
        if ((((iVar4 != 0) || (iVar4 = zmsg_append_u8(pvStack_8c,param_1), iVar4 != 0)) ||
            ((iVar4 = zmsg_append_le16(pvStack_8c,uVar32), iVar4 != 0 ||
             (((iVar4 = zmsg_append_u8(pvStack_8c,uVar21), iVar4 != 0 ||
               (iVar4 = zmsg_append_le16(pvStack_8c,uVar30), iVar4 != 0)) ||
              (iVar4 = zmsg_append_le16(pvStack_8c,uVar29), iVar4 != 0)))))) ||
           (iVar4 = zmsg_append_le16(pvStack_8c,uVar28), iVar4 != 0)) goto _L0;
        iVar4 = zmsg_append_u8(pvStack_8c,uVar22);
        goto _L0;
      }
_L0:
      uVar10 = 0x8a;
      goto _L0;
    }
    if (2 < uVar1) {
      if (uVar1 == 3) {
        auStack_d0[0] = 0;
        if ((*(int *)((int)param_1 + 0x14) != 0) &&
           (iVar4 = zdo_op_node_desc_req(auStack_d0,0), iVar4 == 0)) {
          uVar10 = (uint)auStack_d0[0];
          if (0xfff7 < uVar10) goto _L0;
          uVar7 = nwk_get_short_address();
          if (uVar10 == uVar7) {
            puVar11 = (ushort *)af_get_node_power_desc();
            pvVar14 = (void *)0x0;
            if (puVar11 == (ushort *)0x0) goto _L0;
            pvVar6 = (void *)(uint)*puVar11;
          }
          else {
            iVar4 = nwk_is_device_zed();
            pvVar14 = (void *)0x80;
            if (iVar4 == 0) {
              puVar5 = (undefined2 *)0x0;
              do {
                do {
                  puVar5 = (undefined2 *)nwk_neighbor_table_next(puVar5);
                  if (puVar5 == (undefined2 *)0x0) goto _L531;
                } while ((*(uint *)(puVar5 + 6) & 3) != 2);
                uStack_70 = CONCAT22(uStack_70._2_2_,0xffff);
                nwk_address_short_by_ref(*puVar5,&uStack_70);
              } while (auStack_d0[0] != (ushort)uStack_70);
_L531:
              pvVar14 = (void *)0x81;
            }
_L0:
            pvVar6 = (void *)0x0;
          }
          param_1 = pvStack_8c;
          if (pvStack_8c == (void *)0x0) goto _L0;
          iVar4 = zmsg_append_u8(pvStack_8c,pvVar14);
          if ((iVar4 == 0) && (iVar4 = zmsg_append_le16(pvStack_8c,uVar10), iVar4 == 0)) {
            if (pvVar14 != (void *)0x0) goto _L0;
            goto _L0;
          }
          goto _L0;
        }
      }
      else {
        uStack_c4 = 0;
        memset(&uStack_88,0,0x18);
        iVar4 = *(int *)((int)param_1 + 0x14);
        if (iVar4 != 0) {
          uStack_70 = uStack_70 & 0xffff0000;
          uVar10 = zmsg_get_length(iVar4);
          af_read_le16_isra_0(iVar4,&uStack_70,&uStack_c4);
          af_read_le8_isra_0(iVar4,&uStack_70,(int)&uStack_c4 + 2);
          if ((uStack_70 & 0xffff) <= uVar10) {
            unaff_s4 = (void *)(uStack_c4 & 0xffff);
            if (unaff_s4 < (void *)0xfff8) {
              uStack_88 = CONCAT22((undefined2)uStack_c4,(undefined2)uStack_88);
              pvVar14 = (void *)nwk_get_short_address();
              if (unaff_s4 != pvVar14) {
                iVar4 = nwk_is_device_zczr();
                if (iVar4 != 0) {
                  pvVar14 = (void *)0x0;
                  param_1 = (void *)0x40;
                  goto _L0;
                }
                uVar10 = 0;
                param_1 = (void *)0x0;
                uVar7 = 0;
                uVar31 = 0;
                uVar33 = 0;
                iVar4 = 0x80;
                pvVar14 = (void *)0x0;
                uVar9 = 0;
                goto _L0;
              }
              if (((uStack_c4 >> 0x10 & 0xff) - 1 & 0xff) < 0xfe) {
                pvVar14 = (void *)af_get_simple_desc();
                if (pvVar14 == (void *)0x0) {
                  uVar10 = 0;
                  param_1 = (void *)0x0;
                  uVar7 = 0;
                  uVar31 = 0;
                  uVar33 = 0;
                  uVar9 = 0;
                  iVar4 = 0x83;
                  pvVar14 = (void *)0x0;
                  goto _L0;
                }
                memcpy(&uStack_80,pvVar14,0x10);
                uVar33 = uStack_7c & 0xffff;
                param_1 = (void *)(uStack_7c >> 0x18);
                uVar10 = (uint)bStack_78;
                pvVar6 = (void *)(uint)(byte)uStack_80;
                uVar31 = uStack_7c >> 0x10 & 0xf;
                uVar7 = uStack_7c >> 0x14 & 0xf;
                iVar4 = 0;
                pvVar14 = pvStack_74;
                uVar9 = uStack_7e;
                goto _L0;
              }
              uVar10 = 0;
              param_1 = (void *)0x0;
              pvVar14 = (void *)0x0;
              uVar7 = 0;
              uVar31 = 0;
              uVar33 = 0;
              uVar9 = 0;
              iVar4 = 0x82;
              goto _L0;
            }
          }
        }
      }
      goto _L0;
    }
    iVar4 = *(int *)((int)param_1 + 0x14);
    if (uVar1 == 0) {
      uStack_88 = 0;
      uStack_84 = 0;
      uStack_80 = 0;
      uStack_70 = 0;
      uStack_6c = 0;
      uStack_68 = 0;
      uStack_64 = 0;
      pvStack_60 = (void *)0x0;
      if (iVar4 == 0) goto _L0;
      uStack_b4 = (uint)uStack_b4._2_2_ << 0x10;
      uVar10 = zmsg_get_length(iVar4);
      af_read_bytes_isra_0(iVar4,&uStack_b4,8,&uStack_88);
      af_read_le8_isra_0(iVar4,&uStack_b4,&uStack_80);
      af_read_le8_isra_0(iVar4,&uStack_b4,(int)&uStack_80 + 1);
      if (uVar10 < (uStack_b4 & 0xffff)) goto _L0;
      uStack_70._0_2_ = CONCAT11((char)uStack_88,(undefined1)uStack_70);
      uStack_70._0_3_ = CONCAT12((char)(uStack_88 >> 8),(ushort)uStack_70);
      uStack_70 = CONCAT13((char)(uStack_88 >> 0x10),(undefined3)uStack_70);
      uStack_6c._0_2_ = CONCAT11((char)uStack_84,(char)(uStack_88 >> 0x18));
      uStack_6c._0_3_ = CONCAT12((char)(uStack_84 >> 8),(undefined2)uStack_6c);
      uStack_68 = CONCAT31(uStack_68._1_3_,(char)(uStack_84 >> 0x18));
      uStack_6c = CONCAT13((char)(uStack_84 >> 0x10),(undefined3)uStack_6c);
      uStack_68 = CONCAT22(0xffff,(undefined2)uStack_68);
      puVar12 = (uint *)nwk_get_extended_address();
      if ((uStack_88 == *puVar12) && (uStack_84 == puVar12[1])) {
        nwk_address_short_by_extended(&uStack_88,(int)&uStack_68 + 2);
      }
      else {
        puVar5 = (undefined2 *)nwk_neighbor_table_get_by_extended(&uStack_88);
        if ((puVar5 != (undefined2 *)0x0) && ((*(uint *)(puVar5 + 6) & 3) == 2)) {
          nwk_address_short_by_ref(*puVar5,(int)&uStack_68 + 2);
        }
      }
      uVar21 = (undefined1)(uStack_88 >> 8);
      uVar22 = (undefined1)(uStack_88 >> 0x10);
      uVar25 = (undefined1)(uStack_88 >> 0x18);
      uVar23 = (undefined1)(uStack_84 >> 8);
      uVar24 = (undefined1)(uStack_84 >> 0x10);
      uVar26 = (undefined1)(uStack_84 >> 0x18);
      if (uStack_68 >> 0x10 == 0xffff) {
        if (0xfff7 < *(ushort *)((int)param_1 + 2)) goto _L0;
        uStack_70._0_2_ = CONCAT11((char)uStack_88,0x81);
        uStack_70._0_3_ = CONCAT12(uVar21,(ushort)uStack_70);
        uStack_70 = CONCAT13(uVar22,(undefined3)uStack_70);
        uStack_6c._0_2_ = CONCAT11((char)uStack_84,uVar25);
        uStack_6c._0_3_ = CONCAT12(uVar23,(undefined2)uStack_6c);
        uStack_68 = CONCAT31(uStack_68._1_3_,uVar26);
        uStack_6c = CONCAT13(uVar24,(undefined3)uStack_6c);
        uStack_68 = CONCAT22(0xffff,(undefined2)uStack_68);
      }
      else {
        if ((byte)uStack_80 == '\0') {
          uStack_70._0_1_ = 0;
        }
        else {
          if ((byte)uStack_80 == '\x01') {
            iVar4 = nwk_is_device_zczr();
            if (iVar4 != 0) {
              uStack_70 = uStack_70 & 0xffffff00;
              puVar13 = (undefined4 *)nwk_get_extended_address();
              uVar16 = *puVar13;
              uVar3 = puVar13[1];
              uStack_70._0_2_ = CONCAT11((char)*(undefined3 *)puVar13,(undefined1)uStack_70);
              uStack_70._0_3_ = CONCAT12((char)((uint)uVar16 >> 8),(ushort)uStack_70);
              uStack_70 = CONCAT13((char)((uint)uVar16 >> 0x10),(undefined3)uStack_70);
              uStack_6c._0_2_ =
                   CONCAT11((char)*(undefined3 *)(puVar13 + 1),(char)((uint)uVar16 >> 0x18));
              uStack_6c = CONCAT13((char)((uint)uVar3 >> 0x10),
                                   CONCAT12((char)((uint)uVar3 >> 8),(undefined2)uStack_6c));
              uStack_68 = CONCAT31(uStack_68._1_3_,(char)((uint)uVar3 >> 0x18));
              uVar9 = nwk_get_short_address();
              uStack_68 = CONCAT22(uVar9,(undefined2)uStack_68);
              uVar10 = nwk_neighbor_table_get_ed_num();
              uVar10 = uVar10 & 0xff;
              if (uVar10 != 0) {
                pvStack_60 = calloc(uVar10,2);
              }
              puVar5 = (undefined2 *)0x0;
              uStack_64 = (uint)CONCAT21(uStack_64._2_2_,uStack_80._1_1_) << 8;
              uVar7 = 0;
              while ((puVar5 = (undefined2 *)nwk_neighbor_table_next(puVar5),
                     puVar5 != (undefined2 *)0x0 && ((uStack_64 & 0xff) < uVar10))) {
                if (((uStack_64 >> 8 & 0xff) <= uVar7) && ((*(uint *)(puVar5 + 6) & 3) == 2)) {
                  nwk_address_short_by_ref
                            (*puVar5,(void *)((uStack_64 & 0xff) * 2 + (int)pvStack_60));
                  uStack_64 = CONCAT31(uStack_64._1_3_,(char)uStack_64 + '\x01');
                }
                uVar7 = uVar7 + 1 & 0xff;
              }
            }
            goto _L0;
          }
          if (0xfff7 < *(ushort *)((int)param_1 + 2)) goto _L0;
          uStack_70._0_1_ = 0x80;
        }
        uStack_70._0_2_ = CONCAT11((char)uStack_88,(undefined1)uStack_70);
        uStack_70._0_3_ = CONCAT12(uVar21,(ushort)uStack_70);
        uStack_70 = CONCAT13(uVar22,(undefined3)uStack_70);
        uStack_6c._0_2_ = CONCAT11((char)uStack_84,uVar25);
        uStack_6c._0_3_ = CONCAT12(uVar23,(undefined2)uStack_6c);
        uStack_6c = CONCAT13(uVar24,(undefined3)uStack_6c);
        uStack_68 = CONCAT31(uStack_68._1_3_,uVar26);
        nwk_address_short_by_extended((int)&uStack_70 + 1,(int)&uStack_68 + 2);
      }
_L0:
      uVar10 = zdo_op_nwk_addr_rsp(pvStack_8c,(byte)uStack_80,&uStack_70,1);
    }
    else {
      uStack_88 = 0;
      uStack_70 = 0;
      uStack_6c = 0;
      uStack_68 = 0;
      uStack_64 = 0;
      pvStack_60 = (void *)0x0;
      if (iVar4 != 0) {
        uStack_b4 = (uint)uStack_b4._2_2_ << 0x10;
        uVar10 = zmsg_get_length(iVar4);
        af_read_le16_isra_0(iVar4,&uStack_b4,&uStack_88);
        af_read_le8_isra_0(iVar4,&uStack_b4,(int)&uStack_88 + 2);
        af_read_le8_isra_0(iVar4,&uStack_b4,(int)&uStack_88 + 3);
        if ((uStack_b4 & 0xffff) <= uVar10) {
          uVar10 = uStack_88 & 0xffff;
          uStack_70._0_2_ = CONCAT11(0xff,(undefined1)uStack_70);
          uStack_70._0_3_ = CONCAT12(0xff,(ushort)uStack_70);
          uStack_70 = CONCAT13(0xff,(undefined3)uStack_70);
          uStack_6c = 0xffffffff;
          uStack_68 = CONCAT31(uStack_68._1_3_,0xff);
          uVar7 = nwk_get_short_address();
          if (uVar10 == uVar7) {
            nwk_address_extended_by_short((int)&uStack_70 + 1);
          }
          else {
            puVar5 = (undefined2 *)nwk_neighbor_table_get_by_short(uStack_88 & 0xffff);
            if ((puVar5 != (undefined2 *)0x0) && ((*(uint *)(puVar5 + 6) & 3) == 2)) {
              nwk_address_extended_by_ref(*puVar5,(int)&uStack_70 + 1);
            }
          }
          uVar10 = uStack_88 >> 0x10 & 0xff;
          if (((uStack_6c << 0x18 | uStack_70 >> 8) == 0xffffffff) &&
             ((uStack_68 << 0x18 | uStack_6c >> 8) == 0xffffffff)) {
            uStack_70 = CONCAT31(uStack_70._1_3_,0x81);
            uStack_68 = CONCAT22((undefined2)uStack_88,(undefined2)uStack_68);
          }
          else {
            if (uVar10 == 0) {
              uStack_70 = (uint)uStack_70._1_3_ << 8;
              uStack_68 = CONCAT22((undefined2)uStack_88,(undefined2)uStack_68);
              nwk_address_extended_by_short((int)&uStack_70 + 1);
            }
            else if (uVar10 == 1) {
              uStack_70 = (uint)uStack_70._1_3_ << 8;
              puVar13 = (undefined4 *)nwk_get_extended_address();
              uVar16 = *puVar13;
              uVar3 = puVar13[1];
              uStack_70._0_2_ = CONCAT11((char)*(undefined3 *)puVar13,(undefined1)uStack_70);
              uStack_70._0_3_ = CONCAT12((char)((uint)uVar16 >> 8),(ushort)uStack_70);
              uStack_68 = CONCAT31(uStack_68._1_3_,(char)((uint)uVar3 >> 0x18));
              uStack_70 = CONCAT13((char)((uint)uVar16 >> 0x10),(undefined3)uStack_70);
              uStack_6c._0_2_ =
                   CONCAT11((char)*(undefined3 *)(puVar13 + 1),(char)((uint)uVar16 >> 0x18));
              uStack_6c = CONCAT13((char)((uint)uVar3 >> 0x10),
                                   CONCAT12((char)((uint)uVar3 >> 8),(undefined2)uStack_6c));
              uVar9 = nwk_get_short_address();
              uStack_68 = CONCAT22(uVar9,(undefined2)uStack_68);
              uStack_64 = (uint)CONCAT21(uStack_64._2_2_,uStack_88._3_1_) << 8;
              iVar4 = nwk_is_device_zczr();
              if (iVar4 != 0) {
                uVar10 = nwk_neighbor_table_get_ed_num();
                if ((uVar10 & 0xff) != 0) {
                  pvStack_60 = calloc(uVar10 & 0xff,2);
                }
                iVar4 = 0;
                uVar10 = 0;
                while (iVar4 = nwk_child_table_next(iVar4), iVar4 != 0) {
                  if ((*(uint *)(iVar4 + 0xc) & 0x3c0) == 0x40) {
                    if ((uStack_64 >> 8 & 0xff) <= uVar10) {
                      puVar5 = (undefined2 *)((int)pvStack_60 + (uStack_64 & 0xff) * 2);
                      uStack_64 = CONCAT31(uStack_64._1_3_,(char)uStack_64 + '\x01');
                      uVar9 = nwk_neighbor_get_shortaddr();
                      *puVar5 = uVar9;
                    }
                    uVar10 = uVar10 + 1 & 0xff;
                  }
                }
              }
            }
            else {
              uStack_70 = CONCAT31(uStack_70._1_3_,0x80);
              puVar13 = (undefined4 *)nwk_get_extended_address();
              uVar16 = *puVar13;
              uVar3 = puVar13[1];
              uStack_70._0_2_ = CONCAT11((char)*(undefined3 *)puVar13,(undefined1)uStack_70);
              uStack_70._0_3_ = CONCAT12((char)((uint)uVar16 >> 8),(ushort)uStack_70);
              uStack_70 = CONCAT13((char)((uint)uVar16 >> 0x10),(undefined3)uStack_70);
              uStack_6c._0_2_ =
                   CONCAT11((char)*(undefined3 *)(puVar13 + 1),(char)((uint)uVar16 >> 0x18));
              uStack_6c = CONCAT13((char)((uint)uVar3 >> 0x10),
                                   CONCAT12((char)((uint)uVar3 >> 8),(undefined2)uStack_6c));
              uStack_68 = CONCAT31(uStack_68._1_3_,(char)((uint)uVar3 >> 0x18));
              uVar9 = nwk_get_short_address();
              uStack_68 = CONCAT22(uVar9,(undefined2)uStack_68);
            }
            uVar10 = uStack_88 >> 0x10 & 0xff;
          }
          uVar10 = zdo_op_ieee_addr_rsp(pvStack_8c,uVar10,&uStack_70,1);
          goto _L0;
        }
      }
_L0:
      uVar10 = 0xfe;
    }
_L0:
    pvVar6 = pvStack_60;
    if (pvStack_60 != (void *)0x0) goto _L0;
  }
_L0:
  if (uVar10 == 0) {
_L0:
    uVar10 = zdo_packet_send(auStack_a0);
    return uVar10;
  }
_L0:
  zdo_packet_free(auStack_a0);
  return uVar10;
_L0:
  *(undefined1 *)((int)&uStack_70 + (int)pvVar14) = *puVar17;
  pvVar14 = (void *)((int)pvVar14 + 1U & 0xff);
  goto _L0;
_L0:
  if (pvVar6 <= param_1) goto _L0;
  uVar7 = (uVar7 & 0xff) + 2;
  iVar4 = zmsg_append_le16(pvStack_8c,*(undefined2 *)((int)param_1 * 2 + (int)pvVar14));
  if (iVar4 != 0) goto _L0;
  param_1 = (void *)((int)param_1 + 1U & 0xff);
  goto _L0;
_L0:
  uStack_70 = CONCAT31(uStack_70._1_3_,(char)uVar7);
  puVar13 = &uStack_70;
_L528:
  zmsg_write_bytes(pvStack_8c,uVar16,1,puVar13);
  goto _L0;
}

